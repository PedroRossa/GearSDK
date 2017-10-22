using System;
using System.Collections.Generic;
using GearSDK_CSharpDLL.Gear_Objects;
using Newtonsoft.Json;

namespace GearSDK_CSharpDLL
{
    public class csharp_Wrapper
    {
        #region Attributes

        string data;

        bool headerSetted = false;

        List<Gear_Objects.Gear_Button_csharp> buttons;
        List<Gear_Objects.Gear_Potentiometer_csharp> potentiometers;
        List<Gear_Objects.Gear_RGBLed_csharp> rgbLeds;
        List<Gear_Objects.Gear_MPU6050_csharp> mpus;
        
        #endregion

        #region Private Methods

        Gear_Objects.Gear_Button_csharp CreateButton(Header_Button b)
        {

            string name = b.name;
            string pin = b.pin;
            bool state = b.state;
            int type = b.type;

            Gear_Objects.Gear_Button_csharp btn = new Gear_Objects.Gear_Button_csharp(this.Buttons.Count, name, pin, state, type);
            return btn;
        }

        Gear_Objects.Gear_Potentiometer_csharp CreatePotentiometer(Header_Potentiometer p)
        {
            string name = p.name;
            string pin = p.pin;
            int value = p.value;

            Gear_Objects.Gear_Potentiometer_csharp pot = new Gear_Objects.Gear_Potentiometer_csharp(this.Potentiometers.Count, name, pin, value);

            return pot;
        }

        Gear_Objects.Gear_RGBLed_csharp CreateRGBLed(Header_RgbLed l)
        {
            string name = l.name;
            int mode = l.mode;

            int[] vals = new int[3] { l.value.r, l.value.g, l.value.b };
            string[] pins = new string[3] { l.pin.Split(',')[0], l.pin.Split(',')[1], l.pin.Split(',')[2] };

            Gear_Objects.Gear_RGBLed_csharp led = new Gear_Objects.Gear_RGBLed_csharp(this.RgbLeds.Count, name, pins[0], pins[1], pins[2], mode, vals[0], vals[1], vals[2]);

            return led;
        }

        Gear_Objects.Gear_MPU6050_csharp CreateMPU6050(Header_Mpu m)
        {
            string name = m.name;

            string[] pins = new string[2] { m.pins.Split(',')[0], m.pins.Split(',')[1] };

            int[] accel = new int[3] { m.accel.x, m.accel.y, m.accel.z };
            int[] gyro = new int[3] { m.gyro.x, m.gyro.y, m.gyro.z };
            double[] angle = new double[3] { m.angle.x, m.angle.y, m.angle.z };

            Gear_Objects.Gear_MPU6050_csharp mpu = new Gear_Objects.Gear_MPU6050_csharp(this.Mpus.Count, name, pins[0], pins[1], accel, gyro, angle);

            return mpu;
        }

        #endregion

        #region Constructors

        public csharp_Wrapper()
        {
            this.buttons = new List<Gear_Objects.Gear_Button_csharp>();
            this.potentiometers = new List<Gear_Objects.Gear_Potentiometer_csharp>();
            this.mpus = new List<Gear_Objects.Gear_MPU6050_csharp>();
            this.rgbLeds = new List<Gear_Objects.Gear_RGBLed_csharp>();
        }

        #endregion

        #region Gets and Sets

        public string Data { get => data; set => data = value; }
        public bool HeaderSetted { get => headerSetted; }

        public List<Gear_Button_csharp> Buttons { get => buttons; }
        public List<Gear_Potentiometer_csharp> Potentiometers { get => potentiometers; }
        public List<Gear_RGBLed_csharp> RgbLeds { get => rgbLeds; }
        public List<Gear_MPU6050_csharp> Mpus { get => mpus; }

        void SetRGBLed(int id, Gear_Objects.Gear_RGBLed_csharp led)
        {
            this.rgbLeds[id] = led;
        }

        #endregion

        #region Public Methods

        public void Init(string header)
        {
            if (header.Contains("header")) //if it's probably a json
            {
                try
                {
                    Header_RootObject h_root = JsonConvert.DeserializeObject<Header_RootObject>(header);
                    Header h = h_root.header;

                    this.headerSetted = true;

                    try
                    {
                        //-------- buttons ------------
                        List<Header_Button> btns = h.buttons;

                        for (int i = 0; i < btns.Count; i++)
                            this.buttons.Add(CreateButton(btns[i]));
                        //-----------------------------

                        //-------- potentiometers ------------
                        List<Header_Potentiometer> pots = h.potentiometers;

                        for (int i = 0; i < pots.Count; i++)
                            this.potentiometers.Add(CreatePotentiometer(pots[i]));
                        //-----------------------------

                        //-------- rgb leds ------------
                        List<Header_RgbLed> rgbLeds = h.rgb_leds;

                        for (int i = 0; i < rgbLeds.Count; i++)
                            this.rgbLeds.Add(CreateRGBLed(rgbLeds[i]));
                        //-----------------------------

                        //-------- rgb leds ------------
                        List<Header_Mpu> mpus = h.mpus;

                        for (int i = 0; i < mpus.Count; i++)
                            this.mpus.Add(CreateMPU6050(mpus[i]));
                        //-----------------------------


                    }
                    catch (Exception e)
                    {
                        Console.WriteLine("Excpetion: " + e.Data + " - Or don't have buttons");
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("Excpetion: " + e.Data);
                }
            }
        }

        public void UpdateObjects(string data)
        {
            if (data.Contains("data"))
            {
                try
                {
                    Data_RootObject d_root = JsonConvert.DeserializeObject<Data_RootObject>(data);
                    Data d = d_root.data;

                    try
                    {
                        List<Data_Button> b = d.buttons;

                        for (int i = 0; i < b.Count; i++)
                            this.buttons[i].State = Convert.ToBoolean(b[i].state);


                        List<Data_Potentiometer> p = d.potentiometers;

                        for (int i = 0; i < p.Count; i++)
                            this.potentiometers[i].Value = p[i].value;

                        List<Data_Mpu> m = d.mpus;

                        for (int i = 0; i < m.Count; i++)
                        {
                            this.mpus[i].Accel_Values = new int[3] { m[i].accel.x, m[i].accel.y, m[i].accel.z };
                            this.mpus[i].Gyro_Values = new int[3] { m[i].gyro.x, m[i].gyro.y, m[i].gyro.z };
                            this.mpus[i].Angle_Values = new double[3] { m[i].angle.x, m[i].angle.y, m[i].angle.z };
                        }

                        /*{
                        "name": "rgb_led_0",
                        "pin" : "D3,D4,D5",
                        "mode" : "BLINKING",
                        "value" : {
                        "r": 0,
                        "g" : 1023,
                        "b" : 0
                        }*/

                    }
                    catch (Exception e)
                    {
                        Console.WriteLine("Excpetion: " + e.Data);
                    }

                }
                catch (Exception e)
                {
                    Console.WriteLine("Excpetion: " + e.Data);
                }
            }
        }

        #endregion
    }
}
