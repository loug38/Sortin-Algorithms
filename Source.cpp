#include "Header.h"

int main(){
	int input = 0;
	PQType<int> p;
	
	do{
		cout << "1. Selection" << endl;
		cout << "2. Bubble" << endl;
		cout << "3. Insertion" << endl;
		cout << "4. Heap" << endl;
		cout << "5. Quick" << endl;
		cout << "6. Merge" << endl;
		cout << "7. Exit" << endl;
		cin >> input;

		switch (input){
		case 1:
			p.SelectionSort(p.info.section, 10);
			p.Output();
			break;
		case 2:
			p.BubbleSort(p.info.section, 10);
			p.Output();
			break;
		case 3:
			p.InsertionSort(p.info.section, 10);
			p.Output();
			break;
		case 4:
			p.HeapSort(p.info.section, 10);
			p.Output();
			break;
		case 5:
			p.QuickSort(p.info.section, 0, 9);
			p.Output();
			break;
		case 6:
			p.MergeSort(p.info.section, 0, 9);
			p.Output();
			break;
		}
	} while (input != 7);

}