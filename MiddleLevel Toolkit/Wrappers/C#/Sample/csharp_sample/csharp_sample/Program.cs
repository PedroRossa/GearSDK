using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace csharp_sample
{
    class Program
    {      
        static void Main(string[] args)
        {
            csharp_Client client = new csharp_Client("192.168.15.9", 81);

            client.Init();

            while (client.connection.IsConnected)
            {
                client.Update();

                if (client.CanUpdateObjects)
                {
                    double ax = client.wrapper.Mpus[0].Angle_Values[0];
                    double ay = client.wrapper.Mpus[0].Angle_Values[1];
                    double az = client.wrapper.Mpus[0].Angle_Values[2];

                    Console.WriteLine(ax + " " + ay + " " + az);

                    float intensity = client.wrapper.Potentiometers[0].Value / 1000.0f;

                    if (client.wrapper.Buttons[0].State)
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
                }
            }
        }
    }
}
