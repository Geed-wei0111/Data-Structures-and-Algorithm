#include <iostream>
#include <queue>
using namespace std;

struct Arcnode
{
	int adjvex;
	Arcnode *next;
};

struct Vertexnode
{
	char vertex;
	Arcnode *firstedge;
};

const int Maxsize = 20;

class ALgraph
{
public:
	ALgraph(char a[],int n,int e);	
	void DFSTraverse();
	void BFSTraverse();	
	void Show();
	void Clearvisited();

private:
	void DFSTraverse(int v);
	void BFSTraverse(int v);

	Vertexnode adjlist[Maxsize];
	int visited[Maxsize];
	int vertexnum;
	int arcnum;
};

ALgraph::ALgraph(char a[],int n,int e)
{
	int i;
	this->vertexnum = n;
	this->arcnum = e;
	for (i=0;i<this->vertexnum;i++)
	{
		adjlist[i].vertex = a[i];
		adjlist[i].firstedge = nullptr;
	}
	
	int input1, input2;
	char _space;
	Arcnode* neo = nullptr;
	while ( 1 )
	{
		std::cin >> input1 >> input2;
		std::cin.get(_space);

		neo = new Arcnode;
		neo->adjvex = input2;
		neo->next = adjlist[input1].firstedge;
		adjlist[input1].firstedge = neo;

		if ( _space == '\n' )
			break;
	}
}

void ALgraph:: DFSTraverse()
{
	int i;
	for (i=0; i<vertexnum; i++)
	{
		if (visited[i] == 0)
		{
			DFSTraverse(i);
		}
	}
}

void ALgraph::DFSTraverse(int v)
{
	if ( !visited[v] )
	{
		Arcnode* p = adjlist[v].firstedge;
		std::cout << this->adjlist[v].vertex << ' ';
		this->visited[v] = 1;
		while ( p )
		{
			this->DFSTraverse(p->adjvex);
			p = p->next;
		}
	}
}

void ALgraph:: BFSTraverse()
{
	int i;
	for (i=0; i<vertexnum; i++)
	{
		if (visited[i] == 0)
		{
			BFSTraverse(i);
		}
	}
}
void ALgraph::BFSTraverse(int v)
{
	if ( !visited[v] )
	{
		std::queue<int> Q;
		std::cout << adjlist[v].vertex << ' ';
		Q.push(v);

		int temp = 0;
		while ( !Q.empty() )
		{
			temp = Q.front();
			Q.pop();
			Arcnode *p = adjlist[temp].firstedge;
			while ( p )
			{
				if ( !visited[p->adjvex] )
				{
					Q.push(p->adjvex);
					std::cout << adjlist[p->adjvex].vertex << ' ';
					visited[p->adjvex] = 1;	
				}
				p = p->next;
			}
		}
	}
}

void ALgraph::Clearvisited()
{
	int i;
	for (i = 0;i < vertexnum;i++)
	{
		visited[i] = 0;
	}
}

void ALgraph::Show()
{
	int i;
	for (i=0;i<this->vertexnum;i++)
	{
		std::cout << this->adjlist[i].vertex << ' ';
	}
	std::cout << std::endl;

	for (i=0;i<this->vertexnum;i++)
	{
		std::cout << this->adjlist[i].vertex << ' ';
		Arcnode* p = adjlist[i].firstedge;
		while ( p )
		{
			std::cout << p->adjvex << ' ';
			p = p->next;
		}
		std::cout << '\n';
	}
}

int main()
{
	int i,n,m;
	cin >>n>>m;

	char *b = new char[n];
	for (i = 0;i < n;i++)
	{
		cin >>b[i];
	}
	
	ALgraph a(b,n,m);
	a.Show();

	a.Clearvisited();

	a.DFSTraverse();
	cout <<endl;

	a.Clearvisited();

	a.BFSTraverse();
	delete b;
	return 0;
}
