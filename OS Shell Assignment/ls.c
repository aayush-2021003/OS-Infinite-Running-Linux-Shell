#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    // printf("%d", argc);
    if(strcmp(argv[0], "ls")==0){
        if(argc==1){
            DIR* directory=opendir(".");
            if(directory!=NULL){
                struct dirent* file=readdir(directory);
                while(1){
                    if(file==NULL){
                        break;
                    }
                    else{
                        if(file->d_name[0]!='.'){
                            printf("%s\t", file->d_name);
                            file=readdir(directory);
                        }
                        else{
                            file=readdir(directory);
                        }
                    }
                }
                printf("\n");
            }
            else{
                printf("Directory doesn't exist");
            }
            closedir(directory);
        }
        else if(strcmp(argv[1], "-1")==0 && argc==2){
            DIR* directory=opendir(".");
            if(directory!=NULL){
                struct dirent* file=readdir(directory);
                while(1){
                    if(file==NULL){
                        break;
                    }
                    else{
                        if(file->d_name[0]!='.'){
                            printf("%s\n", file->d_name);
                            file=readdir(directory);
                        }
                        else{
                            file=readdir(directory);
                        }
                    }
                }
                // printf("\n");
            }
            else{
                printf("Error: Directory doesn't exist");
            }
            closedir(directory);
        }
        else if(strcmp(argv[1], "-1")==0){
            char* dirName=argv[2];
            DIR* directory=opendir(dirName);
            if(directory!=NULL){
                struct dirent* file=readdir(directory);
                while(1){
                    if(file==NULL){
                        break;
                    }
                    else{
                        if(file->d_name[0]!='.'){
                            printf("%s\n", file->d_name);
                            file=readdir(directory);
                        }
                        else{
                            file=readdir(directory);
                        }
                    }
                }
                printf("\n");

            }
            else{
                printf("Error: Directory doesn't exist");
            }
            closedir(directory);
        }
        else if(strcmp(argv[1], "-a")==0 && argc==2){
            DIR* directory=opendir(".");
            if(directory!=NULL){
                struct dirent* file=readdir(directory);
                while(1){
                    if(file==NULL){
                        break;
                    }
                    else{
                        printf("%s\t", file->d_name);
                        file=readdir(directory);
                    }
                }
                printf("\n");
            }
            else{
                printf("Directory doesn't exist");
            }
            closedir(directory);

        }
        else if(strcmp(argv[1], "-a")==0){
            char* dirName=argv[2];
            DIR* directory=opendir(dirName);
            if(directory!=NULL){
                struct dirent* file=readdir(directory);
                while(1){
                    if(file==NULL){
                        break;
                    }
                    else{
                        printf("%s\t", file->d_name);
                        file=readdir(directory);
                    }
                }
                printf("\n");

            }
            else{
                printf("Error: Directory doesn't exist");
            }
            closedir(directory);
        }
        else if(argv[1][0]=='-'){
            printf("Wrong command\n");
        }
        else{
            char* dirName=argv[1];
            DIR* directory=opendir(dirName);
            if(directory!=NULL){
                struct dirent* file=readdir(directory);
                while(1){
                    if(file==NULL){
                        break;
                    }
                    else{
                        if(file->d_name[0]!='.'){
                            printf("%s\t", file->d_name);
                            file=readdir(directory);
                        }
                        else{
                            file=readdir(directory);
                        }
                    }
                }
                printf("\n");

            }
            else{
                printf("Error: Directory doesn't exist");
            }
            closedir(directory);
        }
    }
    else{
        if(argc==2){
            DIR* directory=opendir(".");
            if(directory!=NULL){
                struct dirent* file=readdir(directory);
                while(1){
                    if(file==NULL){
                        break;
                    }
                    else{
                        if(file->d_name[0]!='.'){
                            printf("%s\t", file->d_name);
                            file=readdir(directory);
                        }
                        else{
                            file=readdir(directory);
                        }
                    }
                }
                printf("\n");
            }
            else{
                printf("Directory doesn't exist");
            }
            closedir(directory);
        }
        else if(strcmp(argv[2], "-1")==0 && argc==3){
            DIR* directory=opendir(".");
            if(directory!=NULL){
                struct dirent* file=readdir(directory);
                while(1){
                    if(file==NULL){
                        break;
                    }
                    else{
                        if(file->d_name[0]!='.'){
                            printf("%s\n", file->d_name);
                            file=readdir(directory);
                        }
                        else{
                            file=readdir(directory);
                        }
                    }
                }
                // printf("\n");
            }
            else{
                printf("Error: Directory doesn't exist");
            }
            closedir(directory);
        }
        else if(strcmp(argv[2], "-1")==0){
            char* dirName=argv[3];
            DIR* directory=opendir(dirName);
            if(directory!=NULL){
                struct dirent* file=readdir(directory);
                while(1){
                    if(file==NULL){
                        break;
                    }
                    else{
                        if(file->d_name[0]!='.'){
                            printf("%s\n", file->d_name);
                            file=readdir(directory);
                        }
                        else{
                            file=readdir(directory);
                        }
                    }
                }
                printf("\n");

            }
            else{
                printf("Error: Directory doesn't exist");
            }
            closedir(directory);
        }
        else if(strcmp(argv[2], "-a")==0 && argc==3){
            DIR* directory=opendir(".");
            if(directory!=NULL){
                struct dirent* file=readdir(directory);
                while(1){
                    if(file==NULL){
                        break;
                    }
                    else{
                        printf("%s\t", file->d_name);
                        file=readdir(directory);
                    }
                }
                printf("\n");
            }
            else{
                printf("Directory doesn't exist");
            }
            closedir(directory);

        }
        else if(strcmp(argv[2], "-a")==0){
            char* dirName=argv[3];
            DIR* directory=opendir(dirName);
            if(directory!=NULL){
                struct dirent* file=readdir(directory);
                while(1){
                    if(file==NULL){
                        break;
                    }
                    else{
                        printf("%s\t", file->d_name);
                        file=readdir(directory);
                    }
                }
                printf("\n");

            }
            else{
                printf("Error: Directory doesn't exist");
            }
            closedir(directory);
        }
        else if(argv[2][0]=='-'){
            printf("Wrong command\n");
        }
        else{
            char* dirName=argv[2];
            DIR* directory=opendir(dirName);
            if(directory!=NULL){
                struct dirent* file=readdir(directory);
                while(1){
                    if(file==NULL){
                        break;
                    }
                    else{
                        if(file->d_name[0]!='.'){
                            printf("%s\t", file->d_name);
                            file=readdir(directory);
                        }
                        else{
                            file=readdir(directory);
                        }
                    }
                }
                printf("\n");

            }
            else{
                printf("Error: Directory doesn't exist");
            }
            closedir(directory);
        }
    }
    
    

}