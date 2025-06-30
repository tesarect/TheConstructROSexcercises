#include <forward_list>
#include <iostream>
using namespace std;

int main() {
  // Declaring forward list
  forward_list<int> flist1 = {10, 22, 31};
  forward_list<int> flist2;
  flist2.assign(5, 10);

  //   flist2.insert_after(advance(flist2.begin(), 2), 5)

  // Displaying forward lists
  cout << "The elements of first forward list are : ";
  for (int i : flist1)
    cout << i << " ";
  cout << endl;

  cout << "The elements of second forward list are : ";
  for (int &b : flist2)
    cout << b << " ";
  cout << endl;

  return 0;
}

// // Insert 3 after the second element (value 2)
// auto it = fl.begin();
// std::advance(it, 1); // Move iterator to point to the element '2'

// fl.insert_after(it, 3); // Insert '3' after '2'

// // Insert 0 at the beginning of the list
// fl.insert_after(fl.before_begin(), 0);
