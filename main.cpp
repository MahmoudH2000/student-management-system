#include <iostream>
#include<fstream>
#include<cstring>
#include <limits>
#include <iomanip>
#include <stdlib.h>
using namespace std;
std::fstream& GotoLine(std::fstream& file, unsigned int num);
class student
{//this class represents one student's information(name,department,rollno,address,subject number,marks,total grade)
       public:
      int rollno;
      string name,department;
      struct address
	{
	    string city, residential_area;
	    int zip_code;
	}; address my_address ;
      int subject_number;
      float marks[10],total,precentage;
      char grade;
      void read(std::fstream& fin,unsigned int line);
	    string display_name();
	    string display_department();
        string display_city();
        string display_residential_area();
        int display_zip_code();
        int display_subject_number();
        int display_rollno();
        float display_marks(int i);
        float display_total();
        float display_precentage();
	    void calculate();
	    void modify_student();
	    void add_student();
};
void swap_data(student &s1,student &s2);
void sort_data(student s[],int len);
int read(student s[],int sze);
void update_data(student s[],int len);
fstream fin;
std::fstream& GotoLine(std::fstream& file, unsigned int num)
{// this function take the file and the number of line that we want to go to.
 //we use it to go to the line that contains the name to read it
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}
void student::read(std::fstream& fin,unsigned int line)
{  //this the main function that reads the file
    GotoLine(fin,line);//to go to the line that needs to be read
  std::getline(fin,name);//reads the name
  fin>>department>>rollno>>my_address.city>>my_address.residential_area>>my_address.zip_code>>subject_number;
  for(int j=0;j<subject_number;j++)
  fin>>marks[j];
}
void student::add_student(){//this is a function that reads the information of one student to add to the file
    cout<<"\n\n\n\n\n\tEnter the student's name:\n\t";
    cin.ignore();
    getline(cin,name);
    cout<<"\tEnter the student's department:\n\t";
    cin.ignore();
    getline(cin,department);
    cout<<"\tEnter the student's roll no:\n\t";
    cin>>rollno;
    cout<<"\tEnter the student's city:\n\t";
    cin.ignore();
    getline(cin,my_address.city);
    cout<<"\tEnter the student's residential area:\n\t";
    cin.ignore();
    getline(cin,my_address.residential_area);
    cout<<"\tEnter the student's zip code:\n\t";
    cin>>my_address.zip_code;
    cout<<"\tEnter the student's number of subjects:\n\t";
    cin>>subject_number;
    for(int j=0;j<subject_number;j++)
  {
      cout<<"\tEnter the student's mark in subject "<<j+1<<":\n\t";
      cin>>marks[j];
  }
}
void student::modify_student()
{//this function modifies the information of a student
    bool stat =true;//used to end the loop
    char ch;//used as the choice that the user will make
    int i;//nuber of subjects
    while(stat)
    {system("cls");
        cout<<"\n\n\n\n\n\tWhat do you want to modify:\n";
        cout<<"\t1.Name\n";
        cout<<"\t2.Department\n";
        cout<<"\t3.Roll no\n";         //this the menu to choose from
        cout<<"\t4.Address\n";
        cout<<"\t5.Subject number\n";
        cout<<"\t6.Marks\n";
        cout<<"\t7.Exit\n";
        cout<<"\n\n\tPlease Select Your Option (1-7) ";
		cin>>ch;
		switch(ch){
		case '1':{system("cls"); //this will take the new name
		          cout<<"\n\n\n\n\n\tEnter new name:\n";
		           cin.ignore();
                 getline(cin, name);
                 cout<<"\tName has been changed successfully\n";
                 system("pause");}break;
		case '2':{system("cls"); //this will take the new department
		          cout<<"\n\n\n\n\n\tEnter new department:\n";
		           cin.ignore();
                 getline(cin, department);
                 cout<<"\tDepartment has been changed successfully\n";
                 system("pause");}break;
		case '3':{system("cls"); //this will take the new rollno
		          cout<<"\n\n\n\n\n\tEnter new roll no:\n";
		         cin>>rollno;
                 cout<<"\tRoll no has been changed successfully\n";
                 system("pause");}break;
		case '4':{while(stat){system("cls"); //this will take the new address
		           cout<<"\n\n\n\n\n\tWhat do you want to modify:\n";
                   cout<<"\t1.City\n";
                   cout<<"\t2.Residential area\n";
                   cout<<"\t3.Zip code\n";
                   cout<<"\t4.return\n";
                   cout<<"\n\n\tPlease Select Your Option (1-4) ";
                   cin>>ch;
                   switch (ch){
                   case '1':{system("cls");
		          cout<<"\n\n\n\n\n\tEnter new city :\n";
		           cin.ignore();
                 getline(cin, my_address.city);
                 cout<<"\tCity has been changed successfully\n";
                 system("pause");}break;
                   case '2':{system("cls");
		          cout<<"\n\n\n\n\n\tEnter new residential area :\n";
		           cin.ignore();
                 getline(cin, my_address.residential_area);
                 cout<<"\tResidential area has been changed successfully\n";
                 system("pause");}break;
                   case '3':{system("cls");
		          cout<<"\n\n\n\n\n\tEnter new zip code:\n";
		         cin>>my_address.zip_code;
                 cout<<"\tZip code has been changed successfully\n";
                 system("pause");}break;
                   case '4':{stat=false;}break;
                                 }}
                   stat=true;
                   break;}
		case '5':{system("cls"); //this will take the new number of subjects
		          cout<<"\n\n\n\n\n\tEnter subject number:\n";
		         cin>>subject_number;
                 cout<<"\tSubject number has been changed successfully\n";
                 system("pause");}break;
		case '6':{while(stat){system("cls"); //this will take the new marks
		          cout<<"\n\n\n\n\n\tEnter the subject number mark you want to change:\n";
		         cin>>i;
		         if((i<=subject_number)&&(i>0)){
                     cout<<"\tEnter the new mark :\n";
                     cin>>marks[i-1];
                 cout<<"\tMark has been changed successfully\n";}
                 else cout<<"\tinvalid subject number\n";
                 system("pause");
                  cout<<"\tDo you want to exit editing marks:\n";
                   cout<<"\t1.yes\n";
                   cout<<"\t2.no\n";
                   cout<<"\n\n\tPlease Select Your Option (1-2) ";
                   cin>>ch;
                   if(ch=='1')
                    stat=false;
                   }}
                 stat=true;
                 break;
		case '7':{system("cls");//to exit the loop
		stat=false;}break;
    }}}
    //the following 10 functions are used to display the student in formation
