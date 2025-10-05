#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> count(max_val+1, 0);

    for(int x : arr) count[x]++;
    int index = 0;
    for(int i = 0; i <= max_val; i++) {
        while(count[i]-- > 0) arr[index++] = i;
    }
}
