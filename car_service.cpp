#include<iostream>
#include<fstream>
using namespace std;
class customer
{
public:
    int pres(int d)
    {
    if(d==1)
    return 300;
    else if(d==2)
    return 500;
    else if(d==3)
    return 200;
    else if(d==4)
    return 3000;
    else if(d==5)
    return 5000;
    else
    return 10000;
    }
};
class service_schedule : public customer
{
public:
int index()
{
int t;
cout<<"\t1.customer login\t\t\t";
cout<<"2.service schedule\n";
cout<<"you must have an account to enjoy our services.don't have one!no problem get it\n";
cout<<"\t3.coustomer signup\n";
cin>>t;
return t;
}
int printschedule()
{
int v3;
    cout<<"\tSERVICE TYPE\t\t\tTIME\tCOST(Rs)\n";
    cout<<"\t1.carwash\t\t\t1day\t300\n";
    cout<<"\t2.normal checkup\t\t3days\t500\n";
    cout<<"\t3.regular service\t\t5days\t200\n";
    cout<<"\t4.denting and painting\t\t5days\t3000\n";
    cout<<"\t5.part replacement\t\t3-5days\t5000\n";
    cout<<"\t6.accidental vehicles\t\t4days\t10000\n";
    cout<<"enter your choice";
    cin>>v3;
    return v3;
}
};

int main()
{
    int i,v1,vnum,pswd,v4,bill=0;
   string name,vm,v5="y";
    int getdetails();
    int logindetails();
    for(i=0;i<10;i++)
    cout<<"-";
    cout<<"SARFU SERVICE CENTRE";
    for(i=0;i<10;i++)
    cout<<"-";
    cout<<"\n";
    service_schedule s;
    v1=s.index();
    if(v1==1)
    {
    cout<<"enter your vehicle number";
    cin>>vnum;
    cout<<"enter your account password";
    cin>>pswd;
    cout<<"login succesful\n";
    v4=s.printschedule();
    }
    else if(v1==2)
    {v4=s.printschedule();}
    else if(v1==3)
    {cout<<"enter your name\n";
    cin>>name;
    cout<<"enter your vehicle number\n";
    cin>>vnum;
    cout<<"enter your vehicle model\n";
    cin>>vm;
    cout<<"account created succesfully\n";
    v4=s.printschedule();
    }
    else
    {
    cout<<"invalid input";
    s.index();
}
bill=bill+s.pres(v4);
    while(v5=="y")
    {
    cout<<"does your car needs any other service(y-yes || n-no)";
    cin>>v5;
    if(v5=="y"){
    v4=s.printschedule();
    bill=bill+s.pres(v4);}
    else
    v5="n";
    }
    cout<<"the total bill thus calculated is"<<bill;
    ofstream fileobject;
    fileobject.open("record.txt",ios::app);
    fileobject<<name<<"\t\t"<<vnum<<"\t\t"<<vm<<"\t\t"<<bill;
    fileobject.close();
}


