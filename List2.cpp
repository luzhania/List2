#include <iostream>
#define CAPACITY 20

using namespace std;

template<typename T>

class List2
{
    // Class comment
    private:
        T arr[CAPACITY];
        int first;
        int last;
    public:
        List2()
        {
            first = -1;
            last = -1;
        }

        bool isEmpty()
        {
            return ((first == -1) && (last == -1));
        }

        bool isFull()
        {
            return ((first == last + 1) || ((first == 0) && (last == CAPACITY -1)));
        }

        int size()
        {
            int Size;
            if (first > last)
                Size = CAPACITY - first + last + 1;
            else
                Size = last - first + 1;
            return Size;
        }

        bool insertLast(T element)
        {
            bool ans = false;
            if (!isFull())
            {
                ans = true;
                if (isEmpty())
                {
                    first = CAPACITY / 2;
                    last = CAPACITY / 2;
                }
                else
                {
                    if (last == CAPACITY - 1)
                        last = 0;
                    else
                        last++;
                }
                arr[last] = element;
            }
            return ans;
        }

        bool insertFirst(T element)
        {
            bool ans = false;
            if (!isFull())
            {
                ans = true;
                if (isEmpty())
                {
                    first = CAPACITY / 2;
                    last = CAPACITY / 2;
                }
                else
                {
                    if (first == 0)
                        first = CAPACITY - 1;
                    else
                        first--;
                }
                arr[first] = element;
            }
            return ans;
        }

        bool deleteLast()
        {
            bool ans = false;
            if (!isEmpty())
            {
                ans = true;
                if (first == last) //1 element
                {
                    first = -1;
                    last = -1;
                }
                else
                {
                    if(last == 0)
                        last = CAPACITY - 1;
                    else
                        last--;
                }
            }
            return ans;
        }

        bool deleteFirst()
        {
            bool ans = false;
            if (!isEmpty())
            {
                ans = true;
                if (first == last) //1 element
                {
                    first = -1;
                    last = -1;
                }
                else
                {
                    if(first == CAPACITY - 1)
                        first = 0;
                    else
                        first++;
                }
            }
            return ans;
        }

        void showList()
        {
            int i = first;
            int aux = 0;
            int Size = size();
            while(aux < Size)
            {
                cout << arr[i] << endl;
                if (i == CAPACITY - 1)
                    i = 0;
                else
                    i++;
                aux++;
            }
        }

        int search(T searchElement) //find the first element
        {
            int searchPos = -1;
            int i = first;
            int aux = 0;
            int Size = size();
            while (aux < Size - 1 && searchPos == -1)
            {
                if (arr[i] == searchElement)
                    searchPos = i;
                if (i == CAPACITY - 1)
                    i = 0;
                else
                    i++;
                aux++;
            }
            return searchPos;
        }

        void bubbleSort()
        {
            int i, j, k, Size, aux;
            Size = size();
            i = 0;
            aux = last;
            while(i < Size)
            {
                j = first;
                while (j != aux)
                {
                    k = j + 1;
                    if (j == CAPACITY - 1)
                        k = 0;

                    if (arr[j] > arr[k])
                        swap(arr[j], arr[k]);
                    
                    if (j == CAPACITY - 1)
                        j = 0;
                    else
                        j++;
                }
                if (first > last && aux == 0)
                    aux = CAPACITY; 
                aux--;  
                i++;              
            }
        }
        
        static List2 intercalate(List2& lst1, List2& lst2, int size, int& aux, int& i, int& j)
        {
            List2 lstR;
            while (aux < size)
            {
                lstR.insertLast(lst1.arr[i]);
                lstR.insertLast(lst2.arr[j]);
                if(i == CAPACITY - 1)
                    i = 0;
                else 
                    i++;
                if(j == CAPACITY - 1)
                    j = 0;
                else
                    j++;
                aux++;
            }
            return lstR;
        }

        static void copy(int start, List2& lst, List2& lstR, int aux)
        {
            int i = start;
            while (aux < lst.size())
            {
                lstR.insertLast(lst.arr[i]);
                if(i == CAPACITY - 1)
                    i = 0;
                else 
                    i++;
                aux++;
            }
        }

