#include <iostream>
#include <set>

using namespace std;

int main()
{
    // greater<int> stores elements in descending order
    set<int, greater<int> > s1;

    // insert elements in random order
    s1.insert(100);
    s1.insert(1);
    s1.insert(80);
    s1.insert(180);
    s1.insert(0);
    s1.insert(510);


    // printing set s1
    set<int, greater<int> >::iterator itr;
    cout << "\nThe set s1 is : \n";
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    // assigning the elements from s1 to s2
    set<int> s2(s1.begin(), s1.end());
    // s3 is a copy of s2
    set<int> s3(s1.begin(), s1.end());
    // print all elements of the set s2
    cout << "\nThe set s2 after assign from s1 is : \n";
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    // remove all elements less than 100 in s2
    cout << "\ns2 after removal of elements less than 100 "
            ":\n";
    s2.erase(s2.begin(), s2.find(100));
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }
     
    cout<<"\n \n";
    cout <<"After removal of 510 from s2"<<endl;
    // remove element with value 510 in s2
    s2.erase(510); // supports bidirectional iterators but not random-access iterators
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }

    cout <<"\n \n";

    // lower bound and upper bound for set s1
    cout << "s3.lower_bound(80) : \n"
        << *s3.lower_bound(80) << endl;
    cout << "s3.upper_bound(80) : \n"
        << *s3.upper_bound(80) << endl;

    return 0;
}
