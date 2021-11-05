//
// Created by Giancarlo on 07/06/2021.
//

#include "controlli.h"

/**----- procedure per il controllo delle acquisizioni ------*/
void controlloInputNome(RecordSoggetto *soggetto){
    _Bool flaggone=false;
    do{
        printf("\nInserisci il NOME del soggetto\nATTENZIONE: max %d di caratteri!! :  ", DIM_NOM);
        scanf("%63[^\n]s", soggetto->nome);
        svuotaBuffer();
        flaggone = verificaCaratteri(soggetto->nome, DIM_NOM);
        if (flaggone == false)
            printf("\n\t\tINSERIMENTO NON CORRETTO\n");
    }while (!flaggone);
}
void controlloInputCognome(RecordSoggetto *soggetto){
    _Bool flaggone=false;
    do{
        printf("\nInserisci il COGNOME del soggetto\nATTENZIENE: max %d di caratteri!!:  ", DIM_NOM);
        scanf("%63[^\n]s", soggetto->cognome);
        svuotaBuffer();
        flaggone = verificaCaratteri(soggetto->cognome, DIM_NOM);
        if (flaggone == false)
            printf("\n\t\tINSERIMENTO NON CORRETTO\n");
    }while (!flaggone);
}
void controlloInputAltezza(RecordSoggetto *soggetto){
    _Bool flaggone=false;
    do{
        printf("\nAltezza in cm\nInserisci un numero intero: ");
        scanf("%d", &soggetto->altezza);
        svuotaBuffer();
        if ((soggetto->altezza >= LIMITE_ALTEZZA_MIN) && (soggetto->altezza <= LIMITE_ALTEZZA_MAX))
            flaggone = true;
        else
            printf("\n\t\tINSERIMENTO NON CORRETTO\n");
    }while (!flaggone);
}

void controlloInputPeso(RecordSoggetto *soggetto){
    _Bool flaggone;
    do{
        printf("\nInserisci Peso in kg\t;  ");
        scanf("%f", &soggetto->peso);
        svuotaBuffer();
        if ((soggetto->peso >= LIMITE_PESO_MIN) && (soggetto->peso <= LIMITE_PESO_MAX)){
            flaggone = true;
        }else
            printf("\n\t\tINSERIMENTO NON CORRETTO\n");
    }while (!flaggone);
}

void controlloInputResidenza(RecordSoggetto *soggetto){
    _Bool flaggone=false;
    do{
        printf("\nInserisci la Residenza del soggetto\nATTENZIONE: Stato, Provincia, Paese, Cap, Via!! :  ");
        scanf("%511[^\n]s", soggetto->residenza);
        svuotaBuffer();
        flaggone = verificaCaratteriResidenza(soggetto->residenza, DIM_RESIDENZA);
        if (flaggone == false)
            printf("\n\t\tINSERIMENTO NON CORRETTO\n");
    }while (!flaggone);
}
void controlloInputLunghezzaCapelli(RecordSoggetto *soggetto){

    _Bool flaggone=false;
    do{
        printf("\nLunghezza dei capelli.\n[1=corti, 2=medi, 3=lunghi, 4=altro]: ");
        scanf("%d", &soggetto->capelli);
        svuotaBuffer();
        if ((soggetto->capelli >= ENUM_MIN) && (soggetto->capelli <= ENUM_MAX))
            flaggone = true;
        else
            printf("\n\t\tINSERIMENTO NON CORRETTO\n");
    }while (!flaggone);
}

//procedura da implementare//
void controlloInputStatoSoggetto(RecordSoggetto *soggetto){
    _Bool flaggone=false;
    do{

        printf("\nStato del soggetto.\n[1=libero, 2=ricercato, 3=arrestato, 4=evaso]: ");
        scanf("%d", &soggetto->stato);
        svuotaBuffer();
        if ((soggetto->stato >= ENUM_MIN) && (soggetto->stato <= ENUM_MAX))
            flaggone = true;
        else
            printf("\n\t\tINSERIMENTO NON CORRETTO\n");
    }while (!flaggone);
}

void controlloPosizioneGpsLatitudine(RecordSoggetto *soggetto){
    _Bool flaggone;
    do{
        printf("\nInserisci Posizione gps. LATITUDINE:  ");
        scanf("%lf", &soggetto->posizione.latitudine);
        flaggone=false;
        svuotaBuffer();
        if ((soggetto->posizione.latitudine >= GPS_MIN) && (soggetto->posizione.latitudine <= GPS_MAX)){
            flaggone = true;
        }else
            printf("\n\t\tINSERIMENTO NON CORRETTO\n");
    }while (!flaggone);
}

void controlloPosizioneGpsLongitudine(RecordSoggetto *soggetto){
    _Bool flaggone;
    do{
        printf("\nInserisci Posizione gps. LONGITUDINE:  ");
        scanf("%lf", &soggetto->posizione.longitudine);
        flaggone=false;
        svuotaBuffer();
        if ((soggetto->posizione.longitudine >= GPS_MIN) && (soggetto->posizione.longitudine <= GPS_MAX)){
            flaggone = true;
        }else
            printf("\n\t\tINSERIMENTO NON CORRETTO\n");
    }while (!flaggone);
}

