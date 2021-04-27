#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker
{
public:
	//显示个人信息
	virtual void showinfo()=0;
	//获取岗位名称
	virtual string getdeptname() = 0;
	int m_id;//职工编号
	int dept_id;//部门编号
	string m_name;//职工姓名
};
