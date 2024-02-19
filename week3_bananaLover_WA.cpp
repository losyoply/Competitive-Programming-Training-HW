#include <iostream>
#include <vector>
#include <algorithm>
#include<tuple>

using namespace std;
bool comp(tuple<int, int, int, int> a,tuple<int, int, int, int> b)
{
    if(get<0>(a)!=get<0>(b)) return get<0>(a)>get<0>(b);
    else if(get<1>(a)!=get<1>(b)) return get<1>(a)>get<1>(b);
    else if(get<2>(a)!=get<2>(b)) return get<2>(a)>get<2>(b);
    else return get<3>(a)<get<3>(b);
}
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin >> N;
        
        vector<vector<int>> groups;
        vector<tuple<int, int, int, int>> sortKeys;

        for (int i = 0; i < N; i++) 
        {
            int K;
            cin >> K;
            vector<int> group(K);
            int totalMilk = 0;
            int maxMilk = 0;
            for (int j = 0; j < K; j++) 
            {
                cin >> group[j];
                totalMilk += group[j];
                maxMilk = max(maxMilk, group[j]);
            }
            groups.push_back(group);
            sortKeys.push_back(make_tuple(totalMilk, maxMilk, K, i));
        }

        // Sort based on the criteria
        sort(sortKeys.begin(), sortKeys.end(), comp);

        // Output the groups in sorted order
        for (const auto& key : sortKeys) 
        {
            int index = get<3>(key);
            for (const int& milk : groups[index]) 
            {
                cout << milk << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
