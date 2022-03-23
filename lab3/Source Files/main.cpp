#include <iostream>
#include <regex>

void Output(std::vector<std::string> strings, std::string exp)
{
    std::regex regex(exp);
    std::cout << "Regular expression = " << exp << std::endl;

    for (auto string : strings)
    {
        std::cout << "regex_search\t" << string << "\t:\t" << std::regex_search(string, regex) << std::endl;
        std::cout << "regex_match\t" << string << "\t:\t" << std::regex_match(string, regex) << std::endl;
    }
    std::cout << std::endl;
}

int main()
{

    std::cout << "-----TASK 1-----\n";
    std::vector<std::string> strings1 = {"abcdefg", "abcde", "abc"};
    std::string exp1 = "abc\\w{0,5}";
    Output(strings1, exp1);

   
    std::cout << "-----TASK 1.2-----\n";
    std::vector<std::string> strings1_2 = {"abc123xyz", "define \"123\"", "var g = 123;"};
    std::string exp1_2 = ".*123.*";
    Output(strings1_2, exp1_2);


    std::cout << "-----TASK 2-----\n";
    std::vector<std::string> strings2 = {"cat.", "896.", "?=+.", "abc1"};
    std::string exp2 = "....";
    Output(strings2, exp2);


    std::cout << "-----TASK 3-----\n";
    std::vector<std::string> strings3 = {"can", "man", "fan", "dan", "ran", "pan"};
    std::string exp3 = "[cmf]an";
    Output(strings3, exp3);


    std::cout << "-----TASK 4-----\n";
    std::vector<std::string> strings4= {"hog", "dog", "bog"};
    std::string exp4 = "[^b]og";
    Output(strings4, exp4);


    std::cout << "-----TASK 5-----\n";
    std::vector<std::string> strings5 = {"Ana", "Bob", "Cpc", "aax", "bby", "ccz"};
    std::string exp5 = "[A-Z][a-z][A-z]";
    Output(strings5, exp5);


    std::cout << "-----TASK 6-----\n";
    std::vector<std::string> strings6 = {"wazzzzzup", "wazzzup", "wazup"};
    std::string exp6 = "waz{2,5}up";
    Output(strings6, exp6);


    std::cout << "-----TASK 7-----\n";
    std::vector<std::string> strings7 = {"aaaabcc", "aabbbbc", "aacc", "a"};
    std::string exp7 = "a+b*c+";
    Output(strings7, exp7);


    std::cout << "-----TASK 8-----\n";
    std::vector<std::string> strings8 = {"1 file found?", "2 files found?", "24 files found?", "No files found."};
    std::string exp8 = "";
    Output(strings8, exp8);


    std::cout << std::endl;

    return 0;
}