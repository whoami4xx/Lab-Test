#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    return (double)a.value / a.weight >
           (double)b.value / b.weight;
}

double fractionalKnapsack(int capacity,vector<Item>& items) {

    // Sort by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0;

    for (auto item : items) {

        if (capacity == 0)
            break;

        // Take full item
        if (item.weight <= capacity) {

            capacity -= item.weight;
            totalValue += item.value;
        }

        // Take fraction
        else {

            double fraction =(double)capacity / item.weight;
            totalValue += item.value * fraction;
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {

    int capacity = 50;

    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    cout << fractionalKnapsack(capacity, items);

    return 0;
}