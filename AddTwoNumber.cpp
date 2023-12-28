#include <iostream>
#include <math.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        unsigned int so_doi = 0, tmp = x;
        if (x < 0)
            return false;
        do
        {
            so_doi = (so_doi * 10) + (tmp % 10);
            tmp /= 10;
        } while (tmp > 0);
        if ((so_doi - x) == 0)
            return true;
        else
            return false;
    }
};