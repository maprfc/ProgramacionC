#!/usr/bin/python3

# Mario Arturo Perez Rangel
# Suma de dos numeros enteros dados en la linea de comandos.
#
# Usando el modulo de manejo de expresiones regulares revisamos si los parametros son numeros enteros.
#

import sys
import re

# Si no hay dos parametros no tiene caso continuar.
if len(sys.argv) == 1 or len(sys.argv) == 2:
    print "Se necesitan dos parametros enteros."
    print "Uso: " + sys.argv[0] + " entero1 entero2"

# Si hay mas de dos parametros tomamos solo los dos primeros.
if len(sys.argv) > 3:
    print "Solo se requieren dos parametros enteros, se usaran los primeros."

# Un numero entero tiene la forma de una cadena de digitos decimales,
# opcionalmente precedido por el signo de mas o de menos.
if re.match("^[-+]?[0-9]+$",sys.argv[1]) and re.match("^[-+]?[0-9]+$",sys.argv[2]):
    print sys.argv[1] + ' + ' + sys.argv[2] + ' = ' + str(int(sys.argv[1])+int(sys.argv[2]))
else:
    print "Los parametros deben ser numeros enteros."
