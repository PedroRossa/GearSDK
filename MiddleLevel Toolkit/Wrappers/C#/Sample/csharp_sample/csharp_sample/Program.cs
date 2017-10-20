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
            csharp_Client client = new csharp_Client("192.168.15.8", 81);

            client.Init();

            while (client.connection.IsConnected)
            {
                client.Update();

                if (client.CanUpdateObjects)
                {
                    //UpdateObjects();
                }
            }
        }
    }
}
