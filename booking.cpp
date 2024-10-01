#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void bookticket(const std::string& filename);
struct Train {
    char id[5];            
    char name[50];
    char source[50];
    char destination[50];
    char date[11];        
    char time[10];        
};
struct passenger{
    string passid;
    string name;
    string phonenumber;
    string trainid;
};
void writepassengers(const string& filename, const vector<passenger>& pass) {
    ofstream outFile(filename, ios::binary|ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    for (const auto& pass : pass) {
        outFile.write(reinterpret_cast<const char*>(&pass), sizeof(pass));
    }
    outFile.close();
}

void bookticket(const std::string& filename){
    ifstream rf(filename,ios::binary);
    if (!rf) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    Train train;
    string name,phonenumber,source,destination,date,time,id;
    cout<<"enter source:";cin>>source;
    cout<<"enter destination:";cin>>destination;
    cout << "Trains availiable:\n";
    int n=0;
    while (rf.read(reinterpret_cast<char*>(&train), sizeof(Train))) {
        if (train.source==source&&train.destination==destination ){
            n+=1;
            cout<<n<<" id:"<<train.id<< " date:"<<train.date<<" time:"<<train.time<<" train:"<<train.name<<endl;
        }
    }
    rf.close();
    if (n==0){
        cout<<"no trains availiable";
    }
    else{
    cout<<"enter trainid:";cin>>id;
    cout<<"enter name:";cin>>name;
    cout<<"enter phone number:";cin>>phonenumber;
    vector<passenger> pass;
    pass.push_back({id,name,phonenumber,train.id});
    writepassengers("passengers.dat",pass);
    cout<<"ticket booked";}

}