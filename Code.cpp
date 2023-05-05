/* This program is made for the management of the bank system.
  In this, the person who has authority in the bank, can only use this program.
  The program can help in opening an account, checking account Info, Deposit money to the account and many more operations we can do. */

#include <iostream>
#include <vector>
#include <cctype>
#include <iomanip>
#include <fstream>

using namespace std;

// List of user defined function used in this program
void WriteOnFile();
void DisplayFromFile(long long int acno);
void DepositToFile(long long int num);
void WithdrawFromFile(long long int num);
void TransferInsideFile(long long int a , long long int b);
void ModifyFile(long long int num);
void DeleteFromFile(long long int num);
void AllRecordsFromFile();
void menu();

// List of user defined class used in this program
class person;
class account;
class passcodes;

// class person is a abstract class
class person
{
    protected:

    char name[100];

    public:

    virtual void CreateAccount() = 0;
}; // end of class person

// class account is a derived class of class person
class account : public person
{
    protected:

    long long int AcNo;
   
    long long int balance;
   
    char type;
   
    int FDs;
   
    int passbooks=0;
   
    int chequebook=0;
   
    char DCs[12] = "xxxxxxxxxxx";
   
    char CCs[12] = "xxxxxxxxxxx";

    public:

    int ccCheck=0,dcCheck=0;

    /* CreateAccount is the member function for creating a account in the bank,
    for creating account, program will ask customer name, account type(Saving/Current), Initial balance to be deposit,
    and additionally it will ask whether the customer will have to issue a debit or credit card */
    void CreateAccount()
    {
        srand((unsigned) time(NULL));
        cout<<"\nEnter Your Name : ";
        fflush(stdin);
        cin.getline(name,100);

        cout<<"\nEnter Account Type (S/C) : ";
        cin>>type;

        AcNo=(1000+(rand()%9999));
        cout<<"Yor account is created \n";
        cout<<"Your account number is: "<<AcNo<<endl;


        int checker=1;

        while(checker)
        {
            cout<<"\nEnter Initial Balance (Greater Than 1000 for S Type and Greater than 5000 for C Type): ";
       
            cin>>balance;
   
            if(balance < 1000 && type == 'S')
                {
                    cout<<"\nSorry! Minimum Balance Too Low..";
                    continue;
                }
   
            else
                checker=0;

            if(balance < 5000 && type == 'C')
                {
                    cout<<"\nSorry! Minimum Balance Too Low..";
                    continue;
                }  
         
            else
                checker=0;

        } // end of while loop
       
        int choice = 0;
       
        cout<<"\nDo you Wish to Issue a Credit Card? (0/1): ";
       
        cin>>choice;

        if(choice)
        {
            ccCheck=1;
           
            cout<<"\nEnter Your 10 Digit - Credit Card Number (First Four Characters to Be Your Name) : ";
           
            fflush(stdin);
            cin.getline(CCs,11);
           
            cout<<"\nA Credit Card Has Been Successfully Issued with Number : "<<CCs<<endl;
        }

        cout<<"\nDo you Wish to Issue a Debit Card? (0/1): ";
       
        cin>>choice;

        if(choice)
        {
            dcCheck=1;
           
            cout<<"\nEnter Your 10 Digit - Debit Card Number (First Four Characters to Be Your Surname) : ";
           
            fflush(stdin);
            cin.getline(DCs,11);
           
            cout<<"\nA Debit Card Has Been Successfully Issued with Number : "<<DCs<<endl;
        }

        cout<<"\nDo you Wish to Issue a ChequeBook? (0/1): ";
       
        cin>>choice;

        if(choice)
        {
            cout<<"\nA chequeBook Has Been Issued to You.\n";
            chequebook++;
        }

        cout<<"\nDo you Wish to Issue a PassBook? (0/1): ";
       
        cin>>choice;

        if(choice)
        {
            cout<<"\nA PassBook Has Been Issued to You.\n";
            passbooks++;
        }
    } // end of CreateAccount member function

