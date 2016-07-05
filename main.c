#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DAY 6
#define PERIOD 6
#define NUMOFSUBJ 189
#define NUMOFCLA 20
#define NUMOFROOM 20
#define NUMOFTEACH 20
#define TABOO 20

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
    clock_t start, end;
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
        {8,5,8,0,0,0,1},
        {17,6,10,0,0,0,1},
        {12,7,0,0,0,0,1},
        {12,1,7,0,0,0,1},
        {10,7,12,0,0,0,1},
        {5,2,16,0,0,0,1},
        {3,2,7,0,0,0,1},
        {9,8,15,0,0,0,1},
        {15,4,9,0,0,0,1},
        {4,14,5,0,0,0,1},
        {2,9,17,0,0,0,1},
        {2,3,0,0,0,0,1},
        {8,7,9,0,0,0,1},
        {13,10,8,0,0,0,1},
        {17,18,10,0,0,0,1},
        {3,12,17,0,0,0,1},
        {6,15,19,0,0,0,1},
        {11,13,3,0,0,0,1},
        {6,1,12,0,0,0,1},
        {6,12,1,0,0,0,1},
        {6,7,15,0,0,0,1},
        {9,7,7,0,0,0,1},
        {16,11,13,0,0,0,1},
        {8,9,1,0,0,0,1},
        {7,0,2,0,0,0,1},
        {3,16,4,0,0,0,1},
        {7,7,9,0,0,0,1},
        {9,15,0,0,0,0,1},
        {18,14,15,0,0,0,1},
        {19,14,19,0,0,0,1},
        {8,14,18,0,0,0,0},
        {15,11,3,0,0,0,0},
        {18,3,7,0,0,0,0},
        {2,17,11,0,0,0,0},
        {8,0,1,0,0,0,0},
        {10,4,14,0,0,0,0},
        {13,17,3,0,0,0,0},
        {7,0,4,0,0,0,0},
        {1,8,19,0,0,0,0},
        {0,13,14,0,0,0,0},
        {5,13,8,0,0,0,0},
        {16,15,0,0,0,0,0},
        {8,3,7,0,0,0,0},
        {4,2,9,0,0,0,0},
        {10,11,10,0,0,0,0},
        {16,17,3,0,0,0,0},
        {2,0,18,0,0,0,0},
        {3,12,17,0,0,0,0},
        {6,16,14,0,0,0,0},
        {16,0,4,0,0,0,0},
        {12,16,9,0,0,0,0},
        {13,6,12,0,0,0,0},
        {0,2,14,0,0,0,0},
        {11,7,2,0,0,0,0},
        {18,1,4,0,0,0,0},
        {8,9,7,0,0,0,0},
        {8,10,6,0,0,0,0},
        {4,1,17,0,0,0,0},
        {0,1,19,0,0,0,0},
        {3,16,11,0,0,0,0},
        {11,8,16,0,0,0,0},
        {10,3,0,0,0,0,0},
        {16,18,16,0,0,0,0},
        {9,4,8,0,0,0,0},
        {4,16,12,0,0,0,0},
        {13,0,14,0,0,0,0},
        {5,0,5,0,0,0,0},
        {9,19,2,0,0,0,0},
        {10,1,11,0,0,0,0},
        {2,12,2,0,0,0,0},
        {13,10,7,0,0,0,0},
        {15,2,5,0,0,0,0},
        {3,19,16,0,0,0,0},
        {5,4,1,0,0,0,0},
        {0,0,8,0,0,0,0},
        {10,4,3,0,0,0,0},
        {9,14,11,0,0,0,0},
        {15,8,0,0,0,0,0},
        {1,18,17,0,0,0,0},
        {15,17,3,0,0,0,0},
        {1,4,11,0,0,0,0},
        {8,4,7,0,0,0,0},
        {14,5,12,0,0,0,0},
        {2,8,18,0,0,0,0},
        {5,15,19,0,0,0,0},
        {2,5,8,0,0,0,0},
        {3,1,7,0,0,0,0},
        {9,7,19,0,0,0,0},
        {15,10,10,0,0,0,0},
        {14,1,1,0,0,0,0},
        {15,10,15,0,0,0,0},
        {10,13,0,0,0,0,0},
        {12,9,4,0,0,0,0},
        {0,0,6,0,0,0,0},
        {11,0,7,0,0,0,0},
        {18,10,10,0,0,0,0},
        {1,12,19,0,0,0,0},
        {4,19,14,0,0,0,0},
        {10,1,5,0,0,0,0},
        {10,16,1,0,0,0,0},
        {3,10,2,0,0,0,0},
        {3,7,4,0,0,0,0},
        {11,14,9,0,0,0,0},
        {6,12,9,0,0,0,0},
        {2,10,12,0,0,0,0},
        {3,5,17,0,0,0,0},
        {9,7,2,0,0,0,0},
        {18,5,13,0,0,0,0},
        {2,10,5,0,0,0,0},
        {10,13,6,0,0,0,0},
        {7,4,18,0,0,0,0},
        {8,0,5,0,0,0,0},
        {13,5,0,0,0,0,0},
        {4,4,5,0,0,0,0},
        {8,12,19,0,0,0,0},
        {13,8,2,0,0,0,0},
        {17,19,15,0,0,0,0},
        {15,15,17,0,0,0,0},
        {9,17,6,0,0,0,0},
        {3,5,9,0,0,0,0},
        {11,9,6,0,0,0,0},
        {1,9,0,0,0,0,0},
        {14,14,18,0,0,0,0},
        {2,13,0,0,0,0,0},
        {4,8,3,0,0,0,0},
        {9,16,8,0,0,0,0},
        {17,14,8,0,0,0,0},
        {11,10,14,0,0,0,0},
        {4,12,12,0,0,0,0},
        {14,4,3,0,0,0,0},
        {11,2,0,0,0,0,0},
        {18,8,11,0,0,0,0},
        {5,10,3,0,0,0,0},
        {2,13,6,0,0,0,0},
        {4,19,18,0,0,0,0},
        {14,18,6,0,0,0,0},
        {13,15,17,0,0,0,0},
        {7,17,19,0,0,0,0},
        {18,16,12,0,0,0,0},
        {15,3,1,0,0,0,0},
        {3,18,17,0,0,0,0},
        {4,13,16,0,0,0,0},
        {4,4,12,0,0,0,0},
        {9,17,13,0,0,0,0},
        {15,16,5,0,0,0,0},
        {5,8,17,0,0,0,0},
        {0,17,4,0,0,0,0},
        {18,7,7,0,0,0,0},
        {0,19,18,0,0,0,0},
        {2,15,14,0,0,0,0},
        {9,17,12,0,0,0,0},
        {2,10,3,0,0,0,0},
        {3,1,16,0,0,0,0},
        {19,4,7,0,0,0,0},
        {6,3,0,0,0,0,0},
        {12,1,15,0,0,0,0},
        {3,0,18,0,0,0,0},
        {18,11,18,0,0,0,0},
        {13,5,10,0,0,0,0},
        {8,6,14,0,0,0,0},
        {11,4,9,0,0,0,0},
        {11,16,4,0,0,0,0},
        {12,19,15,0,0,0,0},
        {5,8,13,0,0,0,0},
        {18,14,7,0,0,0,0},
        {7,15,11,0,0,0,0},
        {16,17,3,0,0,0,0},
        {6,19,17,0,0,0,0},
        {16,7,19,0,0,0,0},
        {17,15,12,0,0,0,0},
        {3,5,10,0,0,0,0},
        {4,11,17,0,0,0,0},
        {15,1,12,0,0,0,0},
        {1,4,16,0,0,0,0},
        {14,17,17,0,0,0,0},
        {8,11,1,0,0,0,0},
        {15,1,11,0,0,0,0},
        {10,18,9,0,0,0,0},
        {11,7,1,0,0,0,0},
        {1,17,19,0,0,0,0},
        {4,5,7,0,0,0,0},
        {3,0,4,0,0,0,0},
        {11,14,0,0,0,0,0},
        {9,7,1,0,0,0,0},
        {5,2,10,0,0,0,0},
        {6,16,12,0,0,0,0},
        {10,6,8,0,0,0,0},
        {15,13,6,0,0,0,0},
        {11,12,18,0,0,0,0},
        {1,11,19,0,0,0,0}
    };
    
    ROOM room[NUMOFROOM]={};
    TEACHER teacher[NUMOFTEACH]={};
    CLASS class[NUMOFCLA]={};
    COMPULSORY compulsoryData={};
    
    start = clock();
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
        for(l=0;l<NUMOFROOM;l++){
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
        check=-255;
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
    end = clock();
    printf( "処理時間:%ld[ms]\n", end-start);
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
        count += compulsoryData.date[day][period]-1;
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
    for(i=0;i<NUMOFROOM;i++){
        for(j=0;j<DAY;j++){
            for(k=0;k<PERIOD;k++){
                if(room[i].date[j][k]>=2){
                    count += room[i].date[j][k]-1;
                }
            }
        }
    }
    for(i=0;i<NUMOFCLA;i++){
        for(j=0;j<DAY;j++){
            for(k=0;k<PERIOD;k++){
                if(class[i].date[j][k]>=2){
                    count += class[i].date[j][k]-1;
                }
            }
        }
    }
    for(i=0;i<NUMOFTEACH;i++){
        for(j=0;j<DAY;j++){
            for(k=0;k<PERIOD;k++){
                if(teacher[i].date[j][k]>=2){
                    count += teacher[i].date[j][k]-1;
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
