template<class ItemType>
void PQType<ItemType>::HeapSort(ItemType values[], int numValues) {
	int index;

	for (index = (numValues/2) - 1; index >= 0; index--)
		ReheapDown(values, index, numValues - 1);

	for (index = numValues - 1; index >= 1; index--) {
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index - 1);
	}

}
