#!/usr/bin/python3

# Mario Arturo Perez Rangel
# Generador de contrasenas.
# Guarda las contrasenas generadas en el archivo ~/.pwdstore, una por linea

from random import seed,randint
import os

archivo_passwords=".pwdstore"
pwdlen=12

#
# Se almacena el password generado en un archivo localizado
# en el directorio HOME del usuario
def almacena_password(password):
    guarda=open(os.environ['HOME']+'/'+archivo_passwords, "a")
    guarda.write(password+"\n")
    guarda.close()

#
# Verifica si la contrasena ya a sido generada anteriormente.
# Regresa 1 si ya existe.
def password_repetido(password):
    if os.path.isfile(os.environ['HOME']+'/'+archivo_passwords):

        # Abrir el archivo en modo binario para tener mas control
        # en el manejo del archivo.
        revisa=open(os.environ['HOME']+'/'+archivo_passwords, "rb")
        pwdleido=revisa.read(pwdlen)
        revisa.seek(1,1) # Avanzar el salto de linea

        # Exploramos linea por linea hasta el fin del archivo
        # o hasta encontrar el password
        while len(pwdleido) > 0:

            # read entrega una cadena binaria, por eso se apoya
            # en str para convertirla a cadena, y se quitan los caracteres
            # extras agregados.
            if password == str(pwdleido)[2:pwdlen+2]:
                return 1 # El password ya se habia generado antes.
            pwdleido=revisa.read(pwdlen)
            revisa.seek(1,1)
        revisa.close()
    return 0

#
# Crea passwords de al menos 10 caracteres.
# Apoyado en la generacion de numeros aletorios crea una combinacion
# de alfanumericos y de puntuacion sin repetir ninguno de ellos.
def gen_password (longitud):
    if (longitud < 10):
        longitud = 10
    alfanumericos="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890"
    especiales=".,;:?!'{}[]\\\"|/_-"
    seed()   # Iniciamos el generador de numeros aleatorios
    password=''
    for i in range(longitud):
        r = randint(1,2)
        if (r==1):
            n = randint(0,len(alfanumericos)-1)
            password += alfanumericos[n]

            # Quita del conjunto el caracter ya elegido.
            alfanumericos = alfanumericos[:n] + alfanumericos[n+1:]
        else:
            n = randint(0,len(especiales)-1)
            password+=especiales[n]

            # Quita del conjunto el caracter ya elegido.
            especiales = especiales[:n] + especiales[n+1:]
    return password



contrasena = gen_password (pwdlen)

while (password_repetido(contrasena)):
    contrasena = gen_password (pwdlen)

print (contrasena)
almacena_password(contrasena)
