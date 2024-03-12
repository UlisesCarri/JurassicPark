/*
 *
 * Proyecto Interfaz de Jurassic Park
 * Ulises Orlando Carrizalez Lerín
 * A01027715
 * 13/06/2023
 * versio : c++ standard
 * Esta clase defina objeto de tipo AT (Area de trabajo)
*/

#ifndef at_h
#define at_h

#include "admin.h" //biblioteca con mis objetos a usar (hay puentes ente unos y otros, por lo que solo necesito llamar uno de las bibliotecas y solitas se llaman el resto)


class AT {
  
    //Variables de instancia del objeto
    private: //(Modificador de clase)
    int numEmpleados; //Numero de empleados (Sera usado para navegar en el arreglo de empleados)
    Empleado * emp[20]; //Arrego de empleados

    //Metodos deL objeto
    public: //(Modificador de clase)
    AT(); //Metodo constructo de Area de trabajo

    void generarEjemplo(); //Registra a los empleados base del codigo

    void mostrarPlanta(int adm); //Metodo para administradores con el objetivo de revisar los empleados de su area de trabajo

    void agregarEmpleado(int adm, std::string admi); //Metodo para administradores con el objetivo de agregar nuevos empleados a sus areas de trabajo

    Empleado * encontrarEmpleado(int mat); //Metodo nos permite buscara a los empleados en base a su matricula
};

AT :: AT(){
    numEmpleados = 0;
}

//Reliza el arreglo de empleados base
void AT :: generarEjemplo(){ 
    emp[numEmpleados] = new Planta("Programador general" , "Jorge Castillo" , 21986795 , 9 , 1 , "Ulises Carrizalez",2);
    numEmpleados++;
    emp[numEmpleados] = new Planta("Programador de seguridad" , "Ray Arnold" , 21293648 , 8 , 1 , "Ulises Carrizalez",2);
    numEmpleados++;
    emp[numEmpleados] = new Planta("Programador de sistema" , "Dennis Nedry" , 21986795 , 8 , 1 , "Ulises Carrizalez",2);
    numEmpleados++;
    emp[numEmpleados] = new Planta("Cientifico general" , "Henry Wu" , 22948753 , 8, 2 , "John Hammond",2);
    numEmpleados++;
    emp[numEmpleados] = new Planta("Cientifico en ADN" , "Jim Howard O'Conel " , 22036248 , 8 , 2 , "John Hammond",2);
    numEmpleados++;
    emp[numEmpleados] = new Planta("Cientifico en Clonacion" , "Liam Smith Miller" , 22635281 , 8 , 2 , "John Hammond",2);
    numEmpleados++;
    emp[numEmpleados] = new Planta("Seguridad de laboratorio" , "Robert Muldoon" , 23948753 , 8 , 3 , "Alexander Carrizalez",2);
    numEmpleados++;
    emp[numEmpleados] = new Planta("Seguridad de entrada" , "Bob Peck" , 23125360 , 8 , 3 , "Alexander Carrizalez",2);
    numEmpleados++;
    emp[numEmpleados] = new Planta("Seguridad de lobby" , "Gerry Harding" , 23452306 , 9 , 3 , "Alexander Carrizalez",2);
    numEmpleados++;
    emp[numEmpleados] = new Administrador("Programador en Jefe" , "Ulises Carrizalez" , 11203602 , 10 , 1, 15263 , "Ul15e5" , "+52 55 1637 0125" , "Parque de Dizca 74",1);
    numEmpleados++;
    emp[numEmpleados] = new Administrador("Cientifico en Jefe" , "John Hammond" , 12023562 , 12 , 2, 19230 , "JP1993" , "+1 18 0234 5620" , "HAM num 1350",1);
    numEmpleados++;
    emp[numEmpleados] = new Administrador("Seguridad en Jefe" , "Alexander Carrizalez" , 13026587 , 10 , 3, 16530 , "AL2136M" , "+52 55 4520 1369" , "Parque de Dizca 75",1);
    numEmpleados++;
}

/*
*Usa un ciclo for para revisar todo los empleado del arreglo y compara a todos los tipos de empelado con el del administrador,
*finalmente si encuetra alguno se asegura de que no este registrado con un rango de administrador (osea 1)
*/
void AT :: mostrarPlanta(int adm){
    for (int i = 0; i < numEmpleados; i++){
        int tip= emp[i] -> get_Tipo_de_Empleado();
        if (adm == tip and emp[i] -> Empleado::get_Rango() != 1){
            emp[i] -> imprime_info();
        }
    }
}
/*
*Solicita toda la informacion necesaria para realizar el objeto Planta sin contar el Rango (usa 2 por defult), 
*Tipo y Administrador (se le coloca los del Administrador) (No puede diferenciar entre las matriuclas ya existentes y las nuevas)
*/
void AT :: agregarEmpleado(int adm, std::string admi){
    std::string nom;
    std::string pue;
    int mat;
    float Tiempo_Trabajo;
    cout<<"Dame el nombre del nuevo empleado: "<<endl;
    cin>> nom;
    cout<<"Dame el puesto del nuevo empleado: "<<endl;
    cin>> pue;
    cout<<"Dame la matricula del nuevo empleado: "<<endl;
    cin>> mat;
    cout<<"Dame tiempo de trabajo diario del nuevo empleado: "<<endl;
    cin>> Tiempo_Trabajo;
    emp[numEmpleados] = new Planta(pue , nom , mat , Tiempo_Trabajo , adm , admi, 2);
    numEmpleados++;
}
/*
*Para encontrar a los empleados usa la matricula, el programa consigue con un ciclo for las matriculas de 
*los empeados del arreglo y si encuentra una considencia, regresa la informacion del empleado. (Si no 
*lo encuenta, dentiene el programa)
*/
Empleado * AT :: encontrarEmpleado(int mat){
    
    for (int i = 0; i < numEmpleados; i++){
        if (emp[i] -> Empleado::get_Matricula() == mat){
            return emp[i];
            break;
        }
    }
}


#endif