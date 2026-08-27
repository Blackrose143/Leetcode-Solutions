class Solution {
public:
    string lexGreaterPermutation(string s, string tar) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        for (int i = n - 1; i >= 0; i--) {

            vector<int> rem = cnt;
            bool pos = true;

            for (int j = 0; j < i; j++) {
                int x = tar[j] - 'a';
                if (rem[x] == 0) {
                    pos = false;
                    break;
                }

                rem[x]--;
            }

            if (!pos)
                continue;

            int t = tar[i] - 'a';
            for (int c = t + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;
                string ans = tar.substr(0, i);
                ans += char('a' + c);
                rem[c]--;
                for (int x = 0; x < 26; x++) {
                    ans.append(rem[x], char('a' + x));
                }
                return ans;
            }
        }

        return "";
    }
};