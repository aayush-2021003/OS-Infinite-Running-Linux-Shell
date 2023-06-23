#include<stdio.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char* argv[]){
    
    // printf("%d", argc);
    if(strcmp(argv[0], "mkdir")==0){
        if(strcmp(argv[1], "-v")==0){
            for(int i=2; i<argc; i++){
                int direc=mkdir(argv[i], 0777);
                if(direc!=0){
                    printf("Error occurred\n");
                    return 1;
                }
                else{
                    printf("mkdir: created directory %s\n", argv[i]);
                }
            }
        }
        else if(argv[1][0]=='-'){
            printf("Wrong command\n");
        }
        else{
            for(int i=1; i<argc; i++){
                int direc=mkdir(argv[i], 0777);
                if(direc!=0){
                    printf("Error occurred\n");
                    return 1;
                }
            }
        }
    }
    else{
        if(strcmp(argv[2], "-v")==0){
            for(int i=3; i<argc; i++){
                int direc=mkdir(argv[i], 0777);
                if(direc!=0){
                    printf("Error occurred\n");
                    return 1;
                }
                else{
                    printf("mkdir: created directory %s\n", argv[i]);
                }
            }
        }
        else if(argv[2][0]=='-'){
            printf("Wrong command\n");
        }
        else{
            for(int i=2; i<argc; i++){
                int direc=mkdir(argv[i], 0777);
                if(direc!=0){
                    printf("Error occurred\n");
                    return 1;
                }
            }
        }
    }
    
}