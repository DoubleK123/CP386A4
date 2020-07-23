#include <stdio.h>
#include <stdlib.h>
#include "assignment_4.h"
#include <sys/stat.h>
#include <string.h>

#define NUM_OF_CUST 5 //columns
#define NUM_OF_RES 4 //rows

int main(int argc, char* argv[]){
    
    int available[argc];
    int maximum[NUM_OF_RES][NUM_OF_CUST];
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

    // read file
    char* fileName = "sample4_in.txt";
    int result = read_file(fileName,maximum[0]);
    printf("read: %d\n\n",result);

    // testing perpose for maximum 2d array
    for(int k=0;k<NUM_OF_RES;k++){
        for(int b=0;b<NUM_OF_CUST;b++){
            printf("maximum : %d\n", maximum[k][b]);
        }
    }
    
    return 0;
}

int read_file(char* fileName, int* maximum){

    int n=20;
    int array[n];
    FILE* in = fopen(fileName,"r");
    if(!in){
        printf("error has occured\n");
        return -1;
    }else{
        size_t count;
        char* line = malloc(100);
        int index=0;
        while(getline(&line,&count,in)!=-1){
            char* token = NULL;
            token = strtok(line,",");
            while(token!=NULL){
                array[index]=atoi(token);
                // printf("array: %d\n",array[index]);
                token=strtok(NULL,",");
                index++;
            }
        }
        for(int i=0; i< NUM_OF_RES;i++){
            for(int j=0;j<NUM_OF_CUST;j++){
                *(maximum+i*NUM_OF_CUST+j)=array[i*NUM_OF_CUST+j];
            }
        }
        return 1;
    }

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