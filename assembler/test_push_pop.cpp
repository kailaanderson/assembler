//  Stack class test program
//
//  Tests: push and pop
//

#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "string.hpp"

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int>  x;
	int popped;

        // TEST
        x.push(10);
	x.push(20);
	x.push(30);

	popped = x.pop();

        // VERIFY
        assert(popped == 30);
     }

    {
      // setup
      stack<char> x;
      char popped;

      //test
      x.push('p');
      x.push('o');
      x.push('P');

      popped = x.pop();

      // verify
      assert(popped == 'P');
    }

    {
      //setup
      stack<bool> x;
      bool popped;

      //test
      x.push(true);
      x.push(false);

      popped = x.pop();

      //verify
      assert(popped == false);
    }

    {
      //setup
      stack<int> x;
      int pop1;
      int pop2;
      int pop3;

      //test
      x.push(3);
      x.push(4);
      x.push(1);

      pop1 = x.pop();
      pop2 = x.pop();
      pop3 = x.pop();

      //verify
      assert(pop1 == 1);
      assert(pop2 == 4);
      assert(pop3 == 3);
    }

    {
      //setup
      stack<char> x;
      char pop1;
      char pop2;

      //test
      x.push('y');
      x.push('l');
      x.push('t');
      x.push('e');

      pop1 = x.pop();
      pop2 = x.pop();

      //verify
      assert(pop1 == 'e');
      assert(pop2 == 't');
    }

    {
      //setup
      stack<int> x;
      int pop1;
      int pop2;

      //test
      x.push(4);
      x.push(78);
      x.push(65);

      pop1 = x.pop();
      pop2 = x.pop();
      pop2 = x.pop();

      //verify
      assert(pop1 == 65);
      assert(pop2 == 4);
    }

    {
      //setup
      stack<String> x;
      String pop1;

      //test
      x.push("Hello");
      x.push("World");

      pop1 = x.pop();

      //verify
      assert(pop1 == "World");
    }

    {
      //setup
      stack<String> x;
      String tempPop;
      String popped;

      //test
      x.push("Unicorns");
      x.push("do not exist");

      tempPop = x.pop();;

      x.push("do exist");
      popped = x.pop();

      //verify
      assert(tempPop == "do not exist");
      assert(popped == "do exist");
    }

    {
      //setup
      stack<String> x;
      String popped;

      //test
      x.push("");

      popped = x.pop();

      //verify
      assert(popped == "");
    }

    {
      //setup
      stack<String> x;
      String popped;

      //test
      x.push("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
      x.push("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
      x.push("ccccccccccccccccccccccccccccccccccccc");

      popped = x.pop();
      popped = x.pop();
      popped = x.pop();

      //verify
      assert(popped == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    }
   
    std::cout << "Done testing push & pop." << std::endl;
    return 0;
}
