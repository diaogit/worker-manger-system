#pragma once
#include<string>
#include"worker.h"
using namespace std;
class boss :public worker//�ϰ��ļ�
{
public:
	boss(int id, string name, int did);
	void showinfo();
	string getdeptname();
};

