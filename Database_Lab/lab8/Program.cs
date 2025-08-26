using System;
using System.Configuration;

namespace InsuranceLab8
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Lab 8 – VC# Frontend to Oracle Backend");

            try
            {
                using (var db = new DatabaseHelper())
                {
                    db.OpenConnection();

                    Console.WriteLine("\n--- Lab 3 Query 3: Owner Accident Summary ---");
                    db.ExecuteLab3Query3();

                    Console.WriteLine("\n--- Lab 4 Question 1: Unique Car Owners in ACCIDENT 2008 ---");
                    db.ExecuteLab4Question1();

                    // Add calls to other Lab 3 and Lab 4 queries similarly...
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }

            Console.WriteLine("\nPress Enter to exit...");
            Console.ReadLine();
        }
    }
}