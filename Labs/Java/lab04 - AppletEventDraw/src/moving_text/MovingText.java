package moving_text;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class MovingText extends Applet {

    int x, y;
    @Override
    public void init() {
        setFocusable(true);
        requestFocusInWindow(true);
        this.setSize(150, 150);
        x = getWidth()/2-10;
        y = getHeight()/2;
        this.addKeyListener(new KeyListener(){

            @Override
            public void keyTyped(KeyEvent keyEvent) {

            }

            public void keyPressed(KeyEvent keyEvent)
            {
                switch (keyEvent.getKeyCode())
                {
                    case (KeyEvent.VK_UP):      //case arrow up
                        if(y <= 5)
                            y = getHeight();
                        else
                            y = y-10;
                        repaint();
                        break;


                    case (KeyEvent.VK_DOWN):        //case arrow down
                        if(y >= getHeight())
                            y = 5;
                        else
                            y = y+10;
                        repaint();
                        break;

                    case (KeyEvent.VK_LEFT):        //case arrow left
                        if(x <= 0)
                            x = getWidth() - 5;
                        else
                            x = x-10;
                        repaint();
                        break;


                    case (KeyEvent.VK_RIGHT):       //case arrow right
                        if(x >= getWidth())
                            x = 5;
                        else
                            x = x + 10;                        repaint();
                        break;
                }

            }

            @Override
            public void keyReleased(KeyEvent keyEvent) {

            }
        });
    }

    @Override
    public void paint(Graphics g) {
        g.drawString("JAVA", x, y);
    }



}