    // AccountReport is the member function for printing the account details of the customer
    void AccountReport()
    {
        cout<<"\nDisplaying Account Report: -\n\n";

        cout<<"Name : "<<name<<'\t';

        cout<<"Account No. : "<<AcNo<<endl;

        cout<<"\nBalance : "<<balance<<'\t';

        cout<<"Credit Card Issued? : ";
       
        if(ccCheck==0)
            cout<<"No\n";
       
        else
        {
            string dummy;
           
            for (auto i : CCs)
            dummy+=i;
           
            cout<<"Yes ("<<dummy<<")\n";
        }

        cout<<"\nDebit Card Issued? : ";

        if(dcCheck==0)
            cout<<"No\t";
       
        else
        {
            string dummy;
           
            for (auto i : DCs)
            dummy+=i;
           
            cout<<"Yes ("<<dummy<<")\t";
        }

        cout<<"Passbook Issued? : ";passbooks>0?cout<<" Yes\t":cout<<"No\t";

        cout<<"ChequeBook Issued? : ";chequebook>0?cout<<" Yes\n":cout<<"No\n";
    } // end AccountReport member function

    // Deposit is the member function for updating balance after depositing ammount
    void Deposit(int a)
    {
        balance = balance + a;
    }

    // Withdraw is the member function for updating balance after withdrawing ammount
    void Withdraw(int a)
    {
        balance = balance - a;
    }

    // BasicReport is the member function for printing the account number, name nad balance of the customer
    void BasicReport()
    {
        cout<<AcNo<<"\t\t"<<name<<"\t\t"<<balance<<endl<<endl;
    }
 
    // FindAccountNumber is the member function for returning the account number of the customer
    long long int FindAccountNumber()
    {
        return AcNo;
    }

    // ModifyAccount is the member function for inputing the details of customer for modifying the previous details
    void ModifyAccount()
    {
        cout<<"\n\nEnter New Details :- \n\n";

        cout<<"Name : ";
        fflush(stdin);
        cin.getline(name,99);

        cout<<"\nAccount No. : ";
        cin>>AcNo;

        cout<<"\nBalance : ";
        cin>>balance;

        int choice = 0;
       
        cout<<"\n\nDo you Wish to Issue a New Credit Card? (0/1): ";
       
        cin>>choice;

        if(choice)
        {
            ccCheck=1;
           
            cout<<"\nEnter Your 10 Digit - Credit Card Number (First Four Characters to Be Your Name) : ";
            fflush(stdin);
            cin.getline(CCs,11);
           
            cout<<"\nA Credit Card Has Been Successfully Issued with Number : "<<CCs<<endl;
        }

        cout<<"\nDo you Wish to Issue a New Debit Card? (0/1): ";
       
        cin>>choice;

        if(choice)
        {
            dcCheck=1;
           
            cout<<"\nEnter Your 10 Digit - Credit Card Number (First Four Characters to Be Your Surname) : ";
            fflush(stdin);
            cin.getline(DCs,11);
           
            cout<<"\nA Credit Card Has Been Successfully Issued with Number : "<<DCs;
        }

        cout<<"\nDo you Wish to Issue a New ChequeBook? (0/1): ";
       
        cin>>choice;

        if(choice)
        {
            cout<<"\nA chequeBook Has Been Issued to You.\n";
            chequebook++;
        }

        cout<<"\nDo you Wish to Issue a New PassBook? (0/1): ";
       
        cin>>choice;

        if(choice)
        {
            cout<<"\nA Passbook Has Been Issued to You.\n";
            passbooks++;
        }
    } // end of ModifyAccount member function
}; // end of class account

// WriteOnFile is the function for creating new account in the bank
void WriteOnFile()
{
    account A;
   
    ofstream OutputFile;
   
    OutputFile.open("Data.dat",ios::binary|ios::app);
   
    A.CreateAccount();
   
    OutputFile.write(reinterpret_cast<char *> (&A), sizeof(account));
   
    OutputFile.close();
} // end of WriteOnFile function

