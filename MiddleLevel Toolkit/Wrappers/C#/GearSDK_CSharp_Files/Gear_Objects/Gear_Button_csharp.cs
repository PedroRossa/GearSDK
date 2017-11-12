using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GearSDK_CSharpDLL.Gear_Objects
{
    public class Gear_Button_csharp
    {
        #region Attributes

        int id;
        string name;
        string pin;
        bool state;
        int type;

        #endregion

        #region Constructors

        public Gear_Button_csharp()
        {
            
        }

        public Gear_Button_csharp(int id, string name, string pin, bool state = false, int type = (int)Helper.ButtonType.PUSH_BUTTON)
        {
            this.id = id;
            this.name = name;
            this.pin = pin;
            this.state = state;
            this.type = type;
        }

        #endregion

        #region Gets and Sets
        
        public int Id { get => id; }
        public string Name { get => name; }
        public string Pin { get => pin; }
        public bool State { get => state; set => state = value; }
        public int Type { get => type; }

        #endregion

    }
}

namespace Json.Button
{
    public class Header
    {
        public string name { get; set; }
        public string pin { get; set; }
        public int state { get; set; }
        public int type { get; set; }
    }

    public class Root_Header
    {
        public Header button { get; set; }
    }

    public class Data
    {
        public string name { get; set; }
        public int state { get; set; }
    }

    public class Root_Data
    {
        public Data button { get; set; }
    }
}
