#include "include/anfibio.h"
#include "include/ave.h"
#include "include/mamifero.h"
#include "include/pez.h"
#include "include/reptil.h"

#include "include/antropodo.h"
#include "include/molusco.h"
#include "include/equinodermo.h"
#include "include/gusano.h"
#include "include/porifero.h"
#include "include/celentereo.h"

#include "algorithm"
#include "fstream"
#include "iomanip"
#include "iostream"
#include "vector"

using namespace std;

// índice de cada grupo en el array
static const int MAMIFEROS = 0;
static const int AVES = 1;
static const int PECES = 2;
static const int ANFIBIOS = 3;
static const int REPTILES = 4;
static const int ARTROPODOS = 5;
static const int MOLUSCOS = 6;
static const int EQUINODERMOS = 7;
static const int GUSANOS = 8;
static const int PORIFEROS = 9;
static const int CELENTEREOS = 10;

string vertebrados[] = {
    "Mamíferos",
    "Aves",
    "Peces",
    "Anfibios",
    "Reptiles" 
};
string invertebrados[] = {
    "Artrópodos", 
    "Moluscos", 
    "Equinodermos",
    "Gusanos",
    "Poríferos",
    "Celentéreos"
};

vector<string> concatenar_arrays() {
    vector<string> animales;
    for (int i = 0; i < vertebrados->size(); i++) {
        animales.push_back(vertebrados[i]);
    }
    for (int i = 0; i < invertebrados->size(); i++) {
        animales.push_back(invertebrados[i]);
    }
    return animales;
}

vector<vector<string>> get_grupos() {
    // Abrir archivo de texto
    ifstream archivo("data/animales.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir archivo" << endl;
        exit(1);
    }
    
    // Leer archivo y guardar en vector de vectores
    vector<vector<string>> grupos;
    string categoria;
    string animal;
    while (getline(archivo, categoria)) {
        vector<string> grupo;
        grupo.push_back(categoria);
        while (getline(archivo, animal) && !animal.empty()) {
            grupo.push_back(animal);
        }
        grupos.push_back(grupo);
    }
    return grupos;
}

vector<string> set_grupo_aleatorio() {
    vector<vector<string>> _grupos = get_grupos();
    vector<string> _grupo;

    // Generar número aleatorio para elegir grupo y animal
    srand(time(nullptr));
    int grupo_index = rand() % _grupos.size();
    int animal_index = rand() % (_grupos[grupo_index].size() - 1) + 1;
    
    string categoria_actual = _grupos[grupo_index][0];
    string animal_actual = _grupos[grupo_index][animal_index];
    _grupo.push_back(categoria_actual);
    _grupo.push_back(animal_actual);
    return _grupo;
}

int get_total_animales() {
    vector<vector<string>> _grupos = get_grupos();
    int _total_animales = 0;
    for (size_t i = 0; i < _grupos.size(); i++) {
        for (size_t j = 1; j < _grupos[i].size(); j++) {
            _total_animales++;
        }
    }
    return _total_animales;
}

vector<int> calcular_animales_por_tipo() {
    vector<int> _total_animales_por_tipo;

    string path = "data/";
    string extension = ".txt";
    // Array con los nombres de los archivos
    string nombres_archivos[] = {
        "Mamíferos", 
        "Aves",
        "Peces",
        "Anfibios",
        "Reptiles",
        "Artrópodos",
        "Moluscos",
        "Equinodermos",
        "Gusanos",
        "Poríferos",
        "Celentereos"
    };
    int num_archivos = 11; // Cantidad de archivos en el array
    for (int i = 0; i < num_archivos; i++) { // Iterar por cada archivo
        nombres_archivos[i] = path + nombres_archivos[i] + extension;
        ifstream archivo(nombres_archivos[i]); // Abrir el archivo
        if (!archivo.is_open()) {  // Verificar si se pudo abrir el archivo
            _total_animales_por_tipo.push_back(0);
            continue;
        }
        int line_count = 0; // Inicializar el contador de líneas
        string line;
        while (getline(archivo, line)) { // Leer línea por línea el archivo
            line_count++; // Incrementar el contador de líneas
        }
        _total_animales_por_tipo.push_back(line_count - 1); // -1 para no contabilizar el titulo del archivo
        archivo.close();
    }
    return _total_animales_por_tipo;
}

int sum_animales() {
    vector<int> _total_animales_por_tipo = calcular_animales_por_tipo();
    int sum = 0;
    for (int i = 0; i < _total_animales_por_tipo.size(); i++) {
        sum += _total_animales_por_tipo[i];
    }
    return sum;
}

