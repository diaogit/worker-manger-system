#pragma once
#include"worker.h"
#include<iostream>
#include<string>
using namespace std;
class employee:public worker//��ͨԱ���ļ�
{
public:
	employee(int id, string name,int did);
	void showinfo();
	string getdeptname();	
};

