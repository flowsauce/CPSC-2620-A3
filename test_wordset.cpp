//CPSC 2620 Assignment 3
//Made By: Andrew Primeau
//
//Professor: Shahadat Hossain

#include <iostream>
#include "Wordset.h"

using namespace std;

// prototype
WordSet read();

int main()
{
   cout << "Fill the first wordset: " << endl;
   WordSet ws1 = read();
   cout << endl;

   cout << "Fill the second wordset: " << endl;
   WordSet ws2 = read();
   cout << endl;

   cout << "The first wordset contains: " << endl;
   ws1.print();
   cout << "This wordset has: " << ws1.len() << " elements." << endl;
   cout << endl;

   cout << "The second wordset contains: " << endl;
   ws2.print();
   cout << "This wordset has: " << ws2.len() << " elements." << endl;
   cout << endl;

   // Default contructor
   WordSet ws3;
   ws3 = ws1 + ws2;

   cout << "The union of the first and second wordsets is: " << endl;
   ws1.print();
   cout << "+" << endl;
   ws2.print();
   cout << "=" << endl;
   ws3.print();
   cout << "This union wordset has: " << ws3.len() << " elements." << endl;
   cout << endl;

   WordSet ws4;
   ws4 = ws1 * ws2;
   cout << "The intersection of the first and second wordset is: " << endl;
   ws1.print();
   cout << "*" << endl;
   ws2.print();
   cout << "=" << endl;
   ws4.print();
   cout << "This intersection wordset has: " << ws4.len() << " element(s)." << endl;
   cout << endl;

   // Construct from vector
   vector<string> v1 { "This", "is", "my", "overloaded", "constructor", "which", "contains", "twelve", "elements", "of", "type", "string" };
   WordSet ws5(v1);

   cout << "This is a demonstration of the use of my overloaded constructor, (created from vector), which contains: " << endl;
   ws5.print();
   cout << "My overloaded constructor's wordset has: " << ws5.len() << " elements." << endl;
   cout << endl;

   cout << "This is a demonstration of our remove() function on our overloaded constructor to remove 'my' from the vector string" << endl;
   ws5.remove("my");
   ws5.print();
   cout << "This wordset now has: " << ws5.len() << " elements." << endl;
   cout << endl;

   // Using the copy constructor here to copy the elements of the intersection.
   WordSet ws6(ws4);

   cout << "Here we use the copy constructor to copy the wordset from the intersection of our first and second wordset, it contains: " << endl;
   ws6.print();
   cout << "The number of elements in the wordset made by the copy constructor has: " << ws6.len() << " element(s)." << endl;
   cout << endl;



   return 0;
}

// definition
// this is a helper function to read input given by the user. It outpouts a statement to then receive data
// it then adds these string values to our defined wordset. If there is less than 10 words in the count,
// it tells the user there was not enough words and gives a count of how many words were entered. It then
// returns the wordset
WordSet read()
{
   WordSet ws;
   int count = 0;
   string str;

   cout << "Enter at least 10 words (stop by entering a space followed by a '.'): " << endl;
   while (true)
   {
      cin >> str;
      // using an if statement to check the count of words after the '.' which is to stop the input, to ensure
      // that there is enough words
      if (str == ".")
      {
	 // if there are less than 10 cords, output that there is less than 10 words and continues the loop
	 // else it breaks the loop
	 if (count < 10)
         {
	    cout << "You must enter at least 10 words! (" << count << "/10)" << endl;
            continue;
         }
         else
            break;
      }
      // if the '.' hasn't been entered it continues to add to the vector string
      else
      {
         count++;
         ws.add(str);
      }
   }

   return ws;
}
