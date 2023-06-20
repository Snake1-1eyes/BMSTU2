#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char text[100];
    cout << "Enter text: ";
    cin.getline(text, 100);
    char* ptr = text;
    bool found = false;
    char* pos = nullptr;
    cout << "\nOriginal text: " << text;
    while (*ptr != '\0') {
        if (*ptr == 't' && !found && *(ptr-1) == ' ') {
            found = true;
            pos = ptr;
        }
        else if (*ptr == 't') {
            cout << "\nAddress of another 't': " << (void*)ptr;
        }
        ptr++;
    }
    if (pos) {
        char* start = pos;
        char* end = pos;
        while (*end != ' ' && *end != '\0') {
            end++;
        }
        end--;
        while (start < end) {
            char temp = *start;
            *start++ = *end;
            *end-- = temp;
        }
        cout << "\nCorrected text: " << text;
    }
    else {
        cout << "No word starting with 't' found!";
    }
    cout << endl;
    return 0;
}