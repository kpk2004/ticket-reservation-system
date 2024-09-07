#include<iostream>
#include<fstream>
#include<string>
using namespace std;

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
