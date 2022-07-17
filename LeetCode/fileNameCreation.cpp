#include <iostream>

using namespace std;

int main()
{
    string input;
    getline(cin, input, '\n');
    int size = input.size();
    for (int i = 1; i < size; i++)
    {
        if (input[i - 1] == ' ')
        {
            input[i] = tolower(input[i]);
            input[i - 1] = '_';
        }
    }
    input = input + ".cpp";
    cout << input << endl;
    return 0;
}