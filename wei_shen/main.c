//
//  main.c
//  wei_shen
//
//  Created by MAC on 2017/6/24.
//  Copyright © 2017年 blackay. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_LEN 15

void Menu(int s[],char str1[][MAX_LEN],char str2[][MAX_LEN]);
void Banner();
void RandomNumber(int s[]);
void PrintOut(int s[],char str1[][MAX_LEN],char str2[][MAX_LEN]);
void RandomArray(char str[][MAX_LEN],int s[]);

int main()
{
    srand(time(NULL));
    char str1[5][MAX_LEN] = {"Xue_mei:","Pei_lun:","Xian_yu:","Hong_lin:","Mao:"};
    char str2[5][MAX_LEN] = {"Sweeping","Moping","Table","Washbasin","WC"};
    int s[5];
    system("color a");
    Menu(s,str1,str2);
    return 0;
}

void Banner(){
    system("cls");
    printf("*************************************************************\n");
    printf("**                                                         **\n");
    printf("**                     Welcome to                          **\n");
    printf("**                 Forgive Dormitory 315                   **\n");
    printf("**             Health Task Allocation System               **\n");
    printf("**                                                         **\n");
    printf("**                         Developer: blackay03            **\n");
    printf("**                              2017.6.23:V 1.0            **\n");
    printf("**                                                         **\n");
    printf("*************************************************************\n");
    
    char choose;
    do{
        printf("是否关闭帮助？（y/n）\n");
        scanf("%c",&choose);
        if(choose=='y') break;
        else printf("你！学！弟！\n");
        getchar();
    }while(choose!='y'||choose!='n');
}

void Menu(int s[],char str1[][MAX_LEN],char str2[][MAX_LEN]){
RESTARTMENU:printf("************************************************************\n");
    printf("**                                                        **\n");
    printf("**                   请选择功能:                          **\n");
    printf("**                                                        **\n");
    printf("**                   1.任务分配                           **\n");
    printf("**                   2.任务日志                           **\n");
    printf("**                   3.系统帮助                           **\n");
    printf("**                   4.退出系统                           **\n");
    printf("**                （请输入选择序号）                      **\n");
    printf("**                                                        **\n");
    printf("************************************************************\n");
    int choose;
    char answer;
    printf("请输入你的选择：\n");
    scanf("%d",&choose);
    getchar();
    switch(choose) {
        case 1:
            do{
                PrintOut(s,str1,str2);
                printf("对结果是否满意？满意请输入(y)，不满意请输入(n)。\n");
                scanf(" %c",&answer);
                if(answer=='y') break;
                else {
                    system("cls");
                    printf("                你！李！白！\n\n");
                    printf("请重新选择！\n\n");
                    goto RESTARTMENU;
                }
                /*else {
                 printf("输入错误！\n");
                 system("cls");
                 goto RESTARTMENU;
                 }*/
            }while(answer!='y'||answer!='n');
            break;
        case 2:
            system("cls");
            printf("            此功能待添加！\n\n");
            goto RESTARTMENU;
            break;
        case 3:
            Banner();
            system("cls");
            getchar();
            goto RESTARTMENU;
            break;
        case 4:
            printf("系统关闭，感谢您的使用！\n");
            exit(0);
            break;
        default:
            printf("            非法输入！\n\n");
    }
}

void RandomNumber(int s[]){
    int i,j,count = 0;
    for(i=0;i<10;i++) {
        s[i] = rand()%5+1;
        count++;
        
        if(i>=1) {
            for(j=i-1;j>=0;j--) {
                if(s[i]==s[j]) {
                    i--;
                    count--;
                    break;
                }
            }
        }
        if(count==5) break;
    }
}

void PrintOut(int s[],char str1[5][MAX_LEN],char str2[5][MAX_LEN]){
    int j;
    RandomArray(str1,s);
    RandomArray(str2,s);
    printf("************************************************************\n\n");
    printf("P.S.    xian_yu是李白，xue_mei是效宸，mao是茂，hong_lin是霖，pei_lun是佩伦\n");
    printf("P.S.    sweeping 扫地，WC 厕所，Washbasin 洗漱间，moping 拖地，table 桌面\n\n");
    printf("************************************************************\n\n");
    for(j=0;j<5;j++) {
        printf("第%d位成员： ",j+1);
        puts(str1[j]);
        printf("他需要完成的是： ");
        puts(str2[j]);
        printf("\n");
    }
}

void RandomArray(char str[][MAX_LEN],int s[]) {
    char temp[MAX_LEN]= {0};
    int i,number=0;
    RandomNumber(s);
    for(i=0;i<5;i++){
        number=s[i]-1;
        if(strcmp(str[number],str[i])<0) {
            strcpy(temp,str[i]);
            strcpy(str[i],str[number]);
            strcpy(str[number],temp);
        }
    }
}
