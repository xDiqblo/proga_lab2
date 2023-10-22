#define _CRT_SECURE_NO_WARNINGS
#define LEN 32
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <iostream>

int inputNumber();
void cleaner();

struct equip {
	char weapon[LEN];
	char helmet[LEN];
	char armor[LEN];
};

struct soldier {
	char call_sign[LEN];
	int equip_number;
	equip equip_set;
};

struct troop {
	int troop_number;
	char troop_type[LEN];
	int soldiers_count;
	struct soldier* soldiers;
};

struct company {
	int company_number;
	char company_type[LEN];
	int troops_count;
	struct troop* troops;
};

struct battalion {
	int battalion_number;
	char battalion_type[LEN];
	int companies_count;
	struct company* companies;
};

//������������� ��������
equip initEquip(
	const char weapon[LEN],
	const char helmet[LEN],
	const char armor[LEN]
) {
	equip data;
	strcpy(data.weapon, weapon);
	strcpy(data.helmet, helmet);
	strcpy(data.armor, armor);
	return data;
}

soldier initSoldier(
	const char call_sign[LEN],
	int equip_number,
	equip& set
) {
	soldier data;
	strcpy(data.call_sign, call_sign);
	data.equip_number = equip_number;
	data.equip_set = set;
	return data;
}

troop initTroop(
	int troop_number,
	const char troop_type[LEN],
	int soldiers_count,
	soldier* soldiers
) {
	troop data;
	data.troop_number = troop_number;
	strcpy(data.troop_type, troop_type);
	data.soldiers_count = soldiers_count;
	data.soldiers = soldiers;
	return data;
}

company initCompany(
	int company_number,
	const char company_type[LEN],
	int troops_count,
	troop* troops
) {
	company data;
	data.company_number = company_number;
	strcpy(data.company_type, company_type);
	data.troops_count = troops_count;
	data.troops = troops;
	return data;
}

battalion initBattalion(
	int battalion_number,
	const char battalion_type[LEN],
	int companies_count,
	company* companies
) {
	battalion data;
	data.battalion_number = battalion_number;
	strcpy(data.battalion_type, battalion_type);
	data.companies_count = companies_count;
	data.companies = companies;
	return data;
}

//���� ��������
equip inputEquip() {
	equip equip_data;
	const char* WEAPONS[LEN] = { "AK-47", "AK-74", "ABAKAN", "RPK", "VAL", "PECHENEG" };
	const char* HELMETS[LEN] = { "P7", "6B7-1M", "SSH-68M", "6B47" };
	const char* ARMORS[LEN] = { "6B33", "6B11-3", "6B43", "6B45" };

	char data_string[LEN];
	int flag;

	printf("������� ������������ ������ �� ������� ������:\n");
	for (int i = 0; i < 6; i++) {
		printf("%s\n", WEAPONS[i]);
	}
	do {
		gets_s(data_string, LEN);
		flag = 0;
		for (int i = 0; i < 6 && flag == 0; i++) {
			if (strcmp(data_string, WEAPONS[i]) == 0) {
				flag = 1;
			}
		}
	} while (flag == 0 ? printf("�� ����� �������� ������������. ��������� ����:\n") : 0);
	strcpy(equip_data.weapon, data_string);

	printf("\n������� ������������ ����� �� ������� ������:\n");
	for (int i = 0; i < 4; i++) {
		printf("%s\n", HELMETS[i]);
	}
	do {
		gets_s(data_string, LEN);
		flag = 0;
		for (int i = 0; i < 4 && flag == 0; i++) {
			if (strcmp(data_string, HELMETS[i]) == 0) {
				flag = 1;
			}
		}
	} while (flag == 0 ? printf("�� ����� �������� ������������. ��������� ����:\n") : 0);
	strcpy(equip_data.helmet, data_string);

	printf("\n������� ������������ ����������� �� ������� ������:\n");
	for (int i = 0; i < 4; i++) {
		printf("%s\n", ARMORS[i]);
	}
	do {
		gets_s(data_string, LEN);
		flag = 0;
		for (int i = 0; i < 4 && flag == 0; i++) {
			if (strcmp(data_string, ARMORS[i]) == 0) {
				flag = 1;
			}
		}
	} while (flag == 0 ? printf("�� ����� �������� ������������. ��������� ����:\n") : 0);
	strcpy(equip_data.armor, data_string);

	return equip_data;
}

