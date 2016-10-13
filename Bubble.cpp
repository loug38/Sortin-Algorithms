
template <class ItemType>
void PQType<ItemType>::BubbleSort(ItemType values[], int numValues){
	int current = 0;
	while (current < numValues - 1){
		BubbleUp(values, current, numValues - 1);
		current++;
	}
}