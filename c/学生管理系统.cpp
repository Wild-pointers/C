
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

#define NAME 20//���ֳ��� 
#define GRADE 20//�༶���� 

//ѧ���ṹ�嶨��
struct student{
	char name[NAME];
	char number[20];
	char grade[GRADE];
	int score1;
	int score2;
	int score3;
	int allscore;
	int allranking;//ȫ������
	int banranking;//ȫ������ 
	struct student *next; 
}; 
//�˺Žṹ�嶨�� 
struct account{
	char number[200];
	char pass[200];
	struct account *next;
};

/*��������*/
//һ�����˵�ѡ����ʾ 
void Select_MainMenu(struct student* phead);
//����ע��
int Secret_Build(struct student* phead);
//�����޸�
int Secret_Alter(struct student* phead); 
//ѧ���˲˵���غ���
//ѧ�������˵�ѡ����ʾ
void Select_StuMainMenu(struct student* phead);
//�����˵����ɼ���ѯģ����ʾ 
void Select_ScoreMenu(struct student* phead);
//�����˵�����ѯ����ɼ�ģ����ʾ
void Select_AllScoreMenu(struct student* phead);
//�����˵����ɼ�����ģ����ʾ
void Select_ScoreAnalysisMenu(struct student* phead, char num[10]);
//��ʦ�˲˵���غ���
//��ʦ�����˵�ѡ����ʾ
void Select_TeaMainMenu(struct student* phead); 
//�����˵��������µ�ѧ����Ϣģ����ʾ
struct student* Select_AddStudentMenu(struct student* phead);
//�����˵���ɾ��ѧ����Ϣģ����ʾ
struct student* Select_DeleteMenu(struct student* phead);
//�����˵����޸�ѧ����Ϣģ����ʾ
struct student* Select_AlterMenu(struct student* phead);
//�����˵�����ѯѧ����Ϣģ����ʾ
void Select_QueryMenu(struct student* phead);
//�����˵����������ɼ�ģ����ʾ
void Select_OutputMenu(struct student* phead);
//�����˵��������ļ�ģ����ʾ
void Select_DownloadMenu(struct student* phead);
//�����˵����ɼ�����ģ����ʾ
void Select_ScoreAnalysisMenu(struct student* phead);
//����Ա�˵���غ���
//����Ա���˵�ѡ����ʾ
void Select_ManMainMenu(struct student* phead); 
//�����˵����������ѡ��ģ����ʾ
void Select_DealMenu(struct student* phead);
//�����˵�������ע��ģ����ʾ
void Select_PasswordReMenu(struct student* phead);
//�����˵��������޸�ģ����ʾ
void Select_PasswordAlMenu(struct student* phead);
//�����˵������³ɼ���ģ����ʾ
void Select_RenewScoreMenu(struct student* phead);
//�����˵��������ʦ�˽�����Ϣ�޸�ģ����ʾ
void Select_InTeaAlInfoMenu(struct student* phead);
//�����˵��������˺ż�����ģ����ʾ
struct account* Select_AddNumPassMenu(struct account* ahead);
//�����˵���ɾ���˺ż�����ģ����ʾ
struct account* Select_DeleteNumPassMenu(struct account* ahead);
//�����˵����޸��˺ż�����ģ����ʾ
struct account* AccAlterMenu(struct account* ahead);
//�����˵��������˺ż�����ģ����ʾ
struct account* Select_SeekNumPassMenu(struct account* phead);
//�����˵���¼�������˺ż�����ģ����ʾ
struct account* Select_EnterNumPassMenu(struct account* phead);
//�����˵�����������˺ż�����ģ����ʾ
void Select_OutNumPassMenu(struct account* phead);
//�����˵����ֶ�����¼��ѧ����Ϣģ����ʾ
//void Select_EnterStuInfoMenu(struct student* phead);

//�ļ���غ��� 
//�����ļ����������е�����д���ļ�				
int CreateFile(struct student* phead);
//�������Ϊ�����ļ��� 
int CreateFileAs(struct student* phead);
//��ȡ�ļ�������ȡ�ļ��е�Ԫ����Ϣ���浽ѧ���ṹ����				
struct student* ReadFromFile(FILE* fp, struct student* phead);
//����ǰ��ѧ����Ϣд���ļ� 
struct student* WriteToFile(FILE* fp, struct student* phead);
//��½
void land(struct student* phead); 
//��ȡ�˺��ļ� 
struct account* AccReadFromFile (FILE* fp, struct account* ahead);
//�����ļ�
void outlink(struct account *ahead); 

