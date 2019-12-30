package group_chat;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class ChatClient{
    private SampleUI ui;
    private Socket s;
    private DataInputStream dataInputStream;
    private PrintStream printStream;
    Thread th1;
    public ChatClient()
    {
        ui = new SampleUI(this);
        ui.setSize(400, 500);
        ui.setVisible(true);
        try
        {
            s = new Socket("127.0.0.1", 4800);
            System.out.println("s.getPort()");
            dataInputStream = new DataInputStream(s.getInputStream());
            printStream = new PrintStream(s.getOutputStream());
            new Thread(new Runnable() {
                @Override
                public void run() {
                    while(true)
                    {
                        try
                        {
                        String str = dataInputStream.readLine();
                        ui.appendTextArea(str);
                        }
                        catch (IOException e) {
                        e.printStackTrace();
                        }
                    }
                }
            }).start();

        }
        catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }


    }

    public static void main(String[] args) {
        ChatClient chatClient1 = new ChatClient();
        ChatClient chatClient2 = new ChatClient();
    }
    public void sendMsg(String s)
    {
        printStream.println(s);
    }

}