string student::display_name()
{
    return name;
}
string student::display_department()
{
    return department;
}
string student::display_city()
{
    return my_address.city;
}
string student::display_residential_area()
{
    return my_address.residential_area;
}
int student::display_zip_code()
{
    return my_address.zip_code;
}
int student::display_subject_number()
{
    return subject_number;
}
int student::display_rollno()
{
    return rollno;
}
float student::display_marks(int i)
{
    return marks[i];
}
float student::display_total()
{
    return total;
}
float student::display_precentage()
{
    return precentage;
}
void swap_data(student &s1,student &s2)
{//this function swaps two students with each other
    //it will be used in sorting
    student s3;
    s3=s1;
    s1=s2;
    s2=s3;
}
int partition (student arr[], int low, int high)
{//used in sorting as a part of quick sort algorithm to divide the array
    string pivot = arr[high].display_name();
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j].display_name() < pivot)
        {
            i++;
            swap_data(arr[i], arr[j]);
        }
    }
    swap_data(arr[i + 1], arr[high]);
    return (i + 1);
}
void sort_data(student s[],int low,int high)
{//sort the data using quick sort
 if (low < high)
    {

        int i = partition(s, low, high);

        sort_data(s, low, i - 1);
        sort_data(s, i + 1, high);
    }

}
int deleteElement(student arr[], int n,int pos)//it takes the array of students and his position
{//this function deletes a student from the file and decrease the number of objects
int i;
    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return n - 1;
}
int read(student s[],int sze)//it takes the array of students and its size and returns the number of students it read from the file
{
unsigned int i,line=1,j=1;

    fin.open("students.txt");
    if(fin.fail()){
        cout<<"Error opening file."<<endl;
    }

    while(!fin.eof())
    {
        line++;
        GotoLine(fin,line);
    }
   line-=2;
 for(i=0;i<sze&&j<=line;i++,j+=2)
    {

        s[i].read(fin,j);

    }
GotoLine(fin,1);
fin.close();
return i;

}
void update_data(student s[],int len)//it takes the array of students and its length
{//it updates the file after sorting it
    fstream temp;
    int line=1;
    temp.open("students.txt",ios::out);
    if(!temp)
        cout<<"\tError updating data!!!\n";
    else
    {
        temp.open("test.txt", std::ofstream::out | std::ofstream::trunc);
        temp.close();
        temp.open("students.txt",ios::out);
        for(int i=0;i<len;i++)
        {

            temp<<s[i].name;
            temp<<"\n";

            temp<<s[i].display_department()<<" "<<s[i].display_rollno()<<" "<<s[i].display_city()<<" "<<s[i].display_residential_area()<<" "<<s[i].display_zip_code()<<" "<<s[i].display_subject_number()<<" ";
    for(int j=0;j<s[i].display_subject_number();j++)
  temp<<s[i].display_marks(j)<<" ";
  temp<<"\n";

        }
}
}
void student::calculate()
{//it calculates the total percentage and the grade
    total=0;
    for(int i=0;i<subject_number;i++)
    total = total+marks[i];
	        precentage = total/(subject_number) ;

	        if (precentage < 50)
                {
                    grade = 'F';
                }
            else if (precentage < 65)
                {
                    grade = 'D';
                }
            else if (precentage < 75)
                {
                    grade = 'C';
                }
            else if (precentage < 85)
                {
                    grade = 'B';
                }
            else
                {
                    grade = 'A';
                }

}
void display(student s[],int length)//it takes the array of students and its length
{//it will print a table containing the information of the students
   cout<<setw(6)<<"name"<<setw(40)<<"rollno"<<setw(20)<<"department"<<setw(15)<<"subject1"<<setw(15)<<"subject2"<<setw(15)<<"subject3"<<setw(15)<<"subject4"<<setw(15)<<"subject5"<<setw(15)<<"subject6"<<setw(15)<<"grade"<<setw(15)<<"precentage";
    cout<<endl;
    cout<<".........................................................................................................................................................................................\n";
    for(int i=0;i<length;i++){
    cout<<s[i].name<<setw(44-(s[i].name).length())<<s[i].rollno<<setw(20)<<s[i].department;
    for(int j=0;j<6;j++)
        cout<<setw(15)<<s[i].marks[j];
        cout<<setw(15)<<s[i].grade<<setw(15)<<s[i].precentage;
cout<<endl;
cout<<".........................................................................................................................................................................................\n";}
}
void display_student(student s)//it takes the student that needs to be displayed
{//it will the information of the student
 cout<<setw(6)<<"name"<<setw(40)<<"rollno"<<setw(20)<<"department"<<setw(15)<<"subject1"<<setw(15)<<"subject2"<<setw(15)<<"subject3"<<setw(15)<<"subject4"<<setw(15)<<"subject5"<<setw(15)<<"subject6"<<setw(15)<<"grade"<<setw(15)<<"precentage";
    cout<<endl;
    cout<<".........................................................................................................................................................................................\n";
      cout<<s.name<<setw(44-(s.name).length())<<s.rollno<<setw(20)<<s.department;
    for(int j=0;j<6;j++)
        cout<<setw(15)<<s.marks[j];
        cout<<setw(15)<<s.grade<<setw(15)<<s.precentage;
cout<<endl;
cout<<".........................................................................................................................................................................................\n";
}
int search_name ( student s[],int length ,string target)//binary search function
{//it will take the array of student and it's length and the target to find the student
     int first = 0;

int last = length - 1;

int mid;

while (first <= last )

{ mid = (first + last) / 2;

if (s[mid].name == target) {display_student(s[mid]);
return mid;}

else if (s[mid].name > target)

last = mid - 1;

else first = mid + 1; }
cout<<"student not found \n";
return -1;

 }
