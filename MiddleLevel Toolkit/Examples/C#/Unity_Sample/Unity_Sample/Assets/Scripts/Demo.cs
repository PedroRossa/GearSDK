using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using WebSocketSharp;
using GearSDK_CSharpDLL;

using UnityEngine.UI;

public class Demo : MonoBehaviour
{
    public Text txtButton;
    public Text txtPotentiometer;
    public Text txtAccel;
    public Text txtGyro;
    public Text txtAngle;
    public Text txtRGBLed;

    csharp_Client client;

    private void Init()
    {
        client = GearSDK.CreateClient("192.168.15.9", 81);
        client.Init();
    }

    void Start ()
    {
        Init();

    }
	
	void Update ()
    {
        if (client.connection.IsConnected)
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

                txtButton.text = "BUTTON: " + buttonState;
                txtPotentiometer.text = "POTENTIOMETER: " + potentiometer;
                txtAccel.text = "ACELEROMETER: (" + acellX + ", " + acellY + ", " + acellZ + ")";
                txtGyro.text = "GYRO: (" + gyroX + ", " + gyroY + ", " + gyroZ + ")";
                txtAngle.text = "ANGLE: (" + angleX + ", " + angleY + ", " + angleZ + ")";
                txtRGBLed.text = "RGB LED: (" + r + ", " + g + ", " + b + ")";
                
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
            }
        }
    }

    private void OnApplicationQuit()
    {
        client.connection.Disconnect();
    }
}
