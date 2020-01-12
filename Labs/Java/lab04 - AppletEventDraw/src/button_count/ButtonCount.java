package button_count;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ButtonCount extends Applet {
    int x;

    Button b1;
    Button b2;
    @Override
    public void init() {
        b1 = new Button("Increment");
        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                if(x >= 0 & x < 10)
                    x++;
                repaint();
            }
        });

        b2 = new Button("Decrement");
        b2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                if(x > 0 & x <= 10)
                    x--;
                repaint();
            }
        });
        add(b1);
        add(b2);
        x = 0;
    }


    @Override
    public void paint(Graphics g) {
        g.drawString("x = " + x, 150, 150);
    }
}
