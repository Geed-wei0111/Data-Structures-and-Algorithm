#include <iostream>
#include <stack>

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
	~BiTree() { Release(root); }
	void RePreOrder() { RePreOrder(root); }
	int Empty()
	{
		if (root)
			return 0;
		else
			return 1;
	}
private:
	BiNode* root;
	BiNode* Creat(BiNode* bt);
	void RePreOrder(BiNode* bt);
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

std::stack<char> stack;

void BiTree::RePreOrder(BiNode* bt)
{
	if (bt == nullptr)
		return;
	else
	{
		RePreOrder(bt->lchild);
		RePreOrder(bt->rchild);
		stack.push(bt->data);
	}
}
int main()
{
	
	while (1)
	{
		BiTree *A = new BiTree;
		A->RePreOrder();
		if (A->Empty())
		{
			std::cout << "NULL" << std::endl;
			delete A;
			break;
		}
		else
		{
			while (!stack.empty())
			{
				char ch = stack.top();
				if (stack.size() != 1)
					std::cout << ch << ' ';
				else
					std::cout << ch << '\n';
				stack.pop();
			}
		}
		delete A;
	}
	return 0;
}