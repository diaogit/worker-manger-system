#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker
{
public:
	//��ʾ������Ϣ
	virtual void showinfo()=0;
	//��ȡ��λ����
	virtual string getdeptname() = 0;
	int m_id;//ְ�����
	int dept_id;//���ű��
	string m_name;//ְ������
};
