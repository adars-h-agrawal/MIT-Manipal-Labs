using System;
using System.Windows.Forms;

namespace BankingApp
{
    public partial class Form3 : Form
    {
        private double currentBalance;

        public Form3(double balance)
        {
            InitializeComponent();
            currentBalance = balance;
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            comboBoxBeneficiary.Items.Add("Amit Sharma");
            comboBoxBeneficiary.Items.Add("Rahul Verma");
            comboBoxBeneficiary.Items.Add("Neha Singh");
        }

        private void btnTransfer_Click(object sender, EventArgs e)
        {
            double amount;
            if (double.TryParse(txtAmount.Text, out amount) && amount > 0)
            {
                if (amount <= currentBalance)
                {
                    currentBalance -= amount;
                    MessageBox.Show($"₹{amount} Transferred to {comboBoxBeneficiary.SelectedItem}.\nNew Balance: ₹{currentBalance}");
                }
                else
                {
                    MessageBox.Show("Insufficient Balance!");
                }
            }
            else
            {
                MessageBox.Show("Enter a valid amount!");
            }
        }
    }
}