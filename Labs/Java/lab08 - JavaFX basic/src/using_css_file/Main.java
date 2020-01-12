package using_css_file;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.effect.Reflection;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.paint.CycleMethod;
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.Stop;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));

        Text helloWorld = new Text("Hello World");
        Reflection reflection = new Reflection();
        helloWorld.setEffect(reflection);
        helloWorld.setFont(new Font(25));
        reflection.setFraction(0.7);


        StackPane rootPane = new StackPane(helloWorld);

        Scene scene = new Scene(rootPane, 400, 300);

        scene.getStylesheets().add(getClass().getResource("style.css").toString());
        primaryStage.setTitle("Hello World");
        primaryStage.setScene(scene);
        primaryStage.show();
    }


    public static void main(String[] args) {
        Application.launch(args);
    }
}
