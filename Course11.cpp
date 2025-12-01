#include <iostream>
#include "clsUtil.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";
#include <iomanip>
#include "clsMainScreen.h";
#include "clsLoginScreen.h";
#include <stack>
#include <queue>
#include <map>
#include "clsDblLinkedList.h";
#include "clsMyQueue.h";
#include "clsMyStack.h";
#include "clsDynamicArray.h";
#include "clsMyQueueArr.h";
#include "clsMyStackArr.h";
#include "clsMyString.h";
#include "clsQueueLine.h";
using namespace std;



int main(){ 
   


   

     

   /* clsMainScreen::ShowMainMenue();*/
    while (true) {
        if (!clsLoginScreen::ShowLoginScreen()) {
            break;
        }
       
    }
  


    system("pause>0");

    return 0;
   


}

