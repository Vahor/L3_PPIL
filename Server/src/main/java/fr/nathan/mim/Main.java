package fr.nathan.mim;

import fr.nathan.mim.api.data.Parser;
import fr.nathan.mim.api.data.json.JsonParser;
import fr.nathan.mim.server.PacketListener;

import java.io.IOException;

public class Main {

    public static Parser currentParser = new JsonParser();

    public static void main(String[] args) {
        try {
            PacketListener packetListener = new PacketListener(10000);
            packetListener.setName("PacketListener");
            packetListener.join();
            packetListener.start();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
