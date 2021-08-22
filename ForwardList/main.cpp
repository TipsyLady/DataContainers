#include <iostream>
using namespace std;

class Element
{
	int Data; //�������� ��������
	Element* pNext; //����� ���������� ��������
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "E_Constructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "E_Destructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;//������ ������ - ��������� �� ���������(�������) ������� ������
public:
	ForwardList()
	{
		Head = nullptr; //����������� �� ���������, ������� ������ ������
		//���� HEAD ��������� �� ����, �� ������ ����, ��. �� �������� ��-��
		// � HEAD ������ �� �� ��� ���������.
		cout << "L_Constructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "L_Destructor:\t" << this << endl;
	}
//					Adding Elements
	void push_front(int Data)
	{
		//1. ������� ����� �������
		Element* New = new Element(Data);
		//���������� ������� � ������
		New->pNext = Head;
		//3. ����� ������� - ��� ��������� ������� ������
		Head = New;
	}

	//				Methods
	void print() const
	{
		Element* Temp = Head;//Temp - ��� �������� 
		//�������� - ���������, ��� ������ �������� ����� �������� ������
		// � ��������� ��������� ������
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext; // ������ �� ��������� �������
		}
	}
};
void main()
{
	setlocale(LC_ALL, "Russian");
	int n; cout << "������� ������ ������: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
}