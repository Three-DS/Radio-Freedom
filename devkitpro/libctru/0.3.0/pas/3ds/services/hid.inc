  const
     HID_SHAREDMEM_DEFAULT = $10000000;     
  { (new 3DS only) }
  { (new 3DS only) }
  { Not actually provided by HID }
  { c-stick (new 3DS only) }
  { c-stick (new 3DS only) }
  { c-stick (new 3DS only) }
  { c-stick (new 3DS only) }
  { circle pad }
  { circle pad }
  { circle pad }
  { circle pad }
  { Generic catch-all directions }

  //!	Bit values for the keypad buttons. <-- input.inc
  type
  KEYPAD_BITS = cint;
     // PAD_KEY = (
  const
                KEY_A : KEYPAD_BITS = (1 shl 0);
		KEY_B : KEYPAD_BITS = (1 shl 1);
		KEY_SELECT : KEYPAD_BITS = (1 shl 2);
       		KEY_START : KEYPAD_BITS = (1 shl 3);
		KEY_DRIGHT : KEYPAD_BITS = (1 shl 4);
		KEY_DLEFT : KEYPAD_BITS = (1 shl 5);
       		KEY_DUP : KEYPAD_BITS = (1 shl 6);
		KEY_DDOWN : KEYPAD_BITS = (1 shl 7);
		KEY_R : KEYPAD_BITS = (1 shl 8);
       		KEY_L : KEYPAD_BITS = (1 shl 9);
		KEY_X : KEYPAD_BITS = (1 shl 10);
		KEY_Y : KEYPAD_BITS = (1 shl 11);
		KEY_ZL : KEYPAD_BITS = (1 shl 14);
       		KEY_ZR : KEYPAD_BITS = (1 shl 15);
		KEY_TOUCH : KEYPAD_BITS = (1 shl 20);
		KEY_CSTICK_RIGHT : KEYPAD_BITS = (1 shl 24);
       		KEY_CSTICK_LEFT : KEYPAD_BITS = (1 shl 25);
		KEY_CSTICK_UP : KEYPAD_BITS = (1 shl 26);
       		KEY_CSTICK_DOWN : KEYPAD_BITS = (1 shl 27);
		KEY_CPAD_RIGHT : KEYPAD_BITS = (1 shl 28);
       		KEY_CPAD_LEFT : KEYPAD_BITS = (1 shl 29);
		KEY_CPAD_UP : KEYPAD_BITS = (1 shl 30);
       		KEY_CPAD_DOWN : KEYPAD_BITS = (1 shl 31);
	//	KEY_UP : KEYPAD_BITS = (KEY_DUP or KEY_CPAD_UP);
	//	KEY_DOWN : KEYPAD_BITS = (KEY_DDOWN or KEY_CPAD_DOWN);
       	//	KEY_LEFT = KEY_DLEFT or KEY_CPAD_LEFT;
	//	KEY_RIGHT = KEY_DRIGHT or KEY_CPAD_RIGHT;
              //  );
  type
     touchPosition = record
          px : u16;
          py : u16;
       end;
     PtouchPosition  = ^touchPosition;

     circlePosition = record
          dx : s16;
          dy : s16;
       end;
     PcirclePosition  = ^circlePosition;

     accelVector = record
          x : s16;
          y : s16;
          z : s16;
       end;
     PaccelVector  = ^accelVector;
  {roll }
  {yaw }
  {pitch }

     angularRate = record
          x : s16;
          z : s16;
          y : s16;
       end;
     PangularRate  = ^angularRate;

  {"Event signaled by HID-module, when the sharedmem+0(PAD/circle-pad)/+0xA8(touch-screen) region was updated." }
  {"Event signaled by HID-module, when the sharedmem+0(PAD/circle-pad)/+0xA8(touch-screen) region was updated." }
  {"Event signaled by HID-module, when the sharedmem accelerometer state was updated." }
  {"Event signaled by HID-module, when the sharedmem gyroscope state was updated." }
  {"Event signaled by HID-module, when the sharedmem DebugPad state was updated." }
  { used to know how many events there are }

     HID_Event = (HIDEVENT_PAD0 := 0,
		  HIDEVENT_PAD1,
		  HIDEVENT_Accel,
       		  HIDEVENT_Gyro,
		  HIDEVENT_DebugPad,
		  HIDEVENT_MAX);

    var
       hidMemHandle : Handle;cvar;external;
       hidSharedMem : pu32;cvar;external;

  function hidInit(sharedMem:pu32):s32;cdecl;external;
  procedure hidExit;cdecl;external;
  procedure hidScanInput;cdecl;external;
  function hidKeysHeld:u32;cdecl;external;
  function hidKeysDown:u32;cdecl;external;
  function hidKeysUp:u32;cdecl;external;
  procedure hidTouchRead(pos:ptouchPosition);cdecl;external;
  procedure hidCircleRead(pos:pcirclePosition);cdecl;external;
  procedure hidAccelRead(vector:paccelVector);cdecl;external;
  procedure hidGyroRead(rate:pangularRate);cdecl;external;
  procedure hidWaitForEvent(id:HID_Event; nextEvent:bool);cdecl;external;

  { libnds compatibility defines }

{  type
     scanKeys = hidScanInput;
     keysHeld = hidKeysHeld;     
     keysDown = hidKeysDown;     
     keysUp = hidKeysUp;     
     touchRead = hidTouchRead;     
     circleRead = hidCircleRead;
 }

  function HIDUSER_GetHandles(outMemHandle:pHandle; eventpad0:pHandle; eventpad1:pHandle; eventaccel:pHandle; eventgyro:pHandle; eventdebugpad:pHandle):s32;cdecl;external;
  function HIDUSER_EnableAccelerometer:s32;cdecl;external;
  function HIDUSER_DisableAccelerometer:s32;cdecl;external;
  function HIDUSER_EnableGyroscope:s32;cdecl;external;
  function HIDUSER_DisableGyroscope:s32;cdecl;external;

