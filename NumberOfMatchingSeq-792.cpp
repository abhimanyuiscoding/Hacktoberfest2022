//-- https://leetcode.com/problems/number-of-matching-subsequences/
//-------Approach 1 -- Two Pointer Approache -- Time Limit Exceed
class Solution {
    bool isSubseq(string s,string t)
    {
      int sptr=0;
        int tptr=0;
        
        while(sptr<s.length() && tptr<t.length())
        {
            int flag=0;
            
            for(int i=tptr;i<t.length();i++)
            {
              if(s[sptr]==t[i])
              {
                  flag=1;
                  sptr++;
                  tptr=i+1;
                  break;
              }
            }
            
            if(flag) continue;
            
            return false;
        }
        
        if(sptr >= s.length()) return true;
        
        return false;
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       if(!s.length()) return 0;
     int count=0;
      for(auto A: words)
      {
          if(isSubseq(A,s)) 
          {
             // cout<<A<<endl;
              count++;
          }
      }
        
        return count;
    }
};

//--- 2nd Approach By Hashing