#pragma once

/*
inscribir participante
leer participante
modificar participante
*/

#include "utils.h"
#include "participante.h"

void creaArchivo();
void guardarParticipante(Participante participante);
Participante buscaParticipante(int numero);
Participante setTiempoFinal(int numero, Tiempo tiempo);
Participante * getParticipantes();
long numeroParticipantes();
