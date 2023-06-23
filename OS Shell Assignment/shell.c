#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<pthread.h>

void echo(int argc, char* argv[]){
    if(argc<=1){
        printf("Please enter an argument");
    }    
    else{
        for(int i=1; i<argc; i++){
            printf("%s ", argv[i]);
        }
        printf("\n");
    }
}

void echo_n(int argc, char* argv[]){
    if(argc<=1){
        printf("Please enter an argument");
    }    
    else{
        for(int i=2; i<argc; i++){
            printf("%s ", argv[i]);
        }
    }
}

void echo_help(int argc, char* argv[]){
    if(argc==2 || argc==3){
        printf("1) echo:\n");
        printf("i) 'echo [args...]' - prints whatever is passed as an argument as it is and ends with a new line character.\n");
        printf("ii) 'echo -n [args...]' - prints whatever is passed as an argument as it is and doesn't end with a new line character.\n");
        printf("iii) 'echo --help' - prints the echo help page.\n");
    }
    else{
        printf("Wrong command\n");
    }
    
}

void cd(int argc, char* argv[]){
    if(argc==2){
        char* newDirec=argv[1];
        int ret=chdir(newDirec);
        if(ret!=0){
            printf("Directory couldn't be changed\n");
            return;
        }
    }
    else if(argc==3){
        char* newDirec=argv[1];
        int ret=chdir(newDirec);
        if(ret!=0){
            printf("Directory couldn't be changed\n");
            return;
        }
    }

}

void cd_home(int argc, char* argv[]){
    if(argc==1){
        int ret=chdir(getenv("HOME"));
        if(ret!=0){
            printf("Directory couldn't be changed");
            return;
        }
    }
    else if(argc==2){
        int ret=chdir(getenv("HOME"));
        if(ret!=0){
            printf("Directory couldn't be changed\n");
            return;
        }
    }
    else if(argc==3){
        int ret=chdir(getenv("HOME"));
        if(ret!=0){
            printf("Directory couldn't be changed\n");
            return;
        }
    }
}

void pwd(){
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
}

int read_input(char* line){
    int i=0;
    char ch;
    scanf("%c", &line[i]);
    while(line[i]!='\n'){
        i+=1;
        scanf("%c", &line[i]);
    }
    line[i]='\0';
    return i;
}

int parse_input(char* line, char* args[]){
    int i=0;
    int j=0;
    int k=0;
    int count=0;
    while(line[i]!='\0'){
        if(line[i]==' '){
            count+=1;
            args[j][k]='\0';
            j+=1;
            k=0;
            i+=1;
        }
        else{
            args[j][k]=line[i];
            k+=1;
            i+=1;
        }
    }
    count+=1;
    return count;

}

void* thread_execute(void* str1){
    char* command=malloc(sizeof(char)*256);
    char* string=malloc(sizeof(char)*256);
    char* str=(char*)str1;
    char* args[100];
    for(int i=0; i<100; i++){
        args[i]=malloc(sizeof(char)*512);
    }
    int j=0;
    char c=str[j];
    while(c!='&'){
        string[j]=c;
        j+=1;
        c=str[j];
    }
    string[j]='\0';
    int i=0;
    char ch=str[i];
    while(ch!=' '){
        command[i]=ch;
        i+=1;
        ch=str[i];
    }
    command[i]='\0';

    if(strcmp(command, "cat")==0){
        char newStr[1024];
        strcpy(newStr, string);
        char path[1024];
        strcpy(path, "/home/aayush/Desktop/Assignment/./cat ");
        strcat(path, newStr);
        system(path);
    }
    else if(strcmp(command, "rm")==0){
        char newStr[1024];
        strcpy(newStr, string);
        char path[1024];
        strcpy(path, "/home/aayush/Desktop/Assignment/./rm ");
        strcat(path, newStr);
        system(path);
    }
    else if(strcmp(command, "mkdir")==0){
        char newStr[1024];
        strcpy(newStr, string);
        char path[1024];
        strcpy(path, "/home/aayush/Desktop/Assignment/./mkdir ");
        strcat(path, newStr);
        system(path);
    }
    else if(strcmp(command, "ls")==0){
        char newStr[1024];
        strcpy(newStr, string);
        char path[1024];
        strcpy(path, "/home/aayush/Desktop/Assignment/./ls ");
        strcat(path, newStr);
        system(path);
    }
    else if(strcmp(command, "date")==0){
        char newStr[1024];
        strcpy(newStr, string);
        char path[1024];
        strcpy(path, "/home/aayush/Desktop/Assignment/./date ");
        strcat(path, newStr);
        system(path);
    }
    else if(strcmp(command, "echo")==0){
        int count=parse_input(string, args);
        if(strcmp(args[1], "-n")==0){
            echo_n(count, args);
        }
        else if(strcmp(args[1], "--help")==0){
            echo_help(count, args);
        }
        else if(args[1][0]=='-'){
            printf("Wrong command\n");
        }
        else{
            echo(count, args);
        }
    }
    else if(strcmp(command, "pwd")==0){
        int count=parse_input(string, args);
        if(count==2){
            pwd();
        }
        else if(strcmp(args[1], "-P")==0){
            pwd();
        }
        else if(strcmp(args[1], "-L")==0){
            pwd();
        }
        else if(args[1][0]=='-'){
            printf("Wrong command\n");
        }
    }
    else if(strcmp(command, "cd")==0){
        int count=parse_input(string, args);
        if(count==2){
            cd_home(count, args);
        }
        else if(strcmp(args[1], "~")==0){
            cd_home(count, args);
        }
        else{
            cd(count, args);
        }
    }
    else{
        printf("Not a valid command\n");
    }
    return NULL;

}

