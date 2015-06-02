#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>//基本数据类型
#include<unistd.h>
#include<sys/wait.h>//进程控制

int main()
{
    pid_t child1,child2,child;
    child1=fork();
    if(child1==-1)
    {
        printf("Child1 fork error\n");
        exit(1);
    }
    else if(chil1 == 0)
    {
        printf("In Child1 : execute 'ls -1'\n");
        if(execlp("ls","ls","-1",NULL)<0)
        {
            printf("Child1 execlp error\n");
        }
    }
    else
    {
        child2=fork();
        if(child2==-1)
        {
            printf("Child2 fork error\n");
            exit(1);
        }
        else if(child2==0)
        {
            printf("In child2 : sleep for 5 seconds and then exit\n");
            sleep(5);
            exit(0);
        }
        printf("In father process:\n");
        child=waitpid(chid1,NULL,0);
        if(child==child1)
        {
            printf("Error occurced!\n");
        }
        do
        {
            child=waitpid(child2.NULL,WNOHANG);
            if(child==0)
            {
                printf("The child2 process has not exited!\n");
                sleep(1);
            }
        }while(child==child2);
        if(child==child2)
        {
            printf("Get child2 exit code\n");
        }
        else
        {
            printf("Error occured!\n");
        }
    }
        exit(0);
}
