#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include <sys/stat.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    
    if(strcmp(argv[0], "rm")==0){
        if(strcmp(argv[1], "-v")==0){
            for(int i=2; i<argc; i++){
                char* fileName=argv[i];
                int ret=remove(fileName);
                if(ret==0){
                    printf("removed %s\n", fileName);
                }
                else{
                    printf("File couldn't be deleted\n");
                    return 1;
                }
            }
        }
        else if(strcmp(argv[1], "-d")==0){
            for(int i=2; i<argc; i++){
                char* dirName=argv[i];
                int ret=rmdir(dirName);
                if(ret!=0){
                    printf("Directory couldn't be removed\n");
                    return 1;
                }
            }
        }
        else if(argv[1][0]=='-'){
            printf("Wrong command\n");
        }
        else{
            for(int i=1; i<argc; i++){
                char* fileName=argv[i];
                int ret=remove(fileName);
                if(ret!=0){
                    printf("File couldn't be removed\n");
                    return 1;
                }
            }
        }
    }
    else{
        if(strcmp(argv[2], "-v")==0){
            for(int i=3; i<argc; i++){
                char* fileName=argv[i];
                int ret=remove(fileName);
                if(ret==0){
                    printf("removed %s\n", fileName);
                }
                else{
                    printf("File couldn't be deleted\n");
                    return 1;
                }
            }
        }
        else if(strcmp(argv[2], "-d")==0){
            for(int i=3; i<argc; i++){
                char* dirName=argv[i];
                int ret=rmdir(dirName);
                if(ret!=0){
                    printf("Directory couldn't be removed\n");
                    return 1;
                }
            }
        }
        else if(argv[2][0]=='-'){
            printf("Wrong command\n");
        }
        else{
            for(int i=2; i<argc; i++){
                char* fileName=argv[i];
                int ret=remove(fileName);
                if(ret!=0){
                    printf("File couldn't be removed\n");
                    return 1;
                }
            }
        }
    }
    

    
}