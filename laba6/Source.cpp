#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

// ��������� ���� ������
struct Node {
    int value; 
    Node* next; 
};

// ������� ��� ���������� ����� ���� �����
int digitSum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// ������� ��� ���������� ������ �� �����, �������� � ������
Node* createListFromString(string str) {
    Node* head = nullptr; // ��������� �� ������ ����
    Node* tail = nullptr; // ��������� �� ��������� ����
    istringstream iss(str); // ������� ����� ��� ������� ������
    string token;
    while (iss >> token) { // ��������� ����� �� ������ �� ������
        int n = stoi(token); // ��������������� ������ � �����
        Node* node = new Node; // ������� ����� ����
        node->value = n;
        node->next = nullptr; // ���������, ��� ���������� ���� ���� ���
        if (tail != nullptr) { // ���� ������ �� ������
            tail->next = node; // ���������� ���� ��������� �� �����
        }
        else { // ���� ������ ������
            head = node; // ������ ���� - ����� ����
        }
        tail = node; // ����� ���� ���������� ���������
    }
    return head; // ���������� ��������� �� ������ ����
}

// ������� ��� ������ ������ �� �����
void printList(Node* head) {
    cout << "List: ";
    while (head != nullptr) { // ���� ���� ���� � ������
        cout << head->value << " "; 
        head = head->next; // ��������� � ���������� ����
    }
    cout << endl;
}

// ������� ��� ������ ����� � ������������ � ����������� ������ ����
void findMinMaxDigitSum(Node* head) {
    int maxSum = -1; // ������������ ����� ����
    int minSum = INT_MAX; // ����������� ����� ����
    Node* maxNode = nullptr; 
    Node* minNode = nullptr;
    while (head != nullptr) { // ���� ���� ���� � ������
        int sum = digitSum(head->value); // ������� ����� ���� �������� �����
        if (sum > maxSum) { // ���� ����� ���� ������ ������������
            maxSum = sum; // ��������� ������������ ����� ����
            maxNode = head; // ���������� ��������� �� ����
        }
        if (sum < minSum) { // ���� ����� ���� ������ �����������
            minSum = sum; // ��������� ����������� ����� ����
            minNode = head; // ���������� ��������� �� ����
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
    getline(cin, str); // ��������� ������ �� �������
    Node* head = createListFromString(str); // ������� ������ �� ����� ������
    printList(head); // ������� ������ �� �����
    findMinMaxDigitSum(head); // ���� ����� � ������������ � ����������� ������ ����
    return 0;
}