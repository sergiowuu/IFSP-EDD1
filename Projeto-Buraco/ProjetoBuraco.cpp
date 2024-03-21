#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>

using namespace std;

string para_string(int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

void random_shuffle(vector<string> &vec)
{
    for (int i = vec.size() - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        swap(vec[i], vec[j]);
    }
}

int main()
{

    srand(time(0));

    vector<vector<string>> baralho(2);
    for (int b = 0; b < 2; b++)
    {
        for (int n = 1; n <= 4; n++)
        {
            for (int c = 1; c <= 13; c++)
            {
                baralho[b].push_back(to_string(n) + "" + (c < 10 ? "0" : "") + to_string(c) + "" + to_string(b + 1));
            }
        }
        random_shuffle(baralho[b]);
    }

    vector<vector<string>> mao(4);
    for (int j = 0; j < 4; j++)
    {
        for (int b = 0; b < 2; b++)
        {
            for (int c = 0; c < 11; c++)
            {
                mao[j].push_back(baralho[b].back());
                baralho[b].pop_back();
            }
        }
    }

    for (int j = 0; j < 4; j++)
    {
        cout << "Jogador " << (j + 1) << ":\n";
        for (int c = 0; c < 11; c++)
        {
            cout << "Baralho[" << (c / 11) << "][" << (c % 11) << "] = \"" << mao[j][c] << "\"\n";
        }
        cout << "\n";
    }

    return 0;
}