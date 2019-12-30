package group_chat;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Vector;

class ChatHandler extends Thread
{
    DataInputStream dataInputStream;
    PrintStream printStream;
    static Vector<ChatHandler> clientsVector = new Vector<ChatHandler>();


    public ChatHandler(Socket s)
    {
        try
        {
            dataInputStream = new DataInputStream(s.getInputStream());
            printStream = new PrintStream(s.getOutputStream());
            clientsVector.add(this);
            start();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }



    }

    void sendMessageToAll(String msg)
    {
        for(ChatHandler ch : clientsVector)
        {
            ch.printStream.println(msg);
        }
    }

    public void run()
    {
        while(true)
        {
            try
            {
                String str = dataInputStream.readLine();
                sendMessageToAll(str);

            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }
}
