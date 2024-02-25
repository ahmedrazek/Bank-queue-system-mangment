#ifndef BANK_H
#define BANK_H
#include "Client.h"
#include <iostream>
#include <cstddef>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include "ClientQueue.h"
#include "TellerList.h"
using namespace std;

class Bank
{
    Client** clientsServed;
    int size,clientNum,totalWaitingTime,totalServingTime;

public:
    Bank(int size)
    {
        this->size = size;
        clientsServed= new Client*[size];
        totalWaitingTime = 0;
        totalServingTime = 0;
        clientNum = 0;

    }
    void serveClient(ClientQueue *cQueue,TellerList *list)
    {
        clientNum++;
        clientsServed[clientNum-1] = cQueue->getNextClient();
        Teller *teller = list->getTeller();
        int tellerId = teller->getId();
        clientsServed[clientNum-1]->setTellerId(tellerId) ;
        if (teller->getEndTime() >= clientsServed[clientNum-1]->getArrivalTime() )
        {
            int waitingTime = teller->getEndTime() - clientsServed[clientNum-1]->getArrivalTime();
             int tellerEndTime = teller->getEndTime() + clientsServed[clientNum-1]->getServiceTime();
             teller->setEndTime(tellerEndTime);
            clientsServed[clientNum-1]->setLeavingTime(teller->getEndTime());
            clientsServed[clientNum-1]->setwaitingTime(waitingTime);
            int tellerserviceTime = teller->getServiceTime() + clientsServed[clientNum-1]->getServiceTime();
            teller->setServiceTime(tellerserviceTime);
        }
        else if (teller->getEndTime() < clientsServed[clientNum-1]->getArrivalTime())
        {
            clientsServed[clientNum-1]->setwaitingTime(0);
             int tellerEndTime = clientsServed[clientNum-1]->getArrivalTime() + clientsServed[clientNum-1]->getServiceTime();
             teller->setEndTime(tellerEndTime);
            clientsServed[clientNum-1]->setLeavingTime(teller->getEndTime());
            int tellerserviceTime = teller->getServiceTime() + clientsServed[clientNum-1]->getServiceTime();
            teller->setServiceTime(tellerserviceTime);
        }
        totalServingTime += clientsServed[clientNum-1]->getServiceTime();
        totalWaitingTime += clientsServed[clientNum-1]->getWaitingTime();


    }

void Display(ClientQueue *cQueue, TellerList *list,ofstream& outputFile)
{
    int size = cQueue->size;
    for (int i = 0; i < size; i++)
    {
        serveClient(cQueue, list);
    }

    cout << "+------------+---------------+---------------+------------+---------------+---------------+" << endl;
    cout << "| Client ID  | Arrival Time  | Service Time  | Teller ID  | Waiting Time  | Leaving Time  |" << endl;
    cout << "+------------+---------------+---------------+------------+---------------+---------------+" << endl;

    outputFile << "+------------+---------------+---------------+------------+---------------+---------------+" << endl;
    outputFile << "| Client ID  | Arrival Time  | Service Time  | Teller ID  | Waiting Time  | Leaving Time  |" << endl;
    outputFile << "+------------+---------------+---------------+------------+---------------+---------------+" << endl;
    for (int i = 0; i < clientNum; i++)
    {
        Client *client = clientsServed[i];
        cout << "| " << setw(10) << left << client->getId() << " | "
             << setw(13) << left << client->getArrivalTime() << " | "
             << setw(13) << left << client->getServiceTime() << " | "
             << setw(10) << left << client->getTellerId() << " | "
             << setw(13) << left << client->getWaitingTime() << " | "
             << setw(13) << left << client->getLeavingTime() << " |" << endl;
        cout << "+------------+---------------+---------------+------------+---------------+---------------+" << endl;

        outputFile << "| " << setw(10) << left << client->getId() << " | "
             << setw(13) << left << client->getArrivalTime() << " | "
             << setw(13) << left << client->getServiceTime() << " | "
             << setw(10) << left << client->getTellerId() << " | "
             << setw(13) << left << client->getWaitingTime() << " | "
             << setw(13) << left << client->getLeavingTime() << " |" << endl;
        outputFile << "+------------+---------------+---------------+------------+---------------+---------------+" << endl;
    }

    cout << "+------------+-------------------+----------------------+" << endl;
    cout << "| Teller ID  |   Service Time    |   Utilization Rate   |" << endl;
    cout << "+------------+-------------------+----------------------+" << endl;

    outputFile << "+------------+-------------------+----------------------+" << endl;
    outputFile << "| Teller ID  |   Service Time    |   Utilization Rate   |" << endl;
    outputFile << "+------------+-------------------+----------------------+" << endl;
    Teller *current = list->head;
    for (int i = 0; i < list->tellerNum; i++)
    {
        double utilizationRate = (static_cast<double>(current->getServiceTime()) / totalServingTime) * 100;
        cout << "| " << setw(10) << left << current->getId() << " | "
             << setw(17) << left << current->getServiceTime() << " | "
             << setw(22) << fixed << setprecision(2) << utilizationRate << "%" << " |" << endl;
        cout << "+------------+-------------------+----------------------+" << endl;

        outputFile << "| " << setw(10) << left << current->getId() << " | "
             << setw(17) << left << current->getServiceTime() << " | "
             << setw(22) << fixed << setprecision(2) << utilizationRate << "%" << " |" << endl;
        outputFile << "+------------+-------------------+----------------------+" << endl;
        current = current->Next;
    }

    cout << "Average Waiting Time: " << totalWaitingTime / clientNum << " minutes" << endl;
    cout << "Average Serving Time: " << totalServingTime / clientNum << " minutes" << endl;

    outputFile << "Average Waiting Time: " << totalWaitingTime / clientNum << " minutes" << endl;
    outputFile << "Average Serving Time: " << totalServingTime / clientNum << " minutes" << endl;
}

protected:

private:
};

#endif // BANK_H
