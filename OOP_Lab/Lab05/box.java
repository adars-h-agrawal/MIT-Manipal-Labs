import java.util.Scanner;

class Box {
    double width, height, depth;

    Box(double width, double height, double depth){
        this.width = width;
        this.height = height;
        this.depth = depth;
    }

    double getVolume(){
        return width * height * depth;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the width of the box: ");
        double width = scanner.nextDouble();
        System.out.print("Enter the height of the box: ");
        double height = scanner.nextDouble();
        System.out.print("Enter the depth of the box: ");
        double depth = scanner.nextDouble();

        Box myBox = new Box(width, height, depth);

        double volume = myBox.getVolume();
        System.out.println("Volume of the box: " + volume);
        
        scanner.close();
    }
}