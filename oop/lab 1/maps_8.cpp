#include <iostream>
#include <map>
#include <string>
using namespace std;

// problem 8

int main8()
{
    map<int, int> studs; // defining map and its variable types
    int mCount, qCount; // defining integers
    
    // counting first sequence
    cin >> mCount; // input first #'s
    
    for (int i = 0; i < mCount; i++)
    {
        int temp;
        cin >> temp;
        
        if (studs.find(temp) != studs.end())
            studs[temp]++;
        
        else
            studs.insert(make_pair(temp, 1));
    }
    
    // count other sequence
    cin >> qCount;
    
    for (int i = 0; i < qCount; i++)
    {
        int temp;
        cin >> temp;
        
        if (i < qCount - 1)
            
            if(studs.find(temp) != studs.end())
                cout << studs[temp] << " ";
        
            else
                cout << 0 << " ";
        
        else
            cout << studs[temp];
    }
}

