//
// Created by Giancarlo on 30/05/2021.
//

#ifndef TNVPROJECT_LIBRERIA_PRIMARIA_H
#define TNVPROJECT_LIBRERIA_PRIMARIA_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


#define DIM_NOM 63          //Dimensione massima delle stringhe per il nome
#define DIM_RESIDENZA 511    //Dimensione massima della stringa per indicare Stato, Citta', Via
#define DIM_IMPRONTA 16
#define DIM_COLORE 6
#define LIMITE_ALTEZZA_MIN 0
#define LIMITE_ALTEZZA_MAX 250
#define LIMITE_PESO_MIN 0
#define LIMITE_PESO_MAX 200
#define ENUM_MIN 1
#define ENUM_MAX 4
#define GPS_MIN 0
#define GPS_MAX 360

/**Enumerazione per menu di scelta*/
typedef enum { INSERISCI_RECORD = 1, GENERA_CASUALMENTE_RECORD, CARICA_DATI_DA_FILE, CARICA_DATI_CRIPTATI, MODIFICA, ELIMINAZIONE, RICERCA, CONFRONTO, ORDINAMENTO_ALFABETICO, ORDIN_CONFRONTO, STAMP_RECORD_SINGOLO, STAMPA_GENERALE, SALVA_DATI, SALVA_CRIPTATI, ESCI } MenuScelta;

/** Enumerazione StatoSoggetto */
typedef enum { LIBERO = 1 , RICERCATO, ARRESTATO, EVASO } StatoSoggetto;

/** Enumerazione TipoCapelli */
typedef enum {CORTI = 1,MEDI,LUNGHI,ALTRO} LunghezzaCapelli;

/** Struttura posizione Gps del detenuto */
typedef struct {
    double latitudine;
    double longitudine;
} Posizione;

/** Struttura Record Detenuto */

typedef struct {
    char nome[DIM_NOM+1];
    char cognome[DIM_NOM+1];
    int altezza;
    float peso;
    char coloreOcchi[DIM_COLORE];
    char coloreCapelli[DIM_COLORE];
    LunghezzaCapelli capelli;
    _Bool barba;
    _Bool cicatrice;
    char chiaveImprontaDigitale[DIM_IMPRONTA];
    char residenza[DIM_RESIDENZA+1];
    StatoSoggetto stato;
    Posizione posizione;

} RecordSoggetto;


/** vettore dinamico **/
typedef struct{
    RecordSoggetto *v; //vettore dinamico
    int nDetenuti; //numero detenuti nel vettore dinamico
} VettoreDinamico;

void menuAvvio();
/** ------subroutine per funzionalità INSERIMENTO dati-----*/


//subroutine per inserimento di un Record//
RecordSoggetto acquisisciDatiDetenuto();
void azioneInserisciRecord(VettoreDinamico *vd);
void inizializzaVettoreDinamico(VettoreDinamico *vd);
void aggiungiDetenuto(VettoreDinamico *vd, RecordSoggetto soggetto);
void settaElemento(VettoreDinamico *vd, int indice, RecordSoggetto soggetto);
void azioneInserisciRecordGenerato(VettoreDinamico *vd);
RecordSoggetto acquisisciRecordGenerato();

/**-------------------Gestione Vettore------------------------*/
int dimensioneVettore(VettoreDinamico *vd);
void nuovaPosizioneDetenuto(VettoreDinamico *vd, int indice, RecordSoggetto d);
void azioneCancellaRecordDetenuto(VettoreDinamico *vd);
void rimuoviDetenutoInCoda(VettoreDinamico *vd);
void rimuoviDetenutoInPosizione(VettoreDinamico *vd, int indice);
_Bool vettoreVuoto(VettoreDinamico *vd);
void azioneOrdinamentoAlfabetico(VettoreDinamico *vd);
/**-----------------GENERAZIONE RANDOM----------------*/
int generaInteroCasuale(int min, int max);
float generaFloatCasuale ();
void covertiStringaEsadecimale(char *stringaEsadecimale, const char *caratteriCasuali, int nCifre);
void generaCodiceEsadecimaleColore();
void generaCodiceEsadecimaleFingerPrint();
void generaNomiCasuale(RecordSoggetto *soggetto);
void generaCognomiCasuale(RecordSoggetto *soggetto);
void generaAltezza(RecordSoggetto *soggetto);
void generaPeso(RecordSoggetto  *soggetto);
void generaBarba(RecordSoggetto *soggetto);
void generaCicatrici(RecordSoggetto *soggetto);
void generaLunghezzaCapelli(RecordSoggetto *soggetto);
void generaStatoSoggetto(RecordSoggetto *soggetto);
void generaColoreOcchi(RecordSoggetto *soggetto);
void generaColoreCapelli(RecordSoggetto *soggetto);
void generaFingerPrint(RecordSoggetto *soggetto);
void generaPosizioneGps(RecordSoggetto *soggetto);
void generaResidenza(RecordSoggetto *soggetto);




FILE *chiudiFile(FILE * fp);
#endif //TNVPROJECT_LIBRERIA_PRIMARIA_H