#include<algorithm>
int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sumstore;
	
	int n=arr.size();
	for(int i=0;i<n;i++)
	{int sum=0;
		for(int j=i;j<n;j++)
		{
       sum+=arr[j];
	   sumstore.push_back(sum);
		}
	}
	sort(sumstore.begin(),sumstore.end());
	return sumstore[sumstore.size()-k];
}

/* approach 2- tc=o(k)
#include <queue>
int getKthLargest(vector<int> &arr, int k) {
  priority_queue<int, vector<int>, greater<int>> mini;

  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += arr[j];
      if (mini.size() < k) {
        mini.push(sum);
      } else {
        if (sum > mini.top()) {
          mini.pop();
          mini.push(sum);
        }
      }
    }
  }
  return mini.top();
}
*/