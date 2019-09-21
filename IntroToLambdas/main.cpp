#include <iostream>
#include <string>

using namespace std;

int main()
{
    /**
     * [capture list](parameter list) { function body }
     * Define function
    **/

    auto func = [](){
        cout << "Hello World!" << endl;
    };

    // Call function
    func(); // Will print "Hello World!" to the console


    /*
    //Define a function print that will take a string and print it to
    //the terminal
    auto print = [](string str) {
        cout << str << endl;
    };

    //Quick easy way of defining functions to use in your program
    print("Hello World!");
    */

    /*
    //Define lambda function that returns a something
    auto sum = [](int a, int b)-> int{
        return a + b;
    }(5,6);

    // prints the addition of 5+6 to the terminal
    cout << sum << endl;
    */

    /*
    //Capture lists
    int a = 5;
    int b = 4;

    //define lambda function with capture lists
    [a,b](){
        cout << "a is: " << a << endl;
        cout << "b is: " << b << endl;
    }();
    */

    //capture c by reference
//    int c = 20;
//    int d = 30;
    /*
    auto function = [&c](){
        cout << "The inner value of c is :" << c << endl;
    };
    for(int i = 1; i <= 10; i++){
        cout << "The outer value of c is: " << c << endl;
        function();
        c++;
    }
    */

//    // capture c by value
//    auto function = [c](){
//        cout << "The inner value of c is :" << c << endl;
//    };
//    for(int i = 1; i <= 10; i++){
//        cout << "The outer value of c is: " << c << endl;
//        function();
//        c++;
//    }


//    // capture everything by reference
//    auto function2 = [&](){
//        cout << "The inner value of d is :" << d << endl;
//        cout << "The inner value of c is :" << c << endl;
//    };
//    for(int i = 1; i <= 10; i++){
//        cout << "The outer value of d is: " << d << endl;
//        cout << "The outer value of c is: " << c << endl;
//        function2();
//        c++;
//        d++;
//    }

//    // capture everything by value
//    auto function3 = [&](){
//        cout << "The inner value of d is :" << d << endl;
//        cout << "The inner value of c is :" << c << endl;
//    };
//    for(int i = 1; i <= 10; i++){
//        cout << "The outer value of d is: " << d << endl;
//        cout << "The outer value of c is: " << c << endl;
//        function3();
//        c++;
//        d++;
//    }
    return 0;
}
