#include <iostream>
#include <set>
using namespace std;

//problem 18

int main18()
{
    set<int> s;
    int count;
    cin >> count;
    
    for (int i = 0; i < count; i ++)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    cout << s.size();
}

// -------------------------------------------------------

// problem 19

int main19()
{
    set<int> s; // define set
    
    int c1, c2; // define variables
    int n;
    
    cin >> n; // input n
    cin >> c1; // input c1
    cin >> c2; // input c2
    
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    
    int k = 0;
    for(auto & i : s)
    {
        if (c1 <= i && i < c2)
        {
            k++;
        }
    }
    cout << k;
    
    return 0;
}

// -------------------------------------------------------

// problem 20

int main20()
{
    int column, row; // defining ints
    set<int> s; // defining set
    
    cin >> column >> row; // inputting numbers
    
    for (int i = 0; i < column; i++) // loop through columns
    {
        for (int o = 0; o < row; o++) //loop through rows
        {
            int n;
            cin >> n; // current number
            
            if (i == 0 || o == 0 || i == column - 1 || o == row - 1) // checking position
            {
                s.insert(n); // insert number into set
            }
        }
    }
    cout << s.size(); // output answer
    return 0;
}

// -------------------------------------------------------

// problem 21

int main21()
{
    string input; // define input
    cin >> input; // inputting input
    
    set<char> s; // define vector
    int count = 0;
    
    for (char ch : input) // for characters in the input...
    {
        if (!isalpha(ch)) // if characters are not alphabet
        {
            count++; // add to count
        }
        
        else if (!s.insert(ch).second)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}

// -------------------------------------------------------

// problem 22

int main22()
{
    string input; // define input
    cin >> input; // input input
    
    set<char> s; // define set
    int count = 0;
    
    for (char ch : input) // for characters in the input...
    {
       if (!isdigit(ch)) // if character is not an integer...
       {
           count++; // add to count
       }
       else if (!s.insert(ch).second) // if character is other...
       {
           count++; // add to count
       }
        
       if (count > 2) // output answer
       {
           cout << "NO";
           return 0;
       }
   }
   if (s.size() + count <= 9) // output answer
   {
       cout << "YES";
   } else
   {
       cout << "NO";
   }
   return 0;
}

// -------------------------------------------------------

// problem 23

int main23()
{
    int column, row, count = 0; // define variables
    set<int> s; // define set
    
    cin >> column >> row; // input numbers
    
    for (int c = 0; c < column; c++) // loop through columns...
    {
        for (int r = 0; r < row; r++) // ...and rows
        {
            int n;
            cin >> n; // current number on loop
            
            if (!s.insert(n).second)
            {
                count++;
            }
        }
    }
    cout << count; // output answer
    return 0;
}

// -------------------------------------------------------

// problem 24
int main24()
{
    int people, days; // define variables
    set<int> s; // define set
    
    cin >> people >> days; // input numbers
    
    for (int i = 0; i < people; i++) // loop thru
    {
        int start, fin; // define start and end days
        cin >> start >> fin; // input start and end days
        
        for (int d = start; d < fin; d++) // loop thru
        {
            s.insert(d); // insert days into set
        }
    }
    cout << ((s.size() == days) ? "YES" : "NO"); // if days == size of set print yes or no
    return 0;
}

// -------------------------------------------------------

// problem 25

int main25()
{
    int count;
    cin >> count; // input number 1
    
    set<int> s; // define set
     
    for (int i = 0; i < count; i++) // loop thru set
    {
        int num;
        cin >> num; // current number = num
    
        cout << (s.insert(num).second ? "NO\n" : "YES\n"); // if number found in set, print yes otherwise print no
        
    }
    return 0;
}

// -------------------------------------------------------

// problem 26

int main26()
{
    int count;
    cin >> count; // input number
    
    set<string> s; // define set
    
    for (int i = 0; i < count; i++) // loop thru set
    {
        int num;
        string w1, w2; // define variables
        
        cin >> num >> w1 >> w2; // input variables
        
        s.insert(w1 + w2); // insert variables into set
    }
    cout << s.size(); // output set size
    return 0;
}

// -------------------------------------------------------

// problem 27

int main()
{
    int count;
    cin >> count; // input number
    
    set<int> s; // define set
    for (int i = 0; i < count; i++) // making set
    {
        int value;
        cin >> value;
        s.insert(value);
    }
    
    cout << ((s.size() <= 3) ? "YES" : "NO");
    return 0;
}

// -------------------------------------------------------