// DisplayFromFile is the function for displaying the customer account information
void DisplayFromFile(long long int acno)
{
    account A;
   
    bool flag=false;
   
    ifstream InputFile;
   
    InputFile.open("Data.dat",ios::binary);
   
    if(!InputFile)
    {
        cout<<"\nFile could not be open!!\n";
        system("pause");
        return;
    }

    while(InputFile.read(reinterpret_cast<char *> (&A), sizeof(account)))
    {
        if(A.FindAccountNumber()==acno)
        {
            A.AccountReport();
            flag=true;
        }
    } // end of while loop
   
    InputFile.close();
   
    if(flag==false)
    {
        cout<<"\nAccount number does not exist.\n";
        system("pause");
    }
} // end of DisplayFromFile function

// DepositToFile is the function for depositing money in the customer account in the bank
void DepositToFile(long long int num)
{
    bool found = 0;
    account A;
    fstream File;

    File.open("Data.dat", ios::binary|ios::in|ios::out);
   
    if(!File)
    {
        cout<<"\nFile could not be open\n";
        system("pause");
        return;
    }
   
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&A), sizeof(account));
       
        if(A.FindAccountNumber()==num)
        {
            A.AccountReport();
           
            int amount;
           
            cout<<"\nHow Much would you like to deposit? : ";
            cin>>amount;
           
            A.Deposit(amount);

            int pos=(-1)*static_cast<int>(sizeof(A));
           
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&A), sizeof(account));
           
            cout<<"\nRecord Updated.\n";
           
            found=true;
        }
    } // end of while loop
   
    File.close();
   
    if(found==false)
    {
        cout<<"\nRecord Not Found.\n";
        system("pause");
    }
} // end of DepositToFile funtion

// WithdrawFromFile is the function for withdrawing money from the customer account in the bank
void WithdrawFromFile(long long int num)
{
    bool found = 0;
    account A;
   
    fstream File;

    File.open("Data.dat", ios::binary|ios::in|ios::out);
   
    if(!File)
    {
        cout<<"\nFile could not be open\n";
        system("pause");
        return;
    }
   
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&A), sizeof(account));
       
        if(A.FindAccountNumber()==num)
        {
            A.AccountReport();
           
            int amount;
            cout<<"\nHow Much would you like to Withdraw? : ";
            cin>>amount;
           
            A.Withdraw(amount);
           
            int pos=(-1)*static_cast<int>(sizeof(A));
           
            File.seekp(pos,ios::cur);
           
            File.write(reinterpret_cast<char *> (&A), sizeof(account));
            cout<<"\nRecord Updated.\n";
           
            found=true;
        }
    } // end of while loop
   
    File.close();
   
    if(found==false)
    {
        cout<<"\nRecord Not Found.\n";
        system("pause");
    }
} // end of WithdrawFromFile function

// TransferInsideFile is the function for transfering the money from customer account to another account
void TransferInsideFile(long long int a , long long int b)
{
    bool found1 = 0,found2=0;
    int amount;
    account A;
   
    fstream File;

    File.open("Data.dat", ios::binary|ios::in|ios::out);
   
    if(!File)
    {
        cout<<"\nFile could not be open\n";
        system("pause");
        return;
    }
   
    while(!File.eof() && found1==false)
    {
        File.read(reinterpret_cast<char *> (&A), sizeof(account));
       
        if(A.FindAccountNumber()==a)
        {
            cout<<"\nHow Much would you like to Transfer? : ";
            cin>>amount;
           
            A.Withdraw(amount);
           
            int pos=(-1)*static_cast<int>(sizeof(A));
           
            File.seekp(pos,ios::cur);
           
            File.write(reinterpret_cast<char *> (&A), sizeof(account));
           
            found1=true;
        }
    } // end of while loop
   
    File.close();

    File.open("Data.dat", ios::binary|ios::in|ios::out);
   
    if(!File)
    {
        cout<<"\nFile could not be open\n";
        system("pause");
        return;
    }
   
    while(!File.eof() && found2==false)
    {
        File.read(reinterpret_cast<char *> (&A), sizeof(account));
       
        if(A.FindAccountNumber()==b)
        {
            A.Deposit(amount);
           
            int pos=(-1)*static_cast<int>(sizeof(A));
           
            File.seekp(pos,ios::cur);
           
            File.write(reinterpret_cast<char *> (&A), sizeof(account));
           
            cout<<"\nBoth The Records have been Updated.\n";
            found2=true;
        }
    } // end of while loop
   
    File.close();

    if(found1==false || found2==0)
        {
            cout<<"\nRecord(s) Not Found.\n";
            system("pause");
        }
} // end of TransferInsideFile function

