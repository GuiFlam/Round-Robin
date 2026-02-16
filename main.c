#include "./includes/processus.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Round-Robin Simulator !\n");

    processus_t *p = processus_creer("Processus de test", 50, 1);
    if(p == NULL) return -1;

    printf("Processus créé: %s, durée de %ins et priorité %i\n", processus_get_nom(p), processus_get_duree(p), processus_get_prio(p));

}
