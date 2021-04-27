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
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出管理系统
		{
			test.exitsystem();
			break;
		}
		case 1://增加职工信息
		{
			test.addemp();
			break;
		}
		case 2://显示职工信息
		{
			test.showemp();
			break;
		}
		case 3://删除职工信息
		{
			test.delemp();
			break; 
		}
		case 4://修改职工信息
		{
			test.modemp();
			break;
		}
		case 5://查找职工信息
		{
			test.findemp();
			break; 
		}
		case 6://按照编号排序
		{
			test.sortemp();
			break; 
		}
		case 7://清空所有文档
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