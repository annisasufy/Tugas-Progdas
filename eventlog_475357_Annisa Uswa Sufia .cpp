#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file ("event_log_windows_1000.txt");
    ofstream inf, warn, er;
    string keyword;

    if (!file.fail()){
    inf.open("information.txt");
    warn.open("warning.txt");
    er.open("error.txt");


    while (getline(file, keyword)){
    size_t w, i, e;
    w = keyword.find("Warning,");
    i = keyword.find("Information,");
    e = keyword.find("Error,");
        if (i!=string::npos){
            if(inf.is_open()){ 
            inf << keyword << endl;
            }
        }
        if (w!=string::npos){
            if(warn.is_open()){ 
            warn << keyword << endl;
            }
        }
        if (e!=string::npos){
            if(er.is_open()){ 
            er << keyword << endl;
            }
        }
    }
    }
    else{
        cout<< "Input file event_log_windows_1000.txt is not found";
    }
    inf.close();
    warn.close();
    er.close();
    file.close();
}