soldier inputSoldier() {
	soldier soldier_data;
	equip set;
	char data_string[LEN];
	int data_number;

	cleaner();
	printf("\n������� �������� �������:\n");
	gets_s(data_string, LEN);
	strcpy(soldier_data.call_sign, data_string);

	printf("\n������� �������� ����� ����������:\n");
	data_number = inputNumber();
	soldier_data.equip_number = data_number;
	set = inputEquip();
	soldier_data.equip_set = set;
	return soldier_data;
}

troop inputTroop() {

	troop troop_data;
	char data_string[LEN];
	int data_number;

	printf("������� ����� ������:\n");
	data_number = inputNumber();
	troop_data.troop_number = data_number;

	printf("������� ��� ������:\n");
	gets_s(data_string, LEN);
	strcpy(troop_data.troop_type, data_string);

	printf("������� ���-�� ������ � ������:\n");
	data_number = inputNumber();
	const int data_count = data_number;
	troop_data.soldiers_count = data_count;

	soldier* soldiers;
	soldiers = (soldier*)calloc(data_number, sizeof(soldier));
	for (int i = 0; i < data_number; i++) {
		soldiers[i] = inputSoldier();
	}
	troop_data.soldiers = soldiers;
	return troop_data;
}

company inputCompany() {
	company company_data;
	char data_string[LEN];
	int data_number;

	printf("������� ����� ����:\n");
	data_number = inputNumber();
	company_data.company_number = data_number;

	printf("������� ��� ����:\n");
	gets_s(data_string, LEN);
	strcpy(company_data.company_type, data_string);

	printf("������� ���-�� ������� � ����:\n");
	data_number = inputNumber();
	const int data_count = data_number;
	company_data.troops_count = data_number;

	troop* troops;
	troops = (troop*)calloc(data_number, sizeof(troop));
	for (int i = 0; i < data_number; i++) {
		troops[i] = inputTroop();
	}
	company_data.troops = troops;
	return company_data;

}

battalion inputBattalion() {
	battalion battalion_data;
	char data_string[LEN];
	int data_number;

	printf("������� ����� ����������:\n");
	data_number = inputNumber();
	battalion_data.battalion_number = data_number;

	printf("������� ��� ����������:\n");
	gets_s(data_string, LEN);
	strcpy(battalion_data.battalion_type, data_string);

	printf("������� ���-�� ��� � ����������:\n");
	data_number = inputNumber();
	const int data_count = data_number;
	battalion_data.companies_count = data_number;

	company* companies;
	companies = (company*)calloc(data_number, sizeof(company));
	for (int i = 0; i < data_number; i++) {
		companies[i] = inputCompany();
	}
	battalion_data.companies = companies;
	return battalion_data;
}
//����� �������� � �������
void printEquip(
	equip& equip_data
) {
	printf("������: %s\n", equip_data.weapon);
	printf("����: %s\n", equip_data.helmet);
	printf("����������: %s\n", equip_data.armor);
}

void printSoldier(
	soldier& soldier_data
) {
	int flag;
	printf("\n��������:%s\n", soldier_data.call_sign);
	printf("�������� ����� ����������:%d\n", soldier_data.equip_number);

	printf("������� ����������� ������ ����������?\n(1) ��\n(2) ���\n");
	do {
		scanf("%d", &flag);
	} while ((flag != 1 && flag != 2) ? printf("�������� �����. ��������� ����:\n") : 0);
	if (flag == 1) {
		printEquip(soldier_data.equip_set);
	}

}

void printTroop(
	troop& troop_data
) {
	int flag;

	printf("\n����� ������: %d\n", troop_data.troop_number);
	printf("\n��� ������: %s\n", troop_data.troop_type);
	printf("������� ����������� ������ ������?\n(1) ��\n(2) ���\n");
	do {
		scanf("%d", &flag);
	} while ((flag != 1 && flag != 2) ? printf("�������� �����. ��������� ����:\n") : 0);
	if (flag == 1) {
		for (int i = 0; i < troop_data.soldiers_count; i++) {
			printSoldier(troop_data.soldiers[i]);
		}
	}

}

