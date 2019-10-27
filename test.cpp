#include <iostream>
#include <cstdlib>
#include <string>

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
private:
	int Count;
	std::string vertex[MAXSIZE];
	int Arcs[MAXSIZE][MAXSIZE];
};

int main()
{
	UDGraph graph;
	graph.PrintGraphMatrix();
	return 0;
}