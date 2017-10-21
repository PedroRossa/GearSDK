using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace csharp_sample.Gear_Objects
{
    class Gear_Potentiometer_csharp
    {
        #region Attributes

        int id;
        string name;
        string pin;
        int value;

        #endregion

        #region Constructors

        public Gear_Potentiometer_csharp()
        {

        }

        public Gear_Potentiometer_csharp(int id, string name, string pin, int value)
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
    }
}
