// Title: find and substr
// Purpose: Using string operation find and substr
// Author: Fransiskus Agapa
// Have fun - Enjoy the process - Practices make improvement

#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;
using std::getline;

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

int main()
{
    cout << endl;
    string fileName;                           // user-input filename
    ifstream in;                              // deal with file - open file

    cout << "Input filename: ";
    getline(cin,fileName);
    in.open(fileName);                       // try to open file
    if(!in.is_open())                           // check if its open
    {
        cout << endl << "![File cannot be processed/open]" << endl;
                                   // clean error flag
    } else                                      // file is open
    {
        // obj.find(c) | obj.find(c,start);
        // obj.substr(start,length)
        string line;
        cout << endl << "The raw data in file :" << endl;
        while(getline(in,line))
        {
            cout << "[ " << line << " ]" << endl;
        }
        cout << endl << "The extraction of data = " << endl;
        int oneSlash = line.find('/');
        int twoSlash = line.find('/',oneSlash + 1);
        int thirdSlash = line.find('/',twoSlash+1);
        string wholeLine;

        cout << "1st slash: " << oneSlash << endl;
        cout << "1st word: " << line.substr(0,oneSlash) << endl;
        wholeLine += line.substr(0,oneSlash) + ' ';

        cout << endl << "2nd slash: " << twoSlash << endl;
        string tempStr = line.substr(oneSlash+1,twoSlash);
        int tempNum = tempStr.find('/',0);
        cout << "2nd word: " << line.substr(oneSlash+1,tempNum) << endl;
        wholeLine += line.substr(oneSlash+1,tempNum) + ' ';

        cout << endl << "3rd slash: " << thirdSlash << endl;
        tempStr = line.substr(twoSlash+1,thirdSlash);
        tempNum = tempStr.find('/',0);
        cout << "3rd word: " << line.substr(twoSlash+1, tempNum) << endl;
        wholeLine += line.substr(twoSlash+1, tempNum) + ' ';

        cout << endl << "4th word: " << line.substr(thirdSlash+1) << endl ;
        wholeLine +=  line.substr(thirdSlash+1);

        cout << endl << "Whole line: [ " << wholeLine << " ]" << endl;
    }

    in.close();                               // close file when finished
    cout << endl <<  "Exit Program";
    return 0;
}
