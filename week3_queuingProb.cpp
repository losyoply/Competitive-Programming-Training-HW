#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <utility> // For std::pair
using namespace std;
//TLE
// We will use a hashmap to keep track of the queue number and iterator for each person
unordered_map<int, int> personPositionMap;


// Function to process instruction type 0
void processInstruction0(vector<list<int>>& queues, int a, int b) {
    auto& aPos = personPositionMap[a];
    auto& bPos = personPositionMap[b];

    // Remove person a from queueA and add to the back of person b
    // queues[queueA.first].remove(a);
    list<int>::const_iterator ait,bit;
    for(auto it =queues[aPos].cbegin(); it!=queues[aPos].cend(); ++it)
    {
        if(*it==a) 
        {
            ait=it;
            break;
        }
    }
    for(auto it =queues[bPos].cbegin(); it!=queues[bPos].cend(); ++it)
    {
        if(*it==b) 
        {
            bit=it;
            break;
        }
    }
    queues[bPos].splice(++bit, queues[aPos], ait);
    // Update the hashmap for person a
    aPos=bPos;

}

// Function to process instruction type 1
void processInstruction1(vector<list<int>>& queues, int a, int b) {
    // Move all people in queue a to the back of queue b
    if (a != b && !queues[a - 1].empty()) {
        queues[b - 1].splice(queues[b - 1].end(), queues[a - 1]);
    }
    for (auto& pair : personPositionMap) {
        if (pair.second == a-1) {
            pair.second = b-1;
        }
    }
}

// Function to print the final queues
void printQueues(const vector<list<int>>& queues) {
    for (int i = 0; i < queues.size(); ++i) {
        cout << "#" << (i + 1) << ":";
        for (int person : queues[i]) {
            cout << " " << person;
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<list<int>> queues(n);
    for (int i = 0; i < n; ++i) {
        queues[i].push_back(i + 1);
        // Initialize the hashmap with the person's position
        personPositionMap[i + 1] = i; //第幾個queue的哪個位置
    }

    while (m--) {
        int instruction, a, b;
        cin >> instruction >> a >> b;

        if (instruction == 0) {
            processInstruction0(queues, a, b);
        } else if (instruction == 1) {
            processInstruction1(queues, a, b);
        }
    }

    printQueues(queues);

    return 0;
}
