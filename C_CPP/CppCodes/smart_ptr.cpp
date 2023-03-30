//smart pointers, in memory header file;
// auto_ptr,unique_ptr,shared_ptr;

#include <iostream>
#include <string>
#include <memory>

int main()
{
    std::string* normal = new std::string;
    *normal = "Hello 1";
    std::shared_ptr<std::string> s1(new std::string("Hello"));
    std::cout << *s1 << std::endl;
    std::shared_ptr<std::string> s2 = s1;
    std::cout << *s2 << std::endl;
    std::shared_ptr<std::string> s3(normal);
    std::cout << *s3 << std::endl;
}

/*
class Report
{
private:
    std::string str;
public:
    Report(const std::string s) : str(s)
    { std::cout << "Object created\n";}
    ~Report() {std::cout << "Object deleted\n";}
    void comment() const { std::cout << str << "\n";} 
};

int main()
{
    {
        std::auto_ptr<Report> r1(new Report("This is auto_ptr"));
        r1->comment();
    }
    {
        std::unique_ptr<Report> r2(new Report("This is unique_ptr"));
        r2->comment();
    }
    {
        std::shared_ptr<Report> r3(new Report("This is shared_ptr"));
        r3->comment();
    }
    return 0;
}
*/