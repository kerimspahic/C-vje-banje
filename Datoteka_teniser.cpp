#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct elem {
int playerId; 
char firstName[31]; 
char lastName[31]; 
int points; 
struct elem *next; 
 } Elem; 
 
 /* 
 Prototypes of functions being used within the solution. 
 Must be specified before the function invocation. 
 */ 
 // reads data representing player’s information from the file 
Elem* readPlayerData(FILE* atpF); 
 
 // inserts the element within the list 
Elem* insert(Elem* head, Elem* newElement); 
 
 // updates players scores, according to the information 
 // written in the tournamentFile 
void updatePlayersScore(Elem* list, FILE* tournamentFile); 
 
 
int main () { 
Elem *head = NULL, *tail = NULL, // first and last list elements 
*player, *current; // auxiliary pointers 
FILE *input1, *input2, *output; 

if ((input1 = fopen("teniseri.txt","r")) == NULL) { 
printf("Greska u otvaranju ulazne datocurrente teniseri.txt!"); 
exit(1); 
 }
if ((input2 = fopen("wimbledon.txt","r")) == NULL) { 
printf("Greska u otvaranju ulazne datocurrente wimbledon.txt!"); 
exit(1); 
 }
if ((output = fopen("atplist.txt","w")) == NULL) { 
printf("Greska u otvaranju outputne datocurrente atplist.txt!"); 
exit(4); 
 }

while((player = readPlayerData(input1))!=NULL) { 
head = insert(head, player); 
 }
updatePlayersScore(head, input2); 

current = head; 

while (current != NULL) { 
fprintf(output,"%d %s %s %d\n", current->playerId, current->firstName, 
current->lastName, current->points); 
current = current->next; 
}

current = head;
while (current != NULL) { 
tail = current; 
current = current->next; 
free(tail); 
 }

fclose(input1); 
fclose(input2); 
fclose(output); 
return 0;
}

Elem* readPlayerData(FILE* atpF) { 
char firstName[31], lastName[31]; 
int playerId, points; 

if(fscanf(atpF, "%d%s%s%d", &playerId, firstName, lastName, &points)!=EOF) { 
Elem* newElement = malloc(sizeof(Elem)); 
if(newElement==NULL) { 
printf("Greska pri alociranju!"); 
exit(1);
 }
newElement->playerId = playerId; 
newElement->points = points; 
strcpy(newElement->firstName, firstName); 
strcpy(newElement->lastName, lastName); 
return newElement; 
 }
return NULL; 
 }

Elem* insert(Elem* head, Elem* newElement) { 
Elem* current = head; 
 // adding element to the end of the list 
if(current){ 
while(current->next) 
current = current->next; 
current->next = newElement; 
 }
newElement->next = NULL; 
return head ? head : newElement; 
 }

void updatePlayersScore(Elem* list, FILE* tournamentFile) { 
int playerId, pointsToDefend, pointsWon; 
while(fscanf(tournamentFile, "%d%d%d", &playerId, &pointsToDefend, &pointsWon) 
!=EOF) { 
Elem* current = list; 
while (current != NULL && current->playerId != playerId) 
current = current->next; 

if (current != NULL) 
current->points += (pointsWon - pointsToDefend); 
 } 
 }

