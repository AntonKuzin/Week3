#define JUDGE
#ifdef JUDGE
#include <fstream>
std::ifstream cin("sort.in");
std::ofstream cout("sort.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <vector>

static std::vector<int*> pointers;

int* Merge(int* arr1, int size1, int* arr2, int size2)
{
	int size = size1 + size2;
	int* tempArr = new int[size];

	pointers.push_back(tempArr);

	int temp1 = 0, temp2 = 0;

	while (temp1 < size1 && temp2 < size2)
	{
		if (arr1[temp1] <= arr2[temp2])
			tempArr[temp1 + temp2] = arr1[temp1++];
		else
			tempArr[temp1 + temp2] = arr2[temp2++];
	}

	for (size_t i = temp1; i < size1; i++)
	{
		tempArr[temp1 + temp2] = arr1[temp1++];
	}

	for (size_t i = temp2; i < size2; i++)
	{
		tempArr[temp1 + temp2] = arr2[temp2++];
	}

	return tempArr;
}

int* MergeSort(int* arr, int size)
{
	if (size == 1)
	{
		return arr;
	}
	int pivot = size / 2;
	return Merge(MergeSort(&arr[0], pivot), pivot, MergeSort(&arr[pivot], size - pivot), size - pivot);
}

int main() {
	int N;
	cin >> N;

	int* arr = new int[N];
	pointers.push_back(arr);
	for (size_t i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	arr = MergeSort(arr, N);

	for (size_t i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}

	for (size_t i = 0; i < pointers.size(); i++)
	{
		delete pointers[i];
	}
	return 0;
}