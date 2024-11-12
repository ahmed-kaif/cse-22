#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
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


double get_median(OrderedMultiset<int> &days, int d)
{
    double median;
    if (d % 2 == 1) {
        median = days.find_by_order(d / 2 );
    } else {
        median = (days.find_by_order(d / 2 - 1) + days.find_by_order(d / 2)) / 2.0;
    }
    return median;
}

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> expenditure(n);

    for (int i = 0; i < n; i++)
    {
        cin >> expenditure[i];
    }

    OrderedMultiset<int>days;
    for(int i=0; i<d ; i++)days.insert(expenditure[i]);
    int notifications = 0;

    for (int i = d; i < n; i++)
    {
        double median = get_median(days, d);
        if (expenditure[i] >= 2 * median)
        {
            notifications++;
        }
        days.insert(expenditure[i]);
        days.erase(expenditure[i - d]);
    }

    cout << notifications << endl;

    return 0;
}
