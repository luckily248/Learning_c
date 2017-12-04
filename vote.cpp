#include<iostream>
#include<fstream>       /* file io */
#include<cstdlib>
#include <time.h>       /* time */
#include<ctime>
using namespace std;

void create_db_and_seed(){
    //check if the DB allready exists
    ifstream infile("voter_db.txt");
    if(infile.good()){
        return;
    }
    
    //create and seed the DB
    ofstream voter_db;
    voter_db.open("voter_db.txt");
    for(int x=0;x<11;x++){
        voter_db<<rand()%9000 +1<<"\n";
    }
    voter_db.close();
}
void create_canidates(){
    int canidates_amount;
    string canidate_name;
    cout<<"\namount of canidates to create: ";
    cin>>canidates_amount;
    ofstream canidates;
    canidates.open("canidates.txt");
    for(int x=0;x<canidates_amount;x++){
        cout<<"\ncanadates name: ";
        cin>>canidate_name;
        canidates<<canidate_name<<"\n";
    }
    canidates.close();
}   //admin thingy
int  ask_for_voter_id(){
    int voter_id;
    cout<<"    Electrinic Vote \n"
        <<"Enter voter ID: "; 
    cin>>voter_id;
    return voter_id;
}
bool search_db_for_id(int voter_id){
    string line;
    fstream search_db ("voter_db.txt");
    if(search_db.is_open()){
        while(getline(search_db,line)){
            if(stoi(line)==voter_id){
                search_db.close();
                return true;
            }
        }
    search_db.close();
    return false;
    }
}

main(){
    srand(time(0));           //seed random with time
    create_db_and_seed();     //create DB if it is not found
    
    ifstream infile("canidates.txt");
    if(infile.good()){
    }else cout<<"\nnotify admin there are no canadate's to vote for\n";
    
}

/*
can check if a file exists------------------------------------------------------
bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
--------------------------------------------------------------------------------
*/
