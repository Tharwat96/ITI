package sample;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class Main extends Application {
    Controller controller = new Controller();


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
        //open event
        open.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                controller.openFile(primaryStage);

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


        TextArea textArea = new TextArea();

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




    public static void main(String[] args) {
        Application.launch(args);
    }
}
