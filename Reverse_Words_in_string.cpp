 string reverseWords(string s) {
        int i = 0; // I am using i to store starting of every word in string
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ' ') // If whitespace found
            {
                reverse(s.begin() + i, s.begin() + j); //reversing the word
                i = j + 1; //updating i for start of new word
            }
        } 
   reverse(s.begin() + i, s.end()); // to tackle the case for a single word string
        return s;
    }
