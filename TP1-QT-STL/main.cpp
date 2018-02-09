#include <QCoreApplication>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

struct S_Coord {
    double d_X;
    double d_Y;
} ;

// Prototypes
vector<vector<double>> calculEuclidienne(set<S_Coord> s_d_set);

bool operator<(const S_Coord & s1, const S_Coord & s2)
{
    return s1.d_X < s2.d_X;
}
void vectorFunction(){
    vector<int>  v_i_vector;
    cout << "Enter 5 integers :"<<endl;
    int n;
    for(int i = 0; i < 5; i++){
        cin >> n;
        v_i_vector.push_back(n);
    }

    cout<<"Print numbers with [] : "<<endl;
    for(unsigned int i = 0; i < v_i_vector.size(); i++){
        cout<<v_i_vector[i]<<'\t';
    }
    cout<<endl;

    vector<int>::iterator it;

    cout<<"Print numbers with iterator : "<<endl;
    for(it = v_i_vector.begin(); it != v_i_vector.end(); it++){
        cout<<*it<<'\t';
    }
    cout<<endl;

    unsigned int index;
    cout << "Enter an index of the vector for deleting:"<<endl;
    cin >> index;

    if(index < v_i_vector.size()){
        it = v_i_vector.begin();
        it += index;
        v_i_vector.erase(it);
        cout<<"After deleting : "<<endl;
        for(unsigned int i = 0; i < v_i_vector.size(); i++){
            cout<<v_i_vector[i]<<'\t';
        }
        cout<<endl;
    } else{
        cout<<"The index is out of range !"<<endl;
    }

    cout << "Enter an index of the vector for inserting:"<<endl;
    cin >> index;
    cout << "Enter an integer for inserting:"<<endl;
    cin >> n;

    if(index <= v_i_vector.size()) {
        it = v_i_vector.begin();
        it += index;
        v_i_vector.insert(it, n);
        cout<<"After inserting : "<<endl;
        for(unsigned int i = 0; i < v_i_vector.size(); i++){
            cout<<v_i_vector[i]<<'\t';
        }
        cout<<endl;
    }else{
        cout<<"The index is out of range !"<<endl;
    }

    if(! v_i_vector.empty()){
        v_i_vector.clear();
        cout<<"Vector cleared ! Vector size = " << v_i_vector.size() <<endl;
    }
}

void setFunction(){
    set<S_Coord> s_d_set;
    set<S_Coord>::iterator it;
    bool isOK = false;

    for(int i = 0; i < 5; i++){
        S_Coord s_Coord;

        s_Coord.d_X = i;
        s_Coord.d_Y = i+1;

        if(s_d_set.empty()){
            s_d_set.insert(s_Coord);
        }
        else{
            for(it = s_d_set.begin(); it != s_d_set.end(); it++){
                if(s_Coord < *it){
                    isOK = false;
                }else{
                    isOK = true;
                }
            }

            if(isOK){
                s_d_set.insert(s_Coord);
            }
        }
    }

    cout<<"Print the set : "<<endl;
    for(it = s_d_set.begin(); it != s_d_set.end(); it++){
        cout<< '('<<(*it).d_X<<','<< (*it).d_Y<<')'<<endl;
    }
    cout << endl;

    vector<vector<double>> tableau2D;
    tableau2D = calculEuclidienne(s_d_set);

     cout << "Distances of points" << endl;

    for(vector<double> t : tableau2D)
    {
        for(double d : t)
        {
            cout << d << '\t' << '\t';
        }

        cout << endl;
    }

    int A, B;

    cout << "Enter 2 integers of positions of points : " << endl;
    cout << '\t' << "A : ";
    cin >> A;
    cout << '\t' << "B : ";
    cin >> B;

    if(A < (int)tableau2D.size() && A >= 0){
         if(B < (int)tableau2D[A].size() && B >= 0) {
             cout << "Distance of points : " << tableau2D[A][B] << endl;
         }else{
             cout << "Error ! Out of range!" << endl;
             exit(0);
         }
    }else{
        cout << "Error ! Out of range!" << endl;
        exit(0);
    }


}

