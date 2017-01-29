#!/usr/bin/python3

#
# Mario Arturo Perez Rangel
# Recibe dos numeros, el primero para encontrar el punto
# diametralmente opuesto a el, colocados segun el segundo numero
# a distancias iguales en un circulo.
# El punto diametralmente opuesto no existe cuando se coloca
# un punto impar de puntos.
import sys
import re

m=0
n=4

#
# Manejo de los parametros en linea de comandos
#
if len(sys.argv) == 1:
    print "Uso: "+sys.argv[0]+" m n"
    print "Donde: n es la cantidad de numeros consecutivos"
    print "         a posicionar en un circulo"
    print "       m es un numero entero."
    exit (2)

if len(sys.argv) > 3:
    print "El programa solo requiere dos numeros enteros, "\
        "ignorando los demas parametros."

#
# Revisa si los parametros cumplen las condiciones
# 4<=n<=20  y  0<=m<=n-1
if (not re.match("^[0-9]+$", sys.argv[2])):
    print "El segundo valor debe ser un numero entero."
    print "Tomando 4 por default."
else:
    n = int(sys.argv[2])
    if not ((n>=4) and (n<=20)):
        print "El segundo numero debe estar entre 4 y 20."
        exit (3)

if (not re.match("^[0-9]+$", sys.argv[1])):
    print "El primer valor debe ser un numero entero."
    exit(2)
else:
    m = int(sys.argv[1])
    if not ((m>=0) and (m<n)):
        print "El primer valor debe estar entre cero y "+str(n)+".\n"
        exit (4)

if (n%2):
    print "No se puede encontrar el punto diametralmente opuesto"
    print "en un circulo con una cantidad non de numeros"
    exit (5)

# El punto diametralmente opuesto es equivalente a sumar la mitad
# de los puntos colocados en el circulo modulo el numero de puntos
print "El numero diametralmente opuesto de "+sys.argv[1]+" es "+str((m+(n/2))%n)+"."
