using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Console_Sample.Gear_Objects
{
    class Gear_RGBLed_csharp
    {
        #region Attributes

        int id;
        string name;

        string pin_r;
        string pin_g;
        string pin_b;

        int mode;
        uint timeOn;
        uint timeOff;

        int r_value;
        int g_value;
        int b_value;

        #endregion

        #region Constructors

        public Gear_RGBLed_csharp()
        {

        }

        public Gear_RGBLed_csharp(int id, string name, string pin_r, string pin_g, string pin_b, int mode = (int)Helper.LedMode.STATIC, int r_value = 1023, int g_value = 1023, int b_value = 1023, uint timeOn = 1000, uint timeOff = 500)
        {
            this.id = id;
            this.name = name;

            this.pin_r = pin_r;
            this.pin_g = pin_g;
            this.pin_b = pin_b;

            this.mode = mode;
            this.timeOn = timeOn;
            this.timeOff = timeOff;

            this.r_value = r_value;
            this.g_value = g_value;
            this.b_value = b_value;
        }

        #endregion

        #region Gets and Sets

        public int Id { get => id; }
        public string Name { get => name; }
        public string Pin_r { get => pin_r; }
        public string Pin_g { get => pin_g; }
        public string Pin_b { get => pin_b; }

        public int Mode { get => mode; }
        public uint TimeOn { get => timeOn; }
        public uint TimeOff { get => timeOff; }
        public int R_value { get => r_value; set => r_value = value; }
        public int G_value { get => g_value; set => g_value = value; }
        public int B_value { get => b_value; set => b_value = value; }

        public void SetMode(Helper.LedMode mode, uint timeOn = 1000, uint timeOff = 500)
        {
            this.mode = (int)mode;
            this.timeOn = timeOn;
            this.timeOff = timeOff;
        }

        public void SetRGB_Value(int[] values)
        {
            this.r_value = values[0];
            this.g_value = values[1];
            this.b_value = values[2];
        }

        public void SetRGB_Value(int r, int g, int b)
        {
            this.r_value = r;
            this.g_value = g;
            this.b_value = b;
        }

        #endregion


        #region Public Methods

        public string UpdatedJson()
        {
            /*{
                "name": "rgb_led_0",
                "pin": "D3,D4,D5",
                "mode": "BLINKING",
                "value": { "r": 0, "g": 1023, "b": 0 }
                }*/
            string val = "{\"name\":\"" + this.name + "\",";
            val += "\"pin\":\"" + this.pin_r + "," + this.pin_g + "," + this.pin_b + "\",";
            val += "\"mode\":" + this.mode + ",";
            val += "\"value\": {\"r\":" + this.r_value + ", \"g\":" + this.g_value + ", \"b\":" + this.b_value;
            val += "}}";

            return val;
        }

        #endregion
    }
}
