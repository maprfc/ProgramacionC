#if 0
 Practica 13
 Mario Arturo Perez Rangel

 Uso de opciones del preprocesador
#endif

#include <stdio.h>

#define INTEGER   int
#define BEGIN     INTEGER main() {
#define END       }
#define IF        if
#define THEN      {
#define ELSE      } else {
#define ENDIF     }
#define PRINT     printf

BEGIN
INTEGER x = 10;
IF (x >=10)
THEN
   PRINT("TENGO DIEZ\n");
ELSE
   PRINT("REPROBARE\n");
ENDIF
END
