#include<bits/stdc++.h>
using namespace std;

struct Item {
	int value, weight;

	// Constructor
	Item(int value, int weight)
	{
	this->value=value;
	this->weight=weight;
	}
};
class cmp{
    public:
bool operator() (pair<int,int> a, pair<int,int>b)
{
	double ratioA = a.first/(a.second + 0.0);
	double ratioB = b.first/(b.second + 0.0);

	return ratioA < ratioB;
}
};

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int n)
{
	priority_queue < pair<int,int> , vector<pair<int,int > >, cmp>pq;

	for(int i=0;i<n;++i)
	{
		pq.push({arr[i].value,arr[i].weight});
	}

	double final_profit = 0.0;
	while(!pq.empty()){
		int weight = pq.top().second;
		int profit = pq.top().first;
		pq.pop();

		if(weight <= W)
		{
			final_profit += profit;
			W -= weight;
		}else{
			double ratio = profit / (weight + 0.0);
			final_profit += ratio * W;
			break;
		}
	}

	return final_profit;
}

int main(){
int W = 50; // Weight of knapsack
Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 }};

int n = sizeof(arr) / sizeof(arr[0]);

// Function call
cout << "Maximum value we can obtain = "
	<< fractionalKnapsack(W, arr, n);
}