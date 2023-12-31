#define _CRT_SECURE_NO_WARNINGS
#define LEN 32
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <vector>


class Equip {

private:

	std::string weaponName;
	std::string helmetName;
	std::string armorName;

public:

	Equip() = default;

	Equip(
		std::string setWeaponName,
		std::string setHelmetName,
		std::string setArmorName
	) {
		weaponName = setWeaponName;
		helmetName = setHelmetName;
		armorName = setArmorName;
	}

	void setWeaponName(
		std::string newWeaponName
	) {
		weaponName = newWeaponName;
	}

	void setHelmetName(
		std::string newHelmetName
	) {
		helmetName = newHelmetName;
	}

	void setArmorName(
		std::string newArmorName
	) {
		armorName = newArmorName;
	}

	std::string getWeaponName() {
		return weaponName;
	}

	std::string getHelmetName() {
		return helmetName;
	}

	std::string getArmorName() {
		return armorName;
	}

	void createEquipKit() {
		std::string weaponNameStorage;
		std::string helmetNameStorage;
		std::string armorNameStorage;

		std::cout << "������� ������� ����������:" << std::endl;
		std::cout << std::endl;

		std::cout << "������� �������� ������: ";
		std::cin >> weaponNameStorage;
		std::cout << std::endl;

		std::cout << "������� �������� ����������: ";
		std::cin >> helmetNameStorage;
		std::cout << std::endl;


		std::cout << "������� �������� �����������: ";
		std::cin >> armorNameStorage;
		std::cout << std::endl;

		weaponName = weaponNameStorage;
		helmetName = helmetNameStorage;
		armorName = armorNameStorage;

	}

	void printEquipKit() {
		std::cout << "������: " << weaponName << std::endl;
		std::cout << "���������: " << helmetName << std::endl;
		std::cout << "����������: " << armorName << std::endl;
		std::cout << std::endl;
	}
};

class Soldier {

private:

	std::string callSign;
	int equipNumber;
	Equip equipKit;

public:

	Soldier() = default;

	Soldier(
		std::string setCallSign,
		int setEquipNumber,
		Equip setEquipKit
	) {
		callSign = setCallSign;
		equipNumber = setEquipNumber;
		equipKit = setEquipKit;
	}

	void setCallSign(
		std::string newCallSign
	) {
		callSign = newCallSign;
	}

	void setNewEquip(
		int newEquipNumber,
		Equip newEquipKit
	) {
		equipNumber = newEquipNumber;
		equipKit = newEquipKit;
	}

	std::string getCallSign() {
		return callSign;
	}

	int getEquipNumber() {
		return equipNumber;
	}

	Equip getEquipKit() {
		return equipKit;
	}

	void createSoldier() {
		std::string callSignStorage;
		int equipNumberStorage;
		Equip equipKitStorage;

		std::cout << "������� �������� �������: ";
		std::cin >> callSignStorage;
		std::cout << std::endl;

		std::cout << "������� ����� ��������� ����������: ";
		std::cin >> equipNumberStorage;
		std::cout << std::endl;

		equipKitStorage.createEquipKit();

		callSign = callSignStorage;
		equipNumber = equipNumberStorage;
		equipKit = equipKitStorage;

	}

	void printSoldier() {
		std::cout << "�������� �������: " << callSign << std::endl;
		std::cout << "����� ��������� ����������: " << equipNumber << std::endl;
		std::cout << "�������� ����������: " << std::endl;
		equipKit.printEquipKit();
	}

};

class Troop {

private:

	int troopNumber;
	std::string troopType;
	int soldiersCount;
	std::vector<Soldier> soldiersList;

public:

	Troop() = default;

	Troop(
		int setTroopNumber,
		std::string setTroopType,
		int setSoldiersCount,
		std::vector<Soldier> setSoldiersList
	) {
		troopNumber = setTroopNumber;
		troopType = setTroopType;
		soldiersCount = setSoldiersCount;
		soldiersList = setSoldiersList;

	}

	void setTroopNumber(
		int newTroopNumber
	) {
		troopNumber = newTroopNumber;
	}

	void setTroopType(
		std::string newTroopType
	) {
		troopType = newTroopType;
	}

