/**
 * OPR-Praktikum SS 2012
 * Aufgabe 10
 * @author Thomas Mahr
 */

#include "PrueffolgeSport.h"
#include "Sportler.h"
#include "Satz.h"
#include "Uebung.h"
#include "Training.h"
#include "EnergieFormatJoule.h"
#include "EnergieFormatSchokolade.h"
#include <cmath>
#include <sstream>
using namespace std;

const Sportler PrueffolgeSport::SPORTLER("Hugo",85,0.6);

const Bankdruecken PrueffolgeSport::BANKDRUECKEN;
const Klimmzug PrueffolgeSport::KLIMMZUG;


PrueffolgeSport::PrueffolgeSport()
{
	anmelden("Sportler", &pruefungSportler);
	anmelden("Wiederholung ausführen", &pruefungSportlerAusgabe);
	anmelden("Bankdrücken", &pruefungBankdruecken);
	anmelden("Bankdruecken ausgeben", &pruefungBankdrueckenAusgabe);
	anmelden("Klimmzug", &pruefungKlimmzug);
	anmelden("Klimmzug ausgeben", &pruefungKlimmzugAusgabe);
	anmelden("Wiederholungen ausführen", &pruefungWiederholungAusfuehren);
	anmelden("Satz", &pruefungUebungSatz);
	anmelden("Übung Bankdrücken ausführen",&pruefungUebungBankdruecken);
	anmelden("Übung Klimmzug ausführen",&pruefungUebungKlimmzug);
	anmelden("Training",&pruefungTrainingJoule);
	anmelden("Training für eine Tafel Schokolade",&pruefungTrainingSchokolade);
}

void PrueffolgeSport::pruefungSportler() 
{
	Sportler sportler = SPORTLER;
	SICHERSTELLEN(sportler.name()=="Hugo");
	SICHERSTELLEN(sportler.koerpergewicht()==85);	
	SICHERSTELLEN(sportler.armlaenge()==0.6);	
	SICHERSTELLEN(sportler.energieUmsatz()==0);	
}

void PrueffolgeSport::pruefungSportlerAusgabe() 
{
	stringstream s;
	s << "Sportler: " << SPORTLER << "!";
	SICHERSTELLEN(s.str()=="Sportler: Hugo: Körpergewicht = 85 kg, Armlänge = 0.6 m, Energieumsatz = 0 J!");
}

void PrueffolgeSport::pruefungBankdruecken() 
{
	Bankdruecken geraet = BANKDRUECKEN;
	SICHERSTELLEN(geraet.eingestelltesGewicht()==0);
	geraet.gewichtEinstellen(100);
	SICHERSTELLEN(geraet.eingestelltesGewicht()==100);
	Sportler sportler = SPORTLER;
	SICHERSTELLEN(abs(geraet.energieProWiederholung(SPORTLER)-GeraetImpl::ERDBESCHLEUNIGUNG*100*SPORTLER.armlaenge())<0.1);
}

void PrueffolgeSport::pruefungBankdrueckenAusgabe() 
{
	stringstream s;
	Bankdruecken geraet = BANKDRUECKEN;
	geraet.gewichtEinstellen(120);
	s << "Geraet: " << geraet << "!";
	SICHERSTELLEN(s.str()=="Geraet: Auf dem Geraet Bankdrücken sind 120 kg eingestellt.!");
}

void PrueffolgeSport::pruefungKlimmzug() 
{
	Klimmzug geraet = KLIMMZUG;
	SICHERSTELLEN(geraet.eingestelltesGewicht()==0);
	geraet.gewichtEinstellen(SPORTLER.koerpergewicht()-10);
	SICHERSTELLEN(SPORTLER.koerpergewicht()-10);	
	SICHERSTELLEN(abs(geraet.energieProWiederholung(SPORTLER)-GeraetImpl::ERDBESCHLEUNIGUNG*75*SPORTLER.armlaenge())<0.1);
}

void PrueffolgeSport::pruefungKlimmzugAusgabe() 
{
	stringstream s;
	Klimmzug geraet = KLIMMZUG;
	geraet.gewichtEinstellen(100);
	s << "Geraet: " << geraet << "!";
	SICHERSTELLEN(s.str()=="Geraet: Auf dem Geraet Klimmzug sind 100 kg eingestellt.!");
}

void PrueffolgeSport::pruefungWiederholungAusfuehren() 
{
	Sportler sportler = SPORTLER;

	Bankdruecken geraet1 = BANKDRUECKEN;
	geraet1.gewichtEinstellen(100);
	sportler.wiederholungAusfuehren(geraet1);
	SICHERSTELLEN(abs(sportler.energieUmsatz()-100*GeraetImpl::ERDBESCHLEUNIGUNG*sportler.armlaenge()/Sportler::WIRKUNGSGRAD)<0.1);	
	sportler.wiederholungAusfuehren(geraet1);
	SICHERSTELLEN(abs(sportler.energieUmsatz()-2*100*GeraetImpl::ERDBESCHLEUNIGUNG*sportler.armlaenge()/Sportler::WIRKUNGSGRAD)<0.1);	

	Klimmzug geraet2 = KLIMMZUG;
	geraet2.gewichtEinstellen(sportler.koerpergewicht());
	sportler.wiederholungAusfuehren(geraet2);
	SICHERSTELLEN(abs(sportler.energieUmsatz()-(2*100*GeraetImpl::ERDBESCHLEUNIGUNG*sportler.armlaenge()/Sportler::WIRKUNGSGRAD+sportler.koerpergewicht()*GeraetImpl::ERDBESCHLEUNIGUNG*sportler.armlaenge()/Sportler::WIRKUNGSGRAD))<0.1);	
	sportler.wiederholungAusfuehren(geraet2);
	SICHERSTELLEN(abs(sportler.energieUmsatz()-(2*100*GeraetImpl::ERDBESCHLEUNIGUNG*sportler.armlaenge()/Sportler::WIRKUNGSGRAD+2*sportler.koerpergewicht()*GeraetImpl::ERDBESCHLEUNIGUNG*sportler.armlaenge()/Sportler::WIRKUNGSGRAD))<0.1);	
}

