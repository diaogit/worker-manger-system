#include<iostream>
#include<string>
#include"workermanger.h"
#include"boss.h"
#include"employee.h"
#include"manger.h"
#include"worker.h"

using namespace std;
int main()
{
	workermanger test;
	while(true)
	{
		int choice=0;
		test.menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�����ϵͳ
		{
			test.exitsystem();
			break;
		}
		case 1://����ְ����Ϣ
		{
			test.addemp();
			break;
		}
		case 2://��ʾְ����Ϣ
		{
			test.showemp();
			break;
		}
		case 3://ɾ��ְ����Ϣ
		{
			test.delemp();
			break; 
		}
		case 4://�޸�ְ����Ϣ
		{
			test.modemp();
			break;
		}
		case 5://����ְ����Ϣ
		{
			test.findemp();
			break; 
		}
		case 6://���ձ������
		{
			test.sortemp();
			break; 
		}
		case 7://��������ĵ�
		{
			test.cleanemp();
			break; 
		}
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}