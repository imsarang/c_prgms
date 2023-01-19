#include <string.h>
#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

bool checkPalindrome(char input[])
{
    int n = strlen(input) - 1;
    // base condition
    if (input[0] != input[n])
        return false;

    // recursive call
    input[n] = '\0';
    bool ans = checkPalindrome(input + 1);
    if (n == 0 || n == 1)
        return true;
    else
        ans;
}

// & used in 5th parameter for output as it has to be called by its address for inserting elements in it
void TowerOfHanoi(int n, int src, int dest, int aux, vector<pair<int, int>> &output)
{

    if (n != 0)
    {
        // first disk goes from src to aux
        TowerOfHanoi(n - 1, src, aux, dest, output);

        // push the src and dest to output vector
        output.push_back(make_pair(src, dest));

        // disk moves from aux to dest
        TowerOfHanoi(n - 1, aux, dest, src, output);
    }
}

// remove all x charaters in a character array
void removeX(char input[])
{
    if (input[0] == '\n')
        return;

    if (input[0] == 'x')
    {
        for (int i = 0; input[i]; i++)
        {
            input[i] = input[i + 1];
        }
        return removeX(input);
    }
    return removeX(input + 1);
}
