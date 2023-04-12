#include <iostream>
using namespace std;

const int DEFAULT_BALANCE = 1000;
const string DEFAULT_PIN = "0000";
const int MAX_WRONG_PIN_ATTEMPTS = 3;

class MobileMoneyService {
private:
    int balance_;
    string pin_;
    int wrong_pin_attempts_;

public:
    MobileMoneyService() : balance_(DEFAULT_BALANCE), pin_(DEFAULT_PIN), wrong_pin_attempts_(0) {}

    bool authenticate(string entered_pin) {
        if (entered_pin == pin_) {
        wrong_pin_attempts_ = 0;
    return true;
        } else {
        wrong_pin_attempts_++;
        if (wrong_pin_attempts_ >= MAX_WRONG_PIN_ATTEMPTS) {
        cout << "Too many wrong pin attempts. Exiting program." << endl;
    return false;
    }   else {
        cout << "Incorrect pin. Try again." << endl;
    return false;
    }
    }
    }

    void reset_pin(string new_pin) {
        pin_ = new_pin;
        cout << "Pin successfully changed." << endl;
    }

    void check_balance() {
        cout << "Your current balance is: $" << balance_ << endl;
}

    void send_money(int amount) {
    if (balance_ < amount) {
        cout << "Insufficient funds. Transaction failed." << endl;
} 
	else {
    balance_ -= amount;
        cout << "Transaction successful. " << "$"<< amount << " was sent." << endl;
}
}

    void buy_airtime(int amount) {
    if (balance_ < amount) {
        cout << "Insufficient funds. Transaction failed." << endl;
}
    else {
    balance_ -= amount;
        cout << "Airtime purchased successfully. " <<"$"<< amount << " was deducted." << endl;
}
    }
};

int main() {
    MobileMoneyService service;
    string pin;

    while (true) {
        cout << "Enter pin: ";
        cin >> pin;

    if (service.authenticate(pin)) {
    int option;
        cout << "                 MTN MOBILE MONEY SYSTEM" << endl;
        cout << "..............................................................." << endl;
        cout << "\t\t       Menu" << endl;
		cout << "\t\t 1. Reset pin" << endl;
        cout << "\t\t 2. Check balance" << endl;
        cout << "\t\t 3. Send money" << endl;
        cout << "\t\t 4. Buy airtime/bundle" << endl;
        cout << "\t\t 5. Exit" << endl;
        cout << "..............................................................." << endl;
        cout << "Enter option:  ";
        cin >> option;

    switch (option) {
    case 1: {
    string new_pin;
        cout << "Enter new pin: ";
        cin >> new_pin;
    service.reset_pin(new_pin);
    break;
}
    case 2: {
    service.check_balance();
    break;
}
    case 3: {
    int amount, number, confirm_number;
        cout << "Enter recipient Number:  ";
        cin >>number;
        cout << "Confirm Number:  ";
        cin >> confirm_number;
    if (number==confirm_number){
        cout << "Enter amount to send:  $";
        cin >> amount;
        service.send_money(amount);
    break;
}
    else{
        cout << "Number Mismatch. Please try again"<< endl;	
}
}
    case 4: {
    int airtime_amount, no, r_no;
        cout << " \t\t 1. Self" << endl;
        cout << " \t\t 2. Others" << endl;
        cout << "Enter Choice:  ";
        cin >> no;
    if (no ==1){
		cout << "Enter amount to buy airtime/bundle:  $";                
		cin >> airtime_amount;
    service.buy_airtime(airtime_amount);
    break;
}   	
	else if (no == 2){
        cout << "Enter recipient Number:  ";
        cin >> r_no;
        cout << "Enter amount to buy airtime/bundle:  $";                    
	    cin >> airtime_amount;
    service.buy_airtime(airtime_amount);
    break;
}                
	else{
        cout << "Invalid choice"<< endl;	
}
                    
               
}
    case 5: {
        cout << "Exiting program." << endl;
return 0;
                }
                default: {
                    cout << "Invalid option. Try again." << endl;
                    break;
                }
            }
        }
    }
}

