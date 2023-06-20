#include <iostream>
#include <string>

using namespace std;

class Word {
private:
    string word;
    int length;

public:
 

     //конструктор с параметрами
    Word(string _word) {
        word = _word;
        length = _word.length();
    }

    // метод инициализации полей объекта
    void init(string _word) {
        word = _word;
        length = _word.length();
    }

    // функци€, определ€юща€ количество гласных букв в слове
    int countVowels() {
        int count = 0;
        for (int i = 0; i < length; i++) {
            char ch = tolower(word[i]);
            if (ch == 'a' || ch == 'e' 
                || ch == 'i' || ch == 'o' || ch == 'u' 
                || ch == 'A' || ch == 'E' 
                || ch == 'I' || ch == 'O' || ch == 'U') {
                count++;
            }
        }
        return count;

    }
    void print() {
        cout << "Word: " << word << endl;
        cout << "Word len: " << length << endl;
    }
};

int main() {
    // здесь используетс€ конструктор дл€ инициализации полей
    Word myWord("kjkhbkh"); 
    myWord.print();
    cout << "Number of vowels: " << myWord.countVowels() << endl;
    //// а здесь мы используем процедуру инициализации полей
    //myWord.init("sapapapn");
    //myWord.print();
    //cout << "Number of vowels: " << myWord.countVowels() << endl;
    return 0;
}