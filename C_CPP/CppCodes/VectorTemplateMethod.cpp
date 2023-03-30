//vector methods;
//push_back(),erase(),insert(),size(),swap(),begin(),end();
#include <iostream>
#include <string>
#include <vector>

struct Review
{
    std::string title;
    int rating;
};

bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
    using std::cout;
    using std::vector;
    vector<Review> books;
    Review temp;
    while(FillReview(temp))
        books.push_back(temp);
    int num = books.size();
    if (num > 0)
    {
        cout << "Thank you. You entered the following: "
             << "\nRating\tBook\n";
        for (int i = 0;i < num;i++)
            ShowReview(books[i]);
        cout << "Reprising:\n"
             << "Rating\tBook\n";
        vector<Review>::iterator pd;
        pd = books.begin();
        for (pd;pd != books.end();pd++)
            ShowReview(*pd);
        vector<Review> oldlist(books);   //copy constructor;
        if (num > 3)
        {
            books.erase(books.begin()+1,books.begin()+3);   //remove 2 items;
            cout << "After Erasing :\n";
            for (pd = books.begin();pd != books.end();pd++)
                ShowReview(*pd);
            books.insert(books.begin(),oldlist.begin() + 1,oldlist.begin() + 2);//insert 1 item;
            cout << "After Insertion :\n";
            for (pd = books.begin();pd != books.end();pd++)
                ShowReview(*pd);
        }
        books.swap(oldlist);
        cout << "Swapping oldlist with books:\n";
        for (pd = books.begin();pd != books.end();pd++)
            ShowReview(*pd);
    }
    else
        cout << "Nothing entered, nothing gainec!";
    return 0; 
    
}

bool FillReview(Review & rr)
{
    std::cout << "Enter book title (q to quit) : ";
    getline(std::cin,rr.title);
    if(rr.title == "q" || rr.title == "Q")
        return false;
    std::cout << "Enter book rating : ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    while( std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review & rr)
{
    std::cout << rr.rating << ": " << rr.title << std::endl;
}
