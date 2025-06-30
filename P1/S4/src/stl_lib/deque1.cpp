#include <deque>
#include <iostream>

using namespace std;

void display_dq(deque<char> N) {

  for (int i = 0; i < N.size(); i++)
    cout << '\t' << N.at(i);
  cout << '\n';

  //     for (const int& i : N) {
  //     cout << i << "  ";
  //   }
}

int main() {
  deque<char> M;
  // push_back Inserts element at the end
  M.push_back('a');
  // push_front inserts element at the front
  M.push_front('b');
  M.push_back('c');
  M.push_front('d');
  cout << "The deque is : ";
  display_dq(M);

  cout << "\nM.at(2) : " << M.at(2);
  cout << "\nM.front() : " << M.front();
  cout << "\nM.back() : " << M.back();

  cout << "\nAfter removing front element using M.pop_front() : ";
  M.pop_front();
  display_dq(M);

  cout << "\nAfter removing last element using M.pop_back() : ";
  M.pop_back();
  display_dq(M);

  return 0;
}
