//Задание
/*Составить программу, которая содержит динамическую информацию о
автобусных перевозках в виде односвязного списка. Сведения о каждой перевозке
включают:
– номер автобуса;
– фамилию и инициалы водителя;
– пункт убытия
– пункт прибытия
– время в пути
Программа должна обеспечивать:
1) вывод меню для работы со списком;
2) вывод всех автобусов;
3) добавление автобуса в начало списка;
4) добавление автобуса в конец списка;
5) добавление автобуса после определенного автобуса;
6) добавление автобуса перед определенным автобусом;
7) по запросу выдаются сведения об автобусах, отправляющихся в
определенный город.
8) по запросу выдаются сведения об автобусах в отсортированном виде по
времени в пути.
9) по запросу выдаются сведения об автобусах в интервале времени,
введенного пользователем;
10) сохранение данных списка автобусов в текстовый файл.
11) извлечение данных из текстового файла и помещение новых
автобусов в список.
Программа должна обеспечивать диалог с помощью меню и контроль
ошибок при вводе.*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <Windows.h>//Библиотеки
using namespace std;

//Структура списка
struct Node
{
    string nomber;
    string FIO;
    string Ybbltie;
    string Pribbltie;
    int time;

    Node* next;
};
typedef Node* PNode;
PNode Head = NULL;

//Вывод списка
void Print(PNode& Head)
{
    PNode q = Head;

    while (q != NULL)
    {
        cout << "Номер автобуса " << q->nomber << endl;
        cout << "Фамилия и иницыалы водителя " << q->FIO << endl;
        cout << "Пункт убытия " << q->Ybbltie << endl;
        cout << "Пункт прибытия " << q->Pribbltie << endl;
        cout << "Время в пути " << q->time << endl;
        cout << "**********************************************" << endl;
        q = q->next;
    }

    if (Head == NULL)
    {
        cout << "----------------------------------------------" << endl;
        cout << "Список пока пуст" << endl;
        cout << "----------------------------------------------" << endl;
    }
}

//Добаыление узла в начало списка
void AddFirst(PNode& Head, string fnomber, string fFIO, string fYbbltie, string fPribbltie, int ftime)
{
    PNode NewNode = new Node;

    NewNode->nomber = fnomber;
    NewNode->FIO = fFIO;
    NewNode->Ybbltie = fYbbltie;
    NewNode->Pribbltie = fPribbltie;
    NewNode->time = ftime;

    NewNode->next = Head;
    Head = NewNode;
}

//Добавление узла в конец списка
void AddLast(PNode& Head, string fnomber, string fFIO, string fYbbltie, string fPribbltie, int ftime)
{
    PNode NewNode = new Node;

    NewNode->nomber = fnomber;
    NewNode->FIO = fFIO;
    NewNode->Ybbltie = fYbbltie;
    NewNode->Pribbltie = fPribbltie;
    NewNode->time = ftime;

    PNode q = Head;

    if (Head == NULL)
    {
        NewNode->next = Head;
        Head = NewNode;
    }

    while (q->next != NULL)
    {
        q = q->next;
    }

    NewNode->next = q->next;
    q->next = NewNode;
}

//поиск узлов
PNode Poisk(PNode pfind, PNode& Head)
{
    string poisk;

    cout << "Введите ФИО человека которого нужно найти - ";
    cin.ignore();
    getline(cin, poisk);

    pfind = Head;

    while (poisk != pfind->FIO && pfind != NULL)
    {
        pfind = pfind->next;
        if (pfind == NULL)
        {
            cout << "Такого ФИО нет" << endl;
            return NULL;
            break;
        }
    }

    if (poisk == pfind->FIO)
    {
        return pfind;
    }
};

//Добавление узла после заданного
void AddAfter(PNode& Head, string fnomber, string fFIO, string fYbbltie, string fPribbltie, int ftime, PNode p)
{
    PNode NewNode = new Node;
    NewNode->next = NULL;

    NewNode->nomber = fnomber;
    NewNode->FIO = fFIO;
    NewNode->Ybbltie = fYbbltie;
    NewNode->Pribbltie = fPribbltie;
    NewNode->time = ftime;

    NewNode->next = p->next;
    p->next = NewNode;
}

//Добавление узла перед заданным
void AddBefore(PNode& Head, string fnomber, string fFIO, string fYbbltie, string fPribbltie, int ftime, PNode p)
{
    PNode NewNode = new Node;

    NewNode->nomber = fnomber;
    NewNode->FIO = fFIO;
    NewNode->Ybbltie = fYbbltie;
    NewNode->Pribbltie = fPribbltie;
    NewNode->time = ftime;

    PNode q = Head;

    if (Head == p)
    {
        NewNode->next = Head;
        Head = NewNode;
    }

    while (q->next != p && q != NULL)
    {
        q = q->next;
    }

    if (q != NULL)
    {
        NewNode->next = q->next;
        q->next = NewNode;
    }
}

//Автобусы отправившиеся в определенный город
void FindCity(PNode& Head, string city)
{
    PNode q = Head;

    while (q != NULL)
    {
        if (q->Pribbltie == city)
        {
            cout << "Номер автобуса " << q->nomber << endl;
            cout << "Фамилия и иницыалы водителя " << q->FIO << endl;
            cout << "Пункт убытия " << q->Ybbltie << endl;
            cout << "Пункт прибытия " << q->Pribbltie << endl;
            cout << "Время в пути " << q->time << endl;
            cout << "**********************************************" << endl;
        }
        q = q->next;
    }
}

//Сортировка по времени
void SortTime(PNode& Head, int h) 
{
    Node* d = new Node[h];
    Node temp;
    PNode f = Head;

    for (int i = 0; i < h; i++) {
        d[i].time = f->time;
        d[i].FIO = f->FIO;
        d[i].nomber = f->nomber;
        d[i].Pribbltie = f->Pribbltie;
        d[i].Ybbltie = f->Ybbltie;
        f = f->next;
    }

    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < h-1; j++) 
        {
            if (d[j].time > d[j + 1].time) 
            {
                temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
            }
        }
    }

    Head = NULL;

    for (int i = h - 1; i >= 0; i--) 
    {
        AddFirst(Head, d[i].nomber, d[i].FIO, d[i].Ybbltie, d[i].Pribbltie, d[i].time);
    }

    delete[] d;
}

//Счет количества узлов
int KolNode(PNode& Head)
{
    PNode p = Head;
    int a = 0;

    while (p != NULL)
    {
        a++;
        p = p->next;
    }

    return a;
}

//Автобусы в интервал времени
void IntervalTime(PNode& Head)
{
    int TimeMin, TimeMax, i=1;
    PNode s = Head;

    cout << "Введите нижнюю границу времени: ";
    cin >> TimeMin;
    cout << "Введите верхнюю границу времени: ";
    cin >> TimeMax;

    while (s != NULL)
    {
        if (s->time >= TimeMin && s->time <= TimeMax)
        {
            cout << "Водитель № " << i << endl;
            cout << "Номер автобуса " << s->nomber << endl;
            cout << "Фамилия и иницыалы водителя " << s->FIO << endl;
            cout << "Пункт убытия " << s->Ybbltie << endl;
            cout << "Пункт прибытия " << s->Pribbltie << endl;
            cout << "Время в пути " << s->time << endl;
            cout << "**********************************************" << endl;
            i++;
        }
        s = s->next;
    }
}

//Запись в файл.txt
void zapis_txt(PNode& Head)
{
    PNode q = Head;
    string road = "DoraDura.txt";
    ofstream fout;

    fout.open(road);

    if (fout.is_open())//Если файл был открыт
    {
        while (q != NULL)
        {
            fout << "Номер автобуса " << q->nomber << endl;
            fout << "Фамилия и иницыалы водителя " << q->FIO << endl;
            fout << "Пункт убытия " << q->Ybbltie << endl;
            fout << "Пункт прибытия " << q->Pribbltie << endl;
            fout << "Время в пути " << q->time << endl;
            q = q->next;
        }
        cout << "*Данные сохранены в файл. Если хотите убедиться, загляните в папку с проектом*" << endl;
    }
    else
    {
        cout << "Ощибка 404. Файл не был открыт." << endl;
    }

    fout.close();
}

//Извлечение данных из вайла.txt
void Izvlechenie_txt(PNode& Head)
{
    PNode q = Head;
    string road = "DoraDura.txt";
    ifstream fin;

    fin.open(road);

    if (fin.is_open())//Если файл был открыт
    {
        cout << "Файл открыт" << endl;
        string str;

        while (!fin.eof())
        {
            str = "";
            getline(fin, str);
            cout << str << endl;
        }
    }
    else
    {
        cout << "Ощибка 404. Файл не был открыт." << endl;
    }

    fin.close();
}

//Мозг программы
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PNode Head = NULL;
    string fnomber, fFIO, fYbbltie, fPribbltie, city;
    string vrema;
    int ftime;
    int t;
    PNode p = NULL;

    do
    {
        cout << "----------------------------------------------" << endl;
        cout << "**********************************************" << endl;
        cout << "1 - вывод всех автобусов" << endl;
        cout << "2 - добавление автобуса в начало списка" << endl;
        cout << "3 - добавление автобуса в конец списка" << endl;
        cout << "4 - добавление автобуса после определенного автобуса" << endl;
        cout << "5 - добавление автобуса перед определенным автобусом" << endl;
        cout << "6 - по запросу выдаются сведения об автобусах, отправляющихся в определенный город" << endl;
        cout << "7 - по запросу выдаются сведения об автобусах в отсортированном виде по времени в пути" << endl;
        cout << "8 - по запросу выдаются сведения об автобусах в интервале времени, введенного пользователем" << endl;
        cout << "9 - сохранение данных списка автобусов в текстовый файл" << endl;
        cout << "10 - извлечение данных из текстового файла и помещение новых автобусов в список" << endl;
        cout << "0 - закрыть меню" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "**********************************************" << endl;
        cout << "Введите одну из предложенных команд - ";

        cin >> t;
        cout << "**********************************************" << endl;
        cout << "----------------------------------------------" << endl;

        switch (t)
        {
        case 1:
            Print(Head);
            break;
        case 2:
            cout << "Добавление автобуса в начало списка" << endl;
            cout << "Номер автобуса ";
            cin.ignore(127, '\n');
            getline(cin, fnomber);
            cout << "Фамилию и инициалы водителя ";
            getline(cin, fFIO);
            cout << "Пункт убытия ";
            getline(cin, fYbbltie);
            cout << "Пункт прибытия ";
            getline(cin, fPribbltie);
            cout << "Время в пути ";
            cin>>ftime;

            AddFirst(Head, fnomber, fFIO, fYbbltie, fPribbltie, ftime);
            break;

        case 3:
            cout << "Добавление автобуса в конец списка" << endl;
            cout << "Номер автобуса ";
            cin.ignore(127, '\n');
            getline(cin, fnomber);
            cout << "Фамилию и инициалы водителя ";
            getline(cin, fFIO);
            cout << "Пункт убытия ";
            getline(cin, fYbbltie);
            cout << "Пункт прибытия ";
            getline(cin, fPribbltie);
            cout << "Время в пути ";
            cin >> ftime;

            AddLast(Head, fnomber, fFIO, fYbbltie, fPribbltie, ftime);
            break;
        case 4:
            cout << "Добавление автобуса после заданного" << endl;
            cout << "Номер автобуса ";
            cin.ignore(127, '\n');
            getline(cin, fnomber);
            cout << "Фамилию и инициалы водителя ";
            getline(cin, fFIO);
            cout << "Пункт убытия ";
            getline(cin, fYbbltie);
            cout << "Пункт прибытия ";
            getline(cin, fPribbltie);
            cout << "Время в пути ";
            cin >> ftime;

            p = Poisk(p, Head);
            if (p != NULL)
            {
                AddAfter(Head, fnomber, fFIO, fYbbltie, fPribbltie, ftime, p);
            }
            break;
        case 5:
            cout << "Добавление автобуса перед заданным" << endl;
            cout << "Номер автобуса ";
            cin.ignore(127, '\n');
            getline(cin, fnomber);
            cout << "Фамилию и инициалы водителя ";
            getline(cin, fFIO);
            cout << "Пункт убытия ";
            getline(cin, fYbbltie);
            cout << "Пункт прибытия ";
            getline(cin, fPribbltie);
            cout << "Время в пути ";
            cin >> ftime;

            p = Poisk(p, Head);
            if (p != NULL)
            {
                AddBefore(Head, fnomber, fFIO, fYbbltie, fPribbltie, ftime, p);
            }
            break;
        case 6:
            cout << "Город: ";
            cin >> city;

            FindCity(Head, city);
            break;
        case 7:
            cout << "Список отсортирован, чтобы вывести нажмите *1*" << endl;
            SortTime(Head, KolNode(Head));
            break;
        case 8:
            IntervalTime(Head);
            break;
        case 9:
            zapis_txt(Head);
            break;
        case 10:
            Izvlechenie_txt(Head);
            break;
        case 0:
            cout << "ЮХУУУУ, вы наконец-то вышли с этой убогой программы" << endl;
            break;
        default:
            cout << "Такой комбинации у нас нет. УВЫ((" << endl;
            break;
        }

    } while (t != 0);
}