//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            
            String input[] = read.readLine().split(" ");
            String a = input[0];
            
            Solution ob = new Solution();
            if(ob.sameFreq(a)){
                System.out.println(1);
            }
            else{
                System.out.println(0);
            }
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    boolean sameFreq(String s) {
        // code here
        int freq[] = new int[26];
        for(char c: s.toCharArray()) freq[c - 'a']++;
        int count[] = new int[s.length() + 1];
        for(int i = 0 ; i < 26; i++) count[freq[i]]++;
        int cnt = 0, operations = 0, firstNonZero = 0;
        boolean firstNonZeroFound = false;
        if(count[1] > 1){firstNonZero = 1;firstNonZeroFound = true;}
        for(int i = 2; i < count.length; i++){
            if(count[i] > 0 && !firstNonZeroFound){
                firstNonZero = i;
                firstNonZeroFound = true;
            }
            if(count[i] > 0) cnt++;
            if(firstNonZeroFound) operations += count[i] * (i - firstNonZero);
        }
        if(count[1] == 1) {cnt--; operations++;};
        if(cnt > 2) return false;
        return operations <= 1;
    }
}