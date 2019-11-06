#include <iostream>
#include <cstdlib>
const int MAXSIZE = 100;

class Graph
{
public:
	Graph(char a[], int v, int n)
	{
		memset(this->Begin, 0, sizeof(int) * MAXSIZE);
		memset(this->End, 0, sizeof(int) * MAXSIZE);
		memset(this->Weight, 0, sizeof(int) * MAXSIZE);
		int i, j;
		this->edgeNum = n;
		this->vertexNum = v;
		for (i = 0; i < this->edgeNum; i++)
		{
			this->Vertex[i] = a[i];
		}
		
		for (i = 0; i < this->edgeNum; i++)
		{
			std::cout << "edge" << i << ":";
			std::cin >> this->Begin[i];
			std::cin >> this->End[i];
			std::cin >> this->Weight[i];
		}
		system("CLS");
	}

	void SortForKruskal()
	{
		int i, j;
		for (i = 0; i < this->edgeNum - 1; i++)
			for (j = 0; j < this->edgeNum - 1 - i; j++)
				if ( Weight[j] > Weight[j+1] )
				{
					int temp1 = Begin[j];
					Begin[j] = Begin[j + 1];
					Begin[j + 1] = temp1;

					int temp2 = End[j];
					End[j] = End[j + 1];
					End[j + 1] = temp2;

					int temp3 = Weight[j];
					Weight[j] = Weight[j+1];
					Weight[j + 1] = temp3;
				}
	}
	void ShowList()
	{
		int i;
		for (i = 0; i < this->edgeNum; i++)
		{
			std::cout << i << " : " << this->Begin[i] << "->" << this->End[i] << "  " << this->Weight[i] << std::endl;
		}
	}
	void MinSpanKruskal()
	{
		int i, n, m, WPL = 0;
		int* parent = new int[this->edgeNum];
		this->SortForKruskal();
		memset(parent, 0, sizeof(int) * this->edgeNum);

		for (i = 0; i < this->edgeNum; i++)
		{
			n = this->Find(parent, Begin[i]);
			m = this->Find(parent, End[i]);

			if (n != m)
			{
				parent[n] = m;
				WPL += Weight[i];
				std::cout << "(" << Begin[i] << ',' << End[i] << ")=" << Weight[i] << std::endl;
			}
		}
		std::cout << "WPL=" << WPL << std::endl;
		delete[] parent;
	}
private:
	char Vertex[MAXSIZE];
	int Begin[MAXSIZE];
	int End[MAXSIZE];
	int Weight[MAXSIZE];

	int edgeNum;
	int vertexNum;

	int Find(int *parent, int pos)
	{
		while (parent[pos] > 0)
		{
			pos = parent[pos];
		}
		return pos;
	}
};

int main()
{
	char a[10] = {'0', '1', '2', '3', '4', '5' ,'6' ,'7', '8', '\0'};
	Graph g(a, 9, 15);
	g.ShowList();
	g.MinSpanKruskal();
	return 0;
}
