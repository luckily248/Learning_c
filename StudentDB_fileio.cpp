//Michael Orlando

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<ctime>
using namespace std;

void createNewStudent();
void insertStudentToDB();
int retreveStudent_byIdentifyer(int number);
void PrintStudentID(int id);
void ChangeStudentData(int id);

struct student{
    // only one bool per thingy rec...
    //something like are you a Freshman? then F=1, then if upper U=1...
    //no need to ask the rest
    bool   FullTime,PartTime;
    bool   UpperF,LowerF;          //upper or lower freshman
    bool   UpperS,LowerS;          //upper or lower Sophmore 
    string Fname,Lname;
    int    Age;
    time_t TimeCreated = time(0);  //used for experation date
}NewStudent;

int main(){
    int select=42,Search_number=0;
    while(select!=5){
        cout<<"\n_-_-_-_-_-_-_-_-_-_-_-_-_\n"
            <<"1) Create new Student\n"
            <<"2) Search StudentDB\n"
            <<"3) Edit student Data\n"
            <<"5) QUIT\n"
            <<"_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
        cin>>select;
        
        if(select==1){
            createNewStudent();
            insertStudentToDB();
        }
        if(select==2){
            cout<<"\nSearch by?\n"
                <<"8) First Name\n"
                <<"9) Last Name\n"
                <<"7) Age\n";
            cin>>Search_number;
            if(Search_number>=9 && Search_number<=8){
                cout<<"invalid Input";
            }else PrintStudentID(retreveStudent_byIdentifyer(Search_number));
        }
        if(select==3){
            cout<<"\nSearch by?\n"
                <<"8) First Name\n"
                <<"9) Last Name\n"
                <<"7) Age\n";
            cin>>Search_number;
            if(Search_number>=9 && Search_number<=8){
                cout<<"invalid Input";
            }else ChangeStudentData(retreveStudent_byIdentifyer(Search_number));
        }
    }
    
    //cout<<retreveStudent_byIdentifyer(7);
    //PrintStudentID(3);
}

