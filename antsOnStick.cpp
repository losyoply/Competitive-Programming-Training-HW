#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct Ant {
    int position;
    char direction;
};

int main() {
    int N, L;
    cin >> N >> L;

    vector<Ant> ants(N);
    for (int i = 0; i < N; i++) {
        cin >> ants[i].position >> ants[i].direction;
    }

    int Q;
    cin >> Q;

    while (Q--) 
    {
        int queryTime;
        cin >> queryTime;

        vector<int> positions;
        int antsOn=0;
        int ant_to_go;
        for(int i=0;i<N;i++)
        {
            if(ants[i].direction=='L') ant_to_go=ants[i].position-queryTime;
            else ant_to_go=ants[i].position+queryTime;

            if(ant_to_go<=1||ant_to_go>=L) ;
            else antsOn++;
        }
        cout<<antsOn<<endl;
    }

    return 0;
}


    // while (Q--) {
    //     for (int i = 0; i < N; i++) {
    //         int newPosition = ants[i].position;
    //         if (ants[i].direction == 'L') {
    //             newPosition -= queryTime;
    //         } else {
    //             newPosition += queryTime;
    //         }
    //         positions.push_back(newPosition);
    //     }

    //     sort(positions.begin(), positions.end());

    //     int antsOnStick = 0;
    //     for (int i = 0; i < N; i++) {
    //         if (positions[i] > 0 && positions[i] < L) {
    //             antsOnStick++;
    //         }
    //     }

    //     cout << N - antsOnStick << endl;
    // }
