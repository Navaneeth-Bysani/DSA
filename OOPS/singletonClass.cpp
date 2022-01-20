#include <bits/stdc++.h>
using namespace std;

//singleton is a design pattern
//A class that can have only one object and provides a global point of access to that instance in defined as singleton class
class Singleton {
    public:
        static Singleton* getInstance();
        void setValue(int val) {
            value_ = val;
        }
        int getValue() {
            return (value_);
        }
    
    protected:
        int value_;
    private:
        static Singleton* inst_;
        //default construtor
        Singleton() : value_(0) {};
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
};

//since inst_ is a static type, it has to be initialised outside
Singleton* Singleton::inst_ = NULL;

Singleton* Singleton::getInstance() {
   if (inst_ == NULL) {
      inst_ = new Singleton();
   }
   return(inst_);
}

int main() {
    Singleton* p1 = Singleton::getInstance();
    p1->setValue(10);
    Singleton *p2 = Singleton::getInstance();
    cout << p2->getValue() << endl;
}