//
// Created by Giancarlo on 07/06/2021.
//

#ifndef TNVPROJECT_CONTROLLI_H
#define TNVPROJECT_CONTROLLI_H

#include "libreria_primaria.h"

/**---------------Controlli Inserimento-------------------*/
void controlloInputNome(RecordSoggetto *soggetto);
void controlloInputCognome(RecordSoggetto *soggetto);
void controlloInputAltezza(RecordSoggetto *soggetto);
void controlloInputPeso(RecordSoggetto *soggetto);
void controlloInputResidenza(RecordSoggetto *soggetto);
void inputBooleanoBarba(RecordSoggetto *soggetto);
void inputBooleanoCicatrici(RecordSoggetto *soggetto);
void controlloInputLunghezzaCapelli(RecordSoggetto *soggetto);
void controlloInputStatoSoggetto(RecordSoggetto *soggetto);
void controlloPosizioneGpsLongitudine(RecordSoggetto *soggetto);
void controlloPosizioneGpsLatitudine(RecordSoggetto *soggetto);
void controlloInputColoreOcchi(RecordSoggetto *soggetto);
void controlloInputColoreCapelli(RecordSoggetto *soggetto);
void controlloInputFingerPrint(RecordSoggetto *soggetto);



/**----- Funzioni di supporto delle Subroutine-----*/
_Bool verificaCaratteri(char vd[],int dim);
_Bool verificaCifre(int vd[]);
_Bool verificaCaratteriResidenza(char vd[],int dim);
_Bool verificaColori(char v[], int dim);
_Bool verificaFingerPrint(char vd[],int dim);//non testato


_Bool svuotaBuffer();
void controllaInputUtente();
void svuotaInputUtente();
_Bool sceltaConsentita(char valoreInserito, int indice);
_Bool verificaInserimentoStringa(int dim, char vd[dim]);


#endif //TNVPROJECT_CONTROLLI_H
