#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int maxDistance(vector<int>& colors){
        int n = colors.size();
        int x=0;
        int y=0;
        for (int i = n-1; i >= 0; i--)
        {
            if(colors[i]==colors[0])
            {
                continue;
            }
            else
            {
                x=i;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (colors[i]==colors[n-1])
            {
                continue;
            }
            else
            {
                y=n-i-1;
                break;
            }
        }
        return max(x,y);
    }
};

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    solution x;
    int value = x.maxDistance(arr);
    cout<<"Maximum distance between two houses with different colors: "<<value<<endl;
    
    return 0;
}