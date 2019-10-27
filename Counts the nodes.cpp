#include<iostream>

struct Binode
{
	char data;
	Binode* lchild, * rchild;
};

class Bitree
{
public:
	Bitree() { root = Creat(root); }
	~Bitree() { Release(root); }
	int Count() { return Count(root); }
private:
	int n;
	Binode* root;
	Binode* Creat(Binode* bt);
	void Release(Binode* bt);
	int Count(Binode* bt);
};
Binode* Bitree::Creat(Binode* bt)
{
	char d;
	std::cin >> d;
	if (d == '#')
		bt = NULL;
	else
	{
		bt = new Binode;
		bt->data = d;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}
	return bt;
}
void Bitree::Release(Binode* bt)
{
	if (bt != NULL)
	{
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}
int Bitree::Count(Binode* bt)
{
	static int sum = 0;
	if (bt == nullptr)
		return 0;
	else
	{
		sum++;
		Count(bt->lchild);
		Count(bt->rchild);
	}
	return sum;
}
int main()
{
	Bitree a;
	int temp = a.Count();
	if (temp != 0)
		std::cout << temp << std::endl;
	else
		std::cout << "NULL" << std::endl;
	return 0;
}