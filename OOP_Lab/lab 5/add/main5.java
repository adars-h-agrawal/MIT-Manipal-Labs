class Square {
    
    // Method to calculate square of integer
    int square(int x) {
        return x * x;
    }

    // Method to calculate square of double
    double square(double x) {
        return x * x;
    }

    public static void main5(String[] args) {
        Square sq = new Square();
        System.out.println("Square of 3: " + sq.square(3));       // Integer
        System.out.println("Square of 0.2: " + sq.square(0.2));   // Double
    }
}
