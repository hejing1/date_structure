#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<iostream>
using namespace std;

typedef struct josephus{
	int num;   // 座位序号
	struct josephus *next;
}Josephus;

Josephus* creat_link(Josephus*head,int n){
    Josephus *p,*pre;
    p=pre=NULL;
    int i=1;
    do{
    	if(i>n) break;
        p=(Josephus*)malloc(sizeof(Josephus));
        if(p==NULL){
            printf("内存分配失败，退出！");
            exit(1);
        }
        p->num=i++;
        if(head==NULL){  // 循环单链表
            head=p;
        }
        else{
            pre->next=p;
        }
        pre=p;
    }while(1);
    pre->next=head;
    return head;
}

void baoshu(Josephus *head,int n,int m){

	int counter=1;  //出列记数器
    int i=0,j=0;   //报数记数器
    Josephus *p,*pre;
    for(p=pre=head; counter<n;p=p->next){   //模拟循环报数
        i++;
        if(i==m){// 报到3出列，删除该结点
            i=0;
            printf("%d\n",p->num);
            pre->next=p->next;
            free(p);
            counter++;
        }
    	else  pre=p;
    }
}

int main()
{
    Josephus *head=NULL;
    int n,m;
    cin>>n>>m;
    head=creat_link(head,n);
    baoshu(head,n,m);
    return 0;
}




