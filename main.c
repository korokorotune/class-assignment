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
    int room;
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

typedef struct{
    int date[DAY][PERIOD];
}COMPULSORY;

int MidCheck(int newDay,int newPeriod,int newRoom,SUBJECT targetSubject,ROOM room[],TEACHER teacher[],CLASS class[]);
int FinalCheck(ROOM room[],TEACHER teacher[],CLASS class[],SUBJECT subject[],COMPULSORY compulsoryData);

int main(){
    srand((unsigned)time(NULL));
    //もろもろの変数宣言
    int i,j,k,l,per,cla;
    int flag=1;                 //flagはwhileループ回すためのもの
    int count=0;                //countはwhileループ回した回数
    SUBJECT subject[NUMOFSUBJ]={
        {0,0,0,0,0,0,1},
        {1,2,0,0,0,0,1},
        {2,1,0,0,0,0,1},
        {3,2,1,0,0,0,1},
        {1,3,1,0,0,0,1},
        {2,4,1,0,0,0,1},
        {4,1,2,0,0,0,1},
        {1,3,2,0,0,0,0},
        {2,2,2,0,0,0,0},
        {3,0,2,0,0,0,0},
        {1,1,1,0,0,0,0},
        {2,2,0,0,0,0,0},
        {3,1,0,0,0,0,0},
        {1,4,2,0,0,0,0},
        {4,2,0,0,0,0,0},
        {2,1,0,0,0,0,0},
        {0,3,0,0,0,0,0},
        {3,0,1,0,0,0,0},
        {1,2,1,0,0,0,0},
        {2,1,1,0,0,0,0}
        
    };
    
    //ここからwhileループ
    while(flag!=0){
        ROOM room[5]={};
        COMPULSORY compulsoryData={};
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
                subject[i].room = 4;
                
                
            }else if(subject[i].size==1){
                j = rand()%DAY;
                k = rand()%PERIOD;
                l = rand()%2+2;
                per = subject[i].teacher;
                cla = subject[i].class;
                room[l].date[j][k]++;
                teacher[per].date[j][k]++;
                class[cla].date[j][k]++;
                subject[i].day = j;
                subject[i].period = k;
                subject[i].room = l;
                
            }else{
                j = rand()%DAY;
                k = rand()%PERIOD;
                l = rand()%2;
                per = subject[i].teacher;
                cla = subject[i].class;
                room[l].date[j][k]++;
                teacher[per].date[j][k]++;
                class[cla].date[j][k]++;
                subject[i].day = j;
                subject[i].period = k;
                subject[i].room = l;
                
            }
        }
        
        for(i=0;i<NUMOFSUBJ;i++){
            if(subject[i].compulsory==1){
                j = subject[i].day;
                k = subject[i].period;
                compulsoryData.date[j][k]++;
            }
        }
        
        flag = FinalCheck(room, teacher, class, subject, compulsoryData);
        count++;

    }
    for(i=0;i<NUMOFSUBJ;i++){
        printf("subject[%d]は%d日目の%d時間目です。教室は%dです(%d)\n",i,subject[i].day+1,subject[i].period+1,subject[i].room,subject[i].class);
    }
    printf("%d\n",count);
}

int MidCheck(int newDay,int newPeriod,int newRoom,SUBJECT targetSubject,ROOM room[],TEACHER teacher[],CLASS class[]){
    /*
    int oldCount = 0;
    int newCount = 0;
    int i,j,k,oldDay,oldPeriod;
    int compulsoryData[DAY][PERIOD]={};
    oldDay = targetSubject.day;
    oldPeriod = targetSubject.period;
    if(room[targetSubject.room].date[targetSubject.day][targetSubject.period]>=1){
        oldCount += room[targetSubject.room].date[targetSubject.day][targetSubject.period]-1;
    }
    if(teacher[targetSubject.teacher].date[targetSubject.day][targetSubject.period]>=1){
        oldCount += teacher[targetSubject.teacher].date[targetSubject.day][targetSubject.period]-1;
    }
    if(class[targetSubject.class].date[targetSubject.day][targetSubject.period]>=1){
        oldCount += class[targetSubject.class].date[targetSubject.day][targetSubject.period]-1;
    }
    
    //newRoomの方は移動したあとの評価なので1を引かない
    if(room[newRoom].date[targetSubject.day][targetSubject.period]>=1){
        oldCount += room[newRoom].date[targetSubject.day][targetSubject.period]-1;
    }
    if(teacher[targetSubject.teacher].date[targetSubject])
    newCount += teacher[targetSubject.teacher].date[newDay][newPeriod];
    newCount += class[targetSubject.class].date[newDay][newPeriod];
    
    */
    
    
    
    
    return 0;
}

int FinalCheck(ROOM room[],TEACHER teacher[],CLASS class[],SUBJECT subject[],COMPULSORY compulsoryData){
    int i,j,k;
    int count = 0;
    for(i=0;i<5;i++){
        for(j=0;j<DAY;j++){
            for(k=0;k<PERIOD;k++){
                if(room[i].date[j][k]>=1){
                    count += room[i].date[j][k]-1;
                }
                if(teacher[i].date[j][k]>=1){
                    count += teacher[i].date[j][k]-1;
                }
                if(class[i].date[j][k]>=1){
                    count += class[i].date[j][k]-1;
                }
                
            }
        }
    }
    for(j=0;j<DAY;j++){
        for(k=0;k<PERIOD;k++){
            if(compulsoryData.date[j][k]>=1){
                count += compulsoryData.date[j][k]-1;
            }
        }
    }
    
    return count;
}
