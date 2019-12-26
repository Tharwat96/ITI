package group_chat;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;



public class ChatServer {
    private ServerSocket serverSocket;
    private Socket s;
    private ChatServer chatServer1;
    private ChatHandler ch;


    public ChatServer() throws IOException {
        while(true)
        {
            try
            {
                serverSocket = new ServerSocket(4900);
                Socket s = serverSocket.accept();
                System.out.println("accepted socket");
                ch = new ChatHandler(s);


            }

            catch (IOException e) {
//                e.printStackTrace();
            }
//            try
//            {
//                s.close();
//                serverSocket.close();
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
        }
    }


    public static void main(String[] args) {
        try
        {
            ChatServer chatServer = new ChatServer();
        }
        catch (IOException e) {
//            e.printStackTrace();
        }
    }
}

