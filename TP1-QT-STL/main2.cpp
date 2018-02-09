#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "client.h"
#include "affichage.h"

using namespace std;
int main(){
    vector <Client> v_clients;
    v_clients.push_back(*(new Client("P1","P1","A1","C1","Com1", 1,1,1,1)));
    //v_clients.push_back(*(new Client("P2","A2")));
    v_clients.push_back(*(new Client("P1","P1","A1","C1","Com1", 1,1,1,3)));

    for_each(v_clients.begin(), v_clients.end(), Affichage(cout));
    return 0;
}
