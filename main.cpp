#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <map>

int containerLength = 10;

using namespace std;

//Шаблонная функция заполнения коллекции. Добавляем на (последний элемент + 1) рандомное число
template <typename Container>
void fillContainer(Container &t, int count)
{

    for (int i = 0, r; i < count; i++)
    {
        int temp = rand() % 10 + 1;
        t.insert(t.end(), temp);
    }
}

//Шаблонная функция вывода коллекции.
template<typename Container>
void outputContainer(Container container) {
    //Создаем итератор, который ссылается на ячейку с первым элементом
    typename Container::iterator i = container.begin();

    //Цикл, пока итератор не будет ссылаться на ячейку на один элемент больше последнего
    while (i != container.end())
    {
        // Чтобы получить значение итератор, ставим *
        cout << *i << " ";
        ++i;
    }
    cout << endl;
}


void myVector() {
    cout << "vector:" << endl << "------------" << endl;

    //Засекаем время отсчета
    //long start = clock();

    //Создаем вектор
    vector<int> vec;

    //Вызываем функцию заполнения коллекции
    fillContainer(vec, containerLength);
    //Вызываем функцию вывода коллекции (убрать вывод при подсчете времени)
    outputContainer(vec);

    //Функция count_if ищет количество элементов, соответствующих условию. Из количества нужно вычесть сам элемент последний
    // В предикат лямбда-функция
    // [vec] - сторонние от лямбда-функции переменные, нужные в ней
    // (что получаем на входе)
    // -> Что выводит
    // vec.back() - последний элемент вектора
    int count = count_if(vec.begin(), vec.end(),  [vec](int i) -> bool {return i == vec.back();}) - 1;

    //Записывает время окончания работы
    //long end = clock();

    //cout << "Время: " << end - start << endl;
    cout << count;
}

void myList() {
    cout << "list:" << endl << "------------" << endl;

    //long start = clock();

    list<int> list;
    fillContainer(list, containerLength);
    outputContainer(list);

    int count = count_if(list.begin(), list.end(),  [list](int i){return i == list.back();}) - 1;

    //long end = clock();

    //cout << "Время: " << end - start << endl;
    cout << count ;
}

void myMultiset() {
    cout << "multiSet:" << endl << "------------" << endl;

    //long start = clock();

    multiset<int> myMultiSet;
    fillContainer(myMultiSet, containerLength);
    outputContainer(myMultiSet);

    int count = count_if(myMultiSet.begin(), myMultiSet.end(),  [myMultiSet](int i){return i == *myMultiSet.rbegin();}) - 1;

    //long end = clock();

    //cout << "Время: " << end - start << endl;
    cout << count;
}

void myMap() {
    cout << "map:" << endl << "------------" << endl;

    //long start = clock();

    //map работает с парами ключ-значение
    map<int, int> myMap;

    for (int i = 0; i < containerLength; i++) {
        //заносим в map тип pair с двумя значениями. Уникальный ключ(индекс цикла взял), рандомное значение
        myMap.insert(pair<int, int>(i, rand() % 10 + 1));
    }


    typename map<int, int>::iterator i = myMap.begin();

    while (i != myMap.end())
    {
        cout << i->second << " ";
        ++i;
    }

    // myMap.rbegin() выдает последний элемент(пару). Чтобы получить значение, вызови переменную second
    int count = count_if(myMap.begin(), myMap.end(),  [myMap](pair<int, int> myPair){return myPair.second == myMap.rbegin()->second;}) - 1;

    //long end = clock();

    //cout << "Время: " << end - start << endl;
    cout << endl << count;
}

int main() {
    srand (time(NULL));
    system("chcp 65001");

    myVector();
    cout << endl << endl;

    myList();
    cout << endl << endl;

    myMultiset();
    cout << endl << endl;

    myMap();

    return 0;
}
