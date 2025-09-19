import random
import string

MAX = 100

def esperar():
    input("\nPresione ENTER para continuar...")

def imprimir_matriz(matriz):
    for fila in matriz:
        print("\t".join(str(x) for x in fila))

def llenar_matriz_manual(filas, columnas):
    matriz = []
    for i in range(filas):
        fila = []
        for j in range(columnas):
            while True:
                try:
                    val = int(input(f"matriz[{i}][{j}] = "))
                    fila.append(val)
                    break
                except ValueError:
                    print("Valor invalido, ingrese un entero.")
        matriz.append(fila)
    return matriz

def llenar_matriz_aleatorio(filas, columnas, rango=100):
    return [[random.randint(0, rango-1) for _ in range(columnas)] for _ in range(filas)]

def suma_y_transpuesta():
    repetir = 's'
    while repetir.lower() == 's':
        print("\n--- SUMA DE MATRICES Y TRANSPUESTA ---")
        n = int(input("Ingrese numero de filas: "))
        m = int(input("Ingrese numero de columnas: "))

        opcion = input("Desea llenar las matrices manualmente (1) o aleatoriamente (2)? ")

        if opcion == '1':
            matriz1 = llenar_matriz_manual(n, m)
            matriz2 = llenar_matriz_manual(n, m)
        else:
            matriz1 = llenar_matriz_aleatorio(n, m)
            matriz2 = llenar_matriz_aleatorio(n, m)
            print("\nPrimera matriz:")
            imprimir_matriz(matriz1)
            print("\nSegunda matriz:")
            imprimir_matriz(matriz2)

        suma = [[matriz1[i][j] + matriz2[i][j] for j in range(m)] for i in range(n)]

        print("\nMatriz suma:")
        imprimir_matriz(suma)

        transpuesta = [[suma[j][i] for j in range(n)] for i in range(m)]

        print("\nTranspuesta de la suma:")
        imprimir_matriz(transpuesta)

        repetir = input("\nDesea repetir esta opcion? (s/n): ")

def multiplicacion_matrices():
    repetir = 's'
    while repetir.lower() == 's':
        print("\n--- MULTIPLICACION DE MATRICES ---")
        while True:
            f1 = int(input("Filas de la primera matriz: "))
            c1 = int(input("Columnas de la primera matriz: "))
            f2 = int(input("Filas de la segunda matriz: "))
            c2 = int(input("Columnas de la segunda matriz: "))
            if c1 != f2:
                print("Error: columnas de la primera deben coincidir con filas de la segunda.")
            else:
                break

        opcion = input("Desea llenar las matrices manualmente (1) o aleatoriamente (2)? ")

        if opcion == '1':
            m1 = llenar_matriz_manual(f1, c1)
            m2 = llenar_matriz_manual(f2, c2)
        else:
            m1 = llenar_matriz_aleatorio(f1, c1, 10)
            m2 = llenar_matriz_aleatorio(f2, c2, 10)
            print("\nPrimera matriz:")
            imprimir_matriz(m1)
            print("\nSegunda matriz:")
            imprimir_matriz(m2)

        res = [[0 for _ in range(c2)] for _ in range(f1)]

        for i in range(f1):
            for j in range(c2):
                for k in range(c1):
                    res[i][j] += m1[i][k] * m2[k][j]

        print("\nResultado:")
        imprimir_matriz(res)

        repetir = input("\nDesea repetir esta opcion? (s/n): ")

def buscar_en_matriz():
    repetir = 's'
    while repetir.lower() == 's':
        print("\n--- BUSCAR NUMERO EN MATRIZ ---")
        n = int(input("Filas de la matriz: "))
        m = int(input("Columnas de la matriz: "))

        opcion = input("Desea llenar la matriz manualmente (1) o aleatoriamente (2)? ")

        if opcion == '1':
            matriz = llenar_matriz_manual(n, m)
        else:
            matriz = llenar_matriz_aleatorio(n, m, 50)
            print("\nMatriz generada:")
            imprimir_matriz(matriz)

        buscar = int(input("Numero a buscar: "))

        encontrado = False
        for i in range(n):
            for j in range(m):
                if matriz[i][j] == buscar:
                    print(f"Numero encontrado en posicion [{i}][{j}]")
                    encontrado = True
                    break
            if encontrado:
                break

        if not encontrado:
            print("Numero no encontrado.")

        repetir = input("\nDesea repetir esta opcion? (s/n): ")

def contar_palabras():
    repetir = 's'
    while repetir.lower() == 's':
        frase = input("\n--- CONTAR PALABRAS ---\nIngrese una frase: ")
        palabras = frase.strip().split()
        print(f"Cantidad de palabras: {len(palabras)}")
        repetir = input("\nDesea repetir esta opcion? (s/n): ")

def ordenar_letras():
    repetir = 's'
    while repetir.lower() == 's':
        frase = input("\n--- ORDENAR LETRAS ---\nIngrese una cadena: ")
        ordenada = "".join(sorted(frase))
        print(f"Cadena ordenada: {ordenada}")
        repetir = input("\nDesea repetir esta opcion? (s/n): ")

def detectar_subcadena():
    repetir = 's'
    while repetir.lower() == 's':
        cadena = input("\n--- DETECTAR SUBCADENA ---\nIngrese cadena principal: ")
        subcadena = input("Ingrese subcadena a buscar: ")
        if subcadena in cadena:
            print("La subcadena SI aparece en la cadena.")
        else:
            print("La subcadena NO aparece en la cadena.")
        repetir = input("\nDesea repetir esta opcion? (s/n): ")

def es_palindromo(cadena):
    filtrada = ''.join(ch.lower() for ch in cadena if ch.isalnum())
    return filtrada == filtrada[::-1]

def verificar_palindromo():
    repetir = 's'
    while repetir.lower() == 's':
        cadena = input("\n--- VERIFICAR PALINDROMO ---\nIngrese una cadena: ")
        if es_palindromo(cadena):
            print("La cadena ES un palindromo.")
        else:
            print("La cadena NO es un palindromo.")
        repetir = input("\nDesea repetir esta opcion? (s/n): ")

def main():
    while True:
        print("\n--- MENU PRINCIPAL ---")
        print("1. Suma y transpuesta de matrices")
        print("2. Multiplicacion de matrices")
        print("3. Buscar un numero en una matriz")
        print("4. Contar palabras en una cadena")
        print("5. Ordenar letras de una cadena")
        print("6. Detectar subcadena")
        print("7. Verificar palindromo")
        print("8. Salir")
        opcion = input("Ingrese opcion: ")

        if opcion == '1':
            suma_y_transpuesta()
        elif opcion == '2':
            multiplicacion_matrices()
        elif opcion == '3':
            buscar_en_matriz()
        elif opcion == '4':
            contar_palabras()
        elif opcion == '5':
            ordenar_letras()
        elif opcion == '6':
            detectar_subcadena()
        elif opcion == '7':
            verificar_palindromo()
        elif opcion == '8':
            print("Saliendo...")
            break
        else:
            print("Opcion no valida.")

if __name__ == "__main__":
    random.seed()
    main()
