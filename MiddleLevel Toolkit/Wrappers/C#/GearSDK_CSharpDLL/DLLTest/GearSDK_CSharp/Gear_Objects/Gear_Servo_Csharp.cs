using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GearSDK_CSharpDLL.Gear_Objects
{
    public class Gear_Servo_csharp
    {
        #region Attributes

        int id;
        string name;
        string pin;
        int value;

        string lastJson;

        #endregion

        #region Constructors

        public Gear_Servo_csharp()
        {
            
        }

        public Gear_Servo_csharp(int id, string name, string pin, int value)
        {
            this.id = id;
            this.name = name;
            this.pin = pin;
            this.value = value;
        }

        #endregion

        #region Gets and Sets
        
        public int Id { get => id; }
        public string Name { get => name; }
        public string Pin { get => pin; }
        public int Value { get => value; set => this.value = value; }

        #endregion

        #region Public Methods

        public string UpdatedJson()
        {
            string val = "{\"servo\":{\"name\":\"" + this.name + "\",";
            val += "\"value\":" + this.value.ToString();
            val += "}}";

            if (val != lastJson)
            {
                lastJson = val;
            }
            else
            {
                val = "";
            }

            return val;
        }

        #endregion
    }
}

namespace Json.Servo
{
    public class Header
    {
        public string name { get; set; }
        public string pin { get; set; }
        public int value { get; set; }
    }

    public class Root_Header
    {
        public Header servo { get; set; }
    }
    
    public class Data
    {
        public string name { get; set; }
        public int value { get; set; }
    }

    public class Root_Data
    {
        public Data servo { get; set; }
    }
}
