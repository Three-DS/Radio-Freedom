
unit hb;
interface

uses
  ctypes;

{
  Automatically converted by H2Pas 1.0.0 from hb.h
  The following command line parameters were used:
    -d
    -C
    hb.h
}

  Type
  Pu32  = ^u32;
{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}


{$ifndef HB_H}
{$define HB_H}  
  { WARNING ! THIS FILE PROVIDES AN INTERFACE TO A NON-OFFICIAL SERVICE PROVIDED BY NINJHAX }
  { BY USING COMMANDS FROM THIS SERVICE YOU WILL LIKELY MAKE YOUR APPLICATION INCOMPATIBLE WITH OTHER HOMEBREW LAUNCHING METHODS }
  { A GOOD WAY TO COPE WITH THIS IS TO CHECK THE OUTPUT OF initHb FOR ERRORS }
{$include <3ds/types.h>}

  function hbInit:Result;cdecl;external;

  procedure hbExit;cdecl;external;

  { flushes/invalidates entire data/instruction cache }
  { can be useful when writing code to executable pages }
  function HB_FlushInvalidateCache:Result;cdecl;external;

  { fetches the address for ninjhax bootloader addresses, useful for running 3dsx executables }
  { void (*callBootloader)(Handle hb, Handle file); }
  { void (*setArgs)(u32* src, u32 length); }
  function HB_GetBootloaderAddresses(load3dsx:Ppointer; setArgv:Ppointer):Result;cdecl;external;

  { changes the permissions of a given number of pages at address addr to mode }
  { should it fail, the appropriate kernel error code will be returned and *reprotectedPages (if not NULL) }
  { will be set to the number of sequential pages which were successfully reprotected + 1 }
  function HB_ReprotectMemory(addr:Pu32; pages:u32; mode:u32; reprotectedPages:Pu32):Result;cdecl;external;

{$endif}

implementation


end.
