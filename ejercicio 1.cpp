#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Empleado {
    string cedula;
    string nombre;
    int tipoEmpleado;
    double precioHora;
    int horasLaboradas;
    double salarioOrdinario;
    double aumento;
    double salarioBruto;
    double deduccionCCSS;
    double salarioNeto;
};

void mostrarDatosEmpleado(const Empleado& empleado) {
    cout << "\nCedula: " << empleado.cedula << endl;
    cout << "Nombre Empleado: " << empleado.nombre << endl;
    cout << "Tipo Empleado: " << empleado.tipoEmpleado << endl;
    cout << "Salario por Hora: " << empleado.precioHora << endl;
    cout << "Cantidad de Horas: " << empleado.horasLaboradas << endl;
    cout << "Salario Ordinario: " << empleado.salarioOrdinario << endl;
    cout << "Aumento: " << empleado.aumento << endl;
    cout << "Salario Bruto: " << empleado.salarioBruto << endl;
    cout << "Deducción CCSS: " << empleado.deduccionCCSS << endl;
    cout << "Salario Neto: " << empleado.salarioNeto << endl;
}

void mostrarEstadisticas(int cantOperarios, double acumNetoOperarios, int cantTecnicos, double acumNetoTecnicos, int cantProfesionales, double acumNetoProfesionales) {
    double promedioNetoOperarios = cantOperarios ? acumNetoOperarios / cantOperarios : 0;
    double promedioNetoTecnicos = cantTecnicos ? acumNetoTecnicos / cantTecnicos : 0;
    double promedioNetoProfesionales = cantProfesionales ? acumNetoProfesionales / cantProfesionales : 0;

    cout << "\nEstadísticas:" << endl;
    cout << "1) Cantidad Empleados Tipo Operarios: " << cantOperarios << endl;
    cout << "2) Acumulado Salario Neto para Operarios: " << acumNetoOperarios << endl;
    cout << "3) Promedio Salario Neto para Operarios: " << promedioNetoOperarios << endl;
    cout << "4) Cantidad Empleados Tipo Técnico: " << cantTecnicos << endl;
    cout << "5) Acumulado Salario Neto para Técnicos: " << acumNetoTecnicos << endl;
    cout << "6) Promedio Salario Neto para Técnicos: " << promedioNetoTecnicos << endl;
    cout << "7) Cantidad Empleados Tipo Profesional: " << cantProfesionales << endl;
    cout << "8) Acumulado Salario Neto para Profesionales: " << acumNetoProfesionales << endl;
    cout << "9) Promedio Salario Neto para Profesionales: " << promedioNetoProfesionales << endl;
}

int main() {
    vector<Empleado> empleados;
    char continuar;
    int cantOperarios = 0, cantTecnicos = 0, cantProfesionales = 0;
    double acumNetoOperarios = 0, acumNetoTecnicos = 0, acumNetoProfesionales = 0;

    do {
        Empleado emp;
        cout << "Ingrese la cedula del empleado: ";
        cin >> emp.cedula;
        cout << "Ingrese el nombre del empleado: ";
        cin.ignore(); // Para limpiar el buffer de entrada
        getline(cin, emp.nombre);
        cout << "Ingrese el tipo de empleado (1-Operario, 2-Tecnico, 3-Profesional): ";
        cin >> emp.tipoEmpleado;
        cout << "Ingrese el precio por hora: ";
        cin >> emp.precioHora;
        cout << "Ingrese la cantidad de horas laboradas: ";
        cin >> emp.horasLaboradas;

        emp.salarioOrdinario = emp.precioHora * emp.horasLaboradas;

        switch (emp.tipoEmpleado) {
            case 1:
                emp.aumento = emp.salarioOrdinario * 0.15;
                cantOperarios++;
                acumNetoOperarios += emp.salarioNeto;
                break;
            case 2:
                emp.aumento = emp.salarioOrdinario * 0.10;
                cantTecnicos++;
                acumNetoTecnicos += emp.salarioNeto;
                break;
            case 3:
                emp.aumento = emp.salarioOrdinario * 0.05;
                cantProfesionales++;
                acumNetoProfesionales += emp.salarioNeto;
                break;
            default:
                emp.aumento = 0;
        }

        emp.salarioBruto = emp.salarioOrdinario + emp.aumento;
        emp.deduccionCCSS = emp.salarioBruto * 0.0917;
        emp.salarioNeto = emp.salarioBruto - emp.deduccionCCSS;

        mostrarDatosEmpleado(emp);
        empleados.push_back(emp);

        cout << "¿Desea ingresar otro empleado? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    for (size_t i = 0; i < empleados.size(); ++i) {
        const Empleado& emp = empleados[i];
        switch (emp.tipoEmpleado) {
            case 1:
                acumNetoOperarios += emp.salarioNeto;
                break;
            case 2:
                acumNetoTecnicos += emp.salarioNeto;
                break;
            case 3:
                acumNetoProfesionales += emp.salarioNeto;
                break;
        }
    }

    mostrarEstadisticas(cantOperarios, acumNetoOperarios, cantTecnicos, acumNetoTecnicos, cantProfesionales, acumNetoProfesionales);

    return 0;
}


