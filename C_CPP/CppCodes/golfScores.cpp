#include<iostream>
const int ArSize = 10;
int fill(int[],int);
void show(const int[],int);
double average(int[],int);
int main() 
{
    using namespace std;
    int arr[ArSize];
    int nelements = fill(arr,ArSize);
    cout << "Golf Scores : \n";
    show(arr,nelements);
    cout << "\nAverage : \n";
    cout << average(arr,nelements);

    return 0;
}
int fill(int arr[],int size) {
    int nelements = 0;      //number of elements in array;
    int element;
    for (int i=0;i < size;i++) {
        std::cout << "Enter your golf scores(q to quit) #" << i+1 << " : ";
        if (!(std::cin >> element) || element < 0) {
            std::cin.clear();
            break;
        }
        arr[i] = element;
        nelements++;
    }
    return nelements;
}

void show(const int arr[],int size){
    for (int i = 0 ;i < size; i++) {
        std::cout << arr[i] << "\t";
    }
}

double average(int arr[],int size){
    double sum = 0;
    for (int i = 0;i < size;i++){
        sum += arr[i];
    }
    return sum/size;
}