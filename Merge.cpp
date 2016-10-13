template<class ItemType>
void PQType<ItemType>::MergeSort(ItemType values[], int first, int last){
	if (first < last){
		int middle = (first + last) / 2;
		MergeSort(values, first, middle);
		MergeSort(values, middle + 1, last);
		Merge(values, first, middle, middle + 1, last);
	}
}