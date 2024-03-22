#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// problem 1

int main1()
{
    int number1, number2, rez = 0;
    cin >> number1 >> number2;

    number1 = (number1 * 2);
    number2 = (number2 * 2);

    rez = (number1 + number2);

    cout << rez;
}

// --------------------------------------------------

// problem 2

int main2()
{
    int num;
    cin >> num;

    vector<int> v(num * 2);
    for(int i = 0; i < (num*2); i++)
        cin >> v[i];

    int number1 = 0, number2 = 0, area = 0, rez = 0;
    while (v.size() != 0)
    {
        number1 = v.at(0);
        number2 = v.at(1);
    
        area = (number1 * number2);

        rez += area;

        v.erase(v.begin());
        v.erase(v.begin());  
        
    }
    cout << rez;
}

// --------------------------------------------------

// problem 3
int main3()
{
    int num;
    cin >> num;

    vector<int> v(num * 3);
    for (int i = 0; i < (num*3); i++)
        cin >> v[i];

    float n1, n2, n3, rez = 0;
    while (v.size() != 0)
    {
        n1 = v.at(0);
        n2 = v.at(1);
        n3 = v.at(2);

        float s = ((n1 + n2 + n3) / 2);
        float area2 = (s * ((s-n1)*(s-n2)*(s-n3)));
        float area3 = sqrt(area2);
        
        rez += area3;


        v.erase(v.begin());
        v.erase(v.begin());
        v.erase(v.begin());
        
    }
    printf("%.2f", rez);
}

// --------------------------------------------------

// problem 4

int main4()
{
    int num, rez = 0;
    cin >> num;

    vector<int> v(2);
    for (int i = 0; i < 2; i++)
        cin >> v[i];

    int v1 = (v.at(0));
    int v2 = (v.at(1));
    
    if (num == 1) // area
    {
        int area1 = 6*9;
        int area2 = (v1 * v2);

        rez = area1 + area2;
        cout << rez;
    }

    else // perimiters
    {
        int perm1 = (6+6+9+9);
        int perm2 = (v1+v1+v2+v2);

        rez = perm1 + perm2;
        cout << rez;
    }
   return 0; 
}

// --------------------------------------------------

// problem 5

int main5()
{
    float a, b, c;
    cin >> a >> b >> c;

    float area6 = (sqrt(243));
    float s = ((a+b+c)/2);
    float area = sqrt(s * ((s-a)*(s-b)*(s-c)));

    if (area > area6)
    {
        cout << "first\n";
    }

    else if (area6 > area)
    {
        cout << "second\n";
    }

    else if (area6 == area)
    {
        cout << "equal\n";
    } 

    cout << "destroy\n";
    cout << "destroy";
}

// --------------------------------------------------

// problem 15

int main15()
{
    float num, six = 6, rez = 0;
    cin >> num;

    int scholarships = 0;
    string current_name, best_stud;
    for (int t = 0; t < num; t++)
    {
        vector<string> v(six);
        for (int i = 0; i < six; i++){
            cin >> v[i];}

        current_name = v.at(0);
        float n1 = stoi(v.at(1));
        float n2 = stoi(v.at(2));
        float n3 = stoi(v.at(3));
        float n4 = stoi(v.at(4));
        float n5 = stoi(v.at(5));

        float sum = (n1 + n2 + n3 + n4 + n5);
        float average = (sum / 5);

        // cout << "\naverage " << average;

        if (average > 9.2){
            scholarships += 1;}

        if (average > rez)
        {
            rez = average;
            best_stud = current_name;
                if (best_stud == "Anna"){
                    scholarships += 1;}
        }
    }
    cout << scholarships << "\n";
    cout << best_stud;
}

// --------------------------------------------------

// problem 16
int main16()
{
    int num, total_students = 0;
    cin >> num;

    for (int i = 0; i < num; i ++)
    {
        float num2;
        cin >> num2;

        vector<float> v(num2);
        for (float j = 0; j < num2; j++)
            cin >> v[j];

        float sum = 0;
        for (float q = 0; q < num2; q++)
        {
            float current_score_num = v.at(q);
            
            if (current_score_num < 8)
            {
                sum = 0;
                break;
            }
       
            else if (current_score_num >= 8)
            {
                sum = (sum + current_score_num);
            }      
        }

        float score = (sum / num2);

        if (score > 8.5) {
            total_students += 1;}               
    }
    cout << total_students;
}

// --------------------------------------------------
