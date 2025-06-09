#include <iostream>
#include <string>
#include <vector>
#include <cstring>



using namespace std;


class Source;



class Sink {
public:


    virtual void receive(Source& s) = 0;



};


class Source {


    string data;
public:


    Source(string d) : data(d) {}
    


    string getData() const {


        return data;

    }
    


    void Send(Sink& s) {


        cout << "wyslane dane: " << data << endl;


        s.receive(*this);

    }
};


class Sink1 : public Sink {



public:


    void receive(Source& s) override {



        cout << "dane 1 " << s.getData() << endl;
    }
};


class Sink2 : public Sink {



public:

    void receive(Source& s) override {

        string napis = s.getData();

        for(int i = 0; i < napis.length(); i++)
        {
            napis[i] = toupper(i);
        }


    }
};

int main() {



    Source source("hello");

    Sink1 sink1;

    Sink2 sink2;
    


    source.Send(sink1);
    source.Send(sink2);
    
    return 0;
}