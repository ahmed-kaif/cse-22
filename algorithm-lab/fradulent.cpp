#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>struct OrderedMultiset {
    int id;
    ordered_set<pair<T, int>> st;
    OrderedMultiset() {id = 0;}
    void insert(T val) {st.insert({val, id++});}
    void erase(T val) {st.erase(st.lower_bound({val, 0}));} 
    int order_of_key(T val) {return st.order_of_key({val, 0});}
    T find_by_order(int val) { pair<T, int> p = *st.find_by_order(val); return p.first;}
    typename ordered_set<pair<T,int>>::iterator lower_bound(T val) {return st.lower_bound({val, 0});}
    typename ordered_set<pair<T, int>>::iterator upper_bound(T val) {return st.upper_bound({val, id});}
    int size() {return st.size();}
    void clear() { st = ordered_set<pair<T, int>>();}
};
// find_by_order, order_of_key

int get_median(multiset<int>& window, int d) {
    auto mid = next(window.begin(), d / 2);
    if (d % 2 == 0) {
        return ((*mid) + *prev(mid, 1)) / 2.0;
    }
    return *mid;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        cin >> expenditure[i];
    }

    OrderedMultiset<int> window(expenditure.begin(), expenditure.begin() + d);
    int notifications = 0;

    for (int i = d; i < n; i++) {
        int median = get_median(window, d);
        if (expenditure[i] >= 2 * median) {
            notifications++;
        }
        window.insert(expenditure[i]);
        window.erase(window.lower_bound(expenditure[i - d]));
    }

    cout << notifications << endl;

    return 0;
}
