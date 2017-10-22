using GearSDK_CSharpDLL;

namespace WindowsForms_Sample
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.txtAngleZ = new System.Windows.Forms.NumericUpDown();
            this.label11 = new System.Windows.Forms.Label();
            this.txtAngleY = new System.Windows.Forms.NumericUpDown();
            this.label12 = new System.Windows.Forms.Label();
            this.txtAngleX = new System.Windows.Forms.NumericUpDown();
            this.label13 = new System.Windows.Forms.Label();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.txtGyroZ = new System.Windows.Forms.NumericUpDown();
            this.label6 = new System.Windows.Forms.Label();
            this.txtGyroY = new System.Windows.Forms.NumericUpDown();
            this.label9 = new System.Windows.Forms.Label();
            this.txtGyroX = new System.Windows.Forms.NumericUpDown();
            this.label10 = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.txtAccelZ = new System.Windows.Forms.NumericUpDown();
            this.label8 = new System.Windows.Forms.Label();
            this.txtAccelY = new System.Windows.Forms.NumericUpDown();
            this.label7 = new System.Windows.Forms.Label();
            this.txtAccelX = new System.Windows.Forms.NumericUpDown();
            this.label5 = new System.Windows.Forms.Label();
            this.txtPotentiometer = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.txtBValue = new System.Windows.Forms.NumericUpDown();
            this.txtGValue = new System.Windows.Forms.NumericUpDown();
            this.txtRValue = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.ckbButton = new System.Windows.Forms.CheckBox();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox6.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtAngleZ)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtAngleY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtAngleX)).BeginInit();
            this.groupBox5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtGyroZ)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGyroY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGyroX)).BeginInit();
            this.groupBox4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtAccelZ)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtAccelY)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtAccelX)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtPotentiometer)).BeginInit();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtBValue)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGValue)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtRValue)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.panel1);
            this.groupBox1.Location = new System.Drawing.Point(15, 17);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(493, 299);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "GearSDK";
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.groupBox3);
            this.panel1.Controls.Add(this.txtPotentiometer);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.groupBox2);
            this.panel1.Controls.Add(this.ckbButton);
            this.panel1.Location = new System.Drawing.Point(15, 19);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(463, 266);
            this.panel1.TabIndex = 0;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.groupBox6);
            this.groupBox3.Controls.Add(this.groupBox5);
            this.groupBox3.Controls.Add(this.groupBox4);
            this.groupBox3.Location = new System.Drawing.Point(16, 127);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(435, 130);
            this.groupBox3.TabIndex = 9;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "MPU";
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.txtAngleZ);
            this.groupBox6.Controls.Add(this.label11);
            this.groupBox6.Controls.Add(this.txtAngleY);
            this.groupBox6.Controls.Add(this.label12);
            this.groupBox6.Controls.Add(this.txtAngleX);
            this.groupBox6.Controls.Add(this.label13);
            this.groupBox6.Location = new System.Drawing.Point(290, 19);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(136, 104);
            this.groupBox6.TabIndex = 17;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Angle";
            // 
            // txtAngleZ
            // 
            this.txtAngleZ.Location = new System.Drawing.Point(37, 71);
            this.txtAngleZ.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtAngleZ.Minimum = new decimal(new int[] {
            100000,
            0,
            0,
            -2147483648});
            this.txtAngleZ.Name = "txtAngleZ";
            this.txtAngleZ.ReadOnly = true;
            this.txtAngleZ.Size = new System.Drawing.Size(91, 20);
            this.txtAngleZ.TabIndex = 15;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(11, 73);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(20, 13);
            this.label11.TabIndex = 14;
            this.label11.Text = "Z: ";
            // 
            // txtAngleY
            // 
            this.txtAngleY.Location = new System.Drawing.Point(37, 45);
            this.txtAngleY.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtAngleY.Minimum = new decimal(new int[] {
            100000,
            0,
            0,
            -2147483648});
            this.txtAngleY.Name = "txtAngleY";
            this.txtAngleY.ReadOnly = true;
            this.txtAngleY.Size = new System.Drawing.Size(91, 20);
            this.txtAngleY.TabIndex = 13;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(11, 47);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(20, 13);
            this.label12.TabIndex = 12;
            this.label12.Text = "Y: ";
            // 
            // txtAngleX
            // 
            this.txtAngleX.Location = new System.Drawing.Point(37, 19);
            this.txtAngleX.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtAngleX.Minimum = new decimal(new int[] {
            100000,
            0,
            0,
            -2147483648});
            this.txtAngleX.Name = "txtAngleX";
            this.txtAngleX.ReadOnly = true;
            this.txtAngleX.Size = new System.Drawing.Size(91, 20);
            this.txtAngleX.TabIndex = 11;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(11, 21);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(20, 13);
            this.label13.TabIndex = 10;
            this.label13.Text = "X: ";
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.txtGyroZ);
            this.groupBox5.Controls.Add(this.label6);
            this.groupBox5.Controls.Add(this.txtGyroY);
            this.groupBox5.Controls.Add(this.label9);
            this.groupBox5.Controls.Add(this.txtGyroX);
            this.groupBox5.Controls.Add(this.label10);
            this.groupBox5.Location = new System.Drawing.Point(148, 19);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(136, 104);
            this.groupBox5.TabIndex = 16;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Gyroscope";
            // 
            // txtGyroZ
            // 
            this.txtGyroZ.Location = new System.Drawing.Point(37, 71);
            this.txtGyroZ.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtGyroZ.Minimum = new decimal(new int[] {
            100000,
            0,
            0,
            -2147483648});
            this.txtGyroZ.Name = "txtGyroZ";
            this.txtGyroZ.ReadOnly = true;
            this.txtGyroZ.Size = new System.Drawing.Size(91, 20);
            this.txtGyroZ.TabIndex = 15;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(11, 73);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(20, 13);
            this.label6.TabIndex = 14;
            this.label6.Text = "Z: ";
            // 
            // txtGyroY
            // 
            this.txtGyroY.Location = new System.Drawing.Point(37, 45);
            this.txtGyroY.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtGyroY.Minimum = new decimal(new int[] {
            100000,
            0,
            0,
            -2147483648});
            this.txtGyroY.Name = "txtGyroY";
            this.txtGyroY.ReadOnly = true;
            this.txtGyroY.Size = new System.Drawing.Size(91, 20);
            this.txtGyroY.TabIndex = 13;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(11, 47);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(20, 13);
            this.label9.TabIndex = 12;
            this.label9.Text = "Y: ";
            // 
            // txtGyroX
            // 
            this.txtGyroX.Location = new System.Drawing.Point(37, 19);
            this.txtGyroX.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtGyroX.Minimum = new decimal(new int[] {
            100000,
            0,
            0,
            -2147483648});
            this.txtGyroX.Name = "txtGyroX";
            this.txtGyroX.ReadOnly = true;
            this.txtGyroX.Size = new System.Drawing.Size(91, 20);
            this.txtGyroX.TabIndex = 11;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(11, 21);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(20, 13);
            this.label10.TabIndex = 10;
            this.label10.Text = "X: ";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.txtAccelZ);
            this.groupBox4.Controls.Add(this.label8);
            this.groupBox4.Controls.Add(this.txtAccelY);
            this.groupBox4.Controls.Add(this.label7);
            this.groupBox4.Controls.Add(this.txtAccelX);
            this.groupBox4.Controls.Add(this.label5);
            this.groupBox4.Location = new System.Drawing.Point(6, 19);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(136, 104);
            this.groupBox4.TabIndex = 0;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Accelerometer";
            // 
            // txtAccelZ
            // 
            this.txtAccelZ.Location = new System.Drawing.Point(37, 71);
            this.txtAccelZ.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtAccelZ.Minimum = new decimal(new int[] {
            100000,
            0,
            0,
            -2147483648});
            this.txtAccelZ.Name = "txtAccelZ";
            this.txtAccelZ.ReadOnly = true;
            this.txtAccelZ.Size = new System.Drawing.Size(91, 20);
            this.txtAccelZ.TabIndex = 15;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(11, 73);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(20, 13);
            this.label8.TabIndex = 14;
            this.label8.Text = "Z: ";
            // 
            // txtAccelY
            // 
            this.txtAccelY.Location = new System.Drawing.Point(37, 45);
            this.txtAccelY.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtAccelY.Minimum = new decimal(new int[] {
            100000,
            0,
            0,
            -2147483648});
            this.txtAccelY.Name = "txtAccelY";
            this.txtAccelY.ReadOnly = true;
            this.txtAccelY.Size = new System.Drawing.Size(91, 20);
            this.txtAccelY.TabIndex = 13;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(11, 47);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(20, 13);
            this.label7.TabIndex = 12;
            this.label7.Text = "Y: ";
            // 
            // txtAccelX
            // 
            this.txtAccelX.Location = new System.Drawing.Point(37, 19);
            this.txtAccelX.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtAccelX.Minimum = new decimal(new int[] {
            100000,
            0,
            0,
            -2147483648});
            this.txtAccelX.Name = "txtAccelX";
            this.txtAccelX.ReadOnly = true;
            this.txtAccelX.Size = new System.Drawing.Size(91, 20);
            this.txtAccelX.TabIndex = 11;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(11, 21);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(20, 13);
            this.label5.TabIndex = 10;
            this.label5.Text = "X: ";
            // 
            // txtPotentiometer
            // 
            this.txtPotentiometer.Location = new System.Drawing.Point(94, 37);
            this.txtPotentiometer.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtPotentiometer.Name = "txtPotentiometer";
            this.txtPotentiometer.ReadOnly = true;
            this.txtPotentiometer.Size = new System.Drawing.Size(120, 20);
            this.txtPotentiometer.TabIndex = 8;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(13, 39);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(75, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Potentiometer:";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.txtBValue);
            this.groupBox2.Controls.Add(this.txtGValue);
            this.groupBox2.Controls.Add(this.txtRValue);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Location = new System.Drawing.Point(290, 13);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(161, 108);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "rgbLed";
            // 
            // txtBValue
            // 
            this.txtBValue.Location = new System.Drawing.Point(30, 79);
            this.txtBValue.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtBValue.Name = "txtBValue";
            this.txtBValue.Size = new System.Drawing.Size(122, 20);
            this.txtBValue.TabIndex = 18;
            // 
            // txtGValue
            // 
            this.txtGValue.Location = new System.Drawing.Point(30, 53);
            this.txtGValue.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtGValue.Name = "txtGValue";
            this.txtGValue.Size = new System.Drawing.Size(122, 20);
            this.txtGValue.TabIndex = 17;
            // 
            // txtRValue
            // 
            this.txtRValue.Location = new System.Drawing.Point(30, 27);
            this.txtRValue.Maximum = new decimal(new int[] {
            100000,
            0,
            0,
            0});
            this.txtRValue.Name = "txtRValue";
            this.txtRValue.Size = new System.Drawing.Size(122, 20);
            this.txtRValue.TabIndex = 16;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 81);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(17, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "B:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 55);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(18, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "G:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 29);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(18, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "R:";
            // 
            // ckbButton
            // 
            this.ckbButton.AutoSize = true;
            this.ckbButton.Location = new System.Drawing.Point(16, 13);
            this.ckbButton.Name = "ckbButton";
            this.ckbButton.Size = new System.Drawing.Size(57, 17);
            this.ckbButton.TabIndex = 0;
            this.ckbButton.Text = "Button";
            this.ckbButton.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(231, 322);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "Connect";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(522, 351);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Gear SDK Windows Forms Sample";
            this.groupBox1.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtAngleZ)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtAngleY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtAngleX)).EndInit();
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtGyroZ)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGyroY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGyroX)).EndInit();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtAccelZ)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtAccelY)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtAccelX)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtPotentiometer)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtBValue)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtGValue)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtRValue)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.CheckBox ckbButton;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.NumericUpDown txtAngleZ;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.NumericUpDown txtAngleY;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.NumericUpDown txtAngleX;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.NumericUpDown txtGyroZ;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.NumericUpDown txtGyroY;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.NumericUpDown txtGyroX;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.NumericUpDown txtAccelZ;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.NumericUpDown txtAccelY;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.NumericUpDown txtAccelX;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.NumericUpDown txtPotentiometer;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.NumericUpDown txtBValue;
        private System.Windows.Forms.NumericUpDown txtGValue;
        private System.Windows.Forms.NumericUpDown txtRValue;

        csharp_Client client;

        public void UpdateForm()
        {
            client = GearSDK.CreateClient("192.168.15.9", 81);

            client.Init();

            while (client.connection.IsConnected)
            {
                client.Update();

                if (client.CanUpdateObjects)
                {
                    int acellX = client.wrapper.Mpus[0].Accel_Values[0];
                    int acellY = client.wrapper.Mpus[0].Accel_Values[1];
                    int acellZ = client.wrapper.Mpus[0].Accel_Values[2];

                    int gyroX = client.wrapper.Mpus[0].Gyro_Values[0];
                    int gyroY = client.wrapper.Mpus[0].Gyro_Values[1];
                    int gyroZ = client.wrapper.Mpus[0].Gyro_Values[2];

                    double angleX = client.wrapper.Mpus[0].Angle_Values[0];
                    double angleY = client.wrapper.Mpus[0].Angle_Values[1];
                    double angleZ = client.wrapper.Mpus[0].Angle_Values[2];

                    int potentiometer = client.wrapper.Potentiometers[0].Value;

                    bool buttonState = client.wrapper.Buttons[0].State;

                    int r = client.wrapper.RgbLeds[0].R_value;
                    int g = client.wrapper.RgbLeds[0].G_value;
                    int b = client.wrapper.RgbLeds[0].B_value;

                    ckbButton.Checked = buttonState;
                    txtPotentiometer.Value = potentiometer;

                    txtAccelX.Value = acellX;
                    txtAccelY.Value = acellY;
                    txtAccelZ.Value = acellZ;

                    txtGyroX.Value = gyroX;
                    txtGyroY.Value = gyroY;
                    txtGyroZ.Value = gyroZ;

                    txtAngleX.Value = (int)angleX;
                    txtAngleY.Value = (int)angleY;
                    txtAngleZ.Value = (int)angleZ;

                    txtRValue.Value = r;
                    txtGValue.Value = g;
                    txtBValue.Value = b;

                    float intensity = potentiometer / 1000.0f;

                    if (buttonState)
                    {
                        client.wrapper.RgbLeds[0].SetRGB_Value((int)(intensity * 1023), (int)(intensity * 0), (int)(intensity * 1023));
                        client.wrapper.RgbLeds[0].SetMode(Helper.LedMode.STATIC);
                        //wrapper.GetRGBLed(0)->SetMode(LedMode::BLINKING, 500, 100);
                        string s = client.wrapper.RgbLeds[0].UpdatedJson();

                        client.connection.SendMessage(s);
                    }
                    else
                    {
                        client.wrapper.RgbLeds[0].SetRGB_Value((int)(intensity * 0), (int)(intensity * 1023), (int)(intensity * 1023));
                        client.wrapper.RgbLeds[0].SetMode(Helper.LedMode.STATIC);

                        string s = client.wrapper.RgbLeds[0].UpdatedJson();
                        client.connection.SendMessage(s);
                    }

                    System.Threading.Thread.Sleep(20);
                    this.Refresh();
                }
            }
        }

        private System.Windows.Forms.Button button1;
    }
}

