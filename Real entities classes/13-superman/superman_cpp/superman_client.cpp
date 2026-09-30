//C++ Class for Superman Character
//SUPERMAN CLIENT
#include <iostream>
#include "superman_interface.hpp"

int main(void){
    Superman* newSuperman = new Superman;

    newSuperman->showCharacteristics();

    newSuperman->setCharacteristics
    (
        "Red",
        "Super Strength",
        "Fast",
        "Wonder Women",
        "Krypton",
        true,
        false,
        2
    );

    newSuperman->showCharacteristics();

    return 0;
}

