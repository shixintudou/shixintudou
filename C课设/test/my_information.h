#ifndef _MY_INFORMATION_
#define _MY_INFORMATION_
#include<stdio.h>
#include<graphics.h>
#include"mouse.h"
#include"hz.h"
#include"database.h"
 

void draw_my_information(USER*u,char *ID);//�����ҵ���Ϣ����
void my_information(int* page, char* ID);
void lightbutton_login(int x, int y, int x1, int y1, int color1, int color2, int flag);//��¼���水ť����
void recoverbutton_login(int status);//�ָ�

#endif