#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct processus processus_t;

processus_t *processus_creer(char *nom, int duree, uint8_t prio);

int processus_liberer(processus_t *p);

int processus_execute(processus_t *p, int quantum);

char *processus_get_nom(processus_t *p);

int processus_get_duree(processus_t *p);

uint8_t processus_get_prio(processus_t *p);

bool processus_is_done(processus_t *p);