#!/usr/bin/python3

# Mario Arturo Perez Rangel
# Maximo valor representable por un numero de n digitos
#    1<=n<=8

import sys
import re

# Si no hay parametro no tiene caso continuar.
if len(sys.argv) == 1:
    print "Se necesita un numero entero."
    print "Uso: " + sys.argv[0] + " valor"
    print "Donde valor es un numero entero entre 1 y 8."
    exit (1)

# Si hay mas de dos parametros solo tomamos el primero.
if len(sys.argv) > 2:
    print "Solo se requiere un parametro, ignorando los demas."

# Revisa que se trate de un numero entero positivo de un digito
if re.match("^[0-9]$",sys.argv[1]):
    if  (sys.argv[1] >= '1') and (sys.argv[1]<='8'):
        m=''
        for i in range(int(sys.argv[1])):
            m+='9'
        print "El valor maximo representable por un numero de " +\
        sys.argv[1] + " digito(s) es : " + m
    else:
        print "El numero es 0 o 9."
else:
    print "El parametro debe ser un numero entero entre 1 y 8."
