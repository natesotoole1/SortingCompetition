
#include <iostream>
#include <chrono>
#include "sortingcompetition.h"

int main(int argc, char** argv)
{

    cout << endl << endl << "Inside Main" << endl << endl;

    //Number of times to run sort
    const int NUM_REPS = 10;
    unsigned int totalMilliseconds = 0;

    //Create the sorter object and load the data from a file
    sortingcompetition sorter(argv[1]);
    if (!sorter.readData())
    {
        std::cerr << "Error reading data" << std::endl;
        return 1;
    }

    for (int i = 0; i < NUM_REPS; i++)
    {
        //Load the unsorted data into our sorter object
        if (!sorter.prepareData())
        {
            std::cerr << "Error preparing data" << std::endl;
            return 1;
        }

        //Sort the data, and time the results
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        sorter.sortData();
        end = std::chrono::system_clock::now();
        unsigned int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
        totalMilliseconds += milliseconds;
        std::cout << "Sort #" << i+1 << " Time: " << milliseconds << " milliseconds" << std::endl;
    }

    //Print sorted data to a file, and print the avg.
    sorter.outputData(argv[2]);
    std::cout << "Average sorting time: " << totalMilliseconds / NUM_REPS << " milliseconds" << std::endl;
}