vector<int> calcular_por_categoria() {
    vector<int> _cantidad_vertebrados_invertebrados;

    int total_vertebrados = 0;
    int total_invertebrados = 0;
    
    vector<int> _total_animales_por_tipo = calcular_animales_por_tipo();
    
    // vertebrados
    for (int i = 0; i < 5; i++) {
        total_vertebrados += _total_animales_por_tipo[i];
    }
    // invertebrados
    for (int i = 5; i < _total_animales_por_tipo.size(); i++) {
        total_invertebrados += _total_animales_por_tipo[i];
    }
    _cantidad_vertebrados_invertebrados.push_back(total_vertebrados);
    _cantidad_vertebrados_invertebrados.push_back(total_invertebrados);
    return _cantidad_vertebrados_invertebrados;
}

vector<float> calcular_porcentaje_por_tipo() {
    vector<float> _porcentaje_por_tipo;
    vector<int> _total_animales_por_tipo = calcular_animales_por_tipo();
    float porcentaje = 0;
    int total_animales = calcular_por_categoria()[0] + calcular_por_categoria()[1];
    for (size_t i = 0; i < _total_animales_por_tipo.size(); i++) {
        porcentaje = (float) _total_animales_por_tipo[i] / total_animales * 100;
        _porcentaje_por_tipo.push_back(porcentaje);
    }
    return _porcentaje_por_tipo;
}

void insertar_datos(string nombre_archivo, string titulo, Animal* animal) {
    string data_path = "data/";
    string extension = ".txt";
    nombre_archivo = data_path + nombre_archivo + extension;

    // Abrir el archivo en modo append
    ofstream archivo(nombre_archivo, ios::app);

    string nombre_animal = animal->getNombre();

    // Convertimos el nombre del animal a minúsculas para compararlo con las líneas del archivo
    transform(nombre_animal.begin(), nombre_animal.end(), nombre_animal.begin(), [](unsigned char c) {
        return tolower(c);
    });

    if (archivo.is_open()) {
        ifstream archivo_lectura(nombre_archivo); // Verificar que el archivo se ha abierto correctamente
        if (archivo_lectura.peek() == std::ifstream::traits_type::eof()) { // Verificar si el archivo está vacío
            archivo << titulo << endl; // Insertar el título al principio
        } else {
            string primera_linea;
            getline(archivo_lectura, primera_linea); // Leer la primera línea del archivo
            if (primera_linea != titulo) { // Verificar si la primera línea es un título
                archivo.seekp(0, ios::beg); // Mover el cursor al principio del archivo
                archivo << titulo << endl; // Insertar el título al principio
            }
        }
        archivo_lectura.close(); // Cerrar el archivo de lectura
        // Escribir los datos del animal en el archivo
        if (Anfibio* anfibio = dynamic_cast<Anfibio*>(animal)) {
            archivo << endl << anfibio->getNombre() << " " << anfibio->getPeso() << " " << anfibio->getColor() << " " << anfibio->getPielBabosa() << endl;
        } else if (Ave* ave = dynamic_cast<Ave*>(animal)) {
            archivo << endl << ave->getNombre() << " " << ave->getPeso() << " " << ave->getColor() << " " << ave->getCantidadAlas() << endl;
        } else if (Mamifero* mamifero = dynamic_cast<Mamifero*>(animal)) {
            archivo << endl << mamifero->getNombre() << " " << mamifero->getPeso() << " " << mamifero->getColor() << " " << mamifero->getCantidadPatas() << endl;
        } else if (Pez* pez = dynamic_cast<Pez*>(animal)) {
            archivo << endl << pez->getNombre() << " " << pez->getPeso() << " " << pez->getColor() << " " << pez->getCantidadAletas() << " " << pez->getEscamas() << endl;
        } else if (Reptil* reptil = dynamic_cast<Reptil*>(animal)) {
            archivo << endl << reptil->getNombre() << " " << reptil->getPeso() << " " << reptil->getColor() << " " << reptil->getTipo() << endl;
        } else if (Antropodo* antropodo = dynamic_cast<Antropodo*>(animal)) {
            archivo << endl << antropodo->getNombre() << " " << antropodo->getPeso() << " " << antropodo->getColor() << " " << antropodo->getCantidadParesPatas() << " " << antropodo->getAntenas() << endl;
        } else if (Molusco* molusco = dynamic_cast<Molusco*>(animal)) {
            archivo << endl << molusco->getNombre() << " " << molusco->getPeso() << " " << molusco->getColor() << " " << molusco->getTipoConcha() << endl;
        } else if (Equinodermo* equinodermo = dynamic_cast<Equinodermo*>(animal)) {
            archivo << endl << equinodermo->getNombre() << " " << equinodermo->getPeso() << " " << equinodermo->getColor() << " " << equinodermo->getTipo() << endl;
        } else if (Gusano* gusano = dynamic_cast<Gusano*>(animal)) {
            archivo << endl << gusano->getNombre() << " " << gusano->getPeso() << " " << gusano->getColor() << " " << gusano->getTipo() << endl;
        } else if (Porifero* porifero = dynamic_cast<Porifero*>(animal)) {
            archivo << endl << porifero->getNombre() << " " << porifero->getPeso() << " " << porifero->getColor() << endl;
        } else if (Celentereo* celentereo = dynamic_cast<Celentereo*>(animal)) {
            archivo << endl << celentereo->getNombre() << " " << celentereo->getPeso() << " " << celentereo->getColor() << " " << celentereo->getCantidadTentaculos() << endl;
        } else {
            exit(1);
        }
    }
}