// ModifyFile is the function for modifying customer account from the bank records
void ModifyFile(long long int num)
{
    bool found=false;
    account A;
   
    fstream File;
   
    File.open("Data.dat",ios::binary|ios::in|ios::out);
   
    if(!File)
    {
        cout<<"\nFile could not be open\n";
        system("pause");
        return;
    }
   
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&A), sizeof(account));
       
        if(A.FindAccountNumber()==num)
        {
            A.AccountReport();
           
            A.ModifyAccount();
           
            int pos=(-1)*static_cast<int>(sizeof(account));
           
            File.seekp(pos,ios::cur);
           
            File.write(reinterpret_cast<char *> (&A), sizeof(account));
           
            cout<<"\nRecord Updated\n";
            found=true;
          }
    }
   
    File.close();
   
    if(found==false)
    {
        cout<<"\n\n Record Not Found.\n";
        system("pause");
    }
} // end of ModifyFile function

// DeleteFromFile is the function for deleting the existing account from the bank
void DeleteFromFile(long long int num)
{
    account A;
   
    ifstream InFile;
   
    ofstream OutFile;
   
    InFile.open("Data.dat",ios::binary);
   
    if(!InFile)
    {
        cout<<"\nFile could not be open\n";
        system("pause");
        return;
    }
   
    OutFile.open("TempFile.dat",ios::binary);
   
    InFile.seekg(0,ios::beg);
   
    while(InFile.read(reinterpret_cast<char *> (&A), sizeof(account)))
    {
        if(A.FindAccountNumber()!=num)
        {
            OutFile.write(reinterpret_cast<char *> (&A), sizeof(account));
        }
    }
   
    InFile.close();
   
    OutFile.close();
   
    remove("Data.dat");
   
    rename("TempFile.dat","Data.dat");
   
    cout<<"\nRecord Deleted ..\n";
} // end of DeleteFromFile function

// AlRecordsFromFile is the function for printing all records of the bank
void AllRecordsFromFile()
{
    account A;
   
    ifstream InFile;
   
    InFile.open("Data.dat",ios::binary);
   
    if(!InFile)
    {
        cout<<"File could not be open.\n";
        system("pause");
        return;
    }
   
    cout<<"\n\n====================================================\n\n";
   
    cout<<"Account No.      Name           Balance\n";
   
    cout<<"====================================================\n\n";
   
    while(InFile.read(reinterpret_cast<char *> (&A), sizeof(account)))
    {
        A.BasicReport();
    }
   
    cout<<"====================================================\n";
   
    InFile.close();
} // end of AllRecordsFromFile function

// menu is the function for printing the list of operations
void menu()
{
    cout<<"\nWhat would you like to do? \n\n";
   
    cout<<"1. Open An Account.\t";
   
    cout<<"2. Check Account Info.\n\n";
   
    cout<<"3. Deposit Money.\t";
   
    cout<<"4. Withdraw Money.\n\n";
   
    cout<<"5. Modify An Account.\t";
   
    cout<<"6. Transfer Money B/W Accounts.\n\n";
   
    cout<<"7. Delete An Account.\t";
   
    cout<<"8. Display All Records.\n\n";
   
    cout<<"9. Exit\n\n";

} // end of menu function

