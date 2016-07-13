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
            ComPortSelector.SelectedIndex = 0;
            SelectMode.SelectedIndex = 2;
            CheckComPorts();
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
                this.Size = new Size(656, 323);
            }
            else
            {
                this.Size = new Size(656, 433);
            }


        }



        

        private void CheckComPorts()
        {
            int count = 0;
            //ComPortSelector.
            string[] ports = System.IO.Ports.SerialPort.GetPortNames();
            foreach (String s in ports)
            {
                ComPortSelector.Items.Add(s);
                count++;
            }
            if (count == 0)
            {
                ComPortSelector.Items.Add("no port avaible");
                logMessage(Color.Red, new Font("Verdana", 8, FontStyle.Bold), "NO AVAILABLE COMPORTS FOUND", textBox1, 'E');
            }
            if (count > 5) count = 5;
            int size = 17 * (count + 1);
            ComPortSelector.SetBounds(511, 127, 111, size);
            
        }

        private void SendCommand(char command)
        {
            char[] commandoutput = new char[3];
            commandoutput[0] = '#';
            commandoutput[1] = command;
            commandoutput[2] = '$';
            String sendcommand = new String(commandoutput);
            if (ComPortSelector.SelectedIndex != -1 && ComPortSelector.SelectedIndex != 0)
            {
                logMessage(Color.Blue, new Font("Verdana", 8, FontStyle.Bold), sendcommand, textBox1, 'S');
                try
                {
                    serialPort1.Write((String)sendcommand);
                }
                catch (Exception exception)
                {
                    OpenComPort(ComPortSelector.GetItemText(ComPortSelector.SelectedItem));
                    String S = ("Failed to send command:" + sendcommand + "\n");
                    logMessage(Color.Red, new Font("Verdana", 8, FontStyle.Bold), S, textBox1, 'S');
                    logMessage(Color.Red, new Font("Verdana", 8, FontStyle.Bold), S, richTextBox1, 'S');
                    S = (exception.Message + "\n\n" + exception.Data);
                    logMessage(Color.Red, new Font("Verdana", 8, FontStyle.Bold), S, textBox1, 'W');
                    RefreshComPorts();
                }
            }

        }

        private void OpenComPort(String ComName)
        {
            if (ComName != "None")
            {
                try
                {
                    serialPort1.Close();
                    logMessage(Color.Blue, new Font("Verdana", 8, FontStyle.Bold), "Connection discontinued", richTextBox1, 'W');
                    serialPort1.PortName = ComName;
                    serialPort1.DataBits = 8;
                    serialPort1.Parity = Parity.None;
                    serialPort1.StopBits = StopBits.One;
                    serialPort1.BaudRate = 9600;
                    serialPort1.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
                    serialPort1.Open();
                    logMessage(Color.Blue, new Font("Verdana", 8, FontStyle.Bold), "Connection started", richTextBox1, 'W');
                    keyMode.Visible = true;
                    SwitchMode.Visible = true;
                }
                catch (Exception exception)
                {
                    String S = (exception.Message + "\n\n" + exception.Data);
                    logMessage(Color.Red, new Font("Verdana", 8, FontStyle.Bold), S, textBox1, 'E');
                }
            }
            else
            {
                serialPort1.Close();
                logMessage(Color.Blue, new Font("Verdana", 8, FontStyle.Bold), "Connection discontinued", richTextBox1, 'W');
                keyMode.Visible = false;
                SwitchMode.Visible = false;
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

            if (indata != "Mode Changed")
            {
                logMessage(Color.Orange, new Font("Verdana", 8, FontStyle.Bold), indata, richTextBox1, 'R');
            }
            else
            {
                logMessage(Color.Red, new Font("Verdana", 8, FontStyle.Bold), indata, richTextBox1, 'W');
            }
        }


        private delegate void logMessageDelegate(Color color, Font font, String message, RichTextBox location, char messageSource);
        private void logMessage(Color color, Font font, String message, RichTextBox location, char messageSource)
        {
            try
            {
                if (this.InvokeRequired)
                {
                    this.BeginInvoke(new logMessageDelegate(logMessage), new object[] { color, font, message, location, messageSource });
                    return;

                }
                else
                {

                    location.SelectionColor = color;
                    location.SelectionFont = font;
                    this.Controls.Add(location);
                    if (message != null && message != "\n" && message != " ")
                    {
                        if (messageSource == 'S')
                        {
                            location.AppendText("COMMAND SEND: " + message + "\n");
                        }
                        else if (messageSource == 'R')
                        {
                            location.AppendText("Received: " + message + "\n");
                        }
                        else if (messageSource == 'E')
                        {
                            location.AppendText("Error:" + message + "\n");
                        }
                        else if (messageSource == 'W')
                        {
                            location.AppendText("System:" + message + "\n");
                        }
                    }
                    location.ScrollToCaret();
                }
            }
            catch (Exception exception)
            {
                if (this.InvokeRequired)
                {
                    this.BeginInvoke(new logMessageDelegate(logMessage), new object[] { color, font, message, location, 'E' });
                    return;

                }
                else
                {

                    String S = exception.Message + "\n\n" + exception.Data;
                    logMessage(Color.Red, new Font("Verdana", 8, FontStyle.Bold), S, richTextBox1, 'E');
                    //textBox1.AppendText(exception.Message + "\n\n" + exception.Data);
                }
            }

        }
        private void RefreshComPorts()
        {
            serialPort1.Close();
            ComPortSelector.Items.Clear();
            ComPortSelector.Items.Add("None");
            ComPortSelector.SelectedIndex = 0;
            CheckComPorts();
        }

        private void ClearLogs()
        {
            textBox1.Clear();
            richTextBox1.Clear();
        }

        private void RefreshButton_Click(object sender, EventArgs e)
        {
            RefreshComPorts(); 
        }

        private void DIM24_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "DIM 24 SELECTED", textBox1, 'S');
            SendCommand('-');
        }

        private void BRIGHT24_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "INCREASE BRIGHTNISS 24 SELECTED", textBox1, 'S');
            SendCommand('+');
        }

        private void OFF24_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "OFF 24 SELECTED", textBox1, 'S');
            SendCommand('0');
        }

        private void ON24_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "ON 24 SELECTED", textBox1, 'S');
            SendCommand('1');
        }

        private void RED24_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "RED2 4 SELECTED", textBox1, 'S');
            SendCommand('R');
        }

        private void GREEN24_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "GREEN 24 SELECTED", textBox1, 'S');
            SendCommand('G');
        }

        private void BLUE24_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "BLUE 24 SELECTED", textBox1, 'S');
            SendCommand('B');
        }

        private void WHITE24_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "WHITE 24 SELECTED", textBox1, 'S');
            SendCommand('W');
        }

        private void X0Y024_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "X0Y0 24 SELECTED", textBox1, 'S');
            SendCommand('s');
        }

        private void X1Y024_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "X1Y0 24 SELECTED", textBox1, 'S');
            SendCommand('p');
        }

        private void X2Y024_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "X2Y0 24 SELECTED", textBox1, 'S');
            SendCommand('a');
        }

        private void FLASH24_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "FLASH 24 SELECTED", textBox1, 'S');
            SendCommand('F');
        }

        private void X0Y124_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "X0Y1 24 SELECTED", textBox1, 'S');
            SendCommand('o');
        }

        private void X1Y124_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "X1Y1 24 SELECTED", textBox1, 'S');
            SendCommand('u');
        }

        private void X2Y124_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "X2Y1 24 SELECTED", textBox1, 'S');
            SendCommand('i');
        }

        private void STROBE24_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "STROBE 24 SELECTED", textBox1, 'S');
            SendCommand('S');
        }

        private void X0Y224_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "X0Y2 24 SELECTED", textBox1, 'S');
            SendCommand('y');
        }

        private void X1Y224_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "X1Y2 24 SELECTED", textBox1, 'S');
            SendCommand('r');
        }

        private void X2Y224_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "X2Y2 24 SELECTED", textBox1, 'S');
            SendCommand('t');
        }

        private void FADE24_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "FADE 24 SELECTED", textBox1, 'S');
            SendCommand('D');
        }

        private void X0Y324_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "X0Y3 24 SELECTED", textBox1, 'S');
            SendCommand('e');
        }

        private void X1Y324_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "X1Y3 24 SELECTED", textBox1, 'S');
            SendCommand('q');
        }

        private void X2Y324_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "X2Y3 24 SELECTED", textBox1, 'S');
            SendCommand('w');
        }

        private void SMOOTH24_Click(object sender, EventArgs e)
        {
            logMessage(Color.Black, new Font("Verdana", 8, FontStyle.Regular), "SMOOTH 24 SELECTED", textBox1, 'S');
            SendCommand('A');
        }

        private void keyMode_Scroll(object sender, EventArgs e)
        {
            logMessage(Color.Blue, new Font("Verdana", 8, FontStyle.Regular), "Changed Mode Controller", textBox1, 'W');
            SendCommand('/');
        }

        private void clear_Click(object sender, EventArgs e)
        {
            ClearLogs();
        }

        private void ComPortSelector_SelectedIndexChanged(object sender, EventArgs e)
        {
            textBox1.AppendText(ComPortSelector.GetItemText(ComPortSelector.SelectedItem) + " selected\n");
            OpenComPort(ComPortSelector.GetItemText(ComPortSelector.SelectedItem));
        }

        private void SelectMode_SelectedIndexChanged_1(object sender, EventArgs e)
        {
            // CheckComPorts();
            if (SelectMode.GetSelected(0))
            {
                textBox1.Clear();
                richTextBox1.Clear();
                KeyControlls48.Visible = true;
                keyRemote24.Visible = false;
                textBox1.AppendText("48 KEYMODE SELECTED\n");
            }
            else if (SelectMode.GetSelected(1))
            {
                richTextBox1.Clear();
                textBox1.Clear();
                KeyControlls48.Visible = false;
                keyRemote24.Visible = true;
                textBox1.AppendText("24 KEYMODE SELECTED\n");
            }
            else if (SelectMode.GetSelected(2))
            {
                richTextBox1.Clear();
                textBox1.Clear();
                KeyControlls48.Visible = false;
                keyRemote24.Visible = false;
                textBox1.AppendText("No Mode SELECTED\n");
            }
        }

        

        

        

        

        

        

       





    }



}
