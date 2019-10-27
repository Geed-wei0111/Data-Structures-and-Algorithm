#include <iostream>

struct BiNode
{
	char data;
	int ltag, rtag;
	BiNode* lchild, *rchild;
};

class ThrBiTree {
public:
	ThrBiTree() 
	{ 
		root = Create(root);
		BiNode* p = new BiNode;
		p->ltag = 0;
		p->rtag = 1;
		p->rchild = p;
		if (root == nullptr)
		{
			p->lchild = p;
		}
		else
		{
			p->lchild = root;
			pre = p;
			MakeThread(root);
			pre->rchild = nullptr;
			pre->rtag = 1;
		}
		delete p;
	}
//	~ThrBiTree() { Release(root); }

	void PreOrder() { PreOrder(root); }
	void InOrder() 
	{ 
		if (root == nullptr)
			return;
		BiNode* p = root;
		while (p->ltag == 0)
			p = p->lchild;
		std::cout << p->ltag << ' '<< p->data << ' ' << p->rtag << '\n';
		while (p->rchild != nullptr)
		{
			BiNode* q = nullptr;
			if (p->rtag == 1)
				q = p->rchild;
			else
			{
				q = p->rchild;
				while (q->ltag == 0)
					q = q->lchild;
			}
			p = q;
			std::cout << p->ltag << ' ' << p->data << ' ' << p->rtag << '\n';
		}
	}
private:
	BiNode* Create(BiNode* bt)
	{
		char ch;
		std::cin >> ch;
		if (ch != '#')
		{
			bt = new BiNode;
			bt->data = ch;
			bt->lchild = Create(bt->lchild);
			bt->ltag = 0;

			bt->rchild = Create(bt->rchild);
			bt->rtag = 0;

			return bt;
		}
		else
			return nullptr;
	}
	void Release(BiNode* bt)
	{
		if (bt == nullptr)
			return;
		else
		{
			Release(bt->lchild);
			Release(bt->rchild);
			delete bt;
		}
	}
	void PreOrder(BiNode* bt)
	{
		if (bt == nullptr)
			return;
		else
		{
			std::cout << bt->data << ' ';
			PreOrder(bt->lchild);
			PreOrder(bt->rchild);
		}
	}
	void MakeThread(BiNode* bt)
	{
		if (bt == nullptr)
			return;
		MakeThread(bt->lchild);
		if (bt->lchild == nullptr)
		{
			bt->ltag = 1;
			bt->lchild = pre;
		}
		if (pre->rchild == nullptr)
		{
			pre->rtag = 1;
			pre->rchild = bt;
		}
		pre = bt;
		MakeThread(bt->rchild);
	}

	BiNode* pre;
	BiNode* root;
};

int main()
{
	ThrBiTree tree;
	tree.InOrder();
	return 0;
}