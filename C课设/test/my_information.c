#include"public.h"
#include"database.h"
#include"my_information"
void my_information(int *page,char *ID)//page  5:������Ϣ 6����ʷ��¼7���ҵ��ղ� 8���Ժ��ٿ� 9���ҵĶ�̬ 0����ҳ
{
	FILE* fp;
	USER* u1;
	int num = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();//�⺯��
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
		if (strcmp(ID, u->ID) == 0)//�˺�ƥ��
		{
			u1 = u;
		}
	}
	draw_my_information(u1,ID);
	while (1)
	{
		if (MouseX > 110 && MouseX < 220 && MouseY>100 && MouseY < 150)//������Ϣ�ж�
		{
			if (mouse_press(110, 100, 220, 150) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(110, 100, 220, 150, LIGHTMAGENTA, LIGHTGRAY, 5);//color1Ϊ����ɫ��color2Ϊ���ɫ
					num = 5;
				}
				continue;
			}
			else if (mouse_press(110, 100, 220, 150) == 1)
			{
				MouseS = 0;
				*page = 5;//����Ĭ��5Ϊ�ҵĻ�����Ϣҳ
				return;
			}
		}

		if (MouseX > 110 && MouseX < 220 && MouseY>200 && MouseY < 250)//��ʷ��¼�ж�
		{
			if (mouse_press(110, 200, 220, 250) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(110, 200, 220, 250, LIGHTMAGENTA, LIGHTGRAY, 6);//color1Ϊ����ɫ��color2Ϊ���ɫ
					num = 6;
				}
				continue;
			}
			else if (mouse_press(110, 200, 220, 250) == 1)
			{
				MouseS = 0;
				*page = 6;//
				return;
			}
		}

		if (MouseX > 110 && MouseX < 220 && MouseY>300 && MouseY < 350)//�ҵ��ղ��ж�
		{
			if (mouse_press(110, 300, 220, 350) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(110, 300, 220, 350, LIGHTMAGENTA, LIGHTGRAY, 7);//color1Ϊ����ɫ��color2Ϊ���ɫ
					num = 7;
				}
				continue;
			}
			else if (mouse_press(110, 300, 220, 350) == 1)
			{
				MouseS = 0;
				*page = 7;//
				return;
			}
		}

		if (MouseX > 420 && MouseX < 530 && MouseY>100 && MouseY < 150)//�Ժ��ٿ��ж�
		{
			if (mouse_press(420, 100, 530, 150) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(420, 100, 530, 150, RED, RED, 2);//color1Ϊ����ɫ��color2Ϊ���ɫ
					num = 2;
				}
				continue;
			}
			else if (mouse_press(420, 100, 530, 150) == 1)
			{
				MouseS = 0;
				*page = 8;//
				return;
			}
		}

		if (MouseX > 420 && MouseX < 530 && MouseY>200 && MouseY < 250)//�ҵĶ�̬�ж�
		{
			if (mouse_press(420, 200, 530, 250) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(420, 200, 530, 250, RED, RED, 5);//color1Ϊ����ɫ��color2Ϊ���ɫ
					num = 3;
				}
				continue;
			}
			else if (mouse_press(420, 200, 530, 250) == 1)
			{
				MouseS = 0;
				*page = 9;//
				return;
			}
		}

		if (MouseX > 420 && MouseX < 530 && MouseY>300 && MouseY < 350)//������ҳ�ж�
		{
			if (mouse_press(420, 300, 530, 350) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(420, 300, 530, 350, RED, RED, 5);//color1Ϊ����ɫ��color2Ϊ���ɫ
					num = 4;
				}
				continue;
			}
			else if (mouse_press(420, 300, 530, 350) == 1)
			{
				MouseS = 0;
				*page = 0;//����Ĭ��0��ҳ
				return;
			}
		}



		if (num != 0)//�����ָ�
		{
			if (num==2||num == 3 || num == 4 || num == 5||num==6||num==7)
			{
				recoverbutton_login(num);
			}
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}

}
void draw_my_information(USER*u,char *ID)
{

	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);

	rectangle(110, 100, 220, 150);//������Ϣ
	puthz(115, 115, "������Ϣ", 24, 4, LIGHTMAGENTA);

	rectangle(110, 200, 220, 250);//��ʷ��¼
	puthz(115, 215, "��ʷ��¼", 24, 4, LIGHTMAGENTA);

	rectangle(110, 300, 220, 350);//�ҵ��ղ�
	puthz(115, 315, "�ҵ��ղ�", 24, 4, LIGHTMAGENTA);


	setfillstyle(1, LIGHTMAGENTA);//�Ժ��ٿ�
	bar(420, 100, 530, 150);
	puthz(425, 115, "�Ժ��ٿ�", 24, 4, WHITE);

	bar(420, 200, 530, 250);//�ҵĶ�̬
	puthz(425, 215, "�ҵĶ�̬", 24, 4, WHITE);

	bar(420, 300, 530, 350);//����
	puthz(425, 315, "������ҳ", 24, 4, WHITE);



	
	setcolor(LIGHTMAGENTA);//blibliͼ��
	settextstyle(0, 0, 1);

	puthz(0, 0, "�ҵ�����", 20, 23, LIGHTMAGENTA);
	puthz(0, 20, "�ҵ��˺�", 20, 23, LIGHTMAGENTA);


	outtextxy(100, 0, u->users);//
	outtextxy(100, 20, u->ID);//
		

	

	
}
void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag)//��¼���水ť����
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�
	switch (flag)
	{
	case 1:
		break;
	case 2:
		puthz(425, 115, "�Ժ��ٿ�", 24, 4, WHITE);
		break;
	case 3:
		puthz(425, 215, "�ҵĶ�̬", 24, 4, WHITE);
		break;
	case 4:
		puthz(425, 315, "������ҳ", 24, 4, WHITE);
		break;
	case 5:
		puthz(115, 115, "������Ϣ", 24, 4, MAGENTA);
		break;
	case 6:
		puthz(115, 215, "��ʷ��¼", 24, 4, MAGENTA);
		break;
	case 7:
		puthz(115, 315, "�ҵ��ղ�", 24, 4, MAGENTA);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}

}


void recoverbutton_login(int status)//�ָ�
{
	clrmous(MouseX, MouseY);
	switch (status)
	{
	case 3://�Ժ��ٿ��ָ�
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 100, 530, 150);
		puthz(425, 115, "�Ժ��ٿ�", 24, 4, WHITE);
		break;
	case 3://�ҵĶ�̬�ָ�
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 200, 530, 250);
		puthz(425, 215, "�ҵĶ�̬", 24, 4, WHITE);
		break;
	case 3://��¼��ָ�
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 300, 530, 350);
		puthz(425, 315, "������ҳ", 24, 4, WHITE);
		break;
	case 5://������Ϣ�ָ�
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 100, 220, 150);
		rectangle(110, 100, 220, 150);
		puthz(115, 115, "������Ϣ", 24, 4, LIGHTMAGENTA);
	case 6://��ʷ��¼�ָ�
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 200, 220, 250);
		rectangle(110, 200, 220, 250);
		puthz(115, 125, "��ʷ��¼", 24, 4, LIGHTMAGENTA);
	case 7://�ҵ��ղػָ�
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 300, 220, 350);
		rectangle(110, 300, 220, 350);
		puthz(115, 315, "�ҵ��ղ�", 24, 4, LIGHTMAGENTA);
	}
}