#include <iostream>
using namespace std;

class Tree

{

	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) : Data(Data), pLeft(pLeft), pRight(pRight) {}
		~Element(){}

		friend class Tree;
	}*Root;

public:
	Element* getRoot() const
	{
		return Root;
	}
	Tree() :Root(Root) {}
	~Tree() {}
	void insert(int Data)
	{
		insert(Data, Root);
	}
	int minValue() const
	{
		return minValue(Root);
	}
	int maxValue() const
	{
		return maxValue(Root);
	}
	int Count() const
	{
		return Count(Root);
	}
	int Sum() const
	{
		return Sum(Root);
	}
	void print()const
	{
		print(this->Root);
		cout << endl;
	}
private:
	void insert(int Data, Element* Root)
	{
		
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)
			{
				Root->pLeft = new Element(Data);
			}
			else
			{
				insert(Data, Root->pLeft);
			}
		}
		else if(Data>Root->Data)
		{
			if (Root->pRight)insert(Data, Root->pRight);
			else Root->pRight = new Element(Data);
		}
	}

	int minValue(Element* Root) const
	{
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/
		return Root->pLeft ? minValue(Root->pLeft) : Root->Data;
	}

	int maxValue(Element* Root) const
	{
		return Root->pRight ? maxValue(Root->pRight) :Root->Data;
	}
	int Count(Element* Root) const
	{
		/*if (Root == nullptr )return 0;
		else return Count(Root->pLeft) + Count(Root->pRight)+1;*/
		return Root ? Count(Root->pLeft) + Count(Root->pRight) + 1:0;
	}
	int Sum(Element* Root)const
	{
		return Root == nullptr ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}
	void print(Element* Root) const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
};
void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();
	cout << "Минимальное значение в дереве: " << tree.minValue() << endl;
	cout << "Максимальное значение в дереве: " << tree.maxValue() << endl;
	cout <<"Количество элементов в дереве: " << tree.Count() << endl;
	cout << "Сумма всех элементов в дереве: " << tree.Sum() << endl;
}