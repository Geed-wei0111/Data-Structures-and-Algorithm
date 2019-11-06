#include <iostream>
#include <cstdlib>

const int MAXSIZE = 100;
const int Infinity = 65535;
class Net
{
public:
	Net(char a[], int v, int e)
	{
		memset(this->Arc, 0, sizeof(int) * MAXSIZE * MAXSIZE);
		this->edgeNum = e;
		this->vertexNum = v;

		int i;
		for (i = 0; i < v; i++)
		{
			this->Vertex[i] = a[i];
		}

		int j;
		int input;
		for (i = 0; i < v; i++)
		{
			for (j = 0; j < v; j++)
			{
				if (i != j && i < j)
				{
					std::cout << i+1 << " and " << j+1 << ":";
					std::cin >> input;
					this->Arc[i][j] = this->Arc[j][i] = input;
				}
			}
		}
	}

	void PrintMatrix()
	{
		int i, j;
		
		for (i = 0; i < this->vertexNum; i++)
		{
			for (j = 0; j < this->vertexNum; j++)
			{
				std::cout.width(5);
				std::cout << this->Arc[i][j] << ' ';
			}
			std::cout << '\n';
		}
	}
	void MinSpanTree()
	{
		int temp = 0;
		int i, j, k, min = Infinity;
		int lowcost[MAXSIZE];
		int adjvex[MAXSIZE];

		lowcost[0] = 0;
		adjvex[0] = 0;

		for (i = 1; i < this->vertexNum; i++)
		{
			lowcost[i] = Arc[0][i];
			adjvex[i] = 0;
		}

		for (i = 1; i < this->vertexNum; i++)
		{

			for (temp = 0; temp < this->vertexNum; temp++)
			{
				std::cout << lowcost[temp] << ' ';
			}
			std::cout << '\n';
			for (temp = 0; temp < this->vertexNum; temp++)
			{
				std::cout << adjvex[temp] << ' ';
			}
			std::cout << '\n';
			system("PAUSE");

			j = 1; k = 0; min = Infinity;

			while (j < this->vertexNum)
			{
				if (lowcost[j] != 0 && lowcost[j] < min)
				{
					min = lowcost[j];
					k = j;
				}
				j++;
			}
			std::cout << adjvex[k] << "->" << k << std::endl;
			lowcost[k] = 0;

			for (j = 1; j < this->vertexNum; j++)
			{
				if (lowcost[j] != 0 && Arc[k][j] < lowcost[j])
				{
					lowcost[j] = Arc[k][j];
					adjvex[j] = k;
				}
			}
		}
	}
private:
	int vertexNum, edgeNum;
	int Arc[MAXSIZE][MAXSIZE];
	char Vertex[MAXSIZE];
};

int main()
{
	char a[7] = {'1', '2', '3', '4', '5', '6', '\0'};
	Net net(a, 6, 10);
	net.PrintMatrix();
	net.MinSpanTree();
	return 0;
}
