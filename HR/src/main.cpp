#include "HRMS/HRMS.hpp"

using namespace std;
void my_exception(int);

int main()
{
	HRMS *baza = new HRMS;

	Employee A("0001", "Rafal", "Fanski", "Informatyk");
	Employee B("0002", "Katarzyna", "Fanska", "Informatyk");
	Employee C("0003", "Malgorzata", "Fanska", "Informatyk");
	Employee D("0004", "Leszek", "Fanski", "Informatyk");
	Employee E("0005", "Lukasz", "Fanski", "Informatyk");
	Employee F("0006", "Halina", "Fanska", "Informatyk");
	Employee G("0007", "Karolina", "Czyrnek", "Sekretarka");
	Employee H("0008", "Tadeusz", "Wyzny", "Kucharz");
	Employee I("0009", "Tomek", "Fal", "Wozny");
	Employee J("0010", "Jan", "Kowalski", "Wozny");
	Employee K("0011", "Weronika", "Przybyla", "Sprzataczka");

	try{
	baza->add(A, "003", 5300.00);
	}catch(int er) {my_exception(er);}

	try{
	baza->add(B, "004", 500.06);
	}catch(int er) {my_exception(er);}

	try{
	baza->add(C, "004", 5300.00);
	}catch(int er) {my_exception(er);}

	try{
	baza->add(D, "001", 5500.90);
	}catch(int er) {my_exception(er);}

	try{
	baza->add(E, "001", 3000.56);
	}catch(int er) {my_exception(er);}

	try{
	baza->add(F, "002", 2500.12);
	}catch(int er) {my_exception(er);}

	try{
	baza->add(G, "002", 3100.00);
	}catch(int er) {my_exception(er);}

	try{
	baza->add(H, "002", 15000.55);
	}catch(int er) {my_exception(er);}

	try{
	baza->add(I, "001", 25000.34);
	}catch(int er) {my_exception(er);}

	try{
	baza->add(J, "003", 10134.23);
	}catch(int er) {my_exception(er);}

	try{
	baza->add(K, "002", 2505.90);
	}catch(int er) {my_exception(er);}

	cout << "\nTestowanie funkcji printDepartment:\n\n";
	try{
	baza->printDepartment("002");
	}catch(int er) {my_exception(er);}

	cout <<"Testowanie funkcji changeSalary:\n\n";
	try{
		baza->changeSalary("0006", 6053.90);
	}catch(int er){my_exception(er);}

	try{
	baza->changeSalary("0002", 2001.21);
	}catch(int er) {my_exception(er);}

	cout << "Testowanie funkcji printSalaries:\n\n";
	baza->printSalaries();

	cout << "Testowanie funkcji printSalariesSorted:\n\n";
	baza->printSalariesSorted();
	
	return 0;
}

void my_exception(int er)
{
	switch(er)
	{
		case -1:	cout << "ERROR: Utworzenie uzytkownika nie powiodlo sie!"
							" Uzytkownik o podanym id juz istnieje!\n";	break;
		case -2:	cout << "Warning: Utworzenie uzytkownika nie powiodlo sie!" 
							"Zarobki nie moga by liczba ujemna!\n"; break;
		case -3:	cout << "Warning: Podane ID dzialu nie istnieje!\n"; break;
		case -4:	cout << "Warning: Podane ID pracownika nie istnieje!\n"; break;
		case -5:	cout << "Warning: Podana liczba jest ujemna! Zarobki nie moga byc mniejsze od 0!"
							" Zamiana placy nie powiodla sie.\n";
	}
}