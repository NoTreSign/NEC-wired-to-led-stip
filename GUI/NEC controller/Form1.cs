using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;



namespace NEC_controller
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            CheckComPorts();
            

        
        }

        private void SelectMode_SelectedIndexChanged(object sender, EventArgs e)
        {
           // CheckComPorts();
            if (SelectMode.GetSelected(0))
            {
                textBox1.Clear();
                kyMChkBx.Checked = true;
                kyMChkBx2.Checked = false;
                KeyControlls48.Visible = true;
                textBox1.AppendText("48 KEYMODE SELECTED\n");
            }
            else if (SelectMode.GetSelected(1))
            {
                textBox1.Clear();
                kyMChkBx2.Checked=true;
                kyMChkBx.Checked = false;
                KeyControlls48.Visible = false;
                textBox1.AppendText("24 KEYMODE SELECTED\n");
            }
        }

        private void RED48_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("RED 48 SELECTED\n");
            SendCommand('R');
        }

        private void GREEN48_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("GREEN 48 SELECTED\n");
            SendCommand('G');
        }

        private void BLUE48_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("BLUE 48 SELECTED\n");
            SendCommand('B');
        }

        private void WHITE48_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("WHITE 48 SELECTED\n");
            SendCommand('W');
        }

        private void X0Y0_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X0Y0 48 SELECTED\n");
        }

        private void X1Y0_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X1Y0 48 SELECTED\n");
        }

        private void X2Y0_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X2Y0 48 SELECTED\n");
        }

        private void X3Y0_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X3Y0 48 SELECTED\n");
        }

        private void X0Y1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X0Y1 48 SELECTED\n");
        }

        private void X1Y1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X1Y1 48 SELECTED\n");
        }

        private void X2Y1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X2Y1 48 SELECTED\n");
        }

        private void X3Y1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X3Y1 48 SELECTED\n");
        }

        private void X0Y2_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X0Y2 48 SELECTED\n");
        }

        private void X1Y2_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X1Y2 48 SELECTED\n");
        }

        private void X2Y2_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X2Y2 48 SELECTED\n");
        }

        private void X3Y2_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X3Y2 48 SELECTED\n");
        }

        private void X0Y3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X0Y3 48 SELECTED\n");
        }

        private void X1Y3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X1Y3 48 SELECTED\n");
        }

        private void X2Y3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X2Y3 48 SELECTED\n");
        }

        private void X3Y3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X3Y3 48 SELECTED\n");
        }

        private void BRIGHT_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("BRIGHT 48 SELECTED\n");
        }

        private void DIM_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIM 48 SELECTED\n");
        }

        private void PAUZE_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("PAUZE 48 SELECTED\n");
            SendCommand('1');
        }

        private void TOGGLE_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("TOGGLE ON/OFF 48 SELECTED\n");
            SendCommand('0');
        }

        private void REDUP_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("REDUP 48 SELECTED\n");
        }

        private void GREENUP_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("GREENUP 48 SELECTED\n");
        }

        private void BLUEUP_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("BLUEUP 48 SELECTED\n");
        }

        private void QUICK_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("QUICK 48 SELECTED\n");
        }

        private void REDDOWN_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("REDDOWN 48 SELECTED\n");
        }

        private void GREENDOWN_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("GREENDOWN 48 SELECTED\n");
        }

        private void BLUEDOWN_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("BLUEDOWN 48 SELECTED\n");
        }

        private void SLOW_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("SLOW 48 SELECTED\n");
        }

        private void DIY1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIY1 48 SELECTED\n");
        }

        private void DIY2_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIY2 48 SELECTED\n");
        }

        private void DIY3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIY3 48 SELECTED\n");
        }

        private void AUTO_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("AUTO 48 SELECTED\n");
        }

        private void DIY4_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIY4 48 SELECTED\n");
        }

        private void DIY5_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIY5 48 SELECTED\n");
        }

        private void DIY6_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIY6 48 SELECTED\n");
        }

        private void FLASH_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("FLASH 48 SELECTED\n");
        }

        private void JUMP3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("JUMP3 48 SELECTED\n");
        }

        private void JUMP7_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("JUMP7 48 SELECTED\n");
        }

        private void FADE3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("FADE3 48 SELECTED\n");
        }

        private void FADE7_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("FADE7 48 SELECTED\n");
        }

        private void DebugcheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (DebugcheckBox.Checked == false)
            {
                this.Size = new Size(573, 333);
                
            }
            else
            {
                this.Size = new Size(573, 433);
            }


        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
        
        
        private void ComPortSelector_SelectedIndexChanged_1(object sender, EventArgs e)
        {
            textBox1.AppendText(ComPortSelector.GetItemText(ComPortSelector.SelectedItem) + " selected\n");
            OpenComPort( ComPortSelector.GetItemText(ComPortSelector.SelectedItem) );
        }

        private void CheckComPorts (){
            //int i = ComPortSelector.Count();
            //ComPortSelector.
            string[] ports = System.IO.Ports.SerialPort.GetPortNames();
            foreach (String s in ports)
            {
                ComPortSelector.Items.Add(s);
            }
        }

        private void SendCommand(char command)
        {
            char [] commandoutput = new char[3];
            commandoutput[0]= '#';
            commandoutput[1]=command;
            commandoutput[2]='$';
            String sendcommand = new String(commandoutput);
            if (ComPortSelector.SelectedIndex != -1)
            {
                
                    serialPort1.Write(sendcommand);
                    textBox1.AppendText("COMMAND SEND: " + sendcommand + "\n");
            }
        }

        private void OpenComPort(String ComName)
        {
            serialPort1.Close();
            serialPort1.PortName = ComName;
            serialPort1.DataBits = 8;
            serialPort1.Parity = Parity.None;
            serialPort1.StopBits = StopBits.One;
            serialPort1.BaudRate = 9600;
            serialPort1.Open();

        }


        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            serialPort1.Close();
        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            String receivedData = serialPort1.ReadExisting();
            textBox1.ForeColor = Color.Green;
            textBox1.AppendText(receivedData + "\n");
            //textBox1.ForeColor = Color.Black;
        }

    }
}
