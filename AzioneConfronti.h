//
// Created by Giancarlo on 05/06/2021.
//

#ifndef TNVPROJECT_AZIONECONFRONTI_H
#define TNVPROJECT_AZIONECONFRONTI_H
#include "libreria_primaria.h"


int confrontoGenerale(VettoreDinamico *s);
int confrontoString(char string1[], char string2[]);
int confrontoNum(double x, double y);
int confrontoVettori(int dim, char v1[], char v2[]);
int verificaBool (bool e1, bool e2);


_Bool confrontoSoggetti(RecordSoggetto soggetto1,RecordSoggetto soggetto2);
void azioneRicerca(VettoreDinamico *vd);
_Bool confrontoMaggiore(RecordSoggetto soggetto1[], RecordSoggetto soggetto2[]);
void vettoreInString(int dim, char v[], char *e);
void ricercaFrammentoStringa(VettoreDinamico *vd, char *string);
RecordSoggetto recuperaElemento(VettoreDinamico *vd, int indice);


#endif //TNVPROJECT_AZIONECONFRONTI_H
