#ifndef TELLERLIST_H
#define TELLERLIST_H
#include "Teller.h"
#include "ClientQueue.h"

class TellerList
{

public:
    int tellerNum;
    Teller *head,*tail;

    TellerList()
    {
        head = tail = NULL;
        tellerNum= 0  ;
    }

    void addTeller()
    {
        Teller *teller = new Teller(tellerNum+1);

        if(head == NULL)
        {
            head = tail = teller;
        }
        else
        {
            tail->Next = teller;
            teller->Prev = tail;
            tail = teller;
        }
        tellerNum++;
    }
    Teller* getTeller ()
    {
        Teller *current = head;
        Teller *lowest = current;

        while(current->Next != nullptr)
        {
            if ( lowest->getEndTime() > current->Next->getEndTime())
            {
                lowest = current->Next;
            }
            current = current->Next;
        }

        return lowest;
    }




private:
};

#endif // TELLERLIST_H
