#ifndef SORTINGCOMPETITION_H
#define SORTINGCOMPETITION_H
#include <string>
#include <vector>

using namespace std;

class SortingCompetition
{

    private:

    string inFile;
    vector<char*> wordIn;
    vector<char*> wordCopy;

    void selectionSortLen(vector<char*>&, int, int);
    void selectionSortAlph(vector<char*>&, vector<char*>::iterator, vector<char*>::iterator);
    void insertselectionSortLen(vector<char*>&, int, int);
    void insertselectionSortAlph(vector<char*>&, vector<char*>::iterator, vector<char*>::iterator);


    void quickSortLen(vector<char*>&, int, int);
    void quickSortAlph(vector<char*>&, vector<char*>::iterator, vector<char*>::iterator);
    void insertSortLen(vector<char*>&, int, int);
    void insertSortAlph(vector<char*>&, vector<char*>::iterator, vector<char*>::iterator);

    public:

    SortingCompetition(const string& inputFileName);
    void setFileName(const string& inputFileName);
    bool readData();

    bool prepareData();
    void sortData();
    void outputData(const string& outputFileName);

};


#endif // SORTINGCOMPETITION_H
