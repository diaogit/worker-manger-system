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
	workermanger();//���캯��
	void menu();//��ʾ��ҳ��
	void exitsystem();//�˳�����
	int m_empnum;
	worker * * m_emparry;
	void addemp();//���ְ������
	void save();//�����ļ�
	bool m_fileisempty;//�ж��ļ��Ƿ�Ϊ��
	int getempnum();//ͳ������
	void init_emp();//��ʼ��Ա��
	void showemp();//��ʾְ��
	int isexist(int id);//�ж�ְ���Ƿ����
	void delemp();//ɾ��ְ��
	void modemp();//�޸�Ա��
	void findemp();//����ְ��
	void sortemp();//����
	void cleanemp();//���
	~workermanger();//��������
};