void thread_funct(int count, char* str){
    pthread_t thread;
    pthread_create(&thread, NULL, thread_execute, (void*)str);
    pthread_join(thread, NULL);
}

void execute_command(int count, char* args[]){
    if(strcmp(args[0], "echo")==0){
        if(strcmp(args[1], "-n")==0){
            echo_n(count, args);
            return;
        }
        else if(strcmp(args[1], "--help")==0){
            echo_help(count, args);
            return;
        }
        else if(args[1][0]=='-'){
            printf("Wrong command\n");
        }
        else{
            echo(count, args);
            return;
        }
    }
    else if(strcmp(args[0], "pwd")==0){
        if(count==1){
            pwd();
        }
        else if(strcmp(args[1], "-P")==0){
            pwd();
        }
        else if(strcmp(args[1], "-L")==0){
            pwd();
        }
        else if(args[1][0]=='-'){
            printf("Wrong command\n");
        }
        return;
    }
    else if(strcmp(args[0], "cat")==0){
        pid_t pid;
        pid=fork();
        if(pid<0){
            printf("Forking failed\n");
            return;
        }
        else if(pid==0){
            // char path[]="./cat";
            // char* argv[4];
            // if(count==2){
            //     char* argv[]={args[1], NULL, NULL, NULL};
            // }
            // else{
            //     char* argv[]={args[1], args[2], NULL, NULL};
            // }
            // printf("calling cat");
            execv("/home/aayush/Desktop/Assignment/./cat", args);
        }
        else{
            int wc=wait(NULL);
            return;
        }
    }
    else if(strcmp(args[0], "mkdir")==0){
        pid_t pid;
        pid=fork();
        if(pid<0){
            printf("Forking failed\n");
            return;
        }
        else if(pid==0){
            // printf("args[1]= %s", args[1]);
            // char path[]="./mkdir";
            execv("/home/aayush/Desktop/Assignment/./mkdir", args);
        }
        else{
            int wc=wait(NULL);
            return;
        }
    }

    else if(strcmp(args[0], "date")==0){
        pid_t pid;
        pid=fork();
        if(pid<0){
            printf("Forking failed\n");
            return;
        }
        else if(pid==0){
            // printf("args[1]= %s", args[1]);
            // char path[]="./mkdir";
            // char* argv[]={args[0], NULL, NULL, NULL};
            execv("/home/aayush/Desktop/Assignment/./date", args);
        }
        else{
            int wc=wait(NULL);
            return;
        }
    }

    else if(strcmp(args[0], "rm")==0){
        pid_t pid;
        pid=fork();
        if(pid<0){
            printf("Forking failed\n");
            return;
        }
        else if(pid==0){
            execv("/home/aayush/Desktop/Assignment/./rm", args);
        }
        else{
            int wc=wait(NULL);
            return;
        }
    }

    else if(strcmp(args[0], "ls")==0){
        pid_t pid;
        pid=fork();
        if(pid<0){
            printf("Forking failed\n");
            return;
        }
        else if(pid==0){
            printf("HELLOO");
            execv("/home/aayush/Desktop/Assignment/./ls", args);
        }
        else{
            int wc=wait(NULL);
            return;
        }
    }

    else if(strcmp(args[0], "cd")==0){
        if(count==1){
            cd_home(count, args);
        }
        else if(strcmp(args[1], "~")==0){
            cd_home(count, args);
        }
        else{
            cd(count, args);
        }
    }
    else{
        printf("Not a valid command\n");
    }

}

void infinite_loop(){
    while(1){
        char* line;
        line=malloc(sizeof(char)*512);
        char* args[100];
        for(int i=0; i<100; i++){
            args[i]=malloc(sizeof(char)*512);
        }
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("%s$ ", cwd);
        int ct=read_input(line);
        // printf("%s", line);
        if(strcmp(line, "exit")==0){
            return;
        }
        if(line[ct-2]=='&' && line[ct-1]=='t'){
            thread_funct(ct, line);
        }
        else{
            // int i=0;
            // while(line[i]!='\0'){
            //     printf("%c ", line[i]);
            //     i+=1;
            // }
            int count=parse_input(line, args);
            // printf("%s   %s", args[0], args[1]);
            // for(int i=0; i<count; i++){
            //     printf("%s ", args[i]);
            //     printf("\n");
            // }
            args[count]=NULL;
            execute_command(count, args);
        }
        
    }

}

int main(){
    infinite_loop();
}


