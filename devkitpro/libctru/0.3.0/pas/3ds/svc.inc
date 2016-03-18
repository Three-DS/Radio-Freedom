  Type
  PMemInfo  = ^MemInfo;
  PPageInfo  = ^PageInfo;

     MemOp = (MEMOP_FREE := 1,
	      MEMOP_ALLOC := 3,
	      MEMOP_MAP := 4,
       	      MEMOP_UNMAP := 5,
	      MEMOP_PROT := 6,
	      MEMOP_FREE_LINEAR := $10001,
       	      MEMOP_ALLOC_LINEAR := $10003);

  {force 4-byte }

     MemPerm = (MEMPERM_READ := 1,
		MEMPERM_WRITE := 2,
       		MEMPERM_EXECUTE := 4,
		MEMPERM_MAX := $FFFFFFFF
       );

     MemInfo = record
          base_addr : u32;
          size : u32;
          perm : u32;
          state : u32;
       end;

     PageInfo = record
          flags : u32;
       end;

     ArbitrationType = (ARBITER_FREE := 0,
                        ARBITER_ACQUIRE := 1,
       			ARBITER_KERNEL2 := 2,
			ARBITER_ACQUIRE_TIMEOUT := 3,
       			ARBITER_KERNEL4 := 4);

  function getThreadCommandBuffer:pu32;cdecl;external;
  function svcControlMemory(addr_svcout:pu32; addr0:u32; addr1:u32; size:u32; op:MemOp;perm:MemPerm):s32;cdecl;external;
  function svcQueryMemory(info:pMemInfo; svcout:pPageInfo; addr:u32):s32;cdecl;external;
  procedure svcExitProcess;cdecl;external;
  function svcCreateThread(thread:pHandle; entrypoint:ThreadFunc; arg:u32; stack_top:pu32; thread_priority:s32; processor_id:s32):s32;cdecl;external;
  procedure svcExitThread;cdecl;external; 
  procedure svcSleepThread(ns:s64);cdecl;external;
  function svcCreateMutex(mutex:pHandle; initially_locked:bool):s32;cdecl;external;
  function svcReleaseMutex(handle:Handle):s32;cdecl;external;
  function svcCreateEvent(event:pHandle; reset_type:u8):s32;cdecl;external;
  function svcSignalEvent(handle:Handle):s32;cdecl;external;
  function svcClearEvent(handle:Handle):s32;cdecl;external;
  function svcCreateTimer(timer:pHandle; reset_type:u8):s32;cdecl;external;
  function svcSetTimer(timer:Handle; initial:s64; interval:s64):s32;cdecl;external;
  function svcCancelTimer(timer:Handle):s32;cdecl;external;
  function svcClearTimer(timer:Handle):s32;cdecl;external;
  function svcCreateMemoryBlock(memblock:pHandle; addr:u32; size:u32; my_perm:MemPerm; other_perm:MemPerm):s32;cdecl;external;
  function svcMapMemoryBlock(memblock:Handle; addr:u32; my_perm:MemPerm; other_perm:MemPerm):s32;cdecl;external;
  function svcUnmapMemoryBlock(memblock:Handle; addr:u32):s32;cdecl;external;
  function svcCreateAddressArbiter(arbiter:pHandle):s32;cdecl;external;
  function svcArbitrateAddress(arbiter:Handle; addr:u32; _type:ArbitrationType; value:s32; nanoseconds:s64):s32;cdecl;external;
  function svcWaitSynchronization(handle:Handle; nanoseconds:s64):s32;cdecl;external;
  function svcWaitSynchronizationN(svcout:ps32; handles:pHandle; handles_num:s32; wait_all:bool; nanoseconds:s64):s32;cdecl;external;
  function svcCloseHandle(handle:Handle):s32;cdecl;external;
  function svcDuplicateHandle(svcout:pHandle; original:Handle):s32;cdecl;external;
  function svcGetSystemTick:u64;cdecl;external;
  function svcGetSystemInfo(svcout:ps64; _type:u32; param:s32):s32;cdecl;external;
  function svcGetProcessInfo(svcout:ps64; process:Handle; _type:u32):s32;cdecl;external;
  function svcConnectToPort(out svcout:pu32; portName: PChar):s32;cdecl;external; //svcout: volatile ^Handle
  function svcSendSyncRequest(session:Handle):s32;cdecl;external;
  function svcGetProcessId(svcout:pu32; handle:Handle):s32;cdecl;external;
  function svcOutputDebugString(str:pchar; length:longint):s32;cdecl;external;

