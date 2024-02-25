#include <iostream>
#include <cstddef>
#include <iomanip>
#include <fstream>

#include "ClientQueue.h"
#include "TellerList.h"
#include "Bank.h"

void readCustomerData(ifstream& inputFile, ClientQueue *cQueue)
{
    int serviceTime, arrivalTime;
    while (inputFile >> serviceTime >> arrivalTime)
    {
        cQueue->addClient(serviceTime,arrivalTime);
    }

}
using namespace std;

int main()
{
    ifstream inputFile("Data.txt");
if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file.\n";
        return 1;
    }
    ofstream outputFile("Results.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open the output file.\n";
        return 1;
    }
ClientQueue myQueue;
readCustomerData(inputFile,&myQueue);

TellerList tellers;
tellers.addTeller();
tellers.addTeller();
tellers.addTeller();
tellers.addTeller();
Bank myBank(50);
myBank.serveClient(&myQueue,&tellers);
myBank.Display(&myQueue,&tellers,outputFile);



    return 0;
}
