#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//calculate and load defense matrix
float matrix_power(int botsPower[], int botsCount, float bossPower);

//determines missile power based off of individual bot power
template <typename T>
T single_missile_power(T botPower);

//sets defenseMatrix to the higher value
void load_dva(float& defenseMatrix, float matrixPowerRequired);

//calculates possible required micro missiles, then loads the higher value into microMissiles
void load_dva(int& microMissiles, float missilePowerRequired);




int main(){
    //open file
    ifstream combatFile("combat.txt");
    //check if file open
    if (!combatFile.is_open()){
        cout << "combat.txt failed to open" << endl;
    return 0;
    }
    
    //read bots count into int
    int botsCount;
    combatFile >> botsCount;

    //read bots power into int array
    int botsPower[botsCount];
    for(int i=0; i < botsCount; i++){
        combatFile >> botsPower[i];
    }

    //read boss power into float
    float bossPower;
    combatFile >> bossPower;

    //load default micro missile and defense matrix values into int and float
    int microMissiles;
    combatFile >> microMissiles;
    float defenseMatrix;
    combatFile >> defenseMatrix;

    //close combat file when done reading data
    combatFile.close();


    //determines requred matrix power; load into variable
    float matrixPowerRequired = matrix_power(botsPower, botsCount, bossPower);

    //determines required missile power; load into variable
    float missilePowerRequired = 0.0;
    for(int i = 0; i < botsCount; i++){
        missilePowerRequired += single_missile_power(botsPower[i]);
    }
    missilePowerRequired += single_missile_power(bossPower);

    //sets the value of defense matrix
    load_dva(defenseMatrix, matrixPowerRequired);

    //sets the number of micro missiles
    load_dva(microMissiles, missilePowerRequired);


    //create new file for report
    ofstream reportFile("report.txt");
    //check to see if report is open
    if (!reportFile.is_open()){
        cout << "report.txt failed to open" << endl;
    return 0;
    }

    //write data to file
    reportFile << "D.Va's Combat Report\n";
    reportFile << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << bossPower << "." << endl;
    reportFile << "Loaded mech with " << microMissiles << " micro missiles and the defense matrix with power " << defenseMatrix << "." << endl;
    reportFile << "Ready for combat!";

    //close report afterwards just in case
    reportFile.close();

    return 0;
}




//calculate and load defense matrix
float matrix_power(int botsPower[], int botsCount, float bossPower){
    float damageSum;
    for(int i = 0; i < botsCount; i++){
        damageSum += botsPower[i];
    }
    damageSum += bossPower;

    return damageSum;
};

//determines missile power based off of individual bot power
template <typename T>
T single_missile_power(T botPower){

    if (botPower <= 15){
        return 2 * botPower;
    }
    else{
        return 5 * botPower;
    }
};

//sets defenseMatrix to the higher value
void load_dva(float& defenseMatrix, float matrixPowerRequired){
    if (defenseMatrix < matrixPowerRequired){
        defenseMatrix = matrixPowerRequired;
    }
};

//calculates possible required micro missiles, then loads the higher value into microMissiles
void load_dva(int& microMissiles, float missilePowerRequired){
    if (microMissiles < ceil(missilePowerRequired/60)){
    microMissiles = ceil(missilePowerRequired/60);
    }
};