#pragma once

#include "participante.h"
#include "carrera.h"


/*plazo 15 de agosto de 2021 al 05 de septiembre del 2021.

inscribir competidor
ver competidor
modificar competidor
ver inscritos
*/

void inscribirParticipantes(Carrera carrera);
Participante validaParticipante(Carrera carrera);
int asignaCategoria(int edad, bool condicion,Categoria * categorias);
bool validaFechaInscripcion(Fecha 
fecha, Carrera carrera);
