#include <bits/stdc++.h>
using namespace std;


/* There are 2^n subsets of a set and we are basically using the and operator to determine the set bits in the bitmasks of all the integers from 0 to 2^n - 1 and then we are insering all those elements of the vector of the indices where the bits are set. */
vector<vector<int>> subsetGenerator(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> subsets;
    int l = (1<<n);
    for(int i=0; i<l; i++)
    {
        vector<int> subset;
        for(int j=0; j<n; j++)
        {
            if((i & (1<<j))!=0)
            {
                subset.push_back(v[j]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}

int main()
{
	int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    auto subsets = subsetGenerator(v);
    for(auto &el:subsets)
    {
        for(auto &i:el)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}