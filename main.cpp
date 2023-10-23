//#include "classes.h"
#include "structs.h"
#include <Windows.h>

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);

    //Тестирование классов
 
    ////Создание экземпляров классов с помощью конструкторов
    //Equip equip1("AK-47", "P7", "6B11-M");
    //
    //Soldier soldier1("Музыкант", 1, equip1);
    //std::vector<Soldier> soldiers_list = { soldier1 };

    //Troop troop1(1, "Пехота", 1, soldiers_list);
    //std::vector<Troop> troops_list = { troop1 };

    //Company company1(1, "Пехота", 1, troops_list);
    //std::vector<Company> companies_list = { company1 };

    //Battalion battalion1(1, "Пехота", 1, companies_list);

    //std::cout << "---------------Constructor Test------------------" << std::endl;
    //battalion1.printBattalion();

    ////Тестирование методов класса Equip
    //std::cout << "---------------Equip Test------------------" << std::endl;
    //equip1.createEquipKit();
    //equip1.printEquipKit();

    ////Тестирование методов класса Soldier
    //std::cout << "---------------Soldier Test------------------" << std::endl;
    //soldier1.createSoldier();
    //soldier1.printSoldier();

    ////Тестирование методов класса Troop
    //std::cout << "---------------Troop Test------------------" << std::endl;
    //troop1.createTroop();
    //std::cout << "Информация о взводе после создания" << std::endl;
    //troop1.printTroop();

    //troop1.addSoldier(soldier1);
    //std::cout << "Информация о взводе после добавления солдата soldier1:" << std::endl;
    //troop1.printTroop();

    //std::cout << "Список солдат для тестирования метода удаления солдата:" << std::endl;
    //troop1.deleteSoldier();
    //std::cout << "Информация о взводе после удаления солдата:" << std::endl;
    //troop1.printTroop();

    ////Тестирование методов класса Company
    //std::cout << "---------------Company Test------------------" << std::endl;
    //company1.createCompany();
    //std::cout << "Информация о роте после создания:" << std::endl;
    //company1.printCompany();

    //company1.addTroop(troop1);
    //std::cout << "Информация о роте после добавления взвода troop1:" << std::endl;
    //company1.printCompany();

    //std::cout << "Список взводов для тестирования метода удаления взвода" << std::endl;
    //company1.deleteTroop();
    //std::cout << "Информация о роте после удаления взвода:" << std::endl;
    //company1.printCompany();
    //
    ////Тестирование методов класса Battalion
    //std::cout << "---------------Battalion Test------------------" << std::endl;
    //battalion1.createBattalion();
    //std::cout << "Информация о батальоне после создания:" << std::endl;
    //battalion1.printBattalion();

    //battalion1.addCompany(company1);
    //std::cout << "Информация о батальоне после добавления роты company1:" << std::endl;
    //battalion1.printBattalion();

    //std::cout << "Список рот для тестирования метода удаления роты" << std::endl;
    //battalion1.deleteCompany();
    //std::cout << "Информация о батальоне после удаления роты:" << std::endl;
    //battalion1.printBattalion();



    // Тестирование функций инициализации структур
    equip equip1 = initEquip("AK-47", "P7", "6B33");

    soldier soldier1 = initSoldier("Крутой", 123, equip1);
    soldier soldiers[] = { soldier1 }; 

    troop troop1 = initTroop(1, "Пехота", 1, soldiers);
    troop troops[] = { troop1 }; 

    company company1 = initCompany(1, "Пехота", 1, troops);
    company companies[] = { company1 }; 

    battalion battalion1 = initBattalion(1, "Пехота", 1, companies);

    // Печать структур
    printf("\nСнаряжение после инициализации:\n");
    printEquip(equip1);

    printf("\nСолдат после инициализации:");
    printSoldier(soldier1);

    printf("\nВзвод после инициализации:\n");
    printTroop(troop1);

    printf("\nРота после инициализации:");
    printCompany(company1);

    printf("\nБаттальон после инициализации:");
    printBattalion(battalion1);

    // Изменение списков
    printf("\nТестирование функции изменения взвода:\n");
    troop changedTroop = changeSoldiersList(troop1);
    printTroop(changedTroop);

    printf("\nТестирование функции изменения роты:\n");
    company changedCompany = changeTroopsList(company1);
    printCompany(changedCompany);

    printf("\nТестирование функции изменения баттальона:\n");
    battalion changedBattalion = changeCompaniesList(battalion1);
    printBattalion(changedBattalion);

}
