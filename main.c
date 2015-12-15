#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DAY 3
#define PERIOD 3
#define NUMOFSUBJ 20

typedef struct{
    int class;
    int teacher;
    int size;
    int day;
    int period;
    int compulsory;
}SUBJECT;

typedef struct{
    int date[DAY][PERIOD];
    int size;
}ROOM;

typedef struct{
    int date[DAY][PERIOD];
}TEACHER;

typedef struct{
    int date[DAY][PERIOD];
}CLASS;

int MidCheck(int oldDay,int oldPeriod,SUBJECT targetSubject,ROOM room[],TEACHER teacher[],CLASS class[]);
int FinalCheck(ROOM room[],TEACHER teacher[],CLASS class[],SUBJECT subject[]);

int main(){
    srand((unsigned)time(NULL));
    int i,j,k,per,cla;
    int flag=1;
    int count=0;
    SUBJECT subject[NUMOFSUBJ]={
        {0,0,0,0,0,1},
        {1,2,0,0,0,1},
        {2,1,0,0,0,1},
        {3,2,1,0,0,1},
        {1,3,1,0,0,1},
        {2,4,1,0,0,1},
        {4,1,2,0,0,1},
        {1,3,2,0,0,0},
        {2,2,2,0,0,0},
        {3,0,2,0,0,0},
        {1,1,1,0,0,0},
        {2,2,0,0,0,0},
        {3,1,0,0,0,0},
        {1,4,2,0,0,0},
        {4,2,0,0,0,0},
        {2,1,0,0,0,0},
        {0,3,0,0,0,0},
        {3,0,1,0,0,0},
        {1,2,1,0,0,0},
        {2,1,1,0,0,0}
        
    };
    
    while(flag!=0){
        ROOM room[5]={};
        room[0].size = 0;
        room[1].size = 0;
        room[2].size = 1;
        room[3].size = 1;
        room[4].size = 2;
        TEACHER teacher[5]={};
        CLASS class[5]={};
        for(i=0;i<NUMOFSUBJ;i++){
            if(subject[i].size==2){
                j = rand()%DAY;
                k = rand()%PERIOD;
                per = subject[i].teacher;
                cla = subject[i].class;
                room[4].date[j][k]++;
                teacher[per].date[j][k]++;
                class[cla].date[j][k]++;
                subject[i].day = j;
                subject[i].period = k;
                
                
            }else if(subject[i].size==1){
                j = rand()%DAY;
                k = rand()%PERIOD;
                per = subject[i].teacher;
                cla = subject[i].class;
                room[rand()%2+2].date[j][k]++;
                teacher[per].date[j][k]++;
                class[cla].date[j][k]++;
                subject[i].day = j;
                subject[i].period = k;
                
            }else{
                j = rand()%DAY;
                k = rand()%PERIOD;
                per = subject[i].teacher;
                cla = subject[i].class;
                room[rand()%2].date[j][k]++;
                teacher[per].date[j][k]++;
                class[cla].date[j][k]++;
                subject[i].day = j;
                subject[i].period = k;
                
            }
        }
        flag = FinalCheck(room, teacher, class, subject);
        count++;

    }
    for(i=0;i<NUMOFSUBJ;i++){
        printf("subject[%d]は%d日目の%d時間目です(%d)\n",i,subject[i].day+1,subject[i].period+1,subject[i].class);
    }
    printf("%d\n",count);
}

int MidCheck(int newDay,int newPeriod,SUBJECT targetSubject,ROOM room[],TEACHER teacher[],CLASS class[]){
    
    
    return 0;
}

int FinalCheck(ROOM room[],TEACHER teacher[],CLASS class[],SUBJECT subject[]){
    int j,k,l;
    int count = 0;
    int compulsoryData[DAY][PERIOD]={};
    for(l=0;l<5;l++){
        for(j=0;j<DAY;j++){
            for(k=0;k<PERIOD;k++){
                if(room[l].date[j][k]>=1){
                    count += room[l].date[j][k]-1;
                }
                if(teacher[l].date[j][k]>=1){
                    count += teacher[l].date[j][k]-1;
                }
                if(class[l].date[j][k]>=1){
                    count += class[l].date[j][k]-1;
                }
                
            }
        }
    }
    for(l=0;l<NUMOFSUBJ;l++){
        if(subject[l].compulsory==1){
            j = subject[l].day;
            k = subject[l].period;
            compulsoryData[j][k]++;
        }
    }
    for(j=0;j<DAY;j++){
        for(k=0;k<PERIOD;k++){
            if(compulsoryData[j][k]>=1){
                count += compulsoryData[j][k]-1;
            }
            
        }
    }
    
    return count;
}
