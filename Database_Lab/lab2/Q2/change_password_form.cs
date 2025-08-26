using System;
using System.Windows.Forms;

namespace BankingApp
{
    public partial class FormChangePassword : Form
    {
        private string storedPassword = "password";  // Simulated stored password

        public FormChangePassword()
        {
            InitializeComponent();
        }

        private void btnUpdatePassword_Click(object sender, EventArgs e)
        {
            if (txtOldPassword.Text == storedPassword)
            {
                if (txtNewPassword.Text == txtConfirmPassword.Text)
                {
                    storedPassword = txtNewPassword.Text;
                    MessageBox.Show("Password Updated Successfully!");
                    this.Close();
                }
                else
                {
                    MessageBox.Show("New Password and Confirm Password do not match!");
                }
            }
            else
            {
                MessageBox.Show("Incorrect Old Password!");
            }
        }
    }
}