#include"showvideo.h"
void show(int* page,char* vn)
{
	char* ti[] = { "Alarge\\a.dat","Alarge\\b.dat","Alarge\\c.dat","Alarge\\d.dat","Alarge\\f.dat","Alarge\\g.dat" };
	int i = 0;
	int num = 0;
	int state = 0;//0Ϊ�����У�1Ϊ��ͣ��
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawshow();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (state == 0)
		{
			show_dbm(80, 80, ti[i++]);
			delay(10);
			if (i >= sizeof(ti))
			{
				i = 0;
				state = 1;
				recoverbutton_show(2);
			}
		}
		if (((MouseX-315)*(MouseX - 315)+(MouseY-430)*(MouseY - 430))<=1600)//������ͣ��ť
		{
			if (mouse_press(280, 395, 350, 465) == 2)
			{
				MouseS = 1;
				if (state == 0 && num==0 )
				{
					lightbutton_show(BLUE, LIGHTGRAY, 1);//color1Ϊ����ɫ��color2Ϊ���ɫ
					num = 1;
				}
				if (state == 1 && num==0 )
				{
					lightbutton_show(BLUE, LIGHTGRAY, 2);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(280, 395, 350, 465) == 1)
			{
				MouseS = 0;
				if (state == 0)
				{
					lightbutton_show(BLUE, LIGHTGRAY, 2);
					state = 1;
					num = 2;
					delay(100);
					continue;
				}
				if (state == 1)
				{
					lightbutton_show(BLUE, LIGHTGRAY, 1);
					state = 0;
					num = 1;
					delay(100);
				}
			}
		}
		if (MouseX > 590 && MouseX < 640 && MouseY>0 && MouseY < 50)//���ذ�ť
		{
			if (mouse_press(590, 0, 640, 50) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_show(RED, LIGHTGRAY, 3);
					num = 3;
				}
				continue;
			}
			else if (mouse_press(590, 0, 640, 50) == 1)
			{
				MouseS = 0;
				*page = 0;
				return;
			}
		}
		if (MouseX > 450 && MouseX < 540 && MouseY>390 && MouseY < 430)//�ղذ�ť
		{
			if (mouse_press(450, 390, 540, 430) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_show(RED, RED, 4);
					num = 4;
				}
				continue;
			}
			else if (mouse_press(450, 590, 540, 430) == 1)
			{

			}
		}
		if (MouseX > 100 && MouseX < 200 && MouseY>380 && MouseY < 420)//����Ļ��ť
		{
			if (mouse_press(100, 380, 200, 420) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_show(RED, RED, 5);
					num = 5;
				}
				continue;
			}
			else if (mouse_press(100, 380, 200, 420) == 1)
			{

			}
		}
		if (MouseX > 100 && MouseX < 200 && MouseY>435 && MouseY < 475)//���۰�ť
		{
			if (mouse_press(100, 435, 200, 475) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_show(RED, RED, 6);
					num = 6;
				}
				continue;
			}
			else if (mouse_press(100, 435, 200, 475) == 1)
			{

			}
		}
		if (num != 0)
		{
			if (state == 0)
				recoverbutton_show(1);
			if (state == 1)
				recoverbutton_show(2);
			if (num == 3 || num == 4 || num == 5 || num == 6)
				recoverbutton_show(num);
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}
void drawshow()
{
	setcolor(BLUE);

	circle(315, 430, 40);

	line(300, 405, 300, 455);//����ʱ
	line(330, 405, 330, 455);

	//line(300, 405, 300, 455);//��ͣʱ
	//line(300, 405, 340, 430);
	//line(300, 455, 340, 430);

	setfillstyle(1, LIGHTMAGENTA);//�ղ�
	bar(450, 390, 540, 430);
	puthz(468, 399, "�ղ�", 24, 30, WHITE);

	bar(100, 380, 200, 420);//����Ļ
	puthz(116, 388, "����Ļ", 24, 24, WHITE);

	bar(100, 435, 200, 475);//����
	puthz(123, 443, "����", 24, 30, WHITE);

	setcolor(RED);//���ذ�ť
	rectangle(590, 0, 640, 50);
	line(590, 0, 640, 50);
	line(640, 0, 590, 50);
}
void lightbutton_show( int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setfillstyle(1, color2);
	switch (flag)
	{
	case 1://����ʱ
		pieslice(315, 430, 0, 360, 40);
		/*setcolor(WHITE);
		line(315, 430, 355, 430);*/
		setcolor(color1);
		line(300, 405, 300, 455);
		line(330, 405, 330, 455);
		break;
	case 2:
		pieslice(315, 430, 0, 360, 40);
		line(300, 405, 300, 455);//��ͣʱ
	    line(300, 405, 340, 430);
	    line(300, 455, 340, 430);
		break;
	case 3:
		bar(590, 0, 640, 50);
		rectangle(590, 0, 640, 50);
		line(590, 0, 640, 50);
		line(640, 0, 590, 50);
		break;
	case 4://�ղذ�ť
		bar(450, 390, 540, 430);
		puthz(468, 399, "�ղ�", 24, 30, WHITE);
		break;
	case 5://����Ļ
		bar(100, 380, 200, 420);
		puthz(116, 388, "����Ļ", 24, 24, WHITE);
		break;
	case 6://����
		bar(100, 435, 200, 475);
		puthz(123, 443, "����", 24, 30, WHITE);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}
void recoverbutton_show(int status)
{
	clrmous(MouseX, MouseY);
	switch (status)
	{
	case 1:
		setcolor(WHITE);
		setfillstyle(1, WHITE);
		pieslice(315, 430, 0, 360, 40);
		line(315, 430, 355, 430);
		setcolor(BLUE);
		circle(315, 430, 40);
		line(300, 405, 300, 455);//����ʱ
		line(330, 405, 330, 455);
		break;
	case 2:
		setcolor(BLUE);
		setfillstyle(1, WHITE);
		pieslice(315, 430, 0, 360, 40);
		circle(315, 430, 40);
		line(300, 405, 300, 455);//��ͣʱ
		line(300, 405, 340, 430);
		line(300, 455, 340, 430);
		break;
	case 3:
		setcolor(RED);
		setfillstyle(1, WHITE);
		bar(590, 0, 640, 50);
		rectangle(590, 0, 640, 50);
		line(590, 0, 640, 50);
		line(640, 0, 590, 50);
		break;
	case 4:
		setfillstyle(1, LIGHTMAGENTA);//�ղ�
		bar(450, 390, 540, 430);
		puthz(468, 399, "�ղ�", 24, 30, WHITE);
		break;
	case 5:
		setfillstyle(1, LIGHTMAGENTA);
		bar(100, 380, 200, 420);//����Ļ
		puthz(116, 388, "����Ļ", 24, 24, WHITE);
		break;
	case 6:
		setfillstyle(1, LIGHTMAGENTA);
		bar(100, 435, 200, 475);//����
		puthz(123, 443, "����", 24, 30, WHITE);
		break;
	}
}