{$ifdef 3dsintf}

  procedure GPU_Init(gsphandle:pHandle);cdecl;external;
  procedure GPU_Reset(gxbuf:pu32; gpuBuf:pu32; gpuBufSize:u32);cdecl;external;
  procedure GPUCMD_SetBuffer(adr:pu32; size:u32; offset:u32);cdecl;external;
  procedure GPUCMD_SetBufferOffset(offset:u32);cdecl;external;
  procedure GPUCMD_GetBuffer(adr:pu32; size:pu32; offset:pu32);cdecl;external;
  procedure GPUCMD_AddRawCommands(cmd:pu32; size:u32);cdecl;external;
  procedure GPUCMD_Run(gxbuf:pu32);cdecl;external;
  procedure GPUCMD_FlushAndRun(gxbuf:pu32);cdecl;external;
  procedure GPUCMD_Add(cmd:u32; param:pu32; paramlength:u32);cdecl;external;
  procedure GPUCMD_AddSingleParam(cmd:u32; param:u32);cdecl;external;
  procedure GPUCMD_Finalize;cdecl;external;

  {tex param }
  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GPU_TEXTURE_MAG_FILTER(v : longint) : longint;  {takes a GPU_TEXTURE_FILTER_PARAM }

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GPU_TEXTURE_MIN_FILTER(v : longint) : longint;  {takes a GPU_TEXTURE_FILTER_PARAM }

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GPU_TEXTURE_WRAP_S(v : longint) : longint;  {takes a GPU_TEXTURE_WRAP_PARAM }

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GPU_TEXTURE_WRAP_T(v : longint) : longint;  {takes a GPU_TEXTURE_WRAP_PARAM }


  type

     GPU_TEXTURE_FILTER_PARAM = (GPU_NEAREST := $0,GPU_LINEAR := $1);

     GPU_TEXTURE_WRAP_PARAM = (GPU_CLAMP_TO_EDGE := $0,GPU_REPEAT := $2
       );

     GPU_TEXUNIT = (GPU_TEXUNIT0 := $1,GPU_TEXUNIT1 := $2,
       GPU_TEXUNIT2 := $4);

     GPU_TEXCOLOR = (GPU_RGBA8 := $0,GPU_RGB8 := $1,GPU_RGBA5551 := $2,
       GPU_RGB565 := $3,GPU_RGBA4 := $4,GPU_LA8 := $5,
       GPU_HILO8 := $6,GPU_L8 := $7,GPU_A8 := $8,
       GPU_LA4 := $9,GPU_L4 := $A,GPU_ETC1 := $B,
       GPU_ETC1A4 := $C);

     GPU_TESTFUNC = (GPU_NEVER := 0,GPU_ALWAYS := 1,GPU_EQUAL := 2,
       GPU_NOTEQUAL := 3,GPU_LESS := 4,GPU_LEQUAL := 5,
       GPU_GREATER := 6,GPU_GEQUAL := 7);
  { disable scissor test }
  { exclude pixels inside the scissor box }
  { 2 is the same as 0 }
  { exclude pixels outside of the scissor box }

     GPU_SCISSORMODE = (GPU_SCISSOR_DISABLE := 0,GPU_SCISSOR_INVERT := 1,
       GPU_SCISSOR_NORMAL := 3);
  { keep destination value }
  { destination & ~source }
  { destination ^ source }
  { 2 is the same as 1. Other values are too weird to even be usable. }

     GPU_STENCILOP = (GPU_KEEP := 0,GPU_AND_NOT := 1,GPU_XOR := 5
       );

     GPU_WRITEMASK = (GPU_WRITE_RED := $01,GPU_WRITE_GREEN := $02,
       GPU_WRITE_BLUE := $04,GPU_WRITE_ALPHA := $08,
       GPU_WRITE_DEPTH := $10,GPU_WRITE_COLOR := $0F,
       GPU_WRITE_ALL := $1F);

     GPU_BLENDEQUATION = (GPU_BLEND_ADD := 0,GPU_BLEND_SUBTRACT := 1,
       GPU_BLEND_REVERSE_SUBTRACT := 2,GPU_BLEND_MIN := 3,
       GPU_BLEND_MAX := 4);

     GPU_BLENDFACTOR = (GPU_ZERO := 0,GPU_ONE := 1,GPU_SRC_COLOR := 2,
       GPU_ONE_MINUS_SRC_COLOR := 3,GPU_DST_COLOR := 4,
       GPU_ONE_MINUS_DST_COLOR := 5,GPU_SRC_ALPHA := 6,
       GPU_ONE_MINUS_SRC_ALPHA := 7,GPU_DST_ALPHA := 8,
       GPU_ONE_MINUS_DST_ALPHA := 9,GPU_CONSTANT_COLOR := 10,
       GPU_ONE_MINUS_CONSTANT_COLOR := 11,
       GPU_CONSTANT_ALPHA := 12,GPU_ONE_MINUS_CONSTANT_ALPHA := 13,
       GPU_SRC_ALPHA_SATURATE := 14);

     GPU_LOGICOP = (GPU_LOGICOP_CLEAR := 0,GPU_LOGICOP_AND := 1,
       GPU_LOGICOP_AND_REVERSE := 2,GPU_LOGICOP_COPY := 3,
       GPU_LOGICOP_SET := 4,GPU_LOGICOP_COPY_INVERTED := 5,
       GPU_LOGICOP_NOOP := 6,GPU_LOGICOP_INVERT := 7,
       GPU_LOGICOP_NAND := 8,GPU_LOGICOP_OR := 9,
       GPU_LOGICOP_NOR := 10,GPU_LOGICOP_XOR := 11,
       GPU_LOGICOP_EQUIV := 12,GPU_LOGICOP_AND_INVERTED := 13,
       GPU_LOGICOP_OR_REVERSE := 14,GPU_LOGICOP_OR_INVERTED := 15
       );

     GPU_FORMATS = (GPU_BYTE := 0,GPU_UNSIGNED_BYTE := 1,
       GPU_SHORT := 2,GPU_FLOAT := 3);
  {defines for CW ? }

     GPU_CULLMODE = (GPU_CULL_NONE := 0,GPU_CULL_FRONT_CCW := 1,
       GPU_CULL_BACK_CCW := 2);
  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GPU_ATTRIBFMT(i,n,f : longint) : longint;  


  type

     GPU_TEVSRC = (GPU_PRIMARY_COLOR := $00,GPU_TEXTURE0 := $03,
       GPU_TEXTURE1 := $04,GPU_TEXTURE2 := $05,
       GPU_TEXTURE3 := $06,GPU_CONSTANT := $0E,
       GPU_PREVIOUS := $0F);
  {RGB only }

     GPU_COMBINEFUNC = (GPU_REPLACE := $00,GPU_MODULATE := $01,
       GPU_ADD := $02,GPU_ADD_SIGNED := $03,GPU_INTERPOLATE := $04,
       GPU_SUBTRACT := $05,GPU_DOT3_RGB := $06
       );
  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GPU_TEVSOURCES(a,b,c : longint) : longint;  

  { was #define dname(params) para_def_expr }
  { argument types are unknown }
  { return type might be wrong }   
  function GPU_TEVOPERANDS(a,b,c : longint) : longint;  

  { ? }

  type

     GPU_Primitive_t = (GPU_TRIANGLES := $0000,GPU_TRIANGLE_STRIP := $0100,
       GPU_TRIANGLE_FAN := $0200,GPU_UNKPRIM := $0300
       );

  procedure GPU_SetUniform(startreg:u32; data:pu32; numreg:u32);cdecl;external;

  procedure GPU_SetViewport(depthBuffer:pu32; colorBuffer:pu32; x:u32; y:u32; w:u32; 
              h:u32);cdecl;external;

  procedure GPU_SetScissorTest(mode:GPU_SCISSORMODE; x:u32; y:u32; w:u32; h:u32);cdecl;external;

  procedure GPU_DepthRange(nearVal:double; farVal:double);cdecl;external;

  procedure GPU_SetAlphaTest(enable:bool; _function:GPU_TESTFUNC; ref:u8);cdecl;external;

  procedure GPU_SetDepthTestAndWriteMask(enable:bool; _function:GPU_TESTFUNC; writemask:GPU_WRITEMASK);cdecl;external;

  { GPU_WRITEMASK values can be ORed together }
  procedure GPU_SetStencilTest(enable:bool; _function:GPU_TESTFUNC; ref:u8; mask:u8; replace:u8);cdecl;external;

  procedure GPU_SetStencilOp(sfail:GPU_STENCILOP; dfail:GPU_STENCILOP; pass:GPU_STENCILOP);cdecl;external;

  procedure GPU_SetFaceCulling(mode:GPU_CULLMODE);cdecl;external;

  { these two can't be used together }
  procedure GPU_SetAlphaBlending(colorEquation:GPU_BLENDEQUATION; alphaEquation:GPU_BLENDEQUATION; colorSrc:GPU_BLENDFACTOR; colorDst:GPU_BLENDFACTOR; alphaSrc:GPU_BLENDFACTOR; 
              alphaDst:GPU_BLENDFACTOR);cdecl;external;

  procedure GPU_SetColorLogicOp(op:GPU_LOGICOP);cdecl;external;

  procedure GPU_SetBlendingColor(r:u8; g:u8; b:u8; a:u8);cdecl;external;

  procedure GPU_SetAttributeBuffers(totalAttributes:u8; baseAddress:pu32; attributeFormats:u64; attributeMask:u16; attributePermutation:u64; 
              numBuffers:u8; bufferOffsets:array of u32; bufferPermutations:array of u64; bufferNumAttributes:array of u8);cdecl;external;

  procedure GPU_SetTextureEnable(units:GPU_TEXUNIT);cdecl;external;

  { GPU_TEXUNITx values can be ORed together to enable multiple texture units }
  procedure GPU_SetTexture(SetTextunit:GPU_TEXUNIT; data:pu32; width:u16; height:u16; param:u32;
              colorType:GPU_TEXCOLOR);cdecl;external;

  procedure GPU_SetTexEnv(id:u8; rgbSources:u16; alphaSources:u16; rgbOperands:u16; alphaOperands:u16; 
              rgbCombine:GPU_COMBINEFUNC; alphaCombine:GPU_COMBINEFUNC; constantColor:u32);cdecl;external;

  procedure GPU_DrawArray(primitive:GPU_Primitive_t; n:u32);cdecl;external;

  procedure GPU_DrawElements(primitive:GPU_Primitive_t; indexArray:pu32; n:u32);cdecl;external;

  procedure GPU_FinishDrawing;cdecl;external;
{$endif 3dsintf}

{$ifdef 3dsimpl}
  function GPU_TEXTURE_MAG_FILTER(v : longint) : longint;
    begin
//VERTEX_PACK := cuint32((x and $FFFF) or (y shl 16));
//#define VERTEX_PACK(x,y)     (u32)(((x) & 0xFFFF) | ((y) << 16))

//#define GPU_TEXTURE_MAG_FILTER(v) (((v)&0x1)<<1)
       GPU_TEXTURE_MAG_FILTER:= (V and $1) shl 1;
    end;

  function GPU_TEXTURE_MIN_FILTER(v : longint) : longint;
    begin
//#define GPU_TEXTURE_MIN_FILTER(v) (((v)&0x1)<<2)
       GPU_TEXTURE_MIN_FILTER:=(V and $1) shl 2;
    end;

  function GPU_TEXTURE_WRAP_S(v : longint) : longint;
    begin
//#define GPU_TEXTURE_WRAP_S(v) (((v)&0x3)<<8)
//       GPU_TEXTURE_WRAP_S:=(v(@($3))) shl 8;
       GPU_TEXTURE_WRAP_S:=(V and $3) shl 8;
    end;

  function GPU_TEXTURE_WRAP_T(v : longint) : longint;
    begin
//#define GPU_TEXTURE_WRAP_T(v) (((v)&0x3)<<12)
      // GPU_TEXTURE_WRAP_T:=(v(@($3))) shl 12;
       GPU_TEXTURE_WRAP_T:=(V and $3) shl 12;
    end;

  function GPU_ATTRIBFMT(i,n,f : longint) : longint;
    begin
    //#define GPU_ATTRIBFMT(i, n, f) (((((n)-1)<<2)|((f)&3))<<((i)*4))
    // GPU_ATTRIBFMT:=(((n(-(1))) shl 2) or (f(@(3)))) shl (i*4);
       GPU_ATTRIBFMT:=((n-1) shl 2) or ((f and 3) shl (i*4));
    end;

  function GPU_TEVSOURCES(a,b,c : longint) : longint;
    begin
       GPU_TEVSOURCES:=(a or (b shl 4)) or (c shl 8);
    end;
 
  function GPU_TEVOPERANDS(a,b,c : longint) : longint;
    begin
       GPU_TEVOPERANDS:=(a or (b shl 4)) or (c shl 8);
    end;

{$endif 3dsimpl}
