package chapter1

import (
	"fmt"
	"unicode"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func max3(a, b, c int) int {
	return max(max(a, b), c)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func min3(a, b, c int) int {
	return min(min(a, b), c)
}

/*
1.1: Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures?

Idea #1: Use a map -> O(n) space at worst, O(n) time
Idea #2: If we are dealing with characters, most probably we can use a frequency vector of length 26
*/
func IsUnique(s string) bool {
	hasLetter := make(map[rune]bool)

	for _, letter := range s {
		if _, ok := hasLetter[letter]; ok {
			return false
		}

		hasLetter[letter] = true
	}

	return true
}

/*
1.2: Check Permutation: Given two strings, write a method to decide if one is a permutation of the
other.

Idea #1: Use 2 maps and compare them
Complexity Analysis

	Time: 	2 * O(n) for building the freq maps
			2 * O(n) for traversing them
			Total: O(n)
	Space: 2 maps of size O(n)
			Total: O(n)
*/
func CheckPermutation(s, t string) bool {

	if len(s) != len(t) {
		return false
	}

	freq1 := make(map[rune]int)
	freq2 := make(map[rune]int)

	for _, letter := range s {
		freq1[letter] = freq1[letter] + 1
	}
	for _, letter := range t {
		freq2[letter] = freq2[letter] + 1
	}

	/* Characters in s with other frequencies than in t */
	for letter, frequency := range freq1 {
		if freq2[letter] != frequency {
			return false
		}
	}

	/* Check if there are characters in t with a different frequency than in s */
	for letter, frequency := range freq2 {
		if freq1[letter] != frequency {
			return false
		}
	}

	return true
}

/*
1.3. URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. (Note: If implementing in Java, please use a character array so that you can
perform this operation in place.)

Idea: We keep a running offset that tells us how much the non-whitespace characters in the initial string
have to move to the left. The offset increases with each whitespace found.

Complexity:

	Time: O(n)
	Space: O(n)
*/
func URLify(s string) string {
	ans := make([]byte, len(s))
	ansIdx := 0

	for i := 0; i < len(s); i++ {
		ans[i] = s[i]
	}

	for i := 0; i < len(s) && ansIdx < len(ans); i++ {
		if s[i] == ' ' {
			ans[ansIdx] = '%'
			ans[ansIdx+1] = '2'
			ans[ansIdx+2] = '0'
			ansIdx = ansIdx + 3
		} else {
			ans[ansIdx] = s[i]
			ansIdx += 1
		}
		fmt.Printf("ans = %v\n", string(ans))
	}

	return string(ans)
}

/*
1.4. Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

Idea: Construct a map of frequencies. It's palindrome iff all letters occur an even number of times, except for one
group of letters, which can have odd frequency count

Complexity:

	Time: O(n), 2 traversals (string + map)
	Space: O(n) for the map
*/
func IsPalindromePermutation(s string) bool {
	frequency := make(map[rune]int)

	for _, letter := range s {
		if letter == ' ' {
			continue
		}
		lower := unicode.ToLower(letter)
		frequency[lower] = frequency[lower] + 1
	}

	hasOdd := false
	for _, freq := range frequency {
		switch {
		case freq%2 != 0 && hasOdd:
			return false
		case freq%2 != 0:
			hasOdd = true
		}
	}

	return true
}

/*
1.5. One Away: There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.

Idea: Use Dynamic Programming and parse the two strings with 2 different indices i and j.
DP[i][j] is the edit distance between s[0:i] and t[0:j]. At each step, we check s[i] == t[j]

if s[i] == t[j], then dp[i+1][j+1] = dp[i][j]. Recall that dp[i][j] = dist(s[0:i], t[0:j])
Then, dp[i+1][j+1] = dist(s[0:i+1], t[0:j+1]) = dist(s[0:i] || s[i+1], t[0:j] || t[j+1]) =
dist(s[0:i], t[0:j]) + 1 or 0, depending on whether s[i+1] == t[j+1].

if s[i] != t[j], then we take the min of the three variants
- dp[i-1][j] = dist(s[0:i-1], t[0:j]), it takes dp[i-1][j] to get from s[0:i-1] to t[0:j], after which we add s[i]
- dp[i-1][j-1] = dist(s[0:i-1], t[0:j-1]), it takes dp[i-1][j-1] to get from s[0:i-1] to t[0:j-1], after which we add s[i]
- dp[i][j-1] = dist(s[0:i], t[0:j-1]), it takes dp[i][j-1] to get from s[0:i] to t[0:j-1], after which we add t[j]

so, min3 of all these + one edit
*/
func IsOneOrLessAway(s, t string) bool {
	m := len(s)
	n := len(t)

	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}

	for i := 1; i <= m; i++ {
		dp[i][0] = i
	}

	for j := 1; j <= n; j++ {
		dp[0][j] = j
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if s[i-1] == t[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = min3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
			}
		}
	}

	return dp[m][n] <= 1
}
