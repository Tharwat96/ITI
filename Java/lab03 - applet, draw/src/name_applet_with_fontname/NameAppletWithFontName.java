package name_applet_with_fontname;

import java.applet.Applet;
import java.awt.*;

public class NameAppletWithFontName extends Applet
{
    String[] strFont;

    @Override
    public void init() {
//        super.init();
//        strFont = Toolkit.getDefaultToolkit().getFontList();          //built-in java fonts
        resize(1200, 800);
        strFont = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();          //OS fonts
    }

    public void paint(Graphics g)
    {
        int i=0;
        for(String value:strFont)
        {
            Font f1 = new Font(value,Font.BOLD,20);
            g.setFont(f1);
            g.drawString("Hello world " + value, 80, 100+i*30);
            i++;
        }
    }

}
