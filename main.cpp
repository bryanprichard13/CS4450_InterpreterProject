#include <iostream>
// use for error message display
using std::cerr;
using std::endl;

extern FILE* yyin;
extern int yyparse();

int main(int argc, char** argv) {

    // check if the user has provided a file to interpret
    if(argc > 1 && argc < 3) {
        yyin = fopen(argv[1], "r");
        // check if the file can be opened for reading
        if(yyin == NULL) {
            cerr<<"The file you have provided can't be opened. Please try again or use a different file."<<endl;
            return 0;
        }
    } 
    // check if the user has provided too many arguments
    else if (argc > 3) {
        cerr<<"Too many arguments, please only provide a file.";
    }
    // else, no argument given. Let the user know they need to provide a file.
    else {
        cerr<<"You need to provide a file for the program to interpret."<<endl;
    }

}
