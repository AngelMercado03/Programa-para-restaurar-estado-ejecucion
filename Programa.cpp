#include <iostream>
#include <fstream>

// Estructura para almacenar el estado
struct Estado {
    int variable1;
    double variable2;
    // Agrega más variables según sea necesario
};

// Función para guardar el estado en un archivo
void guardarEstado(const Estado& estado, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::binary);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<const char*>(&estado), sizeof(Estado));
        archivo.close();
        std::cout << "Estado guardado correctamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
    }
}

// Función para cargar el estado desde un archivo
Estado cargarEstado(const std::string& nombreArchivo) {
    Estado estado;
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&estado), sizeof(Estado));
        archivo.close();
        std::cout << "Estado cargado correctamente." << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
    }
    return estado;
}

int main() {
    // Ejemplo de uso
    Estado estadoActual = {42, 3.14};  // Puedes inicializar con el estado actual de tus variables
    guardarEstado(estadoActual, "estado.bin");

    // Simular cambios en el estado
    estadoActual.variable1 = 99;
    estadoActual.variable2 = 2.718;

    // Restaurar el estado
    Estado estadoRestaurado = cargarEstado("estado.bin");

    // Verificar que el estado se haya restaurado correctamente
    std::cout << "Variable1 después de restaurar: " << estadoRestaurado.variable1 << std::endl;
    std::cout << "Variable2 después de restaurar: " << estadoRestaurado.variable2 << std::endl;

    return 0;
}
