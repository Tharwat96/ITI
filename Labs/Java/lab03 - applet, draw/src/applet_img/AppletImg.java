package applet_img;

import java.applet.Applet;
import java.awt.*;
import java.net.URL;

public class AppletImg extends Applet {
    Image img;
    @Override
    public void init() {
        try
        {
            URL imgUrl = this.getClass().getResource("Dream-Image-With-Quote.jpg");
            img = getImage(imgUrl);
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }

    @Override
    public void paint(Graphics g) {
        g.drawImage(img, 0, 0, getWidth(),getHeight(), this);
    }
}
