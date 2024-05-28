#include <iostream>
#include <string>

using namespace std;

struct Venta {
    int numeroFactura;
    string cedula;
    string nombre;
    int localidad;
    int cantidadEntradas;
    double precioEntrada;
    string nombreLocalidad;
    double subtotal;
    double cargosServicio;
    double totalPagar;
};

int main() {
    const double PRECIO_SOL = 10500.0;
    const double PRECIO_SOMBRA = 20500.0;
    const double PRECIO_PREFERENCIAL = 25500.0;
    const double CARGO_SERVICIO = 1000.0;

    int totalEntradasSol = 0, totalEntradasSombra = 0, totalEntradasPreferencial = 0;
    double acumuladoDineroSol = 0.0, acumuladoDineroSombra = 0.0, acumuladoDineroPreferencial = 0.0;

    char continuar;

    do {
        Venta venta;

        cout << "Ingrese el numero de factura: ";
        cin >> venta.numeroFactura;
        cout << "Ingrese la cedula del comprador: ";
        cin >> venta.cedula;
        cout << "Ingrese el nombre del comprador: ";
        cin.ignore();  // Para limpiar el buffer
        getline(cin, venta.nombre);
        cout << "Ingrese la localidad (1- Sol Norte/Sur, 2- Sombra Este/Oeste, 3- Preferencial): ";
        cin >> venta.localidad;
        do {
            cout << "Ingrese la cantidad de entradas (maximo 4): ";
            cin >> venta.cantidadEntradas;
        } while (venta.cantidadEntradas < 1 || venta.cantidadEntradas > 4);

        switch (venta.localidad) {
            case 1:
                venta.precioEntrada = PRECIO_SOL;
                venta.nombreLocalidad = "Sol Norte/Sur";
                totalEntradasSol += venta.cantidadEntradas;
                acumuladoDineroSol += venta.precioEntrada * venta.cantidadEntradas;
                break;
            case 2:
                venta.precioEntrada = PRECIO_SOMBRA;
                venta.nombreLocalidad = "Sombra Este/Oeste";
                totalEntradasSombra += venta.cantidadEntradas;
                acumuladoDineroSombra += venta.precioEntrada * venta.cantidadEntradas;
                break;
            case 3:
                venta.precioEntrada = PRECIO_PREFERENCIAL;
                venta.nombreLocalidad = "Preferencial";
                totalEntradasPreferencial += venta.cantidadEntradas;
                acumuladoDineroPreferencial += venta.precioEntrada * venta.cantidadEntradas;
                break;
            default:
                cout << "Localidad no válida." << endl;
                continue;
        }

        venta.subtotal = venta.precioEntrada * venta.cantidadEntradas;
        venta.cargosServicio = CARGO_SERVICIO * venta.cantidadEntradas;
        venta.totalPagar = venta.subtotal + venta.cargosServicio;

        cout << "\nNumero de Factura: " << venta.numeroFactura << endl;
        cout << "Cedula: " << venta.cedula << endl;
        cout << "Nombre comprador: " << venta.nombre << endl;
        cout << "Localidad: " << venta.nombreLocalidad << endl;
        cout << "Cantidad de Entradas: " << venta.cantidadEntradas << endl;
        cout << "Subtotal: " << venta.subtotal << endl;
        cout << "Cargos por Servicios: " << venta.cargosServicio << endl;
        cout << "Total a pagar: " << venta.totalPagar << endl;

        cout << "\n¿Desea ingresar otra venta? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "\nEstadísticas:\n";
    cout << "Cantidad Entradas Localidad Sol Norte/Sur: " << totalEntradasSol << endl;
    cout << "Acumulado Dinero Localidad Sol Norte/Sur: " << acumuladoDineroSol << endl;
    cout << "Cantidad Entradas Localidad Sombra Este/Oeste: " << totalEntradasSombra << endl;
    cout << "Acumulado Dinero Localidad Sombra Este/Oeste: " << acumuladoDineroSombra << endl;
    cout << "Cantidad Entradas Localidad Preferencial: " << totalEntradasPreferencial << endl;
    cout << "Acumulado Dinero Localidad Preferencial: " << acumuladoDineroPreferencial << endl;

    return 0;
}

