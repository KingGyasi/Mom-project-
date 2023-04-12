#include <iostream>


using namespace std;

int main() {
    const string defaultPIN = "0000";
    const float defaultBalance = 1000;
    string pin;
    int balance = defaultBalance;
    int attempts = 0;
    int menuSelection;
    int amount;
    string PhoneNumber;
    string newPin;
    bool isAuthenticated = false;

    //function for Ask user for pin code
    while(!isAuthenticated && attempts < 3){
    	cout << "Please enter your PIN\n ";
    	cin >> pin;

    if(pin == defaultPIN) {
    isAuthenticated = true;
    } else{
    attempts++;
    cout << "Wrong pin, please try again." << endl;
    }
}

    //function for Menu is displayed only if user is authenticated
    if(isAuthenticated){
        do{
    	cout << endl
        << "1. Check balance" << endl
        << "2. Send money" << endl
        << "3. Change/reset PIN" << endl
        << "4. Exit" << endl;

    cout << "Select an option: ";
    cin >> menuSelection;

		
	 switch(menuSelection){

    
     // function for Checking balance
    case 1:
    cout << "Your current balance is: " << balance << endl;
    break;

    // function for Sending money
    case 2:
    cout<<"Enter  Phone number\n ";
    cin >> PhoneNumber;
    while(PhoneNumber.size() != 10){
        cout <<"Invalid number"<<endl;
        cout <<"Re-enter phone number\n ";
        cin >> PhoneNumber;
    } 
    cout << "Enter amount to send: ";
    cin >> amount;
    if(amount <= balance){
    	cout <<"Transaction successfully"<<endl;
    	
    	 balance = balance - amount;
    	 cout << "Your balance is " << balance;
    }

 	else {
    cout << "Insufficient funds." << endl;
    }
    
    break;

    // function for Changing/resetting PIN
    case 3:
    cout << "Enter new PIN\n ";
     cin >> newPin;
    if(newPin.size() != 4){
        cout<<"Invalid pin"<<endl;
        cout<<"Re-enter pin: ";
        cin >> newPin;
    }
    else{
    	
    pin = newPin;
    cout << "Your PIN has been successfully reset." << endl;
    break;
}
    //function for Exiting the program
    case 4:
    cout << "Exiting program..." << endl;
    break;

    //  function for Invalid selection
    default:
    cout << "Invalid selection." << endl;
    }
	  } while (menuSelection != 4);
	  
	  // Exit program if user is not authenticated after 3 attempts
    } else { 
        cout << "Attempts Exceeded. Exiting program..." << endl;
    }
    return 0;
}

    