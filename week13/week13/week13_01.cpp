#include <iostream>
#include <queue>
using namespace std;
// Container Adapters: An Example of PQ

int main()
{
	priority_queue<int, vector<int>, less<int> > pq;
	pq.push(5);
	pq.push(9);
	pq.push(1);
	pq.push(4);
	pq.push(10);
	pq.push(14);

	pq.pop();
	pq.pop();

	cout << "pq top: " << pq.top() << endl;

	if (!pq.empty())
		cout << "pq size: " << pq.size() << endl;
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}