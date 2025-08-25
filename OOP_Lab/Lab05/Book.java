import java.util.Arrays;
import java.util.Scanner;

class Book implements Comparable<Book> {
    private String title;
    private String author;
    private int edition;

    // Constructor
    public Book(String title, String author, int edition) {
        this.title = title;
        this.author = author;
        this.edition = edition;
    }

    // Getter for author
    public String getAuthor() {
        return author;
    }

    // Method to display book details
    public void display() {
        System.out.println("Title: " + title + ", Author: " + author + ", Edition: " + edition);
    }

    // Method for sorting books based on title
    @Override
    public int compareTo(Book other) {
        return this.title.compareTo(other.title);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Book[] books = new Book[6];

        // Input books data
        for (int i = 0; i < books.length; i++) {
            System.out.print("Enter book " + (i + 1) + " : ");
            String title = scanner.next();
            String author = scanner.next();
            int edition = scanner.nextInt();
            books[i] = new Book(title, author, edition);
        }

        // Sort books by title
        Arrays.sort(books);

        System.out.print("Enter the author name to search: ");
        String searchAuthor = scanner.next();
        scanner.close();

        System.out.println("Books by " + searchAuthor + ":");
        for (Book book : books) {
            if (book.getAuthor().equalsIgnoreCase(searchAuthor)) {
                book.display();
            }
        }
    }
}
