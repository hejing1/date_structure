#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <mmsystem.h>                    //��������ͷ�ļ�
#pragma comment(lib,"Winmm.lib")         //��������ͷ�ļ���
#include <sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


#define NAME_MAX 15
#define TEL_MAX 15
#define REL_MAX 20
#define ADDR_MAX 20


typedef struct LINK                                                               
{
	int id; 
	char name[NAME_MAX];
    char rel[REL_MAX];
    char tel[TEL_MAX];
	char addr[ADDR_MAX];
	struct LINK *next;	
}linkman;

linkman * head=(linkman *)malloc(sizeof(linkman));
int cnt=1;

void creatline()	//ok 
{
	FILE *fp = fopen("ͨѶ¼.txt","r");
    if(fp==NULL)
	{
	   printf("���ļ�ʧ�ܣ�\n");
	   exit(0);
	}
	linkman *q=(linkman *)malloc(sizeof(linkman)); 
	fscanf(fp,"%s %s %s %s",&name,&rel,&tel,&addr);
	q->id=cnt;
	strcpy(q->name,name);
	strcpy(q->rel,rel);
	strcpy(q->tel,tel);
	strcpy(q->addr,addr);
	q->next=NULL;
	cnt++;
	head->next=q;
	char name[NAME_MAX];
    char rel[REL_MAX];
    char tel[TEL_MAX];
	char addr[ADDR_MAX];
	while(fscanf(fp,"%s %s %s %s",&name,&rel,&tel,&addr)!=EOF){	
	    linkman *p=(linkman *)malloc(sizeof(linkman)) ;    
		q=p;                           //���ݴ��ļ�������������
		q->id=cnt;
		strcpy(q->name,name);
		strcpy(q->rel,rel);
		strcpy(q->tel,tel);
		strcpy(q->addr,addr);
		q->next=NULL;
		cnt++;
	}
	fclose(fp);
	printf("��Ϣ¼��ɹ���\n");
	return ;
}

void look_linkman()     //��ʾ�������ѡ�ͬѧ��ͬ�� ok
{
	char rel[REL_MAX];
	linkman * i;
	int flag=0;
	printf("��ѡ����Ҫ�鿴����ϵ��:������/ͬѧ/ͬ�£�\n");
	scanf("%s",rel);
	for(i=head;i!=NULL;i=i->next){
		if(strcmp(rel,i->rel)==0){
			printf("%s\t%s\t%s\t%s\t\n",i->name,i->rel,i->tel,i->addr);flag=1;
		}
	}
	if(flag==0) printf("û�д�����ϵ�ˡ�����\n");
	printf("�밴�س���������...");
}

void save(){				//�������ļ�  ��bug,�����������Ҳ����� 
	FILE *fp = fopen("ͨѶ¼.txt","w+");
    if(fp==NULL)
	{
	   printf("���ļ�ʧ�ܣ�\n");
	   exit(0);
	}
    linkman *p = head;
	while(p!=NULL){
		printf("%s %s %s %s\n",p->name,p->rel,p->tel,p->addr);
		fprintf(fp,"%s %s %s %s\n",p->name,p->rel,p->tel,p->addr);
		p=p->next;
	}
	fclose(fp);
	printf("��Ϣ����ɹ���\n");
}


void add_linkman()	//����save()������ok 
{
	if (cnt == 20)
    {
        printf("��ͨѶ¼�������޷�¼����Ϣ��\n");return ;
	}
	linkman *pnew=(linkman *)malloc(sizeof(linkman)); 
    printf("����������:\n");
    scanf("%s",&(pnew->name));
    printf("������������/���Ĺ�ϵ������/ͬѧ/ͬ�£���\n");
    scanf("%s",&(pnew->rel));
    printf("������绰���룺\n");
    scanf("%s",&(pnew->tel));
    printf("���������䣺\n");
    scanf("%s",&(pnew->addr));
    cnt++;
    pnew->id=cnt;
    if(head==NULL) head=pnew;
    else{
    	linkman *q=head;
    	while(q->next!=NULL) q=q->next;
    	q->next=pnew;
	}
	save();
	printf("�밴�س���������..."); 	
}

void menu()                           //�˵���������ʾ���й���
{
	printf("\n");
    printf("........1.�鿴��ϵ����Ϣ.........\n");
    printf("........2.�����ϵ����Ϣ.........\n");
    printf("........3.����绰...............\n");
    printf("........4.�޸���ϵ����Ϣ.........\n");
    printf("........5.ɾ����ϵ��.............\n");
    printf("........6.�����������ϵ��.......\n");
	printf("........0.�˳�...................\n");
}


int main()                                            //������
{
	head->next=NULL;
	int opp = 1;                                     //����ѡ�����opp                            
    creatline(); 
	while (opp)                                      //opp��ֵΪÿһ���ǰ�����֣�opp��Ϊ��ɼ������в�������Ϊ�����˳�
	{
		menu();                                          //�˵�����,��ʾͨѶ¼�Ĺ���
    	printf("��ѡ��:");
    	scanf("%d", &opp);                               //�����ѡ���ҵ��
    	switch (opp)                                     //����switch���������з���
		{
	   		case 0:	exit(EXIT_FAILURE);                      //��ʾû�гɹ�ִ�г���
			break;
			case 1:	look_linkman();        //�鿴��ϵ�˺���  ok 
			break;
        	case 2: add_linkman();         //�����ϵ�˺��� save()���������� 
			break;
		}
		getchar();
		getchar();
		system("cls");
	}
	
	return 0;
}


