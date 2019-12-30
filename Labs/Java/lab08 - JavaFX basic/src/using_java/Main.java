package using_java;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.effect.Reflection;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.*;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));

        Text helloWorld = new Text("Hello World");
        helloWorld.setStyle("-fx-fill: red;");
        Reflection reflection = new Reflection();
        helloWorld.setEffect(reflection);
        Rectangle rect = new Rectangle(0,0, 400, 300);
        helloWorld.setFont(new Font(25));
        reflection.setFraction(0.7);
        Stop[] stops = new Stop[] { new Stop(1, Color.BLACK),new Stop(0.5, Color.WHITE), new Stop( 0, Color.BLACK) };
        LinearGradient linearGradient = new LinearGradient(0, 1, 0, 0, true, CycleMethod.NO_CYCLE, stops);
        rect.setFill(linearGradient);;


        StackPane rootPane = new StackPane(rect);
        rootPane.getChildren().add(helloWorld);


        Scene scene = new Scene(rootPane, 400, 300);


        primaryStage.setTitle("Hello World");
        primaryStage.setScene(scene);
        primaryStage.show();
    }


    public static void main(String[] args) {
        Application.launch(args);
    }
}
