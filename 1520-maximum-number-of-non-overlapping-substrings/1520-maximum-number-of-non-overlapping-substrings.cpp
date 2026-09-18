class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        
        vector<int> order,F,L,cnt(26);
        F.resize(26,-1);
        L.resize(26,-1);
        
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (cnt[c] == 0) {
                F[c] = i;
                order.push_back(c);
            }

            cnt[c]++;
            L[c] = i;
        }

        vector<string> res;
        deque<array<int, 3>> queue;

        for (int c : order) {
            queue.push_front({F[c], L[c], cnt[c]});

            int l = INT_MAX;
            int r = INT_MIN;
            int tot = 0;

            for (auto vc : queue) {
                tot += vc[2];
                l = min(l, vc[0]);
                r = max(r, vc[1]);

                if (tot == r - l + 1) {
                    break;
                }
            }

            if (tot == r - l + 1) {
                string str = s.substr(l, r - l + 1);
                res.push_back(str);
                queue.clear();
            }
        }

        return res;
    }
};