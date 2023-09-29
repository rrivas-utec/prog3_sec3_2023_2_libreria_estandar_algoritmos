#include <iostream>
#include <deque>
#include <list>
#include <map>
// Librerias de algoritmos
#include <algorithm>
#include <numeric>
#include <cmath> // No trabajan con iterador
using namespace std;

void ejemplo_algoritmo_find() {
    deque dq = {1, 10, 5, 7, 20, 21};
    list ls = {1, 10, 5, 7, 20, 21};
    map<char, int> mp = {{'A', 10},
                         {'Z', 20},
                         {'C', 30}};

    auto it = find(begin(dq), end(dq), 7); // deque<int>::iterator
    if (it != end(dq))
        cout << distance(begin(dq), it) << " " << *it << endl;

    auto it2 = find(begin(ls), end(ls), 7); // list<int>::iterator
    if (it2 != end(ls))
        cout << distance(begin(ls), it2) << " " << *it2 << endl;

    auto it3 = mp.find('Z'); // map<char, int>::iterator
    if (it3 != end(mp))
        cout << distance(begin(mp), it3) << " " << it3->second << endl;
}

bool multiple_7(int item) {
    return item % 7 == 0;
}

void ejemplo_algoritmo_find_if() {
    deque dq = {1, 10, 5, 7, 20, 21};
    list ls = {1, 10, 5, 7, 20, 21};
    map<char, int> mp = {{'A', 10},
                         {'Z', 7},
                         {'Z', 20},
                         {'C', 21}};

    auto it = find_if(begin(dq), end(dq), multiple_7);
    if (it != end(dq))
        cout << distance(begin(dq), it) << " " << *it << endl;

    it = find_if(next(it), end(dq), multiple_7);
    if (it != end(dq))
        cout << distance(begin(dq), it) << " " << *it << endl;

}

int sumar(int a, int b) {
    return a + b;
}

int multiplicar(int a, int b) {
    return a * b;
}

void ejemplo_puntero_funcion() {
    int (*ptr_fun1)(int, int);
    ptr_fun1 = sumar;
    cout << ptr_fun1(19, 6) << endl;
}

void show_operacion_aritmetica(int a, int b, int(*ptr_fun)(int, int)) {
    cout << ptr_fun(a, b);
}

template<typename T, typename Callable>
void show_operacion_aritmetica_2(T a, T b, Callable caller) {
    cout << caller(a, b);
}

template <typename Iterator, typename UnaryPredicate>
Iterator buscar_si(Iterator first, Iterator last, UnaryPredicate caller_up) {
    while(first != last) {
        if (caller_up(*first)) return first;
        ++first;
    }
    return first;
}

void ejemplo_callback() {
    show_operacion_aritmetica(10, 20, sumar);
    show_operacion_aritmetica_2(10, 20, multiplicar);
}

void ejemplo_funcion() {
    auto sumar_2 = [](int a, int b) { return a + b; };
    cout << sumar_2(10, 20) << endl;
}

void ejemplo_algoritmo_find_if_lambda() {
    deque dq = {1, 10, 5, 7, 20, 21};
    list ls = {1, 10, 5, 7, 20, 21};
    map<char, int> mp = {{'A', 10},
                         {'Z', 7},
                         {'Z', 20},
                         {'C', 21}};

    auto multiple_7 = [](auto item) { return item % 7 == 0;};

    auto it = find_if(begin(dq), end(dq), multiple_7);
    if (it != end(dq))
        cout << distance(begin(dq), it) << " " << *it << endl;

    it = find_if(next(it), end(dq), [](auto item) { return item % 7 == 0;});
    if (it != end(dq))
        cout << distance(begin(dq), it) << " " << *it << endl;

}

int main() {
//    ejemplo_algoritmo_find();
//    ejemplo_algoritmo_find_if();
//    ejemplo_puntero_funcion();
    ejemplo_funcion();
    return 0;
}
