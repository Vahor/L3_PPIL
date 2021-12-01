package fr.nathan.mim.server;

import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import fr.nathan.mim.Constants;
import fr.nathan.mim.render.Renderer;
import fr.nathan.mim.render.actions.ActionManager;
import fr.nathan.mim.render.actions.IAction;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;

/**
 * Chaque ligne reçue est une action.
 * Elle se compose du nom d'action, un symbole égal, des données
 * exemple : ChangeNameAction=test
 *
 * Le nom d'action STOP est utilisé pour changer de contexte
 */
public class PacketListener extends Thread {

    private final ServerSocket serverSocket;
    private final ActionManager actionManager;

    private Renderer currentRenderer;

    public PacketListener(int port) throws IOException {
        serverSocket = new ServerSocket(port);
        serverSocket.setSoTimeout(5000);

        actionManager = new ActionManager();
    }

    @Override
    public void run() {
        System.out.println("PacketListener lancé");

        //noinspection InfiniteLoopStatement
        while (true) {
            try {
                try (Socket server = serverSocket.accept();
                     BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(server.getInputStream()))) {

                    String line;
                    while ((line = bufferedReader.readLine()) != null) {
                        System.out.println("line = " + line);
                        JsonObject object = new JsonParser().parse(line).getAsJsonObject();
                        String action = object.get("_action").getAsString();

                        // Si l'action est STOP on change le contexte
                        if (action.equals("STOP")) {
                            currentRenderer = null;
                            continue;
                        }


                        // À chaque étape on vérifie si le contexte est encore valide. Sinon on le recrée
                        if (currentRenderer == null || !currentRenderer.isVisible()) {
                            currentRenderer = new Renderer();
                            currentRenderer.setVisible(true);
                        }

                        // On execute l'action demandée dans le contexte actuel
                        // Lance une exception si args[0] n'est pas une action valide
                        actionManager.getActionByName(action).execute(object, currentRenderer);
                    }
                }
            } catch (SocketTimeoutException ignored) {
                // On ignore les exceptions SocketTimeoutException
                // Elles apparaissent lorsque aucune information n'est envoyée pendant le délai du setSoTimeout
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

}
