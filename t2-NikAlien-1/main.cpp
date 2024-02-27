//
// Created by Carp Nicoleta on 11.05.2023.
//


#include "Service.h"
#include "UI.h"

int main()
{
    Service s;
    UI ui(&s);

    ui.start();
}