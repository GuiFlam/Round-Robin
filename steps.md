# Projet de pratique C - Simulateur d'ordonnancement
**Objectif:** Pratiquer pour l'examen de mercredi (Cours 3-5)

## Format d'entrée (fichier `processus.txt`)
```
P1 80 1
P2 40 0
P3 50 2
```
Format: `nom duree priorite`

---

## Étape 1: Structures de base (2h)
**À coder:**
- [ ] Struct `processus_t` (nom, durée, priorité, terminé)
- [ ] `processus_creer()`, `processus_liberer()`
- [ ] `processus_execute(processus, quantum)`
- [ ] `processus_est_termine()`
- [ ] Tests Unity de base

**Concepts pratiqués:** Encapsulation, malloc/free, tests unitaires

---

## Étape 2: File simple FIFO (2h)
**À coder:**
- [ ] Type opaque `file_t` (dans .h: `typedef struct file file_t;`)
- [ ] `file_creer()`, `file_liberer()`
- [ ] `file_enfiler(file, void *element)`
- [ ] `void* file_defiler(file)`
- [ ] `file_est_vide()`
- [ ] Tests Unity pour FIFO

**Concepts pratiqués:** Type opaque, void*, généricité

---

## Étape 3: File à priorités (2h)
**À coder:**
- [ ] `fileprio_t` avec tableau de `file_t*` (une par niveau)
- [ ] `fileprio_creer(nb_niveaux)`
- [ ] `fileprio_enfiler(fileprio, void *element, int priorite)`
- [ ] `void* fileprio_defiler(fileprio)` - parcourt de prio 0 à N
- [ ] Tests: vérifier ordre de priorité + FIFO dans même niveau

**Concepts pratiqués:** Files à priorités, composition

---

## Étape 4: Ordonnanceur Round-Robin (2h)
**À coder:**
- [ ] Lire fichier avec `fopen()`, `fgets()`, `strtok()`
- [ ] Créer processus et les enfiler selon priorité
- [ ] Boucle principale:
```c
  while (!fileprio_est_vide(fp)) {
      processus = fileprio_defiler(fp);
      processus_execute(processus, 20);  // quantum
      if (!processus_est_termine(processus)) {
          fileprio_enfiler(fp, processus, priorite);
      }
      afficher_etat();  // visualisation
  }
```
- [ ] Afficher: tour actuel, processus en cours, file d'attente
- [ ] Libérer tout proprement

**Concepts pratiqués:** Fichiers texte, ordonnancement, intégration complète

---

## Approche de travail

**Méthode intelligente:**
1. ✅ Essaie de coder une fonction sans regarder
2. ✅ Bloqué? → Consulte tes notes de cours
3. ✅ Comprends pourquoi c'est fait comme ça
4. ✅ Code toi-même (pas copier-coller!)
5. ✅ Referme les notes et réessaie

**Règle absolue:**
- ❌ Pas d'IA pour écrire le code
- ✅ Tes notes de cours sont OK
- ✅ Compiler souvent pour voir les erreurs
- ✅ Tests Unity après chaque étape

---

## Checklist finale avant l'examen

- [ ] Projet compilé et fonctionne
- [ ] Tous les tests passent
- [ ] Peux recoder une file FIFO sans notes?
- [ ] Peux expliquer void* et cast?
- [ ] Comprends différence copie superficielle/profonde?
- [ ] Sais utiliser fopen/fgets/strtok?
- [ ] Connais ordre de free() (données avant structure)?

---

## Notes d'examen mercredi

**Format:** [À livre ouvert / À livre fermé - à compléter]

**Durée:** [À compléter]

**Matière couverte:** Cours 1-6 (focus 3-5)