//��Ϣ������غ��� 
//���ѧ����Ϣ 
int AddStudentInfo(struct student* phead, int*npStudentNum);
//���ѧ����Ϣ				
void OutputStudentInfo(struct student* phead);
// ɾ��1��ѧ����Ϣ,��������ɾ���ˣ�����û��ɾ�� 
int DeleteStudentInfo(struct student* phead, char Num[10]); 
// �޸�ָ��ѧ���ĳɼ���Ϣ
struct student* Select_AlterMenu(struct student* phead);
// ��ѯָ��ѧ���ĳɼ���Ϣ
void SeekStudentScoreInfo(struct student* phead, char num[10]); 
// ���ȫ��ѧ���ɼ�
void SeekAllStudentScoreInfo(struct student* phead, int nStudentNum);

//������غ��� 
//��ѧ����������
void SortOnNumAs(struct student* phead,int nStudentNum);
//��ȫ���ܷ���������
void ALLSortOnAllAs(struct student* phead);
//�����δ洢 
struct student* ranking(struct student* phead);
//��ȫ���ܷ���������
struct student* rank_class (struct student* phead);

//�����ܷ�
void AllScore(struct student* phead);
//�������ƽ����
int AverageScore(struct student* phead, int nStudentNum);
//���ѧ������ 
struct student* List(struct student* phead);
//��ӡ�˺����� 
struct account* AccList(struct account* ahead);
//���� 
int chachong(struct student* phead, char number[10]); 
int accchachong(struct account* ahead, char number[20]);
 

struct student* phead;//�洢ѧ����Ϣ������ 
struct account* ahead;//�洢�˺���Ϣ������ 
int i;

