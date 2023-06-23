#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]){

    // printf("%s", argv[0]);
    // printf("%s", argv[0]);
    // printf("%d", argc);
    // printf("inside cat");
    // if(argc==2){
    if(strcmp(argv[0], "cat")==0){
        if(strcmp(argv[1], "-n")==0){
            int j=1;
            for(int i=2; i<argc; i++){
                FILE* fptr;
                fptr=fopen(argv[i], "r");
                if(fptr==NULL){
                    printf("Error: file couldn't open\n");
                    return 0;
                }
                char ch=fgetc(fptr);
                printf("%d ", j);
                while(ch!=EOF){
                    printf("%c", ch);
                    if(ch=='\n'){
                        j+=1;
                        ch=fgetc(fptr);
                        if(ch!=EOF){
                            printf("%d ", j);
                        }
                    }
                    else{
                        ch=fgetc(fptr);
                    }
                }
                fclose(fptr);
                // printf("\n");
            }
        }
        else if(strcmp(argv[1], "-e")==0){
            for(int i=2; i<argc; i++){
                FILE* fptr;
                fptr=fopen(argv[i], "r");
                if(fptr==NULL){
                    printf("Error: file couldn't open\n");
                    return 0;
                }
                char ch=fgetc(fptr);
                if(ch=='\n'){
                    printf("$");
                }
                while(ch!=EOF){
                    printf("%c", ch);
                    ch=fgetc(fptr);
                    if(ch=='\n'){
                        printf("$");
                    }
                }
                fclose(fptr);
                // printf("\n");
            }
        }
        else if(argv[1][0]=='-'){
            printf("Wrong command\n");
        }
        else{
            for(int i=1; i<argc; i++){
                FILE* fptr;
                fptr=fopen(argv[i], "r");
                if(fptr==NULL){
                    printf("Error: file couldn't open\n");
                    return 0;
                }
                char ch=fgetc(fptr);
                while(ch!=EOF){
                    printf("%c", ch);
                    ch=fgetc(fptr);
                }
                fclose(fptr);
                // printf("\n");
            }
        }
    }
    else{
        if(strcmp(argv[2], "-n")==0){
            int j=1;
            for(int i=3; i<argc; i++){
                FILE* fptr;
                fptr=fopen(argv[i], "r");
                if(fptr==NULL){
                    printf("Error: file couldn't open\n");
                    return 0;
                }
                char ch=fgetc(fptr);
                printf("%d ", j);
                while(ch!=EOF){
                    printf("%c", ch);
                    if(ch=='\n'){
                        j+=1;
                        ch=fgetc(fptr);
                        if(ch!=EOF){
                            printf("%d ", j);
                        }
                    }
                    else{
                        ch=fgetc(fptr);
                    }
                }
                fclose(fptr);
                // printf("\n");
            }
        }
        else if(strcmp(argv[2], "-e")==0){
            for(int i=3; i<argc; i++){
                FILE* fptr;
                fptr=fopen(argv[i], "r");
                if(fptr==NULL){
                    printf("Error: file couldn't open\n");
                    return 0;
                }
                char ch=fgetc(fptr);
                if(ch=='\n'){
                    printf("$");
                }
                while(ch!=EOF){
                    printf("%c", ch);
                    ch=fgetc(fptr);
                    if(ch=='\n'){
                        printf("$");
                    }
                }
                fclose(fptr);
                // printf("\n");
            }
        }
        else if(argv[2][0]=='-'){
            printf("Wrong command\n");
        }
        else{
            for(int i=2; i<argc; i++){
                FILE* fptr;
                fptr=fopen(argv[i], "r");
                if(fptr==NULL){
                    printf("Error: file couldn't open\n");
                    return 0;
                }
                char ch=fgetc(fptr);
                while(ch!=EOF){
                    printf("%c", ch);
                    ch=fgetc(fptr);
                }
                fclose(fptr);
                // printf("\n");
            }
        }
    }
    

}