/**
 * OPR-Praktikum SS 2012
 * Aufgabe 10
 * @author Thomas Mahr
 */
 
#include "PrueffolgeSport.h"
#include "Sportler.h"
#include "Bankdruecken.h"
#include "Klimmzug.h"
#include "Uebung.h"
#include "Training.h"
#include "EnergieFormatSchokolade.h"
using namespace std;

void prueffolge()
{
	PrueffolgeSport prueffolge;
	prueffolge.ausfuehren();
}

void beispiel1()
{
	Sportler hugo("Hugo", 85, 0.8);
	cout << "\nAnwendungsbeispiel 1: " << hugo << endl;

	Training<EnergieFormatSchokolade> trainingHugo(hugo);
	
	Bankdruecken geraetBankdruecken;
	Uebung<EnergieFormatSchokolade> uebungBankdruecken(hugo, geraetBankdruecken);
	uebungBankdruecken.satzHinzufuegen(Satz(12,70));
	uebungBankdruecken.satzHinzufuegen(Satz(10,90));
	uebungBankdruecken.satzHinzufuegen(Satz(8,110));
	trainingHugo.uebungHinzufuegen(uebungBankdruecken);
	
	Klimmzug geraetKlimmzug;
	Uebung<EnergieFormatSchokolade> uebungKlimmzug(hugo, geraetKlimmzug);
	uebungKlimmzug.satzHinzufuegen(Satz(15,hugo.koerpergewicht()));
	uebungKlimmzug.satzHinzufuegen(Satz(12,hugo.koerpergewicht()+10));
	uebungKlimmzug.satzHinzufuegen(Satz(10,hugo.koerpergewicht()+20));
	trainingHugo.uebungHinzufuegen(uebungKlimmzug);
	
	trainingHugo.ausfuehren(cout);	
}

void beispiel2()
{
	Sportler clark("Clark Kent", 85, 0.8);
	cout << "\nAnwendungsbeispiel 2: " << clark << endl;
	
	// Diese beiden Parameter sind so einzustellen, dass Clark Kent 1 Tafel Schokolade "verbrennt":
	const int anzahlWiederholungenProSatz = 1;
	const double gewicht = 1;

	Bankdruecken geraetBankdruecken;
	Training<EnergieFormatSchokolade> trainingClark(clark);
	Uebung<EnergieFormatSchokolade> extremBankdruecken(clark, geraetBankdruecken);
	for(int i=0; i<3; i++)
	{
		extremBankdruecken.satzHinzufuegen(Satz(anzahlWiederholungenProSatz,gewicht));
	}
	trainingClark.uebungHinzufuegen(extremBankdruecken);
	trainingClark.ausfuehren(cout);
}

int main()
{
	prueffolge();
	beispiel1();
	beispiel2();
}
