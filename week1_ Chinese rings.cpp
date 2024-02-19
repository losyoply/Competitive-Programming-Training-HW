#include<iostream>
using namespace std;
class Ring
{
public:

       Ring(int n):nRingNum(n){}
       void UpRing(int n);
       void DownRing(int n);
       void startDownRing();
private:

       int nRingNum;
};


void Ring::UpRing(int n)  
{
       if(n>1) UpRing(n-1);
       if(n>2) DownRing(n-2);
       cout << "Move ring " << n <<" in" << endl;
       if(n>2) UpRing(n-2);
}


void Ring::DownRing(int n)
{
       if(n>2) DownRing(n-2);
       cout <<"Move ring " << n <<" out" <<  endl;
       if(n>2) UpRing(n-2);
       if(n>1) DownRing(n-1);
}


void Ring::startDownRing()
{
       DownRing(nRingNum);
}


int main()                  
{
    int n;
    cin>>n;
       Ring ring(n);
       ring.startDownRing();
       return 0;

}
