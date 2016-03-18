  const
     POLLIN = $001;     
     POLLPRI = $002;     
     POLLOUT = $004;     
     POLLERR = $008;     
     POLLHUP = $010;     
     POLLNVAL = $020;     
     POLLRDNORM = $040;     
     POLLRDBAND = $080;     
     POLLWRNORM = $100;     
     POLLWRBAND = $200;     

  type

     nfds_t = u32;
     pollfd = record
          fd : longint;
          events : longint;
          revents : longint;
       end;
     Ppollfd  = ^pollfd;

  function poll(fds:ppollfd; nfsd:nfds_t; timeout:longint):longint;cdecl;external;
