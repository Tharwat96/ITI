package group_chat;

import java.io.*;
import java.net.Socket;
import java.nio.file.Files;
import java.util.Vector;

class ChatHandler extends Thread
{
    DataInputStream dataInputStream;
    PrintStream printStream;
    File file = new File("chat.txt");
    DataInputStream fileInputStream;
    PrintStream filePrintStream;
    PrintWriter writeFile = new PrintWriter(new FileWriter("chat.txt", true));
    static Vector<ChatHandler> clientsVector = new Vector<ChatHandler>();


    public ChatHandler(Socket s) throws IOException {
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
        FileReader fileReader = new FileReader(file);
        sendMessageToAll(fileReader.toString());


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
                if(str != null)
                    writeFile.append(str + "\n");
                sendMessageToAll(str);

            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }
}
