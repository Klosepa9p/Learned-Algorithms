#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);

    for(int i = 0; i < n; i++) {
        int idx = n * arr[i]; // Normalize
        buckets[idx].push_back(arr[i]);
    }

    for(int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    int index = 0;
    for(int i = 0; i < n; i++)
        for(float x : buckets[i])
            arr[index++] = x;
}
