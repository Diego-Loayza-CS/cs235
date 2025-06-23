#include <iostream>
using std::cout;
using std::endl;

#define PRINT(x) cout << #x << " ==> " << x << endl;
#define WHERE(x) cout << "where(" << #x << ") ==> "; where(x);
#define BYTES(x) cout << "bytes(" << #x << ") ==> "; bytes(x);


template <class T>
void where(T const& thing) {
    printf("%p\n", &thing);
}

/*
  This method prints the bytes in RAM that a given variable has
*/
template <class T>
void bytes(T const& thing) {
    unsigned char* addr = (unsigned char*)&thing;
    printf("0x");
    for (int i = sizeof(T) - 1; i >= 0; i--) {
        printf("%02x", addr[i]);
    }
    printf("\n");
}
