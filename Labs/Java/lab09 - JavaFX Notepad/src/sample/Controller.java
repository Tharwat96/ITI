package sample;

import javafx.stage.FileChooser;
import javafx.stage.Window;

import java.io.*;

public class Controller {
    private File file;
    private FileOutputStream fileOutputStream;
    private FileReader fileReader;
    private FileWriter fileWriter;


    Controller()
    {
        file = null;
        fileOutputStream = null;
        fileReader = null;
        fileWriter = null;
    }



    public File getFile()
    {
        return file;
    }

}
