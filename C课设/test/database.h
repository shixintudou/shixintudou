#ifndef _DATA_H_
#define _DATA_H_
typedef struct userinfo
{
	char user[15];           //6-12λ���û���
	char ID[20];             //18λ���˺�
	char password[20];       //8-16λ������
	char phone[21];       //19λ���ֻ���
}USER;	//��װ�û���Ϣ
typedef struct videoinfo
{
	int vid;//��Ƶ���
	char comment[1000];//����
	int bingo;//������
}VIDEO;
#endif