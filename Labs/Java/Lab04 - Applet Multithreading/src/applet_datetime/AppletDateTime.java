package applet_datetime;

import java.applet.Applet;
import java.awt.*;
import java.util.Date;

public class AppletDateTime extends Applet implements Runnable
{
    Thread th1;
    @Override
    public void init()
    {
        th1 = new Thread(this);
        th1.start();
    }

    @Override
    public void paint(Graphics g)
    {
        Font f1 = new Font("FreeMono",Font.BOLD,50);
        g.setFont(f1);
        Date d = new Date();
        g.drawString(d.toString(),50, 100);
    }

    @Override
    public void run() {
        while(true)
        {
            repaint();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }
}
