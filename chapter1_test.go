package chapter1

import (
	"testing"
)

func TestIsUnique(t *testing.T) {
	testCases := map[string]struct {
		want bool
		str  string
	}{
		"empty": {
			want: true,
			str:  "",
		},
		"short unique": {
			want: true,
			str:  "a",
		},
		"short nonunique": {
			want: false,
			str:  "aa",
		},
		"long unique": {
			want: true,
			str:  "abcdefghijklmnopqrstuvwxyz",
		},
	}

	for description, tc := range testCases {
		t.Run(description, func(t *testing.T) {
			got := IsUnique(tc.str)
			want := tc.want

			if got != want {
				t.Fatalf("Got(%t) != Want(%t)", got, want)
			}

		})
	}
}
func TestCheckPermutation(t *testing.T) {
	testCases := map[string]struct {
		want bool
		s    string
		t    string
	}{
		"empty": {
			want: true,
			s:    "",
			t:    "",
		},
		"short permuted": {
			want: true,
			s:    "ab",
			t:    "ba",
		},
		"short non permuted": {
			want: false,
			s:    "ab",
			t:    "ca",
		},
		"long permuted": {
			want: true,
			s:    "abbbcccddd",
			t:    "bbbcccaddd",
		},
	}

	for description, tc := range testCases {
		t.Run(description, func(t *testing.T) {
			got := CheckPermutation(tc.s, tc.t)
			want := tc.want

			if got != want {
				t.Fatalf("Got(%t) != Want(%t)", got, want)
			}

		})
	}
}

func TestURLify(t *testing.T) {
	testCases := map[string]struct {
		plaintext string
		encoded   string
	}{
		"empty": {
			plaintext: "",
			encoded:   "",
		},
		"one space": {
			plaintext: "   ",
			encoded:   "%20",
		},
		"multi space": {
			plaintext: "         ",
			encoded:   "%20%20%20",
		},
		"ok": {
			plaintext: "Hello, world  ",
			encoded:   "Hello,%20world",
		},
	}

	for description, tc := range testCases {
		t.Run(description, func(t *testing.T) {
			got := URLify(tc.plaintext)
			want := tc.encoded

			if got != want {
				t.Fatalf("Got(%q) != Want(%q)", got, want)
			}
		})
	}
}

func TestIsPalindromePermutation(t *testing.T) {
	testCases := map[string]struct {
		s    string
		want bool
	}{
		"empty": {
			s:    "",
			want: true,
		},
		"is palindrome": {
			s:    "Tact Coa",
			want: true,
		},
		"is palindrome odd": {
			s:    "hhh",
			want: true,
		},
		"is palindrome with odd and even": {
			s:    "hhhaabb",
			want: true,
		},
		"is not palindrome with odd and even": {
			s:    "hhhaabbfff",
			want: false,
		},
	}

	for description, tc := range testCases {
		t.Run(description, func(t *testing.T) {
			got := IsPalindromePermutation(tc.s)
			want := tc.want

			if got != want {
				t.Fatalf("Got(%t) != Want(%t)", got, want)
			}
		})
	}
}

func TestIsOneOrLessAway(t *testing.T) {
	testCases := map[string]struct {
		s    string
		t    string
		want bool
	}{
		"empty": {
			s:    "",
			t:    "",
			want: true,
		},
		"remove": {
			s:    "pale",
			t:    "ple",
			want: true,
		},
		"insert": {
			s:    "pales",
			t:    "pale",
			want: true,
		},
		"replace": {
			s:    "pale",
			t:    "bale",
			want: true,
		},
		"nok": {
			s:    "pale",
			t:    "bake",
			want: false,
		},
	}

	for description, tc := range testCases {
		t.Run(description, func(t *testing.T) {
			got := IsOneOrLessAway(tc.s, tc.t)
			want := tc.want

			if got != want {
				t.Fatalf("Got(%t) != Want(%t)", got, want)
			}
		})
	}
}
