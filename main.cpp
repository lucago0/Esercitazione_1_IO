#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

double fun(double x)
{
    return (3.*x)/4.-7./4.;
}

int main()
{
    string fileName = "data.csv";
    ifstream ifstr(fileName);
    ofstream outFile("result.csv");

    if(ifstr.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }

    double val = 0;
    double sumValues = 0;
    unsigned int countVal = 0;

    outFile << "#" << ' ' << "N Mean" << endl;
    while(ifstr >> val)
    {
        sumValues += fun(val);
        countVal++;
        outFile << countVal << ' ' << scientific << setprecision(16) << sumValues/countVal << endl;
    }

    ifstr.close();
    outFile.close();

    return 0;
}
