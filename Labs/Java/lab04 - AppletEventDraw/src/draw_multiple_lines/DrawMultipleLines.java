package draw_multiple_lines;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.Vector;

public class DrawMultipleLines extends Applet{

    int x1, x2, y1, y2;
    Vector<Line> lines = new Vector<Line>(5);

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
                Line l1 = new Line(x1, y1, x2 ,y2);
                lines.add(l1);
                repaint();
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



            }


            @Override
            public void mouseMoved(MouseEvent mouseEvent) {}
        });

    }



    @Override
    public void paint(Graphics g) {
        g.setColor(Color.DARK_GRAY);
        for (Line line: lines)
        {
            g.drawLine(line.x1, line.y1, line.x2, line.y2);
//            System.out.println("x1= " + line.x1 + "y1= " + line.y1 + "x2= " + line.x2 + "y2= " + line.y2);
        }

    }

    class Line{
        int x1, x2, y1, y2;
        Line(int x1, int y1, int x2, int y2)
        {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
    }
}


