#include <stdio.h>
#include <stdlib.h>
#include "assignment_4.h"
#include <sys/stat.h>
#include <string.h>

#define NUM_OF_CUST 5 //columns
#define NUM_OF_RES 4 //rows

int available[4];
int maximum[NUM_OF_RES][NUM_OF_CUST];
int allocation[NUM_OF_RES][NUM_OF_CUST];
int need[NUM_OF_RES];
int request[NUM_OF_RES];
int release[NUM_OF_RES];


int main(int argc, char* argv[]){
    
    
    int i;
    int customer_number;
    int command[4], a,b,c,d;
    if(argc>0){
        int index=0;
        for(i=1;i<argc;i++){
            // printf("argv: %d\n",atoi(argv[i]));
            available[index]=atoi(argv[i]);
            index++;
            // printf("available: %d\n", available[i]);
        }
    }else{
        printf("no arguments have been given check again\n");
    }

    // for(int i=0;i <4;i++){
    //     printf("available: %d\n", available[i]);
    // }

    // read file
    char* fileName = "sample4_in.txt";
    int result = read_file(fileName,maximum[0]);
    printf("read: %d\n\n",result);

    printf("enter command: ");
    scanf("%s %d %d %d %d %d", command, &customer_number, &a,&b,&c,&d);
    
    if(command=="RQ"){
        request[0]=a;
        request[1]=b;
        request[2]=c;
        request[3]=d;
        RQ(customer_number);
    }

    // testing perpose for maximum 2d array
    // for(int k=0;k<NUM_OF_RES;k++){
    //     for(int b=0;b<NUM_OF_CUST;b++){
    //         printf("maximum : %d\n", maximum[k][b]);
    //     }
    // }
    
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

int RQ(int customer_number){

    // request resources function
    for(int i=0;i<4;i++){
        if(request[i]>available[i]){
            return -1;
        }
        if(request[i]>maximum[customer_number][i]){
            return -1;
        }
    }
    if(!safetyAlgorithm(customer_number, request)){
        return -1;
    }

    for(int i=0; i < 4;i++){
        available[i]-=request[i];
        allocation[customer_number][i]+=request[i];
    }
    return 0;


}

void RL(int customer_number){
}

void run(){

}

void asterisk(){

  
}

int safetyAlgorithm(int customer_number, int* request){

    return 0;
}
