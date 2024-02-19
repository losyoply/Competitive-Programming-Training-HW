#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
//TLE
using namespace std;

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    int turn;
    set<pair<int, int>> alice_steps, bob_steps;
    pair<int,int> apos={0,0}, bpos={0,0};

    int time =0;
    int dir=0;
    for(int i=0;i<n;i++)
    {
        cin>>turn;
        if(dir==0)
        {
            for(time;time<turn-1;time++)
            {
                apos={apos.first, apos.second+1};
                alice_steps.insert(apos);
                
            }
        }
        else
        {
            for(time;time<turn-1;time++)
            {
                apos={apos.first+1, apos.second};
                alice_steps.insert(apos);
            }
        }

        if(dir==0) dir=1;
        else dir=0;
        
    } 
    if(dir==0)
    {
        for(time;time<k;time++)
        {
            apos={apos.first, apos.second+1};
            alice_steps.insert(apos);
            
        }
    }
    else
    {
        for(time;time<k;time++)
        {
            apos={apos.first+1, apos.second};
            alice_steps.insert(apos);
        }
    }


    dir=1;
    time=0;
    for(int i=0;i<m;i++)
    {
        cin>>turn;
        if(dir==0)
        {
            for(time;time<turn-1;time++)
            {
                bpos={bpos.first, bpos.second+1};
                bob_steps.insert(bpos);
            }
        }
        else
        {
            for(time;time<turn-1;time++)
            {
                bpos={bpos.first+1, bpos.second};
                bob_steps.insert(bpos);
            }
        }

        if(dir==0) dir=1;
        else dir=0;
        
    } 
    if(dir==0)
    {
        for(time;time<k;time++)
        {
            bpos={bpos.first, bpos.second+1};
            bob_steps.insert(bpos);
        }
    }
    else
    {
        for(time;time<k;time++)
        {
            bpos={bpos.first+1, bpos.second};
            bob_steps.insert(bpos);
        }
    }



    // 计算紫色格子的数量
    set<pair<int, int>> purple_steps;
    set_intersection(alice_steps.begin(), alice_steps.end(),
                     bob_steps.begin(), bob_steps.end(),
                     inserter(purple_steps, purple_steps.begin()));
    

    int purple = purple_steps.size();
    int red = alice_steps.size()-purple;
    int blue = bob_steps.size()-purple;

    cout << red << " " << blue << " " << purple << endl;

    // // 打印 Alice 的步伐
    // cout << "Alice's steps:" << endl;
    // for (const auto& step : alice_steps) {
    //     cout << "(" << step.first << ", " << step.second << ")" ;
    // }

    // // 打印 Bob 的步伐
    // cout << "Bob's steps:" << endl;
    // for (const auto& step : bob_steps) {
    //     cout << "(" << step.first << ", " << step.second << ")" ;
    // }

    return 0;
}
