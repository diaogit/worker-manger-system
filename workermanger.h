#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manger.h"
using namespace std;
#define filename "empfile.txt"
class workermanger
{
public:
	workermanger();//构造函数
	void menu();//显示主页面
	void exitsystem();//退出功能
	int m_empnum;
	worker * * m_emparry;
	void addemp();//添加职工功能
	void save();//保存文件
	bool m_fileisempty;//判断文件是否为空
	int getempnum();//统计人数
	void init_emp();//初始化员工
	void showemp();//显示职工
	int isexist(int id);//判断职工是否存在
	void delemp();//删除职工
	void modemp();//修改员工
	void findemp();//查找职工
	void sortemp();//排序
	void cleanemp();//清空
	~workermanger();//析构函数
};