void printCompany(
	company& company_data
) {
	int flag;

	printf("\n����� ����: %d\n", company_data.company_number);
	printf("\n��� ����: %s\n", company_data.company_type);
	printf("\n���������� �������: %d\n", company_data.troops_count);
	printf("\n������� ����������� ������ �������?\n(1) ��\n(2) ���\n");
	do {
		scanf("%d", &flag);
	} while ((flag != 1 && flag != 2) ? printf("�������� �����. ��������� ����:\n") : 0);
	if (flag == 1) {
		for (int i = 0; i < company_data.troops_count; i++) {
			printTroop(company_data.troops[i]);
		}
	}
}

void printBattalion(
	battalion& battalion_data
) {
	int flag;

	printf("\n����� ����������: %d\n", battalion_data.battalion_number);
	printf("\n��� ����������: %s\n", battalion_data.battalion_type);
	printf("\n���������� ���: %d\n", battalion_data.companies_count);
	printf("\n������� ����������� ������ ���?\n(1) ��\n(2) ���\n");
	do {
		scanf("%d", &flag);
	} while ((flag != 1 && flag != 2) ? printf("�������� �����. ��������� ����:\n") : 0);
	if (flag == 1) {
		for (int i = 0; i < battalion_data.companies_count; i++) {
			printCompany(battalion_data.companies[i]);
		}
	}
}

//��������� ������ ������(���������� � �������� �������) �� ������
troop changeSoldiersList(troop& data_troop) {
	troop return_troop;
	return_troop.troop_number = data_troop.troop_number;
	strcpy(return_troop.troop_type, data_troop.troop_type);

	soldier* data_soldiers_array;
	int flag;
	printf("��� �������� ������ ������ �� ������?\n(1) �������� �������\n(2) ������� �������\n");
	do {
		scanf("%d", &flag);
	} while ((flag != 1 && flag != 2) ? printf("�������� �����. ��������� ����:\n") : 0);

	if (flag == 1) {
		soldier data_soldier;
		data_soldiers_array = (soldier*)calloc(data_troop.soldiers_count + 1, sizeof(soldier));
		data_soldier = inputSoldier();
		int i;
		for (i = 0; i < data_troop.soldiers_count; i++) {
			data_soldiers_array[i] = data_troop.soldiers[i];
		}
		data_soldiers_array[i] = data_soldier;

		return_troop.soldiers_count = data_troop.soldiers_count + 1;
		return_troop.soldiers = data_soldiers_array;
		printf("������ �������.\n");
	}
	else if (flag == 2) {
		int soldier_number;
		printf("������ ������ �� �� ��������:\n");
		for (int i = 0; i < data_troop.soldiers_count; i++) {
			printf("%d)%s\n", i + 1, data_troop.soldiers[i].call_sign);
		}
		printf("������� ����� �������, �������� ������ ������� �� ������:\n");
		do {
			soldier_number = inputNumber();
		} while ((soldier_number > data_troop.soldiers_count) ? printf("�� ����� �������� �����. ��������� ����:\n") : 0);

		data_soldiers_array = (soldier*)calloc(data_troop.soldiers_count - 1, sizeof(soldier));
		for (int i = 0, j = 0; j < data_troop.soldiers_count - 1; i++, j++) {
			if (i == soldier_number - 1) {
				j--;
			}
			else {
				data_soldiers_array[j] = data_troop.soldiers[i];
			}
		}
		return_troop.soldiers_count = data_troop.soldiers_count - 1;
		return_troop.soldiers = data_soldiers_array;
		printf("������ �������.");
	}
	return return_troop;
}

