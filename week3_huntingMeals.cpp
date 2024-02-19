#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

// Create a struct to hold the cat's information
struct Cat {
    string name;
    string position;
    int age;
};

// Define the ordering of positions
map<string, int> position_order = {
    {"elder", 1},
    {"nursy", 2},
    {"kit", 3},
    {"warrior", 4},
    {"appentice", 5},
    {"medicent", 6},
    {"deputy", 7},
    {"leader", 8}
};

// Comparison function for sorting
bool compareCats(const Cat &a, const Cat &b) {
    if (position_order[a.position] != position_order[b.position])
        return position_order[a.position] < position_order[b.position];
    if (a.position == "appentice")
    {
        if(a.age!= b.age) return a.age < b.age;
        else return a.name < b.name;
    }
    if (a.age != b.age)
        return a.age > b.age;
    return a.name < b.name;
}

int main() {
    int N, M;
    
    // Read until EOF
    while (cin >> N >> M) {
        vector<Cat> cats(N);
        
        // Read cat information
        for (int i = 0; i < N; ++i) {
            cin >> cats[i].name >> cats[i].position >> cats[i].age;
        }
        
        // Sort cats based on the custom comparison function
        sort(cats.begin(), cats.end(), compareCats);
        
        // Output the names of cats based on the order they receive meals
        for (int i = 0; i < M && i < N; ++i) {
            cout << cats[i].name << endl;
        }
    }
    
    return 0;
}