void PrueffolgeSport::pruefungUebungSatz() 
{
	Satz satz(10,90);
	SICHERSTELLEN(satz.anzahlWiederholungen()==10);
	SICHERSTELLEN(satz.gewicht()==90);
}

void PrueffolgeSport::pruefungUebungBankdruecken() 
{
	stringstream s;
	Sportler sportler = SPORTLER;
	Bankdruecken geraetBankdruecken;
	Uebung<EnergieFormatJoule> uebung(sportler, geraetBankdruecken);
	uebung.satzHinzufuegen(Satz(12,70));
	uebung.satzHinzufuegen(Satz(10,90));
	uebung.satzHinzufuegen(Satz(8,110));
	SICHERSTELLEN(uebung.anzahlSaetze()==3);
	uebung.ausfuehren(s);
	SICHERSTELLEN(abs(sportler.energieUmsatz() - (12*70+10*90+8*110)*GeraetImpl::ERDBESCHLEUNIGUNG*sportler.armlaenge()/Sportler::WIRKUNGSGRAD)<0.1);
}

void PrueffolgeSport::pruefungUebungKlimmzug() 
{
	stringstream s;
	Sportler sportler = SPORTLER;
	Klimmzug geraetKlimmzug;
	Uebung<EnergieFormatJoule> uebung(sportler, geraetKlimmzug);
	uebung.satzHinzufuegen(Satz(15,sportler.koerpergewicht()));
	uebung.satzHinzufuegen(Satz(12,sportler.koerpergewicht()+10));
	SICHERSTELLEN(uebung.anzahlSaetze()==2);
	uebung.ausfuehren(s);
	SICHERSTELLEN(abs(sportler.energieUmsatz() - (15*sportler.koerpergewicht()+12*(sportler.koerpergewicht()+10))*GeraetImpl::ERDBESCHLEUNIGUNG*sportler.armlaenge()/Sportler::WIRKUNGSGRAD)<0.1);
}

void PrueffolgeSport::pruefungTrainingJoule() 
{
	stringstream s;
	Sportler sportler = SPORTLER;
	
	Training<EnergieFormatJoule> training(sportler);
	
	Bankdruecken geraetBankdruecken;
	Uebung<EnergieFormatJoule> uebungBankdruecken(sportler, geraetBankdruecken);
	uebungBankdruecken.satzHinzufuegen(Satz(12,70));
	uebungBankdruecken.satzHinzufuegen(Satz(10,90));
	uebungBankdruecken.satzHinzufuegen(Satz(8,110));
	training.uebungHinzufuegen(uebungBankdruecken);
	
	Klimmzug geraetKlimmzug;
	Uebung<EnergieFormatJoule> uebungKlimmzug(sportler, geraetKlimmzug);
	uebungKlimmzug.satzHinzufuegen(Satz(15,sportler.koerpergewicht()));
	uebungKlimmzug.satzHinzufuegen(Satz(12,sportler.koerpergewicht()+10));
	training.uebungHinzufuegen(uebungKlimmzug);

	training.ausfuehren(s);	
	double d1 = sportler.energieUmsatz();
	double d2 = (12*70+10*90+8*110)*GeraetImpl::ERDBESCHLEUNIGUNG*sportler.armlaenge()/Sportler::WIRKUNGSGRAD + (15*sportler.koerpergewicht()+12*(sportler.koerpergewicht()+10))*GeraetImpl::ERDBESCHLEUNIGUNG*sportler.armlaenge()/Sportler::WIRKUNGSGRAD;
	SICHERSTELLEN(abs(d1 - d2)<0.1);
	SICHERSTELLEN(training.energieUmsatz()=="118.54 kJ");
}

void PrueffolgeSport::pruefungTrainingSchokolade() 
{
	stringstream s;
	Sportler sportler = SPORTLER;
	
	Training<EnergieFormatSchokolade> training(sportler);
	
	Bankdruecken geraetBankdruecken;
	Uebung<EnergieFormatSchokolade> uebungBankdruecken(sportler, geraetBankdruecken);
	for(int i=0; i<50; i++)
	{
		uebungBankdruecken.satzHinzufuegen(Satz(50,150));
	}
	training.uebungHinzufuegen(uebungBankdruecken);

	training.ausfuehren(s);	
	SICHERSTELLEN(abs(sportler.energieUmsatz() - 50*50*150*GeraetImpl::ERDBESCHLEUNIGUNG*sportler.armlaenge()/Sportler::WIRKUNGSGRAD)<0.1);
	SICHERSTELLEN(training.energieUmsatz()=="4.013 Tafeln Schokolade");
}
