package graphics_lamp;

import java.applet.Applet;
import java.awt.*;

public class DrawLamp extends Applet {

    @Override
    public void init() {
        resize(1200,800);
    }

    public void paint(Graphics g)
    {
        g.drawOval(500, 50, 220, 34);   // top oval
        g.drawLine(500, 70 , 465, 204); //left line from top oval
        g.drawLine(720, 70 , 759, 204);   //right line from top oval
        g.drawArc(465, 170, 294, 60, 0, -180);  //arc from left to right oval
        g.drawLine(590, 230, 570, 320); //left line coming down from the arc
        g.drawLine(630, 230, 650, 320);   //right line coming down from the arc
        g.setColor(Color.DARK_GRAY);
        g.fillRect(505, 318, 210, 20);
        g.setColor(Color.GREEN);
        g.drawRect(505, 318, 210, 20);
        g.setColor(Color.GREEN);
        g.fillOval(520, 100, 30, 100);
        g.setColor(Color.DARK_GRAY);
        g.fillOval(580, 100, 65, 100);
        g.setColor(Color.GREEN);
        g.fillOval(675, 100, 30, 100);
    }

}
