<<<<<<< HEAD
// Tc: O(n * average len of s)
// Sc: O(n * average len of s)
class Solution
{

public:
    string getKey(string str)
    {
        string key;
        int diff = 26 - (str[0] - 'a');
        for(int i = 0; i < str.size(); i ++)
        {
            key[i] = 'a' + (str[i] + diff) % 26;
        }
        return key;

    }

    /*
    string getKey(string str)
    {
        string key;

        for(int i = 1; i < str.size(); i ++)
        {
            int diff = str[i] - str[i-1];
            if(diff < 0)
            {
                diff += 26;
            }

            key[i] = 'a' + diff + '.';
        }
        return key;
    }
    */

    vector<vector<string>> groupStrings(vector<string>& strings)
    {

        unordered_map<string, vector<string>> mp;
        for (auto &s : strings)
        {
            mp[getKey(s)].push_back(s);
        }

        vector<vector<string>> groups;
        for (auto m : mp)
        {
            groups.push_back(m.second);
        }
        return groups;
    }
};
=======
// Tc: O(n * average len of s)
// Sc: O(n * average len of s)
class Solution
{

public:
    string getKey(string str)
    {
        string key;
        int diff = 26 - (str[0] - 'a');
        for(int i = 0; i < str.size(); i ++)
        {
            key[i] = 'a' + (str[i] + diff) % 26;
        }
        return key;

    }

    /*
    string getKey(string str)
    {
        string key;

        for(int i = 1; i < str.size(); i ++)
        {
            int diff = str[i] - str[i-1];
            if(diff < 0)
            {
                diff += 26;
            }

            key[i] = 'a' + diff + '.';
        }
        return key;
    }
    */

    vector<vector<string>> groupStrings(vector<string>& strings)
    {

        unordered_map<string, vector<string>> mp;
        for (auto &s : strings)
        {
            mp[getKey(s)].push_back(s);
        }

        vector<vector<string>> groups;
        for (auto m : mp)
        {
            groups.push_back(m.second);
        }
        return groups;
    }
};
>>>>>>> 68fce0a1f9b9b34f5b12912a7a9770c9e632c20a
