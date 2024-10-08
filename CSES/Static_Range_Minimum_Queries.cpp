#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7;
class SegmentTree {
private:
    vector<int> segTree;
    int n;
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            segTree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node+1, start, mid);
            build(arr, 2*node+2, mid+1, end);
            segTree[node] = min(segTree[2*node+1], segTree[2*node+2]);
        }
    }
    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return INF;
        }
        if (L <= start && end <= R) {
            return segTree[node];
        }
        int mid = (start + end) / 2;
        int leftMin = query(2*node+1, start, mid, L, R);
        int rightMin = query(2*node+2, mid+1, end, L, R);
        return min(leftMin, rightMin);
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        segTree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    int rangeMinQuery(int L, int R) {
        return query(0, 0, n - 1, L, R);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; 
    }
    SegmentTree segTree(v);
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << segTree.rangeMinQuery(a, b) << '\n';
    }

    return 0;
}