// passcodes is the class for authority of bank in which username and passwords are saved
class passcodes
{
    vector<string>names = {"Viplove Tyagi","Manan Garg","Manthan Gupta","Taha Zuberi"};
   
    vector<long long int>passwords = {3060,3081,3063,3059};

    public:

    // check is the function for checking that whether the user using this program is authority of bank or not
    void check(string n, long pass)
    {  
        int x = names.size();
       
        int checker = 0;
       
        while(x--)
        {
            if(names[x]==n && passwords[x]==pass)
                {
                    cout<<"Welcome! Master.\n";
                    checker=1;
                    break;
                }
        }

        if(!checker)
        {
            cout<<"Uh Oh! You aren't authorized to use this software!\n";
            throw 13435;
        }
    }

}; // end of class passcodes

passcodes p;

// main is the function for inputting the user validation details, and choice for doing some operations
int main()
{
    string name;
    long pass;

    cout<<"Enter Master Key (To use this software) : -\n\n";
   
    cout<<"Name: ";
    fflush(stdin);
    getline(cin,name);

    cout<<endl<<"Password: ";
    cin>>pass;
   
    system("cls");

    try
    {
        p.check(name,pass);
    }
   
    catch(int)
    {
        cout<<endl;
        system("pause");
        return 0;
    }

    int choice = 0;
    string clearance;

    while(choice!=9)
    {
        menu();
       
        cout<<"Enter Your Choice : ";
        cin>>choice;
       
        string transact;

        switch(choice)
        {
            case 1:

            WriteOnFile();

            break;

            case 2:

            long long int num;
            cout<<"\nEnter Account No. : ";
            cin>>num;

            DisplayFromFile(num);

            break;

            case 3:

            cout<<"\nEnter Account Number : ";
            long long int x;
            cin>>x;

            DepositToFile(x);

            break;

            case 4:

            cout<<"\nEnter Account Number : ";
            cin>>x;

            WithdrawFromFile(x);

            break;

            case 5:

            cout<<"\nEnter The Account No. whose Account you wish to modify : ";
            cin>>x;

            ModifyFile(x);

            break;

            case 6:

            long long int a,b;

            cout<<"\nEnter The Account Number of the Individual Sending Money : ";
            cin>>a;
            cout<<"\nEnter The Account Number of the Individual Receiving Money : ";
            cin>>b;

            cout<<"\nThe Account Sending Money: -";
            DisplayFromFile(a);

            cout<<"\nThe Account Receiving Money: -";
            DisplayFromFile(b);
           
            cout<<"Do you Approve this Transaction? (Yes/No) : ";
            cin>>transact;

            if(transact=="Yes")
                TransferInsideFile(a,b);

            else
            cout<<"Transaction Cancelled Successfully..\n";

            break;

            case 8:

            cout<<"\nDisplaying All Records: -";
            AllRecordsFromFile();

            break;

            case 7:

            cout<<"\nEnter Account Number of the Account You Wish to Delete : ";
            cin>>x;

            DisplayFromFile(x);

            cout<<"\nDo You Wish to Delete This Account? (Yes/No) : ";
            string del;
            cin>>del;

            if(del=="Yes")
                DeleteFromFile(x);

            else
                cout<<"The Account hasn't been deleted..\n";

            break;

        } // end of switch statement
        if(choice!=9)
        {
            cout<<"\nDo you wish To clear the Screen? (Yes/No) : ";
            cin>>clearance;

            if(clearance=="Yes")
            system("cls");

            else
            ;
        }

    } // end of while loop
   
    cout<<"\nThe program is about to be terminated..\nThanks For Using!\n\n";
    system("pause");
   
    return 0;
} // end of main function

