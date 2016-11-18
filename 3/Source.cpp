#define JUDGE
#ifdef JUDGE
#include <fstream>
std::ifstream cin("antiqs.in");
std::ofstream cout("antiqs.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <vector>

void AntiQSort(std::vector<int>& arr, int left, int right, int& value)
{
	int pivot = (right + left) / 2;
	arr[pivot] = value--;

	if (pivot < right && value > 0)
	{
		AntiQSort(arr, pivot + 1, right, value);
	}
	if (left < pivot && value > 0)
	{
		AntiQSort(arr, left, pivot, value);
	}
}

int main() {
	int N;
	cin >> N;

	std::vector<int> arr(N);

	int temp = N;
	AntiQSort(arr, 0, N - 1, temp);

	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		cout << arr[i] << " ";
	}
	cout << arr[N - 1];
	
	return 0;
}