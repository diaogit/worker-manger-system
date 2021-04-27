#include "manger.h"

manger::manger(int id, string name, int did)
{
	this->m_id = id;
	this->dept_id = did;
	this->m_name = name;
}
void manger::showinfo()
{
	cout << "职工编号：" <<this-> m_id
		<< "\t职工姓名：" <<this-> m_name
		<< "\t岗位 " << this->getdeptname()
		<< "\t岗位职责： 完成老板交给的任务！" << endl;
}

string manger::getdeptname()
{
	return string("经理");
}
