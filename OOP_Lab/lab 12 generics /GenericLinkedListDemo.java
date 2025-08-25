class GenericLinkedList<T> {
    private static class Node<T> {
        T data;
        Node<T> next;

        Node(T data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node<T> head;

    // Add element to the end of the list
    public void add(T data) {
        Node<T> newNode = new Node<>(data);
        if (head == null) {
            head = newNode;
        } else {
            Node<T> current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    // Print the list
    public void printList() {
        Node<T> current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }

    // Get the size of the list
    public int size() {
        int count = 0;
        Node<T> current = head;
        while (current != null) {
            count++;
            current = current.next;
        }
        return count;
    }
}

public class GenericLinkedListDemo {
    public static void main(String[] args) {
        // Linked List for Integer
        GenericLinkedList<Integer> integerList = new GenericLinkedList<>();
        integerList.add(1);
        integerList.add(2);
        integerList.add(3);
        System.out.println("Integer Linked List:");
        integerList.printList();

        // Linked List for Double
        GenericLinkedList<Double> doubleList = new GenericLinkedList<>();
        doubleList.add(1.1);
        doubleList.add(2.2);
        doubleList.add(3.3);
        System.out.println("Double Linked List:");
        doubleList.printList();
    }
}

/*
Integer Linked List:
1 -> 2 -> 3 -> null
Double Linked List:
1.1 -> 2.2 -> 3.3 -> null
 */