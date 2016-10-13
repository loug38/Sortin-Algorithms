template<class ItemType>
void PQType<ItemType>::SelectionSort(ItemType values[], int numValues){
	int endIndex = numValues - 1;
	for (int current = 0; current < endIndex; current++)
		Swap(values[current], values[MinIndex(values, current, endIndex)]);
}//SelectionSort
