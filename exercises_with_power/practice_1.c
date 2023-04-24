// Clase 17/04/2023

#include <stdio.h>

int main()
{

  int legajo, nota;
  int sum_notas = 0, max_nota = 0, cant_alumnos = 0, cant_aprobados = 0;
  int sobresaliente = 0, muy_bueno = 0, bueno = 0, regular = 0, insuficiente = 0;
  float prom_notas = 0;

  while (1)
  {

    printf("Ingrese el numero de legajo del alumno: ");
    scanf("%d", &legajo);

    if (legajo == 0)
    {
      printf("La carga de notas de alumnos ha finalizado. \n");
      break;
    }

    printf("Ingrese la nota del alumno: ");
    scanf("%d", &nota);

    if (nota <= 0 || nota > 10)
    {
      printf("La nota ingresada no es valida. \n");
      continue;
    }

    cant_alumnos++;
    sum_notas += nota;

    if (nota >= 6)
    {
      cant_aprobados++;
    }

    if (nota > max_nota)
    {
      max_nota = nota;
    }

    switch (nota)
    {
    case 10:
      sobresaliente++;
      break;
    case 9:
    case 8:
      muy_bueno++;
      break;
    case 7:
    case 6:
      bueno++;
      break;
    case 5:
    case 4:
      regular++;
      break;
    case 3:
    case 2:
    case 1:
      insuficiente++;
      break;
    }
  }

  prom_notas = (float)sum_notas / cant_alumnos;

  printf("\nLa cantidad de alumnos es: %d \n", cant_alumnos);
  printf("La cantidad de alumnos aprobados es: %d \n", cant_aprobados);
  printf("El promedio de notas de los alumnos es: %.2f \n", prom_notas);
  printf("La nota maxima es: %d \n", max_nota);

  printf("\nEl conteo final de las notas es el siguiente:\n\n Sobresaliente: %d\n Muy bueno: %d\n Bueno: %d\n Regular: %d\n Insuficiente: %d \n", sobresaliente, muy_bueno, bueno, regular, insuficiente);

  return 0;
}