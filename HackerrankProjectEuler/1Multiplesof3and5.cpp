#include <iostream>
using namespace std;

int main() {

    long i,t,j,n,sum,nt,nf,nb;
    scanf("%ld", &t);
    for(i=0;i<t;++i) {
        scanf("%ld", &n);
        sum=0;
        nt=n/3;
        nf=n/5;
        nb=n/15;
        if(!(n%3))
            nt--;
        if(!(n%5))
            nf--;
        if(!(n%15)&&(nb))
            nb--;
        sum=(nt*(3+3*nt))+(nf*(5+5*nf))-(nb*(15+15*nb));
        sum=sum/2;
        printf("%ld\n", sum);
    }
    return 0;
}

