package sample;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import javafx.stage.Window;

import java.io.*;
import java.nio.file.Files;

import static java.nio.file.Files.readAllBytes;

public class Main extends Application {
    Controller controller = new Controller();
    TextArea textArea;
    File fileOpened;
    private FileChooser fileChooser = new FileChooser();



    @Override
    public void start(Stage primaryStage) throws Exception{


        /*Add top menus and their submenus*/

        /*FILE menu*/
        Menu file = new Menu("File");
        MenuItem neo = new MenuItem("New");
        MenuItem open = new MenuItem("Open...");
        MenuItem save = new MenuItem("Save");
        SeparatorMenuItem sep1 = new SeparatorMenuItem();
        MenuItem exit = new MenuItem("Exit");
        file.getItems().addAll(neo, open, save, sep1, exit);

            /*Event handlers*/
        //neo "new" event
        neo.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                textArea.setText("");
            }
        });
        //open event
        open.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try
                {
                    openFile(primaryStage);
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
                primaryStage.setTitle(fileOpened.getName());
            }
        });
        //save event
        save.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                try {
                    saveFile(primaryStage);
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
        });
        //exit event
        exit.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                primaryStage.close();
            }
        });



        /*EDIT menu*/
        Menu edit = new Menu("Edit");
        SeparatorMenuItem sep2 = new SeparatorMenuItem();
        MenuItem undo = new MenuItem("Undo");
        MenuItem cut = new MenuItem("Cut");
        MenuItem copy = new MenuItem("Copy");
        MenuItem paste = new MenuItem("Paste");
        MenuItem delete = new MenuItem("Delete");
        SeparatorMenuItem sep3 = new SeparatorMenuItem();
        MenuItem selectAll = new MenuItem("Select All");
        edit.getItems().addAll(undo, sep2, cut, copy, paste, delete, sep3, selectAll);


        /*About menu*/
        Menu about = new Menu("About");
        MenuItem aboutApp = new MenuItem("About FX Notepad");
        about.getItems().addAll(aboutApp);
        /*Compile menu TODO*/

        /*create MenuBar and add menus to them*/
        MenuBar topBar = new MenuBar();
        topBar.getMenus().addAll(file, edit, about);


        textArea = new TextArea();
        /*Main panel*/
        BorderPane rootPane = new BorderPane();
        rootPane.setTop(topBar);
        rootPane.setCenter(textArea);

        /*set primary scene*/
        primaryStage.setTitle("FX Notepad");
        Scene scene = new Scene(rootPane, 700, 700);
        primaryStage.setScene(scene);
        primaryStage.show();
    }


    public void openFile(Window stage) throws IOException {
        String line;
        fileOpened = fileChooser.showOpenDialog(stage);
        byte[] bytes = Files.readAllBytes(fileOpened.toPath());
        String lines = new String(bytes);
        textArea.setText(lines);


    }

    public void saveFile(Window stage) throws IOException {
        String lines = new String(textArea.getText());
        byte[] bytes = lines.getBytes();
        Files.write(fileOpened.toPath(), bytes);
    }

    public void saveAsFile(Window stage) throws IOException {
        String line;
        fileOpened = fileChooser.showSaveDialog(stage);
        byte[] bytes = Files.readAllBytes(fileOpened.toPath());
        String lines = new String(bytes);
        textArea.setText(lines);

    }


    public static void main(String[] args) {
        Application.launch(args);
    }
}
