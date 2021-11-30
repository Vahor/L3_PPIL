package server;

import render.Renderer;
import render.actions.Action;

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

    private Renderer currentRenderer;

    public PacketListener(int port) throws IOException {
        serverSocket = new ServerSocket(port);
        serverSocket.setSoTimeout(10000);
    }

    @Override
    public void run() {
        //noinspection InfiniteLoopStatement
        while (true) {
            try {
                Socket server = serverSocket.accept();
                try (BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(server.getInputStream()))) {

                    String line;
                    while ((line = bufferedReader.readLine()) != null) {
                        String[] args = line.split("=", 2);
                        if(args.length != 2) {

                            // Si l'action est STOP on change le contexte
                            if(args[0].equals("STOP")) {
                                currentRenderer = null;
                                continue;
                            }

                            throw new UnsupportedOperationException();
                        }

                        // À chaque étape on vérifie si le contexte est encore valide. Sinon on le recrée
                        if(currentRenderer == null || !currentRenderer.isVisible()){
                            currentRenderer = new Renderer();
                            currentRenderer.setVisible(true);
                        }

                        // On execute l'action demandée dans le contexte actuel
                        // Lance une exception si args[0] n'est pas une action valide
                        Action.valueOf(args[0]).execute(args[1], currentRenderer);
                    }
                }
                server.close();
            } catch (SocketTimeoutException ignored) {
                // On ignore les exceptions SocketTimeoutException
                // Elles apparaissent lorsque aucune information n'est envoyée pendant le délai du setSoTimeout
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

}
