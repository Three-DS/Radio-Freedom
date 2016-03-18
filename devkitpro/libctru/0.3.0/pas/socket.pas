//Ghetto-sphere breach && cleanse the brains of war? 
unit socket;

interface

{$IFDEF FPC}
{$PACKRECORDS C}
{$ENDIF}

//in.h
  const
     INADDR_ANY = $00000000;     
     INADDR_BROADCAST = $FFFFFFFF;     
     INADDR_NONE = $FFFFFFFF;     
     INET_ADDRSTRLEN = 16;     

  {#define IPPROTO_IP	??? }
  {#define IPPROTO_TCP	??? }
  {#define IPPROTO_UDP	??? }
  {#define SOL_TCP	??? }
  {#define TCP_NODELAY	??? }
  {#define TCP_NODELAY	??? }

  type

     in_port_t = uint16_t;
     in_addr_t = uint32_t;

     in_addr = record
          s_addr : in_addr_t;
       end;
     pin_addr: ^in_addr;

     sockaddr_in = record
          sin_family : sa_family_t;
          sin_port : in_port_t;
          sin_addr : in_addr;
          sin_zero : array[0..7] of byte;
       end;

  const
     SOL_SOCKET = $FFFF;     
     PF_UNSPEC = 0;     
     PF_INET = 2;     
     PF_INET6 = 10;     
     AF_UNSPEC = PF_UNSPEC;     
     AF_INET = PF_INET;     
     AF_INET6 = PF_INET6;     
     SOCK_STREAM = 1;     
     SOCK_DGRAM = 2;     
     MSG_CTRUNC = $01000000;     
     MSG_DONTROUTE = $02000000;     
     MSG_EOR = $04000000;     
     MSG_OOB = $08000000;     
     MSG_PEEK = $10000000;     
     MSG_TRUNC = $20000000;     
     MSG_WAITALL = $40000000;     
     SHUT_RD = 0;     
     SHUT_WR = 1;     
     SHUT_RDWR = 2;     
     SO_DEBUG = $0001;     
     SO_ACCEPTCONN = $0002;     
     SO_REUSEADDR = $0004;     
     SO_KEEPALIVE = $0008;     
     SO_DONTROUTE = $0010;     
     SO_BROADCAST = $0020;     
     SO_USELOOPBACK = $0040;     
     SO_LINGER = $0080;     
     SO_OOBINLINE = $0100;     
     SO_REUSEPORT = $0200;     
     SO_SNDBUF = $1001;     
     SO_RCVBUF = $1002;     
     SO_SNDLOWAT = $1003;     
     SO_RCVLOWAT = $1004;     
     SO_SNDTIMEO = $1005;     
     SO_RCVTIMEO = $1006;     
     SO_ERROR = $1007;     
     SO_TYPE = $1008;     

  type

     socklen_t = uint32_t;
     Psocklen_t  = ^socklen_t;

     sa_family_t = uint16_t;

     sockaddr = record
          sa_family : sa_family_t;
          sa_data : array of char;
       end;
     Psockaddr  = ^sockaddr;

     sockaddr_storage = record
          ss_family : sa_family_t;
          __ss_padding : array[0..13] of char;
       end;

     linger = record
          l_onoff : longint;
          l_linger : longint;
       end;

//netdb.h
  const
     HOST_NOT_FOUND = 1;     
     NO_DATA = 2;     
     NO_ADDRESS = NO_DATA;     
     NO_RECOVERY = 3;     
     TRY_AGAIN = 4;     

  type
       hostent = record
          h_name : ^char;
          h_aliases : ^^char;
          h_addrtype : longint;
          h_length : longint;
          h_addr_list : ^^char;
       end;
       phostent = ^hostent;


  function h_errno: longint;cdecl;external;

  function gethostbyname(name: PChar):phostent;
  function accept(sockfd:longint; addr:psockaddr; addrlen:psocklen_t):longint;cdecl;external;
  function bind(sockfd:longint; addr:psockaddr; addrlen:socklen_t):longint;cdecl;external;
  function closesocket(sockfd:longint):longint;cdecl;external;
  function connect(sockfd:longint; addr:psockaddr; addrlen:socklen_t):longint;cdecl;external;
  function getpeername(sockfd:longint; addr:psockaddr; addrlen:psocklen_t):longint;cdecl;external;
  function getsockname(sockfd:longint; addr:psockaddr; addrlen:psocklen_t):longint;cdecl;external;
  function getsockopt(sockfd:longint; level:longint; optname:longint; optval:pointer; optlen:psocklen_t):longint;cdecl;external;
  function listen(sockfd:longint; backlog:longint):longint;cdecl;external;
  function recv(sockfd:longint; buf:pointer; len:size_t; flags:longint):ssize_t;cdecl;external;
  function recvfrom(sockfd:longint; buf:pointer; len:size_t; flags:longint; src_addr:psockaddr; addrlen:psocklen_t):ssize_t;cdecl;external;
  function send(sockfd:longint; buf:pointer; len:size_t; flags:longint):ssize_t;cdecl;external;
  function sendto(sockfd:longint; buf:pointer; len:size_t; flags:longint; dest_addr:psockaddr; addrlen:socklen_t):ssize_t;cdecl;external;
  function setsockopt(sockfd:longint; level:longint; optname:longint; optval:pointer; optlen:socklen_t):longint;cdecl;external;
  function shutdown(sockfd:longint; how:longint):longint;cdecl;external;
  function socket(domain:longint; _type:longint; protocol:longint):longint;cdecl;external;
  function sockatmark(sockfd:longint):longint;cdecl;external;

//select.h
  Type
  Pfd_set  = ^fd_set;
  Ptimeval  = ^timeval;
  function select(nfds:longint; readfds:pfd_set; writefds:pfd_set; exceptfds:pfd_set; timeout:ptimeval):longint;cdecl;external;

//ioctl.h
  const
     FIONBIO = 1;
  function ioctl(fd:longint; request:longint; args:array of const):longint;cdecl;external;
  function ioctl(fd:longint; request:longint):longint;cdecl;external;

//inet.h
  function htonl(hostlong: uint32_t): uint32_t; inline;
  function htons(hostshort: uint16_t): uint16_t; inline; 
  function ntohl(netlong: uint32_t): uint32_t; inline;
  function ntohs(netshort: uint16_t): uint16_t; inline;

function inet_addr(cp:pchar):in_addr_t;cdecl;external;
function inet_aton(cp:pchar; inp:pin_addr):longint;cdecl;external;
function inet_ntoa(in:in_addr):pchar;cdecl;external;

implementation


Type array_word = array[0..1] of byte;
Type array_dword = array[0..3] of byte;

function wSwap(value:array_word):array_word;
begin
  result[0]:=value[1];
  result[1]:=value[0];
end;

function dSwap(value: array_dword):array_dword;
begin
  result[0]:=value[3];
  result[1]:=value[2];
  result[2]:=value[1];
  result[3]:=value[0];
end;

//or else we'll resort too 
function htonl(hostlong:uint32_t):uint32_t; inline;
begin
     htonl:=SwapEndian(hostlong);
end;

function htons(hostshort:uint16_t):uint16_t; inline;
begin
     htonl:=SwapEndian(hostlong);
end;

function ntohl(netlong:uint32_t):uint32_t; inline;
begin
     htonl:=SwapEndian(hostlong);
end;

function ntohs(netshort:uint16_t):uint16_t; inline;
begin
     htonl:=SwapEndian(hostlong);
end;

end.
//again what are the command codes, too abandon stomack crapped-in?  
