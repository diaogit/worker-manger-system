#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

class manger :public worker//�����ļ�
{
public:
	manger(int id, string name, int did);
	void showinfo();
	string getdeptname();
};

