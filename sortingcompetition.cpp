#include "sortingcompetition.h"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

using namespace std;


SortingCompetition::SortingCompetition(const string& inputFileName){
    inFile = inputFileName;

}

void SortingCompetition::setFileName(const string& inputFileName){
    inFile = inputFileName;

}
//reads the words from the file and stores it in a vector
/*
bool SortingCompetition::readData()
{

    ifstream input;
    input.open(inFile);
    if(!input)
    {
        cout << inFile << " couldn't be opened" << endl;
        return false;
    }

    char* temp = new char[50];
    char* word;
    long length;

    //Put inputfile into a vector
    while(input.is_open())
    {

        input >> temp;

        //Make a length prefixed string
        char lengthC[2];
        length = strlen(temp);
        word = new char[length + 1];
        lengthC[0] = length;
        strcpy(word, lengthC);
        strncat(word, temp, length);

        //Push word to wordIn char**
        wordIn.push_back(word);
        delete temp;
        temp = new char[50];

        //close file if at end
        if(input.eof())
        {
            delete temp;
            input.close();
        }

    }
    return true;

}
*/


//for selection sort
//reads the words from the file and stores it in a vector
bool SortingCompetition::readData()
{

    ifstream input;
    input.open(inFile);
    if(!input)
    {
        cout << inFile << " couldn't be opened" << endl;
        return false;
    }

    char* temp = new char[50];
    char* word;


    //Put inputfile into a vector
    while(input.is_open())
    {

        input >> temp;

        //Push word to wordIn char**
        wordIn.push_back(word);
        delete temp;
        temp = new char[50];

        //close file if at end
        if(input.eof())
        {
            delete temp;
            input.close();
        }

    }
    return true;

}


//Create a copy of the words so the same set can be tested multiple times and averaged
/*
bool SortingCompetition::prepareData()
{
    wordCopy.erase(wordCopy.begin(), wordCopy.end());
    wordCopy = wordIn;
    return true;

}
*/

//Create a copy of the words so the same set can be tested multiple times and averaged
//for selection sort
bool SortingCompetition::prepareData()
{
    wordCopy.erase(wordCopy.begin(), wordCopy.end());
    wordCopy = wordIn;
    return true;

}

//Sorts the data
/*
void SortingCompetition::sortData()
{
    int numWords = wordCopy.size();

    //Sort by length
    quickSortLen(wordCopy, 0, numWords - 1);

    //Sort by Alpha
    vector<char*>::iterator start = wordCopy.begin(), end;
    for(int i = 0; i < numWords; i++)
    {
        if(int(wordCopy[i][0]) > int(*start[0]))
        {
            end = wordCopy.begin() + (i - 1);
            quickSortAlph(wordCopy, start, end);
            start = end + 1;
        }
    }



}
*/

//Sorts the data
//for selection sort
void SortingCompetition::sortData()
{
    int numWords = wordCopy.size();

    //Sort by length
    quickSortLen(wordCopy, 0, numWords - 1);

    //Sort by Alpha
    vector<char*>::iterator start = wordCopy.begin(), end;
    for(int i = 0; i < numWords; i++)
    {
        if(int(wordCopy[i][0]) > int(*start[0]))
        {
            end = wordCopy.begin() + (i - 1);
            quickSortAlph(wordCopy, start, end);
            start = end + 1;
        }
    }



}

void SortingCompetition::outputData(const string& outputFileName)
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
    for(unsigned int i = 0; i < numWords; i++){
        wordCopy[i][0] = ' ';
        char* outputWord = strtok(wordCopy[i], " ");
        outputFile <<  outputWord << endl;

    }

    outputFile.close();

}

/*
void SortingCompetition::quickSortLen(vector<char*>& words, int left, int right){
    int i, j, mid, unMid, ovMid;
    char* pivot;

    i = left;
    j = right;
    mid = left + (right-left) / 2;

    if(right - left < 20){
        insertSortLen(words, left, right + 1);
        return;
    }

    //3 pivot

    if(int(words[right][0]) < int(words[left][0])){
        swap(words[right], words[left]);
    }
    if(int(words[mid][0]) < int(words[left][0])){
        swap(words[mid], words[left]);
    }
    if(int(words[right][0]) < int(words[mid][0])){
        swap(words[right], words[mid]);
    }

    pivot = words[mid];
    while (i<=j){
        //check start
        while(int(words[i][0]) < int(pivot[0])){
            i++;
        }
        while(int(words[j][0]) > int(pivot[0])){
            j--;
        }
        if(i <= j){
            swap(words[i],words[j]);
            i++;
            j--;
        }
    }
    //recursion
    if(j > left){
        quickSortLen(words, left, j);
    }

    if(i < right){
        quickSortLen(words, i, right);
    }

}
*/


