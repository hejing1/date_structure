#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<string>
using namespace std;
typedef struct josephus{
	int count;  // �������
	struct josephus *next;
}Josephus;

string a[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

Josephus* creat_link(Josephus*head){
    Josephus *p,*q;
    p=q=NULL;
    int j=1;
    do{
    	if(j==14) break;
        p=(Josephus*)malloc(sizeof(Josephus));
        if(p==NULL){
            printf("�ڴ����ʧ�ܣ��˳���");
            exit(1);
        }
        p->count=0;
        if(head==NULL){  // ѭ��������
            head=p;
        }
        else{
			q->next=p;
            p->next=NULL;  
        }
        q=p;
        j++;
    }while(1);
    q->next=head;
    return head;
}

void display_link(Josephus *head){
    Josephus *p;
    int i=0;
    for(p=head;i<13;p=p->next,i++)
        printf("%s\n",a[p->count-1].c_str());
}

void baoshu(Josephus *head){

	int counter=1;  //���м�����
    int i=0,j=0;   //����������
	int m=1;
    Josephus *p;
    for(p=head; m<=13;p=p->next){   //ģ��ѭ������
    	if(p->count!=0) continue;
        i++;
        if(i==m){
            i=0;
            p->count=m;
//            printf("%d\n",p->count);
            m++;
        }
    }
}
int main()
{
    Josephus *head=NULL;
    head=creat_link(head);
	baoshu(head);
	printf("�Ƶ�˳��Ϊ��\n");
    display_link(head);
    return 0;
}
