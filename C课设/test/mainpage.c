#include"mainpage.h"
void main_page(int *page)
{
	int num = 0;
	int i = 0;
	char* t[] = { "Alittle\\a.bmp","Alittle\\b.bmp","Alittle\\c.bmp","Alittle\\d.bmp","Alittle\\e.bmp","Alittle\\f.bmp","Alittle\\g.bmp" };
	char* ti[] = { "Alarge\\a.bmp","Alarge\\b.bmp","Alarge\\c.bmp","Alarge\\d.bmp","Alarge\\e.bmp","Alarge\\f.bmp","Alarge\\g.bmp" };
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawpage();
	putbmp(100, 100, t[0]);
	//while (i <=10)
	//{
	//	putbmp(100, 100, t[i % 8]);
	//	i++;
	//}
	while (1)
	{
		/*putbmp(100, 100, t[i % 6]);
		i++;
		if(i%6==0)
		drawpage();*/
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 100 && MouseX < 260 && MouseY>100 && MouseY < 190)//"��ƵA"���ж�
		{
			if (mouse_press(100, 100, 260, 190) == 2)
			{
				MouseS = 1;
			}
			else if (mouse_press(100, 100, 260, 190) == 1)
			{
				MouseS = 0;
				*page = 4;
				return;
			}
		}
		if (MouseX > 480 && MouseX < 600 && MouseY>400 && MouseY < 470)//"�ҵ�"���ж�
		{
			if (mouse_press(480, 400, 600, 470) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_mainpage(480, 400, 600, 470, LIGHTMAGENTA, LIGHTGRAY, 1);//color1Ϊ����ɫ��color2Ϊ���ɫ
					num = 1;
				}
				continue;
			}
			else if (mouse_press(480, 400, 600, 470) == 1)
			{
				MouseS = 0;
				*page = 3;
				return;
			}
		}
		if (num != 0)
		{
			recoverbutton_mainpage(num);
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}
void drawpage()
{
	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);

	rectangle(480, 400, 600, 470);//"�ҵ�"��
	puthz(500, 420, "�ҵ�", 32, 50, LIGHTMAGENTA);

	rectangle(40, 400, 160, 470);//��ҳ��
	setfillstyle(1, LIGHTMAGENTA);
	bar(40, 400, 160, 470);
	puthz(60, 420, "��ҳ", 32, 50, WHITE);

	puthz(200, 240, "�Ƽ�", 32, 45, LIGHTRED);
	puthz(440, 240, "����", 32, 45, LIGHTRED);
	bar(0, 0, 640, 50);
}
void lightbutton_mainpage(int x, int y, int x1, int y1, int color1, int color2, int flag)
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
		puthz(500, 420, "�ҵ�", 32, 50, LIGHTMAGENTA);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}
void recoverbutton_mainpage(int status)
{
	clrmous(MouseX, MouseY);
	switch (status)
	{

	case 1:
		setfillstyle(1, WHITE);
		setcolor(LIGHTMAGENTA);
		bar(480, 400, 600, 470);
		rectangle(480, 400, 600, 470);//"�ҵ�"��;
		puthz(500, 420, "�ҵ�", 32, 50, LIGHTMAGENTA);
		break;
	}
}