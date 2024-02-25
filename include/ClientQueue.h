#ifndef CLIENTQUEUE_H
#define CLIENTQUEUE_H

#include "Client.h"
class ClientQueue
{
    Client *first, *last;
public:
    int size =0;
    ClientQueue()
    {
        first =last= NULL;

    }
    bool isEmpty()
    {
        return first == NULL;
    }

    void addClient (int serviceTime, int arrival)
    {
        int id = size + 1;
        Client* newClient = new Client(id,serviceTime,arrival);
        if (isEmpty())
        {
            first = last = newClient;
        }
        else {

            last->Next = newClient;
            last = newClient;

        }
    size++;
    }

    Client* getNextClient()
    {
        if (!isEmpty())
        {
            Client* temp = first;
            first = first->Next;
            size--;
            return temp;
        }
    }
protected:

private:
};

#endif // CLIENTQUEUE_H
