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
            SendCommand('q');
        }

        private void X1Y0_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X1Y0 48 SELECTED\n");
            SendCommand('w');
        }

        private void X2Y0_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X2Y0 48 SELECTED\n");
            SendCommand('e');
        }

        private void X3Y0_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X3Y0 48 SELECTED\n");
            SendCommand('r');
        }

        private void X0Y1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X0Y1 48 SELECTED\n");
            SendCommand('X');
        }

        private void X1Y1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X1Y1 48 SELECTED\n");
            SendCommand('t');
        }

        private void X2Y1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X2Y1 48 SELECTED\n");
            SendCommand('y');
        }

        private void X3Y1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X3Y1 48 SELECTED\n");
            SendCommand('u');
        }

        private void X0Y2_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X0Y2 48 SELECTED\n");
            SendCommand('i');
        }

        private void X1Y2_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X1Y2 48 SELECTED\n");
            SendCommand('o');
        }

        private void X2Y2_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X2Y2 48 SELECTED\n");
            SendCommand('p');
        }

        private void X3Y2_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X3Y2 48 SELECTED\n");
            SendCommand('a');
        }

        private void X0Y3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X0Y3 48 SELECTED\n");
            SendCommand('s');
        }

        private void X1Y3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X1Y3 48 SELECTED\n");
            SendCommand('d');
        }

        private void X2Y3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X2Y3 48 SELECTED\n");
            SendCommand('f');
        }

        private void X3Y3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("X3Y3 48 SELECTED\n");
            SendCommand('g');
        }

        private void BRIGHT_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("BRIGHT 48 SELECTED\n");
            SendCommand('+');
        }

        private void DIM_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIM 48 SELECTED\n");
            SendCommand('-');

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
            SendCommand('h');
        }

        private void GREENUP_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("GREENUP 48 SELECTED\n");
            SendCommand('j');
        }

        private void BLUEUP_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("BLUEUP 48 SELECTED\n");
            SendCommand('k');
        }

        private void QUICK_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("QUICK 48 SELECTED\n");
            SendCommand('Q');
        }

        private void REDDOWN_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("REDDOWN 48 SELECTED\n");
            SendCommand('l');
        }

        private void GREENDOWN_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("GREENDOWN 48 SELECTED\n");
            SendCommand('z');
        }

        private void BLUEDOWN_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("BLUEDOWN 48 SELECTED\n");
            SendCommand('x');
        }

        private void SLOW_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("SLOW 48 SELECTED\n");
            SendCommand('S');
        }

        private void DIY1_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIY1 48 SELECTED\n");
            SendCommand('c');
        }

        private void DIY2_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIY2 48 SELECTED\n");
            SendCommand('v');
        }

        private void DIY3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIY3 48 SELECTED\n");
            SendCommand('b');

        }

        private void AUTO_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("AUTO 48 SELECTED\n");
            SendCommand('A');
        }

        private void DIY4_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIY4 48 SELECTED\n");
            SendCommand('n');
        }

        private void DIY5_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIY5 48 SELECTED\n");
            SendCommand('m');
        }

        private void DIY6_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("DIY6 48 SELECTED\n");
            SendCommand('M');
        }

        private void FLASH_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("FLASH 48 SELECTED\n");
            SendCommand('F');
        }

        private void JUMP3_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("JUMP3 48 SELECTED\n");
            SendCommand('K');
        }

        private void JUMP7_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("JUMP7 48 SELECTED\n");
            SendCommand('J');
        }

        private void FADE3_Click(object sender, EventArgs e)
        {
            SendCommand('O');
            textBox1.AppendText("FADE3 48 SELECTED\n");
        }

        private void FADE7_Click(object sender, EventArgs e)
        {
            textBox1.AppendText("FADE7 48 SELECTED\n");
            SendCommand('I');
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
                logMessage(Color.Blue, new Font ("Verdana", 8, FontStyle.Bold), sendcommand,textBox1);
                serialPort1.Write((String)sendcommand);
            }
            
        }

        private void OpenComPort(String ComName)
        {
            try
            {
                serialPort1.Close();
                serialPort1.PortName = ComName;
                serialPort1.DataBits = 8;
                serialPort1.Parity = Parity.None;
                serialPort1.StopBits = StopBits.One;
                serialPort1.BaudRate = 9600;
                serialPort1.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
                serialPort1.Open();
            }
            catch (Exception exception)
            {
               textBox1.AppendText(exception.Message + "\n\n" + exception.Data);
            }
            

        }


        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            serialPort1.Close();
        }

       

        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            string indata = sp.ReadExisting();


            logMessage(Color.Orange, new Font("Verdana", 8, FontStyle.Bold), indata, richTextBox1);
          }
        private delegate void logMessageDelegate(Color color, Font font, String message, RichTextBox location);
        private void logMessage(Color color, Font font, String message, RichTextBox location)
        {
            try
            {
                if (this.InvokeRequired)
                {
                    this.BeginInvoke(new logMessageDelegate(logMessage), new object[] { color, font, message, location });
                    return;

                }else{

                    location.SelectionColor = color;
                    location.SelectionFont = font;
                    this.Controls.Add(location);


                    location.AppendText("COMMAND SEND: " + message + "\n");
                    location.ScrollToCaret();
                }
            }
            catch (Exception exception)
            {
                if (this.InvokeRequired)
                {
                    this.BeginInvoke(new logMessageDelegate(logMessage), new object[] { color, font, message, location });
                    return;

                }else{
                    textBox1.SelectionColor = Color.Red;
                    textBox1.SelectionFont = new Font("Verdana", 8, FontStyle.Bold);
                    this.Controls.Add(textBox1);
                    textBox1.AppendText(exception.Message + "\n\n" + exception.Data);
                }
            }
            
        }


       
        

    }
    
       
    
}
