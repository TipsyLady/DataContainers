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
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
			cout << "It_Constructor:\t" << this << endl;
		}
		~Iterator()
		{
			cout << "It_Destructor:\t" << this << endl;
		}
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}

		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*() const
		{
			return this->Temp->Data;
		}
		 int& operator*() 
		{
			return this->Temp->Data;
		}
	};
	Iterator begin()
	{
		return this->Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	int get_Size() { return Size; }
	ForwardList()
	{
		Head = nullptr; //Конструктор по умолчанию, создает пустой список
		//Если HEAD указывает на ноль, то список пуст, те. не содержит эл-ов
		// и HEAD больше не на что указывать.
		Size = 0;
		cout << "L_Constructor:\t" << this << endl;
	}
	ForwardList (const initializer_list<int>& il) :ForwardList()
	{
		cout << typeid (il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			this->push_back(*it);
		}
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		//Конструктор копирования выполняет DeepCopy
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext) 
			push_back(Temp->Data);
	}
	~ForwardList()
	{
		del();
		cout << "L_Destructor:\t" << this << endl;
	}
	//			Operators
	ForwardList& operator=(const ForwardList& other)
	{
		//1- удалить старое значение объекта
		while (Head) pop_front();
		//Конструктор копирования выполняет DeepCopy
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		return *this;
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

		while (tmp->pNext)
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
		////Итератор - указатель, при помощи которого можно получить доступ
		//// к элементам структуры данных
		//while (Temp != nullptr)
		//{
		//	cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		//	Temp = Temp->pNext; // преход на следующий элемент
		//}
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
	}
};

//#define BASE_CHECK
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef BASE_CHECK
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
#endif // BASE_CHECK

	ForwardList list = { 3,5,8,13,21 };
	list.print();
	/*ForwardList list2;
	list2 = list;
	list2.print();*/
	for (int i : list)
	{
		cout << i << "  ";
	}
	cout << endl;
}