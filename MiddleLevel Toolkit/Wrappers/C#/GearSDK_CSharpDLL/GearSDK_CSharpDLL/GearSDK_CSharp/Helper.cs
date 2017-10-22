using System;
using System.Collections.Generic;

namespace GearSDK_CSharpDLL
{
    public class Helper
    {
        public enum ButtonType
        {
            PUSH_BUTTON = 0,
            STATE_BUTTON = 1
        };

        public enum LedMode
        {
            STATIC = 0,
            BLINK = 1,
            BLINKING = 2,
            FADE = 3,
            FADING = 4
        };
    }


    public class Header_Button
    {
        public string name { get; set; }
        public string pin { get; set; }
        public bool state { get; set; }
        public int type { get; set; }
    }

    public class Header_Potentiometer
    {
        public string name { get; set; }
        public string pin { get; set; }
        public int value { get; set; }
    }

    public class Header_Mpu
    {
        public string name { get; set; }
        public string pins { get; set; }
        public Accel accel { get; set; }
        public Gyro gyro { get; set; }
        public Angle angle { get; set; }
    }

    public class Header_RgbLed
    {
        public string name { get; set; }
        public string pin { get; set; }
        public int mode { get; set; }
        public Value value { get; set; }
    }

    public class Header_Led
    {
        public string name { get; set; }
        public string pin { get; set; }
        public int value { get; set; }
    }


    public class Data_Button
    {
        public int state { get; set; }
        public int type { get; set; }
    }

    public class Data_Potentiometer
    {
        public int value { get; set; }
    }

    public class Data_RgbLed
    {
        public int mode { get; set; }
        public Value value { get; set; }
    }

    public class Data_Led
    {
        public int value { get; set; }
    }

    public class Data_Mpu
    {
        public Accel accel { get; set; }
        public Gyro gyro { get; set; }
        public Angle angle { get; set; }
    }


    public class Value
    {
        public int r { get; set; }
        public int g { get; set; }
        public int b { get; set; }
    }

    public class Accel
    {
        public int x { get; set; }
        public int y { get; set; }
        public int z { get; set; }
    }

    public class Gyro
    {
        public int x { get; set; }
        public int y { get; set; }
        public int z { get; set; }
    }

    public class Angle
    {
        public double x { get; set; }
        public double y { get; set; }
        public double z { get; set; }
    }


    public class Header
    {
        public List<Header_Button> buttons { get; set; }
        public List<Header_Potentiometer> potentiometers { get; set; }
        public List<Header_RgbLed> rgb_leds { get; set; }
        public List<Header_Led> leds { get; set; }
        public List<Header_Mpu> mpus { get; set; }
    }

    public class Data
    {
        public List<Data_Button> buttons { get; set; }
        public List<Data_Potentiometer> potentiometers { get; set; }
        public List<Data_RgbLed> rgb_leds { get; set; }
        public List<Data_Led> leds { get; set; }
        public List<Data_Mpu> mpus { get; set; }
    }

    public class Header_RootObject
    {
        public Header header { get; set; }
    }

    public class Data_RootObject
    {
        public Data data { get; set; }
    }
}
