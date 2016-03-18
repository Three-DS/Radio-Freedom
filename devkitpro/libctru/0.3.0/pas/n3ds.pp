//Author KennyD Lee
//written & published @ the downtown (Gatineau, Qc pro-litter-riot's university)

unit n3ds;

interface

{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}

uses ctypes;

{$linklib ctru}

{$linklib c}
{$linklib gcc}
{$linklib g}
{$linklib sysbase}

{$define 3dsintf}
{$i "3ds/3dstypes.inc"}
{$i 3ds/svc.inc}
{$i 3ds/srv.inc}
{$i 3ds/linear.inc}
{$i 3ds/os.inc}
{$i 3ds/gfx.inc}
{$i 3ds/services/ac.inc}
{$i 3ds/services/apt.inc}
{$i 3ds/services/cfgnor.inc}
{$i 3ds/services/csnd.inc}
{$i 3ds/services/fs.inc}
{$i 3ds/services/gsp.inc}
{$i 3ds/services/hid.inc}
{$i 3ds/services/irrst.inc}
{$i 3ds/services/httpc.inc}
{$i 3ds/services/ir.inc}
{$i 3ds/services/ptm.inc}
{$i 3ds/services/soc.inc}
{$i 3ds/services/mic.inc}
{$i 3ds/services/mvd.inc}
{$i 3ds/gpu/gx.inc}
{$i 3ds/gpu/gpu.inc}
{$i 3ds/gpu/shdr.inc}
{.$i 3ds/util/rbtree.inc}
{$i 3ds/sdmc.inc}
{$undef 3dsintf}

implementation

{$define 3dsimpl}
{$i 3ds/3dstypes.inc}
{$i 3ds/os.inc}

{$i 3ds/services/apt.inc}
{$i 3ds/services/gsp.inc}

{$i 3ds/gpu/gx.inc}
{$i 3ds/gpu/gpu.inc}
{.$i 3ds/util/rbtree.inc}

{$undef 3dsimpl}

end.
