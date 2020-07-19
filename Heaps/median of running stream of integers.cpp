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
	priority_queue<int> leftheap;
	priority_queue<int,vector<int>,greater<int>> rightheap;

	int d;
	cin>>d;
	leftheap.push(d);
	float med = d;
	cout<<" Median	"<< med << " ";

	cin>>d;

	while(d != -1)
	{
		//logic
		if(leftheap.size()>rightheap.size())
		{
			if(d<med)
			{
				rightheap.push(leftheap.top());
				leftheap.pop();
				leftheap.push(d);
			}
			else
			{
				rightheap.push(d);
			}
			med = (rightheap.top() + leftheap.top())/2.0;

		}
		else if(leftheap.size() == rightheap.size())
		{
			if(d<med)
			{
				leftheap.push(d);
				med = leftheap.top();
			}
			else
			{
				rightheap.push(d);
				med = rightheap.top();
			}
		}
		else
		{
			if(d>med)
			{
				leftheap.push(rightheap.top());
				rightheap.pop();
				rightheap.push(d);

			}
			else
			{
				leftheap.push(d);
			}
			med = (rightheap.top() + leftheap.top())/2.0;
		}

		cout<<"Med "<< med <<endl;
		cin>>d;
	}
	return 0;
}

------------------------------------------------------------------------------------------------------------------------

HACKERBLOCKS CODE
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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int d;
		cin >> d;
		priority_queue<int>leftheap;
		priority_queue<int, vector<int>, greater<int>> rightheap;

		leftheap.push(d);
		int med = d;
		cout << med << " ";
		n--;
		while (n--)
		{
			cin >> d;
			//logic
			if (leftheap.size() > rightheap.size())
			{
				if (d < med)
				{
					rightheap.push(leftheap.top());
					leftheap.pop();
					leftheap.push(d);
				}
				else
				{
					rightheap.push(d);
				}
				med = (rightheap.top() + leftheap.top()) / 2.0;

			}
			else if (leftheap.size() == rightheap.size())
			{
				if (d < med)
				{
					leftheap.push(d);
					med = leftheap.top();
				}
				else
				{
					rightheap.push(d);
					med = rightheap.top();
				}
			}
			else
			{
				if (d > med)
				{
					leftheap.push(rightheap.top());

					rightheap.pop();
					rightheap.push(d);

				}
				else
				{
					leftheap.push(d);
				}
				med = (rightheap.top() + leftheap.top()) / 2.0;
			}
			cout << med << " ";
		}
	}
	return 0;
}
