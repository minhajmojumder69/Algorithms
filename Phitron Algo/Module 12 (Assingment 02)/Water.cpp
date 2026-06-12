#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ts;
    cin >> ts;
    while (ts--)
    {
        int n;
        cin >> n;
        int h[n]; 
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        int max_idx = 0, sec_mx = -1;
        for (int i = 1; i < n; i++)
        {
            if (h[i] > h[max_idx])
            {
                sec_mx = max_idx;
                max_idx = i;
            }
            else if(sec_mx == -1 || h[i] > h[sec_mx])
                sec_mx = i;
            
        }
        if (max_idx < sec_mx)
        {
            cout << max_idx << " " << sec_mx << endl;
        }
        else
            cout << sec_mx << " " << max_idx << endl;
        
    }
    
    return 0;
}