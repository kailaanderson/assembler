//  Stack class test program
//
//  Tests: Default Constructor
//

#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "string.hpp"

//===========================================================================
int main(){
  
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> x;

        // VERIFY
        assert(x.empty());
    }

    {
      //setup

      //test
      stack<char> x;

      //verify
      assert(x.empty());
    }

    {
      //setup

      //test
      stack<double> x;

      //verify
      assert(x.empty());
     
    }

    {
      //setup

      //test
      stack<bool> x;

      //verify
      assert(x.empty());
     
    }
    
    {
      //setup

      //test
      stack<String> x;

      //verify
      assert(x.empty());      
    }


    // ADD ADDITIONAL TESTS AS NECESSARY

    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}