vector<vector<double>> calculEuclidienne(set<S_Coord> s_d_set)
{
    vector<vector<double>> tableau2D;
    vector<double> vec;
    set<S_Coord>::iterator it1, it2;

    if(s_d_set.empty())
    {
            cout << "Tableau vide" << endl;
            exit(0);
    }

    double dis;

    // Loop 1 time data point
    for(it1 = s_d_set.begin(); it1 != s_d_set.end(); it1++) {
        // Loop 10 times to calculate the distances
        for(it2 = s_d_set.begin(); it2 != s_d_set.end(); it2++) {
            dis = sqrt(pow(((*it1).d_X - (*it2).d_X), 2) + pow(((*it1).d_Y - (*it2).d_Y), 2));
            vec.push_back(dis);
        }
        tableau2D.push_back(vec);
        vec.clear();
    }

    return tableau2D;
}

void multimapFunction()
{
    int key;
    string strKey, strValue;
    multimap<int,string> myMultiMap;
    multimap<int,string>::iterator it;


    /*
    while(true)
    {
        cout << "Enter your key or end to exit : ";
        cin >> strKey;

        if(strKey == "end")
            break;

        key = stoi(strKey);

        cout << "Enter your value : ";
        cin >> strValue;

        myMultiMap.insert(pair<int,string>(key, strValue));
    }

    cout << endl << "Display line of multimap :" << endl;

    cout << "key" << "\t" << "value" << endl;

    for(it = myMultiMap.begin(); it != myMultiMap.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    */

    /*
    while(true)
    {
        cout << "Enter key to find : ";
        cin >> strKey;
        key = stoi(strKey);

        if(key == 0)
            break;

        if(myMultiMap.find(key)->first == key)
        {
             cout << endl << myMultiMap.find(key)->second << endl;
        }else{
            cout << endl << myMultiMap.upper_bound(key)->second << endl;
        }
        // Revoir pour multiple valeurs

    }

    while(true) {
        cout << "Enter value to find : ";
        cin >> strValue;

        if(strValue == "end")
            break;


    }
    */

    // Suppression

    myMultiMap.insert(pair<int,string>(1, "add"));
    myMultiMap.insert(pair<int,string>(2, "baa"));
    myMultiMap.insert(pair<int,string>(3, "gaa"));
    myMultiMap.insert(pair<int,string>(4, "cd"));
    myMultiMap.insert(pair<int,string>(5, "edd"));
    myMultiMap.insert(pair<int,string>(6, "htht"));

    cout << "Enter value to delete : ";
    cin >> strValue;

    int sizeStr = strValue.size();
    vector<string> resultStr;
    string str;

    if(sizeStr > 1)
    {
        for(int i = 0; i < sizeStr; i++){
            str = strValue.substr(i, 1);
            resultStr.push_back(str);
        }
    }else{
        resultStr.push_back(strValue);
    }


    /*
    for(string s : resultStr){
        cout<<s<<endl;
    }
    */


    string strFind;
    vector<multimap<int,string>> vecMaps;

    for (it = myMultiMap.begin(); it != myMultiMap.end(); it++)
    {

        strFind = it->second; // strFind = value
        for(string s : resultStr)
        {
            cout<<"hello1"<<endl;
           if (strFind.find(s) == strFind.npos) // if we find
           {
               cout<<"hello2"<<endl;
               //vecMaps.push_back((*it));
               //myMultiMap.erase(it);
           }
       }
    }


    for(int i = 0; i < vecMaps.size(); i++){
       // cout<<vecMaps[i]->first<<"\t"<<vecMaps[i]->second<<endl;
    }


    /*
    for(it = myMultiMap.begin(); it != myMultiMap.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }
    */

}

/*
int main()
{
    //vectorFunction();
    //setFunction();
    multimapFunction();
}
*/
