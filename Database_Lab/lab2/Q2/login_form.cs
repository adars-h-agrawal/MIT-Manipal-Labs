using System;
using System.Windows.Forms;

namespace BankingApp
{
    public partial class Form1 : Form
    {
        private string storedUsername = "user123";
        private string storedPassword = "password";

        public Form1()
        {
            InitializeComponent();
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            if (txtUsername.Text == storedUsername && txtPassword.Text == storedPassword)
            {
                MessageBox.Show("Login Successful!");
                Form2 dashboard = new Form2(txtUsername.Text);
                dashboard.Show();
                this.Hide();
            }
            else
            {
                MessageBox.Show("Invalid Credentials!");
            }
        }

        private void btnChangePassword_Click(object sender, EventArgs e)
        {
            FormChangePassword changePassword = new FormChangePassword();
            changePassword.Show();
        }
    }
}