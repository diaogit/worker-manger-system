#include "manger.h"

manger::manger(int id, string name, int did)
{
	this->m_id = id;
	this->dept_id = did;
	this->m_name = name;
}
void manger::showinfo()
{
	cout << "ְ����ţ�" <<this-> m_id
		<< "\tְ��������" <<this-> m_name
		<< "\t��λ " << this->getdeptname()
		<< "\t��λְ�� ����ϰ彻��������" << endl;
}

string manger::getdeptname()
{
	return string("����");
}
