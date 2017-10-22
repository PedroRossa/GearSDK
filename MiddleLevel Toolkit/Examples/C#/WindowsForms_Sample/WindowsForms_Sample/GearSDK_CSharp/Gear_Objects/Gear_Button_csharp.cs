using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsForms_Sample.Gear_Objects
{
    class Gear_Button_csharp
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
