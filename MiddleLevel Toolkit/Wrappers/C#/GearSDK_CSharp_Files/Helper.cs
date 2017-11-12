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
}
