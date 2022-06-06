#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<vector>
using namespace std;

struct Processes {
	int pid;
	int ar;
	int bt;
	
	int process_size;
};
int main()
{
	int m_size;
	int page_size;
	int qt;
	int cs, n;

	ifstream in;
	in.open("Processes.txt");
	in >> n;
	in >> m_size;
	in >> page_size;
	in >> qt;
	in >> cs;
	Processes pro[5];
	for (int i = 0; i < n; i++)
	{
		in >> pro[i].pid;
		in >> pro[i].ar;
		in >> pro[i].bt;
		in >> pro[i].process_size;


	}
	cout << endl << endl;

	cout << "\t \t \t \tAYAT ABUALLAN 191060" << endl;
	cout  << endl << endl << endl;

	cout << "PageTable of memory  : \n";
	cout << endl;
	cout << "Process number :\tPage number :\tFrame number :" << endl << endl;
	vector<int> random;
	int modulas = m_size / page_size;
	vector<int>page;
	int r1 = rand() % modulas;
	random.push_back(r1);
	int count = 0;
	for (int u = 0; u < n; u++) {

		if (pro[u].process_size <= m_size - page_size * (r1 - 1))

			for (int j = 0; j < pro[u].process_size / page_size; j++) {
				int r1 = rand() % modulas;
				int i;
				for (i = 0; i < modulas; i++) {
					if (r1 == random[i])
						r1 = (rand()) % modulas;

					else
						break;
				}
				random.push_back(r1);
				int o;
				for (o = 0; o < i - 1; o++)
				{
					if (random[o] == r1) {
						r1 = (rand()) % modulas;
						random[i] = r1;
					}
					if (random[o] == r1) {
						r1++;
						random[i] = r1;
					}
				}

				cout << endl << "\t" << u << "    \t\t    " << j << "  \t\t  " << r1;
				page.push_back(r1);
				count++;
			}

	}
	cout << endl << endl << endl;


	//The memory map of the physical memory showing filled frames and free frames


	vector<int> filledFrames;
	vector<int>freeFrames;
	for (int i = 0; i < page.size(); i++) {
		int v = page[i];
		filledFrames.push_back(v);
	}
	int o = 0; bool cheack = true;
	for (int i = 0; i < modulas; i++) {
		for (int t = 0; t < filledFrames.size(); t++) {
			if (i == filledFrames[t])
				cheack = false;
		}


		if (cheack == true)
		{
			freeFrames.push_back(i);
			o++;
		}
		cheack = true;
	}
	cout << endl;
	cout << " Filled Frames  :    ";
	for (int i = 0; i < filledFrames.size(); i++) {
		cout << filledFrames[i] << "   ";
	}
	cout << endl;
	cout << " Free Frames  :    ";
	for (int i = 0; i < freeFrames.size(); i++) {
		cout << freeFrames[i] << "  ";
	}



	cout << endl << endl;
	cout << "The mapping \n";
	cout << endl;
	int logical;
	while (true) {
		cout << "enter  logical address and if you want to cancele enter zero  :";
		cin >> logical;
		if (logical == 0)
			return 0;
		else if (logical <= m_size) {
			cout << "  Page : " << logical / page_size << endl << "  Displacement : " << logical % page_size << endl;
			cout << "  Frame : " << page[(logical / page_size)] << endl;
			cout << "  Phsical address : " << (((page[logical / page_size]) * page_size) + (logical % page_size)) << endl << endl << endl;
		}
		else
			cout << "your address is too long !\n";

	}

	system("pause");
	return 0;
}