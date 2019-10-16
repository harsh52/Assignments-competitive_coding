     				/*************  Read Lock Setter  *************/
#include <sys/types.h>   
#include <unistd.h>      
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
int main()
{
  struct flock lock, savelock;
  int fd;
  printf("PID:%d",getpid());
  fd = open("testfile.dat", O_RDONLY);
  lock.l_type = F_RDLCK;
  lock.l_start = 0;
  lock.l_whence = SEEK_SET;
  lock.l_len = 50;
  savelock = lock;
  fcntl(fd, F_GETLK, &lock);
  if (lock.l_type == F_WRLCK)
  {
      printf("File is write-locked by process %ld.\n", lock.l_pid);
      exit(1);
  }
  fcntl(fd, F_SETLK, &savelock);
  pause();
}