int search_rollno(int x,student s[],int len)
{//it will take the array of student and it's length and the target to find the student
for (int i=0;i<len;i++)
    {
        if (s[i].display_rollno()==x)
   {
        display_student( s[i]);
        return i;
            }
    }
cout<<"Student not found\n";
return -1;
}
int main()
{
     int r,f,h,l;//options read from user
    int rollno_search;//used in searching by roll no
    string name_search;//used in searching by name
   student s[100];//array of objects of type student
   int i =0;//number of objects occupied in the array
   bool test =false;//to check that the data is read from the file
    char ch;
	do
	{
	system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. Insert students into the system";
		cout<<"\n\n\t02. Add student into the system";
		cout<<"\n\n\t03. Delete student from the system";
		cout<<"\n\n\t04. Search for a student via their id number or via their name";
		cout<<"\n\n\t05. Edit student details";
		cout<<"\n\n\t06. Calculate the total score and get grade of the student";
		cout<<"\n\n\t07. Print student information";
		cout<<"\n\n\t08. EXIT";

		cout<<"\n\n\tPlease Select Your Option (1-8) ";
		cin>>ch;
		switch(ch)
		{
			case '1': {system("cls");//option 1 Insert students into the system from file discussed in details in the report
			           i=read(s,sizeof(s)/sizeof(s[0]));
			           if(i){sort_data(s,0,i-1);
                             update_data(s,i);
                             for(int u=0;u<i;u++)
                                s[u].calculate();
			                    test =true;
			                    cout<<"\n\n\n\n\n\tDone reading the data from the file.\n";
			                    }
                       system("pause");}
            break;
            case '2': {      if(test){system("cls");//option 2 Adds student into system discussed in details in the report
                                  if(i<sizeof(s)/sizeof(s[0]))//checks that we didn't exceed the size of the array.
                                  {
                                      s[i].add_student();
                                      s[i].calculate();
                                      i++;
                                      cout<<"\tstudent added successfully.\n\t";
                                      system("pause");
                                      sort_data(s,0,i-1);
                                      update_data(s,i);


                                  }
                                  else
                            cout<<"\n\n\n\n\n\tNot enough space to add new student\n\t";
                                  }
                        else {system("cls");cout<<"\n\n\n\n\n\tNO DATA HAS BEEN ENTERED \n";
                system("pause");}

                       }
            break;
            case '3':{if(test){ system("cls");cout<<"\n\n\n\n\n\t1.Delete using name \n\n";//option 3 Delete student from the system discussed in details in the report
                    cout<<"\n\n\t2.Delete using rollno \n\n";
                    cout<<"\n\n\tPlease Select Your Option (1,2) ";
                    cin>>r;
                    if(r==1)
                        {
                            system("cls");
                            cout<<"\n\n\n\n\n\tplease enter the name \n\t";
                            cin.ignore();
                            getline(cin, name_search);
                            l=search_name(s,i,name_search);
                            if(l!=-1)
                            {


                            i=deleteElement(s,i,l);
                            update_data(s,i);
                            cout<<"The student has been deleted successfully.\n";
                            system("pause");}
                            else
                                system("pause");
                        }
                    else if(r==2)
                        {
                            system("cls");
                           cout<<"\n\n\n\n\n\tplease enter the rollno \n\t";
                            cin>>rollno_search;
                            l=search_rollno(rollno_search,s,i);
                            if(l!=-1)
                            {


                            i=deleteElement(s,i,l);
                            update_data(s,i);
                            cout<<"The student has been deleted successfully.\n";
                            system("pause");}
                            else
                                system("pause");
                        }

                        }


                        else {system("cls");cout<<"\n\n\n\n\n\tNO DATA HAS BEEN ENTERED \n";
                system("pause");}



            }break;
			case '4'://option 4 Search for a student via their id number or via their name discussed in details in the report

                {if(test)
                {system("cls");
                    cout<<"\n\n\n\n\n\t1.search using name \n\n";
                    cout<<"\n\n\t2.search using rollno \n\n";
                    cout<<"\n\n\tPlease Select Your Option (1,2) ";
                    cin>>r;
                    if(r==1)
                        {
                            system("cls");
                            cout<<"\n\n\n\n\n\tplease enter the name \n\t";
                            cin.ignore();
                            getline(cin, name_search);
                            l=search_name(s,i,name_search);
                            system("pause");
                        }
                    else if(r==2)
                        {
                            system("cls");
                           cout<<"\n\n\n\n\n\tplease enter the rollno \n\t";
                            cin>>rollno_search;
                            l=search_rollno(rollno_search,s,i);
                            system("pause");
                        }
                }

                else {system("cls");cout<<"\n\n\n\n\n\tNO DATA HAS BEEN ENTERED \n";
                system("pause");}
                }

                  break;
			case '5':{system("cls");//option 5 Edit student details discussed in details in the report
			           if(test){
                    cout<<"\n\n\n\n\n\t1.edit using name \n\n";
                    cout<<"\n\n\t2.edit using rollno \n\n";
                    cout<<"\n\n\tPlease Select Your Option (1,2) ";
                    cin>>r;
                    if(r==1)
                        {
                            system("cls");
                            cout<<"\n\n\n\n\n\tplease enter the name \n\t";
                            cin.ignore();
                            getline(cin, name_search);
                            l=search_name(s,i,name_search);
                            if(l!=-1)
                            {

                            s[l].modify_student();
                            sort_data(s,0,i);
                          update_data(s,i);
                            }
                            else
                                system("pause");

                        }
                    else if(r==2)
                        {
                            system("cls");
                           cout<<"\n\n\n\n\n\tplease enter the rollno \n\t";
                            cin>>rollno_search;
                            l=search_rollno(rollno_search,s,i);
                            if(l!=-1){
                            s[l].modify_student();
                            sort_data(s,0,i);
                          update_data(s,i);

                        }
                         else
                                system("pause");
                        }

			           }
			           else {system("cls");
			           cout<<"\n\n\n\n\n\tNO DATA HAS BEEN ENTERED \n";
                       system("pause");}


                     }
				break;
            case '6' : {//Calculate the total score and get grade of the student discussed in details in the report
		if (test){system("cls");
                for(int t=0;t<i;t++)
                      s[t].calculate();
                      cout<<"\n\n\n\n\n\tthe grades have been calculated\n";
                      system("pause");}
                      else {system("cls");
                      cout<<"\n\n\n\n\n\tNO DATA HAS BEEN ENTERED \n";
                      system("pause");}}
                  break;
            case '7' ://option 7 Print student information discussed in details in the report
                {system("cls");
			    if (test){
                    cout<<"\n\n\n\n\n\t1.display one student\n";
                    cout<<"\t2.display all students\n";
                    cout<<"\n\n\tPlease Select Your Option (1,2) ";
                    cin>>f;
                    if(f==2){
                     display(s,i);
                     system("pause");
                    }
                     if(f==1){system("cls");
                        cout<<"\n\n\n\n\n\t1.enter  name \n\n";
                    cout<<"\t2.enter rollno \n\n";
                    cout<<"\n\n\tPlease Select Your Option (1,2) ";
                    cin>>h;
                    if(h==1)
                        {system("cls");
                            cout<<"\n\n\n\n\n\tplease enter the name \n\t";
                            cin.ignore();
                            getline(cin, name_search);
                            search_name(s,i,name_search);
                            system("pause");
                        }
                    else if(h==2)
                        {system("cls");
                           cout<<"\n\n\n\n\n\tplease enter the rollno \n\t";
                            cin>>rollno_search;
                            search_rollno(rollno_search,s,i);
                            system("pause");
                        }
                     }
			    }
                     else  {system("cls");cout<<"\n\n\n\n\n\tNO DATA HAS BEEN ENTERED \n";system("pause");}
			}
                  break;
			default :cout<<"\a";
		}
    }while(ch!='8');//option 8 Exits from the program
return 0;
}


