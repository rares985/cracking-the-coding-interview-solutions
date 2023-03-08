#include "Chapter1.h"
#include <map>
#include <iostream>

std::map<char, int> BuildFrequencyMap(std::string &str)
{
    std::map<char, int> frequencies;
    for (char c : str)
    {
        if (frequencies.find(c) != frequencies.end())
        {
            frequencies[c] += 1;
        }
        else
        {
            frequencies[c] = 1;
        }
    }

    return frequencies;
}
/**
 * 1.1 Write an algorithm to determine if a string has all unique characters.
 *
 */
bool Solutions::AllUniqueCharacters(std::string &str)
{
    /**
     * Add each character to the map. If already there, return false
     * At the end, return true
     * n characters * log(n) lookup = O(nlogn)
     */
    std::map<char, int> frequencies;

    for (char c : str)
    {
        if (frequencies.find(c) != frequencies.end())
        {
            return false;
        }
        frequencies[c] = 1;
    }
    return true;
}

/**
 * 1.2. Given two strings, write a method to decide if one is
 * a permutation of the other.
 */
bool Solutions::ArePermutations(std::string &s1, std::string &s2)
{
    /**
     * Build a frequency map with all characters in s1. - O(nlogn)
     * Decrease for each character in s2 (if freq == 0, false) - O(nlogn)
     * Iterate map for != 0 values - O(n)
     * Total complexity O(nlogn)
     */
    std::map<char, int> frequencies;
    for (char c : s1)
    {
        if (frequencies.find(c) != frequencies.end())
        {
            frequencies[c] += 1;
        }
        else
        {
            frequencies[c] = 1;
        }
    }

    for (char c : s2)
    {
        if (frequencies.find(c) == frequencies.end())
        {
            /* Character in s2 but not in s1 */
            return false;
        }
        frequencies[c] -= 1;
        if (frequencies[c] < 0)
        {
            /* More occurences in s2 than in s1 */
            return false;
        }
    }

    for (auto &it : frequencies)
    {
        if (it.second != 0)
        {
            /* More occurences in s1 than in s2 */
            return false;
        }
    }
    return true;
}

/**
 * 1.3. Write a method to replace all spaces in a string with '%20'.
 * You may assume that the string has sufficient space at the end to hold the additional characters
 *  and that you are given the "true" length of the string.
 */
std::string Solutions::URLify(std::string &)
{
    // TODO:
    return std::string{};
}

/**
 * 1.4. : Given a string, write a function to check if it is a permutation of a palindrome.
 * A palindrome is a word or phrase that is the same forwards and backwards. A permutation
 * is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
 *
 * EXAMPLE: "taco cat" and "atco cta"
 */
bool Solutions::IsPalindromePermutation(std::string &str)
{
    /**
     * Build a frequency map O (nlogn) and iterate through it O(n).
     * If any two characters have odd frequencies, they cannot be palindromes.
     * Total complexity: O(nlogn)
     */
    std::map<char, int> frequencies;
    for (char c : str)
    {
        if (c == ' ')
            continue;
        if (frequencies.find(c) != frequencies.end())
        {
            frequencies[c] += 1;
        }
        else
        {
            frequencies[c] = 1;
        }
    }

    int oddFrequencies = 0;
    for (auto &it : frequencies)
    {
        if (it.second % 2 != 0)
        {
            if (oddFrequencies == 1)
            {
                /* Cannot have a palindrome with two letters appearing an odd number of times */
                return false;
            }
            oddFrequencies += 1;
        }
    }

    return true;
}

/**
 * 1.5. There are three types of edits that can be performed on strings: insert a character,
 * remove a character, or replace a character.
 * Given two strings, write a function to check if they are one edit (or zero edits) away.
 */
bool Solutions::OneAway(std::string &s1, std::string &s2)
{
    // TODO:
    return false;
}