	void setSoldiersList(
		int newSoldiersCount,
		std::vector<Soldier> newSoldiersList
	) {
		soldiersCount = newSoldiersCount;
		soldiersList = newSoldiersList;
	}

	int getTroopNumber() {
		return troopNumber;
	}

	std::string getTroopType() {
		return troopType;
	}

	int getSoldiersCount() {
		return soldiersCount;
	}

	std::vector<Soldier> getSoldiersList() {
		return soldiersList;
	}

	void createTroop() {

		int troopNumberStorage;
		std::string troopTypeStorage;
		int soldiersCountStorage;
		std::vector<Soldier> soldiersListStorage;
		Soldier soldierDataStorage;

		std::cout << "������� ����� ������: ";
		std::cin >> troopNumberStorage;
		std::cout << std::endl;

		std::cout << "������� ��� ������: ";
		std::cin >> troopTypeStorage;
		std::cout << std::endl;

		std::cout << "������� ���������� ������ �� ������: ";
		std::cin >> soldiersCountStorage;
		std::cout << std::endl;

		for (int i = 0; i < soldiersCountStorage; i++) {
			soldierDataStorage.createSoldier();
			soldiersListStorage.push_back(soldierDataStorage);
		}

		troopNumber = troopNumberStorage;
		troopType = troopTypeStorage;
		soldiersCount = soldiersCountStorage;
		soldiersList = soldiersListStorage;

	}

	void printTroop() {

		std::cout << "����� ������: " << troopNumber << std::endl;
		std::cout << "��� ������: " << troopType << std::endl;
		std::cout << "���������� ������ �� ������: " << soldiersCount << std::endl;
		std::cout << "������ ������: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < soldiersCount; i++) {
			soldiersList[i].printSoldier();
		}
	}

	void addSoldier(Soldier soldierDataStorage) {
		soldiersCount++;
		soldiersList.push_back(soldierDataStorage);
	}

	void deleteSoldier() {
		int deleteSoldierNumber;

		std::cout << "������ ������: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < soldiersCount; i++) {
			std::cout << "������ " << i + 1 << ":" << std::endl;
			soldiersList[i].printSoldier();
		}

		std::cout << "������� ����� �������, �������� ������ �������:" << std::endl;
		do {

			std::cin >> deleteSoldierNumber;

			if (deleteSoldierNumber > soldiersCount) {
				std::cout << "������� � ����� ������� �� ����������. ��������� ����" << std::endl;
			}
		} while (deleteSoldierNumber > soldiersCount);
		soldiersList.erase(soldiersList.begin() + deleteSoldierNumber - 1);
		soldiersCount--;
	}
};

class Company {

private:

	int companyNumber;
	std::string companyType;
	int troopsCount;
	std::vector<Troop> troopsList;

public:

	Company() = default;

	Company(
		int setCompanyNumber,
		std::string setCompanyType,
		int setTroopsCount,
		std::vector<Troop> setTroopsList
	) {
		companyNumber = setCompanyNumber;
		companyType = setCompanyType;
		troopsCount = setTroopsCount;
		troopsList = setTroopsList;
	}

	void setCompanyNumber(
		int newCompanyNumber
	) {
		companyNumber = newCompanyNumber;
	}

	void setCompanyType(
		std::string newCompanyType
	) {
		companyType = newCompanyType;
	}

	void setTroopsList(
		int newTroopsCount,
		std::vector<Troop> newTroopsList
	) {
		troopsCount = newTroopsCount;
		troopsList = newTroopsList;
	}

	void createCompany(){

		int companyNumberStorage;
		std::string companyTypeStorage;
		int troopsCountStorage;
		std::vector<Troop> troopsListStorage;
		Troop troopDataStorage;

		std::cout << "������� ����� ����: ";
		std::cin >> companyNumberStorage;
		std::cout << std::endl;

		std::cout << "������� ��� ����: ";
		std::cin >> companyTypeStorage;
		std::cout << std::endl;

		std::cout << "������� ���������� ������� � ����: ";
		std::cin >> troopsCountStorage;
		std::cout << std::endl;

		for (int i = 0; i < troopsCountStorage; i++) {
			troopDataStorage.createTroop();
			troopsListStorage.push_back(troopDataStorage);
		}

		companyNumber = companyNumberStorage;
		companyType = companyTypeStorage;
		troopsCount = troopsCountStorage;
		troopsList = troopsListStorage;
	}

