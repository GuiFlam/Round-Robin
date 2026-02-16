#include "processus.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

struct processus {
  char *nom;
  int duree;
  uint8_t prio; // on met uint8_t, pour avoir des nombres de 0 a 255.
  bool done;
};


/*
  @param nom Nom qui est donné au processus
  @param duree Duree de vie du processus en ns
  @param prio Priorité du processus, de 0 a 255
  @return pointeur vers le processus crée

*/
processus_t *processus_creer(char *nom, int duree, uint8_t prio) {
    processus_t *p = malloc(sizeof(processus_t));
    if(p == NULL) return NULL;

    // IMPORTANT: on doit faire une copie profonde de *nom, sinon on copie seulement ce qui est à l'adresse de *nom
    p->nom = malloc(strlen(nom) + 1); // +1 pour le \0
    if(p->nom == NULL) return NULL;

    strcpy(p->nom, nom);
    p->duree = duree;
    p->prio = prio;
    p->done = false;

    return p;
}

/*
  @param p Processus que on veut liberer
  @return 1 si reussi, -1 si echec

*/
int processus_liberer(processus_t *p) {
  if(p == NULL) return -1;

  free(p->nom);
  free(p);

  return 1;
}


/*
  @param p Processus que on veut liberer
  @param quantum Temps en ns quon veut executer le processus
  @return 1 si reussi, -1 si echec

*/
int processus_execute(processus_t *p, int quantum) {

  p->duree -= quantum;

  if(p->duree <= 0) {
    p->duree = 0;
    p->done = true;
  }
  return 1;
}




// ENCAPSULATION
char *processus_get_nom(processus_t *p) {
  return p->nom;
}

int processus_get_duree(processus_t *p) {
  return p->duree;
}

uint8_t processus_get_prio(processus_t *p) {
  return p->prio;
}

bool processus_is_done(processus_t *p) {
  return p->done;
}
