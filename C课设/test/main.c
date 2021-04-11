#include"main.h"
#include"public.h"
#include"playvideo.h"
int main()
{
	int page = 0;
	int i = 0;
	int gd = VGA, gm = VGAHI;
	//char* t[] = { "Alittle\\a.bmp","Alittle\\b.bmp","Alittle\\c.bmp","Alittle\\d.bmp","Alittle\\e.bmp","Alittle\\f.bmp","Alittle\\g.bmp" };
	//char* tp[] = { "a.dat","b.dat","c.dat","d.dat","e.dat","f.dat","g.dat" };
	//char* ti[] = { "Alarge\\a.bmp","Alarge\\b.bmp","Alarge\\c.bmp","Alarge\\d.bmp","Alarge\\e.bmp","Alarge\\f.bmp","Alarge\\g.bmp" };
	USER u;
	memset(&u, '\0', sizeof(USER));
	initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");
	//bmp_convert("Alittle\\e.bmp", "e.dat");
	/*for (i = 0; i < 7; i++)
	{
		bmp_convert(ti[i], tp[i]);
	}*/
	//welcome_page();	//»¶Ó­½çÃæ
	mouseinit();
	while (1)
	{
		switch (page)
		{
		case 0:
			main_page(&page);//Ö÷Ò³
			break;
		case 1:
			login_main(&page, &u);//µÇÂ¼
			break;
		case 2:
			register_main(&page);//×¢²á
			break;
		case 4:
			show(&page);//ÊÓÆµ²¥·Å
			break;
		}
	}
	closegraph();
	return 0;
}