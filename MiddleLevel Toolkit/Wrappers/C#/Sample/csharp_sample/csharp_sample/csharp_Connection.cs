using System;
using WebSocketSharp;

namespace csharp_sample
{
    class csharp_Connection
    {
        #region Private Attributes

        WebSocket webSocketClient;

        private string hardwareIP;
        private int port;
        
        private string receivedMessage;
        
        private int messageCounter = 0;
        private bool isConnected = false;
        
        #endregion

        #region Constructors

        public csharp_Connection()
        {

        }

        public csharp_Connection(string ip, int port = 81)
        {
            this.hardwareIP = ip;
            this.port = port;
        }

        #endregion

        #region Gets and Sets
        
        public string IP { get => hardwareIP; set => hardwareIP = value; }
        public int Port { get => port; set => port = value; }
        public int MessageCounter { get => messageCounter; }
        public bool IsConnected { get => isConnected; set => isConnected = value; }

        #endregion

        #region Public Methods

        public bool Connect(string initialMessage = "Hello Hardware i'm the C# =P !!!")
        {
            try
            {
                webSocketClient = new WebSocket("ws://" + this.hardwareIP + ":" + this.port);

                // On connection is opened
                webSocketClient.OnOpen += (sender, e) =>
                {
                    webSocketClient.Send(initialMessage);
                };
                //On client receive a message
                webSocketClient.OnMessage += (sender, e) =>
                {
                    this.receivedMessage = e.Data;
                    Console.WriteLine("Server says: " + e.Data);
                };
                //On connection is closed
                webSocketClient.OnClose += (sender, e) =>
                {
                    Disconnect();
                };

                webSocketClient.Connect();

            }
            catch (Exception e)
            {
                Console.WriteLine("Error on send message: " + e.Message);
                this.isConnected = false;
                return false;
            }
            this.isConnected = true;
            return true;
        }

        public void Disconnect(string byebyeMessage = "Bye bye my Hardware Friend")
        {
            webSocketClient.Close();

            Console.WriteLine("Oh, it's so Sad, but we are alone now :( ");
            this.isConnected = false;
        }


        public bool SendMessage(string message)
        {
            try
            {
                webSocketClient.Send(message);
            }
            catch (Exception e)
            {
                Console.WriteLine("Error on send message:" + e.Message);
                return false;
            }

            return true;
        }

        public string ReceivedMessage()
        {
            return receivedMessage;
        }

        public bool StablishConnection()
        {
            while (!this.isConnected)
            {
                if(this.Connect())
                    this.SendMessage("Server we are sooo connected!!! <3");
                else
                {
                    Console.WriteLine("Some problem with the connection occurs!");
                    Console.ReadKey(true);
                    return false;
                }
            }
            return true;
        }

        #endregion
    }
}
