//writer.c
#include<sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
key_t key=ftok("a.txt",'A');
int shmid= shmget( key ,1024,0777|IPC_CREAT);
char *str= (char*) shmat(shmid,(void*)0,0);
printf("write data into file");
gets(str);
printf("Data written in memory: %s\n",str);
shmdt(str);
system("ipcs -m");
return 0;
}
//reader.c
#include<sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
key_t key=ftok("a.txt",'A');
int shmid= shmget( key ,1024,0777|IPC_CREAT);
char *str= (char*) shmat(shmid,(void*)0,0);
printf("Data read from memory: %s\n",str);
system("ipcs -m");
shmdt(str);
shmctl(shmid,IPC_RMID,NULL);
return 0;
}
//output
usr/bin/ld: /tmp/cc2Y4KfH.o: in function `main':
student@student:~$ ./a.out
write data into file this is system change
Data written in memory: this is system change
------ Shared Memory Segments --------
key shmid owner perms bytes nattch status
0x00000000 2 student 600 524288 2 dest
0x00000000 24 student 600 524288 2 dest
0x410526c5 25 student 777 1024 0
student@student:~$ ipcs -m
------ Shared Memory Segments --------
key shmid owner perms bytes nattch status
0x00000000 2 student 600 524288 2 dest
0x00000000 24 student 600 524288 2 dest
student@student:~$ gcc reader.c -o b.out
student@student:~$ ./b.out
Data read from memory: This is writer file
student@student:~$ gcc reader.c -o b.out
student@student:~$ ./b.out
Data read from memory: this is another data
student@student:~$ gcc reader.c -o b.out
student@student:~$ gcc reader.c -o b.out
student@student:~$ ./b.out
Data read from memory: this is system change
------ Shared Memory Segments --------
key shmid owner perms bytes nattch status
0x00000000 2 student 600 524288 2 dest
0x00000000 24 student 600 524288 2 dest
0x410526c5 25 student 777 1024 1