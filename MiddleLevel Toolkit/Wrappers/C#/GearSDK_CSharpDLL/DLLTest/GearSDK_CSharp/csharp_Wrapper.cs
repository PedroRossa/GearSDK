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

        List<Gear_Button_csharp> buttons;
        List<Gear_Potentiometer_csharp> potentiometers;
        List<Gear_RGBLed_csharp> rgbLeds;
        List<Gear_MPU6050_csharp> mpus;
        List<Gear_Servo_csharp> servos;
        List<Gear_HallEffect_csharp> hallEffects;
        List<Gear_PulseDetector_csharp> pulseDetectors;

        #endregion

        #region Private Methods

        Gear_Button_csharp CreateButton(Json.Button.Header jData)
        {

            string name = jData.name;
            string pin = jData.pin;
            int state = jData.state;
            int type = jData.type;

            Gear_Button_csharp btn = new Gear_Button_csharp(this.Buttons.Count, name, pin, Convert.ToBoolean(state), type);

            this.buttons.Add(btn);
            return btn;
        }

        Gear_Potentiometer_csharp CreatePotentiometer(Json.Potentiometer.Header jData)
        {
            string name = jData.name;
            string pin = jData.pin;
            int value = jData.value;

            Gear_Potentiometer_csharp pot = new Gear_Potentiometer_csharp(this.Potentiometers.Count, name, pin, value);

            this.potentiometers.Add(pot);
            return pot;
        }

        Gear_RGBLed_csharp CreateRGBLed(Json.RGBLed.Header jData)
        {
            string name = jData.name;
            int mode = jData.mode;

            int[] vals = new int[3] { jData.value.r, jData.value.g, jData.value.b };
            string[] pins = new string[3] { jData.pin.Split(',')[0], jData.pin.Split(',')[1], jData.pin.Split(',')[2] };

            Gear_RGBLed_csharp led = new Gear_RGBLed_csharp(this.RgbLeds.Count, name, pins[0], pins[1], pins[2], mode, vals[0], vals[1], vals[2]);

            this.rgbLeds.Add(led);
            return led;
        }

        Gear_MPU6050_csharp CreateMPU6050(Json.MPU.Header jData)
        {
            string name = jData.name;

            string[] pins = new string[2] { jData.pins.Split(',')[0], jData.pins.Split(',')[1] };

            int[] accel = new int[3] { jData.accel.x, jData.accel.y, jData.accel.z };
            int[] gyro = new int[3] { jData.gyro.x, jData.gyro.y, jData.gyro.z };
            double[] angle = new double[3] { jData.angle.x, jData.angle.y, jData.angle.z };

            Gear_MPU6050_csharp mpu = new Gear_MPU6050_csharp(this.Mpus.Count, name, pins[0], pins[1], accel, gyro, angle);

            this.mpus.Add(mpu);
            return mpu;
        }

        Gear_Servo_csharp CreateServo(Json.Servo.Header jData)
        {

            string name = jData.name;
            string pin = jData.pin;
            int value = jData.value;

            Gear_Servo_csharp serv = new Gear_Servo_csharp(this.servos.Count, name, pin, value);

            this.servos.Add(serv);
            return serv;
        }

        Gear_HallEffect_csharp CreateHallEffect(Json.HallEffect.Header jData)
        {
            string name = jData.name;
            string pin = jData.pin;
            int value = jData.value;

            Gear_HallEffect_csharp hall = new Gear_HallEffect_csharp(this.hallEffects.Count, name, pin, value);

            this.hallEffects.Add(hall);
            return hall;
        }

        Gear_PulseDetector_csharp CreatePulseDetector(Json.PulseDetector.Header jData)
        {
            string name = jData.name;
            string pin = jData.pin;
            int value = jData.value;

            Gear_PulseDetector_csharp pulse = new Gear_PulseDetector_csharp(this.pulseDetectors.Count, name, pin, value);

            this.pulseDetectors.Add(pulse);
            return pulse;
        }


        bool UpdateButton(Json.Button.Data jData)
        {
            string name = jData.name;
            int state = jData.state;
            for (int i = 0; i < this.buttons.Count; i++)
            {
                if (this.buttons[i].Name == name)
                {
                    this.buttons[i].State = Convert.ToBoolean(state);
                    return true;
                }
            }
            return false;
        }

        bool UpdatePotentiometer(Json.Potentiometer.Data jData)
        {
            string name = jData.name;
            int value = jData.value;

            for (int i = 0; i < this.potentiometers.Count; i++)
            {
                if (this.potentiometers[i].Name == name)
                {
                    this.potentiometers[i].Value = value;
                    return true;
                }
            }
            return false;
        }

        bool UpdateRGBLed(Json.RGBLed.Data jData)
        {
            //TODO: MAKE THIS TO RGBLed
            return false;
        }

        bool UpdateMPU(Json.MPU.Data jData)
        {
            string name = jData.name;
            int[] accel = new int[3] { jData.accel.x, jData.accel.y, jData.accel.z };
            int[] gyro = new int[3] { jData.gyro.x, jData.gyro.y, jData.gyro.z };
            double[] angle = new double[3] { jData.angle.x, jData.angle.y, jData.angle.z };

            for (int i = 0; i < this.mpus.Count; i++)
            {
                if (this.mpus[i].Name == name)
                {
                    this.mpus[i].Accel_Values = accel;
                    this.mpus[i].Gyro_Values = gyro;
                    this.mpus[i].Angle_Values = angle;

                    return true;
                }
            }
            return false;
        }

        bool UpdateServo(Json.Servo.Data jData)
        {
            string name = jData.name;
            int value = jData.value;
            for (int i = 0; i < this.servos.Count; i++)
            {
                if (this.servos[i].Name == name)
                {
                    this.servos[i].Value = value;
                    return true;
                }
            }
            return false;
        }

        bool UpdateHallEffect(Json.HallEffect.Data jData)
        {
            string name = jData.name;
            int value = jData.value;

            for (int i = 0; i < this.hallEffects.Count; i++)
            {
                if (this.hallEffects[i].Name == name)
                {
                    this.hallEffects[i].Value = value;
                    return true;
                }
            }
            return false;
        }

        bool UpdatePulseDetector(Json.PulseDetector.Data jData)
        {
            string name = jData.name;
            int value = jData.value;

            for (int i = 0; i < this.pulseDetectors.Count; i++)
            {
                if (this.pulseDetectors[i].Name == name)
                {
                    this.pulseDetectors[i].Value = value;
                    return true;
                }
            }
            return false;
        }

        #endregion

        #region Constructors

        public csharp_Wrapper()
        {
            this.buttons = new List<Gear_Button_csharp>();
            this.potentiometers = new List<Gear_Potentiometer_csharp>();
            this.mpus = new List<Gear_MPU6050_csharp>();
            this.rgbLeds = new List<Gear_RGBLed_csharp>();
            this.servos = new List<Gear_Servo_csharp>();
            this.hallEffects = new List<Gear_HallEffect_csharp>();
            this.pulseDetectors = new List<Gear_PulseDetector_csharp>();
        }

        #endregion

        #region Gets and Sets

        public string Data { get => data; set => data = value; }
        public bool HeaderSetted { get => headerSetted; }

        public List<Gear_Button_csharp> Buttons { get => buttons; }
        public List<Gear_Potentiometer_csharp> Potentiometers { get => potentiometers; }
        public List<Gear_RGBLed_csharp> RgbLeds { get => rgbLeds; }
        public List<Gear_MPU6050_csharp> Mpus { get => mpus; }
        public List<Gear_Servo_csharp> Servos { get => servos; }
        public List<Gear_HallEffect_csharp> HallEffects { get => hallEffects; }
        public List<Gear_PulseDetector_csharp> PulseDetctors { get => pulseDetectors; }

        #endregion

        #region Public Methods

        public void Init(string header)
        {
            if (header.Contains("header")) //if it's probably a json
            {
                try
                {
                    string[] jsonHeaders = header.Split('#');

                    for (int i = 0; i < jsonHeaders.Length; i++)
                    {
                        try
                        {
                            //-------- Button ------------
                            if (jsonHeaders[i].Contains("button"))
                            {
                                Json.Button.Root_Header rh = JsonConvert.DeserializeObject<Json.Button.Root_Header>(jsonHeaders[i]);
                                CreateButton(rh.button);
                            }
                            //-------- Potentiometer ------------
                            else if (jsonHeaders[i].Contains("potentiometer"))
                            {
                                Json.Potentiometer.Root_Header rh = JsonConvert.DeserializeObject<Json.Potentiometer.Root_Header>(jsonHeaders[i]);
                                CreatePotentiometer(rh.potentiometer);
                            }
                            //-------- RGB Led ------------
                            else if (jsonHeaders[i].Contains("rgb_led"))
                            {
                                Json.RGBLed.Root_Header rh = JsonConvert.DeserializeObject<Json.RGBLed.Root_Header>(jsonHeaders[i]);
                                CreateRGBLed(rh.rgb_led);
                            }
                            //-------- MPU 6050 ------------
                            else if (jsonHeaders[i].Contains("mpu"))
                            {
                                Json.MPU.Root_Header rh = JsonConvert.DeserializeObject<Json.MPU.Root_Header>(jsonHeaders[i]);
                                CreateMPU6050(rh.mpu);
                            }
                            //-------- SERVO ------------
                            else if (jsonHeaders[i].Contains("servo"))
                            {
                                Json.Servo.Root_Header rh = JsonConvert.DeserializeObject<Json.Servo.Root_Header>(jsonHeaders[i]);
                                CreateServo(rh.servo);
                            }
                            //-------- HALL EFFECT ------------
                            else if (jsonHeaders[i].Contains("hallEffect"))
                            {
                                Json.HallEffect.Root_Header rh = JsonConvert.DeserializeObject<Json.HallEffect.Root_Header>(jsonHeaders[i]);
                                CreateHallEffect(rh.hallEffect);
                            }
                            //-------- PULSE DETECTOR ------------
                            else if (jsonHeaders[i].Contains("pulseDetector"))
                            {
                                Json.PulseDetector.Root_Header rh = JsonConvert.DeserializeObject<Json.PulseDetector.Root_Header>(jsonHeaders[i]);
                                CreatePulseDetector(rh.pulseDetector);
                            }
                        }
                        catch (Exception e)
                        {
                            Console.WriteLine("Excpetion: " + e.Data);
                        }
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine("Excpetion: " + e.Data);
                }
                finally
                {
                    this.headerSetted = true;
                }
            }
        }

        public void UpdateObjects(string data)
        {
            if (data.Contains("data")) //if it's probably a json
            {
                try
                {
                    string[] jsonDatas = data.Split('#');

                    for (int i = 0; i < jsonDatas.Length; i++)
                    {
                        try
                        {
                            //-------- Button ------------
                            if (jsonDatas[i].Contains("button"))
                            {
                                Json.Button.Root_Data rd = JsonConvert.DeserializeObject<Json.Button.Root_Data>(jsonDatas[i]);
                                UpdateButton(rd.button);
                            }
                            //-------- Potentiometer ------------
                            if (jsonDatas[i].Contains("potentiometer"))
                            {
                                Json.Potentiometer.Root_Data rd = JsonConvert.DeserializeObject<Json.Potentiometer.Root_Data>(jsonDatas[i]);
                                UpdatePotentiometer(rd.potentiometer);
                            }
                            //-------- RGBLed ------------
                            if (jsonDatas[i].Contains("rgb_led"))
                            {
                                Json.RGBLed.Root_Data rd = JsonConvert.DeserializeObject<Json.RGBLed.Root_Data>(jsonDatas[i]);
                                UpdateRGBLed(rd.rgb_led);
                            }
                            //-------- MPU ------------
                            if (jsonDatas[i].Contains("mpu"))
                            {
                                Json.MPU.Root_Data rd = JsonConvert.DeserializeObject<Json.MPU.Root_Data>(jsonDatas[i]);
                                UpdateMPU(rd.mpu);
                            }
                            //-------- SERVO ------------
                            if (jsonDatas[i].Contains("servo"))
                            {
                                Json.Servo.Root_Data rd = JsonConvert.DeserializeObject<Json.Servo.Root_Data>(jsonDatas[i]);
                                UpdateServo(rd.servo);
                            }
                            //-------- HALL EFFECT ------------
                            if (jsonDatas[i].Contains("hallEffect"))
                            {
                                Json.HallEffect.Root_Data rd = JsonConvert.DeserializeObject<Json.HallEffect.Root_Data>(jsonDatas[i]);
                                UpdateHallEffect(rd.hallEffect);
                            }
                            //-------- PULSE DETECTOR ------------
                            if (jsonDatas[i].Contains("pulseDetector"))
                            {
                                Json.PulseDetector.Root_Data rd = JsonConvert.DeserializeObject<Json.PulseDetector.Root_Data>(jsonDatas[i]);
                                UpdatePulseDetector(rd.pulseDetector);
                            }
                        }
                        catch (Exception e)
                        {
                            Console.WriteLine("Excpetion: " + e.Data);
                        }
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