void controlloInputColoreOcchi(RecordSoggetto *soggetto){
    int i;
    _Bool flaggone=false;
    do{


        printf("\nInserisci il codice relativo al colore degli OCCHI del soggetto\nATTENZIONE massimo %d caratteri esadecimali!! :  ", DIM_COLORE);
        for (i=0; i<DIM_COLORE; i++) {
            scanf("%6[^\n]c", soggetto[i].coloreOcchi);
        }
        svuotaBuffer();


        flaggone = verificaColori(soggetto->coloreOcchi, DIM_COLORE);
        if (flaggone == false)
            printf("\n\t\tINSERIMENTO NON CORRETTO\n");
    }while (!flaggone);
}
void controlloInputColoreCapelli(RecordSoggetto *soggetto){
    int i;
    _Bool flaggone=false;
    do{

        printf("\nInserisci il codice relativo al colore dei CAPELLI del soggetto\nATTENZIONE massimo %d caratteri esadecimali!! :  ", DIM_COLORE);
        for (i=0; i<DIM_COLORE; i++) {
            scanf("%6[^\n]c", soggetto[i].coloreCapelli);
        }
        svuotaBuffer();
        flaggone = verificaColori(soggetto->coloreCapelli, DIM_COLORE);
        if (flaggone == false)
            printf("\n\t\tINSERIMENTO NON CORRETTO\n");
    }while (!flaggone);
}
void controlloInputFingerPrint(RecordSoggetto *soggetto){
    int i;
    _Bool flaggone=false;
    do{


        printf("\nInserire Chiave IMPRONTA DIGITALE\nATTENZIONE massimo %d caratteri esadecimali!! :  ", DIM_IMPRONTA);
        for (i=0; i<DIM_IMPRONTA; i++) {
            scanf("%16[^\n]c", soggetto[i].chiaveImprontaDigitale);
        }
        svuotaBuffer();
        flaggone = verificaFingerPrint(soggetto->chiaveImprontaDigitale, DIM_IMPRONTA);
        if (flaggone == false)
            printf("\n\t\tINSERIMENTO NON CORRETTO\n");
    }while (!flaggone);
}




/** -----------Supporto per alcune Subroutine-------------- */

void inputBooleanoBarba(RecordSoggetto *soggetto){
    char scelta;
    do{
        printf("\nIl detenuto ha la barba? [S = ha la barba, N= non ha la barba]: ");
        scanf("%c", &scelta);
        svuotaBuffer();
        if (((scelta == 'N') || (scelta == 'n')) && (scelta != '\n'))
            soggetto->barba = false;

        if (((scelta == 'S') || (scelta == 's')) && (scelta != '\n'))
            soggetto->barba = true;
        else
            printf("\n l'inserimento non è corretto");
    } while (!((scelta == 'N')||(scelta == 'n')|| (scelta == 'S')|| (scelta == 's') && (scelta != '\n')));
}
void inputBooleanoCicatrici(RecordSoggetto *soggetto) {
    char scelta;
    do {
        printf("\nIl detenuto ha cicatrici visibili? [S = ha cicatrici, N = non ha cicatrici]: ");
        scanf("%c", &scelta);
        svuotaBuffer();
        if (((scelta == 'N') || (scelta == 'n')) && (scelta != '\n')) {
            soggetto->cicatrice = false;

            if (((scelta == 'S') || (scelta == 's')) && (scelta != '\n'))
                soggetto->cicatrice = true;
        }else
            printf("\n l'inserimento non è corretto");
    } while (!((scelta == 'N')||(scelta == 'n')|| (scelta == 'S')|| (scelta == 's') && (scelta != '\n')));
}


_Bool verificaCaratteri(char vd[], int dim){
    int i;
    for (i=0; vd[i] != '\0'; i++){
        if(isalpha(vd[i]) == 0 && (vd[i] != ' ')) //può ammettere solo lettere e lo spazio
            return false;
    }
    return true;
}


_Bool verificaCifre(int vd[]){
    int i;
    for (i=0; vd[i] != '\0'; i++){
        if(isdigit(vd[i]) == 0) //può ammettere solo cifre
            return false;
    }
    return true;
}
_Bool verificaCaratteriResidenza(char vd[], int dim){
    int i;
    for (i=0; vd[i] != '\0'; i++){
        if((vd[i] != ' ' && (vd[i] != ',')))
            if(isalpha(vd[i]) == 0 && isdigit(vd[i]) == 0 )//può ammettere solo lettere, cifre, spazio e virgole
                return false;
    }
    return true;
}
_Bool verificaColori(char v[], int dim){
    int i;
    for (i=0; v[i]!= '\0'; i++){
        if (isxdigit(v[i])==0)
            return false;
    }
    return true;
}
/**_Bool verificaCifra(int cifra){
    if (isdigit(cifra) != 0){
        return true;}
    else
        return false;
}*/

_Bool verificaFingerPrint(char vd[],int dim){
    int i;
    for (i=0; vd[i] != '\0'; i++){
        if(isxdigit(vd[i]) == 0) //può ammettere solo caratteri esadecimali
            return false;
    }
    return true;
}

void svuotaInputUtente() {
    if (!svuotaBuffer()) { //Se sono stati trovati caratteri diversi da un unico '\n'
        printf("Attenzione! Stringa non corretta. Alcuni caratteri saranno ignorati.\n");
    }
}
_Bool svuotaBuffer() {
    _Bool inputCorretto = true;

    //Scorri il buffer finché non si ha un carattere di andata a capo
    while (getchar() != '\n') {
        inputCorretto = false; //Se nel buffer c'è stato almeno un carattere diverso da '\n'
    }

    return inputCorretto;
}

void controllaInputUtente() {
    if (!svuotaBuffer()) { //Se sono stati trovati caratteri diversi da un unico '\n'
        printf("Attenzione! Stringa non corretta. Alcuni caratteri saranno ignorati.\n");
    }
}
