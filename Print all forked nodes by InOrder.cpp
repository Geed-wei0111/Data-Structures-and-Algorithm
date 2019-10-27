#include <iostream>

struct BiNode
{
	char data;
	BiNode* lchild, * rchild;
};

class BiTree
{
public:
	BiTree() { root = Creat(root); }
	void InOrder() { InOrder(root); }
	int Empty()
	{
		if (root == NULL)
			return 1;
		else
			return 0;
	}
private:
	BiNode* root;
	BiNode* Creat(BiNode* bt);
	void InOrder(BiNode* bt);
};

BiNode* BiTree::Creat(BiNode* bt)
{
	char ch;
	std::cin >> ch;
	if (ch == '#')
		return NULL;
	else
	{
		bt = new BiNode;
		bt->data = ch;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}
	return bt;
}

void BiTree::InOrder(BiNode* bt)
{
	if (bt == nullptr)
		return;
	InOrder(bt->lchild);
	if (bt->lchild != nullptr || bt->rchild != nullptr)
	{
		std::cout << bt->data << ' ';
	}
	InOrder(bt->rchild);
	return;
}

int main()
{
	BiTree btree;
	btree.InOrder();
	return 0;
}
