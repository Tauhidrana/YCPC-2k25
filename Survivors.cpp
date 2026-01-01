#include <bits/stdc++.h>
using namespace std;

bool canSurvive(long long hours, vector<long long>& r, long long T) {
    int n = r.size();
    vector<long long> dryness(n, 0);
    long long water = 0;
    
    for (long long h = 0; h < hours; h++) {
        // Increase dryness for all plants
        for (int i = 0; i < n; i++) {
            dryness[i] += r[i];
        }
        
        // Check if any plant died before watering
        for (int i = 0; i < n; i++) {
            if (dryness[i] >= T) {
                return false;
            }
        }
        
        // Receive 1 unit of water
        water += 1;
        
        // Water plants greedily (highest dryness first)
        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return dryness[a] > dryness[b];
        });
        
        for (int i = 0; i < n; i++) {
            int idx = indices[i];
            if (dryness[idx] >= T) {
                if (water > 0) {
                    dryness[idx] = 0;
                    water--;
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    long long N, T;
    cin >> N >> T;
    vector<long long> r(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }
    
    
    long long left = 0, right = 1e18;
    long long ans = 0;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canSurvive(mid, r, T)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}
