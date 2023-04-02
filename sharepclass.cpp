#include <iostream>
#include <memory>
#include <map>
#include <stdio.h>

struct Channel
{
    int a;
};

typedef std::map<int,Channel> Channel_map;

class Parxml
{
public:
   Channel_map ch;
public:
    void parxml(){

        ch[1] = {1};
    }
};

class ParxmlConfigur{

public:
    std::shared_ptr<Parxml> ptr1;
public:
    ParxmlConfigur(){
        ptr1 = std::make_shared<Parxml>();

    }
    ~ParxmlConfigur(){

    }
    void configure(){
        ptr1 -> parxml();
    }

};

class GPS : public ParxmlConfigur
{
private:
    std::shared_ptr<Parxml> ptr3;
    ParxmlConfigur* p;
   
public:
    GPS(ParxmlConfigur* pcon){
        p = pcon;
        ptr3 = p ->ptr1;
    }

    ~GPS(){

    }

    void gps(){
        ptr3 -> ch[1] = {3};
    }

};

class Internal: public ParxmlConfigur
{
private:
    std::shared_ptr<Parxml> ptr4;
    ParxmlConfigur* p;
public:
    Internal(ParxmlConfigur* pcon);
    ~Internal();

    void intern(){

        printf("the number is%d\n",ptr4 ->ch[1]);
    }
};

Internal::Internal(ParxmlConfigur* pcon)
{
    p = pcon;
    ptr4 = p->ptr1;
}

Internal::~Internal()
{
}

int main(){

    std::shared_ptr<ParxmlConfigur> par;
    par = std::make_shared<ParxmlConfigur>();
    par ->configure();

    std::shared_ptr<GPS> gps = std::make_shared<GPS>(par);
    gps ->gps();

    std::shared_ptr<Internal> in = std::make_shared<Internal>(par);
    in ->intern();
}






