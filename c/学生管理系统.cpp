
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

#define NAME 20//名字长度 
#define GRADE 20//班级长度 

//学生结构体定义
struct student{
	char name[NAME];
	char number[20];
	char grade[GRADE];
	int score1;
	int score2;
	int score3;
	int allscore;
	int allranking;//全级排名
	int banranking;//全班排名 
	struct student *next; 
}; 
//账号结构体定义 
struct account{
	char number[200];
	char pass[200];
	struct account *next;
};

/*函数声明*/
//一级主菜单选项显示 
void Select_MainMenu(struct student* phead);
//密码注册
int Secret_Build(struct student* phead);
//密码修改
int Secret_Alter(struct student* phead); 
//学生端菜单相关函数
//学生端主菜单选项显示
void Select_StuMainMenu(struct student* phead);
//二级菜单：成绩查询模块显示 
void Select_ScoreMenu(struct student* phead);
//二级菜单：查询本班成绩模块显示
void Select_AllScoreMenu(struct student* phead);
//二级菜单：成绩分析模块显示
void Select_ScoreAnalysisMenu(struct student* phead, char num[10]);
//教师端菜单相关函数
//教师端主菜单选项显示
void Select_TeaMainMenu(struct student* phead); 
//二级菜单：增加新的学生信息模块显示
struct student* Select_AddStudentMenu(struct student* phead);
//二级菜单：删除学生信息模块显示
struct student* Select_DeleteMenu(struct student* phead);
//二级菜单：修改学生信息模块显示
struct student* Select_AlterMenu(struct student* phead);
//二级菜单：查询学生信息模块显示
void Select_QueryMenu(struct student* phead);
//二级菜单：输出本班成绩模块显示
void Select_OutputMenu(struct student* phead);
//二级菜单：下载文件模块显示
void Select_DownloadMenu(struct student* phead);
//二级菜单：成绩分析模块显示
void Select_ScoreAnalysisMenu(struct student* phead);
//管理员菜单相关函数
//管理员主菜单选项显示
void Select_ManMainMenu(struct student* phead); 
//二级菜单：进入代办选项模块显示
void Select_DealMenu(struct student* phead);
//三级菜单：密码注册模块显示
void Select_PasswordReMenu(struct student* phead);
//三级菜单：密码修改模块显示
void Select_PasswordAlMenu(struct student* phead);
//三级菜单：更新成绩库模块显示
void Select_RenewScoreMenu(struct student* phead);
//二级菜单：进入教师端进行信息修改模块显示
void Select_InTeaAlInfoMenu(struct student* phead);
//二级菜单：增加账号及密码模块显示
struct account* Select_AddNumPassMenu(struct account* ahead);
//二级菜单：删除账号及密码模块显示
struct account* Select_DeleteNumPassMenu(struct account* ahead);
//二级菜单：修改账号及密码模块显示
struct account* AccAlterMenu(struct account* ahead);
//二级菜单：查找账号及密码模块显示
struct account* Select_SeekNumPassMenu(struct account* phead);
//二级菜单：录入所有账号及密码模块显示
struct account* Select_EnterNumPassMenu(struct account* phead);
//二级菜单：输出所有账号及密码模块显示
void Select_OutNumPassMenu(struct account* phead);
//二级菜单：手动重新录入学生信息模块显示
//void Select_EnterStuInfoMenu(struct student* phead);

//文件相关函数 
//创建文件，并将现有的数据写入文件				
int CreateFile(struct student* phead);
//创建另存为其它文件名 
int CreateFileAs(struct student* phead);
//读取文件，并提取文件中的元素信息保存到学生结构体中				
struct student* ReadFromFile(FILE* fp, struct student* phead);
//将当前的学生信息写入文件 
struct student* WriteToFile(FILE* fp, struct student* phead);
//登陆
void land(struct student* phead); 
//读取账号文件 
struct account* AccReadFromFile (FILE* fp, struct account* ahead);
//存入文件
void outlink(struct account *ahead); 

//信息管理相关函数 
//添加学生信息 
int AddStudentInfo(struct student* phead, int*npStudentNum);
//输出学生信息				
void OutputStudentInfo(struct student* phead);
// 删除1个学生信息,返回正常删除了，还是没有删除 
int DeleteStudentInfo(struct student* phead, char Num[10]); 
// 修改指定学生的成绩信息
struct student* Select_AlterMenu(struct student* phead);
// 查询指定学生的成绩信息
void SeekStudentScoreInfo(struct student* phead, char num[10]); 
// 输出全班学生成绩
void SeekAllStudentScoreInfo(struct student* phead, int nStudentNum);

//排序相关函数 
//按学号升序排序
void SortOnNumAs(struct student* phead,int nStudentNum);
//按全级总分升序排序
void ALLSortOnAllAs(struct student* phead);
//级名次存储 
struct student* ranking(struct student* phead);
//按全班总分升序排序
struct student* rank_class (struct student* phead);

//计算总分
void AllScore(struct student* phead);
//计算各科平均分
int AverageScore(struct student* phead, int nStudentNum);
//输出学生链表 
struct student* List(struct student* phead);
//打印账号链表 
struct account* AccList(struct account* ahead);
//查重 
int chachong(struct student* phead, char number[10]); 
int accchachong(struct account* ahead, char number[20]);
 

