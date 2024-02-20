// QUESTION
// Given a string s and a dictionary of n words dictionary, find out if a s can be segmented into a space-separated sequence of dictionary words. Return 1 if it is possible to break the s into a sequence of dictionary words, else return 0. 

// Note: From the dictionary dictionary each word can be taken any number of times and in any order.

// Example 1:

// Input:
// n = 6
// s = "ilike"
// dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
// Output:
// 1
// Explanation:
// The string can be segmented as "i like".
// Example 2:

// Input:
// n = 6
// s = "ilikesamsung"
// dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
// Output:
// 1
// Explanation:
// The string can be segmented as 
// "i like samsung" or "i like sam sung".
// Your Task:
// Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. You don't need to read any input or print any output, it is done by driver code.

// Expected Time Complexity: O(len(s)2)
// Expected Space Complexity: O(len(s))

// Constraints:
// 1 ≤ n ≤ 12
// 1 ≤ len(s) ≤ 1100
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class TrieNode {
    TrieNode[] children;
    boolean isEndOfWord;

    public TrieNode() {
        children = new TrieNode[26];
        isEndOfWord = false;
    }
}
class Solution {
    static TrieNode root;

    public static int wordBreak(int n, String s, ArrayList<String> dictionary) {
        // Initialize the root of the trie
        root = new TrieNode();
        // Build the trie 
        for (String word : dictionary) {
            insert(word);
        }
        // Check if the string can be segmented using the trie
        return canSegmentString(s, root) ? 1 : 0;
           
    }

    static boolean canSegmentString(String s, TrieNode root) {
        int n = s.length();
        if (n == 0)
            return true;
        TrieNode current = root;
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (current.children[ch - 'a'] == null)
                return false;
            current = current.children[ch - 'a'];
            if (current.isEndOfWord && canSegmentString(s.substring(i + 1), root))
                return true;
        }
        return false;
    }

    static void insert(String word) {
        TrieNode current = root;
        for (char ch : word.toCharArray()) {
            int index = ch - 'a';
            if (current.children[index] == null)
                current.children[index] = new TrieNode();
            current = current.children[index];
        }
        current.isEndOfWord = true;
    }
}
