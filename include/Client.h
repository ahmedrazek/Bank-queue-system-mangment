#ifndef CLIENT_H
#define CLIENT_H
#include <cstddef>

class Client
{
    int tellerId,waiting,arrivalTime,serviceTime, id, leavingTime;

public:
    Client *Next;
    Client(int id,int serviceTime, int arrivalTime)
    {

        this->arrivalTime=arrivalTime;
        this->serviceTime=serviceTime;
        this->id = id;

        Next = nullptr;
    }
    int getId () {

        return this->id;

    }
    void setId (int id)
    {
        this->id = id;
    }
    int getServiceTime ()
    {
        return this->serviceTime;
    }
    void setServiceTime (int serviceTime) {

        this->serviceTime = serviceTime;
    }
    int getArrivalTime ()
    {
        return this->arrivalTime;
    }
    void setArrivalTime (int arrivalTime) {

        this->arrivalTime = arrivalTime;
    }
    int getWaitingTime ()
    {
        return this->waiting;
    }
    void setwaitingTime (int waiting) {

        this->waiting = waiting;
    }
    int getLeavingTime ()
    {
        return this->leavingTime;
    }
    void setLeavingTime (int leavingTime) {

        this->leavingTime = leavingTime;
    }
    int getTellerId ()
    {
        return this->tellerId;
    }
    void setTellerId (int tellerId) {

        this->tellerId = tellerId;
    }


protected:

private:
};

#endif // CLIENT_H
