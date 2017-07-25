#include <iostream>
#include <iomanip>
#include <set>

using std::cout; using std::cin; using std::endl;
using std::set;
using std::right; using std::setw;


/*                                                                      sieve()

   Paramaters:
      set<int>& s - the container being used to store the number values
      int n - 'n' represents the value of total elements in the set container.

   Objectives:
      Applies the "sieve of eratosthenes" algorithm to remove all nonprime numbers
      from an integer set. It does this by first initializing and filling the 's'
      set container with numbers via "s.insert(p)". It then goes through and takes
      out any of the values that are multiples until only prime numbers in range
      of 2 to n remain.

   Returns:
      void - the function returns no value.

******************************************************************************/
void sieve( set<int>& s, int n){

   int i, p = 2, set_size = n;

   while (p < set_size){ //fills the set container with values
      s.insert(p);
      p++;
   }

   for(int m = 2; m * m <= set_size; m++){ //processes multiples
      i = 2 * m;
      while(i <= set_size){
         s.erase(i);
         i += m;
      }
   }
}



/*                                                               print_primes()

   Paramaters:
     const set<int>& s - 's' is a "set" container that will be containing all
     the values processed from sieve(), which contain prime numbers.

   Objectives:
     is used to print the prime numbers processeed through the set container

   Returns:
     void - the function returns no value.

******************************************************************************/
void print_primes( const set<int>& s){

    int NO_ITEMS = 8, ITEM_W = 6, i = 0;

    for(set<int>::iterator it = s.begin(); it!=s.end(); ++it){
       i++;
       cout << right << setw(ITEM_W) << *it;
       if (i % NO_ITEMS == 0)
          cout << endl;
    }
    cout << endl;
}



int main(){
    set<int> s;
    sieve(s, 500);
    print_primes(s);
    return 0;
}



