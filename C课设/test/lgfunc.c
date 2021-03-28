
#include"lgfunc.h"
#include"mouse.h"
#include"hz.h"
#include"public.h"
#include"database.h"
#include<string.h>
/*********************************************
FUNCTION:inputadmin
***********************************************/
void inputadmin(char* id, int x1, int y1, int charnum, int color)//������ַ����������xy��������ַ����ƣ���������ɫ
{
	int k = 0;
	int i = 0;
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while (bioskey(1))
	{
		k = bioskey(0);//��
	}
	while (1)
	{

		t = bioskey(0);
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1 - 1, id + i);//���t�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��  
				break;
			}
		}
	}
}
/*********************************************
FUNCTION:inputpassword
DESCRIPTION���������ܣ������������Ҫ���ص���Ϣ
INPUT:id,x1,y1,charnum,color
RETURN:��
***********************************************/
void inputpassword(char* id, int x1, int y1, int charnum, int color)
{
	int k = 0;
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while (bioskey(1))
	{
		k = bioskey(0);//��
	}
	while (1)
	{
		t = bioskey(0);//��ȡ��ֵ
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//033��ʾEsc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1 + 4, "*");//���*�ַ�
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��
				break;
			}
		}
	}
}

///*********************************************
//FUNCTION:login_complete
//DESCRIPTION�������жϵ�¼��Ϣ�Ƿ�������ȫ����ȷ
//INPUT:u,p
//RETURN:1/0
//***********************************************/
int login_complete(char* u, char* p)
{
	int state1 = 1;//�Ƿ�����ı���
	int state2 = 1;
	while (1)
	{
		recoverhz(557, 150, BLACK);
		recoverhz(557, 190, BLACK);
		judge(u, &state1, 557, 150);
		judge(p, &state2, 557, 190);
		if (state1 == 1 || state2 == 1)
		{
			break;
		}
		else if (state1 == 0 && state2 == 0)
		{
			if (judge_rightpassword(u, p))
			{
				return 1;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}
/*********************************************
//FUNCTION:register_complete
//DESCRIPTION�������ж�ע����Ϣ�Ƿ�������ȫ����ȷ
//INPUT : u, p, cp, id, vc, rdvc, b, bp
//RETURN : 1 / 0
//* **********************************************/
int register_complete(char* u, char* p, char* cp, char* id,char* b)//rdvcΪrandomvc
{
	int i;
	int state = 0;
	int state1 = 1;
	int state2 = 1;
	int state3 = 1;
	int state4 = 1;
	while (1)
	{
		recoverhz(557, 105, BLACK);
		recoverhz(557, 145, BLACK);
		recoverhz(557, 185, BLACK);
		recoverhz(557, 225, BLACK);
		recoverhz(557, 265, BLACK);
		recoverhz(19, 190, BLACK);
		recoverhz(280, 440, BLACK);
		judge(id, &state, 557, 115);          //judge:δ�����state=1
		judge(b, &state, 557, 155);
		judge(u, &state, 557, 195);
		judge(p, &state, 557, 235);
		judge(cp, &state, 557, 275);
		if (state == 1)
		{
			break;
		}
		else if (state == 0)
		{
			if (!judge_sameuser(u, 1))          //  �����򷵻�0��δ��������1
			{
				state1 = checkright_user(u, 557, 185);
				state2 = checkright_password(p, 557, 225);
				state3 = checkright_confirmedpassword(p, cp, 557, 265);
				state4 = checkright_ID(id, 557, 105, 1);
				break;
			}
			else if (judge_sameuser(u, 2))//�˺�û������
			{
				puthz(20, 190, "���õ��˺�", 16, 17, RED);
				state1 = checkright_user(u, 557, 185);
				state2 = checkright_password(p, 557, 225);
				state3 = checkright_confirmedpassword(p, cp, 557, 265);
				state4 = checkright_ID(id, 557, 105, 1);
				if (state1 != 0 || state2 != 0 || state3 != 0 || state4 != 0 )
				{
					break;
				}
				else if (state1 == 0 && state2 == 0 && state3 == 0 && state4 == 0 )
				{
					input_database(u, id, p, b);
					//д�����ݿ�
					puthz(280, 440, "ע��ɹ�", 16, 17, RED);
					delay(2000);
 				return 1;//����
				}
			}
		}
	}
	return 0;
}

///*********************************************
//FUNCTION:judge_rightpassword
//DESCRIPTION���ж��˺ź������Ƿ�ƥ��
//	ƥ�����¼
//INPUT:name,id,pass,againpass
//RETURN:1/0
//***********************************************/
int judge_rightpassword(char* name, char* pass)
{
	long len;
	long i;
	long j;
	FILE* fp;
	USER* u;
	if ((fp = fopen("Database\\UserData.dat", "rb+")) == NULL)
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0L, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		 j = i * sizeof(USER);
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, j, SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(name, u->ID) == 0)//�˺�ƥ��
		{
			if (strcmp(pass, u->password) != 0)//���벻��
			{
				puthz(560, 190, "�������", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(pass, u->password)  == 0)//����ƥ��
			{
				puthz(290, 355, "��¼�ɹ�", 16, 17, RED);
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				delay(1000);
				if (fclose(fp) != 0)
				{
					printf("\n cannot close Database");
					delay(3000);
					exit(1);
				}
				return 1;
				//�л�����
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{
		puthz(560, 150, "�˻�δע��", 16, 17, RED);//�ߵ����һλ
	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database");
		delay(3000);
		exit(1);
	}
	return 0;
}

///*********************************************
//FUNCTION:input_database
//DESCRIPTION�����û�ע����߿�����Ϣд���ļ�
//INPUT:name,id,code,bank,bankcode
//RETURN:1/0
//***********************************************/
void input_database(char* name, char* id, char* code, char* bank)
{
	FILE* fp;
	USER* u;
	char n;
	if ((fp = fopen("Database\\UserData.dat", "wb+")) == NULL)//�������ݿ�
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	if ((u = (USER*)malloc(sizeof(USER))) == NULL)
	{
		printf("memoryallocation runs wrong in lgfunc.c");
		delay(3000);
		exit(1);
	}
	memset(u, '\0', sizeof(USER));
	strcpy(u->ID, name);
	strcpy(u->phone, id);
	strcpy(u->password, code);
	strcpy(u->user, bank);
	fseek(fp, 0, SEEK_END);//��ת���ļ�ĩβ
	fwrite(u, sizeof(USER), 1, fp);//���û���Ϣд���ļ� ���Ĭ��Ϊ0
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
}

///*********************************************
//FUNCTION:judge_sameuser
//DESCRIPTION���ж��˻��Ƿ��������,
//	flagΪ1�ж��Ƿ�ע�ᣬ
//	flagΪ2�ж��һ��������Ƿ����
//INPUT:new_user,flag
//RETURN:1/0
//***********************************************/
int judge_sameuser(char* new_user, int flag)
{
	int len;
	int i;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("database\\UserData.dat", "rb+")) == NULL)//�������ݿ�
	{
		printf("cannot open file UserData.dat");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->user, new_user) == 0)
		{
			switch (flag)
			{
			case 1:
				puthz(45, 190, "�û��ѱ�ע��", 16, 17, RED);
				break;
			case 2:
				puthz(450, 110, "�˺Ŵ���", 16, 17, RED);
				break;
			default:
				printf("something wrong");
				delay(3000);
				exit(1);
			}
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n cannot close Database.");
				delay(3000);
				exit(1);
			}
			return 0;
		}
		free(u);
		u = NULL;
	}
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	return 1;
}