int main() {
	system("color 3e");
	FILE *fp = fopen("studentlist(1).txt", "r");
	FILE *ap = fopen("add.txt", "r");
	if (fp == NULL) {//�������ļ������ڣ��½������ļ�
		printf("�ļ�������\n");	
	}else /*��ȡ���������ļ���Ϣ*/ {	
		phead = (struct student*) malloc (sizeof(struct student));
		phead = ReadFromFile(fp, phead);//��ȡѧ����Ϣ 
		ahead = (struct account*) malloc (sizeof(struct account));
		ahead = AccReadFromFile (ap, ahead);//��ȡ�˺���Ϣ
	}//�ر��ļ�
	fclose(fp);
	fclose(ap);
	ranking(phead);
	rank_class (phead);
	land(phead);
} 
struct student* ReadFromFile (FILE* fp, struct student* phead) {//��ȡ�ļ� 
	struct student *pnew, *p1;
	//p1 = (struct student*) malloc (sizeof(struct student));
	p1 = phead;
	while (!feof(fp)){
		pnew = (struct student*) malloc (sizeof(struct student));
		fscanf(fp, "%s%s", pnew -> name, pnew -> number);
		fscanf(fp, "%s%d%d%d", pnew -> grade, &pnew -> score1, &pnew -> score2, &pnew -> score3);
		pnew -> allscore = pnew -> score1 + pnew -> score2 + pnew -> score3; 
		pnew -> next = NULL;
    	p1 -> next = pnew;  //p1��pnew�仯 
    	p1 = pnew;  //����ǰ���½�㶨��Ϊ��β�ն˽ڵ�
	}
	return phead;
}
struct account* AccReadFromFile (FILE* ap, struct account* ahead) {//��ȡ�˺��ļ� 
	int i;
	struct account *pnew, *p1;
	p1 = ahead;
	while (!feof(ap)){
		pnew = (struct account*) malloc (sizeof(struct account));
		fscanf(ap, "%s%s", pnew -> number, pnew -> pass);
		pnew -> next = NULL;
    	p1 -> next = pnew;  //p1��pnew�仯 
    	p1 = pnew;  //����ǰ���½�㶨��Ϊ��β�ն˽ڵ�
	}
	return ahead;
}
void Select_MainMenu(struct student* phead) {//���˵�ҳ�� 
	int nMainchoose;
	while(1) {

		printf("\t----------------------------------------------------------------------------------------  \n");
		printf("\t*                                          ѧ���ɼ�����ϵͳ                             *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                        1.ѧ����½                              2.��ʦ��½             *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                        3.����Ա��½                            4.�˺�ע��             *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                        5.�����޸�                              6.�˳�ϵͳ             *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t---------------------------------------------------------------------------------------   \n");
		//printf("\n\t�����ļ�%s��Ŀǰ����%d��ѧ�� \n\n",studentlist(1),*npStudentNum);
		printf("\t\t   ��ѡ�������(1~6):");
	    scanf("%d", &nMainchoose);//�û����ݽ�����ʾ�������� 
	    system("cls");
	    while(nMainchoose)
		switch (nMainchoose) {
			case 1: Select_StuMainMenu(phead);//ת��ѧ�������˵�ѡ����ʾ 
			        break;
			case 2: Select_TeaMainMenu(phead);//ת����ʦ�����˵�ѡ����ʾ 
					break;
			case 3: Select_ManMainMenu(phead);//ת������Ա�����˵�ѡ����ʾ
					break;
			case 4: Select_AddNumPassMenu(ahead);//�˺�ע�� 
					break;
			case 5: AccAlterMenu(ahead);//�����޸� 
					break;			
			case 6: printf("\n\n\t\t��лʹ�����ǵ��������ӭ�´�������") ;
			        exit(0);
					break; 
			default:printf("ѡ����������ѡ��\n");
		}//switch���� 
	}//while(1)�������� 
}//Select_MainMenu��������
void Select_StuMainMenu(struct student* phead) {//ѧ����ҳ�� 
	int nStuMainchoose, cclass;
	char num[6], pass[8];
	printf("������ѧ��\n");
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
			printf("��������ȷ��ѧ��!\n");
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
		printf("\t*                                          ѧ���ɼ�����ϵͳ                             *\n");
		printf("\t*                                              ѧ����                                   *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                        1.�ɼ���ѯ                              2.��ѯ����ɼ�         *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                        3.�ɼ�����                              4.������һ��           *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                        5.�˳�                                                         *\n");
		printf("\t*                                                                                       *\n");
		printf("\t---------------------------------------------------------------------------------------   \n");
		printf("\t\t   ��ѡ�������(1~5):\n");
	   	scanf("%d", &nStuMainchoose);//�û����ݽ�����ʾ�������� 
		system("cls");
		switch (nStuMainchoose) {
			case 1: SeekStudentScoreInfo(phead, num);//ת��ѧ���ɼ���ѯ, numΪѧ��
			        break;
			case 2: printf("��������Ҫ��ѯ�İ༶(1~5)��\n");
					scanf("%d", &cclass);
					while (cclass < 0 || cclass > 5) {
						printf("��������ȷ�İ༶��\n");
						printf("��������Ҫ��ѯ�İ༶(1~5)��\n");
						scanf("%d", &cclass);
					}
					SeekAllStudentScoreInfo(phead, cclass * 31);
					break;
			case 3: Select_ScoreAnalysisMenu(phead, num);//ת���ɼ�����ģ����ʾ��numΪѧ�� 
					break;
			case 4: Select_MainMenu(phead);
					break;	
			case 5: printf("\n\n\t\t��лʹ�����ǵ��������ӭ�´�������") ;
		    	    exit(0);
					break; 
			default:printf("ѡ����������ѡ��\n");
		}//switch���� 
		system("cls");
	}
}//Select_StuMainMenu��������
void Select_TeaMainMenu(struct student* phead) {//��ʦ��ҳ�� 
	int nTeaMainchoose;
	while(1) {

		printf("\t----------------------------------------------------------------------------------------  \n");
		printf("\t*                                          ѧ���ɼ�����ϵͳ                             *\n");
		printf("\t*                                               ��ʦ��                                  *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     1.�����µ�ѧ����Ϣ                      2.ɾ��ѧ����Ϣ            *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     3.�޸�ѧ����Ϣ                          4.��ѯѧ����Ϣ            *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     5.�������ɼ�                          6.���ص��ļ���            *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     7.�ɼ�����                              8.������һ��              *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     9.�˳�ϵͳ                                                        *\n");
		printf("\t---------------------------------------------------------------------------------------   \n");
		printf("\t\t   ��ѡ�������(1~9):");
		
	    scanf("%d", &nTeaMainchoose);//�û����ݽ�����ʾ�������� 
	    system("cls");
	    int num;
		switch (nTeaMainchoose) {
			case 1: Select_AddStudentMenu(phead);//ת�������µ�ѧ����Ϣģ����ʾ 
			        break;
			case 2: Select_DeleteMenu(phead);//ɾ��ѧ����Ϣģ����ʾ
					break;
			case 3: Select_AlterMenu(phead);//�޸�ѧ����Ϣģ����ʾ
					break;
			case 4: Select_QueryMenu(phead);//��ѯѧ����Ϣģ����ʾ
					break;
			case 5: printf("��������Ҫ��ѯ�İ༶(1~5)��\n");
					scanf("%d", &num);
					while (num < 0 || num > 5) {
						printf("��������ȷ�İ༶��\n");
						printf("��������Ҫ��ѯ�İ༶(1~5)��\n");
						scanf("%d", &num);
					}
					system("pause");
					SeekAllStudentScoreInfo(phead, num * 31);
					break;		
			case 6: Select_DownloadMenu(phead);//�����ļ�ģ����ʾ
					break;		
			case 7: Select_ScoreAnalysisMenu(phead);//�ɼ�����ģ����ʾ
					break;
			case 8: Select_MainMenu(phead);//������һ�� 
					break;	
			case 9: printf("\n\n\t\t��лʹ�����ǵ��������ӭ�´�������") ;
			        exit(0);
					break; 
			default:printf("ѡ����������ѡ��\n");
		}//switch���� 
	}//while(1)�������� 
}//Select_MainMenu��������
void Select_ManMainMenu(struct student* phead) {//����Ա��ҳ�� 
	int nManMainchoose;
	while(1) {

		printf("\t----------------------------------------------------------------------------------------  \n");
		printf("\t*                                          ѧ���ɼ�����ϵͳ                             *\n");
		printf("\t*                                             ����Ա��                                  *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     1.�鿴����ѡ��                      2.�����ʦ�˽�����Ϣ�޸�      *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     3.�����˺ż�����                    4.ɾ���˺ż�����              *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     5.�޸��˺ż�����                    6.�����˺ż�����              *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     7.¼�������˺ż�����                8.��������˺ż�����          *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     9.������һ��                        10.�˳�ϵͳ                   *\n");
		printf("\t---------------------------------------------------------------------------------------   \n");
		printf("\t\t   ��ѡ�������(1~9):");
		
	    scanf("%d", &nManMainchoose);//�û����ݽ�����ʾ�������� 
	    system("cls");
	    int num;
		switch (nManMainchoose) {
			case 1: Select_DealMenu(phead); //�������ѡ��ģ����ʾ
			        break;
			case 2: Select_TeaMainMenu(phead);//�����ʦ�˽�����Ϣ�޸�ģ����ʾ
					break;
			case 3: Select_AddNumPassMenu(ahead);//�����˺ż�����ģ����ʾ
					break;
			case 4: ahead = Select_DeleteNumPassMenu(ahead);//ɾ���˺ż�����ģ����ʾ
					break;
			case 5: ahead = AccAlterMenu(ahead);//�޸��˺ż�����ģ����ʾ
					break;		
			case 6: Select_SeekNumPassMenu(ahead);//�����˺ż�����ģ����ʾ
					break;		
			case 7: ahead = Select_EnterNumPassMenu(ahead);//¼�������˺ż�����ģ����ʾ
					break;
			case 8: Select_OutNumPassMenu(ahead);//��������˺ż�����ģ����ʾ
					break;
			case 9: Select_MainMenu(phead);//���ص����˵� 
					break;	
			case 10: printf("\n\n\t\t��лʹ�����ǵ��������ӭ�´�������") ;
			        exit(0);
					break; 
			default:printf("ѡ����������ѡ��\n");
		}//switch���� 
	}//while(1)�������� 
}//Select_MainMenu��������
void Select_DealMenu(struct student* phead) {//����Ա��ҳ����� 
	int nDealMenuchoose;
	while(1) {

		printf("\t----------------------------------------------------------------------------------------  \n");
		printf("\t*                                          ѧ���ɼ�����ϵͳ                             *\n");
		printf("\t*                                           ����Ա�˴���                                *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     1.����ע��                                2.�����޸�              *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t*                     3.������һ��                              4.�˳�ϵͳ              *\n"); 
		printf("\t*                                                                                       *\n");
		printf("\t*                                                                                       *\n");
		printf("\t---------------------------------------------------------------------------------------   \n");
		printf("\t\t   ��ѡ�������(1~4):");
		
	    scanf("%d", &nDealMenuchoose);//�û����ݽ�����ʾ�������� 
	    system("cls");
	    switch(nDealMenuchoose) {
	    	case 1: Select_AddNumPassMenu(ahead); break;//����ע�� 
	    	case 2: AccAlterMenu(ahead); break;//�����޸� 
	    	case 3: Select_ManMainMenu(phead); break;
			case 4: printf("\n\n\t\t��лʹ�����ǵ��������ӭ�´�������") ;
			        exit(0);
					break; 
			default:printf("ѡ����������ѡ��\n");
		}
	} 
} 
void SeekAllStudentScoreInfo(struct student* phead, int num){//����ɼ���� 
	struct student *p1;
    p1 = phead;
    int i = 31;
    num -= 31;
    while (num--) {
    	p1 = p1 -> next;
	}
	p1 = p1 -> next;
	printf("����\tѧ��\t�༶\t����\t��ѧ\tӢ��\t�ܷ�\t������\t������\n");
	while (i--) {
	    printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t", p1 -> name, p1 -> number, p1 -> grade, p1 -> score1, p1 -> score2, p1 -> score3, p1 -> allscore, p1 -> allranking, p1 -> banranking);
        printf("\n");
		p1 = p1 -> next;
    }
    system("pause");
    system("cls");
    Select_StuMainMenu(phead);
}
void SeekStudentScoreInfo(struct student* phead, char num[10]) {//ѧ���ɼ���ѯ 
	struct student *p1;
	p1 = phead -> next;
	while (p1 != NULL) {
		if (!strcmp(p1 -> number, num)) {
			printf("����\t ��ѧ\t Ӣ��\n");
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
int AllSortOnAllAs(struct student* phead,char num[10]) {//��ȫ���ܷ�����
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
int yibanSortOnAllAs(struct student* phead,char num[10]) {//һ���ܷ�����
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
int erbanSortOnAllAs(struct student* phead,char num[10]) {//�����ܷ�����
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
int sanbanSortOnAllAs(struct student* phead,char num[10]) {//�����ܷ�����
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
int sibanSortOnAllAs(struct student* phead,char num[10]) {//�İ��ܷ�����
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
int wubanSortOnAllAs(struct student* phead,char num[10]) {//����ܷ�����
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
struct student* Select_AddStudentMenu(struct student* phead) {//�����µ�ѧ����Ϣ
	struct student *pnew, *p1;
	FILE* fp;
	char name[20], number[20], grade[20], s1[10], s2[10], s3[10];
	int score1, score2, score3, flag;
	fp = fopen("studentlist(1).txt", "at+");
	printf("������Ҫ���ӵ�ѧ�ţ�\n");
	while (1) {
		fflush(stdin);
		gets(number);
		if(!chachong(phead, number)) {		//û���ظ������� 
			break;
		}
		printf("��ѧ���Ѿ���������������\n");
	}
	printf("������Ҫ���ӵ�ѧ����Ϣ��\n");
	fflush(stdin);
	printf("������\n");
	gets(name);
	fflush(stdin);
	system("cls");
	printf("�༶��\n");
	gets(grade);
	fflush(stdin);
	system("cls");
	printf("���ĳɼ���\n");
	scanf("%d", &score1);
	while (score1 < 0 || score1 > 100) {
		printf("������0~100֮��ĳɼ���\n");
		printf("�������޸ĺ����ĳɼ���\n");
		scanf("%d", &score1);
	}
	fflush(stdin);
	system("cls");
	printf("��ѧ�ɼ���\n");
	scanf("%d", &score2);
	while (score2 < 0 || score2 > 100) {
		printf("������0~100֮��ĳɼ���\n");
		printf("�������޸ĺ���ѧ�ɼ���\n");
		scanf("%d", &score2);
	}
	fflush(stdin);
	system("cls");
	printf("Ӣ��ɼ���\n");
	scanf("%d", &score3);
	while (score3 < 0 || score3 > 100) {
				printf("������0~100֮��ĳɼ���\n");
				printf("�������޸ĺ�Ӣ��ɼ���\n");
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
	printf("����ɹ���\n");
	fclose(fp);
    printf("�����ѧ����Ϣ��\n");
    p1 = phead -> next;
    pnew = (struct student*)malloc(sizeof(struct student));//����һ���½ڵ� 
	strcpy(pnew -> name, name);
	strcpy(pnew -> number, number);
	strcpy(pnew -> grade, grade);
	pnew -> score1 = score1;
	pnew -> score2 = score2;
	pnew -> score3 = score3;//�����½ڵ��еĴ洢��ֵ 
	phead -> next = pnew;
	pnew -> next = p1;
	List(phead);
	return phead;
}
struct student* Select_DeleteMenu(struct student* phead){//ɾ��ѧ����Ϣ
	struct student *p1, *p2;
	char num[10];
	printf("��������Ҫɾ��ѧ��ѧ�ţ�");
	scanf("%s", num);
	system("cls");
	p1 = phead;
	p2 = p1 -> next;
	while (p2 != NULL) {
		if (!strcmp(p2 -> number, num)) {
			p1 -> next = p2 -> next;
			printf("�ѳɹ�ɾ����\n");
			printf("ɾ����ѧ����Ϣ��\n");
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
		printf("���޴��ˣ����������룡\n");
		system("pause");
		system("cls");
		struct student* Select_DeleteMenu(phead);
	} else {
		;
	}
}
void Select_ScoreAnalysisMenu(struct student* phead, char num[10]) {//�ɼ�����ģ����ʾ��numΪѧ��
	system("cls");
	int allming, banming, n;
	struct student *p1;
	p1 = phead -> next;
	//printf("���������İ༶:(1~5)\n");
	//scanf("%d", &n);
	//system("cls");
	//switch(n) {
	//	case 1: banming = yibanSortOnAllAs(phead, num); break;
	//	case 2: banming = erbanSortOnAllAs(phead, num); break;
	//	case 3: banming = sanbanSortOnAllAs(phead, num); break;
	//	case 4: banming = sibanSortOnAllAs(phead, num); break;
	//	case 5: banming = wubanSortOnAllAs(phead, num); break;
	//	default: printf("����������������룡\n");
	//			 Select_ScoreAnalysisMenu(phead, num); break;
	//}
	while (p1 != NULL) {
		if (strcmp(p1 -> number, num) == 0) {
			allming = AllSortOnAllAs(phead, num);
			printf("\n");
			printf("_________________________________________________________________________________________\n");
			printf("\n");
			printf("                                           ѧ������ϵͳ                            \n");
			printf("\n");
			printf("*****************************************************************************************\n");
			printf("\n");
			printf("****************                        ��Ϊȫ����%d��                       ***********\n", p1 -> allranking);
			printf("****************                        ��Ϊȫ���%d��                        ***********\n", p1 -> banranking);
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
		printf("���޴��ˣ����������룡\n");
		system("pause");
		system("cls");
		Select_StuMainMenu(phead);
	} else {
		;
	}
}
void Select_QueryMenu(struct student* phead){//��ѯѧ���ɼ�
	printf("��������Ҫ��ѯ��ѧ��ѧ�ţ�");
	char num[10];
	scanf("%s", num);
	struct student *p1;
	p1 = phead -> next;
	while (p1 != NULL) {
		if (!strcmp(p1 -> number, num)) {
			printf("�������ĳɼ���%d ��ѧ�ɼ���%d Ӣ��ɼ���%d", p1 -> score1, p1 -> score2, p1 -> score3);
			system("pause");
			system("cls");
			break;
		} else {
			;
		}
		p1 = p1 -> next;
	}
	if (p1 == NULL) {
		printf("���޴��ˣ����������룡\n");
		system("pause");
		system("cls");
		Select_QueryMenu(phead);
	} else {
		;
	}
	return ;
}
struct account* Select_AddNumPassMenu(struct account* ahead) {//�����˺ż�����
	FILE *fp;
	struct account *p1 = ahead -> next;
	fp = fopen("add.txt", "at+");
	char number[20];
	char pass[10];
	char apass[10];
	int i;
	printf("������ע���µ��˺�!\n");
	printf("�������û�����\n");
	while (1) {
		fflush(stdin);
		gets(number);
		if(!accchachong(ahead, number)) {		//û���ظ������� 
			break;
		}
		printf("���˺��Ѿ���������������\n");
	}
	printf("���������룺(8λ)\n");
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
		printf("���ٴ��������룺��8λ��\n");
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
			printf("ע��ɹ���\n");
			fclose(fp);
			system("pause");
			system("cls");
			break;
		}
	} 
	return ahead;
}
void land(struct student* phead) {//��½ 
	FILE *fp1, *fp2;
	int i, flag = 0; 
	char number[10];//numberΪ�û�������û��� 
	char account[10];//accountΪ�ļ��д�����û��� 
	char pass[10], apass[10];//passΪ�û��������룬apassΪ��ȷ���� 
	fp1 = fopen("add.txt", "rt");
	fp2 = fopen("add.txt", "rt");
	if (fp1 == NULL || fp2 == NULL) {
		printf("�ļ��޷��򿪣�\n");
		exit(0);
	} else {
		printf("�������û�����\n");
		fflush(stdin);
		gets(number);
		system("cls");
		while (!feof(fp1)) {
			fscanf(fp1, "%s", account);
			if (strcmp(number, account) == 0) {//�鿴�Ƿ��и��û� 
				flag = 1;
				break;
			} else {
				;
			}
		}
		if (!flag) {
			printf("���û������ڣ���ע��!\n");
			system("pause");
			system("cls");
			Select_AddNumPassMenu(ahead);
		}
		flag = 0;
		printf("���������룺\n");
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
				printf("��½�ɹ���\n");
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
			printf("�û��������벻ƥ�䣡\n");
			system("pause");
			system("cls");
			land(phead);
		} else {
			;
		}
	}
	return ;
}
struct student* Select_AlterMenu(struct student* phead){//�޸�ѧ����Ϣ
	printf("��������Ҫ�޸�ѧ��ѧ�ţ�\n");
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
			printf("��ѧ���ɼ�Ϊ%d %d %d\n", p1 -> score1, p1 -> score2, p1 -> score3);
			printf("�������޸ĺ����ĳɼ���\n");
			scanf("%d", &p1 -> score1);
			while (p1 -> score1 < 0 || p1 -> score1 > 100) {
				printf("������0~100֮��ĳɼ���\n");
				printf("�������޸ĺ����ĳɼ���\n");
				scanf("%d", &p1 -> score1);
			}
			printf("�������޸ĺ���ѧ�ɼ���\n");
			scanf("%d", &p1 -> score2);
			while (p1 -> score2 < 0 || p1 -> score2 > 100) {
				printf("������0~100֮��ĳɼ���\n");
				printf("�������޸ĺ���ѧ�ɼ���\n");
				scanf("%d", &p1 -> score2);
			}
			printf("�������޸ĺ�Ӣ��ɼ���\n");
			scanf("%d", &p1 -> score3);
			while (p1 -> score1 < 0 || p1 -> score1 > 100) {
				printf("������0~100֮��ĳɼ���\n");
				printf("�������޸ĺ�Ӣ��ɼ���\n");
				scanf("%d", &p1 -> score1);
			}
			system("pause");
			system("cls");
			printf("�޸ĳɹ���\n");
			system("pause");
			system("cls");
			printf("�޸ĺ�ȫ���ɼ���\n");
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
		printf("���޴��ˣ����������룡\n");
		system("pause");
		system("cls");
		Select_AlterMenu(phead);
	}
}
struct student* List(struct student* phead) { //��ӡѧ������ 
    struct student *p1;
    p1 = phead -> next;
    printf("����\tѧ��\t�༶\t����\t��ѧ\tӢ��\t����\t����\n");
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
void Select_DownloadMenu(struct student* phead) {//�����ļ� 
	struct student *p1 = phead -> next;
	char filename[50];
	printf("�������ļ�����\n");
	scanf("%s", filename);
	FILE *fp = fopen(filename, "w+");
	while(p1 != NULL){
		fprintf(fp, "%s %s %s %d %d %d %d\n", p1 -> name, p1 -> number, p1 -> grade, p1 -> score1, p1->score2, p1 -> score3, p1 -> allranking);
		p1 = p1 -> next;
	}
	printf("\n");
	printf("���سɹ�!\n");
	fclose(fp);
	system("pause");
	system("cls");
	return ;
}
void Select_ScoreAnalysisMenu(struct student* phead){//�ɼ�����ģ����ʾ

	printf("************************************************************************************\n");
	printf("\n");
	printf("************************************************************************************\n");
	printf("\n");
	printf("                                     ȫ��ѧ���ɼ������Σ�\n");
	printf("\n");
	List(phead); 
	printf("************************************************************************************\n");
	return ;
}
struct student* ranking(struct student* phead) {//ȫ�����δ洢 
	struct student *p1;
	p1 = phead -> next;
	while (p1 != NULL) {
		p1 -> allranking = AllSortOnAllAs(phead, p1 -> number);
		p1 = p1 -> next; 
	}
	free(p1);
	return phead;
}
struct student* rank_class (struct student* phead) {//ȫ�����δ洢 
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
				if(q -> allscore > score) {		//����ÿ����㣬�Ƚϴ�С 
				count++;					//��¼count��ֵ 
				}
			}
			q = q -> next;
		}
		p -> banranking = count + 1;				//count+1��ֵ��Ϊ���� 
		p = p -> next;
	}
}
struct account* Select_DeleteNumPassMenu(struct account* ahead) {//ɾ���˺ż����� 
	FILE *ap1, *ap2;
	struct account *p1, *p2;
	int i, flag = 0; 
	char number[10];//numberΪ�û�������û��� 
	char account[10];//accountΪ�ļ��д�����û��� 
	char pass[10], apass[10];//passΪ�û��������룬apassΪ��ȷ���� 
	ap1 = fopen("add.txt", "rt");
	ap2 = fopen("add.txt", "rt");
	if (ap1 == NULL || ap2 == NULL) {
		printf("�ļ��޷��򿪣�\n");
		exit(0);
	} else {
		printf("��������Ҫɾ�����û�����\n");
		fflush(stdin);
		gets(number);
		system("cls");
		while (!feof(ap1)) {
			fscanf(ap1, "%s", account);
			if (strcmp(number, account) == 0) {//�鿴�Ƿ��и��û� 
				flag = 1;
				break;
			} else {
				;
			}
		}
		if (!flag) {
			printf("���û������ڣ�����������!\n");
			system("pause");
			system("cls");
			Select_DeleteNumPassMenu(ahead);
		}
		flag = 0;
		printf("���������룺\n");
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
				printf("ȷ������\n");
				system("pause");
				system("cls");
				p1 = ahead;
				p2 = p1 -> next;
				while (p2 != NULL) {
					if (!strcmp(p2 -> number, number)) {
							p1 -> next = p2 -> next;
							printf("�ѳɹ�ɾ����\n");
							printf("ɾ�����˺ż����룺\n");
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
				printf("�û��������벻ƥ�䣡�����ع���Ա��ҳ��\n");
				system("pause");
				system("cls");
				Select_ManMainMenu(phead);
			} else {
				;
			}
	}
	return ahead;
}
struct account* AccList(struct account* ahead) { //��ӡ�˺����� 
    struct account *p1;
    p1 = ahead -> next;
    printf("�˺�\t����\n");
    while (p1 -> next != NULL) {
    	printf("%s\t", p1 -> number);
    	printf("%s\n", p1 -> pass);
        p1 = p1 -> next;
    }
    system("pause");
    system("cls");
    return ahead;
}
struct account* AccAlterMenu(struct account* ahead){//�޸��˺���Ϣ
	printf("��������Ҫ�޸ĵ��û�����\n");
	char num[20], pass[20], apass[20], opass[20];
	int flag = 0;
	struct account* p1;
	p1 = ahead -> next;
	fflush(stdin);
	gets(num);
	printf("���������룺\n");
	for (i = 0; i < 8; i++) {
		opass[i] = getch();
		printf("*");
	}
	while(p1) {
		if (!strcmp(num, p1 -> number)) {
			flag = 1;
			if(!strcmp(opass, p1 -> pass)) {
				printf("ȷ������\n");
				while(p1 != NULL) {
					if (!strcmp(num, p1 -> number)) {
						printf("�������޸ĺ��λ���룺\n");
						for (i = 0; i < 8; i++) {
						pass[i] = getch();
						printf("*");
						}
						pass[8] = '\0';
						printf("\n");
						printf("����ȷ��һ�����룺\n");
						for (i = 0; i < 8; i++) {
							apass[i] = getch();
							printf("*");
						}
						apass[8] = '\0';
						if(!strcmp(pass, apass)) {
							strcpy(p1 -> pass, pass);
						} else {
							printf("��������\n");
							system("pause");
							system("cls");
							AccAlterMenu(ahead);
						}
					}
				}
			} else{
				printf("\n������󣡽����ع���Ա��ҳ��\n");
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
		printf("û������û��������������룡\n");
		system("pause");
		system("cls");
		AccAlterMenu(ahead);
	}
	system("cls");
	printf("�޸ĺ��˺ż����룺\n");
	AccList(ahead);
	outlink(ahead);
	Select_ManMainMenu(phead);
	return ahead;
}
struct account* Select_SeekNumPassMenu(struct account* ahead){//�����˺ż����� 
	struct account *p1;
	char num[10];
	printf("��������Ҫ���ҵ��˺ţ�\n");
	fflush(stdin);
	gets(num);
	p1 = ahead -> next;
	while(p1 != NULL) {
		if(!strcmp(num, p1 -> number)) {
			printf("�˺�\t����\n");
			printf("%s\t%s\n", p1 -> number, p1 -> pass);
			break;
		}
		p1 = p1 -> next;
	}
	if(p1 == NULL) {
		printf("û�д��˺ţ���˶Ժ�����\n");
		system("pause");
		system("cls");
		Select_SeekNumPassMenu(ahead);
	} 
	system("pause");
	system("cls");
	return ahead;
}
struct account* Select_EnterNumPassMenu(struct account* ahead) {//¼�������˺ż����� 
	struct account *p1, *p2;
	int n, j;
	p1 = ahead -> next;
	while(p1 != NULL) {
		p1 = p1 -> next;
	}
	printf("������¼���˺ż�����\n");
	printf("����������Ҫ¼����û�������\n");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		Select_AddNumPassMenu(ahead);
	}
	system("cls");
	outlink(ahead);
	return ahead;
}
void Select_OutNumPassMenu(struct account* ahead) {//��������˺ż����� 
	struct account *p1;
	p1 = ahead -> next;
	printf("�˺�\t����\n");
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
int chachong(struct student* phead, char number[20]) {//ѧ������ 
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
int accchachong(struct account* ahead, char number[20]) {//�˺Ų��� 
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
void outlink(struct account *ahead) {//�����ļ� 
	struct account *p = ahead -> next;
	char filename[20];
	printf("�����뱣���ļ�����\n");
	scanf("%s", filename);
	FILE *fp = fopen(filename,"w");
	if(fp == NULL) {
	printf("���ļ�ʧ��!");
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
