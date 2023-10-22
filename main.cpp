#include "classes.h"
#include <Windows.h>

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);

	Equip equipKit1("AK-47", "P7", "6B33");
	Equip equipKit2("VAL", "6B43", "6B33-M");

	Soldier soldier1("Музыкант", 1, equipKit1);
	Soldier soldier2("Ястреб", 2, equipKit2);
	Soldier soldier3("Мужик", 3, equipKit1);
	std::vector<Soldier> soldiersList = { soldier1, soldier2 };

	Troop troop1(1, "Пехотная", 2, soldiersList);

	troop1.printTroop();
	troop1.addSoldier(soldier3);
	std::cout << "Взвод после добавления:" << std::endl;
	troop1.printTroop();

	troop1.deleteSoldier();
	std::cout << "Взвод после удаления:" << std::endl;
	troop1.printTroop();

}














//#include "structs.h"
//#include <Windows.h>
//int main() {
//	setlocale(0, "");
//	SetConsoleCP(1251);
//	equip ratnik = initEquip("жж", "см", "eqw");
//	soldier soldat1 = initSoldier("жж", 1, ratnik);
//	soldier soldat2 = initSoldier("шфышоа", 2, ratnik);
//	soldier soldati[2] = { soldat1, soldat2 };
//	troop vzvod1 = initTroop(1, "пехта", 2, soldati);
//	troop vzvod2 = initTroop(2, "мото", 2, soldati);
//	troop vzvodi[2] = { vzvod1, vzvod2 };
//
//	company rota1 = initCompany(1, "неважно", 2, vzvodi);
//	company rota2 = initCompany(2, "для теста", 2, vzvodi);
//	company roti[2] = { rota1, rota2 };
//
//	battalion batt1 = initBattalion(1, "ыпав", 2, roti);
//	printBattalion(batt1);
//	
//	battalion batt2 = changeCompaniesList(batt1);
//
//	printBattalion(batt2);
//}