#include<iostream>
const int ArSize = 5;
int fill_array(double[],int);
void show_array(const double[],int);
int main() 
{
    using namespace std;
    double arr[ArSize];
    int num = fill_array(arr,ArSize);
    cout << endl << endl;
    show_array(arr,num);
    return 0;
}

int fill_array(double arr[],int limit) {
    using namespace std;
    double temp;
    int i;
    for (i =0 ;i < limit ;i++)
    {
        std::cout << "Enter value of #" << (i+1) << ": ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            //while (cin.get() != '\n') continue;
            cout << "Bad input; input process terminated. \n";
            break;
        } else if (temp < 0) break;
        arr[i] = temp;
    }
    return i;
}
void show_array(const double arr[],int n)
{
    for (int i = 0; i < n;i++){
        std::cout << "Property #" << (i+1) << ": $";
        std::cout << arr[i] << std::endl;
    }
}