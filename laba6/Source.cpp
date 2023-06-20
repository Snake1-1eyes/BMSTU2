#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

// Структура узла списка
struct Node {
    int value; 
    Node* next; 
};

// Функция для вычисления суммы цифр числа
int digitSum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Функция для построения списка из чисел, заданных в строке
Node* createListFromString(string str) {
    Node* head = nullptr; // указатель на первый узел
    Node* tail = nullptr; // указатель на последний узел
    istringstream iss(str); // создаем поток для разбора строки
    string token;
    while (iss >> token) { // считываем числа из строки по одному
        int n = stoi(token); // преобразовываем строку в число
        Node* node = new Node; // создаем новый узел
        node->value = n;
        node->next = nullptr; // указываем, что следующего узла пока нет
        if (tail != nullptr) { // если список не пустой
            tail->next = node; // предыдущий узел ссылается на новый
        }
        else { // если список пустой
            head = node; // первый узел - новый узел
        }
        tail = node; // новый узел становится последним
    }
    return head; // возвращаем указатель на первый узел
}

// Функция для вывода списка на экран
void printList(Node* head) {
    cout << "List: ";
    while (head != nullptr) { // пока есть узлы в списке
        cout << head->value << " "; 
        head = head->next; // переходим к следующему узлу
    }
    cout << endl;
}

// Функция для поиска чисел с максимальной и минимальной суммой цифр
void findMinMaxDigitSum(Node* head) {
    int maxSum = -1; // максимальная сумма цифр
    int minSum = INT_MAX; // минимальная сумма цифр
    Node* maxNode = nullptr; 
    Node* minNode = nullptr;
    while (head != nullptr) { // пока есть узлы в списке
        int sum = digitSum(head->value); // считаем сумму цифр текущего числа
        if (sum > maxSum) { // если сумма цифр больше максимальной
            maxSum = sum; // обновляем максимальную сумму цифр
            maxNode = head; // запоминаем указатель на узел
        }
        if (sum < minSum) { // если сумма цифр меньше минимальной
            minSum = sum; // обновляем минимальную сумму цифр
            minNode = head; // запоминаем указатель на узел
        }
        head = head->next; 
    }
    cout << "Numbers with maximal digit sum (" << maxSum << "): ";
    cout << maxNode->value << " "; 
    cout << endl;
    cout << "Numbers with minimal digit sum (" << minSum << "): ";
    cout << minNode->value << " ";  
    cout << endl;
}

int main() {
    string str;
    cout << "Enter a string of positive integers (0-65535) separated by space: ";
    getline(cin, str); // считываем строку из консоли
    Node* head = createListFromString(str); // создаем список из чисел строки
    printList(head); // выводим список на экран
    findMinMaxDigitSum(head); // ищем числа с максимальной и минимальной суммой цифр
    return 0;
}