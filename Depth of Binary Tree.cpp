#include<iostream>

class BiNode
{
public:
	char data;
	BiNode* lchild, * rchild;
};
class BiTree
{
public:
	BiTree() { root = Creat(root); }
	int Depth() { return Depth(root); }
private:
	BiNode* root;
	BiNode* Creat(BiNode* root);
	int Depth(BiNode* root);
};
BiNode* BiTree::Creat(BiNode* bt)
{
	char ch;
	std::cin >> ch;
	if (ch == '#')
		bt = NULL;
	else
	{
		bt = new BiNode; bt->data = ch;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}
	return bt;
}
int BiTree::Depth(BiNode* bt)
{
	int left = 0, right = 0;
	if (bt == nullptr)
		return 0;
	else
	{
		left = Depth(bt->lchild);
		right = Depth(bt->rchild);
		if (left > right)
		{
			return left + 1;
		}
		else
			return right + 1;
	}
}

int main()
{
	int D = 0;
	while (1)
	{
		BiTree *A = new BiTree;
		D = A->Depth();
		delete A;
		if (D != 0)
			std::cout << D << std::endl;
		else
		{
			std::cout << 0 << std::endl;
			break;
		}
	}
	return 0;
}