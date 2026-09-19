#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
pid_t pid;
pid=fork();
if(pid==0){
printf("Child Running\n");
}
else{

wait(NULL);
printf("Parent Running after Child\n");
}
return 0;
}
