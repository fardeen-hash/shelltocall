# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/shm.h>
# include <string.h>
void main()
{
  void * sharedMemory;
  int id = shmget((key_t)1234, 1024, 0666|IPC_CREAT); // 0666- read and write permission.
  printf("Shared Memory Key is: %d\n",id);
  sharedMemory = shmat(id,NULL,0); // attaching the process to the shared memory segement.
  printf("Shared Memory Address: %p\n",sharedMemory);
  printf("Data read from shared Memory: %s\n",(char *)sharedMemory); // the void poointer is cast into a character pointer.
}
