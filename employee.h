#pragma once
#include"worker.h"
#include<iostream>
#include<string>
using namespace std;
class employee:public worker//普通员工文件
{
public:
	employee(int id, string name,int did);
	void showinfo();
	string getdeptname();	
};

