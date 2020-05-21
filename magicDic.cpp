#include <iostream>
#include <map>
using namespace std;

int main()
{
    string line, word, detail;
    map<string, string> wordToDetail, detailToWord;
    int pos;
    while (getline(cin, line))
    {
        if (line == "@END@")
            break;
        pos = line.find(']');
        word = line.substr(0, pos + 1);
        detail = line.substr(pos + 2);
        wordToDetail[word] = detail;
        detailToWord[detail] = word;
    }
    int n;
    cin >> n;
    string quest, answer;
    getchar();
    while (n--)
    {
        getline(cin, quest);
        if (wordToDetail.find(quest) != wordToDetail.end())
            cout << wordToDetail[quest] << endl;
        else if (detailToWord.find(quest) != detailToWord.end())
        {
            answer = detailToWord[quest];
            answer = answer.substr(1, answer.size() - 2);
            cout << answer << endl;
        }
        else
            cout << "what?" << endl;
    }
    return 0;
}