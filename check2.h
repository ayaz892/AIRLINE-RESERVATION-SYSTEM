#include <iostream>
using namespace std;

int checkpackage(int x)
{
	float bp;
   switch (x)
   {
   	case 1:
   		bp = 2500.00;
   		break;
   	case 2:
   		bp = 1500.00;
   		break;
   	case 3:
   		bp = 2350.00;
   		break;
   	case 4:
   		bp = 3100.00;
   		break;
   	case 5:
   		bp = 2500.00;
   		break;
   	case 6:
   		bp = 1260.00;
   		break;
   	default:
   		return 0;
   		break;
   }
   return bp;
}
