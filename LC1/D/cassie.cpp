














long long recursion (vector<vector<long long> > objs, int index) {
    long long ans = 0;
    ans += objs[index-1][0];
    int required = objs[index-1][1];
    if (required == 0) {
        return ans;
    } else {
        for (int k = 1; k <= required; k++) {
            ans += recursion(objs, objs[index-1][k+1]);
        }
        return ans;
    }
}

int main() {
    long long n, q;
    cin >> n >> q;
    vector<vector<long long> > objs;
    //vector<int> objs_for_sort;
    //input 
    for (int i = 0; i < n; i++) {
        vector <long long> obj;
        long long time, amount;
        cin >> time >> amount;
        obj.push_back(time);
        obj.push_back(amount);
        for (int j = 0; j < amount; j++) {
            long long pre;
            cin >> pre;
            obj.push_back(pre);
        }
        objs.push_back(obj);
        //objs_for_sort.push_back(obj[1]);
        //objs_for_sort.push_back(i);
    }

    //sort(objs_for_sort.begin(), objs_for_sort.end());
    //sort
   

    //query
    for (int i = 0; i < q; i++) {
        char ins;
        cin >> ins;
        if (ins == 'Q') {
            int index;
            cin >> index;
            long long ans;
            ans = recursion(objs, index);
            cout << ans << endl;
        }
        if (ins == 'M') {
            long long num, new_time;
            cin >> num >> new_time;
            objs[num-1][0] = new_time;
        }
    }
    return 0;
} 
