#ifndef _PUBLIC_H_
#define _PUBLIC_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<math.h>
#include<bios.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include"HZ.H"
#include"MOUSE.H"
#include"DATABASE.H"

void draw_my_information(USER* u);
void my_information(int* page, USER* u);//page  5:������Ϣ 6����ʷ��¼7���ҵ��ղ� 8���Ժ��ٿ� 9���ҵĶ�̬ 0����ҳvoid lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag);//��¼���水ť����
void lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag);//��ť����
void recoverbutton_login_information(int status);//�ָ�
int control_judge(USER* u);
void cpop(int i);



void main_base(int* page, USER* u);
void base_draw_information(USER* u);
void base_draw_my_information(USER* u);
void base_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag);//��ť����
void base_recoverbutton_login_information(int status);//�ָ�


#define NUM0 0x5230
#define NUM1 0x4f31
#define NUM2 0x5032
#define NUM3 0x5133
#define NUM4 0x4134
#define NUM5 0x4c35
#define NUM6 0x4d36
#define NUM7 0x4737
#define NUM8 0x4838
#define NUM9 0x4939
#define F2 0x3c00
#define F3 0x3d00
#define F4 0x3e00
#define F5 0x3f00
#define F6 0x4000
#define F7 0x4100
#define F8 0x4200
#define F9 0x4300
#define F10 0x4400
#define F1 0x3b00
#define ENTER 0x1c0d
#define BACK 0x0e08
#define ESC 0x011b
#define UP 0x4800
#define DOWN 0x5000
#define RIGHT 0x4d00
#define LEFT 0x4b00
#define ONE 0x0231
#define TWO 0x0332
#define THREE 0x0433
#define FOUR 0x0534
#define FIVE 0x0635
#define SIX 0x0736
#define SEVEN 0x0837
#define EIGHT 0x0938
#define NINE 0x0a39
#define ZERO 0x0b30

#endif