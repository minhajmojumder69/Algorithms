#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ts;
    cin >> ts;
    while (ts--)
    {
        string s1,s2;
        cin >> s1 >> s2;

        if(s1.size() != s2.size())
            cout << "NO\n";
        else
        {
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            if (s1 == s2)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }
    return 0;
}