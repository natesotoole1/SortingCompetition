#include "sortingcompetition.h"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
//USED THE SELECTION SORT ALGORITHM PROVIDED ONLINE @ http://cforbeginners.com/ssort.html
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

    ifstream input;
    input.open(inFile);
    if(!input)
    {
        cout << inFile << " couldn't be opened" << endl;
        return false;
     }

    string word;

    //Put inputfile into a vector
    while(input.is_open())
    {

        input >> word;


        //puts word in vector
        wordIn.push_back(word);

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
    int numWords = wordCopy.size(); //determine number of words in vector

    //Sort by length
    selectionSortLength(wordCopy, numWords - 1);

    //Sort by alphabet
    selectionSortAlphabet(wordCopy, numWords - 1);

}

//sort by length
//for selection sort
void sortingcompetition::selectionSortLength(vector<string>& words, int totalWords)
{


    int n = totalWords + 1;
       int pos_min;
       string temp;
       //pos_min is short for position of minimum

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

 }
//sort by alphabet
//for selection sort
void sortingcompetition::selectionSortAlphabet(vector<string>& words, int totalWords)
{
    int n = totalWords + 1;
    int pos_min;
    string temp;
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
    for(int i = 0; i < numWords; i++)
    {
        string outputWord = wordCopy[i];
        outputFile <<  outputWord << " " << endl << endl;

    }

    outputFile.close();

}




