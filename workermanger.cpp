#include "workermanger.h"

	workermanger::workermanger()//构造函数
	{

		//文件不存在
		ifstream ifs;
		ifs.open(filename, ios::in);
		if (!ifs.is_open())
		{
			//初始化属性
			this->m_empnum = 0;
			this->m_emparry = NULL;
			this->m_fileisempty = true;
			ifs.close();
			return;
		}
		//文件存在，但为空
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			cout << "文件为空！" << endl;
			this->m_empnum = 0;
			this->m_emparry = NULL;
			this->m_fileisempty = true;
			ifs.close();
			return;
		}
		//文件存在，并记录数据
		int num = this->getempnum();
		this->m_empnum = num;
		//开辟空间
		this->m_emparry = new worker * [this->m_empnum];
		//将文件中的数据存到数组中
		this->init_emp();	
	}
	void workermanger::menu()//显示主页面
	{
		cout << "*******************************" << endl;
		cout << "*****欢迎使用职工管理系统******" << endl;
		cout << "*****0.退出管理系统******" << endl;
		cout << "*****1.增加职工信息******" << endl;
		cout << "*****2.显示职工信息******" << endl;
		cout << "*****3.删除职工信息******" << endl;
		cout << "*****4.修改职工信息******" << endl;
		cout << "*****5.查找职工信息******" << endl;
		cout << "*****6.按照编号排序******" << endl;
		cout << "*****7.清空所有文档******" << endl;
	}
	void workermanger::addemp()//添加职工
	{
		cout << "请输入添加职工数量："<<endl;
		int addnum = 0;//保存用户输入数量
		cin >> addnum;
		if (addnum > 0)
		{
			int newsize = this->m_empnum + addnum;//计算添加新空间大小，新空间人数=加入的+原有的
			worker** newspace = new worker *[newsize];//开辟新空间
			if (this->m_emparry != NULL)
			{
				for (int i = 0; i <this->m_empnum; i++)
				{
					newspace[i] = this->m_emparry[i];
				}
			}
			//批量添加新数据
			for (int i=0;i<addnum;i++)
			{
				int id;
				string name;
				int deptselect;
				cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
				cin >> id;
				cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
				cin >> name;
				cout << "请选择该职工岗位：" << endl;
				cout << "1.普通员工"
					<< "2.经理"
					<< "3.老板" << endl;
				cin >> deptselect;
				worker* worker=NULL;
				switch (deptselect)
				{
				case 1:
				
					worker = new employee(id,name,1);
					break;
				
				case 2:
				
					worker = new manger(id, name,2);
					break;
				
				case 3:
				
					worker = new boss(id, name,3);
					break;
				
				default:
					break;
				}
				newspace[this->m_empnum + i] = worker;
			}
			delete[] this->m_emparry;
			this->m_emparry = newspace;
			this->m_empnum = newsize;
			this->m_fileisempty = false;//职工不为空
			cout << "成功添加"<<addnum<<"新员工！" <<endl;
			this->save();//保存数据到文件中
		}
		else
		{
			cout << "输入有误！" << endl;
		}
		system("pause");
		system("cls");
	}
	void workermanger::exitsystem()//退出功能
	{
		cout << "欢迎下次使用" << endl;
		system("pause");
		exit(0);
	}
	void workermanger::save()//保存文件
	{
		ofstream ofs;
		ofs.open(filename, ios::out);//用输出方式打开文件，写文件
		for (int i = 0; i < this->m_empnum; i++)//将每个人的数据写入
		{
			ofs << this->m_emparry[i]->m_id << " "//写入所有员工id号
				<< this->m_emparry[i]->m_name << " "//写入所有员工姓名
				<< this->m_emparry[i]->dept_id << endl;//写入所有员工部门编号
				
		}
		ofs.close();
	}
	int workermanger::getempnum()//统计人数
	{
		ifstream ifs;
		ifs.open(filename, ios::in);
		int id;
		string name;
		int did;
		int num = 0;
		while (ifs>>id&&ifs>>name&&ifs>>did)
		{
			num++;
		}
		ifs.close();
		return num;
	}
	void workermanger::init_emp()//初始化员工
	{
		ifstream ifs;
		ifs.open(filename, ios::in);
		int id;
		string name;
		int did;
		int index=0;
		while (ifs >> id && ifs >> name && ifs >> did)
		{
			worker* worker = NULL;
			//根据不同部门id创建不同对象
			if(did==1)//普通员工
			{ 
				worker = new employee(id,name,did);
			}
			else if (did == 2)//经理
			{
				worker = new manger(id, name, did);
			}
			else//老板
			{
				worker = new boss(id, name, did);
			}
			this->m_emparry[index] = worker;//存放在数组中
			index++;
		}
		ifs.close();
	}

	void workermanger::showemp()//显示员工
	{
		if (this->m_fileisempty)
		{
			cout << "文件不存在或记录为空！" << endl;
		}
		else
			for (int i = 0; i < m_empnum; i++)
			{
				this->m_emparry[i]->showinfo();
			}
		system("pause");
		system("cls");
	}

	int workermanger::isexist(int id)
	{
		int index = -1;
		for (int i = 0; i < this->m_empnum; i++)
		{
			if (this->m_emparry[i]->m_id == id)
			{
				index = i;
				break;
			}
		}
		return index;
	}

	void workermanger::delemp()
	{
		if (this->m_fileisempty)
		{
			cout << "文件为空！" <<endl;
		}
		else
		{
			cout << "请输入要删除的职工编号：" << endl;
			int id=0;
			cin >> id;
			int index =this->isexist(id);
			if (index != -1)//职工存在，并且要删除掉index编号的职工
			{
				for (int i = index; i < this->m_empnum - 1; i++)
				{
					this->m_emparry[i] = this->m_emparry[i + 1];//数据前移	
				}
				this->m_empnum--;//人数维护
				this->save();//同步到文件中
				cout << "删除成功！" << endl;
			}
			else
			{
				cout << "删除失败，未找到该职工！" << endl;
			}
		}
		system("pause");
		system("cls");
	}

	void workermanger::modemp()
	{
		if (this->m_fileisempty)
		{
			cout << "文件为空！" << endl;
		}
		else
		{
			cout << "请输入要修改的职工编号：" << endl;
			int id = 0;
			cin >> id;
			int ret = this->isexist(id);
			if (ret != -1)
			{
				delete this->m_emparry[ret];
				int newid = 0;
				string newname = "";
				int dselect = 0;
				cout << "查到" << id << "号职工，请输入新职工号：" << endl;
				cin >> newid;
				cout << "请输入新姓名：" << endl;
				cin >> newname;
				cout << "请输入岗位："
					<< "1.普通员工"
					<< "2.经理"
					<< "3.老板" << endl;
				cin >> dselect;
				worker* worker = NULL;
				switch (dselect)
				{
				case 1://普通员工
				{
					worker = new employee(newid, newname, dselect);
					break;
				}
				case 2://经理
				{
					worker = new employee(newid, newname, dselect);
					break;
				}
				case 3://老板
				{
					worker = new employee(newid, newname, dselect);
					break;
				}
				default:
					break;
				}
				this->m_emparry[ret] = worker;
				cout << "修改成功！" << this->m_emparry[ret]->dept_id << endl;
				this->save();
			}
			else
			{
				cout << "查无此人！" << endl;
			}
		}
		system("pause");
		system("cls");
	}

	void workermanger::findemp()//查找
	{
		if (this->m_fileisempty)
		{
			cout << "文件为空！" << endl;
		}
		else
		{
			cout << "请输入查找方式：" << endl;
			cout << "1.按照编号查找" << endl;
			cout << "2.按照姓名查找" << endl;
			int select = 0;
			cin >> select;
			if (select == 1)
			{
				int id;
				bool flag = false;
				cout << "请输入查找的职工号：" <<endl;
				cin >> id;
				int ret = isexist(id);
				if (ret != -1)
				{
					cout << "查找成功，该用户信息如下：" << endl;
					flag = true;
					this->m_emparry[ret]->showinfo();
				}
				else
				{
					cout << "查找失败！" << endl;
				}
			}
			else if (select == 2)
			{
				string name;
				cout << "请输入查找的姓名：" << endl;
				cin >> name;
				bool flag = false;
				for (int i = 0; i < m_empnum; i++)
				{
					if (m_emparry[i]->m_name == name)
					{
						cout << "查找成功，职工编号为：" << m_emparry[i]->m_id
							<< "号的信息如下：" << endl;
						flag = true;
						m_emparry[i]->showinfo();
					}
				}
				if (flag == false)
				{
					cout << "查找失败！" << endl;
				}
			}
			else
			{
				cout << "输入选项有误！" << endl;
			}
		}
		system("pause");
		system("cls");
	}

	void workermanger::sortemp()//排序
	{
		if (this->m_fileisempty)
		{
			cout << "文件为空！" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			cout << "请输入排序方式：" << endl;
			cout << "1.按照编号升序" << endl;
			cout << "2.按照编号降序" << endl;
			int select = 0;
			cin >> select;
			for (int i = 0; i < m_empnum; i++)
			{
				int maxormin = i;
				for (int j = 0; j < m_empnum; j++)
				{
					if (select == 1)//升序
					{
						if (m_emparry[maxormin]->m_id > m_emparry[j]->m_id)
						{
							maxormin = j;
						}
					}
					else//降序
					{
						if (m_emparry[maxormin]->m_id < m_emparry[j]->m_id)
						{
							maxormin = j;
						}
					}
				}
				if (i != maxormin)
				{
					worker* temp = m_emparry[i];
					m_emparry[i] = m_emparry[maxormin];
					m_emparry[maxormin] = temp;
				}
			}
			cout << "排序成功，排序后结果为：" << endl;
			this->save();
			this->showemp();
		}
	}

	void workermanger::cleanemp()//清空
	{
		cout << "确认要清空吗？" << endl;
		cout << "1.确认" << endl;
		cout << "2.不是，按错了！" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			ofstream ofs(filename, ios::trunc);
			ofs.close();
			if (this->m_emparry != NULL)
			{
				for (int i = 0; i < this->m_empnum; i++)
				{
					if (this->m_emparry != NULL)
					{
						delete this->m_emparry[i];
					}
				}
				this->m_empnum = 0;
				delete[] this->m_emparry;
				this->m_emparry = NULL;
				this->m_fileisempty = true;
			}
			cout << "清空成功！" << endl;
		}
		system("pause");
		system("cls");
	}

	workermanger::~workermanger()
	{
		if (this->m_emparry != NULL)
		{
			delete[] this->m_emparry;
			this->m_emparry = NULL;
		} 
	}
	


