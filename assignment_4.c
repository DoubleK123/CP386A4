#include <stdio.h>
#include <stdlib.h>
#include "assignment_4.h"

int main(int argc, char* argv[]){
    
    int available[argc];
    int i;
    if(argc>0){
        for(i=0;i<argc;i++){
            // printf("argv: %d\n",atoi(argv[i]));
            available[i]=atoi(argv[i]);
            // printf("available: %d\n", available[i]);
        }
    }else{
        printf("no arguments have been given check again\n");
    }

    char* fileName = "sample4_in.txt";
    int result = read_file(fileName);
    printf("read: %d\n",result);

    return 0;
}

int read_file(char* fileName){

    return 0;
}

void RQ(char* command){

}

void RL(char* command){

}

void run(){

}

int safetyAlgorithm(){

    return 0;
}