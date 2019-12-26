package applet_marqueestring;

import java.applet.Applet;
import java.awt.*;

public class AppletMarqueeString extends Applet implements Runnable {

    Thread th1;
    int x;
    int y;
    @Override
    public void init() {
        x = 0;
        y = 100;
        th1 = new Thread(this);
        th1.start();
    }

    @Override
    public void paint(Graphics g) {
        Font f1 = new Font("FreeMono",Font.BOLD,50);
        g.setFont(f1);
        g.drawString("JAVA World", x, y);
    }

    @Override
    public void run() {
        while(true)
        {
            repaint();
            if(x >=0 && x <400)
            x++;
            else if(x >= 400)
            {
                x = 0;
            }
            try {
                Thread.sleep(30);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
