
#include <iostream>
#include <vector>
#include <string>
using namespace std;


// problem 1- vectors
int main1()
{
    // create two variables
    int count1, count2;
    cin >> count1 >> count2;
    
    vector<int> v(count1);
    
    // filling vector, cycle 1
    for (int i = 0; i < count1; i++)
        cin >> v[i];
    
    // filling vector, cycle 2; remove index
    for (int i = 0; i < count2; i++)
    {
        int removeIndex;
        cin >> removeIndex;
        v.erase(v.begin() + removeIndex - 1);
    }
    
    // print all elements
    for (int i = 0; i < v.size() - 1; i++)
        cout << v[i] << " ";
    
    cout << *v.rbegin();
    
    return 0;
}

// -------------------------------------------------------

// problem 2
int main2()
{
    int num1, num2, num, sum; // defining variables
    cin >> num1 >> num2; // input first line of numbers

    vector<int> v(num1); // defining original vector
    vector<int> sumsum;

    for (int i = 0; i < num1; i++) // inputting original vector
        cin >> v[i];

    // loop dependent on functions
    for (int i = 0; i < num2; i++)
    {
        string com; // defining commands
        cin >> com; // input command

        if (com == "sum") // if command = sum, do sum function
        {
            sum = 0;
            cin >> num; // input number

            
            for (int i = 0; i < num; i++) // sum function
                sum += v[i];
            
            
            cout << sum << '\n'; // PRINT SUM OUTSIDE FUNCTION
        }
        
        else if (com == "pap") // if command = pap, insert 2m at [n]
            {
                cin >> num; // input number
                v.insert(v.begin() + num, num * 2);
            }

        else if (com == "del") // if command = del, delete nth number
        {
            cin >> num; // input number place
            v.erase(v.begin() + num - 1);
        }
    }
    return 0;
}

// -------------------------------------------------------

// problem 3
int main3()
{
    // defining variables
    int count1;
    cin >> count1; // entering how many numbers in vector
    
    vector<int> v(count1); // defining vector
    vector<int> positive; // defining lists
    vector<int> negative;

    // making vector
    for (int i = 0; i < count1; i++)
        cin >> v[i]; // vector input
    
    for (int i = 0; i < count1; i++)
    // if positive number; add to list
        if (v.at(i) > 0)
        {
            positive.push_back(v.at(i));
        }
    
    // if negative number add to negative list
        else
        {
            negative.push_back(v.at(i));
        }

    // print and combine vectors
    // print first number
    // then space and rest of numbers so no space at end
    positive.insert(positive.end(), negative.begin(), negative.end());

    cout << positive[0];

    for (int i = 1; i < positive.size(); i++){
        cout << " " << positive[i];
    }
    return 0;
}

// -------------------------------------------------------

// problem 4
int main4()
{
    int p_num = 0, j_num = 0, reps = 0;
    cin >> p_num >> j_num; // input how many starting cards for players
    
    vector<int> peter_cards(p_num); // defining peter vector
    for (int i = 0; i < p_num; i++) // making peter vector
        cin >> peter_cards[i];
    
    vector<int> jhon_cards(j_num); // defining jhon vector
    for (int i = 0; i < j_num; i++) // making jhon vector
        cin >> jhon_cards[i];
    
    while (true) // loop
    {
        int pcard1 = peter_cards.at(0); // defining first cards
        int jcard1 = jhon_cards.at(0);
        
        peter_cards.erase(peter_cards.begin()); // erasing first cards
        jhon_cards.erase(jhon_cards.begin());
        
        // if peters card wins...
        if (pcard1 > jcard1)
        {
            peter_cards.push_back(jcard1); // take opponent card- end of deck
            peter_cards.push_back(pcard1); // take own card- end of deck
        }
        // if jhons card wins
        else if (jcard1 > pcard1)
        {
            jhon_cards.push_back(pcard1); // take opponent card- end of deck
            jhon_cards.push_back(jcard1); // take own card- end of deck
        }
        else // if it ties...
        {
            cout << "Both losers";
            return 0;
        }
        
        reps += 1; // adding cycles each time
        
        // output jhon losing
        if (peter_cards.empty())
        {
            cout << reps << " Jhon";
            return 0;
        }
        // output peter losing
        else if (jhon_cards.empty())
        {
            cout << reps << " Peter";
            return 0;
        }
        // if game goes forever, both lose
        else if (reps > 1000)
        {
            cout << "Both losers";
            return 0;
        }
    }
    return 0;
}


// -------------------------------------------------------

// problem 5

int main5()
{
    int count;
    cin >> count; // input number
    
    vector<int> one(count);
    for (int i = 0; i < count; i++)
        one[i] = i + 1;
    
    vector<int> two;
    
    while (true)
    {
        two.push_back(one.at(0)); //put card from first and put into second
        one.erase(one.begin()); // erase from one
        
        if (one.empty()) // if one is empty...
            
        { // output vector
            cout << two[0];
            for (int i = 1; i < two.size(); i++)
            {
                cout << "," << two[i];
            }
            return 0;
        }
        one.push_back(one.at(0)); // put first element to back
        one.erase(one.begin()); // erase element
        
        if (one.empty())
        {
            cout << two[0];
            for (int i = 1; i < two.size(); i++)
            {
                cout << "," << two[i];
            }
            return 0;
        }
    }
    return 0;
}

// -------------------------------------------------------

// problem 29

int main()
{
    int dish_num, ppl_num, rez = 0;
    cin >> dish_num; // input number of dishes
    
    vector<string> dishes(dish_num); // defining and making dishes vector
    for (int i = 0; i < dish_num; i++)
        cin >> dishes[i];
        
    cin >> ppl_num; // input number of names
    
    vector<string> people(ppl_num*2); // defining and making names / dishes vector
    for (int i = 0; i < ppl_num*2; i++)
        cin >> people[i];
    
    
    while (people.size() != 0) // while people vector isn't empty...
    {
        people.erase(people.begin()); // delete name
        
        // if wanted dish is found in list...
        if (std::find(dishes.begin(), dishes.end(), people[0]) != dishes.end())
        {
            int count = std::count(dishes.begin(), dishes.end(), people[0]); // counting how many times in vector
            
            dishes.erase(std::remove(dishes.begin(), dishes.end(), people[0]), dishes.end()); // erase dish list
            
            if (count > 1) // if dish is repeated...
            {
                for (int i = 0; i < count-1; i++) // add item back to list
                {
                    dishes.push_back(people[0]);
                }
            }
            
            people.erase(people.begin()); // delete dish from people
            rez ++; // keeping count
        }
        
        else
        {
            people.erase(people.begin()); // otherwise delete person dish from people
        }
    }
    cout << rez;
}

// -------------------------------------------------------
