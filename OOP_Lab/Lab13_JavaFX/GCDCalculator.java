import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class GCDCalculator extends Application {

    // Method to calculate GCD of two numbers
    private int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    @Override
    public void start(Stage primaryStage) {
        // Create UI elements
        Label number1Label = new Label("Enter first positive integer:");
        TextField number1Field = new TextField();
        
        Label number2Label = new Label("Enter second positive integer:");
        TextField number2Field = new TextField();
        
        Button calculateButton = new Button("Calculate GCD");
        Label resultLabel = new Label();

        // Set up the button action
        calculateButton.setOnAction(e -> {
            try {
                int num1 = Integer.parseInt(number1Field.getText());
                int num2 = Integer.parseInt(number2Field.getText());

                if (num1 <= 0 || num2 <= 0) {
                    resultLabel.setText("Please enter positive integers.");
                } else {
                    int gcd = calculateGCD(num1, num2);
                    resultLabel.setText("GCD of " + num1 + " and " + num2 + " is " + gcd);
                }
            } catch (NumberFormatException ex) {
                resultLabel.setText("Please enter valid integers.");
            }
        });

        // Create a GridPane layout
        GridPane gridPane = new GridPane();
        gridPane.setHgap(10);
        gridPane.setVgap(10);
        
        // Add elements to the grid
        gridPane.add(number1Label, 0, 0);
        gridPane.add(number1Field, 1, 0);
        gridPane.add(number2Label, 0, 1);
        gridPane.add(number2Field, 1, 1);
        gridPane.add(calculateButton, 1, 2);
        gridPane.add(resultLabel, 1, 3);

        // Create a Scene with the GridPane
        Scene scene = new Scene(gridPane, 400, 200);
        
        // Set the title of the Stage
        primaryStage.setTitle("GCD Calculator");
        
        // Set the Scene to the Stage
        primaryStage.setScene(scene);
        
        // Show the Stage
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
