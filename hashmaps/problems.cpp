#include <iostream>
#include <string>
#include <unordered_map>

std::string uniqueChar(std::string str)
{
	// Write your code here
	int index = 0;
	// string output[str.length()];
	std::unordered_map<char, int> map;
	std::string output;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (map[str[i]] == 0)
		{
			output.push_back(str[i]);
			map[str[i]]++;
		}
	}
	// str[index] = '\0';
	return output;
}

int summation(int x)
{
	if (x == 0)
		return 0;
	else
		return (x - 1) + summation(x - 1);
}
int getPairsWithDifferenceK(int *arr, int n, int k)
{
	// Write your code here
	std::unordered_map<int, int> map;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		map[arr[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == k + arr[i])
		{
			count += summation(map[arr[i]]);
			map[arr[i]] = 0;
		}
		else if (arr[i] - k >= 0 && map[arr[i] - k] > 0)
		{
			count += map[arr[i]] * map[arr[i] - k];
			// map[abs(k+arr[i])] = 0;
			map[arr[i]] = 0;
		}
		else if (map[k + arr[i]] > 0)
		{
			count += map[arr[i]] * map[k + arr[i]];
			// map[abs(k+arr[i])] = 0;
			map[arr[i]] = 0;
		}
	}
	return count;
}

int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
	// Write your code here
	int length = 0;
	int sum = 0;
	std::unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];

		if (arr[i] == 0 && length == 0)
			length = 1;

		if (sum == 0)
			length = i + 1;

		if (m.count(sum) > 0)
		{
			length = std::max(length, i - m[sum]);
		}
		else
		{
			m[sum] = i;
		}
	}

	return length;
}

std::vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
	// Your Code goes here
	std::vector<int> ans;
	std::unordered_map<int, int> a;
	for (int i = 0; i < n; i++)
	{
		a[arr[i]] = 1;
	}
	int max = 0;
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		int x = arr[i];
		int j = 0;
		if (a.count(x - 1) > 0)
			continue;
		while (a.count(x) > 0)
		{

			j++;
			x++;
		}
		if (j > max)
		{
			max = j;
			k = arr[i];
			// cout<<" j:"<<j<<" k:"<<k<<endl;
		}
	}

	std::ans.push_back(k);
	std::ans.push_back(k + max - 1);
	return ans;
}