void menu_1() {
    string categoria_actual = set_grupo_aleatorio()[0];
    string animal_actual = set_grupo_aleatorio()[1];

    cout << endl;
    cout << "=== Animal Aleatorio ===" << endl;
    cout << "Nombre: " << animal_actual << endl;
    cout << "Grupo: " << categoria_actual << endl;

    string nombre;
    string peso;
    string color;

    nombre = animal_actual;
    cout << "Peso: ";
    cin >> peso;
    cout << "Color: ";
    cin >> color;

    Animal* animalObj = nullptr;
    string titulo = "";
    if (categoria_actual.compare("Anfibios") == 0) {
        string piel_babosa;
        cout << "¿Tiene la piel babosa? (Si o No) ";
        cin >> piel_babosa;
        bool is_piel_babosa = (piel_babosa == "Si") ? true : false;
        Anfibio* anfibio = new Anfibio(nombre, peso, color, is_piel_babosa);
        animalObj = anfibio;
        titulo = "Nombre Peso Color Piel(Babosa o No)";
    } else if (categoria_actual.compare("Aves") == 0) {
        int cantidad_alas;
        cout << "N° de alas: ";
        cin >> cantidad_alas;
        Ave* ave = new Ave(nombre, peso, color, cantidad_alas);
        animalObj = ave;
        titulo = "Nombre Peso Color N°Alas";
    } else if (categoria_actual.compare("Mamíferos") == 0) {
        int cantidad_patas;
        cout << "N° de patas: ";
        cin >> cantidad_patas;
        Mamifero* mamifero = new Mamifero(nombre, peso, color, cantidad_patas);
        animalObj = mamifero;
        titulo = "Nombre Peso Color N°Patas";
    } else if (categoria_actual.compare("Peces") == 0) {
        int cantidad_aletas;
        cout << "N° de aletas: ";
        cin >> cantidad_aletas;
        string escamas;
        cout << "¿Tiene escamas? (Si o No) ";
        cin >> escamas;
        bool is_escamas = (escamas == "Si") ? true : false;
        Pez* pez = new Pez(nombre, peso, color, cantidad_aletas, is_escamas);
        animalObj = pez;
        titulo = "Nombre Peso Color N°Aletas Escamas(Si o No)";
    } else if (categoria_actual.compare("Reptiles") == 0) {
        string tipo;
        cout << "Tipo(Tierra, Mar o Ambas): ";
        cin >> tipo;
        Reptil* reptil = new Reptil(nombre, peso, color, tipo);
        animalObj = reptil;
        titulo = "Nombre Peso Color Tipo(Tierra, Mar o Ambos)";
    } else if (categoria_actual.compare("Artrópodos") == 0) {
        int cantidad_pares_patas;
        cout << "N°Pares de Patas: ";
        cin >> cantidad_pares_patas;
        string antenas;
        cout << "¿Tiene antenas? (Si o No) ";
        cin >> antenas;
        bool is_antenas = (antenas == "Si") ? true : false;
        Antropodo* pez = new Antropodo(nombre, peso, color, cantidad_pares_patas, is_antenas);
        animalObj = pez;
        titulo = "Nombre Peso Color N°Pares de Patas Antenas(Si o No)";
    } else if (categoria_actual.compare("Moluscos") == 0) {
        string tipo;
        cout << "Tipo de Concha: ";
        cin >> tipo;
        Molusco* molusco = new Molusco(nombre, peso, color, tipo);
        animalObj = molusco;
        titulo = "Nombre Peso Color Tipo de Concha";
    } else if (categoria_actual.compare("Equinodermos") == 0) {
        string tipo;
        cout << "Tipo(Estrella o Erizo): ";
        cin >> tipo;
        Equinodermo* equinodermo = new Equinodermo(nombre, peso, color, tipo);
        animalObj = equinodermo;
        titulo = "Nombre Peso Color Tipo(Estrella o Erizo)";
    } else if (categoria_actual.compare("Gusanos") == 0) {
        string tipo;
        cout << "Tipo: ";
        cin >> tipo;
        Gusano* gusano = new Gusano(nombre, peso, color, tipo);
        animalObj = gusano;
        titulo = "Nombre Peso Color Tipo de cuerpo";
    } else if (categoria_actual.compare("Poríferos") == 0) {
        Porifero* porifero = new Porifero(nombre, peso, color);
        animalObj = porifero;
        titulo = "Nombre Peso Color";
    } else if (categoria_actual.compare("Celentéreos") == 0) {
        int cantidad_tentaculos;
        cout << "N° de tentaculos: ";
        cin >> cantidad_tentaculos;
        Celentereo* celentereo = new Celentereo(nombre, peso, color, cantidad_tentaculos);
        animalObj = celentereo;
        titulo = "Nombre Peso Color N°De Tentaculos";
    } else {
        cout << "Categoría no encontrada" << endl;
        exit(1);
    }
    insertar_datos(categoria_actual, titulo, animalObj);
    cout << "!Animal insertado correctamente!" << endl;
    cout << endl;
    delete animalObj;
}

