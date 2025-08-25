import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;

public class MultiplicationTable extends Application {

    @Override
    public void start(Stage primaryStage) {
        // Create UI elements
        TextField inputField = new TextField();
        inputField.setPromptText("Enter an integer");

        Button generateButton = new Button("Generate Table");
        Label resultLabel = new Label();

        // Set up the button action
        generateButton.setOnAction(e -> {
            String input = inputField.getText();
            try {
                int number = Integer.parseInt(input);
                StringBuilder table = new StringBuilder();
                for (int i = 1; i <= 10; i++) {
                    table.append(number).append(" x ").append(i).append(" = ").append(number * i).append("\n");
                }
                resultLabel.setText(table.toString());
            } catch (NumberFormatException ex) {
                resultLabel.setText("Please enter a valid integer.");
            }
        });

        // Create a FlowPane layout
        FlowPane flowPane = new FlowPane();
        flowPane.setHgap(10);
        flowPane.setVgap(10);
        flowPane.getChildren().addAll(inputField, generateButton, resultLabel);

        // Create a Scene with the FlowPane
        Scene scene = new Scene(flowPane, 400, 200);
        
        // Set the title of the Stage
        primaryStage.setTitle("Multiplication Table Generator");
        
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
5 x 1 = 5
5 x 2 = 10
5 x 3 = 15
5 x 4 = 20
5 x 5 = 25
5 x 6 = 30
5 x 7 = 35
5 x 8 = 40
5 x 9 = 45
5 x 10 = 50
 */