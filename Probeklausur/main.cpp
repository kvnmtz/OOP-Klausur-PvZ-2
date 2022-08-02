#include <iostream>

#include "engineerzombie.h"
#include "garden.h"
#include "plant.h"
#include "random.hpp"

int main()
{
    Random::Initialize();

    const auto garden = new CGarden();

    const auto rod = new CEngineerZombie(*garden, 100, CPosition(1, 1), ELightSensitivity::Diurnal, true, true);
    const auto plant1 = new CPlant(*garden, CPosition(2, 5));
    const auto plant2 = new CPlant(*garden, CPosition(3, 2));
    const auto plant3 = new CPlant(*garden, CPosition(6, 3));

    garden->AddEntityToGarden(*rod);
    garden->AddEntityToGarden(*plant1);
    garden->AddEntityToGarden(*plant2);
    garden->AddEntityToGarden(*plant3);

    garden->Render();

    rod->FireWeapon(plant2->GetPosition());

    const auto nearestPlant = rod->SearchNearestPlant();
    if (nearestPlant)
    {
        const auto nearestPlantPos = nearestPlant->GetPosition();
        std::cout << "Nächste Pflanze (zu Rod) steht auf: " << nearestPlantPos.X << ", " << nearestPlantPos.Y << std::endl;
    }
    else
    {
        std::cout << "Rod hat keine Pflanzen gefunden!" << std::endl;
    }

    delete rod;
    delete plant1;
    delete plant2;
    delete plant3;

    delete garden;
}
