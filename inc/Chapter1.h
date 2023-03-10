#ifndef CHAPTER_1_H_
#define CHAPTER_1_H_

#include <string>

class Chapter1
{
public:
    bool AllUniqueCharacters(std::string &);
    bool ArePermutations(std::string &, std::string &);
    std::string URLify(std::string &);

    bool IsPalindromePermutation(std::string &);
    bool OneAway(std::string &, std::string &);
};
#endif /* CHAPTER_1_H_ */