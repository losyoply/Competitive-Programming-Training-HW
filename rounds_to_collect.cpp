#include <iostream>
#include <vector>
using namespace std;


int main() 
{
    int n;
    int qq;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> qq;
        a[qq]=i;//qq是第幾個進來的
    }
    int rounds = 0; 
    int start;
    for (int target = 1; target <= n; )
    {
        start=a[target];
        target++;
        for(int i=start;i<=a.size();)
        {
            if(target<=n&&a[target]>start)
            {
                start=a[target];
                target++;
            }
            else
            {
                break;
            }
        }
        rounds++;
    }
    cout << rounds << endl;
    return 0;
}
// int main() 
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     int rounds = 0; 
//     for (int target = 1; target <= n; )
//     {
//         for (int i = 0; i < a.size(); i++) 
//         {
//             if (a[i] == target) 
//             {
//                 a.erase(a.begin() + i);
//                 i--;
//                 target++; 
//             } 
//         }
//         rounds++;
//     }
//     cout << rounds << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int main() 
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     unordered_map<int, int> freq;

//     for (int i = 0; i < n; i++) 
//     {
//         cin >> a[i];
//         freq[a[i]]++;
//     }

//     int rounds = 0;
//     for (int target = 1; target <= n; target++) 
//     {
//         if (freq.find(target) != freq.end() && freq[target] > 0) 
//         {
//             freq[target]--;
//         } 
//         else 
//         {
//             while (freq.find(target) == freq.end() || freq[target] == 0) 
//             {
//                 target++;
//             }
//             freq[target]--;
//         }
//         rounds++;
//     }

//     cout << rounds << endl;
//     return 0;
// }

