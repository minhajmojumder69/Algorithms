#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int min_mov;
    while (n--)
    {
        int mood;
        cin >> mood;
        sum += mood;
    }   
    if (sum < 0)
    {
        min_mov = (sum-1)/(-2);
    }
    else if (sum > 0)
    {
        min_mov = (sum+1)/2;
    }
    else if (sum == 0)
    {
        min_mov = 0;
    }
    
    cout << min_mov;

  return 0;
}