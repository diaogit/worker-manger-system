#include "employee.h"

employee::employee(int id, string name, int did)
{
	this->m_id = id;
	this->dept_id = did;
	this->m_name = name;
}
void employee::showinfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ " << this->getdeptname()
		<< "\t��λְ�� ��ɾ�����������" << endl;
}

string employee::getdeptname()
{
	return string("Ա��");
}
