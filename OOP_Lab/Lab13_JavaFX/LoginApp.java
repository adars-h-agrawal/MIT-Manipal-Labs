import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class LoginApp extends Application {

    @Override
    public void start(Stage primaryStage) {
        // Create UI elements
        Label userNameLabel = new Label("Username:");
        TextField userNameField = new TextField();
        
        Label passwordLabel = new Label("Password:");
        PasswordField passwordField = new PasswordField();
        
        Button signInButton = new Button("Sign in");
        Text welcomeMessage = new Text();

        // Set up the button action
        signInButton.setOnAction(e -> {
            String userName = userNameField.getText();
            welcomeMessage.setText("Welcome " + userName);
        });

        // Create a GridPane layout
        GridPane gridPane = new GridPane();
        gridPane.setHgap(10);
        gridPane.setVgap(10);
        
        // Add elements to the grid
        gridPane.add(userNameLabel, 0, 0);
        gridPane.add(userNameField, 1, 0);
        gridPane.add(passwordLabel, 0, 1);
        gridPane.add(passwordField, 1, 1);
        gridPane.add(signInButton, 1, 2);
        gridPane.add(welcomeMessage, 1, 3);

        // Create a Scene with the GridPane
        Scene scene = new Scene(gridPane, 300, 200);
        
        // Set the title of the Stage
        primaryStage.setTitle("Login Application");
        
        // Set the Scene to the Stage
        primaryStage.setScene(scene);
        
        // Show the Stage
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
