#ifndef SOLUTIONS_H_
#define SOLUTIONS_H_

#include <string>

class Solutions
{
protected:
    bool AllUniqueCharacters(std::string &);
    bool ArePermutations(std::string &, std::string &);
    std::string URLify(std::string &);

    bool IsPalindromePermutation(std::string &);
};
#endif /* SOLUTIONS_H_ */