using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Oracle.DataAccess.Types;
using Oracle.DataAccess.Client;
namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        OracleCommand comm;
        OracleConnection conn;
        OracleDataAdapter da;
        DataSet ds;
        DataTable dt;

        public Form1()
        {
            InitializeComponent();
        }

        private void connect()
        {
            string oradb = "DATA SOURCE=172.16.54.24:1521/ictorcl;USER ID=IT230911264;Password=student";
            conn = new OracleConnection(oradb);
            conn.Open();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            connect();

            comm = new OracleCommand();
            comm.CommandText = "SELECT * FROM ACCIDENT";
            comm.CommandType = CommandType.Text;

            ds = new DataSet();
            da = new OracleDataAdapter(comm.CommandText, conn);
            da.Fill(ds, "ACCIDENT");

            dt = ds.Tables["ACCIDENT"];
            int t = dt.Rows.Count;
            MessageBox.Show(t.ToString());

            string output = "";

            // Loop through each row in the table
            for (int i = 0; i < dt.Rows.Count; i++)
            {
                // Loop through each column in the row
                for (int j = 0; j < dt.Columns.Count; j++)
                {
                    output += dt.Rows[i][j].ToString() + "\t";  // Add tab between columns
                }
                output += Environment.NewLine;  // New line after each row
            }

            // textBox1.Multiline = true;
            // textBox1.ScrollBars = ScrollBars.Vertical;
            textBox1.Text = output;

            conn.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            connect();
            MessageBox.Show("Connection Establishe");
            conn.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            connect();

            comm = new OracleCommand();
            comm.CommandText = "SELECT * FROM ACCIDENT";
            comm.CommandType = CommandType.Text;

            ds = new DataSet();
            da = new OracleDataAdapter(comm.CommandText, conn);
            da.Fill(ds, "ACCIDENT");

            dt = ds.Tables["ACCIDENT"];
            int t = dt.Rows.Count;
            MessageBox.Show(t.ToString());

            string output = "";

            // Loop through each row in the table
            for (int i = 0; i < dt.Rows.Count; i++)
            {
                // Loop through each column in the row
                for (int j = 0; j < dt.Columns.Count; j++)
                {
                    output += dt.Rows[i][j].ToString() + "\t";  // Add tab between columns
                }
                output += Environment.NewLine;  // New line after each row
            }

            dataGridView1.DataSource = ds;
            dataGridView1.DataMember = "ACCIDENT";

            conn.Close();
        }
    }
}