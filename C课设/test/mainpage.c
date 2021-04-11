#include"mainpage.h"
void main_page(int *page)
{
	int num = 0;
	int i = 0;
	char* t[] = { "Alittle\\a.dat","Alittle\\b.dat","Alittle\\c.dat","Alittle\\d.dat","Alittle\\f.dat","Alittle\\g.dat" };
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawpage();	
	show_dbm(96, 100, "Alittle\\a.dat");	
	while (1)
	{
		/*putbmp(100, 100, t[i % 6]);
		i++;
		if(i%6==0)
		drawpage();*/
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 96 && MouseX < 256 && MouseY>100 && MouseY < 190)//"视频A"框判定
		{
			if (mouse_press(96, 100, 256, 190) == 2)
			{
				MouseS = 0;
				show_dbm(96, 100, t[i++]);
				if (i >= sizeof(t))
				{
					i = 0;
				}					
				continue;
			}
			else if (mouse_press(96, 100, 256, 190) == 1)
			{
				MouseS = 0;
				*page = 4;
				return;
			}
		}
		if (MouseX > 384 && MouseX < 544 && MouseY>100 && MouseY < 190)//"视频B"框判定
		{
			if (mouse_press(384, 100, 544, 190) == 2)
			{

			}
			else if (mouse_press(384, 100, 544, 190) == 1)
			{

			}
		}
		if (MouseX > 96 && MouseX < 256 && MouseY>290 && MouseY < 380)//"视频C"框判定
		{
			if (mouse_press(96, 290, 256, 380) == 2)
			{

			}
			else if (mouse_press(96, 290, 256, 380) == 1)
			{

			}
		}
		if (MouseX > 384 && MouseX < 544 && MouseY>290 && MouseY < 380)//"视频D"框判定
		{
			if (mouse_press(384, 290, 544, 380) == 2)
			{

			}
			else if (mouse_press(384, 290, 544, 380) == 1)
			{

			}
		}
		if (MouseX > 480 && MouseX < 600 && MouseY>400 && MouseY < 470)//"我的"框判定
		{
			if (mouse_press(480, 400, 600, 470) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_mainpage(480, 400, 600, 470, LIGHTMAGENTA, LIGHTGRAY, 1);//color1为线颜色，color2为填充色
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

	rectangle(480, 400, 600, 470);//"我的"框
	puthz(500, 420, "我的", 32, 50, LIGHTMAGENTA);

	rectangle(40, 400, 160, 470);//主页框
	setfillstyle(1, LIGHTMAGENTA);
	bar(40, 400, 160, 470);
	puthz(60, 420, "主页", 32, 50, WHITE);

	puthz(200, 40, "推荐", 32, 45, LIGHTRED);
	puthz(440, 40, "热门", 32, 45, LIGHTRED);
}
void lightbutton_mainpage(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//画边框
	switch (flag)
	{
	
	case 1:
		puthz(500, 420, "我的", 32, 50, LIGHTMAGENTA);
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
		rectangle(480, 400, 600, 470);//"我的"框;
		puthz(500, 420, "我的", 32, 50, LIGHTMAGENTA);
		break;
	}
}