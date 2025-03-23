/**
 * OPR-Praktikum SS 2012
 * Aufgabe 10
 * @author Thomas Mahr
 */

#pragma once
#include "Prueffolge.h"
#include "Sportler.h"
#include "Bankdruecken.h"
#include "Klimmzug.h"

class PrueffolgeSport : public Prueffolge
{
public:

	PrueffolgeSport();

private:

	static void pruefungSportler();
	static void pruefungSportlerAusgabe();
	static void pruefungBankdruecken();
	static void pruefungBankdrueckenAusgabe();
	static void pruefungKlimmzug();
	static void pruefungKlimmzugAusgabe();
	static void pruefungWiederholungAusfuehren();
	static void pruefungUebungSatz();
	static void pruefungUebungBankdruecken();
	static void pruefungUebungKlimmzug();
	static void pruefungTrainingJoule();
	static void pruefungTrainingSchokolade();
	
	static const Sportler SPORTLER;
	static const Bankdruecken BANKDRUECKEN;
	static const Klimmzug KLIMMZUG;
};
