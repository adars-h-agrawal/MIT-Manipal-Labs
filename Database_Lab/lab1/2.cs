using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace student_registration_form
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String name = textBox1.Text;
            String age = textBox2.Text;
            String dob = dateTimePicker1.Text;
            String address = textBox4.Text;
            String contact_number = textBox3.Text;
            String gender = null;
            String course = comboBox1.Text;
            if (radioButton1.Checked)
                gender = "Male";
            else if (radioButton2.Checked)
                gender = "Female";
            else if (radioButton3.Checked)
                gender = "Other";


            MessageBox.Show("Name: " + name + "\nAge: " + age + "\nDate of Birth: " + dob + "\nAddress: " + address + "\nConatct Number: " + contact_number + "\nGender: " + gender + "\nCourse: " + course + "\n\n\n" + "CONFIRM OR NOT");
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            comboBox1.Items.Add("Computer Science");
            comboBox1.Items.Add("Information Technology");
            comboBox1.Items.Add("Mechanical");
            comboBox1.Items.Add("Electrical");
            comboBox1.Items.Add("Chemical");
            comboBox1.Items.Add("Civil");

        }
       
    }
}