//sort by length
//for selection sort
void SortingCompetition::selectionSortLen(vector<char*>& words, int left, int right)
{
    int n = right + 1;
    int pos_min, temp;
    //pos_min is short for position of min
        int pos_min,temp;

        for (int i=0; i < n-1; i++)
        {
            pos_min = i;//set pos_min to the current index of array

            for (int j=i+1; j < n; j++)
            {

            if (strlen(words[j]) < strlen(words[pos_min]))
                       pos_min=j;
        //pos_min will keep track of the index that min is in, this is needed when a swap happens
            }

        //if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
                if (pos_min != i)
                {
                    strcpy(temp, words[i]);
                    strcpy(words[i], words[pos_min]);
                    strcpy(words[pos_min], temp);
                }
        }

/*

    int i, j, mid, unMid, ovMid;
    char* pivot;

    i = left;
    j = right;
    mid = left + (right-left) / 2;

    if(right - left < 20){
        insertSortLen(words, left, right + 1);
        return;
    }

    //3 pivot

    if(int(words[right][0]) < int(words[left][0])){
        swap(words[right], words[left]);
    }
    if(int(words[mid][0]) < int(words[left][0])){
        swap(words[mid], words[left]);
    }
    if(int(words[right][0]) < int(words[mid][0])){
        swap(words[right], words[mid]);
    }

    pivot = words[mid];
    while (i<=j){
        //check start
        while(int(words[i][0]) < int(pivot[0])){
            i++;
        }
        while(int(words[j][0]) > int(pivot[0])){
            j--;
        }
        if(i <= j){
            swap(words[i],words[j]);
            i++;
            j--;
        }
    }
    //recursion
    if(j > left){
        quickSortLen(words, left, j);
    }

    if(i < right){
        quickSortLen(words, i, right);
    }
*/
}
//quick sort alphabetically
void SortingCompetition::quickSortAlph(vector<char*>& words, vector<char*>::iterator left, vector<char*>::iterator right){
    vector<char*>::iterator i, j, mid;
    char* pivot;
    //checks for 2nd recursive call
    while(left< right){

        if ((right - left) < 15){
            insertSortAlph(words, left, right + 1);
        }
        i = left;
        j = right;
        mid = left + (right - left) / 2;

        if(strcmp(*right, *left) < 0){
            swap(*right, *left);
        }

        if(strcmp(*mid, *left) < 0){
            swap(*mid, *left);
        }

        if(strcmp(*right, *mid) < 0){
            swap(*right, *mid);
        }

        pivot = *mid;
        bool check = true;
        while (check == true){
            while (i <= j && strcmp(*i, pivot) < 0){
                 i++;
            }
            while (i <= j && strcmp(*j, pivot) > 0){
                j--;
            }

            //check
            if(i > j){
                check = false;
            }

            swap(*i, *j);

            if (mid ==j){
                mid = i;
            }

            i++;
            j--;

        }
        *mid = *j;
        *j = pivot;
        j--;

        //recurse
        if((j - left) < (right - i)){
            quickSortAlph(words, left, j);
            left = i;
        }
        else{
            quickSortAlph(words, i, right);
            right = j;
        }

    }
}

void SortingCompetition::insertSortLen(vector<char*>& words, int left, int right){
    char* temp;
    int j;

    for (int i = left + 1; i < right; i ++ ){
        temp = words[i];
        j = i - 1;

        while (j >= 0 && int(temp[0]) < int(words[j][0])){
            words[j + 1] = words[j];
            j--;
        }
        words[j+1] = temp;
    }
}

void SortingCompetition::insertSortAlph(vector<char*>& words, vector<char*>::iterator left, vector<char*>::iterator right){
    char* temp1;
    vector<char*>::iterator j;
    vector<char*>::iterator temp2;

    for(vector<char*>::iterator i = left + 1; i < right; i++ ){
        temp1 = *i;
        j = i - 1;
        temp2 = j + 1;
        while( j>= words.begin() && strcmp(temp1, *j) < 0){
            *temp2 = *j;
            j--;
            temp2 = j + 1;
        }
        *temp2 = temp1;
    }
}



/*
void quickSort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];


      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };


      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}
*/
/*
void BubbleSort(apvector <int> &num)
{
      int i, j, flag = 1;    // set flag to 1 to start first pass
      int temp;             // holding variable
      int numLength = num.length( );
      for(i = 1; (i <= numLength) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (numLength -1); j++)
         {
               if (num[j+1] > num[j])      // ascending order simply changes to <
              {
                    temp = num[j];             // swap elements
                    num[j] = num[j+1];
                    num[j+1] = temp;
                    flag = 1;               // indicates that a swap occurred.
               }
          }
     }
     return;   //arrays are passed to functions by address; nothing is returned
}
*/


