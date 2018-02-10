#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "client.h"
#include "affichage.h"
#include "sortRes.h"

using namespace std;

//vector<int> op(vector<int> vec)
//{
//    sort(vec.begin(), vec.end());
//    return vec;
//}

Client op(Client c)
{
    // pourquoi ca marche pas ?
    // sort(c.getIdRes().begin(),c.getIdRes().end());

    vector<int> intVec = c.getIdRes();
    sort(intVec.begin(), intVec.end());
    c.setIdRes(intVec);

    return c;
}
int main(){
    vector <Client> v_clients;
    vector <int> v_c1;
    v_c1.push_back(1);
    v_c1.push_back(2);
    v_c1.push_back(3);
    v_c1.push_back(3);
    v_c1.push_back(7);
    v_c1.push_back(4);
    v_c1.push_back(9);

    vector <int> v_c2;
    v_c2.push_back(5);
    v_c2.push_back(7);
    v_c2.push_back(10);
    v_c2.push_back(17);
    v_c2.push_back(32);
    v_c2.push_back(8);
    v_c2.push_back(9);

    v_clients.push_back(*(new Client("P1","P1","A1","C1","Com1", 1,1,1,1, v_c1)));
    v_clients.push_back(*(new Client("P1","P1","A1","C1","Com1", 1,1,1,3, v_c2)));

    for_each(v_clients.begin(), v_clients.end(), Affichage(cout));
    transform(v_clients.begin(), v_clients.end(), v_clients.begin(), op);

    //transform((v_clients.begin())->getIdRes().begin(), (v_clients.end())->getIdRes().end(), (v_clients.begin())->getIdRes().begin(), op);

    for(int i = 0; i < v_clients.size(); i++)
    {
        for(int j = 0; j < v_clients[i].getIdRes().size(); j ++)
        {
            cout << v_clients[i].getIdRes()[j]<<'\t';
        }
        cout << endl;
    }
    return 0;
}
