#include <iostream>
#include <queue>
using namespace std;


int main() {
    queue<int> q;

    q.push(2);
    q.push(3);
    cout << q.front() << endl; //2

    q.pop();
    cout << q.front() << endl; //3

    q.pop();
    q.push(4);
    q.push(5);
    q.push(6);
    cout << q.front() << endl; //4

    return 0;
}