package sample;

import javafx.stage.FileChooser;
import javafx.stage.Window;

import java.io.*;

public class Controller {
    private File file;
    private FileOutputStream fileOutputStream;
    private FileReader fileReader;
    private FileWriter fileWriter;
    final FileChooser fileChooser = new FileChooser();


    Controller()
    {
        file = null;
        fileOutputStream = null;
        fileReader = null;
        fileWriter = null;
    }

    public void openFile(Window stage) throws FileNotFoundException {
        file = fileChooser.showOpenDialog(stage);
        FileInputStream fileInputStream = new FileInputStream(file);
        fileReader.read();

    }

    public File getFile()
    {
        return file;
    }

}
