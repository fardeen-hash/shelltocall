# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/shm.h>
# include <string.h>
void main()
{
  void * sharedMemory; // void pointer called sharedMemory (pointer without any data type. It can be casted to any data type.)
  int id;
  char values[50];
  id = shmget((key_t)1234,1024,0666|IPC_CREAT); // key_t is a datatype, creates shared Memory segment.
  printf("Shared Memory Key: %d\n",id);
  sharedMemory = shmat(id,NULL,0); // attaching the process to the shared maemory segement.
  printf("Process attached at memory Address: %p\n",sharedMemory); // print's the shared memory address.
  printf("Enter data to write to the Shared Memory\n");
  fgets(values,50,stdin); //gets(values);
  strcpy(sharedMemory, values); // writing data to the shared memory area.
  printf("Data Written: %s\n",(char *)sharedMemory); // the void poointer is cast into a character pointer.
}
