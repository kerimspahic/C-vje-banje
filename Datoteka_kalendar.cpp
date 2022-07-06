/*Tekstualna datoteka kalendar.txt u svakom redu sadrži informacije
o zakazanim aktivnostima u jednom danu. Za svaku aktivnost navodi 
se vrijeme poèetka, vrijeme završetka i kratak opis. 
Format jednog reda datoteke je dat u priloženom primjeru. Napisati
program koji èita red po red iz datoteke, pravi strukturu aktivnosti
na osnovu podataka iz proèitanog reda i stavlja je u listu u 
hronološkom poretku. Potom, polazeæi od poèetka liste pronalazi 
aktivnosti koje se preklapaju. Ako se detektuje preklapanje izmeðu 
dve aktivnosti, iz liste se izbacuje aktivnost koja poèinje kasnije
ili, ako obe poèinju u isto vrijeme, izbacuje se ona koja je druga
u poretku. Aktivnost se može preklapati sa proizvoljno mnogo drugih
aktivnosti. Aktivnosti koje se izbace iz liste, ispisuju se u 
izlaznu tekstualnu datoteku preklapanja.txt. Za kratak opis 
aktivnosti koristi se maksimalno 80 znakova. Na kraju program 
treba da ispravno oslobodi zauzete resurse. Uèitavanje i brisanje 
liste realizovati kao potprograme.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_TEXT_LEN 80

typedef struct sVrijeme {
int sati, minute;
 } Vrijeme;

typedef struct sAkcija {
Vrijeme startVrijeme, endVrijeme;
char opis[DEFAULT_TEXT_LEN + 1];
 } Akcija;

typedef struct sListElement {
Akcija * pAkcija;
struct sListElement * next;
} ListElement;

ListElement* insert(ListElement* l, Akcija* act);
Akcija* readAkcija(FILE* f);
ListElement* removeOverlappedActivities(ListElement* aList, FILE* output);
void printAkcija(Akcija* actv, FILE * f);
void printAkcijaList(ListElement* aList, FILE* f);
int isOverlaped(Akcija* a1, Akcija* a2); 
int isVrijemeBeforeOrEqual(Vrijeme t1, Vrijeme t2); 
int isAkcijaBeforeOrEqual(Akcija* a1, Akcija* t2);
int isVrijemeBefore (Vrijeme t1, Vrijeme t2);
int isAkcijaBefore(Akcija* a1, Akcija* a2);
void dealocate(ListElement* actv);

int main() {
ListElement* AkcijaList = NULL; Akcija* currAkcija;
int s = 0;
FILE* scheduleFile = fopen("kalendar.txt", "r");
FILE* overlapingFile = fopen("preklapanja.txt", "w");

if (scheduleFile == NULL) { 
fprintf(stderr, "Cannot open input file."); s = 1; goto END; 
 } 
if (overlapingFile == NULL) { 
fprintf(stderr, "Cannot open output file."); s = 1; goto END; 
 } 

while ((currAkcija = readAkcija(scheduleFile)) != NULL) { 
AkcijaList = insert(AkcijaList, currAkcija); 
 } 

printAkcijaList(AkcijaList, stdout); 
removeOverlappedActivities(AkcijaList, overlapingFile); 
printAkcijaList(AkcijaList, stdout); 

END: if (scheduleFile) fclose(scheduleFile);
if (overlapingFile) fclose(overlapingFile); 

dealocate(AkcijaList); 
return s;
 }
Akcija* readAkcija(FILE* f) { 
int numOfData; 
Akcija* actv = (Akcija*)malloc(sizeof(Akcija)); 
if(!actv) { 
printf("Error in memory allocation"); 
exit(2); 
 } 
numOfData = fscanf(f, "%d:%d-%d:%d ", 
&actv->startVrijeme.sati, &actv->startVrijeme.minute, 
&actv->endVrijeme.sati, &actv->endVrijeme.minute); 

if (numOfData == EOF) { 
free(actv); //nepotrebno smo alocirali 
return NULL; 
 } 

fgets(actv->opis, DEFAULT_TEXT_LEN, f); 

return actv; 
 } 

ListElement* insert(ListElement* lstFirst, Akcija* actv) { 
ListElement* newActv = (ListElement*) malloc(sizeof(ListElement)); 

newActv->pAkcija = actv; 

ListElement* curr = lstFirst, *prev = NULL; 
while (curr) { 
if (isAkcijaBeforeOrEqual(curr->pAkcija, actv)) 
prev = curr, curr = curr->next; 
else break; // pronasli smo mesto! 
 } 

if (!prev) lstFirst = newActv; //prvi element 
else prev->next = newActv; // 
newActv->next = curr; // ulancavanmo u postojecu 

return lstFirst; // vracamo glavu liste 
 } 

ListElement* removeOverlappedActivities(ListElement* aList, FILE* output) { 
ListElement * pi = aList, * pj = NULL, * pjPrev, * old; 
while (pi) { 
pj = pi->next; 
while (pj) { 
if (isOverlaped(pi->pAkcija, pj->pAkcija)) { 
printAkcija(pj->pAkcija, output); 
pi->next = pj->next; 
free(pj->pAkcija); 
free(pj); 
pj = pi->next; 
 } else { 
pj = pj->next; 
 }
 } 
pi = pi->next;
 } 

return aList; 
 }

int isOverlaped(Akcija* a1, Akcija* a2) { 
return ( isVrijemeBeforeOrEqual(a1->startVrijeme, a2->startVrijeme) 
&& isVrijemeBefore(a2->startVrijeme, a1->endVrijeme) ) 
|| ( isVrijemeBeforeOrEqual(a2->startVrijeme, a1->startVrijeme) 
&& isVrijemeBefore(a1->startVrijeme, a2->endVrijeme) ); 
 } 

int isVrijemeBeforeOrEqual(Vrijeme t1, Vrijeme t2) { 
return (t1.sati < t2.sati) || 
(t1.sati == t2.sati && t1.minute <= t2.minute); 
} 

int isVrijemeBefore(Vrijeme t1, Vrijeme t2) { 
return (t1.sati < t2.sati) || 
(t1.sati == t2.sati && t1.minute < t2.minute); 
 } 

int isAkcijaBeforeOrEqual(Akcija* a1, Akcija* a2) { 
return isVrijemeBeforeOrEqual(a1->startVrijeme, a2->startVrijeme); 
} 

void printAkcija(Akcija* actv, FILE* f) { 
fprintf(f, "%d:%d-%d:%d ", actv->startVrijeme.sati, actv->startVrijeme.minute,
actv->endVrijeme.sati, actv->endVrijeme.minute); 
fputs(actv->opis, f); 
 } 

void printAkcijaList(ListElement* aList, FILE* f) {
ListElement* p = aList; 
while (p) {
printAkcija(p->pAkcija, f);
p = p->next;
}
} 

void dealocate(ListElement* actv){ 
ListElement* tmp; 
while(actv){ 
tmp = actv;
actv = actv->next; 
/* Obavezno osloboditi i memoriju koju zauzima dinamicki alocirana 
struktura koja predstavlja aktivnost! */ 
free(tmp->pAkcija);
free(tmp);
 } 
 } 

