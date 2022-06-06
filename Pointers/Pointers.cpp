// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <memory>
using namespace std;

int x = 42;
void uniquePointer()
{
    cout << "\nUnique pointers are a type of smart pointer that will assume complete ownership of an object or resource.\n";
    Sleep(5000);
    // pros
    cout << "Unique pointers will free the memory space they were using once they go out of scope.\n";
    Sleep(5000);
    cout << "They can also transfer ownership of the resource using the std::move() function.\n";
    Sleep(5000);
    cout << "Which will keep the object alive, but change the value of the original pointer to null.\n\n"; 
    Sleep(5000);
    // cons
    cout << "As the name suggests, there can only be one copy of a unique pointer.\n";
    Sleep(5000);
    cout << "This means if you were to try to access the memory location of a unique pointer with another pointer,\n";
    Sleep(5000);
    cout << "you will run into an compile error when you try to run the program.\n\n";
    Sleep(5000);
    // when to use
    cout << "Unique pointers are best when you only want one pointer to have ownership of an object or resource at a time, \n";
    Sleep(5000);
    cout << "and delete the resource once it's no longer in use.\n \n";
    Sleep(5000);
    cout << "To create a unique pointer, you'll use the keyword 'unique_ptr<data type>'.\n";
    Sleep(5000);
    cout << "Afterwards you will give the pointer a name like you would to any variable, and use 'make_unique<data type>(reference)' when you're initializing the pointer.\n\n\n";
}

void sharedPointer() 
{
    cout << "\nUnlike unique pointers, shared pointers are capable of sharing ownership of the same resource.\n";
    Sleep(5000);
    // pros
    cout << "Shared pointers use a reference counter to track how many pointers are currently associated with a object or resource.\n";
    Sleep(5000);
    cout << "The reference counter keeps the object active until the last pointer goes out of scope.\n";
    Sleep(5000);
    cout << "This allows the same piece of memory to be used constantly throughout a program even after the first pointer has been destroyed.\n\n";
    Sleep(5000);
    // cons
    cout << "However, since the reference counter will keep the object alive until the last pointer is destroyed,\n";
    Sleep(5000);
    cout << "there will always be a block of memory that will never be freed as long as there are still pointers trying to use it. \n";
    Sleep(5000);
    // when to use
    cout << "Shared pointers are ideal for when you want multiple pointers to share the same resource.\n\n";
    Sleep(5000);
    cout << "Shared pointers use the keywords 'shared_ptr<data type>' for declaring and 'make_shared<data type>(reference)' for iniializing \n\n\n";
    Sleep(5000);

}

void weakPointer()
{
    
    // pros
    cout << "\nWeak pointers function similar to shared pointers, but are excluded from the reference count.\n";
    Sleep(5000);
    cout << "Weak pointers are able to reference an object but will not take owenership of any resources\n";
    Sleep(5000);
    // cons
    cout << "Unlike shared pointers and unique pointers, weak pointers will not keep an object alive when it has to access it.\n\n";
    Sleep(5000);

    // when to use
    cout << "Weak pointers are used best along when you want to reference the same object or resource \n";
    Sleep(5000);
    cout << "a shared pointer is using, without increasing the reference count.\n\n";
    Sleep(5000);

    cout << "Weak pointers use 'weak_ptr<data type>pointerName = reference' when declaring/initializing the pointer\n\n\n";
    Sleep(5000);
}

int main()
{
    
    // introduction
    cout << "Welcome, this program will give a brief introduction into the different types of smart pointers,\n";
    cout << "and when is the best time to use them.\n";
    string userInput;
    cout << "Type 'start' to begin\n";
    while (userInput != "start")
    {
        // only continue if the user types "start"
        cin >> userInput;
    }
    // Give an introduction on unique pointers
    uniquePointer();

    // Create a unique pointer to reference x
    unique_ptr<int>xPtr = make_unique<int>(x);
    cout << "By using 'unique_ptr<int>xPtr = make_unique<int>(x);'\n";
    Sleep(5000);
    cout << "We can create a unique pointer called 'xPtr' and point it to the variable 'x',\n";
    Sleep(5000);
    cout << "and gain access to x's memory address, and dereference the pointer to gain x's value.\n\n";
    Sleep(5000);

    // print the value of x, the value of xPtr, and the dereferenced value of xPtr
    cout << "The value of the variable 'x' is: " << x << endl;
    cout << "The address the unique pointer 'xPtr' is pointing to: " << xPtr << endl;
    cout << "The value of the dereferenced unique pointer: " << *xPtr << endl;
   
    cout << "Type 'c' to continue\n";
    while (userInput != "c")
    {
        // only continue if the user types "c"
        cin >> userInput;
    }
    // Give an introduction on shared pointers
    sharedPointer();
    // reset the value of userInput
    userInput.clear();
    cout << "Type 'c' to continue\n";
    while (userInput != "c")
    {
        // only continue if the user types "start"
        cin >> userInput;
    }
    // Give an introduction on weak pointers
    weakPointer();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
