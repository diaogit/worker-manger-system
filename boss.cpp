#include "boss.h"

boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->dept_id = did;
	this->m_name = name;
}
void boss::showinfo()
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ " << this->getdeptname()
		<< "\t��λְ�� ��������Ա��������" << endl;
}

string boss::getdeptname()
{
	return string("�ϰ�");
}