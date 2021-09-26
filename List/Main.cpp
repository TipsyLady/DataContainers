#include <iostream>
using namespace std;

template <typename T> 
class  List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev) {}
		~Element() {}
		friend class List;
	}*Head, *Tail;
	int Size;
	
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{}
		~Iterator()
		{}
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
		bool operator == (const Iterator& other) const
		{
			return this->Temp == other.Temp;
		}
		bool operator != (const Iterator& other) const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
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
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	class ReverseIterator
	{
		Element* Temp;
		ReverseIterator(Element* Temp = nullptr) :Temp(Temp)
		{

		}
		~ReverseIterator()
		{

		}
	};

	int get_Size()const { return Size; }

	List()
	{
		Head = Tail = nullptr;
		Size = 0;
	}
	List(const initializer_list<T>& il) : List()
	{
		for (T const* it = il.begin(); it != il.end(); it++) { push_back(*it); }
	}
	List(const List<T>& other) :List()
	{
		for (Element* Temp = other.Head; Temp; Temp++)push_back(Temp->Data);
		
	}
	~List() { while (Tail) pop_back(); }
	/////////////////////Operators////////////////////////
	List<T>& operator=(const List<T>& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
		
		return *this;
	}
	
///////////////////////// Methods ////////////////////////
	 
	void push_front(T Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
		}
		else
		{
			/*Element* New = new Element(Data);
			New->pNext = Head;
			Head->pPrev = New;
			Head = New;*/
			Head = Head->pPrev = new Element(Data, Head);
		}
		Size++;

	}
	void push_back(T Data)
	{
		if (!Head && !Tail) return push_front(Data);
		/*Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;*/
		Tail = Tail->pNext = new Element(Data, 0 , Tail);
		Size++;
	}
	void pop_front()
	{
		//1. Проверить не является ли удаляемый элемент списка последним
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		Size--;
	}
	void pop_back()
	{
		if (Head == Tail) return pop_front();
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		Size--;
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
	void insert(T Data,int index)
	{
		Element* tmpN = this->Head;
		for (int i = 0; i < index - 1; i++)
				{
					tmpN = tmpN->pNext;
				}
		Element* New = new Element(Data);
		Element* tmpP = tmpN->pPrev;
		tmpP->pNext = New;
		New->pNext = tmpN;
		New->pPrev = tmpP;
		tmpN->pPrev = New;	
		Size++;

	}

	void print() const
	{
		cout << "Адрес начала списка: " << Head << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		cout << "Количество элементов списка: " << this->Size << endl;
	}
	void reverse_print()
	{
		cout << "Адрес конца списка: " << Head << endl;
		for (Element* Temp=Tail; Temp; Temp= Temp->pPrev)
		cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		cout << "Количество элементов списка: " << this->Size << endl;
	}

};

//#define BASE_CHECK	
//#define Container

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef BASE_CHECK

	List obj;
	int n;
	cout << "Введите размер списка: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		obj.push_back(rand() % 100);
	}
	/*cout << "Заполнение двусвязного списка: " << endl;
	obj.print();
	obj.reverse_print();
	cout << "Удаление последнего элемента: " << endl;
	obj.pop_back();
	obj.print();
	cout << "Удаление одного элемента: "; cin >> n;
	cout << endl;
	obj.erase(n);
	obj.print();*/
	obj.print();
	obj.insert(10, 2);
	obj.print();
#endif // BASE_CHECK
#ifdef Container
	List list = { 3,5,8,13,21 };
	list = list;
	list.print();
	//List list2 = list; //Copy_Constructor
	List list2;			//Default Constructor
	list2 = list;		//Copy_Assignment
	list2.print();
	for (List::Iterator it = list2.begin(); it != list2.end(); ++it)
	{
		cout << *it << "\t";
	}
#endif // Container

	int arr[] = { 3,5,8,13,21 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << arr[i] << "  " ;
	}
	cout << endl;
	for (int i : arr) //Range-base for (для работы с контейнерами)
	{
		cout << i << "  ";
	}
	cout << endl;

	// for(type i : container)
	//{  i-iterator;}

	List<int> list = { 0,1,1,2,3,5,8,13,21 };
	for (int i : list) // type i - тип данных в контейнере
	{
		cout << i << "  ";
	}
	cout << endl;
}