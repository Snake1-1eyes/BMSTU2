#include <iostream>
#include <string>

using namespace std;

class Word {
private:
    string word;
    int length;

public:
 

     //����������� � �����������
    Word(string _word) {
        word = _word;
        length = _word.length();
    }

    // ����� ������������� ����� �������
    void init(string _word) {
        word = _word;
        length = _word.length();
    }

    // �������, ������������ ���������� ������� ���� � �����
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
    // ����� ������������ ����������� ��� ������������� �����
    Word myWord("kjkhbkh"); 
    myWord.print();
    cout << "Number of vowels: " << myWord.countVowels() << endl;
    //// � ����� �� ���������� ��������� ������������� �����
    //myWord.init("sapapapn");
    //myWord.print();
    //cout << "Number of vowels: " << myWord.countVowels() << endl;
    return 0;
}