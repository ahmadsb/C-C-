#include <iostream>
void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}
void RemoveSpaces(std::string &str, int len)
{
    int i = 0, j = 0;
    std::cout << str << std::endl;
    for (; i < len; ++i)
    {
        if (str[i] == ' ')
        {
            ++j;
        }
        else
        {
            break;
        }
    }
    i = 0;
    bool flagSpace = false;
    while (j < len )
    {
        std::cout << j << ' ' << len << std::endl;
        if (str[j] != ' ')
        {
            str[i] = str[j];
            flagSpace = false;
            
        }
        else
        {
            if (!flagSpace)
            {
                str[i] = str[j];
                flagSpace = true;
              
            }
            else
            {
                ++j;
                continue;
            }
            
        }
          ++i;
        ++j;
    }
    if (str[i-1] == ' ')
        str[i-1] = '\0';
    else
    {
        str[i] = '\0';
    }
}
int main()
{
    std::string str = "  my name  is ahmad";
    RemoveSpaces(str, str.length());
    std::cout << str << std::endl;
    return 0;
}