#include "head.h"

vector<student> students;

int main()
{int choose;
load_from_file(students);
  do {
      cout<<"-------------------------------------------------------------------------------------------------------------"<<endl<<
      "choose number from 1 to 9"<<endl<<"1) add student "<<endl<<"2) display all students"<<endl<<"3) search for student"<<endl<<"4) update student "<<endl<<"5) delete student"<<endl<<"6) show top performing students"<<endl<<"7) save to file "<<endl<<"8) load from file"<<endl<<"9) exit program"<<endl;

      cin>>choose;
      switch (choose)
      {case (1):
          add_student(students);
          break;
       case (2):
           display(students) ;
           break;
       case (3):
            Search(students) ;
           break;
       case (4):
           update(students) ;
           break;
       case (5):
          delete_student(students) ;
           break;
       case (6):
           show_top_performing_students(students) ;
           break;
       case (7):
           save_to_file(students);
           break;
       case(8):
        load_from_file(students);
        break;
        case(9):
            { cout<<"do you want to save ? (press 1 if yes , -1 if no)"<<endl;
            int k;
            cin>>k;
            if (k==1)
              save_to_file(students);

            cout<<"have a nice day"<<endl ;
        break;

            }

       default:
        cout<<"invalid input please try again"<<endl;

      }
  }
while (choose!=9);
}

