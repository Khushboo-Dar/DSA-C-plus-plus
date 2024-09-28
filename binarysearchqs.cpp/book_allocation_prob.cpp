bool ispossible(vector<int> arr,int n, int m,int mid)
{
   int studentcount=1;
   int pagesum=0;
   for(int i=0;i<arr.size();i++)
   {
       if(pagesum+arr[i]<=mid)
       {
           pagesum+=arr[i];
       } else {
           studentcount++;
           pagesum = arr[i];
       }
           if (studentcount > m || arr[i] > mid) {
             return false;

           }
           
       
   }
   return true;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n)
    {
        return -1;
    }
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
sum+=arr[i];

    }
    int e=sum;
    int ans=-1;
   
    while(s<=e)
    { int mid=s+(e-s)/2;
        if(ispossible(arr,n,m,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
      

    }
    return ans;
}