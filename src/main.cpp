#include <iostream>
#include <string>
#include "utilerias.h"
#include "ticket.h"
int main() {
    std::cout << "=== SISTEMA DE VENTAS MECATRONICA ===\n";

    // Paso 1: solicitar el nombre del producto
    std::string nombre = leerCadena("Ingrese el nombre del producto: ");

    // Paso 2: solicitar y validar precio, cantidad y descuento
    double precio = leerDecimal("Ingrese el precio unitario: ");
    while (precio <= 0) {
        std::cout << "[ERROR] El precio debe ser mayor a 0. Intente de nuevo.\n";
        precio = leerDecimal("Ingrese el precio unitario: ");
    }

    int cantidad = 0;
    cantidad = leerEntero("Ingrese la cantidad de piezas: ");
    while (cantidad <= 0) {
        std::cout << "[ERROR] La cantidad debe ser mayor a 0. Intente de nuevo.\n";
        cantidad = leerEntero("Ingrese la cantidad de piezas: ");
    }

    double descuento = leerDecimal("Ingrese el porcentaje de descuento (0-99): ");
    while (descuento < 0 || descuento > 99) {
        std::cout << "[ERROR] El descuento debe estar entre 0 y 99. Intente de nuevo.\n";
        descuento = leerDecimal("Ingrese el porcentaje de descuento (0-99): ");
    }

    // Paso 3: calcular los importes
    double subtotal = precio * cantidad;
    double montoDescuento = subtotal * descuento / 100.0;
    double baseImponible = subtotal - montoDescuento;
    double iva = baseImponible * 16.0 / 100.0; // IVA del 16%
    double total = baseImponible + iva;

    // Paso 4: imprimir el ticket
    imprimirTicket(nombre, cantidad, precio, subtotal, montoDescuento, iva, total);
}