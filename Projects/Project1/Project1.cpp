#include <iostream>
#include <iomanip>
#include <string>

//creates struct to hold account data
struct userAccount{
    std::string username;
    std::string nationality;
    int age;
    float accountBalance;
};

int main(){

    //create an array to load accounts into later
    userAccount accounts[20];

    //tell user what data to enter
    std::cout << "Please enter information to database in the format of <username> <nationality> <age> <accountBalance>, separated each user by a newline:\n";

    //define variables for use in the loop
    std::string username;
    std::string nationality;
    int age;
    float accountBalance = 0.0;
    int userCount = 0;

    //gather data from user input and load into array
    while(std::cin >> username >> nationality >> age >> accountBalance){
        //std::cout<< accountBalance << std::endl;
        userAccount user;
        user.username = username;
        user.nationality = nationality;
        user.age = age;
        user.accountBalance = accountBalance;
        accounts[userCount] = user;
        userCount++;
    }

    //find the highest account balance, also sets precision in case of bigger numbers
    std::cout << "Q: What's the highest account balance among all users?" << std::endl;
    float highestBalance = 0;
    for(int i = 0; i <= userCount; i++){
        if(accounts[i].accountBalance > highestBalance){
            highestBalance = accounts[i].accountBalance;
        }
    }
    std::cout << "A: The highest account balance is: $" << std::setprecision(1) << std::fixed << highestBalance << std::endl;

    //sum all the account balances
    std::cout << "\nQ: What's the sum of account balance of all users?\n";
    float accountSum = 0;
    for (int i = 0; i <= userCount; i++){
        accountSum += accounts[i].accountBalance;
    }
    std::cout << "A: The sum of all accounts is $" << std::setprecision(2) << accountSum << std::endl;

    //find whether anyone is swedish
    std::cout << "\nQ: How many users come from Sweden?" << std::endl;
    int swedishUsers = 0;
    for (int i =0; i <= userCount; i++){
        if (accounts[i].nationality == "Swedish"){
            swedishUsers++;
        }
    }
    std::cout << "A: " << swedishUsers << std::endl;

    //find whether there are any users under 21
    std::cout << "\nQ: Do we have any user younger than 21?" << std::endl;
    std::string under21 = "No";
    for(int i = 0; i <= userCount; i++){
        if(accounts[i].age < 21){
            under21 = "Yes";
            break;
        }
    }
    std::cout << "A: " << under21;

    return 0;
}