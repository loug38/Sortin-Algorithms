template<class ItemType>
void PQType<ItemType>::QuickSort(ItemType values[], int first, int last){
	if (first < last) {

		int splitPoint;

		Split(values, first, last, splitPoint);
		QuickSort(values, first, splitPoint - 1);
		QuickSort(values, splitPoint + 1, last);

	}
}
