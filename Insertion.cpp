template<class ItemType>
void PQType<ItemType>::InsertionSort(ItemType values[], int numValues){
	for (int count = 0; count < numValues; count++)
		InsertItem(values, 0, count);
}