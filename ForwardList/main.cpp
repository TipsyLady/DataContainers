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
	Element* Head;//голова списка - указывает на начальный(нулевой) элемент списка
public:
	ForwardList()
	{
		Head = nullptr; //Конструктор по умолчанию, создает пустой список
		//Если HEAD указывает на ноль, то список пуст, те. не содержит эл-ов
		// и HEAD больше не на что указывать.
		cout << "L_Constructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "L_Destructor:\t" << this << endl;
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
	list.print();
}