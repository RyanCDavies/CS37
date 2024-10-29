#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Battle{
    friend class Mech;
    private:
        int botsPower[10];
        int botsCount;
        float bossPower;

    public:
        Battle(int botsPower, int botsCount, float bossPower);
        float matrix_power();
};

class Mech{
    private:
        int microMissiles;
        float defenseMatrix;

    public:
        Mech();

        void load(float matrixPowerRequired, float missilePowerRequired);
        float micro_missile(Battle dvaBattle);
        int get_missiles();
        float get_matrix();
};  


int main() {
//open file
ifstream combatFile("combat.txt");
//check if file open
if (!combatFile.is_open()){
    cout << "combat.txt failed to open" << endl;
    return 0;
}
int botsCount;
combatFile >> botsCount;

//read bots power into array
int botsPower[botsCount];
    for(int i=0; i < botsCount; i++){
        combatFile >> botsPower[i];
    }

 //read boss power into float
float bossPower;
combatFile >> bossPower;

//Initialize battle and dva
Battle dvaBattle(botsPower[botsCount], botsCount, bossPower);
Mech dva;

//Calculate power needed
float matrixPowerRequired = dvaBattle.matrix_power();
float missilePowerRequired = dva.micro_missile(dvaBattle);

//Load D.Va
dva.load(matrixPowerRequired, missilePowerRequired);

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
reportFile << "Loaded mech with " << dva.get_missiles() << " micro missiles and the defense matrix with power " << dva.get_matrix() << "." << endl;
reportFile << "Ready for combat!";

//close report afterwards just in case
reportFile.close();

return 0;
}

Battle::Battle(int botsPower, int botsCount, float bossPower){
    this->bossPower = bossPower;
    this->botsCount = botsCount;
    this->botsPower[10] = botsPower;
}

Mech::Mech(){
    int microMissiles = 10;
    float defenseMatrix = 100.0;
}

void Mech::load(float matrixPowerRequired, float missilePowerRequired){
    if (this->defenseMatrix < matrixPowerRequired){
        this->defenseMatrix = matrixPowerRequired;
    }
}

float Battle::matrix_power(){
    int sum = 0;
    for (int i; botsCount; i++){
        sum += botsPower[i];
    }
    sum += bossPower;
    return sum;
}

float Mech::micro_missile(Battle dvaBattle){
    int sum = 0;
    for (int i; dvaBattle.botsCount; i++){
        sum += dvaBattle.botsPower[i];
    }
    if (microMissiles < 5*dvaBattle.bossPower + 2*sum){
        return 5*dvaBattle.bossPower + 2*sum;
    }
    return microMissiles;
}

int Mech::get_missiles(){
    return microMissiles;
}

float Mech::get_matrix(){
    return defenseMatrix;
}