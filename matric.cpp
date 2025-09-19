#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 100;

void esperar() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(1000, '\n');
    cin.get();
}

void imprimirMatriz(int matriz[MAX][MAX], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j)
            cout << matriz[i][j] << "\t";
        cout << endl;
    }
}

void sumaYTranspuesta() {
    char repetir;
    do {
        int n, m, opcion;
        int matriz1[MAX][MAX], matriz2[MAX][MAX], suma[MAX][MAX], transpuesta[MAX][MAX];

        cout << "\n--- SUMA DE MATRICES Y TRANSPUESTA ---\n";
        cout << "Ingrese numero de filas: ";
        cin >> n;
        cin.ignore(1000, '\n');
        cout << "Ingrese numero de columnas: ";
        cin >> m;
        cin.ignore(1000, '\n');

        cout << "Desea llenar las matrices manualmente (1) o aleatoriamente (2)? ";
        cin >> opcion;
        cin.ignore(1000, '\n');

        srand(time(0));

        if (opcion == 1) {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    cout << "matriz1[" << i << "][" << j << "] = ";
                    cin >> matriz1[i][j];
                }
            cin.ignore(1000, '\n');
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    cout << "matriz2[" << i << "][" << j << "] = ";
                    cin >> matriz2[i][j];
                }
            cin.ignore(1000, '\n');
        } else {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    matriz1[i][j] = rand() % 100;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    matriz2[i][j] = rand() % 100;

            cout << "\nPrimera matriz:\n";
            imprimirMatriz(matriz1, n, m);
            cout << "\nSegunda matriz:\n";
            imprimirMatriz(matriz2, n, m);
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                suma[i][j] = matriz1[i][j] + matriz2[i][j];

        cout << "\nMatriz suma:\n";
        imprimirMatriz(suma, n, m);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                transpuesta[j][i] = suma[i][j];

        cout << "\nTranspuesta de la suma:\n";
        imprimirMatriz(transpuesta, m, n);

        cout << "\nDesea repetir esta opcion? (s/n): ";
        cin >> repetir;
        cin.ignore(1000, '\n');
    } while (repetir == 's' || repetir == 'S');
}

void multiplicacionMatrices() {
    char repetir;
    do {
        int f1, c1, f2, c2, opcion;
        int m1[MAX][MAX], m2[MAX][MAX], res[MAX][MAX];

        cout << "\n--- MULTIPLICACION DE MATRICES ---\n";

        do {
            cout << "Filas y columnas de la primera matriz:\n";
            cin >> f1 >> c1;
            cin.ignore(1000, '\n');
            cout << "Filas y columnas de la segunda matriz:\n";
            cin >> f2 >> c2;
            cin.ignore(1000, '\n');
            if (c1 != f2)
                cout << "Error: columnas de la primera deben coincidir con filas de la segunda.\n";
        } while (c1 != f2);

        cout << "Desea llenar las matrices manualmente (1) o aleatoriamente (2)? ";
        cin >> opcion;
        cin.ignore(1000, '\n');

        srand(time(0));

        if (opcion == 1) {
            for (int i = 0; i < f1; ++i)
                for (int j = 0; j < c1; ++j) {
                    cout << "m1[" << i << "][" << j << "] = ";
                    cin >> m1[i][j];
                }
            cin.ignore(1000, '\n');
            for (int i = 0; i < f2; ++i)
                for (int j = 0; j < c2; ++j) {
                    cout << "m2[" << i << "][" << j << "] = ";
                    cin >> m2[i][j];
                }
            cin.ignore(1000, '\n');
        } else {
            for (int i = 0; i < f1; ++i)
                for (int j = 0; j < c1; ++j)
                    m1[i][j] = rand() % 10;
            for (int i = 0; i < f2; ++i)
                for (int j = 0; j < c2; ++j)
                    m2[i][j] = rand() % 10;

            cout << "\nPrimera matriz:\n";
            imprimirMatriz(m1, f1, c1);
            cout << "\nSegunda matriz:\n";
            imprimirMatriz(m2, f2, c2);
        }

        for (int i = 0; i < f1; ++i)
            for (int j = 0; j < c2; ++j)
                res[i][j] = 0;

        for (int i = 0; i < f1; ++i)
            for (int j = 0; j < c2; ++j)
                for (int k = 0; k < c1; ++k)
                    res[i][j] += m1[i][k] * m2[k][j];

        cout << "\nResultado:\n";
        imprimirMatriz(res, f1, c2);

        cout << "\nDesea repetir esta opcion? (s/n): ";
        cin >> repetir;
        cin.ignore(1000, '\n');
    } while (repetir == 's' || repetir == 'S');
}

