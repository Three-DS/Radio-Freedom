//size_t
  function linearAlloc(size:u32):pointer;cdecl;external;
  function linearMemAlign(size:u32; alignment:u32):pointer;cdecl;external;
  function linearRealloc(mem:pointer; size:u32):pointer;cdecl;external;
  procedure linearFree(mem:pointer);cdecl;external;
  function linearSpaceFree:u32;cdecl;external;
