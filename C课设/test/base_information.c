#include"public.h"
#include"database.h"
void main_base(int *page,USER* u)
{
	int num = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();//�⺯��
	base_draw_information(u);
	base_draw_my_information(u);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 420 && MouseX < 530 && MouseY>300 && MouseY < 350)//������ҳ�ж�
		{
			if (mouse_press(420, 300, 530, 350) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					base_lightbutton_login_information(420, 300, 530, 350, RED, RED, 4);//color1Ϊ����ɫ��color2Ϊ���ɫ
					num = 4;
				}
				continue;
			}
			else if (mouse_press(420, 300, 530, 350) == 1)
			{
				MouseS = 0;
				*page = 3;//����Ĭ��0��ҳ
				return;
			}
		}
		if (num != 0)//�����ָ�
		{
			if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7)
			{
				base_recoverbutton_login_information(num);
			}
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}
void base_draw_information(USER* u)
{
	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);//blibliͼ��
	settextstyle(0, 0, 3);

	puthz(24*4, 0, "�ҵ�����", 24, 24 + 4, LIGHTMAGENTA);
	puthz(24*4, 24*2, "�ҵ��˺�", 24, 24 + 4, LIGHTMAGENTA);
	puthz(24 * 4, 24*4, "���ֻ�", 24, 24 + 4, LIGHTMAGENTA);
	

	outtextxy(110+24*4, 0, u->user);//
	outtextxy(110+24*4, 24*2, u->ID);//
	outtextxy(110+24*4, 24*4, u->phone);//


}
void base_draw_my_information(USER* u)
{

	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);


	bar(420, 300, 530, 350);//����
	puthz(425, 315, "����", 24, 4 + 24, WHITE);

}
void base_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag)//��ť����
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
		puthz(425, 115, "�Ժ��ٿ�", 24, 4 + 24, WHITE);
		break;
	case 3:
		puthz(425, 215, "�ҵĶ�̬", 24, 4 + 24, WHITE);
		break;
	case 4:
		puthz(425, 315, "����", 24, 4 + 24, WHITE);
		break;
	case 5:
		puthz(115, 115, "������Ϣ", 24, 4 + 24, MAGENTA);
		break;
	case 6:
		puthz(115, 215, "��ʷ��¼", 24, 4 + 24, MAGENTA);
		break;
	case 7:
		puthz(115, 315, "�ҵ��ղ�", 24, 4 + 24, MAGENTA);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}

}


void base_recoverbutton_login_information(int status)//�ָ�
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
		puthz(425, 315, "����", 24, 28, WHITE);
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