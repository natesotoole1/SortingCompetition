#include "sortingcompetition.h"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

using namespace std;


sortingcompetition::sortingcompetition(const string& inputFileName){
    inFile = inputFileName;

}

void sortingcompetition::setFileName(const string& inputFileName){
    inFile = inputFileName;

}


//for selection sort
//reads the words from the file and stores it in a vector
bool sortingcompetition::readData()
{
    cout << "Inside read Data!" << endl << endl;

    ifstream input;
    input.open(inFile);
    if(!input)
    {
        cout << inFile << " couldn't be opened" << endl;
        return false;
    }

    string temp;
    string word;


    //Put inputfile into a vector
    while(input.is_open())
    {

        input >> temp;
        word = temp;

        //Push word to wordIn string
        wordIn.push_back(word);

        //POSSIBLY DELETE THE STRING
        //POSSIBLY REINITIALIZE THE STRING

        //close file if at end
        if(input.eof())
        {
            input.close();
        }

    }
    return true;

}




//Create a copy of the words so the same set can be tested multiple times and averaged
//for selection sort
bool sortingcompetition::prepareData()
{
    wordCopy.erase(wordCopy.begin(), wordCopy.end());
    wordCopy = wordIn;
    return true;

}



//Sorts the data
//for selection sort
void sortingcompetition::sortData()
{
    int numWords = wordCopy.size();

    //Sort by length
    selectionSortLen(wordCopy, numWords - 1);
    //Sort by alphabet
    selectionSortAlph(wordCopy, numWords - 1);    

}

//sort by length
//for selection sort
void sortingcompetition::selectionSortLen(vector<string>& words, int right)
{


    int n = right + 1;
       int pos_min;
       string temp = " ";
       //pos_min is short for position of min

           for (int i=0; i < n-1; i++)
           {
               pos_min = i;//set pos_min to the current index of array

               for (int j=i+1; j < n; j++)
               {

               if (words[j].length() < words[pos_min].length())
                          pos_min=j;
           //pos_min will keep track of the index that min is in, this is needed when a swap happens
               }

           //if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
                   if (pos_min != i)
                   {
                       temp = words[i];
                       words[i] = words[pos_min];
                       words[pos_min] = temp;
                   }
           }
           for(int i = 0; i < n; i++)
               {
                   cout << endl << "Word in element: " << i << " is: " << words[i] << endl;
               }
 }
//sort by alphabet
//for selection sort
void sortingcompetition::selectionSortAlph(vector<string>& words, int right)
{
    int n = right + 1;
    int pos_min;
    string temp = " ";
    //pos_min is short for position of min

        for (int i=0; i < n-1; i++)
        {
            pos_min = i;//set pos_min to the current index of array

            for (int j=i+1; j < n; j++)
            {

            if (words[j].length() == words[pos_min].length() && words[j] < words[pos_min])
                       pos_min=j;
        //pos_min will keep track of the index that min is in, this is needed when a swap happens
            }

        //if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
                if (pos_min != i)
                {
                    temp = words[i];
                    words[i] = words[pos_min];
                    words[pos_min] = temp;
                }
        }

    cout << endl << "SORTED ARRAY" << endl << endl;

    for(int i = 0; i < n; i++)
    {
        cout << endl << "Word in element: " << i << " is: " << words[i] << endl;
    }
}


void sortingcompetition::outputData(const string& outputFileName)
{
    //Open output file
    ofstream outputFile("output.txt");
    if(!outputFile)
    {
        cerr << outputFileName << " couldn't be opened" << endl;
        exit(1);
    }

    //Get size of vector
    int numWords = 0;
    numWords = wordCopy.size();

    //Output words
    for(unsigned int i = 0; i < numWords; i++)
    {
        string outputWord = wordCopy[i];
        outputFile <<  outputWord << " " << endl << endl;

    }

    outputFile.close();

}




