#ifndef _DATA_H_
#define _DATA_H_
typedef struct userinfo
{
	char user[15];           //6-12位，用户名
	char ID[20];             //18位，账号
	char password[20];       //8-16位，密码
	char phone[21];       //19位，手机号
}USER;	//封装用户信息
typedef struct videoinfo
{
	int vid;//视频编号
	char comment[1000];//评论
	int bingo;//点赞数
}VIDEO;
#endif