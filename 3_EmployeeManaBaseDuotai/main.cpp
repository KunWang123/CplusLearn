#include<iostream>
#include"workManager.h"
#include"worker.h"
#include"employee.h"
using namespace std;

int main(){
    workManager wm;
    int choice = 0;
    // Worker * work = NULL;
    // work = new Employee(1, "zhangsan", 1);
    // work->showinfo();
    while (true)
    {
        // show meau
        wm.ShowMeau();
        cout << "Enter Your choice: " << endl;
        cin >> choice;// input char will broken
        switch (choice)
        {
        case 0:// 0. quit
            wm.ExitSystem();
            break;
        case 1:// 1. add
            break;
        case 2:// 2. show
            break;
        case 3://3. delete
            break;
        case 4://4. modify 
            break;
        case 5://5. look for
            break;
        case 6://6. sort all
            break;
        case 7://7. clear all
            break;        
        default:
            // wm.ExitSystem();
            system("cls");
            break;
        }
    }
    
    // wm.ShowMeau();
    return 0;
}