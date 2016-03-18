type

     SHDR_type = (VERTEX_SHDR := $0,GEOMETRY_SHDR := $1);

     SHDR_outType = (RESULT_POSITION := $0,
                     RESULT_COLOR := $2,
       		     RESULT_TEXCOORD0 := $3,
		     RESULT_TEXCOORD1 := $5,
                     RESULT_TEXCOORD2 := $6);

     DVLP_s = record
          codeSize : u32;
          codeData : ^u32;
          opdescSize : u32;
          opcdescData : ^u32;
       end;
     PDVLP_s  = ^DVLP_s;

     DVLE_constEntry_s = record
          header : u32;
          data : array[0..3] of u32;
       end;

     DVLE_outEntry_s = record
          _type : u16;
          regID : u16;
          header : u32;
       end;

     DVLE_uniformEntry_s = record
          symbolOffset : u32;
          startReg : u16;
          endReg : u16;
       end;

     DVLE_s = record
          _type : SHDR_type;
          mainOffset : u32;
          endmainOffset : u32;
          constTableSize : u32;
          constTableData : ^DVLE_constEntry_s;
          outTableSize : u32;
          outTableData : ^DVLE_outEntry_s;
          uniformTableSize : u32;
          uniformTableData : ^DVLE_uniformEntry_s;
          symbolTableData : ^char;
       end;
     PDVLE_s  = ^DVLE_s;

     DVLB_s = record
          numDVLE : u32;
          DVLP : DVLP_s;
          DVLE : ^DVLE_s;
       end;
     PDVLB_s  = ^DVLB_s;

  function SHDR_ParseSHBIN(shbinData:pu32; shbinSize:u32):pDVLB_s;cdecl;external;
  procedure SHDR_UseProgram(dvlb:pDVLB_s; id:u8);cdecl;external;
  procedure SHDR_FreeDVLB(dvlb:pDVLB_s);cdecl;external;
  function SHDR_GetUniformRegister(dvlb:pDVLB_s; name:pchar; programID:u8):s8;cdecl;external;
  procedure DVLP_SendCode(dvlp:pDVLP_s);cdecl;external;
  procedure DVLP_SendOpDesc(dvlp:pDVLP_s);cdecl;external;
  procedure DVLE_SendOutmap(dvle:pDVLE_s);cdecl;external;
  procedure DVLE_SendConstants(dvle:pDVLE_s);cdecl;external;
