#include<stdio.h>
#include<time.h>
#include<string.h>

int main(int argc, char* argv[]){

    if(strcmp(argv[0], "date")==0){
        if(argc==1){
            time_t seconds;
            time(&seconds);
            printf("%s", ctime(&seconds));
        }
        else if(strcmp(argv[1], "-u")==0){
            time_t seconds;
            time(&seconds);
            struct tm* utc=gmtime(&seconds);
            printf("%d/%d/%d %d:%d:%d\n", utc->tm_mday, utc->tm_mon, utc->tm_year, utc->tm_hour, utc->tm_min, utc->tm_sec);
        }
        else if(argv[1][0]=='-'){
            printf("Wrong command\n");
        }
    }
    else{
        if(argc==2){
            time_t seconds;
            time(&seconds);
            printf("%s", ctime(&seconds));
        }
        else if(strcmp(argv[2], "-u")==0){
            time_t seconds;
            time(&seconds);
            struct tm* utc=gmtime(&seconds);
            printf("%d/%d/%d %d:%d:%d\n", utc->tm_mday, utc->tm_mon, utc->tm_year, utc->tm_hour, utc->tm_min, utc->tm_sec);
        }
        else if("Wrong command\n");
    }
    
}