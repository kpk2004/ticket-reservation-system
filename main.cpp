#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "booking.cpp"
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
int main(){
    int choice;
    cout<<"welcome to railyatri"<<endl<<"what would you like to do?"<<endl;
    cout<<"1.see availiable train data"<<endl;
    cout<<"2.book a ticket"<<endl;
    cout<<"3.cancel a ticket"<<endl;
    cout<<"choose:1,2,or3:";cin>>choice;
    if (choice==1){
        showtraindata();
    }
    if (choice==2){
        bookticket("trains.dat");
    }

}