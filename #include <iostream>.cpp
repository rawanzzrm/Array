#include <iostream>

using namespace std;

class MyArray
{
    int index = 0;
    int* fixedArray;
    int sizeOfArray;

public: MyArray(int size)
{
    fixedArray = new int[size];
    sizeOfArray = size;
}

public: void Add(int item)
{
    if (index == sizeOfArray - 1)
    {
        cout << "Array is full\n";
        return;
    }

    fixedArray[index] = item;
    index++;
}



public: string Search(int number)
{
    for (int i = 0; i <= index; i++)
    {
        if (number == fixedArray[i])
            return "True";
    }

    return "False";
}

public: void RemoveAt(int indexOfNumber)
{
    if (indexOfNumber > index)
    {
        cout << "Invalid index";
        return;
    }
    else if (index == 0)
    {
        cout << "Array is Empty\n";
        return;
    }

    else if (indexOfNumber == index - 1)
        index--;

    else
    {
        for (int i = indexOfNumber; i < index; i++)
        {
            fixedArray[i] = fixedArray[i + 1];
        }

        index--;
    }

}

public: void InsertAt(int number, int indexOfNumber)
{
    if (index == sizeOfArray - 1)
    {
        cout << "Array is full\n";
        return;
    }


    else if (indexOfNumber > index)
    {
        cout << "Invalid index";
        return;
    }

    else if (index == 0)
        fixedArray[0] = number;

    else
    {
        for (int i = index; i > indexOfNumber; i--)
        {
            fixedArray[i] = fixedArray[i - 1];
        }

        fixedArray[indexOfNumber] = number;
    }

    index++;
}

public: void Print()
{
    for (int i = 0; i < index; i++)
        cout << fixedArray[i] << "\n";
}
};

int main()
{
    MyArray array(5);

    cout << "Add : \n";
    array.Add(1);
    array.Add(3);
    array.Add(4);
    array.Print();

    cout << "________\n";
    cout << "InsertAt : \n";
    array.InsertAt(20, 1);
    array.Print();

    cout << "________\n";
    cout << "Add more than size number\n";
    array.Add(5);
    array.Add(6);

    cout << "________\n";
    cout << "Remove : \n";
    array.RemoveAt(2);
    array.Print();


    cout << "________\n";
    cout << "Search : \n";
    cout << array.Search(1) << "\n";
    cout << array.Search(100) << "\n";

    return 0;
}