{$ifdef 3dsintf}
  {! @defgroup fs_open_flags FS Open Flags
   *
   *  @sa FSUSER_OpenFile
   *  @sa FSUSER_OpenFileDirectly
   *
   *  @
    }
  {! Open file for read.  }

  const
     FS_OPEN_READ = 1 shl 0;     
  {! Open file for write.  }
     FS_OPEN_WRITE = 1 shl 1;     
  {! Create file if it doesn't exist.  }
     FS_OPEN_CREATE = 1 shl 2;     
  { @  }
  {! @defgroup fs_create_attributes FS Create Attributes
   *
   *  @sa FSUSER_OpenFile
   *  @sa FSUSER_OpenFileDirectly
   *
   *  @
    }
  {! No attributes.  }
     FS_ATTRIBUTE_NONE = $00000000;     
  {! Create with read-only attribute.  }
     FS_ATTRIBUTE_READONLY = $00000001;     
  {! Create with archive attribute.  }
     FS_ATTRIBUTE_ARCHIVE = $00000100;     
  {! Create with hidden attribute.  }
     FS_ATTRIBUTE_HIDDEN = $00010000;     
  {! Create with directory attribute.  }
     FS_ATTRIBUTE_DIRECTORY = $01000000;     
  {! @  }
  {! @defgroup fs_write_flush_flags FS Flush Flags
   *
   *  @sa FSFILE_Write
   *
   *  @
    }
  {! Don't flush  }
     FS_WRITE_NOFLUSH = $00000000;     
  {! Flush  }
     FS_WRITE_FLUSH = $00010001;     
  { @  }
  {! FS path type  }
  {!< Specifies an invalid path. }
  {!< Specifies an empty path. }
  {!< Specifies a binary path, which is non-text based. }
  {!< Specifies a text based path with a 8-bit byte per character. }
  {!< Specifies a text based path with a 16-bit short per character. }

  type

     FS_pathType = (PATH_INVALID := 0,PATH_EMPTY := 1,
       PATH_BINARY := 2,PATH_CHAR := 3,PATH_WCHAR := 4
       );
  {! FS archive ids  }

     FS_archiveIds = (ARCH_ROMFS := $3,ARCH_SAVEDATA := $4,
       ARCH_EXTDATA := $6,ARCH_SHARED_EXTDATA := $7,
       ARCH_SYSTEM_SAVEDATA := $8,ARCH_SDMC := $9,
       ARCH_SDMC_WRITE_ONLY := $A,ARCH_BOSS_EXTDATA := $12345678,
       ARCH_CARD_SPIFS := $12345679,ARCH_NAND_RW := $1234567D,
       ARCH_NAND_RO := $1234567E,ARCH_NAND_RO_WRITE_ACCESS := $1234567F
       );
  {! FS path  }
  {!< FS path type. }
  {!< FS path size. }
(* Const before type ignored *)
  {!< Pointer to FS path data. }

     FS_path = record
          _type : FS_pathType;
          size : u32;
          data : ^u8;
       end;
  {! FS archive  }
  {!< Archive ID. }
  {!< FS path. }
  {!< High word of handle. }
  {!< Low word of handle. }

     FS_archive = record
          id : u32;
          lowPath : FS_path;
          handleLow : Handle;
          handleHigh : Handle;
       end;
      pFS_archive= ^FS_archive;
  {! Directory entry  }
  { 0x00 }
  {!< UTF-16 encoded name }
  { 0x20C }
  {!< 8.3 file name }
  { 0x215 }
  {!< ??? }
  { 0x216 }
  {!< 8.3 file extension (set to spaces for directories) }
  { 0x21A }
  {!< ??? }
  { 0x21B }
  {!< ??? }
  { 0x21C }
  {!< directory bit }
  { 0x21D }
  {!< hidden bit }
  { 0x21E }
  {!< archive bit }
  { 0x21F }
  {!< read-only bit }
  { 0x220 }
  {!< file size }

     FS_dirent = record
          name : array[0..261] of u16;
          shortName : array[0..8] of u8;
          unknown1 : u8;
          shortExt : array[0..3] of u8;
          unknown2 : u8;
          unknown3 : u8;
          isDirectory : u8;
          isHidden : u8;
          isArchive : u8;
          isReadOnly : u8;
          fileSize : u64;
       end;
       pFS_dirent = ^FS_dirent;
  {! Create an FS_path from a type and data pointer.
   *
   *  @param[in] type Path type.
   *  @param[in] path Pointer to path data.
   *
   *  @returns FS_path
   *
   *  @sa FS_pathType
    }

//    function FS_makePath(tpath:FS_pathType; path:PChar):FS_path;inline;
    function fsExit:s32;cdecl;external;
    function FSUSER_Initialize(handle:pHandle):s32;cdecl;external;
    function FSUSER_OpenArchive(handle:pHandle; archive:pFS_archive):s32;cdecl;external;
    function FSUSER_OpenDirectory(handle:pHandle; Dirout:pHandle; archive:FS_archive; dirLowPath:FS_path):s32;cdecl;external;
    function FSUSER_OpenFile(handle:pHandle; Fileout:pHandle; archive:FS_archive; fileLowPath:FS_path; openflags:u32; attributes:u32):s32;cdecl;external;
    function FSUSER_OpenFileDirectly(handle:pHandle; Dirout:pHandle; archive:FS_archive; fileLowPath:FS_path; openflags:u32; attributes:u32):s32;cdecl;external;
    function FSUSER_CloseArchive(handle:pHandle; archive:pFS_archive):s32;cdecl;external;
    function FSUSER_CreateDirectory(handle:pHandle; archive:FS_archive; dirLowPath:FS_path):s32;cdecl;external;
    function FSUSER_DeleteFile(handle:pHandle; archive:FS_archive; fileLowPath:FS_path):s32;cdecl;external;
    function FSUSER_DeleteDirectory(handle:pHandle; archive:FS_archive; dirLowPath:FS_path):s32;cdecl;external;
    function FSUSER_GetSdmcArchiveResource(handle:pHandle; sectorSize:pu32; clusterSize:pu32; numClusters:pu32; freeClusters:pu32):s32;cdecl;external;
    function FSUSER_IsSdmcDetected(handle:pHandle; detected:pu32):s32;cdecl;external;
    function FSUSER_IsSdmcWritable(handle:pHandle; writable:pu32):s32;cdecl;external;
    function FSFILE_Close(handle:Handle):s32;cdecl;external;
    function FSFILE_Read(handle:Handle; bytesRead:pu32; offset:u64; buffer:pointer; size:u32):s32;cdecl;external;
    function FSFILE_Write(handle:Handle; bytesWritten:pu32; offset:u64; buffer:pointer; size:u32; flushFlags:u32):s32;cdecl;external;
    function FSFILE_GetSize(handle:Handle; size:pu64):s32;cdecl;external;
    function FSFILE_SetSize(handle:Handle; size:u64):s32;cdecl;external;
    function FSFILE_GetAttributes(handle:Handle; attributes:pu32):s32;cdecl;external;
    function FSFILE_SetAttributes(handle:Handle; attributes:u32):s32;cdecl;external;
    function FSFILE_Flush(handle:Handle):s32;cdecl;external;
    function FSDIR_Read(handle:Handle; entriesRead:pu32; entrycount:u32; buffer:pFS_dirent):s32;cdecl;external;
    function FSDIR_Close(handle:Handle):s32;cdecl;external;
{$endif 3dsintf}

{$ifdef 3dsimpl}
  function FS_makePath(tpath:FS_pathType; path:PChar):FS_path;inline;
    begin
       FS_makePath := tpath; //(FS_path){tpath, strlen(path)+1, (const u8*)path 
    end;
{$endif 3dsimpl}
