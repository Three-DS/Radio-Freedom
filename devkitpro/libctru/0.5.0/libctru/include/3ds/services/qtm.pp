
unit qtm;
interface

uses
  ctypes;

{
  Automatically converted by H2Pas 1.0.0 from qtm.h
  The following command line parameters were used:
    -d
    -C
    qtm.h
}

  Type
  Pcfloat  = ^cfloat;
  PqtmHeadtrackingInfo  = ^qtmHeadtrackingInfo;
  PqtmHeadtrackingInfoCoord  = ^qtmHeadtrackingInfoCoord;
  Pu32  = ^u32;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


(** unsupported pragma#pragma once*)
  {See also: http://3dbrew.org/wiki/QTM_Services }

  type
    qtmHeadtrackingInfoCoord = record
        x : cfloat;
        y : cfloat;
      end;
  {"not used by System_Settings." }
  {"Not used by System_Settings." }

    qtmHeadtrackingInfo = record
        flags : array[0..4] of u8;
        padding : array[0..2] of u8;
        floatdata_x08 : cfloat;
        coords0 : array[0..3] of qtmHeadtrackingInfoCoord;
        unk_x2c : array[0..4] of u32;
      end;

  function qtmInit:Result;cdecl;external;

  procedure qtmExit;cdecl;external;

  function qtmCheckInitialized:bool;cdecl;external;

  function qtmGetHeadtrackingInfo(val:u64; out:PqtmHeadtrackingInfo):Result;cdecl;external;

  {val is normally 0. }
  function qtmCheckHeadFullyDetected(info:PqtmHeadtrackingInfo):bool;cdecl;external;

  function qtmConvertCoordToScreen(coord:PqtmHeadtrackingInfoCoord; screen_width:Pcfloat; screen_height:Pcfloat; x:Pu32; y:Pu32):Result;cdecl;external;

  {screen_* can be NULL to use the default values for the top-screen. }

implementation


end.
