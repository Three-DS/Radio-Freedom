{$ifdef 3dsintf}


//  function rbtree_item(ptr,_type,member : longint) : ptype;

  type
//  forward
     rbtree = rbtree_t;
     rbtree_node = rbtree_node_t;

  rbtree_node_destructor_t = procedure (Node:prbtree_node_t);cdecl;
  rbtree_node_comparator_t = function (lhs:prbtree_node_t; rhs:prbtree_node_t):longint;cdecl;

     rbtree = record
          root : ^rbtree_node_t;
          comparator : rbtree_node_comparator_t;
          size : u32;// size_t;
       end;
     Prbtree_t  = ^rbtree;


     rbtree_node = record
          parent_color : pcuint;// cdecl;
          child : array[0..1] of ^rbtree_node_t;
       end;
     Prbtree_node_t  = ^rbtree_node;

  procedure rbtree_init(tree:prbtree_t; comparator:rbtree_node_comparator_t);cdecl;external;
  function rbtree_empty(tree:prbtree_t):longint;cdecl;external;
  function rbtree_size(tree:prbtree_t):size_t;cdecl;external;
  function rbtree_insert(tree: ^rbtree_t; node: ^rbtree_node_t):^rbtree_node_t;cdecl;external;
  procedure rbtree_insert_multi(tree:prbtree_t; node:prbtree_node_t);cdecl;external;
  function rbtree_find(tree:prbtree_t; node:prbtree_node_t):^rbtree_node_t;cdecl;external;
  function rbtree_min(tree:prbtree_t):^rbtree_node_t;cdecl;external;
  function rbtree_max(tree:prbtree_t):^rbtree_node_t;cdecl;external;
  function rbtree_node_next(node:prbtree_node_t):^rbtree_node_t;cdecl;external;
  function rbtree_node_prev(node:prbtree_node_t):^rbtree_node_t;cdecl;external;
  function rbtree_remove(tree:prbtree_t; node:prbtree_node_t; destructor:rbtree_node_destructor_t):^rbtree_node_t;cdecl;external;
  procedure rbtree_clear(tree:prbtree_t; destructor:rbtree_node_destructor_t);cdecl;external;
{$endif 3dsintf}

{$ifdef 3dsimpl}
  function rbtree_item(ptr,_type,member : longint) : ptype;
    begin
       rbtree_item:=ptype((pchar(ptr))-(offsetof(_type,member)));
    end;
{$endif 3dsimpl}
