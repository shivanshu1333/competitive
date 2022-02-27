vector<int> getTimeStamps(vector<int> time, vector<int> dir) {
    int n = time.size();
    time.push_back(1E9 + 1E6);
    vector<int> out(n);
    queue<int> q[2];
    int t=time[0];
    int fl=-1;
    for (int i = 0; i < n; i++) {
        q[dir[i]].push(i);
        while (t < time[i + 1]) {
            if (not q[0].empty() and not fl) {
                out[q[0].front()] = t++;
                q[0].pop();
                fl = 0;
            }
            else if (not q[1].empty()) {
                out[q[1].front()] = t++;
                q[1].pop();
                fl = 1;
            }
            else if (not q[0].empty()) {
                out[q[0].front()] = t++;
                q[0].pop();
                fl = 0;
            }
            else {
                t = time[i + 1];
                fl = -1;
            }
        }
    }
    return out;
}