	void printCompany() {

		std::cout << "����� ����: " << companyNumber << std::endl;
		std::cout << "��� ����: " << companyType << std::endl;
		std::cout << "���������� ������� � ����: " << troopsCount << std::endl;
		std::cout << "������ �������: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < troopsCount; i++) {
			troopsList[i].printTroop();
		}
	}

	void addTroop(Troop troopDataStorage) {
		troopsCount++;
		troopsList.push_back(troopDataStorage);
	}

	void deleteTroop() {
		int deleteTroopNumber;

		std::cout << "������ �������: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < troopsCount; i++) {
			std::cout << "����� " << i + 1 << ":" << std::endl;
			troopsList[i].printTroop();
		}

		std::cout << "������� ����� ������, �������� ������ �������:" << std::endl;
		do {

			std::cin >> deleteTroopNumber;

			if (deleteTroopNumber > troopsCount) {
				std::cout << "������� � ����� ������� �� ����������. ��������� ����" << std::endl;
			}
		} while (deleteTroopNumber > troopsCount);
		troopsList.erase(troopsList.begin() + deleteTroopNumber - 1);
		troopsCount--;
	}

};

class Battalion {

private:

	int battalionNumber;
	std::string battalionType;
	int companiesCount;
	std::vector<Company> companiesList;

public:

	Battalion() = default;

	Battalion(
		int setBattalionNumber,
		std::string setBattalionType,
		int setCompaniesCount,
		std::vector<Company> setCompaniesList
	) {
		battalionNumber = setBattalionNumber;
		battalionType = setBattalionType;
		companiesCount = setCompaniesCount;
		companiesList = setCompaniesList;
	}

	void setBattalionNumber(
		int newBattalionNumber
	) {
		battalionNumber = newBattalionNumber;
	}

	void setBattalionType(
		std::string newBattalionType
	) {
		battalionType = newBattalionType;
	}

	void setCompaniesList(
		int newCompaniesCount,
		std::vector<Company> newCompaniesList
	) {
		companiesCount = newCompaniesCount;
		companiesList = newCompaniesList;
	}

	void createBattalion() {

		int battalionNumberStorage;
		std::string battalionTypeStorage;
		int companiesCountStorage;
		std::vector<Company> companiesListStorage;
		Company companyDataStorage;

		std::cout << "������� ����� ���������: ";
		std::cin >> battalionNumberStorage;
		std::cout << std::endl;

		std::cout << "������� ��� ���������: ";
		std::cin >> battalionTypeStorage;
		std::cout << std::endl;

		std::cout << "������� ���������� ��� � ���������: ";
		std::cin >> companiesCountStorage;
		std::cout << std::endl;

		for (int i = 0; i < companiesCountStorage; i++) {
			companyDataStorage.createCompany();
			companiesListStorage.push_back(companyDataStorage);
		}

		battalionNumber = battalionNumberStorage;
		battalionType = battalionTypeStorage;
		companiesCount = companiesCountStorage;
		companiesList = companiesListStorage;
	}

	void printBattalion() {

		std::cout << "����� ���������: " << battalionNumber << std::endl;
		std::cout << "��� ���������: " << battalionType << std::endl;
		std::cout << "���������� ��� � ���������: " << companiesCount << std::endl;
		std::cout << "������ ���: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < companiesCount; i++) {
			companiesList[i].printCompany();
		}
	}

	void addCompany(Company companyDataStorage) {
		companiesCount++;
		companiesList.push_back(companyDataStorage);
	}

	void deleteCompany() {
		int deleteCompanyNumber;

		std::cout << "������ ���: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < companiesCount; i++) {
			std::cout << "���� " << i + 1 << ":" << std::endl;
			companiesList[i].printCompany();
		}

		std::cout << "������� ����� ����, ������� ������ �������:" << std::endl;
		do {

			std::cin >> deleteCompanyNumber;

			if (deleteCompanyNumber > companiesCount) {
				std::cout << "���� � ����� ������� �� ����������. ��������� ����" << std::endl;
			}
		} while (deleteCompanyNumber > companiesCount);
		companiesList.erase(companiesList.begin() + deleteCompanyNumber - 1);
		companiesCount--;
	}

};