
#include <stdlib.h>
#include"PowerPlantCollection.h"
#include "ProgramMenu.h"
#include <Windows.h>

#define RESET "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033;35m"
#define CYAN "\033;36m"
#define WHITE "\033;37m"

using namespace std;


int main()
{
    
    cout << GREEN <<"                    -------------------------------------------------------------------------------" << endl << endl;
    
    cout << "                                              University of Ruhuna" << endl;
    cout << "                                             Faculty of Engineering" << endl;
    cout << "                                 Department of Electrical and Information Enginerring" << endl;
    cout << "                                      EE 3302 - Data Structures and Algorithms" << endl << endl;
    
    cout << "                    -------------------------------------------------------------------------------" <<RESET<< endl << endl;
    

    PowerPlantCollection rawData;

    Menu(rawData);

    return 0; 

} 

