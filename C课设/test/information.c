#include"public.h"
#include"database.h"
void my_information(int* page, USER* u)//page  5:������Ϣ 6����ʷ��¼7���ҵ��ղ� 8���Ժ��ٿ� 9���ҵĶ�̬ 0����ҳ
{
	/*FILE* fp;
	USER* u1;*/
	int judge;
	int num = 0;
	judge = control_judge(u);
	if (judge == 0)
	{
		cpop(judge);
		*page = 1;
		return;
	}
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();//�⺯��
	
	draw_my_information(u);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 110 && MouseX < 220 && MouseY>100 && MouseY < 150)//������Ϣ�ж�
		{
			if (mouse_press(110, 100, 220, 150) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login_information(110, 100, 220, 150, LIGHTMAGENTA, LIGHTGRAY, 5);//color1Ϊ����ɫ��color2Ϊ���ɫ
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
					lightbutton_login_information(110, 200, 220, 250, LIGHTMAGENTA, LIGHTGRAY, 6);//color1Ϊ����ɫ��color2Ϊ���ɫ
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
					lightbutton_login_information(110, 300, 220, 350, LIGHTMAGENTA, LIGHTGRAY, 7);//color1Ϊ����ɫ��color2Ϊ���ɫ
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
					lightbutton_login_information(420, 100, 530, 150, RED, RED, 2);//color1Ϊ����ɫ��color2Ϊ���ɫ
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
					lightbutton_login_information(420, 200, 530, 250, RED, RED, 3);//color1Ϊ����ɫ��color2Ϊ���ɫ
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
					lightbutton_login_information(420, 300, 530, 350, RED, RED, 4);//color1Ϊ����ɫ��color2Ϊ���ɫ
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
				recoverbutton_login_information(num);
			}
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}

}
void draw_my_information(USER*u)
{

	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);

	rectangle(110, 100, 220, 150);//������Ϣ
	puthz(115, 115, "������Ϣ", 24, 4+24, LIGHTMAGENTA);

	rectangle(110, 200, 220, 250);//��ʷ��¼
	puthz(115, 215, "��ʷ��¼", 24, 4+24, LIGHTMAGENTA);

	rectangle(110, 300, 220, 350);//�ҵ��ղ�
	puthz(115, 315, "�ҵ��ղ�", 24, 4+24, LIGHTMAGENTA);


	setfillstyle(1, LIGHTMAGENTA);//�Ժ��ٿ�
	bar(420, 100, 530, 150);
	puthz(425, 115, "�Ժ��ٿ�", 24, 4+24, WHITE);

	bar(420, 200, 530, 250);//�ҵĶ�̬
	puthz(425, 215, "�ҵĶ�̬", 24, 4+24, WHITE);

	bar(420, 300, 530, 350);//����
	puthz(425, 315, "������ҳ", 24, 4+24, WHITE);



	
	setcolor(LIGHTMAGENTA);//blibliͼ��
	settextstyle(0, 0, 3);

	/*puthz(200, 0, "", 24, 24+4, LIGHTMAGENTA);*/
	/*puthz(0, 24, "�ҵ��˺�", 24, 24+4, LIGHTMAGENTA);

	
	outtextxy(110, 0, u->user);//*/
	outtextxy(220, 50, "bilibili");//
		

	

	
}
void lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag)//��ť����
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
		puthz(425, 115, "�Ժ��ٿ�", 24, 4+24, WHITE);
		break;
	case 3:
		puthz(425, 215, "�ҵĶ�̬", 24, 4+24, WHITE);
		break;
	case 4:
		puthz(425, 315, "������ҳ", 24, 4+24, WHITE);
		break;
	case 5:
		puthz(115, 115, "������Ϣ", 24, 4+24, MAGENTA);
		break;
	case 6:
		puthz(115, 215, "��ʷ��¼", 24, 4+24, MAGENTA);
		break;
	case 7:
		puthz(115, 315, "�ҵ��ղ�", 24, 4+24, MAGENTA);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}

}


void recoverbutton_login_information(int status)//�ָ�
{
	clrmous(MouseX, MouseY);
	switch (status)
	{
	case 2://�Ժ��ٿ��ָ�
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 100, 530, 150);
		puthz(425, 115, "�Ժ��ٿ�", 24, 28, WHITE);
		break;
	case 3://�ҵĶ�̬�ָ�
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 200, 530, 250);
		puthz(425, 215, "�ҵĶ�̬", 24, 28, WHITE);
		break;
	case 4://��¼��ָ�
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420, 300, 530, 350);
		puthz(425, 315, "������ҳ", 24, 28, WHITE);
		break;
	case 5://������Ϣ�ָ�
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 100, 220, 150);
		rectangle(110, 100, 220, 150);
		puthz(115, 115, "������Ϣ", 24, 28, LIGHTMAGENTA);
	case 6://��ʷ��¼�ָ�
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 200, 220, 250);
		rectangle(110, 200, 220, 250);
		puthz(115, 215, "��ʷ��¼", 24, 28, LIGHTMAGENTA);
	case 7://�ҵ��ղػָ�
		setcolor(LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		setfillstyle(1, WHITE);
		bar(110, 300, 220, 350);
		rectangle(110, 300, 220, 350);
		puthz(115, 315, "�ҵ��ղ�", 24, 28, LIGHTMAGENTA);
	}
}
int control_judge(USER* u)
{
	setfillstyle(1, LIGHTGRAY);
	bar(560, 1, 640, 23);          //�ڸ�
	if (strlen(u->user) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void cpop(int i)
{
	clrmous(MouseX, MouseY);
	if (i == 0)
	{
		setfillstyle(SOLID_FILL, LIGHTMAGENTA);
		bar(180, 150, 460, 330);
		setfillstyle(SOLID_FILL, LIGHTMAGENTA);
		bar(200, 170, 440, 310);
		puthz(250, 200, "���ȵ�¼", 16, 20, WHITE);
		puthz(250, 260, "����", 16, 20, WHITE);
		settextjustify(LEFT_TEXT, TOP_TEXT);
		settextstyle(2, HORIZ_DIR, 6);
		setcolor(WHITE);
		outtextxy(295, 260, "3");
		puthz(310, 260, "����ת", 16, 20, WHITE);
		delay(1000);
		setfillstyle(SOLID_FILL, LIGHTMAGENTA);
		bar(295, 260, 308, 273);
		outtextxy(295, 260, "2");
		delay(1000);
		bar(295, 260, 308, 273);
		outtextxy(295, 260, "1");
		delay(1000);
	}
}