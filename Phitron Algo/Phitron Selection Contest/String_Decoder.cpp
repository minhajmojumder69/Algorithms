#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i+=2)
        {
            char l = s[i];
            int nm = s[i+1] - '0';

            for (int j = 0; j < nm; j++)
            {
                cout << l;
            }
            
        }
        cout << endl;
        
    }
    
  return 0;
}