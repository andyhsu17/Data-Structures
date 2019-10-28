#include "PriorityQueue.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
// int Menu()
// {
//   int choice;
//   cout << "======Main Menu======" << endl;
//   cout << "1. Get Patient Information from File" << endl;
//   cout << "2. Add Patient to Priority Queue" << endl;
//   cout << "3. Show Next Patient" << endl;
//   cout << "4. Treat Next Patient" << endl;
//   cout << "5. Treat Entire Queue" << endl;
//   cout << "6. Quit" << endl;
//
//   cin >> choice;
//   return choice;
// }



// int main(int argc, char *argv[])
// {
//   int totalTreatmentTime = 0;
//   char *size = argv[1];
//   int nsize = atoi(size);
//   int choice;
//   PriorityQueue bet(nsize);
//
//   bool quit = false;
//   while(quit == false)
//   {
//   choice = Menu();
//   switch(choice)
//   {
//
//     // input patients from file
//   case 1: {
//       ifstream myfile("patientFile.txt");
//       string line;
//       string name;
//       string severity;
//       string time;
//
//       while(getline(myfile, line))
//       {
//         if(bet.isFull())
//         {
//           cout << "Priority Queue full. Send Patient to another hospital." << endl;;
//           break;
//         }
//         stringstream ss;
//         ss >> name;
//         ss >> severity;
//         ss >> time;
//         int nseverity = stoi(severity);
//         int ntime = stoi(time);
//         bet.enqueue(name, nseverity, ntime);
//       }
//         break;
// }
//     // add new patient to priority queue
//      case 2:
//      {
//      if(bet.isFull())
//      {
//        cout << "Priority Queue full. Send Patient to another hospital." << endl;
//        break;
//      }
//      string patientName;
//      int patientInjurySeverity;
//      int patientTreatmentTime;
//      cout << "Enter Patient Name:" << endl;
//      cin >> patientName;
//      cout << "Enter Injury Severity:" << endl;
//      cin >> patientInjurySeverity;
//      cout << "Enter Treatment Time:" << endl;
//      cin >> patientTreatmentTime;
//      bet.enqueue(patientName, patientInjurySeverity, patientTreatmentTime);
//      break;
//    }
//
//    // show next patient
//      case 3:
//      {
//        if(bet.isEmpty())
//        {
//          cout << "Queue empty." << endl;
//          break;
//        }
//        else
//        {
//        string patientName = bet.peekName();
//        int patientInjurySeverity = bet.peekInjurySeverity();
//        int patientTreatmentTime = bet.peekTreatmentTime();
//        cout << "Patient Name: " << patientName << endl;
//        cout << "Injury Severity: " << patientInjurySeverity << endl;
//        cout << "Treatment Time: " << patientTreatmentTime << endl;
//        }
//
//      break;
//      }
//
//      // treat first patient
//      case 4:
//      {
//        if(bet.isEmpty())
//        {
//          cout << "Queue empty." << endl;
//          break;
//        }
//        string patientName = bet.peekName();
//        int patientTreatmentTime = bet.peekTreatmentTime();
//        totalTreatmentTime += patientTreatmentTime;
//        cout << "Patient Name: " << patientName
//        << " - Total Time Treating Patients: " <<
//        totalTreatmentTime << endl;
//        bet.dequeue();
//
//        break;
//      }
//
//      // treat all patients in queue
//      case 5:
//      {
//        if(bet.isEmpty())
//        {
//          cout << "Queue empty." << endl;
//          break;
//        }
//
//        while(1)
//        {
//        if(bet.isEmpty())
//        {
//        cout << "Queue empty." << endl;
//        break;
//        }
//        string patientName = bet.peekName();
//        int patientTreatmentTime = bet.peekTreatmentTime();
//        totalTreatmentTime += patientTreatmentTime;
//        cout << "Patient Name: " << patientName
//        << " - Total Time Treating Patients: " <<
//        totalTreatmentTime << endl;
//        bet.dequeue();
//
//
//        }
//      break;
//    }
//      case 6:
//      {
//        cout << "Goodbye!" << endl;
//        quit = true;
//        break;
//      }
// }
//
//
// }
//
//
//
//
//
//
//
//
// }


int main()
{

  PriorityQueue bet(5);


  bet.enqueue("andy", 0, 5);
  bet.enqueue("zach", 1, 3);
   bet.enqueue("remy", 2, 2);
  bet.enqueue("blake", 3, 2);
  bet.enqueue("pussy", 4, 0);

  string name = bet.peekName();
  cout << "patient is " << name << endl;

  bet.dequeue();
  name = bet.peekName();
  cout << "new patient is " << name << endl;

  bet.dequeue();
  name = bet.peekName();
  cout << "new patient is " << name << endl;

  bet.dequeue();
  if(bet.isEmpty())
  {
    cout << "queue is empty" << endl;
  }
  else
  {
  name = bet.peekName();
  cout << "new patient is " << name << endl;
}
  //
  bet.dequeue();
  name = bet.peekName();
  cout << "new patient is " << name << endl;

  bet.dequeue();
  name = bet.peekName();
  cout << "new patient is " << name << endl;


}
