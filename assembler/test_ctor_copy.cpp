//  Stack class test program
//
//  Tests: copy constructor
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
      stack<int> x;

      x.push(1);
      x.push(2);
      x.push(3);
      x.push(4);
      x.push(5);
      
        // TEST
      stack<int> y(x); 

        // VERIFY
      assert(y.pop() == 5);
      assert(y.pop() == 4);
      assert(y.pop() == 3);
      
    }

    {
      //setup
      stack<char> x;

      x.push('a');
      x.push('b');
      x.push('c');
      x.push('d');

      //test
      stack<char> y(x);

      //verify
      assert(y.pop() == 'd');
      assert(y.pop() == 'c');
      assert(y.pop() == 'b');
      assert(y.pop() == 'a');
    }

    {
      //setup
      stack<double> x;

      x.push(3.9);
      x.push(5.7);
      x.push(6.45);

      //test
      stack<double> y(x);

      //verify
      assert(y.pop() == 6.45);
      assert(y.pop() == 5.7);
      assert(y.pop() == 3.9);
    }

    {
      //setup
      stack<String> x;

      x.push("jioeafbewf");
      x.push("bdueigyfrbg");
      x.push("uyuebfruycue");

      //test
      stack<String> y(x);

      //verify
      assert(y.pop() == "uyuebfruycue");
      assert(y.pop() == "bdueigyfrbg");
      assert(y.pop() ==  "jioeafbewf");
     }

     {
       //setup
       stack<String> x;

       x.push("llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll");
       x.push("grrrrrrrrrrrrrrrrrrrrrrrghhhhhhhhhhhhhhhhhhhhhhhhhuuuuuuuuuuuuuuuuuuuuuuuuuuuusssssssssssssssssssssssssssssssbbbbbbbbbbbbbbbbbbbbbbbb");

       //test
       stack<String> y(x);

       //verify
       assert(y.pop() == "grrrrrrrrrrrrrrrrrrrrrrrghhhhhhhhhhhhhhhhhhhhhhhhhuuuuuuuuuuuuuuuuuuuuuuuuuuuusssssssssssssssssssssssssssssssbbbbbbbbbbbbbbbbbbbbbbbb");
    
     }

     {
       //setup
       stack<String> x;

       x.push("");
       x.push(" ");

       //test
       stack<String> y(x);

       //verify
       assert(y.pop() == " ");
       assert(y.pop() == "");
     }

     {
       //setup
       stack<String> x;

       x.push("kopewjgiwrjgrowipjfiewofhrfuihlsfuegirgh");
       x.push("jfiohfurihwgurildhruil");
       x.push("hfirwhujrbkgvr.ebguilueialdhfbueirhgr");
       x.push("iudfegfyugfbvuftyfeghfvewrg");
       x.push("hfuiwrgfurgfysugfufey6wfugbrjbgrg");
       x.push("bfurgfyuegfhbgrjdgfyuergrhjebuihfuwihfuewfbhjbsfgetygfyejbfgjrdvhiosuhgrjbdgjrue");

       //test
       stack<String> y(x);

       //verify
       assert(y.pop() == "bfurgfyuegfhbgrjdgfyuergrhjebuihfuwihfuewfbhjbsfgetygfyejbfgjrdvhiosuhgrjbdgjrue");
       assert(y.pop() == "hfuiwrgfurgfysugfufey6wfugbrjbgrg");
       assert(y.pop() == "iudfegfyugfbvuftyfeghfvewrg");
     }

     {
       //setup
       stack<int> x;

       x.push(483925746);
       x.push(3732);
       x.push(76452483);
       x.push(99807);
       x.push(6775);

       //test
       stack<int> y(x);

       //verify
       assert(y.pop() == 6775);
       assert(y.pop() == 99807);
       assert(y.pop() == 76452483);
    }

    {
      //setup
      stack<char> x;

      x.push('l');
      x.push('g');
      x.push('t');
      x.push('f');
      x.push('f');
      x.push('f');
      x.push('f');
      x.push('f');

      //test
      stack<char> y(x);

      //verify
      assert(y.pop() == 'f');
      assert(y.pop() == 'f');
      y.pop();
      y.pop();
      y.pop();
      assert(y.pop() == 't');
      

    }

    {
      //setup
      stack<bool> x;

      x.push(true);
      x.push(false);
      x.push(true);
      x.push(true);

      //test
      stack<bool> y(x);

      //verify
      assert(y.pop() == true);
      assert(y.pop() == true);
      assert(y.pop() == false);
      assert(y.pop() == true);
    }
    	

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing copy constructor." << std::endl;
    return 0;
}

