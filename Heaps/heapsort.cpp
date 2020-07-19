#include<bits/stdc++.h>
using namespace std;
bool compare(int a, int b)
{
	return a > b;
}


void heapify(vector<int> &v , int idx, int size)
{
	int left = 2 * idx + 1 ;
	int right = left + 1;

	int min_idx = idx;
	int last = size - 1;

	if (left <= last and compare(v[left], v[min_idx]))
	{
		min_idx = left;
	}
	if (right <= last and compare(v[right], v[min_idx]))
	{
		min_idx = right;
	}

	if (min_idx != idx)
	{
		swap(v[idx], v[min_idx]);

		heapify(v, min_idx, size);
	}
}
void buildheap(vector<int> &v)
{

	for (int i = (v.size() - 1 / 2); i >= 0; i--)
	{
		heapify(v, i, v.size());
	}
}
void heapsort(vector<int> &arr)
{
	buildheap(arr);
	int n = arr.size();

	while (n)
	{
		swap(arr[0], arr[n - 1]);
		n--;
		heapify(arr, 0, n);
	}
}

int main()
{
	int n;
	cin >> n;
	//heap h;
	vector<int> arr;
	//arr.push_back(-1);
	for (int i = 0; i < n; i++)
	{
		int no;
		cin >> no;
		arr.push_back(no);
		//h.push(no);
	}

	heapsort(arr);
	// while (!h.empty())
	// {
	// 	cout << h.top() << " ";
	// 	h.pop();
	// }

	for (int i = 0; i < arr.size(); i++)

	{
		cout << arr[i] << " ";
	}
	return 0;
}
