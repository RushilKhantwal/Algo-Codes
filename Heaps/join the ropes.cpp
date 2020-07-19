int join_ropes(int ropes[],int n)
{
	priority_queue<int,vector<int>,greater<int>> pq(ropes,ropes+n);
	//Creates min heap out of the required input array

	int cost=0;
	while(pq.size()>1)
	{
		int A = pq.top();
		pq.pop();
		int B = pq.top();
		pq.pop();

		int newrope = (A+B);

		cost+= newrope;
		pq.push(newrope);
	}
	return cost;
}
