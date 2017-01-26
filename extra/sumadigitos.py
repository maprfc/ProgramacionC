#!/usr/bin/python3

# Mario Arturo Perez Rangel
# Suma de digitos.
# El programa recibe un numero entero positivo de dos digitos y suma sus digitos.
# Se apoya con expresiones regulares para su tare.

import sys
import re

# Si no hay parametro no tiene caso continuar.
if len(sys.argv) == 1:
    print "Se necesita un numero entero."
    print "Uso: " + sys.argv[0] + " valor"
    print "Donde valor es un numero entero de dos digitos."
    exit (1)

# Si hay mas de dos parametros solo tomamos el primero.
if len(sys.argv) > 2:
    print "Solo se requiere un parametro, ignorando los demas."

if re.match("^[0-9]+$",sys.argv[1]): # Revisa que se trate de un numero entero positivo
    if  re.match("[0-9]{2}$", sys.argv[1]): # Vemos si el numero es de dos digitos
        print "La suma de los digitos de " + sys.argv[1] + " es: " \
            + sys.argv[1][0] + " + " + sys.argv[1][1] + ' = ' + str(int(sys.argv[1][0])+int(sys.argv[1][1]))
    else:
        print "El numero no es de dos digitos."
else:
    print "El parametro debe ser un numero entero de dos digitos."
