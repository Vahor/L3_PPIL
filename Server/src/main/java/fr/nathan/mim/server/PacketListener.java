package fr.nathan.mim.server;

import fr.nathan.mim.render.Renderer;
import fr.nathan.mim.render.actions.ActionManager;

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

                        switch (line) {
                            case "INIT": {
                                currentRenderer = new Renderer();
                                currentRenderer.setVisible(true);
                                break;
                            }
                            case "REFRESH": {
                                currentRenderer.repaint();
                                break;
                            }
                            default: {
                                actionManager.handleAction(line, currentRenderer);
                            }
                        }

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
