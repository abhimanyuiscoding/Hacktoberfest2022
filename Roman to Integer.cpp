   int romanToInt(string s) {
        unordered_map <char, int> um;
        
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        
        int ans = 0;
        int prev = 0;
        
        for(int c : s)
        {
            if(prev < um[c])
            {
                ans = ans - prev - prev;
            }
            ans += um[c];
            prev = um[c];
        }
        return ans;
    }
