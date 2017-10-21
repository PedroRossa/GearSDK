using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace csharp_sample.Gear_Objects
{
    class Gear_MPU6050_csharp
    {
        #region Private Attributes

        int id;
        string name;
        string pin_SDA;
        string pin_SCL;
        int[] accel_Values;
        int[] gyro_Values;

        double[] angle_Values;

        #endregion

        #region Constructors

        public Gear_MPU6050_csharp()
        {

        }

        public Gear_MPU6050_csharp(int id, string name, string pin_SDA, string pin_SCL, int[] accel_Values, int[] gyro_Values, double[] angle_Values)
        {
            this.id = id;
            this.name = name;
            this.pin_SDA = pin_SDA;
            this.pin_SCL = pin_SCL;
            this.accel_Values = accel_Values;
            this.gyro_Values = gyro_Values;
            this.angle_Values = angle_Values;

        }

        public Gear_MPU6050_csharp(int id, string name, string pin_SDA, string pin_SCL, int accel_x = 0, int accel_y = 0, int accel_z = 0, int gyro_x = 0, int gyro_y = 0, int gyro_z = 0)
        {
            this.id = id;
            this.name = name;
            this.pin_SDA = pin_SDA;
            this.pin_SCL = pin_SCL;

            int[] accel = new int[] { accel_x, accel_y, accel_z };
            this.accel_Values = accel;

            int[] gyro = new int[] { gyro_x, gyro_y, gyro_z };
            this.gyro_Values = gyro;

            double[] angle = new double[3];
            this.angle_Values = angle;
        }

        #endregion

        #region Gets and Sets

        public int Id { get => id; }
        public string Name { get => name; }
        public string Pin_SDA { get => pin_SDA; }
        public string Pin_SCL { get => pin_SCL; }
        public int[] Accel_Values { get => accel_Values; set => accel_Values = value; }
        public int[] Gyro_Values { get => gyro_Values; set => gyro_Values = value; }
        public double[] Angle_Values { get => angle_Values; set => angle_Values = value; }

        #endregion
    }
}
