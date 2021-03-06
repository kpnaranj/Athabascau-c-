#include <iostream>

using namespace std;

void printArray(const char *arrayPtr);
char* createCharArray(char *arrayPtr);

int main() {

    char* str1 [100] = "This is a test line.";
    char* str2 [100] = createCharArray(str1);
    char* str3 [100] = createCharArray(str2);

    cout << "Array 1: " << (void*)str2 << endl;
    printArray(str1);

    cout << "\nArray 2: " << (void*)str3 << endl;
    printArray(str2);

    delete str2;
    delete str3;

return 0;
}

void printArray(const char *arrayPtr) {

    int array_size = 0;
    while ( *(arrayPtr + array_size++ ) != '\0');

    for (int i = 0; i < array_size; i++)
        cout << *(arrayPtr + i);

    cout << endl;
}

char* createCharArray(char *arrayPtr) {

    int array_size = 0;
    while ( *(arrayPtr + array_size++ ) != '\0');

    char* result = new char[array_size];

    for (int i = 0; i < array_size; i++)
        *(result + i) = *(arrayPtr + i);

    *(result + array_size) = '\0';

return result;
}