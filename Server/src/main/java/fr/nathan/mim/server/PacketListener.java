package fr.nathan.mim.server;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.data.json.JsonParser;
import fr.nathan.mim.render.renderer.Renderer;
import fr.nathan.mim.render.renderer.RendererActionManager;
import fr.nathan.mim.render.shape.actions.ActionManager;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;

public class PacketListener extends Thread {

    private final ServerSocket serverSocket;

    private final ActionManager actionManager;
    private final RendererActionManager rendererActionManager;

    private Renderer currentRenderer;
    private final JsonParser parser = new JsonParser();

    public PacketListener(int port) throws IOException {
        serverSocket = new ServerSocket(port); serverSocket.setSoTimeout(5000);

        actionManager = new ActionManager(); rendererActionManager = new RendererActionManager();
    }

    @Override
    public void run() {
        System.out.println("PacketListener lancé");

        //noinspection InfiniteLoopStatement
        while (true) {
            try {
                try (Socket server = serverSocket.accept();
                     BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(server.getInputStream()))) {

                    String line; while ((line = bufferedReader.readLine()) != null) {

                        DataObject object = parser.parse(line).getAsObject();

                        // On fait une différence avec RENDERER
                        // pour savoir quel manager utiliser.
                        // On pourrait en utiliser qu'un seul, mais de cette manière le code est plus lisible
                        if (object.has("RENDERER")) {
                            currentRenderer = rendererActionManager.handleAction(object.get("RENDERER").getAsObject(), currentRenderer);
                        }
                        else if (currentRenderer != null) {
                            actionManager.handleAction(object, currentRenderer);
                        }
                        else {
                            throw new RuntimeException("Rendered not initialized");
                        }

                    }
                }
            } catch (SocketTimeoutException ignored) {
                // On ignore les exceptions SocketTimeoutException.
                // Elles apparaissent lorsque aucune information n'est envoyée pendant le délai du setSoTimeout
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

}
