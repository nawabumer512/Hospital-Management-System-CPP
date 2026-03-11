#include<iostream>
using namespace std;

struct Patient {
    int ID;
    char name[20];
    int amount;
    struct DocInfo{
        char DocName[20];
        char Spec[20];
    }doc;
};

void displayPatient(Patient& p){
cout<<"==============================="<<endl;
cout<<"  ID         : "<<p.ID<<endl;
cout<<"  Name       : "<<p.name<<endl;
cout<<"  Bill (Rs)  : "<<p.amount<<endl;
cout<<"-------------------------------"<<endl;
cout<<"  Doctor     : "<<p.doc.DocName<<endl;
cout<<"  Specialization : "<<p.doc.Spec<<endl;
cout<<"==============================="<<endl;
}

Patient& searchP(Patient* p, int id, int size){
    int index = 0;
    bool found = false;
    for(int i=0; i<size; i++)
        if((p+i)->ID == id){
            found = true;
            index = i;
            cout<<"-------------------------------"<<endl;
            cout<<"   Enter New Doctor Details    "<<endl;
            cout<<"-------------------------------"<<endl;
            cout<<"  Doctor Name      : "; cin>>(p+i)->doc.DocName;
            cout<<"  Specialization   : "; cin>>(p+i)->doc.Spec;
            cout<<"-------------------------------"<<endl;
        }
    if(!found)
        cout<<"==============================="<<endl
            <<"      Patient Not Found!       "<<endl
            <<"==============================="<<endl;
    return p[index];
}

int main(){

    cout<<"======================================="<<endl;
    cout<<"   Welcome to City Hospital System     "<<endl;
    cout<<"======================================="<<endl<<endl;

    int n;
    cout<<"  Enter Number of Patients : "; cin>>n;

    Patient* p = new Patient[n];

    for(int i=0; i<n; i++){
        cout<<endl<<"==============================="<<endl;
        cout<<"       Patient "<<i+1<<" Details        "<<endl;
        cout<<"==============================="<<endl;
        cout<<"  Patient ID       : "; cin>>(p+i)->ID;
        cout<<"  Patient Name     : "; cin>>(p+i)->name;
        cout<<"  Bill Amount (Rs) : "; cin>>(p+i)->amount;
        cout<<"-------------------------------"<<endl;
        cout<<"     Doctor Information        "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"  Doctor Name      : "; cin>>(p+i)->doc.DocName;
        cout<<"  Specialization   : "; cin>>(p+i)->doc.Spec;
        cout<<"==============================="<<endl;
    }

    cout<<endl<<"======================================="<<endl;
    cout<<"       Update Doctor Information       "<<endl;
    cout<<"======================================="<<endl;
    int id;
    cout<<"  Enter Patient ID : "; cin>>id;

    Patient& updP = searchP(p, id, n);

    cout<<endl<<"======================================="<<endl;
    cout<<"         Updated Patient Record        "<<endl;
    cout<<"======================================="<<endl;
    displayPatient(updP);

    delete[] p;
    return 0;
}