void buscarEnMatriz() {
    char repetir;
    do {
        int n, m, matriz[MAX][MAX], buscar, opcion;
        bool encontrado = false;

        cout << "\n--- BUSCAR NUMERO EN MATRIZ ---\n";
        cout << "Tama�o de la matriz (filas columnas): ";
        cin >> n >> m;
        cin.ignore(1000, '\n');

        cout << "Desea llenar la matriz manualmente (1) o aleatoriamente (2)? ";
        cin >> opcion;
        cin.ignore(1000, '\n');

        srand(time(0));

        if (opcion == 1) {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    cout << "matriz[" << i << "][" << j << "] = ";
                    cin >> matriz[i][j];
                }
            cin.ignore(1000, '\n');
        } else {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    matriz[i][j] = rand() % 50;

            cout << "\nMatriz generada:\n";
            imprimirMatriz(matriz, n, m);
        }

        cout << "Numero a buscar: ";
        cin >> buscar;
        cin.ignore(1000, '\n');

        encontrado = false;
        for (int i = 0; i < n && !encontrado; ++i)
            for (int j = 0; j < m; ++j)
                if (matriz[i][j] == buscar) {
                    cout << "Numero encontrado en posicion [" << i << "][" << j << "]\n";
                    encontrado = true;
                    break;
                }

        if (!encontrado)
            cout << "Numero no encontrado.\n";

        cout << "\nDesea repetir esta opcion? (s/n): ";
        cin >> repetir;
        cin.ignore(1000, '\n');
    } while (repetir == 's' || repetir == 'S');
}

void contarPalabras() {
    char repetir;
    do {
        string frase;
        int contador = 0;
        bool dentroPalabra = false;

        cout << "\n--- CONTAR PALABRAS ---\n";
        cout << "Ingrese una frase: ";
        getline(cin, frase);

        for (size_t i = 0; i < frase.length(); ++i) {
            if (!isspace(frase[i]) && !dentroPalabra) {
                dentroPalabra = true;
                contador++;
            } else if (isspace(frase[i])) {
                dentroPalabra = false;
            }
        }

        cout << "Cantidad de palabras: " << contador << endl;
        cout << "\nDesea repetir esta opcion? (s/n): ";
        cin >> repetir;
        cin.ignore(1000, '\n');
    } while (repetir == 's' || repetir == 'S');
}

void ordenarLetras() {
    char repetir;
    do {
        string frase;
        cout << "\n--- ORDENAR LETRAS ---\n";

        cout << "Ingrese una cadena: ";
        getline(cin, frase);

        sort(frase.begin(), frase.end());

        cout << "Cadena ordenada: " << frase << endl;

        cout << "Desea repetir esta opcion? (s/n): ";
        cin >> repetir;
        cin.ignore(1000, '\n');
    } while (repetir == 's' || repetir == 'S');
}

void detectarSubcadenaMenu() {
    char repetir;
    do {
        string cadena, subcadena;
        cout << "\n--- DETECTAR SUBCADENA ---\n";

        cout << "Ingrese cadena principal: ";
        getline(cin, cadena);
        cout << "Ingrese subcadena a buscar: ";
        getline(cin, subcadena);

        if (cadena.find(subcadena) != string::npos)
            cout << "La subcadena SI aparece en la cadena.\n";
        else
            cout << "La subcadena NO aparece en la cadena.\n";

        cout << "Desea repetir esta opcion? (s/n): ";
        cin >> repetir;
        cin.ignore(1000, '\n');
    } while (repetir == 's' || repetir == 'S');
}

bool esPalindromo(const string& str) {
    string filtrada;
    for (size_t i = 0; i < str.length(); ++i) {
        if (isalnum(str[i]))
            filtrada += tolower(str[i]);
    }
    int izquierda = 0;
    int derecha = filtrada.length() - 1;
    while (izquierda < derecha) {
        if (filtrada[izquierda] != filtrada[derecha])
            return false;
        izquierda++;
        derecha--;
    }
    return true;
}

void verificarPalindromo() {
    char repetir;
    do {
        string cadena;
        cout << "\n--- VERIFICAR PALINDROMO ---\n";
        cout << "Ingrese una cadena: ";
        getline(cin, cadena);

        if (esPalindromo(cadena))
            cout << "La cadena ES un palindromo.\n";
        else
            cout << "La cadena NO es un palindromo.\n";

        cout << "Desea repetir esta opcion? (s/n): ";
        cin >> repetir;
        cin.ignore(1000, '\n');
    } while (repetir == 's' || repetir == 'S');
}

int main() {
    string opcion;
    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Suma y transpuesta de matrices\n";
        cout << "2. Multiplicacion de matrices\n";
        cout << "3. Buscar un numero en una matriz\n";
        cout << "4. Contar palabras en una cadena\n";
        cout << "5. Ordenar letras de una cadena\n";
        cout << "6. Detectar subcadena\n";
        cout << "7. Verificar palindromo\n";
        cout << "8. Salir\n";
        cout << "Ingrese opcion: ";
        getline(cin, opcion);

        if (opcion == "1")
            sumaYTranspuesta();
        else if (opcion == "2")
            multiplicacionMatrices();
        else if (opcion == "3")
            buscarEnMatriz();
        else if (opcion == "4")
            contarPalabras();
        else if (opcion == "5")
            ordenarLetras();
        else if (opcion == "6")
            detectarSubcadenaMenu();
        else if (opcion == "7")
            verificarPalindromo();
        else if (opcion == "8")
            cout << "Saliendo...\n";
        else
            cout << "Opcion no valida.\n";

    } while (opcion != "8");

    return 0;
}