///*********************************************
//FUNCTION:checkright_user
//DESCRIPTION������û����Ƿ����6λ
//INPUT:str,x,y
//RETURN:1/0
//***********************************************/
int checkright_user(char* str, int x, int y)
{
	if (strlen(str) <6  )
	{
		puthz(x, y, "����Ӧ", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">6");
		return 1;
	}
	else if (strlen(str) >= 6 && strlen(str) <= 12)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		//line(550, 98, 560, 108); 
		//line(560, 108, 570, 88); 
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

///*********************************************
//FUNCTION:checkright_password
//DESCRIPTION����������Ƿ����8λ
//INPUT:str,x,y
//RETURN:1/0
//***********************************************/
int checkright_password(char* str, int x, int y)
{
	if (strlen(str) < 8)//С��8λ
	{
		puthz(x, y, "����Ӧ", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 53, y - 5, ">8");
		return 1;
	}
	else if (strlen(str) >= 8 && strlen(str) <= 16)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		//line(550, 158, 560, 168);
		//line(560, 168, 570, 148);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

///*********************************************
//FUNCTION:checkright_password
//DESCRIPTION�����ȷ�������Ƿ�һ��
//INPUT:str1,str2,x,y
//RETURN:1/0
//***********************************************/
int checkright_confirmedpassword(char* str1, char* str2, int x, int y)
{
	if (strcmp(str1, str2) != 0)
	{
		puthz(x, y, "���β�һ��", 16, 17, RED);
		return 1;
	}
	else if (strcmp(str1, str2) == 0)
	{
		setcolor(BLUE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(x + 3, y + 8, x + 13, y + 18);
		line(x + 13, y + 18, x + 23, y - 2);
		return 0;
	}
	return 1;
}

///*********************************************
//FUNCTION:checkright_ID
//DESCRIPTION��������֤λ�����ʽ
//INPUT:str,x,y,flag
//RETURN:1/0
//***********************************************/
int checkright_ID(char* str, int x, int y, int flag)
{
	int i;
	int state = 1;
	if (strlen(str) != 11)
	{
		puthz(x, y, "ӦΪ", 16, 17, RED);
		setcolor(RED);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(x + 35, y - 5, "11");
		puthz(x + 65, y, "λ", 16, 17, RED);//���Ȳ�����
		return 1;
	}
	else if (strlen(str) == 11)
	{
		for (i = 0; i < 9; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				continue;
			}
			else
			{
				puthz(x, y, "��ʽ����ȷ", 16, 17, RED);
				return 0;
			}

		}
		state = 0;
		/*if (str[17] == 'X' || (str[17] >= '0' && str[17] <= '9'))
		{
			state = 0;//�ж����һλ�Ƿ�Ϊ���ֺ�X
		}
		else
		{
			puthz(x, y, "��ʽ����ȷ", 16, 17, RED);
			return 1;
		}*/
	}
	if (state == 0)
	{
		switch (flag)
		{
		case 1:
			setcolor(BLUE);
			setlinestyle(SOLID_LINE, 0, 3);
			line(x + 3, y + 8, x + 13, y + 18);
			line(x + 13, y + 18, x + 23, y - 2);
			break;
		case 2:
			break;
		}
		return 0;
	}
	return 1;
}
///*********************************************
//FUNCTION:judge
//DESCRIPTION���ж�ע���״̬
//INPUT : str, p, x, y
//RETURN : ��
//* **********************************************/
void judge(char* str, int* p, int x, int y)
{
	if (strlen(str) == 0)
	{
		*p = 1;
		puthz(x, y, "δ����", 16, 17, RED);
	}
	else
	{
		*p = 0;
	}
}

///************************************
//* ����֮ǰ����
//*************************************/
void recoverhz(int x, int y, int color)
{
	setfillstyle(SOLID_FILL, color);
	bar(x, y, x + 95, y + 35);
}
	