void menu_2() {
    vector<vector<string>> _grupos = get_grupos();
    cout << endl;
    for (size_t i = 0; i < _grupos.size(); i++) {
        cout << "=== " << _grupos[i][0] << " ===" << endl;
        for (size_t j = 1; j < _grupos[i].size(); j++) {
            cout << _grupos[i][j] << endl;
        }
        cout << endl;
    }
}

void menu_3() {
    int total_vertebrados = calcular_por_categoria()[0];
    int total_invertebrados = calcular_por_categoria()[1];

    cout << endl;
    cout << "Cantidad total de vertebrados: " << total_vertebrados << endl;
    cout << "Cantidad total de invertebrados: " << total_invertebrados << endl;
    cout << endl;
}

void menu_4() {
    int total_vertebrados = calcular_por_categoria()[0];
    int total_invertebrados = calcular_por_categoria()[1];
    int total_animales = sum_animales();

    // formula = (total_vertebrados/invertebrados / total_animales) * 100
    float porcentaje_vertebrados = (float) total_vertebrados / total_animales * 100;
    float porcentaje_invertebrados = (float) total_invertebrados / total_animales * 100;

    cout << endl;
    cout << "Porcentaje de animales vertebrados en relacional a total de animales: " <<  fixed << setprecision(2) << porcentaje_vertebrados << "%" << endl;
    cout << "Porcentaje de animales invertebrados en relacional a total de animales: " << fixed << setprecision(2) << porcentaje_invertebrados << "%" << endl;
    cout << endl;
}

void menu_5() {

    vector<int> _total_animales_por_tipo = calcular_animales_por_tipo();
    vector<string> animales = concatenar_arrays();
    cout << endl;
    for (size_t i = 0; i < _total_animales_por_tipo.size(); i++) {
        float porcentaje = (float) _total_animales_por_tipo[i] / sum_animales() * 100;
        cout << fixed;
        cout << setprecision(2);
        cout << animales[i] << ": " << porcentaje << "%" << endl;
    }
    cout << endl;
}

void menu_6(string nombre_archivo) {
    string path = "data/";
    string extension = ".txt";
    string ruta_archivo = path  + nombre_archivo + extension;
    ifstream archivo(ruta_archivo);

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo" << endl;
    }

    // Leer y descartar la primera línea
    // string first_line;
    // getline(archivo, first_line);

    cout << endl;

    int line_count = 0;
    string line;
    while (getline(archivo, line)) {
        cout << line << endl;
    }
    cout << endl;
    archivo.close();
}

int main() {
    int opcion;
    do {
        cout << "=== Tarea 1 ===" << endl;
        cout << "1. Guardar animal" << endl;
        cout << "2. Mostrar cantidad de animales por tipo o grupo" << endl;
        cout << "3. Mostrar la cantidad de animales vertebrados e invertebrados presentes en el zoólogico" << endl;
        cout << "4. Mostrar el porcentaje de animales vertebrados e invertebrados presentes en el zoólogicos" << endl;
        cout << "5. Mostrar el porcentaje de cada tipo o grupo de animal en relación al total de animales" << endl;
        cout << "6. Mostrar la lista de animales almacenados en el archivo correspondiente al tipo o grupo deseado" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        string grupo;

        switch (opcion) {
            case 1: 
                menu_1();
            break;
            case 2:
                menu_2();
                break;
            case 3:
                menu_3();
                break;
            case 4:
                menu_4();
                break;
            case 5:
                menu_5();
                break;
            case 6:
                cout << "Por favor, escriba el nombre del tipo o grupo deseado: ";
                cin >> grupo;
                menu_6(grupo);
                break;
            default:
            break;
        }
    } while (opcion != 7);

    return 0;
}