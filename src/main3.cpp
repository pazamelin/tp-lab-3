//
// Created by Yakhtin Leonid on 12.11.2019.
//

#include <bits/stdc++.h>
#include "DateTime.h"

using namespace std;

int main(){
    DateTime temp;
    cout<<temp.getToday()<<'\n';
    cout<<temp.getPast(2)<<'\n';
    cout<<temp.getFuture(2)<<'\n';
    DateTime t(1,1,2019);
    cout<<temp.getDifference(t)<<'\n';
    DateTime dt(1,11,2018);
    cout<<dt.getToday()<<'\n';
    return 0;
}
