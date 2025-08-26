using System;
using System.Configuration;
using Oracle.ManagedDataAccess.Client;

namespace InsuranceLab8
{
    public class DatabaseHelper : IDisposable
    {
        private OracleConnection _conn;

        public void OpenConnection()
        {
            var connString = ConfigurationManager.ConnectionStrings["OracleDb"].ConnectionString;
            _conn = new OracleConnection(connString);
            _conn.Open();
            Console.WriteLine("Connected to Oracle database.");
        }

        public void ExecuteLab3Query3()
        {
            string sql = @"
SELECT p.name AS owner_name,
       COUNT(pt.report_number) AS no_of_accidents,
       SUM(pt.damage_amount) AS total_damage
FROM PARTICIPATED pt
JOIN PERSON p ON p.driver_id = pt.driver_id
GROUP BY p.name
ORDER BY total_damage DESC";
            using var cmd = new OracleCommand(sql, _conn);
            using var dr = cmd.ExecuteReader();

            Console.WriteLine("OWNER_NAME\tNo_of_Accidents\tTotal_Damage");
            while (dr.Read())
            {
                Console.WriteLine($"{dr["owner_name"]}\t{dr["no_of_accidents"]}\t{dr["total_damage"]}");
            }
        }

        public void ExecuteLab4Question1()
        {
            string sql = @"
SELECT COUNT(DISTINCT p.driver_id) AS total_people
FROM ACCIDENT a
JOIN PARTICIPATED p ON a.report_number = p.report_number
WHERE EXTRACT(YEAR FROM a.accd_date) = 2008";

            using var cmd = new OracleCommand(sql, _conn);
            var result = cmd.ExecuteScalar();
            Console.WriteLine($"Total people who owned cars involved in accidents in 2008: {result}");
        }

        public void Dispose()
        {
            _conn?.Close();
            _conn?.Dispose();
        }
    }
}