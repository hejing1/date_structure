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

Josephus* baoshu(Josephus *head,int n,int m,int b){

	int counter=1;  //出列记数器
    int i=0,j=0;   //报数记数器
    Josephus *p,*pre;
    p=pre=head;
    while(b--){
    	p=pre=p->next;
	}
    for( ; counter<n;p=p->next){   //模拟循环报数
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
    head=p;
    return head;
}

int main()
{
    Josephus *head=NULL;
    int n,m;
    cout<<"请输入小孩的人数及K值：（以空格隔开）\n";
    cin>>n>>m;
    cout<<"请输入从第__（数字）个小孩开始报数：";
	int b;
	cin>>b; 
    head=creat_link(head,n);
    head=baoshu(head,n,m,b-1);
   cout<<head->num<<endl; 
    return 0;
}
