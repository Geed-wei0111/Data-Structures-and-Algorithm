#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>

const int MAXSIZE = 10;
class UDGraph
{
public:
	UDGraph()
	{
		int i, j, temp;
		std::cin >> Count;
		memset(&Arcs, 0, sizeof(Arcs));
		for (i = 0; i < Count; i++)
		{
			char Buffer[10];
			_itoa_s(i, Buffer, 10);
			vertex[i] = "V" ;
			vertex[i] += Buffer;
			vertex[i] += "\0";
		}
		for (i = 0; i < Count; i++)
		{
			for (j = 1; j < Count; j++) 
			{
				if (i == j || i > j)
					continue;
				std::cout << vertex[i] << " and " << vertex[j] << ':';
				std::cin >> temp;
				if (temp == 1)
				{
					Arcs[i][j] = Arcs[j][i] = 1;
				}
				else
				{
					Arcs[i][j] = Arcs[j][i] = 0;
				}
			}
		}
		system("CLS");
	}
	void PrintGraphMatrix()
	{
		int i, j;
		for (i = 0; i < Count; i++)
		{
			std::cout << vertex[i] << '\n';
		}
		for (i = 0; i < Count; i++)
		{
			for (j = 0; j < Count; j++)
			{
				std::cout << Arcs[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
	bool SearchArcs(int i, int j)
	{
		if (Arcs[i][j] == 1)
			return 1;
		else
			return 0;
	}
	bool SearchArcs()
	{
		int i, j;
		std::cout << "I=";
		std::cin >> i;

		std::cout << "J=";
		std::cin >> j;

		i = SearchArcs(i, j);
		return i;
	}
	int GetDegree(int pos)
	{
		int i, count = 0;
		for (i=0;i<Count;i++)
		{
			if ( this->Arcs[pos][i] == 1 )
				count++;
		}
		return count;
	}
	int GetDegree()
	{
		int pos;
		std::cout << "Pos:";
		std::cin >> pos;
		if ( pos >= 0 )
		{
			return GetDegree(pos);
		}
		else
			return -1;
	}

	void BFStraverse()
	{
		std::cout << "BFS:" ;
		int i, j;
		int *visited = new int[Count];
		memset(visited, 0, sizeof(int)*Count);
		std::queue<std::string> Q;
		for (i=0;i<Count;i++)
		{
			if ( !visited[i] )
			{
				std::cout << this->vertex[i] << ' ';
				visited[i] = 1;
				Q.push(this->vertex[i]);

				while ( !Q.empty() )
				{
					std::string temp = Q.front();
					Q.pop();
					int t = temp[1] - '0';
					for (j=0;j<Count;j++)
					{
						if ( this->Arcs[i][j] == 1 && !visited[i] )
						{
							std::cout << this->vertex[i] << ' ';
							visited[i] = 1;
							Q.push(this->vertex[i]);
						}
					}
				}
			}
		}
		delete visited;
		std::cout << std::endl;
		return ;
	}
	void DFStraverse()
	{
		int *visited = new int[Count];
		memset(visited, 0, sizeof(int)*Count);
		if ( Count != 1 )
		{
			std::cout << "DFS:" << this->vertex[0] << ' ';
			visited[0] = 1;
			DFStraverse(visited, 0);
		}
		else
		{
			std::cout <<  "DFS:" << this->vertex[0] << ' ';
		}
		std::cout << std::endl;
		delete visited;
	}
private:
	void DFStraverse(int *visited, int pos)
	{
		int i;
		for (i=0;i<Count;i++)
		{
			if ( this->Arcs[pos][i] == 1 && !visited[i])
			{
				std::cout << this->vertex[i] << ' ';
				visited[i] = 1;
				DFStraverse(visited, i);
			}
		}
	}
	int Count;
	std::string vertex[MAXSIZE];
	int Arcs[MAXSIZE][MAXSIZE];
};

int main()
{
	UDGraph graph;
	graph.PrintGraphMatrix();
	graph.BFStraverse();
	graph.DFStraverse();
	return 0;
}
