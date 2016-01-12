#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DAY 4
#define PERIOD 4
#define NUMOFSUBJ 20
#define TABOO 3

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

int SimCheck(SUBJECT targetSubject,ROOM room[],TEACHER teacher[],CLASS class[], COMPULSORY compulsoryData);

int MidCheck(int newDay,int newPeriod,int newRoom,SUBJECT targetSubject,ROOM room[],TEACHER teacher[],CLASS class[], COMPULSORY compulsoryData);
int FinalCheck(ROOM room[],TEACHER teacher[],CLASS class[],SUBJECT subject[],COMPULSORY compulsoryData);

int main(){
    srand((unsigned)time(NULL));
    //もろもろの変数宣言
    int i,j,k,l,per,cla,hoge;
    int flag=0;                 //flagはwhileループ回すためのもの
    int maxnum=0;
    int minnumday=0;
    int minnumperiod=0;
    int check=0;
    int taboo[TABOO]={};
    hoge = 0;
    for(i=0;i<TABOO;i++){
        taboo[i]=NUMOFSUBJ;
    }
    //int count=0;
    //countはwhileループ回した回数
    SUBJECT subject[NUMOFSUBJ]={
        {0,0,0,0,0,0,1},
        {1,2,3,0,0,0,1},
        {2,1,4,0,0,0,1},
        {3,2,1,0,0,0,1},
        {1,3,3,0,0,0,1},
        {2,4,1,0,0,0,1},
        {4,1,2,0,0,0,1},
        {1,3,2,0,0,0,0},
        {2,2,3,0,0,0,0},
        {3,0,4,0,0,0,0},
        {1,1,1,0,0,0,0},
        {2,2,0,0,0,0,0},
        {3,1,3,0,0,0,0},
        {1,4,2,0,0,0,0},
        {4,2,0,0,0,0,0},
        {2,1,4,0,0,0,0},
        {0,3,0,0,0,0,0},
        {3,0,3,0,0,0,0},
        {1,2,1,0,0,0,0},
        {2,1,1,0,0,0,0}
        
    };
    
    ROOM room[5]={};
    TEACHER teacher[5]={};
    CLASS class[5]={};
    COMPULSORY compulsoryData={};
    
    //ここからwhileループ
    //do{
    /*
     この部分はいらない気がする
     room[0].size = 0;
     room[1].size = 0;
     room[2].size = 1;
     room[3].size = 1;
     room[4].size = 2;
     */
    for(i=0;i<NUMOFSUBJ;i++){
        for(l=0;l<5;l++){
            if(subject[i].size==l){
                j = rand()%DAY;
                k = rand()%PERIOD;
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
    }
    
    for(i=0;i<NUMOFSUBJ;i++){
        if(subject[i].compulsory==1){
            j = subject[i].day;
            k = subject[i].period;
            compulsoryData.date[j][k]++;
        }
    }
    
    flag = FinalCheck(room, teacher, class, subject, compulsoryData);
    
    printf("%d\n",flag);
    printf("%d\n",room[subject[0].room].date[subject[0].day][subject[0].period]);
    //}while(flag!=0);
    
    
    while(flag!=0){
        check=0;
        maxnum=0;
        for(i=0;i<NUMOFSUBJ;i++){
            hoge=0;
            for(j=0;j<TABOO;j++){
                if(taboo[j]==i){
                    hoge = 1;
                }
            }
            if(check<SimCheck(subject[i], room, teacher, class, compulsoryData)&&hoge==0){
                check = SimCheck(subject[i], room, teacher, class, compulsoryData);
                maxnum = i;
            }
        }
        for(i=TABOO;i>0;i--){
            taboo[i] = taboo[i-1];
        }
        taboo[0]=maxnum;
        
        for(i=0;i<TABOO;i++){
            printf("taboo[%d] = %d\n",i,taboo[i]);
        }
        
        printf("maxnum=%d\ncheck=%d\n",maxnum,check);
        check=0;
        for(i=0;i<DAY;i++){
            for(j=0;j<PERIOD;j++){
                if(check<MidCheck(i, j, subject[maxnum].room, subject[maxnum], room, teacher, class, compulsoryData)){
                    check = MidCheck(i, j, subject[maxnum].room, subject[maxnum], room, teacher, class, compulsoryData);
                    minnumday = i;
                    minnumperiod = j;
                }
            }
        }
        
        room[subject[maxnum].room].date[subject[maxnum].day][subject[maxnum].period]--;
        teacher[subject[maxnum].teacher].date[subject[maxnum].day][subject[maxnum].period]--;
        class[subject[maxnum].class].date[subject[maxnum].day][subject[maxnum].period]--;
        if(subject[maxnum].compulsory==1){
            compulsoryData.date[subject[maxnum].day][subject[maxnum].period]--;
        }
        
        subject[maxnum].day = minnumday;
        subject[maxnum].period = minnumperiod;
        
        room[subject[maxnum].room].date[subject[maxnum].day][subject[maxnum].period]++;
        teacher[subject[maxnum].teacher].date[subject[maxnum].day][subject[maxnum].period]++;
        class[subject[maxnum].class].date[subject[maxnum].day][subject[maxnum].period]++;
        if(subject[maxnum].compulsory==1){
            compulsoryData.date[subject[maxnum].day][subject[maxnum].period]++;
        }
        
        
        flag = FinalCheck(room, teacher, class, subject, compulsoryData);
        printf("%d\n",flag);
        
    }
    
    for(i=0;i<NUMOFSUBJ;i++){
        printf("subject[%d]は%d日目の%d時間目です。教室は%dです(%d)\n",i,subject[i].day+1,subject[i].period+1,subject[i].room,subject[i].class);
    }
    for(i=0;i<DAY;i++){
        for(j=0;j<PERIOD;j++){
            printf("%d\n",class[2].date[i][j]);
        }
    }
    return 0;
    
}

//現在の違反数を判定するための超簡易判定関数
int SimCheck(SUBJECT targetSubject,ROOM room[],TEACHER teacher[],CLASS class[], COMPULSORY compulsoryData){
    int count=0;
    int day = targetSubject.day;
    int period = targetSubject.period;
    count += room[targetSubject.room].date[day][period]-1;
    count += teacher[targetSubject.teacher].date[day][period]-1;
    count += class[targetSubject.class].date[day][period]-1;
    if(targetSubject.compulsory==1){
        count += compulsoryData.date[day][period];
    }
    return count;
}

//途中で判定するための簡易判定関数
int MidCheck(int newDay,int newPeriod,int newRoom,SUBJECT targetSubject,ROOM room[],TEACHER teacher[],CLASS class[], COMPULSORY compulsoryData){
    int oldCount = 0;
    int newCount = 0;
    int oldDay,oldPeriod;
    oldDay = targetSubject.day;
    oldPeriod = targetSubject.period;
    
    //ここから遷移させる前の違反数検出
    if(room[targetSubject.room].date[oldDay][oldPeriod]>=2){
        oldCount += room[targetSubject.room].date[oldDay][oldPeriod]-1;
    }
    if(room[newRoom].date[newDay][newPeriod]>=2){
        oldCount += room[newRoom].date[newDay][newPeriod]-1;
    }
    
    if(teacher[targetSubject.teacher].date[oldDay][oldPeriod]>=2){
        oldCount += teacher[targetSubject.teacher].date[oldDay][oldPeriod]-1;
    }
    if(teacher[targetSubject.teacher].date[newDay][newPeriod]>=2){
        oldCount += teacher[targetSubject.teacher].date[newDay][newPeriod]-1;
    }

    if(class[targetSubject.class].date[oldDay][oldPeriod]>=2){
        oldCount += class[targetSubject.class].date[oldDay][oldPeriod]-1;
    }
    if(class[targetSubject.class].date[newDay][newPeriod]>2){
        oldCount += class[targetSubject.class].date[newDay][newPeriod]-1;
    }

    
    if(compulsoryData.date[oldDay][oldPeriod]>=2){
        oldCount += compulsoryData.date[oldDay][oldPeriod]-1;
    }
    if(compulsoryData.date[newDay][newPeriod]>=2){
        oldCount += compulsoryData.date[newDay][newPeriod]-1;
    }
    
    
    //ここから遷移させた後の違反数検出(遷移させた後なので1を引かない)
    if(room[targetSubject.room].date[newDay][newPeriod]>=3){
        newCount += room[targetSubject.room].date[newDay][newPeriod]-2;
    }
    if(room[newRoom].date[newDay][newPeriod]>=1){
        newCount += room[newRoom].date[newDay][newPeriod];
    }
    
    if(teacher[targetSubject.teacher].date[oldDay][oldPeriod]>=3){
        newCount += teacher[targetSubject.teacher].date[oldDay][oldPeriod]-2;
    }
    if(teacher[targetSubject.teacher].date[newDay][newPeriod]>=1){
        newCount += teacher[targetSubject.teacher].date[newDay][newPeriod];
    }
    
    if(class[targetSubject.class].date[oldDay][oldPeriod]>=3){
        newCount += class[targetSubject.class].date[oldDay][oldPeriod]-2;
    }
    if(class[targetSubject.class].date[newDay][newPeriod]>=1){
        newCount += class[targetSubject.class].date[newDay][newPeriod];
    }
    
    if(compulsoryData.date[oldDay][oldPeriod]>=2){
        if(targetSubject.compulsory==1){
            newCount += compulsoryData.date[oldDay][oldPeriod]-2;
        }else{
            newCount += compulsoryData.date[oldDay][oldPeriod]-1;
        }
    }
    if(compulsoryData.date[newDay][newPeriod]>=1){
        if(targetSubject.compulsory==1){
            newCount += compulsoryData.date[newDay][newPeriod];
        }else{
            newCount += compulsoryData.date[newDay][newPeriod]-1;
        }
    }
    
    return oldCount-newCount;
}

//最終的に判定するための判定関数
int FinalCheck(ROOM room[],TEACHER teacher[],CLASS class[],SUBJECT subject[],COMPULSORY compulsoryData){
    int i,j,k;
    int count = 0;
    for(i=0;i<5;i++){
        for(j=0;j<DAY;j++){
            for(k=0;k<PERIOD;k++){
                if(room[i].date[j][k]>=2){
                    count += room[i].date[j][k]-1;
                }
                if(teacher[i].date[j][k]>=2){
                    count += teacher[i].date[j][k]-1;
                }
                if(class[i].date[j][k]>=2){
                    count += class[i].date[j][k]-1;
                }
                
            }
        }
    }
    for(j=0;j<DAY;j++){
        for(k=0;k<PERIOD;k++){
            if(compulsoryData.date[j][k]>=2){
                count += compulsoryData.date[j][k]-1;
            }
        }
    }
    
    return count;
}