struct student* phead;//存储学生信息的链表 
struct account* ahead;//存储账号信息的链表 
int i;

int main() {
	system("color 3e");
	FILE *fp = fopen("studentlist(1).txt", "r");
	FILE *ap = fopen("add.txt", "r");
	if (fp == NULL) {//若数据文件不存在，新建数据文件
		printf("文件不存在\n");	
	}else /*读取现有数据文件信息*/ {	
		phead = (struct student*) malloc (sizeof(struct student));
		phead = ReadFromFile(fp, phead);//读取学生信息 
		ahead = (struct account*) malloc (sizeof(struct account));
		ahead = AccReadFromFile (ap, ahead);//读取账号信息
	}//关闭文件
	fclose(fp);
	fclose(ap);
	ranking(phead);
	rank_class (phead);
	land(phead);
} 
struct student* ReadFromFile (FILE* fp, struct student* phead) {//读取文件 
	struct student *pnew, *p1;
	//p1 = (struct student*) malloc (sizeof(struct student));
	p1 = phead;
	while (!feof(fp)){
		pnew = (struct student*) malloc (sizeof(struct student));
		fscanf(fp, "%s%s", pnew -> name, pnew -> number);
		fscanf(fp, "%s%d%d%d", pnew -> grade, &pnew -> score1, &pnew -> score2, &pnew -> score3);
		pnew -> allscore = pnew -> score1 + pnew -> score2 + pnew -> score3; 
		pnew -> next = NULL;
    	p1 -> next = pnew;  //p1随pnew变化 
    	p1 = pnew;  //将当前的新结点定义为表尾终端节点
	}
	return phead;
}
struct account* AccReadFromFile (FILE* ap, struct account* ahead) {//读取账号文件 
	int i;
	struct account *pnew, *p1;
	p1 = ahead;
	while (!feof(ap)){
		pnew = (struct account*) malloc (sizeof(struct account));
		fscanf(ap, "%s%s", pnew -> number, pnew -> pass);
		pnew -> next = NULL;
    	p1 -> next = pnew;  //p1随pnew变化 
    	p1 = pnew;  //将当前的新结点定义为表尾终端节点
	}
	return ahead;
}
void Select_MainMenu(struct student* phead) {//主菜单页面 
	int nMainchoose;
	while(1) {

		printf("\t----------------------------------------------------------------------------------------  \n");
		printf("\t*                                          学生成绩管理系统                             *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                        1.学生登陆                              2.教师登陆             *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                        3.管理员登陆                            4.账号注册             *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                        5.密码修改                              6.退出系统             *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t---------------------------------------------------------------------------------------   \n");
		//printf("\n\t数据文件%s中目前共有%d名学生 \n\n",studentlist(1),*npStudentNum);
		printf("\t\t   请选择功能序号(1~6):");
	    scanf("%d", &nMainchoose);//用户根据界面提示输入数字 
	    system("cls");
	    while(nMainchoose)
		switch (nMainchoose) {
			case 1: Select_StuMainMenu(phead);//转到学生端主菜单选项显示 
			        break;
			case 2: Select_TeaMainMenu(phead);//转到教师端主菜单选项显示 
					break;
			case 3: Select_ManMainMenu(phead);//转到管理员端主菜单选项显示
					break;
			case 4: Select_AddNumPassMenu(ahead);//账号注册 
					break;
			case 5: AccAlterMenu(ahead);//密码修改 
					break;			
			case 6: printf("\n\n\t\t感谢使用我们的软件，欢迎下次再来！") ;
			        exit(0);
					break; 
			default:printf("选择有误，请重选！\n");
		}//switch结束 
	}//while(1)函数结束 
}//Select_MainMenu函数结束
void Select_StuMainMenu(struct student* phead) {//学生端页面 
	int nStuMainchoose, cclass;
	char num[6], pass[8];
	printf("请输入学号\n");
	fflush(stdin);
	gets(num);
	while(1) {
		struct student *p1 = phead -> next;
		while (p1 != NULL) {
			if(!strcmp(p1 -> number, num)) {
				break;
			}
			p1 = p1 -> next;
		}
		if(p1 == NULL) {
			printf("请输入正确的学号!\n");
			fflush(stdin);
			gets(num);
		} else {
			break;
		}
	}
	fflush(stdin);
	system("cls");
	while(1) {
		printf("\t----------------------------------------------------------------------------------------  \n");
		printf("\t*                                          学生成绩管理系统                             *\n");
		printf("\t*                                              学生端                                   *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                        1.成绩查询                              2.查询本班成绩         *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                        3.成绩分析                              4.返回上一层           *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                        5.退出                                                         *\n");
		printf("\t*                                                                                       *\n");
		printf("\t---------------------------------------------------------------------------------------   \n");
		printf("\t\t   请选择功能序号(1~5):\n");
	   	scanf("%d", &nStuMainchoose);//用户根据界面提示输入数字 
		system("cls");
		switch (nStuMainchoose) {
			case 1: SeekStudentScoreInfo(phead, num);//转到学生成绩查询, num为学号
			        break;
			case 2: printf("请输入需要查询的班级(1~5)：\n");
					scanf("%d", &cclass);
					while (cclass < 0 || cclass > 5) {
						printf("请输入正确的班级！\n");
						printf("请输入需要查询的班级(1~5)：\n");
						scanf("%d", &cclass);
					}
					SeekAllStudentScoreInfo(phead, cclass * 31);
					break;
			case 3: Select_ScoreAnalysisMenu(phead, num);//转到成绩分析模块显示，num为学号 
					break;
			case 4: Select_MainMenu(phead);
					break;	
			case 5: printf("\n\n\t\t感谢使用我们的软件，欢迎下次再来！") ;
		    	    exit(0);
					break; 
			default:printf("选择有误，请重选！\n");
		}//switch结束 
		system("cls");
	}
}//Select_StuMainMenu函数结束
void Select_TeaMainMenu(struct student* phead) {//教师端页面 
	int nTeaMainchoose;
	while(1) {

		printf("\t----------------------------------------------------------------------------------------  \n");
		printf("\t*                                          学生成绩管理系统                             *\n");
		printf("\t*                                               教师端                                  *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     1.增加新的学生信息                      2.删除学生信息            *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     3.修改学生信息                          4.查询学生信息            *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     5.输出本班成绩                          6.下载到文件中            *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     7.成绩分析                              8.返回上一层              *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     9.退出系统                                                        *\n");
		printf("\t---------------------------------------------------------------------------------------   \n");
		printf("\t\t   请选择功能序号(1~9):");
		
	    scanf("%d", &nTeaMainchoose);//用户根据界面提示输入数字 
	    system("cls");
	    int num;
		switch (nTeaMainchoose) {
			case 1: Select_AddStudentMenu(phead);//转到增加新的学生信息模块显示 
			        break;
			case 2: Select_DeleteMenu(phead);//删除学生信息模块显示
					break;
			case 3: Select_AlterMenu(phead);//修改学生信息模块显示
					break;
			case 4: Select_QueryMenu(phead);//查询学生信息模块显示
					break;
			case 5: printf("请输入需要查询的班级(1~5)：\n");
					scanf("%d", &num);
					while (num < 0 || num > 5) {
						printf("请输入正确的班级！\n");
						printf("请输入需要查询的班级(1~5)：\n");
						scanf("%d", &num);
					}
					system("pause");
					SeekAllStudentScoreInfo(phead, num * 31);
					break;		
			case 6: Select_DownloadMenu(phead);//下载文件模块显示
					break;		
			case 7: Select_ScoreAnalysisMenu(phead);//成绩分析模块显示
					break;
			case 8: Select_MainMenu(phead);//返回上一层 
					break;	
			case 9: printf("\n\n\t\t感谢使用我们的软件，欢迎下次再来！") ;
			        exit(0);
					break; 
			default:printf("选择有误，请重选！\n");
		}//switch结束 
	}//while(1)函数结束 
}//Select_MainMenu函数结束
void Select_ManMainMenu(struct student* phead) {//管理员端页面 
	int nManMainchoose;
	while(1) {

		printf("\t----------------------------------------------------------------------------------------  \n");
		printf("\t*                                          学生成绩管理系统                             *\n");
		printf("\t*                                             管理员端                                  *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     1.查看代办选项                      2.进入教师端进行信息修改      *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     3.增加账号及密码                    4.删除账号及密码              *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     5.修改账号及密码                    6.查找账号及密码              *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     7.录入所有账号及密码                8.输出所有账号及密码          *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     9.返回上一层                        10.退出系统                   *\n");
		printf("\t---------------------------------------------------------------------------------------   \n");
		printf("\t\t   请选择功能序号(1~9):");
		
	    scanf("%d", &nManMainchoose);//用户根据界面提示输入数字 
	    system("cls");
	    int num;
		switch (nManMainchoose) {
			case 1: Select_DealMenu(phead); //进入代办选项模块显示
			        break;
			case 2: Select_TeaMainMenu(phead);//进入教师端进行信息修改模块显示
					break;
			case 3: Select_AddNumPassMenu(ahead);//增加账号及密码模块显示
					break;
			case 4: ahead = Select_DeleteNumPassMenu(ahead);//删除账号及密码模块显示
					break;
			case 5: ahead = AccAlterMenu(ahead);//修改账号及密码模块显示
					break;		
			case 6: Select_SeekNumPassMenu(ahead);//查找账号及密码模块显示
					break;		
			case 7: ahead = Select_EnterNumPassMenu(ahead);//录入所有账号及密码模块显示
					break;
			case 8: Select_OutNumPassMenu(ahead);//输出所有账号及密码模块显示
					break;
			case 9: Select_MainMenu(phead);//返回到主菜单 
					break;	
			case 10: printf("\n\n\t\t感谢使用我们的软件，欢迎下次再来！") ;
			        exit(0);
					break; 
			default:printf("选择有误，请重选！\n");
		}//switch结束 
	}//while(1)函数结束 
}//Select_MainMenu函数结束
void Select_DealMenu(struct student* phead) {//管理员端页面代办 
	int nDealMenuchoose;
	while(1) {

		printf("\t----------------------------------------------------------------------------------------  \n");
		printf("\t*                                          学生成绩管理系统                             *\n");
		printf("\t*                                           管理员端代办                                *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     1.密码注册                                2.密码修改              *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     3.返回上一层                              4.退出系统              *\n"); 
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t---------------------------------------------------------------------------------------   \n");
		printf("\t\t   请选择功能序号(1~4):");
		
	    scanf("%d", &nDealMenuchoose);//用户根据界面提示输入数字 
	    system("cls");
	    switch(nDealMenuchoose) {
	    	case 1: Select_AddNumPassMenu(ahead); break;//密码注册 
	    	case 2: AccAlterMenu(ahead); break;//密码修改 
	    	case 3: Select_ManMainMenu(phead); break;
			case 4: printf("\n\n\t\t感谢使用我们的软件，欢迎下次再来！") ;
			        exit(0);
					break; 
			default:printf("选择有误，请重选！\n");
		}
	} 
} 
void SeekAllStudentScoreInfo(struct student* phead, int num){//本班成绩输出 
	struct student *p1;
    p1 = phead;
    int i = 31;
    num -= 31;
    while (num--) {
    	p1 = p1 -> next;
	}
	p1 = p1 -> next;
	printf("姓名\t学号\t班级\t语文\t数学\t英语\t总分\t级名次\t班名次\n");
	while (i--) {
	    printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t", p1 -> name, p1 -> number, p1 -> grade, p1 -> score1, p1 -> score2, p1 -> score3, p1 -> allscore, p1 -> allranking, p1 -> banranking);
        printf("\n");
		p1 = p1 -> next;
    }
    system("pause");
    system("cls");
    Select_StuMainMenu(phead);
}
void SeekStudentScoreInfo(struct student* phead, char num[10]) {//学生成绩查询 
	struct student *p1;
	p1 = phead -> next;
	while (p1 != NULL) {
		if (!strcmp(p1 -> number, num)) {
			printf("语文\t 数学\t 英语\n");
			printf("%d\t%d\t%d\n", p1 -> score1, p1 -> score2, p1 -> score3);
			system("pause");
			break;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	system("cls");
	free(p1);
	return ;
}
int AllSortOnAllAs(struct student* phead,char num[10]) {//按全级总分排序
	int count = 1, score;
	struct student* p1;
	p1 = phead -> next;
	while (p1 != NULL) {
		if (!strcmp(p1 -> number, num)) {
			score = p1 -> allscore;
			break;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	p1 = phead -> next;
	while (p1 != NULL) {
		if ((p1 -> allscore) > score) {
			count++;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	return count;
}
int yibanSortOnAllAs(struct student* phead,char num[10]) {//一班总分排序
	int count = 1, score;
	struct student* p1;
	p1 = phead -> next;
	i = 31;
	while (i--) {
		if (!strcmp(p1 -> number, num)) {
			score = p1 -> allscore;
			break;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	p1 = phead -> next;
	i = 31;
	while (i--) {
		if ((p1 -> allscore) > score) {
			count++;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	return count;
}
int erbanSortOnAllAs(struct student* phead,char num[10]) {//二班总分排序
	int count = 1, score;
	struct student* p1;
	p1 = phead -> next;
	i = 31;
	while (i--) {
		p1 = p1 -> next;
	}
	i = 31;
	while (i--) {
		if (!strcmp(p1 -> number, num)) {
			score = p1 -> allscore;
			break;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	p1 = phead -> next;
	i = 31;
	while (i--) {
		if ((p1 -> allscore) > score) {
			count++;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	return count;
}
int sanbanSortOnAllAs(struct student* phead,char num[10]) {//三班总分排序
	int count = 1, score;
	struct student* p1;
	p1 = phead -> next;
	i = 62;
	while (i--) {
		p1 = p1 -> next;
	}
	i = 31;
	while (i--) {
		if (!strcmp(p1 -> number, num)) {
			score = p1 -> allscore;
			break;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	p1 = phead -> next;
	i = 31;
	while (i--) {
		if ((p1 -> allscore) > score) {
			count++;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	return count;
}
int sibanSortOnAllAs(struct student* phead,char num[10]) {//四班总分排序
	int count = 1, score;
	struct student* p1;
	p1 = phead -> next;
	i = 93;
	while (i--) {
		p1 = p1 -> next;
	}
	i = 31;
	while (i--) {
		if (!strcmp(p1 -> number, num)) {
			score = p1 -> allscore;
			break;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	p1 = phead -> next;
	i = 31;
	while (i--) {
		if ((p1 -> allscore) > score) {
			count++;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	return count;
}
int wubanSortOnAllAs(struct student* phead,char num[10]) {//五班总分排序
	int count = 1, score;
	struct student* p1;
	p1 = phead -> next;
	i = 124;
	while (i--) {
		p1 = p1 -> next;
	}
	i = 31;
	while (i--) {
		if (!strcmp(p1 -> number, num)) {
			score = p1 -> allscore;
			break;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	p1 = phead -> next;
	i = 31;
	while (i--) {
		if ((p1 -> allscore) > score) {
			count++;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	return count;
}
struct student* Select_AddStudentMenu(struct student* phead) {//增加新的学生信息
	struct student *pnew, *p1;
	FILE* fp;
	char name[20], number[20], grade[20], s1[10], s2[10], s3[10];
	int score1, score2, score3, flag;
	fp = fopen("studentlist(1).txt", "at+");
	printf("请输入要增加的学号：\n");
	while (1) {
		fflush(stdin);
		gets(number);
		if(!chachong(phead, number)) {		//没有重复的跳出 
			break;
		}
		printf("该学号已经存在请重新输入\n");
	}
	printf("请输入要增加的学生信息：\n");
	fflush(stdin);
	printf("姓名：\n");
	gets(name);
	fflush(stdin);
	system("cls");
	printf("班级：\n");
	gets(grade);
	fflush(stdin);
	system("cls");
	printf("语文成绩：\n");
	scanf("%d", &score1);
	while (score1 < 0 || score1 > 100) {
		printf("请输入0~100之间的成绩！\n");
		printf("请输入修改后语文成绩：\n");
		scanf("%d", &score1);
	}
	fflush(stdin);
	system("cls");
	printf("数学成绩：\n");
	scanf("%d", &score2);
	while (score2 < 0 || score2 > 100) {
		printf("请输入0~100之间的成绩！\n");
		printf("请输入修改后数学成绩：\n");
		scanf("%d", &score2);
	}
	fflush(stdin);
	system("cls");
	printf("英语成绩：\n");
	scanf("%d", &score3);
	while (score3 < 0 || score3 > 100) {
				printf("请输入0~100之间的成绩！\n");
				printf("请输入修改后英语成绩：\n");
				scanf("%d", &score3);
			}
	fflush(stdin);
	system("cls");
	fp = fopen("studentlist(1).txt", "at+");
	fprintf(fp, name);
	fprintf(fp, "\t");
	fprintf(fp, number);
	fprintf(fp, "\t");
	fprintf(fp, grade);
	fprintf(fp, "\t");
	sprintf(s1, "%d ", score1);
	fprintf(fp, s1);
	fprintf(fp, "\t");
	sprintf(s2, "%d ", score2);
	fprintf(fp, s2);
	fprintf(fp, "\t");
	sprintf(s3, "%d ", score3);
	fprintf(fp, s3);
	fprintf(fp, "\n");
	printf("加入成功！\n");
	fclose(fp);
    printf("加入后学生信息：\n");
    p1 = phead -> next;
    pnew = (struct student*)malloc(sizeof(struct student));//申请一个新节点 
	strcpy(pnew -> name, name);
	strcpy(pnew -> number, number);
	strcpy(pnew -> grade, grade);
	pnew -> score1 = score1;
	pnew -> score2 = score2;
	pnew -> score3 = score3;//输入新节点中的存储数值 
	phead -> next = pnew;
	pnew -> next = p1;
	List(phead);
	return phead;
}
struct student* Select_DeleteMenu(struct student* phead){//删除学生信息
	struct student *p1, *p2;
	char num[10];
	printf("请输入需要删除学生学号：");
	scanf("%s", num);
	system("cls");
	p1 = phead;
	p2 = p1 -> next;
	while (p2 != NULL) {
		if (!strcmp(p2 -> number, num)) {
			p1 -> next = p2 -> next;
			printf("已成功删除！\n");
			printf("删除后学生信息：\n");
			List(phead);
			return phead;
			break;
		} else {
			;
		}
		p1 = p2;
		p2 = p2 -> next;
	}
	if (p2 == NULL) {
		printf("查无此人，请重新输入！\n");
		system("pause");
		system("cls");
		struct student* Select_DeleteMenu(phead);
	} else {
		;
	}
}
void Select_ScoreAnalysisMenu(struct student* phead, char num[10]) {//成绩分析模块显示，num为学号
	system("cls");
	int allming, banming, n;
	struct student *p1;
	p1 = phead -> next;
	//printf("请输入您的班级:(1~5)\n");
	//scanf("%d", &n);
	//system("cls");
	//switch(n) {
	//	case 1: banming = yibanSortOnAllAs(phead, num); break;
	//	case 2: banming = erbanSortOnAllAs(phead, num); break;
	//	case 3: banming = sanbanSortOnAllAs(phead, num); break;
	//	case 4: banming = sibanSortOnAllAs(phead, num); break;
	//	case 5: banming = wubanSortOnAllAs(phead, num); break;
	//	default: printf("输入错误，请重新输入！\n");
	//			 Select_ScoreAnalysisMenu(phead, num); break;
	//}
	while (p1 != NULL) {
		if (strcmp(p1 -> number, num) == 0) {
			allming = AllSortOnAllAs(phead, num);
			printf("\n");
			printf("_________________________________________________________________________________________\n");
			printf("\n");
			printf("                                           学生管理系统                            \n");
			printf("\n");
			printf("*****************************************************************************************\n");
			printf("\n");
			printf("****************                        您为全级第%d名                       ***********\n", p1 -> allranking);
			printf("****************                        您为全班第%d名                        ***********\n", p1 -> banranking);
			printf("\n");
			printf("******************************************************************************************\n");
			system("pause");
			system("cls");
			Select_StuMainMenu(phead);
		} else {
			;
		}
		phead = p1;
		p1 = p1 -> next;
	}
	if (p1 == NULL) {
		printf("查无此人，请重新输入！\n");
		system("pause");
		system("cls");
		Select_StuMainMenu(phead);
	} else {
		;
	}
}
void Select_QueryMenu(struct student* phead){//查询学生成绩
	printf("请输入需要查询的学生学号：");
	char num[10];
	scanf("%s", num);
	struct student *p1;
	p1 = phead -> next;
	while (p1 != NULL) {
		if (!strcmp(p1 -> number, num)) {
			printf("该生语文成绩：%d 数学成绩：%d 英语成绩：%d", p1 -> score1, p1 -> score2, p1 -> score3);
			system("pause");
			system("cls");
			break;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	if (p1 == NULL) {
		printf("查无此人！请重新输入！\n");
		system("pause");
		system("cls");
		Select_QueryMenu(phead);
	} else {
		;
	}
	return ;
}
struct account* Select_AddNumPassMenu(struct account* ahead) {//增加账号及密码
	FILE *fp;
	struct account *p1 = ahead -> next;
	fp = fopen("add.txt", "at+");
	char number[20];
	char pass[10];
	char apass[10];
	int i;
	printf("您正在注册新的账号!\n");
	printf("请输入用户名：\n");
	while (1) {
		fflush(stdin);
		gets(number);
		if(!accchachong(ahead, number)) {		//没有重复的跳出 
			break;
		}
		printf("该账号已经存在请重新输入\n");
	}
	printf("请输入密码：(8位)\n");
	fflush(stdin);
	for (i = 0; i < 8; i++) {
		fflush(stdin);
		pass[i] = getch();
		printf("*");
	}
	pass[8] = '\0';
	system("cls");
	printf("\n");
	while(1) {
		printf("请再次输入密码：（8位）\n");
		for (i = 0; i < 8; i++) {
			fflush(stdin);
			apass[i] = getch();
			printf("*");
		}
		apass[8] = '\0';
		system("cls");
		if (!strcmp(apass, pass)) {
			fprintf(fp, number);
			fprintf(fp, "\t");
			fprintf(fp, pass);
			fprintf(fp, "\n");
			printf("注册成功！\n");
			fclose(fp);
			system("pause");
			system("cls");
			break;
		}
	} 
	return ahead;
}
void land(struct student* phead) {//登陆 
	FILE *fp1, *fp2;
	int i, flag = 0; 
	char number[10];//number为用户输入的用户名 
	char account[10];//account为文件中储存的用户名 
	char pass[10], apass[10];//pass为用户输入密码，apass为正确密码 
	fp1 = fopen("add.txt", "rt");
	fp2 = fopen("add.txt", "rt");
	if (fp1 == NULL || fp2 == NULL) {
		printf("文件无法打开！\n");
		exit(0);
	} else {
		printf("请输入用户名：\n");
		fflush(stdin);
		gets(number);
		system("cls");
		while (!feof(fp1)) {
			fscanf(fp1, "%s", account);
			if (strcmp(number, account) == 0) {//查看是否有该用户 
				flag = 1;
				break;
			} else {
				;
			}
		}
		if (!flag) {
			printf("该用户不存在！请注册!\n");
			system("pause");
			system("cls");
			Select_AddNumPassMenu(ahead);
		}
		flag = 0;
		printf("请输入密码：\n");
		for (i = 0; i < 8; i++) {
			fflush(stdin);
			pass[i] = getch();
			printf("*");
		}
		pass[8] = '\0';
		system("cls");
		while (!feof(fp2)) {
			fscanf(fp2, "%s %s",account, apass);
			if (strcmp(pass, apass) == 0 && strcmp(account, number) == 0) {
				printf("登陆成功！\n");
				system("pause");
				system("cls");
				flag = 1;
				Select_MainMenu(phead);
				break;
			} else {
				;
			}
		}
		if(!flag) {
			printf("用户名与密码不匹配！\n");
			system("pause");
			system("cls");
			land(phead);
		} else {
			;
		}
	}
	return ;
}
struct student* Select_AlterMenu(struct student* phead){//修改学生信息
	printf("请输入需要修改学生学号：\n");
	char num[6];
	int flag = 0;
	struct student* p1;
	p1 = phead -> next;
	fflush(stdin);

	for (i = 0; i < 5; i++) {
		num[i] = getchar();
	}
	num[5] = '\0';
	while(p1 != NULL) {
		if (!strcmp(num, p1 -> number)) {
			printf("该学生成绩为%d %d %d\n", p1 -> score1, p1 -> score2, p1 -> score3);
			printf("请输入修改后语文成绩：\n");
			scanf("%d", &p1 -> score1);
			while (p1 -> score1 < 0 || p1 -> score1 > 100) {
				printf("请输入0~100之间的成绩！\n");
				printf("请输入修改后语文成绩：\n");
				scanf("%d", &p1 -> score1);
			}
			printf("请输入修改后数学成绩：\n");
			scanf("%d", &p1 -> score2);
			while (p1 -> score2 < 0 || p1 -> score2 > 100) {
				printf("请输入0~100之间的成绩！\n");
				printf("请输入修改后数学成绩：\n");
				scanf("%d", &p1 -> score2);
			}
			printf("请输入修改后英语成绩：\n");
			scanf("%d", &p1 -> score3);
			while (p1 -> score1 < 0 || p1 -> score1 > 100) {
				printf("请输入0~100之间的成绩！\n");
				printf("请输入修改后英语成绩：\n");
				scanf("%d", &p1 -> score1);
			}
			system("pause");
			system("cls");
			printf("修改成功！\n");
			system("pause");
			system("cls");
			printf("修改后全级成绩：\n");
			List(phead);
			return phead;
			Select_TeaMainMenu(phead);
			flag = 1;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	if (!flag) {
		printf("查无此人，请重新输入！\n");
		system("pause");
		system("cls");
		Select_AlterMenu(phead);
	}
}
struct student* List(struct student* phead) { //打印学生链表 
    struct student *p1;
    p1 = phead -> next;
    printf("姓名\t学号\t班级\t语文\t数学\t英语\t级名\t班名\n");
    while (p1 -> next != NULL) {
    	printf("%s\t", p1 -> name);
    	printf("%s\t", p1 -> number);
    	printf("%s\t", p1 -> grade);
    	printf("%d\t", p1 -> score1);
    	printf("%d\t", p1 -> score2);
    	printf("%d\t", p1 -> score3);
    	printf("%d\t", p1 -> allranking);
    	printf("%d\n", p1 -> banranking);
        p1 = p1 -> next;
    }
    system("pause");
    system("cls");
}
void Select_DownloadMenu(struct student* phead) {//下载文件 
	struct student *p1 = phead -> next;
	char filename[50];
	printf("请输入文件名：\n");
	scanf("%s", filename);
	FILE *fp = fopen(filename, "w+");
	while(p1 != NULL){
		fprintf(fp, "%s %s %s %d %d %d %d\n", p1 -> name, p1 -> number, p1 -> grade, p1 -> score1, p1->score2, p1 -> score3, p1 -> allranking);
		p1 = p1 -> next;
	}
	printf("\n");
	printf("下载成功!\n");
	fclose(fp);
	system("pause");
	system("cls");
	return ;
}
void Select_ScoreAnalysisMenu(struct student* phead){//成绩分析模块显示

	printf("************************************************************************************\n");
	printf("\n");
	printf("************************************************************************************\n");
	printf("\n");
	printf("                                     全级学生成绩及名次：\n");
	printf("\n");
	List(phead); 
	printf("************************************************************************************\n");
	return ;
}
struct student* ranking(struct student* phead) {//全级名次存储 
	struct student *p1;
	p1 = phead -> next;
	while (p1 != NULL) {
		p1 -> allranking = AllSortOnAllAs(phead, p1 -> number);
		p1 = p1 -> next; 
	}
	free(p1);
	return phead;
}
struct student* rank_class (struct student* phead) {//全班名次存储 
	int count = 0;
	int score;
	struct student *p, *q;
	p = phead -> next;
	while (p -> next) {
		score = p -> allscore;
		count = 0;
		q = phead -> next;
		while (q -> next) {
			if(!strcmp(p -> grade, q -> grade)) {
				if(q -> allscore > score) {		//遍历每个结点，比较大小 
				count++;					//记录count的值 
				}
			}
			q = q -> next;
		}
		p -> banranking = count + 1;				//count+1的值即为排名 
		p = p -> next;
	}
}
struct account* Select_DeleteNumPassMenu(struct account* ahead) {//删除账号及密码 
	FILE *ap1, *ap2;
	struct account *p1, *p2;
	int i, flag = 0; 
	char number[10];//number为用户输入的用户名 
	char account[10];//account为文件中储存的用户名 
	char pass[10], apass[10];//pass为用户输入密码，apass为正确密码 
	ap1 = fopen("add.txt", "rt");
	ap2 = fopen("add.txt", "rt");
	if (ap1 == NULL || ap2 == NULL) {
		printf("文件无法打开！\n");
		exit(0);
	} else {
		printf("请输入需要删除的用户名：\n");
		fflush(stdin);
		gets(number);
		system("cls");
		while (!feof(ap1)) {
			fscanf(ap1, "%s", account);
			if (strcmp(number, account) == 0) {//查看是否有该用户 
				flag = 1;
				break;
			} else {
				;
			}
		}
		if (!flag) {
			printf("该用户不存在！请重新输入!\n");
			system("pause");
			system("cls");
			Select_DeleteNumPassMenu(ahead);
		}
		flag = 0;
		printf("请输入密码：\n");
		for (i = 0; i < 8; i++) {
			fflush(stdin);
			pass[i] = getch();
			printf("*");
		}
		pass[8] = '\0';
		system("cls");
		while (!feof(ap2)) {
			fscanf(ap2, "%s %s",account, apass);
			if (strcmp(pass, apass) == 0 && strcmp(account, number) == 0) {
				printf("确认无误！\n");
				system("pause");
				system("cls");
				p1 = ahead;
				p2 = p1 -> next;
				while (p2 != NULL) {
					if (!strcmp(p2 -> number, number)) {
							p1 -> next = p2 -> next;
							printf("已成功删除！\n");
							printf("删除后账号及密码：\n");
							AccList(ahead);
							outlink(ahead);
							flag = 1;
							break;
					} else {
						;
					}
					p1 = p2;
					p2 = p2 -> next;
				}
			}
		}
		if(!flag) {
				printf("用户名与密码不匹配！将返回管理员端页面\n");
				system("pause");
				system("cls");
				Select_ManMainMenu(phead);
			} else {
				;
			}
	}
	return ahead;
}
struct account* AccList(struct account* ahead) { //打印账号链表 
    struct account *p1;
    p1 = ahead -> next;
    printf("账号\t密码\n");
    while (p1 -> next != NULL) {
    	printf("%s\t", p1 -> number);
    	printf("%s\n", p1 -> pass);
        p1 = p1 -> next;
    }
    system("pause");
    system("cls");
    return ahead;
}
struct account* AccAlterMenu(struct account* ahead){//修改账号信息
	printf("请输入需要修改的用户名：\n");
	char num[20], pass[20], apass[20], opass[20];
	int flag = 0;
	struct account* p1;
	p1 = ahead -> next;
	fflush(stdin);
	gets(num);
	printf("请输入密码：\n");
	for (i = 0; i < 8; i++) {
		opass[i] = getch();
		printf("*");
	}
	while(p1) {
		if (!strcmp(num, p1 -> number)) {
			flag = 1;
			if(!strcmp(opass, p1 -> pass)) {
				printf("确认无误！\n");
				while(p1 != NULL) {
					if (!strcmp(num, p1 -> number)) {
						printf("请输入修改后八位密码：\n");
						for (i = 0; i < 8; i++) {
						pass[i] = getch();
						printf("*");
						}
						pass[8] = '\0';
						printf("\n");
						printf("请再确认一次密码：\n");
						for (i = 0; i < 8; i++) {
							apass[i] = getch();
							printf("*");
						}
						apass[8] = '\0';
						if(!strcmp(pass, apass)) {
							strcpy(p1 -> pass, pass);
						} else {
							printf("密码有误：\n");
							system("pause");
							system("cls");
							AccAlterMenu(ahead);
						}
					}
				}
			} else{
				printf("\n密码错误！将返回管理员端页面\n");
				system("pause"); 
				system("cls");
				Select_ManMainMenu(phead);
				break;
			}
		} else {
			;
		}
		p1 = p1 -> next;
	}
	if (!flag) {
		printf("\n");
		printf("没有这个用户名，请重新输入！\n");
		system("pause");
		system("cls");
		AccAlterMenu(ahead);
	}
	system("cls");
	printf("修改后账号及密码：\n");
	AccList(ahead);
	outlink(ahead);
	Select_ManMainMenu(phead);
	return ahead;
}
struct account* Select_SeekNumPassMenu(struct account* ahead){//查找账号及密码 
	struct account *p1;
	char num[10];
	printf("请输入您要查找的账号：\n");
	fflush(stdin);
	gets(num);
	p1 = ahead -> next;
	while(p1 != NULL) {
		if(!strcmp(num, p1 -> number)) {
			printf("账号\t密码\n");
			printf("%s\t%s\n", p1 -> number, p1 -> pass);
			break;
		}
		p1 = p1 -> next;
	}
	if(p1 == NULL) {
		printf("没有此账号，请核对后输入\n");
		system("pause");
		system("cls");
		Select_SeekNumPassMenu(ahead);
	} 
	system("pause");
	system("cls");
	return ahead;
}
struct account* Select_EnterNumPassMenu(struct account* ahead) {//录入所有账号及密码 
	struct account *p1, *p2;
	int n, j;
	p1 = ahead -> next;
	while(p1 != NULL) {
		p1 = p1 -> next;
	}
	printf("您正在录入账号及密码\n");
	printf("请输入您需要录入的用户个数：\n");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		Select_AddNumPassMenu(ahead);
	}
	system("cls");
	outlink(ahead);
	return ahead;
}
void Select_OutNumPassMenu(struct account* ahead) {//输出所有账号及密码 
	struct account *p1;
	p1 = ahead -> next;
	printf("账号\t密码\n");
	while(p1 != NULL) {
		printf("%s\t %s\n", p1 -> number, p1 -> pass);
		p1 = p1 -> next;
	}
	p1 = NULL;
	system("pause");
	system("cls");
	Select_ManMainMenu(phead);
	return ;
}
int chachong(struct student* phead, char number[20]) {//学生查重 
	struct student *p1;
	p1 = phead -> next;
	while (p1) {
		if (!strcmp(p1 -> number, number)) {
			return 1;
			break;
		}
		p1 = p1 -> next;
	}
	return 0;
}
int accchachong(struct account* ahead, char number[20]) {//账号查重 
	struct account *p1;
	p1 = ahead -> next;
	while (p1) {
		if (!strcmp(p1 -> number, number)) {
			return 1;
			break;
		}
		p1 = p1 -> next;
	}
	return 0;
}
void outlink(struct account *ahead) {//保存文件 
	struct account *p = ahead -> next;
	char filename[20];
	printf("请输入保存文件名：\n");
	scanf("%s", filename);
	FILE *fp = fopen(filename,"w");
	if(fp == NULL) {
	printf("打开文件失败!");
	return ;
	}
	while(p) {
		fprintf(fp, "%s ", p -> number);
		fprintf(fp, "%s ", p -> pass);
		p = p -> next;
	}
	fclose(fp);
	return;
}
