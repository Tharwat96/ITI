package draw_line;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;
import java.util.Vector;

public class DrawLine extends Applet {

    int x1, x2, y1, y2;
    @Override
    public void init() {
        this.setSize(1200, 800);
        this.addMouseListener(new MouseListener(){
            @Override
            public void mouseClicked(MouseEvent mouseEvent) {}

            @Override
            public void mousePressed(MouseEvent mouseEvent) {
                x1 = mouseEvent.getX();
                y1 = mouseEvent.getY();

            }

            @Override
            public void mouseReleased(MouseEvent mouseEvent) {


            }

            @Override
            public void mouseEntered(MouseEvent mouseEvent) {}

            @Override
            public void mouseExited(MouseEvent mouseEvent) {}


        });
        this.addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent mouseEvent) {
                x2 = mouseEvent.getX();
                y2 = mouseEvent.getY();
                repaint();

            }


            @Override
            public void mouseMoved(MouseEvent mouseEvent) {}
        });
    }



    @Override
    public void paint(Graphics g) {
        g.setColor(Color.DARK_GRAY);
        g.drawLine(x1, y1, x2, y2);
    }
}
