#include "boss.h"

boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->dept_id = did;
	this->m_name = name;
}
void boss::showinfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位 " << this->getdeptname()
		<< "\t岗位职责： 分配所有员工的任务！" << endl;
}

string boss::getdeptname()
{
	return string("老板");
}
