/**
 * OPR-Praktikum SS 2012
 * Aufgabe 10
 * @author Thomas Mahr
 */

#pragma once
#include "Sportler.h"
#include "Bankdruecken.h"
#include "EnergieFormatJoule.h"
#include "Uebung.h"
#include "EnergieFormatSchokolade.h"
#include "Prueffolge.h"




class PrueffolgeSport : public Prueffolge
{
public:

	PrueffolgeSport();

private:

	static void pruefungSportler();
	static void pruefungSportlerAusgabe();
	static void pruefungBankdruecken();
	static void pruefungBankdrueckenAusgabe();
	static void pruefungWiederholungAusfuehren();
	static void pruefungUebungBankdrueckenJoule();
	static void pruefungUebungBankdrueckenSchokolade();
	
	static const Sportler SPORTLER;
	static const Bankdruecken BANKDRUECKEN;
};
