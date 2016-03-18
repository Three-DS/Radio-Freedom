  type

     mvdstdMode = (MVDMODE_COLORFORMATCONV,MVDMODE_VIDEOPROCESSING);
     mvdstdTypeInput = (MVDTYPEIN_YUYV422 := $00010001,MVDTYPEIN_H264 := $00020001);
     mvdstdTypeOutput = (MVDTYPEOUT_RGB565 := $00040002);
  {0x0 for colorconv, 0x1 for H.264 }
  {Only set for H.264. }

     mvdstdConfig = record
          input_type : mvdstdTypeInput;
          unk_x04 : u32;
          unk_x08 : u32;
          inwidth : u32;
          inheight : u32;
          physaddr_colorconv_indata : u32;
          unk_x18 : array[0..($28 shr 2)-1] of u32;
          flag_x40 : u32;
          unk_x44 : u32;
          unk_x48 : u32;
          outheight0 : u32;
          outwidth0 : u32;
          unk_x54 : u32;
          output_type : mvdstdTypeOutput;
          outwidth1 : u32;
          outheight1 : u32;
          physaddr_outdata0 : u32;
          physaddr_outdata1_colorconv : u32;
          unk_x6c : array[0..($b0 shr 2)-1] of u32;
       end;
       PmvdstdConfig  = ^mvdstdConfig;

  procedure mvdstdGenerateDefaultConfig(config:pmvdstdConfig; input_width:u32; input_height:u32; output_width:u32; output_height:u32; 
              vaddr_colorconv_indata:pu32; vaddr_outdata0:pu32; vaddr_outdata1_colorconv:pu32);cdecl;external;

  function mvdstdInit(mode:mvdstdMode; input_type:mvdstdTypeInput; output_type:mvdstdTypeOutput; size:u32):s32;cdecl;external;

  {The input size isn't used when type==MVDTYPE_COLORFORMATCONV. Video processing / H.264 isn't supported currently. }
  function mvdstdShutdown:s32;cdecl;external;
  function mvdstdSetConfig(config:pmvdstdConfig):s32;cdecl;external;
  function mvdstdProcessFrame(config:pmvdstdConfig; h264_vaddr_inframe:pu32; h264_inframesize:u32; h264_frameid:u32):s32;cdecl;external;
