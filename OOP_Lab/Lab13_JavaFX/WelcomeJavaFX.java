import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;
import javafx.scene.paint.Color;

public class WelcomeJavaFX extends Application {

    @Override
    public void start(Stage primaryStage) {
        // Create a Label
        Label welcomeLabel = new Label("Welcome to JavaFX programming");
        
        // Set the text color to Magenta
        welcomeLabel.setTextFill(Color.MAGENTA);
        
        // Create a FlowPane layout
        FlowPane flowPane = new FlowPane();
        flowPane.setHgap(10); // Horizontal gap
        flowPane.setVgap(10); // Vertical gap
        
        // Add the Label to the FlowPane
        flowPane.getChildren().add(welcomeLabel);
        
        // Create a Scene with the FlowPane
        Scene scene = new Scene(flowPane, 500, 200);
        
        // Set the title of the Stage
        primaryStage.setTitle("This is the first JavaFX Application");
        
        // Set the Scene to the Stage
        primaryStage.setScene(scene);
        
        // Show the Stage
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}

/*
When you run the program, a window should appear displaying the message 
"Welcome to JavaFX programming" in magenta color, with the title 
"This is the first JavaFX Application" and a window size of 500x200 pixels.
 */