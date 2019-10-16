#include <sys/types.h>   /***********  Write Lock Setter  *******/
#include <unistd.h>      
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
int main()
{
  int fd;
  struct flock lock, savelock;
  printf("PID:%d",getpid());
  fd = open("testfile.dat", O_RDWR);
  lock.l_type    = F_WRLCK;   /* Test for any lock on any part of file. */
  lock.l_start   = 0;
  lock.l_whence  = SEEK_SET;
  lock.l_len     = 0;        
  savelock = lock;
  fcntl(fd, F_GETLK, &lock);  /* Overwrites lock structure with preventors. */
  if (lock.l_type == F_WRLCK)
  {
     printf("Process %ld has a write lock already!\n", lock.l_pid);
     exit(1);
  }
  else if (lock.l_type == F_RDLCK)
  {
     printf("Process %ld has a read lock already!\n", lock.l_pid);
     exit(1);
  }
  else
     fcntl(fd, F_SETLK, &savelock);
  pause();
}
