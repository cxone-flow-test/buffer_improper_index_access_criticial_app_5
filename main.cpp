#include <cstdint>
#include <cwchar>
#include <iostream>
#include <string.h>

using namespace std;

#define MAX 4

void print_array(int array[], int len) {
  cout << "print_array" << endl;

  for (int x = 0; x < len; x++) {
    cout << array[x] << endl;
  }
}

void print_array_ptr(int *array, int len) {
  cout << "print_array_ptr" << endl;

  for (int x = 0; x < len; x++) {
    cout << array[x] << endl;
  }
}

void do_stuff(int *a, int *b) {

  for (int x = 0; x < MAX; x++)
    a[x] = x;

  a[0] = 2000;
  a[MAX] = 400;
  a[MAX + 1] = 500;
  a[MAX - 1] = 700;
  a[(MAX + 1) - 3] = 800;
  a[6] = 600;

  cout << "a[0]: " << a[0] << endl;
  cout << "a[MAX]: " << a[MAX] << endl;
  cout << "a[6]: " << a[6] << endl;

  print_array(a, MAX);
  print_array(a, MAX + 1);
  print_array_ptr(a, MAX);
  print_array_ptr(a, MAX + 1);

  b[0] = 5;
  b[1] = 6;
  b[2] = 7;
  b[3] = 8;

  print_array(b, MAX);
  print_array(b, MAX + 1);
  print_array_ptr(b, MAX);
  print_array_ptr(b, MAX + 1);

  b[4] = 900;

  print_array(b, MAX);
  print_array(b, MAX + 1);
  print_array_ptr(b, MAX);
  print_array_ptr(b, MAX + 1);
}

int main(int argc, char *argv[]) {

  int foo[MAX], bar[MAX];

  // Same code as example 3, but this line was added.
  do_stuff(foo, bar);

  // The program crashes here after running the previous line.
  // No results were emitted, apparently because of this one line
  // where the size of the buffers can't be determined.
  do_stuff(NULL, NULL);
}
