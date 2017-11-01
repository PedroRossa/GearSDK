
namespace GearSDK_CSharpDLL
{
    public class GearSDK
    {
        public static csharp_Client CreateClient(string ip, int port)
        {
            return new csharp_Client(ip, port);
        }
        
    }
}
