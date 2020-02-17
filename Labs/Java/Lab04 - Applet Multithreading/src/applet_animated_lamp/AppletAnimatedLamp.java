package applet_animated_lamp;

import java.applet.Applet;
import java.awt.*;

public class AppletAnimatedLamp extends Applet implements Runnable {

    Color[] cArr;
    Color c1, c2, c3;
    Thread th1;
    int i = 0;

    @Override
    public void init() {
        resize(1200,800);
        cArr = new Color[25];
        cArr[0] = Color.WHITE;
        cArr[1] = Color.lightGray;
        cArr[2] = Color.LIGHT_GRAY;
        cArr[3] = Color.gray;
        cArr[4] = Color.GRAY;
        cArr[5] = Color.darkGray;
        cArr[6] = Color.DARK_GRAY;
        cArr[7] = Color.black;
        cArr[8] = Color.BLACK;
        cArr[9] = Color.red;
        cArr[10] = Color.RED;
        cArr[11] = Color.pink;
        cArr[12] = Color.PINK;
        cArr[13] = Color.orange;
        cArr[14] = Color.ORANGE;
        cArr[15] = Color.yellow;
        cArr[16] = Color.YELLOW;
        cArr[17] = Color.green;
        cArr[18] = Color.GREEN;
        cArr[19] = Color.magenta;
        cArr[20] = Color.MAGENTA;
        cArr[21] = Color.cyan;
        cArr[22] = Color.CYAN;
        cArr[23] = Color.blue;
        cArr[24] = Color.BLUE;


        th1 = new Thread(this);

        th1.start();
    }

    public void paint(Graphics g)
    {
        g.drawOval(500, 50, 220, 34);   // top oval
        g.drawLine(500, 70 , 465, 204); //left line from top oval
        g.drawLine(720, 70 , 759, 204);   //right line from top oval
        g.drawArc(465, 170, 294, 60, 0, -180);  //arc from left to right oval
        g.drawLine(590, 230, 570, 320); //left line coming down from the arc
        g.drawLine(630, 230, 650, 320);   //right line coming down from the arc
        g.setColor(c1);
        g.fillRect(505, 318, 210, 20);
        g.setColor(c2);
        g.drawRect(505, 318, 210, 20);
        g.setColor(c2);
        g.fillOval(520, 100, 30, 100);
        g.setColor(c3);
        g.fillOval(580, 100, 65, 100);
        g.setColor(c2);
        g.fillOval(675, 100, 30, 100);
    }

    @Override
    public void run()
    {
        System.out.println("test1");

        while (true)
        {
            repaint();
            System.out.println("test");
            if (i >= 10)
                i = 0;

            c1 = cArr[i];
            c2 = cArr[i + 7];
            c3 = cArr[i + 13];
            i++;
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }
}
