#include <iostream>
using namespace std;
class atm{
    private:
    int amount;
    int pin;
    string userName;
    public:

    atm(){
        amount  = 0;
        pin = 1234;
    }
    bool authenticate(int pass){
        if(pass == pin){
            return true;
        }
        else{
            return false;
        }
    }
    void setPin(int newPin){
        if(newPin == pin){
            cout<< " You have used this pin earlier "<<endl;
        }
        else{
            pin = newPin;
        }
        
    }
    void setUserName(string name){
        userName = name;
    }
    void setAmount(int money){
        if(money<0){
            cout<< "Error: Deposit should be more than 0 "<<endl;
        }
        else{amount += money;}
        
    }

    void getAmount(){
        cout<< "Your bank currently has "<<amount<< " Rs"<<endl;
    }

    void withdraw(int expenses){
        if(expenses> amount){
            cout<< "Insufficent funds, Try to earn it before withdrawing "<<endl;
        }
        else{
        amount -= expenses;
        cout<< "You withdrew "<< expenses<<endl;
        cout<< "your bank now has "<< amount<<endl;
        }
        
    }


};

int main(){
    atm ATM;

    int x = 0;

    string name;

     cout<< "Enter you name ";

     cin>> name;

    ATM.setUserName(name);

     int pin;
     cout<< "enter your pin ";
     cin>> pin;

      if (!ATM.authenticate(pin)) {
        cout << "Incorrect Pin." << endl;
        return 0;  // Exit program if authentication fails
    }

    
   
        cout<< "Welcome " << name <<" to Our Bank! Please choose an option by entering the corresponding number:\n"
    "1 - Deposit Money: Add funds to your account.\n"
    "2 - Withdraw Money: Take out funds from your account (subject to sufficient balance).\n"
    "3 - Check Balance: View the current balance in your account.\n"
    "4 - New Pin: Change your current pin.\n"
    "5 - Exit: End your session with the bank system.\n"
    "Please enter your choice: ";
   while(x != 5){
        
    cin>> x;
    if (cin.fail()) {
            cout << "Error: Please enter a valid number!" << endl;

            // Clear the error state
            cin.clear();

            // Ignore the invalid input from the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Skip the rest of the loop and prompt for input again
        }
    switch (x)
    {
    case 1:
        int n;
        cout<< "enter amount you want to deposit ";
        cin>> n;

        ATM.setAmount(n);
        cout<< "You deposited "<< n<< " Rs"<<endl;
        ATM.getAmount();
       

        break;
    
    case 2:
        int m;

        cout<< "enter the amount you want to withdraw ";
        cin>> m;
       
        ATM.withdraw(m);
        

        break;

    case 3:
        ATM.getAmount();
        break;

    case 4:
        int newPin;
        cout<< "enter the new pin ";
        cin>> newPin;
        ATM.setPin(newPin);
        break;
    case 5:
        cout<< "Thank you for using Our Bank! Have a great day ahead! "<<endl;
        break;
    default:
        cout<< "Visit Again!!! ";

    }
    if (x != 5) {
            cout<< "\n\n";
            cout << "What do you want to do now?\n"
                 << "1 - Deposit Money: Add funds to your account.\n"
                 << "2 - Withdraw Money: Take out funds from your account (subject to sufficient balance).\n"
                 << "3 - Check Balance: View the current balance in your account.\n"
                 << "4- set Pin. \n"
                 << "5 - Exit: End your session with the bank system.\n"
                 << "Please enter your choice: ";
     
        }
   }
   cout<< "Visit Again!!!! ";
    }