        static List2 merge(List2& lst1, List2& lst2)
        {
            List2 lstR;
            int size1 = lst1.size();
            int size2 = lst2.size();

            int i = lst1.first;
            int j = lst2.first;
            
            int aux = 0;
            if (size1 > size2)
            {
                lstR = intercalate(lst1, lst2, size2, aux, i, j);
                copy(i, lst1, lstR, aux);
            }
            else
            {
                lstR = intercalate(lst1, lst2, size1, aux, i, j);
                copy(j, lst2, lstR, aux);
            }
            return lstR;
        }
};


class Utils
{
    public:
        static int menu()
        {
            int option;
            cout << "---------------MENU---------------" << endl;
            cout << "1. Insert last" << endl;
            cout << "2. Insert first" << endl;
            cout << "3. Delete last" << endl;
            cout << "4. Delete first" << endl;
            cout << "5. Show list" << endl;
            cout << "6. Search element in the list" << endl;
            cout << "7. Bubble sort" << endl;
            cout << "8. Merge" << endl;
            cout << "0. Exit" << endl;
            cout << "-----------------------------------" << endl;
            cout << "Select an option: ";
            cin >> option;
            return option;
        }
};

int main()
{
    int option;
    int element, ans;
    List2<int> l, l2, lR;
    l.insertFirst(0);
    l.insertFirst(2);
    l.insertFirst(5);
    l.insertFirst(4);
    l.insertFirst(108);
    l.insertFirst(10);
    l.insertFirst(100);
    l.insertFirst(11);
    l.insertLast(32);
    l2.insertLast(-1);
    l2.insertLast(-3);
    l2.insertLast(-4);
    l2.insertLast(-5);
    do{
        option = Utils::menu();
        system("cls");
        switch(option)
        {
            case 1: //insert last
                cout << "Original array: " << endl;
                l.showList();
                cout << "---------------------" << endl;
                cout << "Element to insert: ";
                cin >> element;
                if(l.insertLast(element))
                    cout << "The element was inserted last" << endl;
                else
                {
                    cout << "The array is full" << endl;
                    cout << "The element wasn't inserted" << endl;
                }
                l.showList();
                system("pause");
                break;
            case 2: //insert first
                cout << "Original array: " << endl;
                l.showList();
                cout << "---------------------" << endl;
                cout << "Element to insert: ";
                cin >> element;
                if(l.insertFirst(element))
                    cout << "The element was inserted first" << endl;
                else
                {
                    cout << "The array is full" << endl;
                    cout << "The element wasn't inserted" << endl;     
                }
                l.showList();
                system("pause");
                break;
            case 3: //delete last
                cout << "Original array: " << endl;
                l.showList();
                cout << "---------------------" << endl;
                if (l.deleteLast())
                {
                    cout << "The last element was deleted" << endl;
                    if (!l.isEmpty())
                        l.showList();
                }    
                else
                {
                    cout << "The array is empty" << endl;
                    cout << "The element wasn't deleted" << endl;
                }
                system("pause");
                break;
            case 4: //delete first
                cout << "Original array: " << endl;
                l.showList();
                cout << "---------------------" << endl;
                if (l.deleteFirst())
                {
                    cout << "The first element was deleted" << endl;
                    if (!l.isEmpty())
                        l.showList();
                }    
                else
                {
                    cout << "The array is empty" << endl;
                    cout << "The element wasn't deleted" << endl;
                }
                system("pause");
                break;
            case 5: //show list
                if (!l.isEmpty())
                    l.showList();
                else
                    cout << "The array is empty" << endl;
                system("pause");
                break;
            case 6: //search element
                cout << "Original array: " << endl;
                l.showList();
                cout << "---------------------" << endl;
                cout << "Element to search" << endl;
                cin >> element;
                ans = l.search(element);
                if (ans != -1)
                    cout << "The element is in the position " << ans << endl;
                else
                    cout << "The element isn't in the array" << endl;
                system("pause");
                break;
            case 7://BubbleSort
                cout << "Original array: " << endl;
                l.showList();
                cout << "---------------------" << endl;
                cout << "Sorted array" << endl;
                l.bubbleSort();
                l.showList();
                system("pause");
                break;
            case 8: //merge
                cout << "Array 1:" << endl;
                l.showList();
                cout << "---------------------" << endl;
                cout << "Array 2:" << endl;
                l2.showList();
                lR = l.merge(l2, l);
                cout << "---------------------" << endl;
                cout << "Array Result:" << endl;
                lR.showList();
        }    
    }while(option != 0);
}