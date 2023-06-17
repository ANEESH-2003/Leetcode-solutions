//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int a[], int b[], int na, int nb, int k)
    {
        if(na>nb)
            return kthElement(b,a,nb,na,k);
        int l=max(0,k-nb),r=min(k,na);
        while(l<=r)
        {
            int mid=(l+r)/2;
            int mid2=k-mid;
        //cout<<l<<" "<<r<<" "<<mid<<" "<<mid2<<"\n";
            int l1=mid==0?INT_MIN:a[mid-1];
            int l2=mid2==0?INT_MIN:b[mid2-1];
            int r1=mid==na?INT_MAX:a[mid];
            int r2=mid2==nb?INT_MAX:b[mid2];
            if(l1<=r2 && l2<=r1)
                return max(l1,l2);
            else if(l1>r2)
                r=mid-1;
            else
                l=mid+1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends