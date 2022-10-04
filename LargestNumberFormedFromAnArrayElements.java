/**
 * Greedy based problem from GFG Practice: Largest Number Formed From An Array
 * Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.
 * The result is going to be very large, hence return the result in the form of a string.
 * Sample Input:
	5
	3 30 34 5 9
 * Sample Output:
	9534330
 * 
 * Problem ref. link: https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
 * 
 * 
**/

import java.util.*;
import java.io.*;

public class LargestNumberFormedFromAnArrayElements {
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            int n = Integer.parseInt(br.readLine().trim());
            String[] arr = br.readLine().trim().split(" ");

            String ans = new Solution().printLargest(arr);
            System.out.println(ans);
        }
    }
}

class Solution {
	// Time: O(n log n)		Space: O(1)
    String printLargest(String[] arr) {
        Arrays.sort(arr, new Comparator<String>(){
            @Override
            public int compare(String a, String b) {
                return (b + a).compareTo(a + b);
            }
        });
        return Arrays.toString(arr).replaceAll("\\[|]|,| ", "");
    }
}

