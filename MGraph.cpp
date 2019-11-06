#include <iostream>
#include <queue>
using namespace std;

const int MaxSize = 10;

class MGraph
{
public:
	MGraph(char a[], int n, int e);
	void DFSTraverse()
	{
		int i;
		for (i=0;i<this->vertexNum;i++)
		{
			this->DFSTraverse(i);
		}
	}
	void BFSTraverse()
	{
		int i, j;
		std::queue<int> Q;
		for (i=0;i<this->vertexNum;i++)
		{
			if ( !this->visited[i] )
			{
				std::cout << this->vertex[i] << ' ';
				this->visited[i] = 1;
				Q.push(i);

				while (!Q.empty())
				{
					int t = Q.front();
					Q.pop();
					for (j=0;j<this->vertexNum;j++)
					{
						if ( this->arc[t][j] == 1 && !visited[j] )
						{
							std::cout << this->vertex[j] << ' ';
							visited[j] = 1;
							Q.push(j);
						}
					}
				}
			}
		}
	}
	void DFSTraverse(int v);

	void ClearVisited();
	void Display();//输出顶点值，再输出邻接矩阵
private:
	char vertex[MaxSize];
	int arc[MaxSize][MaxSize];
	int vertexNum, arcNum;
	int visited[MaxSize];
};

MGraph::MGraph(char a[], int n, int e)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            arc[i][j] = 0;
        }
    }
	this->vertexNum = n;
	this->arcNum = e;

	for (int i=0;i<n;i++)
	{
		this->vertex[i] = a[i];
	}

	int i1, i2;
	char _space;
	while ( 1 )
	{
		std::cin >> i1 >> i2;
		std::cin.get(_space);

		this->arc[i1][i2] = arc[i2][i1] = 1;

		if ( _space == ' ' )
			continue;
		else if (_space == '\n')
			break;
	}
}

void MGraph::DFSTraverse(int v)
{
	if (!visited[v])
	{
		int i;
		std::cout << this->vertex[v] << ' ';
		visited[v] = 1;
		for (i=0;i<this->vertexNum;i++)
		{
			if (this->arc[v][i] == 1 && !visited[i] )
			{
				this->DFSTraverse(i);
			}
		}
	}
}

void MGraph::ClearVisited()
{
	for (int i=0;i<vertexNum;i++)
    {
        visited[i] = 0;
    }
}

void MGraph::Display()
{
	int i, j;
    for (i=0;i<vertexNum;i++)
    {
        std::cout << vertex[i] << ' ';
    }
    cout << endl;
	for (i=0;i<this->vertexNum;i++)
	{
		for (j=0;j<this->vertexNum;j++)
		{
			std::cout << this->arc[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	int n = 0;
	int e = 0;

	cin >> n >> e;

	char p[MaxSize];

	int i = 0; 
	int j = 0;

	for (i=0; i<n; i++)
	{
		cin >> p[i];
	}

	MGraph MG(p, n, e);
	
	MG.Display();

	MG.ClearVisited();

	MG.DFSTraverse();
	cout << endl;

	MG.ClearVisited();

	MG.BFSTraverse();
	cout << endl;

	return 0;
}
