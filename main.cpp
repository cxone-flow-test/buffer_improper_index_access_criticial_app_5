#include <cstdint>
#include <cwchar>
#include <iostream>
#include <string.h>


using namespace std;

#define MAX 4

void print_array(char array[], int len) {
  cout << "print_array" << endl;

  for (int x = 0; x < len; x++) {
    cout << array[x] << endl;
  }
}

void print_array_ptr(char *array, int len) {
  cout << "print_array_ptr" << endl;

  for (int x = 0; x < len; x++) {
    cout << array[x] << endl;
  }
}

__attribute__((visibility("default"))) void do_stuff(char *a, char *b) {
  
  for (int x = 0; x < MAX; x++)
    a[x] = 'A' + x;

  a[0] = 'A';
  a[MAX] = 'A';
  a[MAX + 1] = 'A';
  a[MAX - 1] = 'A';
  a[(MAX + 1) - 3] = 'A';
  a[6] = 'A';

  cout << "a[0]: " << a[0] << endl;
  cout << "a[MAX]: " << a[MAX] << endl;
  cout << "a[MAX]: " << (char*)(&a[MAX]) << endl;
  cout << "a[6]: " << a[6] << endl;

  print_array(a, MAX);
  print_array(a, MAX + 1);
  print_array_ptr(a, MAX);
  print_array_ptr(a, MAX + 1);

  b[0] = 'A';
  b[1] = 'A';
  b[2] = 'A';
  b[3] = 'A';

  print_array(b, MAX);
  print_array(b, MAX + 1);
  print_array_ptr(b, MAX);
  print_array_ptr(b, MAX + 1);

  b[4] = 'A';

  print_array(b, MAX);
  print_array(b, MAX + 1);
  print_array_ptr(b, MAX);
  print_array_ptr(b, MAX + 1);
}
