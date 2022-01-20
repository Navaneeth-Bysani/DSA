#include <bits/stdc++.h>
using namespace std;

//Class instrument has atleast one pure virtual function, hence it is an "ABSTRACT CLASS"
//Instances of abstract classes cannot be created
//However pointers pointing to type of the abstract class can be created

class Instrument {
    public:

        virtual void play() = 0;
        // virtual function: when virtual is used, this function is overridden by the same function implementation in child class
        // virtual void play() {
        //     cout << "Playing instrument.....\n";
        // }
};

class Piano : public Instrument {
    public:
        void play() {
            cout << "Playing piano.....\n";
        }
};

class Violin : public Instrument {
    public:
        void play() {
            cout << "Playing violin.....\n";
        }
};

int main() {
    Piano p1;
    // p1.play();
    Violin v1;
    // v1.play();
    Instrument* instruments[2] = {&p1, &v1};
    for(int i = 0; i<2; i++) {
        instruments[i]->play();
    }

    
}