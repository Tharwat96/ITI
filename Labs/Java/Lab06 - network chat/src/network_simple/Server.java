package network_simple;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private ServerSocket serverSocket;
    private Socket s1;
    private DataInputStream dataInputStream;
    private PrintStream printStream;

    public Server()
    {
        try
        {
            serverSocket = new ServerSocket(4900);
            s1 = serverSocket.accept();
            System.out.println("accepted socket");
            dataInputStream = new DataInputStream(s1.getInputStream());
            printStream = new PrintStream((s1.getOutputStream()));
            String msg = dataInputStream.readLine();
            System.out.println(msg);
            printStream.println("Bye client, this is the server.");
        } catch (IOException e) {
            e.printStackTrace();
        }

        try
        {
            printStream.close();
            dataInputStream.close();
            s1.close();
            serverSocket.close();
            System.out.println("socket closed");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {

        Server s1;
        s1 = new Server();
    }
}
