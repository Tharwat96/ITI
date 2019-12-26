package network_simple;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Client {

    private Socket s1;
    private DataInputStream dataInputStream;
    private PrintStream printStream;

    public Client()
    {
        try
        {
            s1 = new Socket("127.0.0.1", 4900);
            dataInputStream = new DataInputStream(s1.getInputStream());
            printStream = new PrintStream((s1.getOutputStream()));
            printStream.println("Hi server, I'm client");
            String msg = dataInputStream.readLine();
            System.out.println(msg);
        } catch (IOException e) {
            e.printStackTrace();
        }

        try
        {
            printStream.close();
            dataInputStream.close();
            s1.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        Client c1;
        c1 = new Client();

    }

}
