#include "head.h"
void add_student(vector<student>& students){
    cout<<"provide these informations";
    student s;
    string ids;
    cout<<"inter student id from 6 digits "<<endl;
    while(cin>>ids){
    cin.ignore();
    if (ids=="-1")
    {return;}
    int i;
    for (i=0;i<students.size();i++)
    {if(ids==students[i].id)
        {cout<<"id is already exist, enter new one or press -1 to back menu"<<endl; break;}}
        if (i==students.size())
        break;
    }
     s.id=ids;
    cout<<"inter student name from three names "<<endl;
    getline(cin,s.name);
    for(int i=0;i<subnum;i++)
     {cout<<"inter grade of subject "<<subnames[i]<<endl;
     int deg;
     while(true){
            cin>>deg;
        if(deg<0||deg>maxdegree)
        {cout<<"please inter valid degree between 0&100"<<endl;}
        else
            break;
     }
        s.grades[i]=deg;}
        students.push_back(s);
}

/////////////////display
void display(vector<student>& students){
    if(students.size()==0)
      { cout<<"no students to display";
         return;
      }
    cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"  student id   | student name\t\t|logic   |Statistics |Numerical |Machine |Control |total grade"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0; i<students.size();i++)
      {cout << "  "<<students[i].id<<"       | ";
       cout<<students[i].name<<"\t|";
       for(int j=0;j<subnum;j++){
        cout<< "  " <<students[i].grades[j];
        cout << "\t| ";
       }
     cout<<students[i].total_rate()<<endl;
      }

      cout<<endl;
}




///////search
void Search(vector<student>& students){
    if(students.size()==0)
        {cout<<"no students to search";return;}
    int click;
    string inter;
    cout<<"to search by name click 0"<<endl;
    cout<<"to search by id click 1"<<endl;
    cin>>click;

    if (click==0)
     {cout<<"inter the name"<<endl;
     cin.ignore();
     getline(cin, inter);
     int c=0;
         for(int i=0; i<students.size();i++){
           if (inter==students[i].name)
         {c++;
         if (c==1)
   {cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"  student id\t  | student name\t\t|logic   |Statistics |Numerical |Machine |Control |total grade"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;}
      cout<<"  "<<students[i].id<<"\t     ";
      cout<<students[i].name<<"\t  ";
       for(int j=0;j<subnum;j++)
        cout<<"      "<<students[i].grades[j]<<"   ";
    cout<<"   "<<students[i].total_rate()<<endl;

         }
     }
     if (c==0)
      {cout<<"student not found";}
      return;}



  if (click==1)
     {cout<<"inter the id"<<endl;
     cin.ignore();
     getline(cin, inter);
         for(int i=0; i<students.size();i++)
         {if (inter==students[i].id)
         {

       cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
       cout<<"  student id\t  | student name\t\t|logic   |Statistics |Numerical |Machine |Control |total grade"<<endl;
       cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
       cout<<"  "<<students[i].id<<"\t     ";
       cout<<students[i].name<<"\t  ";
       for(int j=0;j<subnum;j++)
        cout<<"      "<<students[i].grades[j]<<"   ";
        cout<<"   "<<students[i].total_rate()<<endl;
                  return;
         }

         }
      cout<<"student not found";
      return;
     }
cout<<"invalid choice"<<endl;
}


////////////////update
void update (vector<student>& students){
    int click;
    string inter;
    cout<<"to update by name click 0"<<endl;
    cout<<"to update by id click 1"<<endl;
    cin>>click;

    if (click==0)
     {cout<<"inter the name"<<endl;
     cin.ignore();
     getline(cin, inter);
         for(int i=0; i<students.size();i++)
         {if (inter==students[i].name)
         {string ID;
             cout<<"to keep id enter -1 , to update enter new id";
             cin>>ID;
             if(ID!="-1")
                students[i].id=ID;
             //////rewrite
             int deg;
             cout<<" to keep  degrees press -1 ";
             cin>>deg;
             if (deg!=-1)
                for(int j=0;j<subnum;j++)
               {cout<<" inter grade of "<<subnames[j]<<endl;
                cin>>students[i].grades[j];
               }
                 return;

         }

         }
      cout<<"student not found";
      return;
     }
 if (click==1)
     {cout<<"inter the id"<<endl;
     cin.ignore();
     getline(cin, inter);
         for(int i=0; i<students.size();i++)
         {if (inter==students[i].id)
         {string names;
             cout<<"to keep name enter -1 , to update enter new name";
             cin.ignore();
             getline(cin, names);
             if(names!="-1")
                students[i].name=names;
             //////rewrite
             int degr;
             cout<<" to keep press degrees inter -1 ";
             cin>>degr;
             if (degr!=-1)
                for(int j=0;j<subnum;j++)
               {cout<<" inter grade of "<<subnames[j]<<endl;
                cin>>students[i].grades[j];
               }

                 return;

         }

         }
      cout<<"student not found";
      return;
     }
cout<<"invalid choice";
}

/////////////delete
void delete_student(vector<student>& students){
  string ID;
  cout<<" inter id to delete";
  cin>>ID;
  for(int i=0;i<students.size();i++)
   {if(students[i].id==ID)
        {for (int j=i;j<students.size()-1;j++)
        {students[j]=students[j+1];}
        students.pop_back();
        return;}}
cout<<"id not found";
}


void show_top_performing_students (vector<student>& students){
    if (students.size()==0)
    {cout<<"no students";
    return;
    }
    vector<student>sorting;
    sorting=students;
    sort(sorting.begin(),sorting.end(),[]( student&a, student&b){
         return a.total_rate()>b.total_rate();});
///////////////////////////////
                   cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
                   cout<<"  student id\t  | student name\t\t|logic   |Statistics |Numerical |Machine |Control |total grade"<<endl;
                   cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0; i<students.size();i++)
      {cout<<"  "<<sorting[i].id<<"\t     ";
       cout<<sorting[i].name<<"\t  ";
       for(int j=0;j<subnum;j++)
        cout<<"      "<<sorting[i].grades[j]<<"   ";
      cout<<"   "<<sorting[i].total_rate()<<endl;
      }
cout<<endl;
    }

////////////////////////////////////////////////storing
void save_to_file(vector<student>& students){
    ofstream save("students.txt");
    if(!save.is_open())
       {cout<<"error no file exist"<<endl; return;}
    for (int i=0;i<students.size();i++)
         {
           save << students[i].id<<endl;
           save << students[i].name<<endl;
           for (int j=0;j<subnum;j++){
                save<<students[i].grades[j]<<" ";

           }
           save<<endl;
         }

save.close();
cout<<"data saved"<<endl;
}

///////////////////////////////////////////////loading
 void load_from_file(vector<student>& students){
 ifstream input ("students.txt");
 students.clear();
 if (!input.is_open()){
    cout<<"file not found"<<endl;
    return;
 }
 student s;
 bool hasdata=false;
 while (input>>s.id){
        input.ignore();
        getline(input,s.name);
   for (int j=0;j<subnum;j++){
    input>>s.grades[j];}
    students.push_back(s);
    hasdata=true;
 }
 if(!hasdata){
    cout<<"file is empty"<<endl;
 }
 else
cout<<"data loaded"<<endl;
 input.close();

 }