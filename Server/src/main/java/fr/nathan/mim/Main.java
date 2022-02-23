package fr.nathan.mim;

import fr.nathan.mim.api.data.Parser;
import fr.nathan.mim.api.data.json.JsonParser;
import fr.nathan.mim.server.PacketListener;

import java.io.IOException;

public class Main {

    // Json est l'interpréteur par défaut
    public static Parser currentParser = new JsonParser();

    public static void main(String[] args) {
        try {
            // Lancement de la boucle de reception de packet
            PacketListener packetListener = new PacketListener(10000);
            packetListener.setName("PacketListener");
            packetListener.join();
            packetListener.start();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
