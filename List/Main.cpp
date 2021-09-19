#include <iostream>
using namespace std;

class Element
{
	int Data;
	Element* pNext;
	Element* pPrev;
public:
	Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev) {}
	~Element() {}

	friend class List;
};

class  List
{
	int Size;
	Element* Head;
	Element* Tail;
public:
	int get_Size() { return Size; }

	List()
	{
		Head = nullptr;
		Tail = nullptr;
		Size = 0;
	}

	~List() {}

///////////////////////// Methods ////////////////////////
	 
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pPrev = nullptr;
		New->pNext = Head;
		if (Head != 0)Head->pPrev = New;
		if (Size == 0) Head = Tail = New;
		else Head= New;
		Size++;
	}
	void push_back(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = nullptr;
		New->pPrev = Tail;
		if (Tail != 0) Tail->pNext = New;
		if (Size == 0) Tail = Head = New;
		else Tail = New;
		Size++;
	}
	void pop_front()
	{
		Element* Delete = Head;
		Head = Head->pNext;
		Head->pPrev = nullptr;
		delete Delete;
		Size--;
	}
	void pop_back()
	{
		erase(Size);
	}
	void erase(int index)
	{
		Element* Delete = Head;
		
		for (int i = 0; i < index-1; i++)
		{
			Delete = Delete->pNext;
		}
		Element* Pre = Delete->pPrev;
		Element* Next = Delete->pNext;
		if (Pre != 0 && Size != 0) Pre->pNext = Next;
		else if (Next != 0 && Size != 0) Next->pPrev = Pre;
		else if (index == 0)Head = Next;
		else if (index == Size) Tail = Pre;
		delete Delete;
		Size--;
	}

	void print()
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
	}

};

	
void main()
{
	setlocale(LC_ALL, "Russian");

	List obj;
	int n;
	for (int i = 0; i < 5; i++)
	{
		obj.push_back(rand() % 10);
	}
	cout << "Заполнение двусвязного списка: " << endl;
	obj.print();
	cout << "Удаление последнего элемента: " << endl;
	obj.pop_back();
	obj.print();
	cout << "Удаление одного элемента: "; cin >> n;
	cout << endl;
	obj.erase(n);
	obj.print();
}