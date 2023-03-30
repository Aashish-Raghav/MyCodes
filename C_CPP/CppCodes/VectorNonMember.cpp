//non member function i.e., methods for STL containers
//defined under algorithm header file
//for_each(),random_shuffle(),sort()

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
    std::string title;
    int rating;
};

bool operator<(const Review & r1,const Review & r2);
bool WorseThan(const Review & r1,const Review & r2);
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
        cout << "Thank You. You entered the following:\n";
        cout << "Rating : Book\n";
        for_each(books.begin(),books.end(), ShowReview);

        sort(books.begin(),books.end());    // sort() needs a operator<() to be overloaded accordingly;
        cout << "Sorted by Title:\nRating\tBook\n";
        for_each(books.begin(),books.end(),ShowReview);

        sort(books.begin(),books.end(),WorseThan);  //sort according WorseThan;
        cout << "Sorted by Rating:\nRating\tBook\n";
        for_each(books.begin(),books.end(),ShowReview);

        random_shuffle(books.begin(),books.end());
        cout << "After Random Shuffle:\nRating\tBook\n";
        for_each(books.begin(),books.end(),ShowReview);
    }
    return 0; 
    
}

bool operator<(const Review & r1,const Review & r2)
{
    if (r1.title < r2.title)
        return true;
    else if (r1.title == r2.title && r1.rating < r2.rating)
        return true;
    else 
        return false;
}

bool WorseThan(const Review & r1,const Review & r2)
{
    if (r1.rating < r2.rating)
        return true;
    else 
        return false;
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
