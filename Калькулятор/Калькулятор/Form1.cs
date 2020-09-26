using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Калькулятор
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double nmb1, nmb2;
            nmb1 = Convert.ToDouble(textBox1.Text);
            
            nmb2 = Convert.ToDouble(textBox2.Text);
            
            switch(comboBox1.Text)
            {
                case "+":
                    textBox3.Text = Convert.ToString(nmb1 + nmb2);
                    break;

                case "-":
                    textBox3.Text = Convert.ToString(nmb1 - nmb2);
                    break;

                case "*":
                    textBox3.Text = Convert.ToString(nmb1 * nmb2);
                    break;

                case "/":
                    if (nmb2 == 0)
                    {
                        MessageBox.Show("НА НОЛЬ ДЕЛИТЬ НЕЛЬЗЯ!!!!");
                    }
                        
                    textBox3.Text = Convert.ToString(nmb1 / nmb2);
                    break;

            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            comboBox1.Text = "";
        }
      }
}