company changeTroopsList(company& data_company) {
	company return_company;
	return_company.company_number = data_company.company_number;
	strcpy(return_company.company_type, data_company.company_type);

	troop* data_troops_array;
	int flag;
	printf("��� �������� ������ ������� � ����?\n(1) �������� �����\n(2) ������� �����\n");
	do {
		scanf("%d", &flag);
	} while ((flag != 1 && flag != 2) ? printf("�������� �����. ��������� ����:\n") : 0);

	if (flag == 1) {
		troop data_troop;
		data_troops_array = (troop*)calloc(data_company.troops_count + 1, sizeof(troop));
		data_troop = inputTroop();
		int i;
		for (i = 0; i < data_company.troops_count; i++) {
			data_troops_array[i] = data_company.troops[i];
		}
		data_troops_array[i] = data_troop;

		return_company.troops_count = data_company.troops_count + 1;
		return_company.troops = data_troops_array;
		printf("������ �������.\n");
	}

	else if (flag == 2) {
		int troop_number;
		printf("������ �������:\n");
		for (int i = 0; i < data_company.troops_count; i++) {
			printf("%d)%s\n", i + 1, data_company.troops[i].troop_type);
		}
		printf("������� ����� ������, ������� ������ ������� �� ������:\n");
		do {
			troop_number = inputNumber();
		} while ((troop_number > data_company.troops_count) ? printf("�� ����� �������� �����. ��������� ����:\n") : 0);

		data_troops_array = (troop*)calloc(data_company.troops_count - 1, sizeof(troop));
		for (int i = 0, j = 0; j < data_company.troops_count - 1; i++, j++) {
			if (i == troop_number - 1) {
				j--;
				continue;
			}
			data_troops_array[j] = data_company.troops[i];
		}
		return_company.troops_count = data_company.troops_count - 1;
		return_company.troops = data_troops_array;
		printf("������ �������.\n");
	}
	return return_company;
}

battalion changeCompaniesList(const battalion& data_battalion) {
	battalion return_battalion;
	return_battalion.battalion_number = data_battalion.battalion_number;
	strcpy(return_battalion.battalion_type, data_battalion.battalion_type);

	int flag;
	printf("��� �������� ������ ��� � ���������?\n(1) �������� ����\n(2) ������� ����\n");
	do {
		scanf("%d", &flag);
	} while ((flag != 1 && flag != 2) ? printf("�������� �����. ��������� ����:\n") : 0);

	if (flag == 1) {
		return_battalion.companies_count = data_battalion.companies_count + 1;
		return_battalion.companies = (company*)calloc(return_battalion.companies_count, sizeof(company));
		for (int i = 0; i < data_battalion.companies_count; i++) {
			return_battalion.companies[i] = data_battalion.companies[i];
		}

		return_battalion.companies[return_battalion.companies_count - 1] = inputCompany();
		printf("������ �������.\n");
	}
	else if (flag == 2) {
		int company_number;
		printf("������ ���:\n");
		for (int i = 0; i < data_battalion.companies_count; i++) {
			printf("%d) %s\n", i + 1, data_battalion.companies[i].company_type);
		}
		printf("������� ����� ����, ������� ������ ������� �� ������:\n");
		do {
			scanf("%d", &company_number);
		} while (company_number < 1 || company_number > data_battalion.companies_count);

		return_battalion.companies_count = data_battalion.companies_count - 1;
		return_battalion.companies = (company*)malloc(return_battalion.companies_count * sizeof(company));
		int j = 0;
		for (int i = 0; i < data_battalion.companies_count; i++) {
			if (i + 1 != company_number) {
				return_battalion.companies[j] = data_battalion.companies[i];
				j++;
			}
		}
		printf("������ �������.\n");
	}

	return return_battalion;
}

//���� ������ �������������� �����
int inputNumber() {
	void cleaner();
	char number[10];
	int flag;
	do {
		flag = 1;
		scanf("%s", &number);
		cleaner();
		for (int i = 0; i < strlen(number) && flag == 1; i++) {
			if (isdigit(number[i]) == 0) {
				flag = 0;
			}
		}
	} while ((flag == 0 || atoi(number) < 1) ? printf("�� ����� �������� �����. ��������� ����:\n") : 0);
	return atoi(number);
}

//������� ������ stdin
void cleaner() {
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}
