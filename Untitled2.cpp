#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <mmsystem.h>                    //调用声音头文件
#pragma comment(lib,"Winmm.lib")         //导入声音头文件库
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
	FILE *fp = fopen("通讯录.txt","r");
    if(fp==NULL)
	{
	   printf("打开文件失败！\n");
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
		q=p;                           //数据从文件放在链表里面
		q->id=cnt;
		strcpy(q->name,name);
		strcpy(q->rel,rel);
		strcpy(q->tel,tel);
		strcpy(q->addr,addr);
		q->next=NULL;
		cnt++;
	}
	fclose(fp);
	printf("信息录入成功！\n");
	return ;
}

void look_linkman()     //显示所有亲友、同学或同事 ok
{
	char rel[REL_MAX];
	linkman * i;
	int flag=0;
	printf("请选择你要查看的联系人:（亲友/同学/同事）\n");
	scanf("%s",rel);
	for(i=head;i!=NULL;i=i->next){
		if(strcmp(rel,i->rel)==0){
			printf("%s\t%s\t%s\t%s\t\n",i->name,i->rel,i->tel,i->addr);flag=1;
		}
	}
	if(flag==0) printf("没有此类联系人。。。\n");
	printf("请按回车继续操作...");
}

void save(){				//保存至文件  有bug,会跳出程序，找不出来 
	FILE *fp = fopen("通讯录.txt","w+");
    if(fp==NULL)
	{
	   printf("打开文件失败！\n");
	   exit(0);
	}
    linkman *p = head;
	while(p!=NULL){
		printf("%s %s %s %s\n",p->name,p->rel,p->tel,p->addr);
		fprintf(fp,"%s %s %s %s\n",p->name,p->rel,p->tel,p->addr);
		p=p->next;
	}
	fclose(fp);
	printf("信息保存成功！\n");
}


void add_linkman()	//除了save()，其他ok 
{
	if (cnt == 20)
    {
        printf("该通讯录已满，无法录入信息！\n");return ;
	}
	linkman *pnew=(linkman *)malloc(sizeof(linkman)); 
    printf("请输入姓名:\n");
    scanf("%s",&(pnew->name));
    printf("请输入您和他/她的关系（亲友/同学/同事）：\n");
    scanf("%s",&(pnew->rel));
    printf("请输入电话号码：\n");
    scanf("%s",&(pnew->tel));
    printf("请输入邮箱：\n");
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
	printf("请按回车继续操作..."); 	
}

void menu()                           //菜单函数，显示所有功能
{
	printf("\n");
    printf("........1.查看联系人信息.........\n");
    printf("........2.添加联系人信息.........\n");
    printf("........3.拨打电话...............\n");
    printf("........4.修改联系人信息.........\n");
    printf("........5.删除联系人.............\n");
    printf("........6.清空所有人联系人.......\n");
	printf("........0.退出...................\n");
}


int main()                                            //主函数
{
	head->next=NULL;
	int opp = 1;                                     //定义选择变量opp                            
    creatline(); 
	while (opp)                                      //opp的值为每一项功能前的数字，opp不为零可继续进行操作，若为零则退出
	{
		menu();                                          //菜单函数,显示通讯录的功能
    	printf("请选择:");
    	scanf("%d", &opp);                               //输出你选择的业务
    	switch (opp)                                     //利用switch函数，进行分类
		{
	   		case 0:	exit(EXIT_FAILURE);                      //表示没有成功执行程序
			break;
			case 1:	look_linkman();        //查看联系人函数  ok 
			break;
        	case 2: add_linkman();         //添加联系人函数 save()函数有问题 
			break;
		}
		getchar();
		getchar();
		system("cls");
	}
	
	return 0;
}


