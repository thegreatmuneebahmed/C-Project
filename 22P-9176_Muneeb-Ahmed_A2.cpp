#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountnumber;
    string accountHolder;
    double balance;
    static int totalaccount;
public:
    BankAccount() {
        accountHolder = "N/A";
        balance = 0;
        totalaccount++;
        accountnumber = totalaccount;
    }
    BankAccount(int accountnumber, string accountHolder, double balance) {
        this->accountnumber=accountnumber;
        this->accountHolder=accountHolder;
        this->balance=balance;
        totalaccount++;
    }
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        if (amount>0 && amount<=balance) {
            balance -= amount;
        }
    }
    double getbal() {
        return balance;
    }
    int getaccountnumber() {
        return accountnumber;
    }
    static int getTotalaccount() {
        return totalaccount;
    }
    string getaccountholder() {
        return accountHolder;
    }
};
int BankAccount::totalaccount = 0;

class BankManager {
private:
    BankAccount*accounts;
    int size;

public:
    BankManager() {
        size = 0;
        accounts = new BankAccount[50];
    }
    BankAccount* createdaccount(string accountHolder ="Account Holder") {
        if (size < 50) {
            accounts[size] = BankAccount(size + 1, accountHolder, 0.0);
            BankAccount*newaccount=&accounts[size];
            size++;
            return newaccount;
        }
        cout<<"Limit Full"<<endl;
        return 0;
    }
    void deleteaccount(BankAccount* account) {
        for (int i=0; i<size; i++) {
            if (account == &accounts[i]) {
                for (int j=i; j<size-1; j++) {
                    accounts[j]=accounts[j + 1];
                }
                size--;
                cout<<"Account Deleted"<<endl;
                return;
            }
        }

        cout<<"Account not found"<<endl;
    }
    BankAccount* find(int num) {
        for (int i=0; i<size; i++) {
            if (num==accounts[i].getaccountnumber()) {
               return &accounts[i];
            }
        }
        return 0;
    }
    void display() {
        for (int i = 0; i < size; i++) {
        cout<<"--------------------------------"<<endl;
        cout<<"Account Number: "<<accounts[i].getaccountnumber()<<endl;
        cout<<"Account Holder: "<<accounts[i].getaccountholder()<<endl;
        cout<<"Balance: "<<accounts[i].getbal()<<endl;
        cout<<"--------------------------------"<<endl;

        }
    }
    int getTotalAccounts() {
        return size;
    }
    ~BankManager() {
        delete[] accounts;
    }
    void TotalAccounts() {
        cout<<"--------------------------------"<<endl;
        cout<<"Total Active Accounts: "<<getTotalAccounts()<<endl;
        cout<<"--------------------------------"<<endl;
    }
};

int main() {
    BankManager acc;
    BankAccount*acc1=acc.createdaccount("Muneeb");
    BankAccount*acc2=acc.createdaccount("Ahmed");
    acc1->deposit(1500);
    acc2->deposit(1000);
    acc.display();
    cout<<endl;
    BankAccount* foundAccount;
    foundAccount = acc.find(2);
    if (foundAccount) 
    {
        cout<<"--------------------------------"<<endl;
        cout<<"Account Found: "<<foundAccount->getaccountnumber()<<endl;
        cout<<"Account Holder: "<<foundAccount->getaccountholder()<<endl;
        cout<<"Balance: "<<foundAccount->getbal()<<endl;
        cout<<"--------------------------------"<<endl;

    } else {
        cout<<"Account not found";
    }
    cout<<endl;
    acc.TotalAccounts();
    acc.deleteaccount(acc2);
    acc.deleteaccount(acc1);
    cout<<"--------------------------------"<<endl;
    return 0;
}