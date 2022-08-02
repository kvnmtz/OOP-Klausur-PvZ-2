// ReSharper disable CppClangTidyCppcoreguidelinesSpecialMemberFunctions
#pragma once
#include "entity.h"
#include "position.h"

class CPlant;
class CToolFacet;
class CVeganFacet;

/* Nur "enum" (anstatt "enum class") reicht auch, gibt bei mir nur ne Warnung */
enum class ELightSensitivity
{
	/* Tagaktiv */
	Diurnal,
	/* Dämmerungsaktiv */
	Crepuscular,
	/* Nachtaktiv */
	Nocturnal
};

class CZombie : public CEntity
{
	int HealthPoints;
	// (Position in CEntity deklariert)
	ELightSensitivity Sensitivity;

	/* Komposition Werkzeug- und Veganerzombies */
	CToolFacet* ToolFacet = nullptr;
	CVeganFacet* VeganFacet = nullptr;

public:
	CZombie(CGarden& garden, int hp, CPosition pos, ELightSensitivity sensitivity, bool hasTools = false, bool isVegan = false);

	/* Destruktor um Komposition umzusetzen */
	/* "virtual" muss hier nicht hin aber gibt sonst ne Warnung */
	virtual ~CZombie();

	int GetHP() const;

	ELightSensitivity GetLightSensitivity() const;

	void SetHP(int hp);

	virtual bool FireWeapon(CPosition targetPos) = 0;

	CPlant* SearchNearestPlant() const;
};
