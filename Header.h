#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


template<class ItemType>
struct Info{
	int course[10];
	int section[10];
};


template <class ItemType>
class PQType{
public:
	PQType();
	void SelectionSort(ItemType values[], int numValues);
	void BubbleSort(ItemType values[], int numValues);
	void InsertionSort(ItemType values[], int numValues);
	void MergeSort(ItemType values[], int first, int last);
	void HeapSort(ItemType values[], int numValues);
	void QuickSort(ItemType values[], int first, int last);
	void Output();
	Info<ItemType> info;

private:
	void Split(ItemType values[], int first, int last, int& splitPoint);
	void ReheapDown(ItemType values[], int root, int bottom);
	inline void Swap(ItemType& item1, ItemType& item2);
	int MinIndex(ItemType values[], int startIndex, int endIndex);
	void InsertItem(ItemType values[], int startIndex, int endIndex);
	void BubbleUp(ItemType values[], int startIndex, int endIndex);
	void Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst,
		int rightLast);
	Info<ItemType> copy;

};


template<class ItemType>
PQType<ItemType>::PQType(){
	fstream dataFile("load.txt", ios::in);

	if (dataFile.is_open()){
		for (int i = 0; i < 10; i++){
			dataFile >> info.course[i];
			dataFile >> info.section[i];
		}
	}

	for (int i = 0; i < 10; i++){
		copy.course[i] = info.course[i];
		copy.section[i] = info.section[i];
	}
	dataFile.close();
}//Constructor

template<class ItemType>
inline void PQType<ItemType>::Swap(ItemType& item1, ItemType& item2){
	ItemType tempItem;

	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}//Sweep

template<class ItemType>
void PQType<ItemType>::Output(){
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (info.section[i] == copy.section[j])
				info.course[i] = copy.course[j];

	for (int i = 0; i < 10; i++)
		cout << info.course[i] << " " << info.section[i] << endl;
}//output



//********************************FOR INSERT SORT********************************
template<class ItemType>
int PQType<ItemType>::MinIndex(ItemType values[], int startIndex, int endIndex){
	int indexOfMin = startIndex;
	for (int index = startIndex + 1; index <= endIndex; index++)
	if (values[index] < values[indexOfMin])
		indexOfMin = index;
	return indexOfMin;
}//minIndex

template<class ItemType>
void PQType<ItemType>::InsertItem(ItemType values[], int startIndex, int endIndex){
	bool finished = false;
	int current = endIndex;
	bool moreToSearch = (current != startIndex);

	while (moreToSearch && !finished){
		if (values[current] < values[current - 1]){
			Swap(values[current], values[current - 1]);
			current--;
			moreToSearch = (current != startIndex);
		}else
			finished = true;
	}
}//InsertItem


//********************************FOR BUBBLE SORT********************************
template <class ItemType>
void PQType<ItemType>::BubbleUp(ItemType values[], int startIndex, int endIndex){
	for (int index = endIndex; index > startIndex; index--)
	if (values[index] < values[index - 1])
		Swap(values[index], values[index - 1]);
}//BubbleUp

//********************************FOR HEAP SORT********************************
template<class ItemType>
void PQType<ItemType>::ReheapDown(ItemType values[], int root, int bottom){
	int max, right, left;

	left = root * 2 + 1;
	right = root * 2 + 2;
	if (left <= bottom){
		if (left == bottom)
			max = left;
		else{
			if (values[left] <= values[right])
				max = right;
			else
				max = left;
		}
		if (values[root] < values[max]){
			swap(values[root], values[max]);
			ReheapDown(values, max, bottom);
		}
	}
}//ReheapDown

//********************************FOR MERGE SORT********************************
template<class ItemType>
void PQType<ItemType>::Merge(ItemType values[], int leftFirst,	int leftLast, int rightFirst,
	int rightLast){

	ItemType tempArray[10000];
	int index = leftFirst;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast)){
		if (values[leftFirst] < values[rightFirst]){
			tempArray[index] = values[leftFirst];
			leftFirst++;
		}else{
			tempArray[index] = values[rightFirst];
			rightFirst++;
		}
		index++;
	}

	while (leftFirst <= leftLast){
		tempArray[index] = values[leftFirst];
		leftFirst++;
		index++;
	}

	while (rightFirst <= rightLast){
		tempArray[index] = values[rightFirst];
		rightFirst++;
		index++;
	}

	for (index = saveFirst; index <= rightLast; index++)
		values[index] = tempArray[index];

}//Merge

//********************************FOR QUICK SORT*************************************
template<class ItemType>
void PQType<ItemType>::Split(ItemType values[], int first, int last, int& splitPoint){

	ItemType splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;

	first++;
	do{
		onCorrectSide = true;
		while (onCorrectSide){
			if (values[first] > splitVal)
				onCorrectSide = false;
			else{
				first++;
				onCorrectSide = (first <= last);
			}
		}

		onCorrectSide = (first <= last);
		while (onCorrectSide){
			if (values[last] <= splitVal)
				onCorrectSide = false;
			else{
				last--;
				onCorrectSide = (first <= last);
			}
		}

		if (first < last){
			Swap(values[first], values[last]);
			first++;
			last--;
		}

	} 
	while (first <= last);

	splitPoint = last;
	Swap(values[saveFirst], values[splitPoint]);

}//Split

#include "Merge.cpp"
#include "Quick.cpp"
#include "Heap.cpp"
#include "Selection.cpp"
#include "Bubble.cpp"
#include "Insertion.cpp"