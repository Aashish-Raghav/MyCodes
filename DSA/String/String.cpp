#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void printArr(int arr[],int size = 26);
template <class T>
void printArr(vector<T> v);
int getlength(char arr[]);
string replaceSpace(string & str1,char str2[]); 
string removeAllSubstr(string str1,string str2); //6
bool permSubstr(string str1,string str2); //7  //check whether any perm of str2 in str1;
string removeAllAdjacent(string str);

int compress1(vector<char> &chars);
int compress2(vector<char> &chars);

int main()
{
    // string str1 = "dadbac";
    // string str2 = "ll";
    // string str3 = removeAllAdjacent(str1);
    vector<char> chars;
    chars.push_back('h');
    chars.push_back('e');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('l');
    chars.push_back('o');chars.push_back('o');
    // printArr(chars);
    // chars.erase(chars.begin(),chars.begin()+1);
    // printArr(chars);
    // char ch = ( (char) 6 ) + '0';
    // cout << ch;
    int size = compress1(chars);
    cout << size << endl;
    // cout << str3 << endl;

    // cout.setf(ios_base::boolalpha);
    // cout <<  permSubstr(str1,str2) << endl;;
}

void printArr(int arr[],int size)
{
    for (int i = 0;i < size;i++)
    {
        if (arr[i] != 0)
            cout << (char) ('a' + i);
    }
    cout << endl;
}

template <class T>
void printArr(vector<T> v)
{
    cout << "Your Vector = ";
    for (int i = 0;i < v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int getlength(char arr[])
{
    int count = 0;
    for (int i = 0;arr[i] != '\0';i++)
    {
        count++;
    }
    return count;
}

string replaceSpace(string &str1,char str2[])
{
    string temp = "";
    for (int i = 0;i < str1.size();i++)
    {
        if (str1[i] == ' ')
        {
            for (int j = 0;j < getlength(str2);j++)
                temp.push_back(str2[j]);
        }
        else
            temp.push_back(str1[i]);
    }
    return temp;
}

string removeAllSubstr(string str1,string str2)
{
    //find (substr)     // if got return index else return npos;
    while (str1.length() != 0 && str1.find(str2) <= str1.length())
    {
        str1.erase(str1.find(str2),str2.length());  //erase(begin index,length);
    }
    return str1;
}

bool checkEqual(int arr1[],int arr2[])
{
    for (int i = 0;i < 26;i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

bool permSubstr(string str1,string str2)
{
    int count1[26] = {0};
    for (int i = 0;i < str2.size();i++)
        count1[str2[i] - 'a']++;

    int i = 0;
    int windowSize = str2.size();
    int count2[26] = {0};

    //creating first window;
    while (i < windowSize && i < str1.length())
    {
        count2[str1[i] - 'a']++;
        i++;
    }

    if (checkEqual(count1,count2))
        return true;

    //aage wali window handle here;
    while (i < str1.length())
    {
        //add count of new element;
        count2[str1[i] - 'a']++;

        //delete count of old element;
        count2[str1[i-windowSize] - 'a']--;
        i++;
        if (checkEqual(count1,count2))
            return true;
    }

    return false;
}

string removeAllAdjacent(string str)
{
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < str.size())
    {
        // cout << i << " ";
        if (str[i] == str[j])
        {
            count++;
            i++;
        }
        else
        {
            if (count > 1)
            {
                str.erase(j,count);                
                i = i - count - 1;
            }
            if (i < 0)
                i = 0;
            j = i;
            count = 0;
        }
    }
    return str;
}

int compress1(vector<char> &chars)
{
    int checkLoop = 0;
    int size = chars.size();
    int i = 0,j = 0,count = 0;


    while (checkLoop <= size)
    {
        
        if (chars[i] == chars[j])
        {
            count++;
            i++;
            checkLoop++;
        }
        else
        {
            char c = chars[i-1];
            chars.erase(chars.begin(),chars.begin()+count);
            chars.push_back(c);
            if (count != 1)
            {
                string cnt = to_string(count);
                for (char ch : cnt)
                    chars.push_back(ch);
            }
            
            count = 0;
            i = 0;
            j= i;
        }
    }
    printArr(chars);
    return chars.size();
}

int compress2(vector<char> &chars)
{
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();
    while (i < n)
    {
        int j = i+1;
        while (j < n && chars[i] == chars[j])
        {
            j++;
        }

        chars[ansIndex++] = chars[i];

        int count = j-i;
        if (count > 1)
        {
            string cnt = to_string(count);
            for (char ch: cnt)
            {
                chars[ansIndex++] = ch;
            }
        }
        i = j;
    }
    printArr(chars);
    return ansIndex;
}