#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include<iostream>
using namespace std;

typedef struct josephus{
	int num;   // ��λ���
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
            printf("�ڴ����ʧ�ܣ��˳���");
            exit(1);
        }
        p->num=i++;
        if(head==NULL){  // ѭ��������
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

	int counter=1;  //���м�����
    int i=0,j=0;   //����������
    Josephus *p,*pre;
    p=pre=head;
    while(b--){
    	p=pre=p->next;
	}
    for( ; counter<n;p=p->next){   //ģ��ѭ������
        i++;
        if(i==m){// ����3���У�ɾ���ý��
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
    cout<<"������С����������Kֵ�����Կո������\n";
    cin>>n>>m;
    cout<<"������ӵ�__�����֣���С����ʼ������";
	int b;
	cin>>b; 
    head=creat_link(head,n);
    head=baoshu(head,n,m,b-1);
   cout<<head->num<<endl; 
    return 0;
}
