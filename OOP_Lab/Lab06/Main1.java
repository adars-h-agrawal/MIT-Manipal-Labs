import java.util.Scanner;

// Base class Account
abstract class Account {
    private String name;
    private String accNo;
    protected double balance;
    protected String accType;

    public Account(String name, String accNo, String accType) {
        this.name = name;
        this.accNo = accNo;
        this.accType = accType;
        this.balance = 0.0;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: " + amount);
        } else {
            System.out.println("Deposit amount must be positive.");
        }
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
        } else {
            System.out.println("Invalid withdrawal amount.");
        }
    }

    public void displayBalance() {
        System.out.println("Account Balance: " + balance);
    }

    public abstract void computeAndDepositInterest();

    protected abstract void checkMinimumBalance();
}

// Derived class for CurrentAccount
class CurrentAccount extends Account {
    private static final double PENALTY = 50.0; // Penalty for below minimum balance
    private static final double MIN_BALANCE = 500.0; // Minimum balance for Current Account

    public CurrentAccount(String name, String accNo) {
        super(name, accNo, "Current");
    }

    @Override
    public void withdraw(double amount) {
        super.withdraw(amount);
        checkMinimumBalance();
    }

    @Override
    protected void checkMinimumBalance() {
        if (balance < MIN_BALANCE) {
            balance -= PENALTY;
            System.out.println("Penalty applied. New Balance: " + balance);
        }
    }

    @Override
    public void computeAndDepositInterest() {
        // No interest for CurrentAccount
    }
}

// Derived class for SavingsAccount
class SavingsAccount extends Account {
    private static final double INTEREST_RATE = 0.04; // 4% annual interest rate
    private static final double MIN_BALANCE = 1000.0; // Minimum balance for Savings Account
    private static final double PENALTY = 100.0; // Penalty for below minimum balance

    public SavingsAccount(String name, String accNo) {
        super(name, accNo, "Savings");
    }

    @Override
    public void computeAndDepositInterest() {
        if (balance > MIN_BALANCE) {
            double interest = balance * INTEREST_RATE;
            deposit(interest);
            System.out.println("Interest of " + interest + " deposited. New Balance: " + balance);
        }
    }

    @Override
    protected void checkMinimumBalance() {
        if (balance < MIN_BALANCE) {
            balance -= PENALTY;
            System.out.println("Penalty applied. New Balance: " + balance);
        }
    }
}

// Main class with user input
public class Main1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter account type (Current/Savings): ");
        String type = scanner.nextLine();

        System.out.print("Enter customer name: ");
        String name = scanner.nextLine();

        System.out.print("Enter account number: ");
        String accNo = scanner.nextLine();

        Account account;
        if (type.equalsIgnoreCase("Current")) {
            account = new CurrentAccount(name, accNo);
        } else if (type.equalsIgnoreCase("Savings")) {
            account = new SavingsAccount(name, accNo);
        } else {
            System.out.println("Invalid account type.");
            return;
        }

        while (true) {
            System.out.println("\n1. Deposit\n2. Withdraw\n3. Display Balance\n4. Compute Interest\n5. Exit");
            System.out.print("Choose an option: ");
            int option = scanner.nextInt();

            switch (option) {
                case 1:
                    System.out.print("Enter deposit amount: ");
                    double depositAmount = scanner.nextDouble();
                    account.deposit(depositAmount);
                    break;
                case 2:
                    System.out.print("Enter withdrawal amount: ");
                    double withdrawAmount = scanner.nextDouble();
                    account.withdraw(withdrawAmount);
                    break;
                case 3:
                    account.displayBalance();
                    break;
                case 4:
                    account.computeAndDepositInterest();
                    break;
                case 5:
                    System.out.println("Exiting.");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid option.");
            }
        }
    }
}