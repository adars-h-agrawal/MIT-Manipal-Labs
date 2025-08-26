using System;
using System.Windows.Forms;

namespace BankingApp
{
    public partial class Form2 : Form
    {
        private string username;
        private double balance = 5000.0;
        private string lastAccess = DateTime.Now.ToString("dd/MM/yyyy HH:mm");
        private string[] lastTransactions = { "Paid ₹1000", "Received ₹500", "Paid ₹200", "Received ₹1000", "Paid ₹50" };

        public Form2(string user)
        {
            InitializeComponent();
            username = user;
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            lblUsername.Text = "Welcome, " + username;
            lblBalance.Text = "Balance: ₹" + balance.ToString();
            lblLastAccess.Text = "Last Access: " + lastAccess;
            listBoxTransactions.Items.AddRange(lastTransactions);
        }

        private void btnTransfer_Click(object sender, EventArgs e)
        {
            Form3 transferForm = new Form3(balance);
            transferForm.Show();
        }
    }
}