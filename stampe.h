//
// Created by Giancarlo on 07/06/2021.
//

#ifndef TNVPROJECT_STAMPE_H
#define TNVPROJECT_STAMPE_H
#include "libreria_primaria.h"
/**-------subroutines per la stampa----------------*/
void stampaCaratteri(char ch,int n);
void benvenuto();
void intestazione();
void stampaDetenuto(RecordSoggetto soggetto);
void stampaSingoloDetenuto(VettoreDinamico *vd);
void stampaVettoreDinamico(VettoreDinamico *vd);
void stampaVettoreColoreOcchi(char vd[], int dim);
void stampaVettoreColoreCapelli(char vd[], int dim);
void stampaVettoreFingerPrint(char vd[], int dim);
void stampaLunghezzaCapelli(LunghezzaCapelli scelta);
void stampaStatoSoggetto(StatoSoggetto e);
void stampaBarba(bool barbuto);
void stampaCicatrici(bool cicatrici);

#endif //TNVPROJECT_STAMPE_H
