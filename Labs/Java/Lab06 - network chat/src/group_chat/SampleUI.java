package group_chat;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SampleUI extends JFrame {
    private ChatClient chatClient;
    private JTextArea ta;
    private JScrollPane scroll;
    private JTextField tf;
    private JButton okButton;
    public SampleUI(ChatClient chatClient){
        this.chatClient = chatClient;
        this.setLayout(new FlowLayout());
        ta=new JTextArea(5,35);
        scroll=new JScrollPane(ta);
        scroll.setViewportView(ta);
        tf=new JTextField(30);
        okButton=new JButton("Send");
        okButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent ae){
                String str = tf.getText();
                chatClient.sendMsg(str);
                tf.setText("");
//                ta.append(tf.getText()+"\n");
            }
        });
        add(scroll);
        add(tf);
        add(okButton);
    }

    public String getTextField()
    {
        return tf.getText();
    }

    public void appendTextArea(String str)
    {
        ta.append(str +"\n");
    }


}
