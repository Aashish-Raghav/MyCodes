#include<iostream>
int main() 
{
    using namespace std;
    string months[12] = {"Jan","Feb","Mar", "Apr","May", "June","July","Aug","Sep","Oct","Nov","Dec"};
    int saleMonths[3][12];
    int sum[3] = {0};
    for (int i = 0;i <= 2;i++)
    {
        cout << "Input Data for year : " << i+1 << endl;
        for (int j = 0;j <= 11;j++) 
        {
            cout << "sale in month " << months[j] << " : "; cin >> saleMonths[i][j];
            sum[i]= sum[i] + saleMonths[i][j];
        }
        cout << endl << endl;
    }
    for (int i = 0 ;i <= 2;i++) 
    {
        cout << "sale in year " << i +1 << " = " << sum[i]<<endl;
    }
    cout << "\n\nTotal sale : " << sum[0] + sum[1] + sum[2];
    return 0;
}