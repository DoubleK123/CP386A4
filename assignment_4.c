// Kashif Khan khan4310   160694310 Github: 
// Hamdan Kasem Kase4140  171874140 Github: Kase4140


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>


int read_file(char* fileName, int* maximum);
int RQ(int);
void RL(int);
void asterisk();
void run();
int safetyAlgorithm(int, int* request);

#define NUM_OF_CUST 5 //rows
#define NUM_OF_RES 4 //columns

int available[4];
int maximum[NUM_OF_CUST][NUM_OF_RES];
int allocation[NUM_OF_CUST][NUM_OF_RES];
int need[NUM_OF_RES];
int request[NUM_OF_RES];
int release[NUM_OF_RES];


int main(int argc, char* argv[]){
    
    int i;
    int customer_number;
    int a,b,c,d;
    char command[4];
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
    printf("\n");
    if(strcmp(command,"RQ")==0){
        request[0]=a;
        request[1]=b;
        request[2]=c;
        request[3]=d;
        RQ(customer_number);
    }else if(strcmp(command,"RL")==0){
        release[0]=a;
        release[1]=b;
        release[2]=c;
        release[3]=d;
        RL(customer_number);
    }else if(strcmp(command,"*")==0){
        asterisk();
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

        for(int i=0; i< NUM_OF_CUST;i++){
            for(int j=0;j<NUM_OF_RES;j++){
                *(maximum+i*NUM_OF_RES+j)=array[i*NUM_OF_RES+j];
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
    for(int i=0; i < 4; i++){
        available[i]+=release[i];
        allocation[customer_number][i]-=release[i];
    }
}

void run(){
    // int running_thread = 1;

}

void asterisk(){

    printf("\n");
    printf("available array\n");
    for(int i=0;i<4;i++){
        printf("%d ", available[i]);
    }
    printf("\n");

    printf("maximum array\n");
    for(int i=0; i <NUM_OF_CUST;i++){
        printf("\n");
        for(int j=0;j<NUM_OF_RES;j++){
            printf("%d\t",maximum[i][j]);
        }
    }
    printf("\n");

    printf("allocation\n");
    for(int i=0; i <NUM_OF_CUST;i++){
        printf("\n");
        for(int j=0;j<NUM_OF_RES;j++){
            printf("%d\t",allocation[i][j]);
        }
    }
    printf("\n");

    printf("need\n");
    for(int i=0;i<4;i++){
        printf("%d ", need[i]);
    }
    printf("\n");
}

int safetyAlgorithm(int customer_number, int* request){
    int copy_resources[4];
    int copy_allocation[NUM_OF_CUST][NUM_OF_RES];
    // int flag = 0;
    for(int i=0; i<4;i++){
        copy_resources[i]=available[i];
    }
      for(int i=0; i <NUM_OF_CUST;i++){
        for(int j=0;j<NUM_OF_RES;j++){
            copy_allocation[i][j]=allocation[i][j];
        }
    }

    for(int i=0; i <NUM_OF_RES;i++){
        if(*(request+i)>copy_resources[i]){
            return 0;
        }
    }

    for(int i=0; i < NUM_OF_RES;i++){
        copy_resources[i]-=*(request+i);
        copy_allocation[customer_number][i]+=*(request+i);
    }

    int finish[NUM_OF_CUST];
    for(int i=0; i <NUM_OF_CUST;i++){
        finish[i]=0;
    }

    for(int i=0; i < NUM_OF_CUST; i++){
        for(int j=0; j<NUM_OF_RES;j++){
            if(!finish[j]){
                for(int k = 0; k<4;k++){
                    if(!((maximum[j][k] - copy_allocation[j][k]) > copy_resources[k])){
                        finish[j]=1;
                        for(int l=0;l<4;l++){
                            copy_resources[l]+=copy_allocation[j][l];
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i <4;i++){
        copy_allocation[customer_number][i]-=*(request+i);
    }

    for(int f = 0 ; f< NUM_OF_CUST;f++){
        if(!finish[f]){
            return 0;
        }
    }
    return 1;
}
