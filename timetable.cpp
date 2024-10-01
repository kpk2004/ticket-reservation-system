#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void showtraindata(){

    string myFilePath = "timetable.csv";
    ifstream allRecords;
    allRecords.open(myFilePath);



    if(allRecords.fail()){
        cerr<<"Unable to Open the File"<< myFilePath<<endl;
        return ;
    }

    while(allRecords.peek()!=EOF){
        string records;
        getline(allRecords,records);

        cout<<records<<endl;
    }

allRecords.close();

return;
}
int main(){}
