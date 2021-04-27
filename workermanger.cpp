#include "workermanger.h"

	workermanger::workermanger()//���캯��
	{

		//�ļ�������
		ifstream ifs;
		ifs.open(filename, ios::in);
		if (!ifs.is_open())
		{
			//��ʼ������
			this->m_empnum = 0;
			this->m_emparry = NULL;
			this->m_fileisempty = true;
			ifs.close();
			return;
		}
		//�ļ����ڣ���Ϊ��
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			cout << "�ļ�Ϊ�գ�" << endl;
			this->m_empnum = 0;
			this->m_emparry = NULL;
			this->m_fileisempty = true;
			ifs.close();
			return;
		}
		//�ļ����ڣ�����¼����
		int num = this->getempnum();
		this->m_empnum = num;
		//���ٿռ�
		this->m_emparry = new worker * [this->m_empnum];
		//���ļ��е����ݴ浽������
		this->init_emp();	
	}
	void workermanger::menu()//��ʾ��ҳ��
	{
		cout << "*******************************" << endl;
		cout << "*****��ӭʹ��ְ������ϵͳ******" << endl;
		cout << "*****0.�˳�����ϵͳ******" << endl;
		cout << "*****1.����ְ����Ϣ******" << endl;
		cout << "*****2.��ʾְ����Ϣ******" << endl;
		cout << "*****3.ɾ��ְ����Ϣ******" << endl;
		cout << "*****4.�޸�ְ����Ϣ******" << endl;
		cout << "*****5.����ְ����Ϣ******" << endl;
		cout << "*****6.���ձ������******" << endl;
		cout << "*****7.��������ĵ�******" << endl;
	}
	void workermanger::addemp()//���ְ��
	{
		cout << "���������ְ��������"<<endl;
		int addnum = 0;//�����û���������
		cin >> addnum;
		if (addnum > 0)
		{
			int newsize = this->m_empnum + addnum;//��������¿ռ��С���¿ռ�����=�����+ԭ�е�
			worker** newspace = new worker *[newsize];//�����¿ռ�
			if (this->m_emparry != NULL)
			{
				for (int i = 0; i <this->m_empnum; i++)
				{
					newspace[i] = this->m_emparry[i];
				}
			}
			//�������������
			for (int i=0;i<addnum;i++)
			{
				int id;
				string name;
				int deptselect;
				cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
				cin >> id;
				cout << "�������" << i + 1 << "����ְ��������" << endl;
				cin >> name;
				cout << "��ѡ���ְ����λ��" << endl;
				cout << "1.��ͨԱ��"
					<< "2.����"
					<< "3.�ϰ�" << endl;
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
			this->m_fileisempty = false;//ְ����Ϊ��
			cout << "�ɹ����"<<addnum<<"��Ա����" <<endl;
			this->save();//�������ݵ��ļ���
		}
		else
		{
			cout << "��������" << endl;
		}
		system("pause");
		system("cls");
	}
	void workermanger::exitsystem()//�˳�����
	{
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		exit(0);
	}
	void workermanger::save()//�����ļ�
	{
		ofstream ofs;
		ofs.open(filename, ios::out);//�������ʽ���ļ���д�ļ�
		for (int i = 0; i < this->m_empnum; i++)//��ÿ���˵�����д��
		{
			ofs << this->m_emparry[i]->m_id << " "//д������Ա��id��
				<< this->m_emparry[i]->m_name << " "//д������Ա������
				<< this->m_emparry[i]->dept_id << endl;//д������Ա�����ű��
				
		}
		ofs.close();
	}
	int workermanger::getempnum()//ͳ������
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
	void workermanger::init_emp()//��ʼ��Ա��
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
			//���ݲ�ͬ����id������ͬ����
			if(did==1)//��ͨԱ��
			{ 
				worker = new employee(id,name,did);
			}
			else if (did == 2)//����
			{
				worker = new manger(id, name, did);
			}
			else//�ϰ�
			{
				worker = new boss(id, name, did);
			}
			this->m_emparry[index] = worker;//�����������
			index++;
		}
		ifs.close();
	}

	void workermanger::showemp()//��ʾԱ��
	{
		if (this->m_fileisempty)
		{
			cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
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
			cout << "�ļ�Ϊ�գ�" <<endl;
		}
		else
		{
			cout << "������Ҫɾ����ְ����ţ�" << endl;
			int id=0;
			cin >> id;
			int index =this->isexist(id);
			if (index != -1)//ְ�����ڣ�����Ҫɾ����index��ŵ�ְ��
			{
				for (int i = index; i < this->m_empnum - 1; i++)
				{
					this->m_emparry[i] = this->m_emparry[i + 1];//����ǰ��	
				}
				this->m_empnum--;//����ά��
				this->save();//ͬ�����ļ���
				cout << "ɾ���ɹ���" << endl;
			}
			else
			{
				cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
			}
		}
		system("pause");
		system("cls");
	}

	void workermanger::modemp()
	{
		if (this->m_fileisempty)
		{
			cout << "�ļ�Ϊ�գ�" << endl;
		}
		else
		{
			cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
			int id = 0;
			cin >> id;
			int ret = this->isexist(id);
			if (ret != -1)
			{
				delete this->m_emparry[ret];
				int newid = 0;
				string newname = "";
				int dselect = 0;
				cout << "�鵽" << id << "��ְ������������ְ���ţ�" << endl;
				cin >> newid;
				cout << "��������������" << endl;
				cin >> newname;
				cout << "�������λ��"
					<< "1.��ͨԱ��"
					<< "2.����"
					<< "3.�ϰ�" << endl;
				cin >> dselect;
				worker* worker = NULL;
				switch (dselect)
				{
				case 1://��ͨԱ��
				{
					worker = new employee(newid, newname, dselect);
					break;
				}
				case 2://����
				{
					worker = new employee(newid, newname, dselect);
					break;
				}
				case 3://�ϰ�
				{
					worker = new employee(newid, newname, dselect);
					break;
				}
				default:
					break;
				}
				this->m_emparry[ret] = worker;
				cout << "�޸ĳɹ���" << this->m_emparry[ret]->dept_id << endl;
				this->save();
			}
			else
			{
				cout << "���޴��ˣ�" << endl;
			}
		}
		system("pause");
		system("cls");
	}

	void workermanger::findemp()//����
	{
		if (this->m_fileisempty)
		{
			cout << "�ļ�Ϊ�գ�" << endl;
		}
		else
		{
			cout << "��������ҷ�ʽ��" << endl;
			cout << "1.���ձ�Ų���" << endl;
			cout << "2.������������" << endl;
			int select = 0;
			cin >> select;
			if (select == 1)
			{
				int id;
				bool flag = false;
				cout << "��������ҵ�ְ���ţ�" <<endl;
				cin >> id;
				int ret = isexist(id);
				if (ret != -1)
				{
					cout << "���ҳɹ������û���Ϣ���£�" << endl;
					flag = true;
					this->m_emparry[ret]->showinfo();
				}
				else
				{
					cout << "����ʧ�ܣ�" << endl;
				}
			}
			else if (select == 2)
			{
				string name;
				cout << "��������ҵ�������" << endl;
				cin >> name;
				bool flag = false;
				for (int i = 0; i < m_empnum; i++)
				{
					if (m_emparry[i]->m_name == name)
					{
						cout << "���ҳɹ���ְ�����Ϊ��" << m_emparry[i]->m_id
							<< "�ŵ���Ϣ���£�" << endl;
						flag = true;
						m_emparry[i]->showinfo();
					}
				}
				if (flag == false)
				{
					cout << "����ʧ�ܣ�" << endl;
				}
			}
			else
			{
				cout << "����ѡ������" << endl;
			}
		}
		system("pause");
		system("cls");
	}

	void workermanger::sortemp()//����
	{
		if (this->m_fileisempty)
		{
			cout << "�ļ�Ϊ�գ�" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			cout << "����������ʽ��" << endl;
			cout << "1.���ձ������" << endl;
			cout << "2.���ձ�Ž���" << endl;
			int select = 0;
			cin >> select;
			for (int i = 0; i < m_empnum; i++)
			{
				int maxormin = i;
				for (int j = 0; j < m_empnum; j++)
				{
					if (select == 1)//����
					{
						if (m_emparry[maxormin]->m_id > m_emparry[j]->m_id)
						{
							maxormin = j;
						}
					}
					else//����
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
			cout << "����ɹ����������Ϊ��" << endl;
			this->save();
			this->showemp();
		}
	}

	void workermanger::cleanemp()//���
	{
		cout << "ȷ��Ҫ�����" << endl;
		cout << "1.ȷ��" << endl;
		cout << "2.���ǣ������ˣ�" << endl;
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
			cout << "��ճɹ���" << endl;
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
	


