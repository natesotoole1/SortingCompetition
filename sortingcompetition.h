#ifndef SORTINGCOMPETITION_H
#define SORTINGCOMPETITION_H
#include <string>
#include <vector>

using namespace std;

class sortingcompetition
{

    private:

    string inFile;
    vector<string> wordIn;
    vector<string> wordCopy;

    void selectionSortLen(vector<string>&, int);
    void selectionSortAlph(vector<string>&, int);

    public:

    sortingcompetition(const string& inputFileName);
    void setFileName(const string& inputFileName);
    bool readData();

    bool prepareData();
    void sortData();
    void outputData(const string& outputFileName);

};


#endif // SORTINGCOMPETITION_H
