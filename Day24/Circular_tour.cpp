#include <bits/stdc++.h>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

class Solution {
public:
    int tour(petrolPump p[], int n) {
        long long int s = 0;
        
        for (int i = 0; i < n; i++)
            s += (p[i].petrol - p[i].distance);
        
        if (s < 0)
            return -1;
    
        int index = 0;
        int c = 0;
        
        for (int i = 0; i < n; i++) {
            c += (p[i].petrol - p[i].distance);
            
            if (c < 0) {
                c = 0;
                index = i + 1;
            }
        }
        
        return index;
    }
};

int main() {

    int n = 4;
    petrolPump p[n] = { 4 ,6 ,7 ,4};
    
    Solution obj;
    int start = obj.tour(p, n);
    
    cout << start << endl;
    
    return 0;
}
