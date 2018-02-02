#include <QCoreApplication>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
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
void vectorTest(){
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

void setTest(){
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

    if(A < tableau2D.size() && A >= 0){
         if(B < tableau2D[A].size() && B >= 0) {
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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //vectorTest();
    setTest();

    return a.exec();
}
