#!/usr/bin/python3

# Mario Arturo Perez Rangel
# Implementacion simple del cifrado Cesar.
# Recibe tres parametros:
#   Un numero entero k que es la llave para cifrar.
#   Una cadena encerrada entre comillas, si no esta entre comillas
#     solo acepta una palabra.
#   Una letra que puede ser e para cifrar la cadena o d descifrar el mensaje.
#
# Solo cifra letras mayusculas.

import sys
import re

alfabeto=['A','B','C','D','E','F','G','H','I',
          'J','K','L','M','N','O','P','Q','R',
          'S','T','U','V','W','X','Y','Z']

#
# Desplaza hacia la "derecha" cada letra mayuscula tantos lugares
# en el alfabeto segun el entero k. Si llega al final empieza desde el inicio.
def cifra(cadena,k):
    mensaje=''
    for i in range(len(cadena)):
        if cadena[i] in alfabeto:
            mensaje += alfabeto[(k + alfabeto.index(cadena[i])) % len(alfabeto)]

        # Los caracteres que no estan en el alfabeto no son cifrados
        else:
            mensaje += cadena[i]
    return mensaje

#
# Desplaza hacia la "izquierda" cada letra mayuscula tantos lugares
# en el alfabeto segun el entero k. Si llega al final empieza desde el final.
def descifra(cadena,k):
    mensaje=''
    for i in range(len(cadena)):
        if cadena[i] in alfabeto:
            mensaje += alfabeto[(alfabeto.index(cadena[i]) - k) % len(alfabeto)]

        # Los caracteres que no estan en el alfabeto no son cifrados
        else:
            mensaje += cadena[i]
    return mensaje

#
# Revision y validacion de los parametros.
#
if len(sys.argv) != 4:
    print "Uso: " + sys.argv[0] + " k m [e|d]"
    print "Donde: k es un numero entero"
    print "       m es una cadena encerrada entre comillas (\"\")"
    print "       e cifrar la cadena, d descifrar el mensaje"
    exit (1)

if (not re.match("^[0-9]+$", sys.argv[1])):
    print "La llave debe ser un numero entero"
    exit (2)

if (sys.argv[3] != 'e') and (sys.argv[3] != 'd'):
    print "Solo debe usar 'e' o 'd' como tercer parametro."

# Cifrado o descifrado del mensaje
if (sys.argv[3] == 'e'):
    mensaje=cifra(sys.argv[2], int(sys.argv[1]))

if (sys.argv[3] == 'd'):
    mensaje=descifra(sys.argv[2], int(sys.argv[1]))

print ("Mensaje cifrado: "+mensaje)
