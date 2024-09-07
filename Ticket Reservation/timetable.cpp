#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// class detail{
//     public:
//     int tno;
//     char tname[100],startp[100],destp[100];

//     void getdetail(){
//         cout<<"Train no : "<<endl;
//         cin>>tno;
//         cout<<"Train name : "<<endl;
//         // gets(tname);
//         // cin>>tname>>endl;
//         // gets(tname);
//         cout<<"Enter the starting point : "<<endl;
//         gets(startp);
//         // cout<<"Enter the destination point : "<<endl;
//         // gets(destp);
//     };

// //     void displaydetail(){
// //         cout<<"Train No. " <<tno<<" From "<<tname<<" to "<<startp<<"  "<<destp<<endl;
//     }
// };

int main(){

    string myFilePath = "timetable.csv";
    ifstream allRecords;
    allRecords.open(myFilePath);



    if(allRecords.fail()){
        cerr<<"Unable to Open the File"<< myFilePath<<endl;
        return 1;
    }

    while(allRecords.peek()!=EOF){
        string records;
        getline(allRecords,records,',');

        cout<<records<<endl;
    }

allRecords.close();

return 0;
}
