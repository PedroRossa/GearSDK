using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using GearSDK_CSharpDLL;

namespace Console_Sample
{
    class Program
    {
        static void Main(string[] args)
        {
           csharp_Client client = GearSDK.CreateClient("192.168.15.4", 81);

            client.Init();

            while (client.connection.IsConnected)
            {
                client.Update();

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

                Console.WriteLine("BUTTON: " + buttonState);
                Console.WriteLine("POTENTIOMETER: " + potentiometer);
                Console.WriteLine("ACELEROMETER: (" + acellX + ", " + acellY + ", " + acellZ + ")");
                Console.WriteLine("GYRO: (" + gyroX + ", " + gyroY + ", " + gyroZ + ")");
                Console.WriteLine("ANGLE: (" + angleX + ", " + angleY + ", " + angleZ + ")");
                Console.WriteLine("RGB LED: (" + r + ", " + g + ", " + b + ")");

                float intensity = potentiometer / 1000.0f;

                if (buttonState)
                {
                    client.wrapper.RgbLeds[0].SetRGB_Value((int)(intensity * 1023), (int)(intensity * 0), (int)(intensity * 1023));
                    client.wrapper.RgbLeds[0].SetMode(Helper.LedMode.STATIC);
                    //wrapper.GetRGBLed(0)->SetMode(LedMode::BLINKING, 500, 100);
                    string s = client.wrapper.RgbLeds[0].UpdatedJson();

                    if (!string.IsNullOrEmpty(s))
                        client.connection.SendMessage(s);

                }
                else
                {
                    client.wrapper.RgbLeds[0].SetRGB_Value((int)(intensity * 0), (int)(intensity * 1023), (int)(intensity * 1023));
                    client.wrapper.RgbLeds[0].SetMode(Helper.LedMode.STATIC);

                    string s = client.wrapper.RgbLeds[0].UpdatedJson();

                    if(!string.IsNullOrEmpty(s))
                        client.connection.SendMessage(s);
                }

                System.Threading.Thread.Sleep(50);
                Console.Clear();
            }
        }
    }
}