void insertStudentToDB(){
    ofstream StudentDB;
    StudentDB.open("StudentDB.txt",ofstream::app);
    StudentDB <<"-------------------"<<"\n" //next student devider & identifyer
              <<NewStudent.FullTime<<"\n"
              <<NewStudent.UpperF<<"\n"
              <<NewStudent.LowerF<<"\n"
              <<NewStudent.UpperS<<"\n"
              <<NewStudent.LowerS<<"\n"
              <<NewStudent.Age<<"\n"
              <<NewStudent.Fname<<"\n"
              <<NewStudent.Lname<<"\n"
              <<ctime(&NewStudent.TimeCreated);
    StudentDB.close();                
}
void createNewStudent(){
    cout <<"\nFirst name:";
    cin >>NewStudent.Fname;
    cout <<"\nLast name:";
    cin >>NewStudent.Lname;
    cout <<"\nAge:";
    cin >>NewStudent.Age;
    
    cout <<"\n-------------------------------------"
         <<"\n Enter 1 for Yes | Enter: 0 for No"
         <<"\n-------------------------------------";
    cout <<"\nFull Time Student:";
    cin >>NewStudent.FullTime;
    cout <<"\nPart Time Student:";
    cin >>NewStudent.PartTime;
    cout <<"\nUpper Freshman:";
    cin >>NewStudent.UpperF;
    cout <<"\nLower Freshman:";
    cin >>NewStudent.LowerF;
    cout <<"\nUpper Sophomore:";
    cin >>NewStudent.UpperS;
    cout <<"\nLower Sophomore:";
    cin >>NewStudent.LowerS;
}
int  retreveStudent_byIdentifyer(int number){
    int count=0,lineTraker=1,SearchInt;
    string line,SearchString;
    ifstream StudentDB;
    StudentDB.open("StudentDB.txt");
    
    if(number == 8 || number == 9){
        cout<<"Enter String: ";
        cin>>SearchString;
    }
    if(number>1 && number<8){
        cout<<"Enter Int: ";
        cin>>SearchInt;
    }
    
    if (StudentDB.is_open()){
        while(StudentDB.good()){
         getline (StudentDB, line);
         count++;
         //cout<<count<<"|"<<lineTraker<<": "<<line<<"\n";   //fast check to see number vs data
          if(count==10){
              count=0;       // next student
              lineTraker++;  // how far from Top
          }
          
          if((number == 8 || number == 9)&&(SearchString==line))return lineTraker;
          if((number>1 && number<8)&&(SearchInt==atoi(line.c_str())))return lineTraker;
        }
        StudentDB.close(); 
    }else cout<<"cant open file? (retreveStudent_byLName)";
}
void PrintStudentID(int id){
    int count=0,lineTraker=1,num;
    string line;
    ifstream StudentDB;
    StudentDB.open("StudentDB.txt");
    
    if (StudentDB.is_open()){
        while(StudentDB.good()){
            getline (StudentDB, line);
            if(lineTraker==id){
                
                if(count==1 && atoi(line.c_str()) == 1)cout<<"\nFull Time\n";
                if(count==2 && atoi(line.c_str()) == 1)cout<<"Upper Freshman"<<"\n";
                if(count==3 && atoi(line.c_str()) == 1)cout<<"Lower Freshman"<<"\n";
                if(count==4 && atoi(line.c_str()) == 1)cout<<"Upper Sophmore"<<"\n";
                if(count==5 && atoi(line.c_str()) == 1)cout<<"Lower Sophmore"<<"\n";
                if(count==6)cout<<"Age: "<<line<<"\n";
                if(count==7)cout<<line<<" ";
                if(count==8)cout<<line<<"\n";
                if(count==9)cout<<"Time Created: "<<line<<"\n";
                
                //cout<<count<<"|"<<lineTraker<<": "<<line<<"\n";
                // should close after this runs but meh...
            }
            
            count++;
            //cout<<count<<"|"<<lineTraker<<": "<<line<<"\n";   //fast check to see number vs data
            if(count==10){
                count=0;       // next student
                lineTraker++;  // how far from Top
            }
        }
    }
}
void ChangeStudentData(int id){
    createNewStudent();
    //copys the textfile to temporary vector, moding the selected student
    vector<string> tempfile;
    string line,tempstring;
    int count=0,lineTraker=1;
    bool DoOnce=true;
    ifstream StudentDB;
    
    StudentDB.open("StudentDB.txt");
    if (StudentDB.is_open()){
        
        //saves && modifys text file to tempfile vector
        while(StudentDB.good()){
         getline (StudentDB, line);
         count++;
         //cout<<count<<"|"<<lineTraker<<": "<<line<<"\n";   //fast check to see number vs data
          if(count==10){
              count=0;       // next student
              lineTraker++;  // how far from Top
          }
          
          if(lineTraker == id && count <= 9 && count > 0){ //meh lazy fix
            if(DoOnce){
                tempfile.push_back("-------------------");
                tempstring = to_string(NewStudent.FullTime);
                tempfile.push_back(tempstring);
                tempstring = to_string(NewStudent.UpperF);
                tempfile.push_back(tempstring);
                tempstring = to_string(NewStudent.LowerF);
                tempfile.push_back(tempstring);
                tempstring = to_string(NewStudent.UpperS);
                tempfile.push_back(tempstring);
                tempstring = to_string(NewStudent.LowerS);
                tempfile.push_back(tempstring);
                tempstring = to_string(NewStudent.Age);
                tempfile.push_back(tempstring);
                tempstring = NewStudent.Fname;
                tempfile.push_back(tempstring);
                tempstring = NewStudent.Lname;
                tempfile.push_back(tempstring);
                //tempstring = ctime(&NewStudent.TimeCreated);
                //tempfile.push_back(tempstring);
                DoOnce=false;
            }
          }else tempfile.push_back(line);
        }
        
        StudentDB.close(); 
    }else cout<<"cant open file?";
    
    ofstream StudentDB_overwrite;
    StudentDB_overwrite.open("StudentDB.txt");
    
    //recreates text file from tempfile vector
    for(int i=0; tempfile.size()>i; i++){
        StudentDB_overwrite<<tempfile[i]<<"\n";
    }
    
    StudentDB_overwrite.close();
    


}
/*
Glaring Problems with this{
    1) this program will not check duplicates during creation 
    2) if there are more than one that fits the search criteria... 
       (a vector could be used to store it as it iterates in retreveStudent_byIdentifyer)
    3) the UpperF...ect 1 or 0 data entry could be simplifyed
}
struct tm (http://www.cplusplus.com/reference/ctime/tm/){
    time_t TimeCreated = time(0);   // gets the system time in seconds
    ctime(&NewStudent.TimeCreated); // ctime will print out orginized time string
}
convert string to int{
    atoi("230498".c_str())
}
info on data retreval{
    1:  FullTime
    2:  UpperF
    3:  LowerF
    4:  UpperS
    5:  LowerS
    6:  Age
    7:  Fname
    8:  Lname
    9:  TimeCreated
}
info on dealing with text files{
    ifstream  // recive Input File Stream
    ofstream  // send   Output File Stream
    
    ofstream Name_your_file OR ifstream Name_your_file
    .open(file.txt) //ofstream::app can be added if you want to append
                    //otherwise same as cout<<.... useing << Ex:(Name_your_file << "stuff";)
    Then when done  .close() 
}
*/