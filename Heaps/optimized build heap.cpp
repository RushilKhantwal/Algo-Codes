#include<bits/stdc++.h>
using namespace std;
bool compare(int a, int b)
{
	return a > b;
}
class heap
{
	vector<int>v;
	bool minHeap;;
	bool compare(int a, int b)
	{
		if (minHeap)
			return a < b;
		else
			return a > b;
	}
	void heapify(int idx)
	{
		int left = 2 * idx;
		int right = 2 * idx + 1;

		int min_idx = idx;
		int last = v.size() - 1;

		if (left <= last and compare(v[left], v[idx]))
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

			heapify(min_idx);
		}
	}

public:
	heap(int default_size = 10, bool type = true)
	{
		v.reserve(default_size);
		v.push_back(-1); // BLOCKING THE 0TH INDEX
		minHeap = type;
	}
	void push(int d)
	{
		v.push_back(d);

		int idx = v.size() - 1;
		int parent = idx / 2;

		while (idx > 1 and compare(v[idx], v[parent]))
		{
			swap(v[idx], v[parent]);
			idx = parent;
			parent /= 2;
		}
	}
	int top()
	{
		return v[1];
	}

	void pop()
	{
		int last = v.size() - 1;
		swap(v[1], v[last]);

		v.pop_back();
		heapify(1);
	}
	bool empty()
	{
		return v.size() == 1;
	}
};

void heapify(vector<int> &v , int idx)
{
	int left = 2 * idx ;
	int right = left + 1;

	int min_idx = idx;
	int last = v.size() - 1;

	if (left <= last and compare(v[left], v[idx]))
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

		heapify(v, min_idx);
	}
}
void buildheap(vector<int> &v)
{
	for (int i = (v.size() - 1 / 2); i >= 1; i--)
	{
		heapify(v, i);
	}
}
int main()
{
	int n;
	cin >> n;
	//heap h;
	vector<int> arr;
	arr.push_back(-1);
	for (int i = 0; i < n; i++)
	{
		int no;
		cin >> no;
		arr.push_back(no);
		//h.push(no);
	}

	buildheap(arr);
	// while (!h.empty())
	// {
	// 	cout << h.top() << " ";
	// 	h.pop();
	// }

	for (int i = 1; i < arr.size(); i++)

	{
		cout << arr[i] << " ";
	}
	return 0;
}
