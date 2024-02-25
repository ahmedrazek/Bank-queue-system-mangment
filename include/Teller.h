#ifndef TELLER_H
#define TELLER_H


class Teller
{
    int serviceTime,Id,endTime;
public:
    Teller *Prev,*Next;

    Teller(int id)
    {
        Prev=Next=NULL;
        Id = id;
        serviceTime = endTime = 0;
    }
    void setServiceTime (int srviceTime)
    {
        this->serviceTime = srviceTime;
    }
    void setEndTime (int endTime)
    {
        this->endTime = endTime;
    }
    void setId (int Id)
    {
        this->Id = Id;
    }
    int getServiceTime ()
    {
        return this->serviceTime;
    }
    int getEndTime ()
    {
        return this->endTime;
    }
    int getId()
    {
        return this->Id;
    }
protected:

private:
};

#endif // TELLER_H
