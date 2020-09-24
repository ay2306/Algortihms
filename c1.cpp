#include<iostream>
using namespace std;

class s{
    int a,b;
    public: 
    s(int a, int b){
        this->a = a;
        this->b = b;
    }
    s(s &v){
        this->a = v.a;
        this->b = v.b;
    }
    int getA(){return a;}
    int getB(){return b;}
};

int main(){
    s v1(1,2);
    s v2(v1);
    cout << v2.getA() << " " << v2.getB() << endl;
    return 0;
}