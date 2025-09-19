def calcular_factorial():
    repetir = 1
    while repetir == 1:
        numero = int(input("Ingrese un número entero positivo: "))

        if numero < 0:
            print("El factorial no está definido para números negativos.")
        else:
            number = 1
            for i in range(1, numero + 1):
                number = number * i
            print(str(numero) + "! = " + str(number))

        print("\n¿Desea calcular otro factorial?")
        print("1. Sí")
        print("2. Regresar al menú")
        repetir = int(input("Seleccione una opción: "))


def calcular_subsidio():
    cantidad_hijos = int(input("Ingrese cantidad de hijos: "))
    subsidio = 0
    total_extra = 0

    if cantidad_hijos == 3:
        subsidio = 300
    elif cantidad_hijos >= 4 and cantidad_hijos <= 5:
        subsidio = 350
    elif cantidad_hijos > 5:
        subsidio = 400

    if subsidio > 0:
        for i in range(1, cantidad_hijos + 1):
            edad = int(input("Edad del hijo " + str(i) + ": "))
            if edad >= 7 and edad <= 18:
                total_extra = total_extra + subsidio * 0.06
        subsidio_total = subsidio + total_extra
        print("El subsidio total es: Q" + str(subsidio_total))
    else:
        print("No aplica subsidio para menos de 3 hijos.")


def mostrar_menu():
    print("\n--- MENÚ PRINCIPAL ---")
    print("1. Factorial de un número")
    print("2. Determinar subsidio de familia")
    print("3. Salir")


def main():
    opcion = 0
    while opcion != 3:
        mostrar_menu()
        opcion = int(input("Seleccione una opción: "))

        if opcion == 1:
            calcular_factorial()
        elif opcion == 2:
            calcular_subsidio()
        elif opcion == 3:
            print("Saliendo del programa...")
        else:
            print("Opción inválida. Intente de nuevo.")


main()