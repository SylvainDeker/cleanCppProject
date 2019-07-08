#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <QApplication>


#include "version.h"
#include "qt/MainWindow.hpp"

using namespace std;

void printHelp()
{
    cout << "Help for cleanCppApplication " << endl;
    cout << "Version: " << Version::current().asLongStr() << endl;
    cout << "Version: " << Version::current().asShortStr() << endl;
    cout << "Version: " << Version::current().asNumber() << endl;
    cout << "Author:  " << endl;
    cout << "URL:     " << endl;
    /// @todo Do stuff in here also
}

/**
 * Example UML diagram:
 *
 * \startuml
 *
 * [-> main : start program
 *
 * activate main
 *
 * main -> main : process parameters
 *
 * main -> Version : get version
 *
 * activate Version
 * Version -> Version : loads version
 * Version -> main
 * deactivate Version
 *
 * main -> main : prints version
 *
 * main -> SomeClass : create instance
 * activate SomeClass
 * SomeClass -> BaseClass : call constructor
 * activate BaseClass
 *
 * main -> SomeClass : do stuff
 * activate SomeClass
 * SomeClass -> main : return stuff
 * deactivate SomeClass
 *
 * BaseClass -> SomeClass
 * deactivate BaseClass
 * SomeClass -> main
 * deactivate SomeClass
 *
 * deactivate main
 *
 * \enduml
 */
int main(int argc, char * argv[])
{
    // Print help if no arguments are given
    if (argc == 1)
        printHelp();
	
    // process parameters
    

    int argIt;
    for (argIt = 1; argIt < argc; ++argIt)
    {
        string tmp = argv[argIt];

        if (tmp == "--help" || tmp == "-h")
            printHelp();
        else if (tmp == "--version")
            cout << "v" << Version::current().asLongStr() << endl;
        else
            break;
    }

    
    QApplication aqt( argc, argv );

    MainWindow hello(nullptr);
    hello.resize( 600, 300 );

    hello.show();
    return aqt.exec(); 
    
}
