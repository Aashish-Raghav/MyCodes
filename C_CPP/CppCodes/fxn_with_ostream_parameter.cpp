#include<iostream>
#include<fstream>
#include<cstdlib>

//ostream & parameter;
void file_it(std::ostream & os,double fo,const double fe[],int n);
const int LIMIT = 5;

int main() 
{
    using namespace std;
    ofstream fout;
    const char * fn = "Telescope.txt";
    fout.open(fn);
    if (!fout.is_open()){
        cout << "Can't open " << fn << ". Bye.\n";
        exit(EXIT_FAILURE);
    }
    double objective;
    cout << "Enter the focal length of your telescope objective in mm: ";
    cin >> objective;
    double eyePiece[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces:\n";
    for (int i = 0;i < LIMIT; i++){
        cout << "Eyepiece #" << i+1 << " : ";
        cin >> eyePiece[i];
    }
    file_it(fout,objective,eyePiece,LIMIT);
    file_it(cout,objective,eyePiece,LIMIT);
    
    return 0;
}
void file_it(std::ostream & os,double fo,const double fe[],int n){
    using namespace std;
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed);  //save initial formatting state;
    os.precision(0);
    os << "Focal Length of Objective : " << fo << " mm\n";
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "f.1. eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for (int i = 0;i < n;i++) {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int (fo/fe[i] + 0.5) << endl;
    }
    os.setf(initial);
}