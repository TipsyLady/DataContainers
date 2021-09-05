#include <iostream>
using namespace std;

class Element
{
	int Data; //значение элемента
	Element* pNext; //адрес следующего элемента
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
	int Size;
	Element* Head;//голова списка - указывает на начальный(нулевой) элемент списка
public:
	int get_Size() { return Size; }
	ForwardList()
	{
		Head = nullptr; //Конструктор по умолчанию, создает пустой список
		//Если HEAD указывает на ноль, то список пуст, те. не содержит эл-ов
		// и HEAD больше не на что указывать.
		Size = 0;
		cout << "L_Constructor:\t" << this << endl;
	}
	~ForwardList()
	{
		del();
		cout << "L_Destructor:\t" << this << endl;
	}

	const int& operator[](const int index)
	{
		int count = 0;
		Element *tmp = this->Head;
		while (tmp != nullptr)
		{
			if (count == index)
			{
				return tmp->Data;
			}
			tmp = tmp->pNext;
			count++;

		}
	}
//					Adding Elements
	void push_front(int Data)
	{
		//1. Создать новый элемент
		Element* New = new Element(Data);
		//Прикрепить элемент к списку
		New->pNext = Head;
		//3. Новый элемент - это начальный элемент списка
		Head = New;
		Size++;
	}


void push_back(int Data)
{
	if (Head == nullptr)
	{
		Head = new Element(Data);
	}
	else
	{
		Element* tmp = this->Head;

		while (tmp->pNext != nullptr)
		{
			tmp = tmp->pNext;
		}
		tmp->pNext = new Element(Data);
	}
	Size++;
}
void pop_front()
{
	Element* temp = Head;
	Head = Head->pNext;
	delete temp;
	Size--;
}
void pop_back()
{
	erase(Size - 1);
}
void insert(int Data, int index)
{
	if (index == 0)
	{
		push_front(Data);
	}
	else
	{
		Element* tmp = this->Head;
		for (int i = 0; i < index - 1; i++)//адрес предшевствующего элемента index
		{
			tmp = tmp->pNext;//записываем адрес элементов пока не дойдем до предшевствующего index значения
		}
		Element* New = new Element(Data, tmp->pNext);
		tmp->pNext = New;
		Size++;
	}
}
	void erase(int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else
		{
			Element* tmp = this->Head;
			for (int i = 0; i < index - 1; i++)
			{
				tmp = tmp->pNext;
			}
			Element* del = tmp->pNext;
			tmp->pNext = del->pNext;
			delete del;
			Size--;
		}
	}

void del()
{
	while (Size){pop_front();}
}

	//				Methods
	void print() const
	{
		Element* Temp = Head;//Temp - это итератор 
		//Итератор - указатель, при помощи которого можно получить доступ
		// к элементам структуры данных
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext; // преход на следующий элемент
		}
	}
};
void main()
{
	setlocale(LC_ALL, "Russian");
	int n; cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	cout << "Add elements to the end of list: " << endl;
	list.push_back(5);
	list.push_back(10);
	list.push_back(3);
	cout << "List of elements: " << endl;
	list.print();
	cout << "Element: " << list[3] << endl;
	cout << "Quantity of elements: " << list.get_Size() << endl;
	cout << "Delete the first element: " << endl;
	list.pop_front();
	cout << "List of elements: " << endl;
	list.print();
	cout << "Insert element: " << endl;
	list.insert(100, 1);
	list.print();
	cout << "Delete element: " << endl;
	list.erase(1);
	list.print();
	cout << "Delete the last element: " << endl;
	list.pop_back();
	list.print();
	cout << "Quantity of elements: " << list.get_Size() << endl;


	
}