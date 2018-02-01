#include <QCoreApplication>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include<set>
using namespace std;

struct S_Coord {
    double d_X;
    double d_Y;
} ;

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
    set<S_Coord>::iterator it = s_d_set.begin();
    bool isOK = false;

    for(int i = 0; i < 10; i++){
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
    cout<<endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //vectorTest();
    setTest();

    return a.exec();
}
