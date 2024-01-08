//  Stack class test program
//
//  Tests: assignment overload
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
        stack<int>  x;
	stack<int> y;

	x.push(9);
	x.push(9);
	x.push(8);
	x.push(8);
	x.push(5);

        // TEST
        y = x;

        // VERIFY
        assert(y.pop() == 5);
	assert(y.pop() == 8);
	assert(y.pop() == 8);
	assert(y.pop() == 9);
	assert(y.pop() == 9);
     }

    {
      //setup
      stack<char> x;
      stack<char> y;

      x.push('l');
      x.push('l');
      x.push('e');
      x.push('g');

      //test
      y = x;

      //verify
      assert(y.pop() == 'g');
      assert(y.pop() == 'e');
      assert(y.pop() == 'l');
      assert(y.pop() == 'l');
    }

    {
      //setup
      stack<bool> x;
      stack<bool> y;

      x.push(true);
      x.push(false);
      x.push(false);
      x.push(false);

      //test
      y = x;

      //verify
      assert(y.pop() == false);
      assert(y.pop() == false);
      assert(y.pop() == false);
      assert(y.pop() == true);
    }

    {
      //setup
      stack<double> x;
      stack<double> y;

      x.push(43.8);
      x.push(78.0);
      x.push(753.9);
      x.push(1.0);
      x.push(76.3);

      //test
      y = x;

      //verify
      assert(y.pop() == 76.3);
      assert(y.pop() == 1.0);
    }

    {
      //setup
      stack<String> x;
      stack<String> y;

      x.push("hhhhhhhhhhhhhh");
      x.push("iiiiiiiiiiiiiiiiii");
      x.push("jjjjjjjjjjjjjjjj");
      x.push("kkkkkkkkkkkkkkk");

      //test
      y = x;

      //verify
      assert(y.pop() == "kkkkkkkkkkkkkkk");
      assert(y.pop() == "jjjjjjjjjjjjjjjj");
    }

    {
      //setup
      stack<String> x;
      stack<String> y;

      x.push("");
      x.push(" ");
      x.push("feguwi");
      x.push("dbueibgfg");
      x.push("yuegfew");

      //test
      y = x;

      //verify
      assert(y.pop() == "yuegfew");
      assert(y.pop() == "dbueibgfg");
      assert(y.pop() == "feguwi");
      assert(y.pop() == " ");
      assert(y.pop() == "");
    }

    {
      //setup
      stack<String> x;
      stack<String> y;

      x.push("bufirw");
      String pop = x.pop();

      //test
      y = x;

      //verify
      assert(y.empty());
    }

    {
      //setup
      stack<String> x;
      stack<String> y;

      x.push("jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj");
      x.push("jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll");

      //test
      y = x;

      //verify
      y.pop();
      assert (y.pop() == "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj");
      
    }

    {
      //setup
      stack<String> x;
      stack<String> y;

      x.push("gwewfirongs");

      //test
      y = x;

      //verify
      assert(y.pop() == "gwewfirongs");
    }

    {
      //setup
      stack<String> x;
      stack<String> y;
      stack<String> z;

      x.push("feiwobfeubgugre");
      x.push("huifrwhfbjvhaopakfe");
      x.push("buiywgbfrsovpnkrs");

      //test
      z = y = x;

      //verify
      assert(y.pop() == "buiywgbfrsovpnkrs");
      assert(z.pop() == "buiywgbfrsovpnkrs");
    }

    // ADD ADDITIONAL TESTS AS NECESSARY  
    std::cout << "Done testing assignment overload." << std::endl;
    return 0;
}


