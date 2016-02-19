#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> dict;
char mapping[128];

bool is_exist_mapping(char ch) {
    return find(mapping, mapping + sizeof(mapping), ch) != mapping + sizeof(mapping);
}

bool map_word(string dic_word, string target_word)
{
    char original_mapping[128];

    // copy original mapping
    for (int i = 'a'; i <= 'z'; i++)
        original_mapping[i] = mapping[i];

    for (int i = 0; i < dic_word.length(); i++) {
        if (mapping[target_word[i]] == '*' && !is_exist_mapping(dic_word[i])    // empty mapping
            || mapping[target_word[i]] == dic_word[i])                          // mapping matched
            mapping[target_word[i]] = dic_word[i];

        // revert mapping
        else {
            for (int i = 'a'; i <= 'z'; i++)
                mapping[i] = original_mapping[i];

            return false;
        }
    }
    return true;
}

bool match_word(vector<string> words, int index)
{
    // terminate condition
    if (index == words.size())
        return true;

    char original_mapping[128];

    // copy original mapping
    for (int i = 'a'; i <= 'z'; i++)
        original_mapping[i] = mapping[i];

    // start matching
    for (int i = 0; i < dict.size(); i++) {
        if (words[index].length() == dict[i].length()) {
            if (map_word(dict[i], words[index])) {
                // do next match
                if (match_word(words, index + 1))
                    return true;

                // current match failed
                for (int i = 'a'; i <= 'z'; i++)
                    mapping[i] = original_mapping[i];
            }
        }
    }

    return false;
}

int main(int argc, const char* argv[]) {
    ios::sync_with_stdio(false);

    int word_num;
    cin >> word_num;

    string buf;

    getline(cin, buf);

    for (int i = 0; i < word_num; i++) {
        getline(cin, buf);
        dict.push_back(buf);
    }

    // decrypt sentences
    while (getline(cin, buf))
    {
        string word;
        stringstream ss(buf);
        vector<string> word_list;

        // tokenize sentence
        while (ss >> word)
            word_list.push_back(word);

        // init mapping
        for (int i = 0; i < 128; i++) {
            mapping[i] = '*';
        }

        // create sorted list of words in size
        vector<string> sorted_list = vector<string>(word_list);
        sort(sorted_list.begin(), sorted_list.end(), [](const string &a, const string &b)
        {
            return a.length() > b.length();
        });

        // try to match words recursively
        match_word(sorted_list, 0);

        // print decrypted sentence
        for (int i = 0; i < word_list.size(); i++)
        {
            for (int j = 0; j < word_list[i].length(); j++)
                cout << mapping[word_list[i][j]];

            // fix: no space at the end of sentence
            if(i < word_list.size())
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}
