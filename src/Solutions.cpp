#include "Solutions.h"
#include <map>
#include <iostream>

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
    std::cout << "Checking " << s1 << " " << s2 << "\n";
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