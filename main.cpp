/*
 *
 * Proyecto Interfaz de Jurassic Park
 * Ulises Orlando Carrizalez Lerín
 * A01027715
 * 13/06/2023
 * versio : 2
 * Como proyecto de TC1030 realize el siguiente trabajo. Este trata de una interfaz 
 * de empleado para Jurassic Park, en esta puede acceder tano administradores como empleados, 
 * los empleados podrán revisar su estatus como empleado (Nombre, Matricula, Área de trabajo 
 * (1,2,3), Sueldo, puesto y administrador a cargo). Mientras que los administradores tendran 
 * las misma capacidad que el empleado de planta, tambien puede enseñar los empleados de su area 
 * de trabajo que estan a su cargo, agregar nuevos empleados, enseñar informacion basica del administrador 
 * y revisar su informacion sencible, pero requiere dar su contraseña para ello, si falla, el programa se 
 * va a burlar cual Jurassic Park. El programa ya tendra de informacion base 3 Areas de trabajo, con 4 empleados 
 * de planta y 1 administrador (La informacion de cada empleado esta en el excel "Empleado JP.xlsx" para que pueda 
 * probar cada empleado).
*/

# include "at.h" //biblioteca con mis objetos a usar (hay puentes ente unos y otros, por lo que solo necesito llamar uno de las bibliotecas y solitas se llaman el resto)

int main(){ //
    int x;
    int y;
    int mat;
    int con;
    AT JP;
    JP.generarEjemplo();
    //Imprime el logo de Jurassic Park y da la bievenida
    cout<<endl<<"Bienvenidos a intefas de empleado de Jurassic Park"<<endl;
    cout<<"                  ,"<<endl;
    cout<<"               ,  ;:._.-`''."<<endl;
    cout<<"             ;.;'.;`      _ `."<<endl;
    cout<<"              ',;`       ( \ ,`-."<<endl;  
    cout<<"           `:.`,         (_/ ;\  `-."<<endl;
    cout<<"            ';:              / `.   `-._"<<endl;
    cout<<"          `;.;'              `-,/ .     `-."<<endl;
    cout<<"          ';;'              _    `^`       `."<<endl;
    cout<<"         ';;            ,'-' `--._          ;"<<endl;
    cout<<"':      `;;        ,;     `.    ':`,,.__,,_ /"<<endl;
    cout<<" `;`:;`;:`       ,;  '.    ;,      ';';':';;`"<<endl;
    cout<<"              .,; '    '-._ `':.;    "<<endl;
    cout<<"            .:; `          '._ `';;,"<<endl;
    cout<<"          ;:` `    :'`'       ',__.)"<<endl;
    cout<<"        `;:;:.,...;'`'"<<endl;
    cout<<"      ';. '`'::'`''  .'`'"<<endl;
    cout<<"    ,'   `';;:,..::;`'`'"<<endl;
    cout<<", .;`      `'::''`"<<endl;
    cout<<",`;`."<<endl;
    while (true){
        //Empieza solicitando que tipo de empleado es
        cout<<"_______________________________________"<<endl;
        cout<<"Indique el tipo de empleado que es (insertar el numero de opcion):"<<endl<<"1. Administrador"<<endl<<"2. Empleado de planta"<<endl<<"3. Apagar sistema"<<endl;
        cin >> x;
        cout<<endl<<"_______________________________________"<<endl;
        if (x == 1){//Si es un Administrador
            cout<<"Dame tu matricula:"<<endl; //Solicita la matricula
            cin >> mat;
            Empleado * trabajador= JP.encontrarEmpleado(mat); //usa .econtrarEmpleado para buscar el empleado en base a su matricula
            if (trabajador -> Empleado::get_Rango() != 1){
                cout<<"ERROR, EL DUENO DE LA MATRICULA NO ES UN ADMINISTRADOR"<<endl; //imprime esto y regresa al inicio si la matricula no es de administrador
            }
            else {
                std::string NombreA= trabajador -> Empleado::get_Nombre();
                while (true){
                    //Despliega el menu de opciones
                    cout<<endl<<"_______________________________________"<<endl;
                    cout<<"Bienvenido "<<NombreA<<" como te puedo ayudar el dia de hoy? (insertar el numero de opcion):"<<endl<<"1. Ensenar informacion de mis empleado de planta de tu area"<<endl<<"2. Agregar empleado de planta"<<endl<<"3. Ensenar mi informacion basica"<<endl<<"4. Ensenar mi informacion avanzada"<<endl<<"5. Cerrar sesion"<<endl;
                    cin>> y;
                    cout<<endl<<"_______________________________________"<<endl;

                    if (y==1){
                        int adm= trabajador -> Empleado::get_Tipo_de_Empleado();
                        JP.mostrarPlanta(adm);
                    }

                    else if (y==2){
                        int adm= trabajador -> Empleado::get_Tipo_de_Empleado();
                        JP.agregarEmpleado(adm, NombreA);
                        cout<<endl<<"_______________________________________"<<endl;
                    }

                    else if (y==3){
                        trabajador -> imprime_info();
                    }

                    else if (y==4){ //Solicita la contrasena para enseñar la infromacion avanzada del Administrador
                        cout<<"Contrasena de acceso: "<<endl;
                        cin>> con;
                        /*
                        *"dynamic_cast" es una funcion que nos permite  realizar una conversión segura de tipos en tiempo de ejecución, 
                        *en este codigo lo que hace es cambiar el objeto "trabajador (clase Empleado*)" a "trabajador (clase Administrador*)",
                        *una ves que esto se cumple entra el en if y usa el metodo exclusivo de la clase administrador imprime_info(int datosCon) 
                        *para imprimir la infromacion que se solicita. (https://www.ibm.com/docs/es/i/7.5?topic=expressions-dynamic-cast-operator-c-only)
                        */
                        if (Administrador* trabajador = dynamic_cast<Administrador*>(trabajador)) {  
                            trabajador->imprime_info(con);
                        }
                    }

                    else if (y==5){break;}

                    else {
                        cout<<"ERROR DE RESPUESTA, ESA RESPUESTA NO ES PARTE DE LAS OPCIONES, PORFAVOR VUELVA A INTANTAR"<<endl;
                    }
                }
            }
        }

        else if (x == 2) { //Si el usario pone la opcion de Empleado de Planta
            cout<<"Dame tu matricula:"<<endl; //Solicita la matricula
            cin >> mat;
            Empleado * trabajador= JP.encontrarEmpleado(mat);

            if (trabajador -> Empleado::get_Rango() != 2){ //Si no es una matricula de Empleado de Planta Regresa al inicio
                cout<<"ERROR, EL DUENO DE LA MATRICULA NO ES UN EMPLEADO DE PALANTA"<<endl;
            }

            else {
                std::string NombreA= trabajador -> Empleado::get_Nombre();
                while (true){
                    cout<<endl<<"_______________________________________"<<endl; //Despliega la interfas para usarios perdonalizada para el Empleado de planta
                    cout<<"Bienvenido "<<NombreA<<", esta es la informacion que nosotros le podemos proporcionar: "<<endl<<"1. Mi informacion de Empleado"<<endl<<"2. Cerrar sesion"<<endl;
                    cin >> y;

                    if (y == 1){ //imprime la informacion basica del Empleado de Planta
                        trabajador -> imprime_info();
                        cout<<endl<<"_______________________________________"<<endl;
                    }
                    
                    else if (y == 2){break;}
                }
                
            }
        
        }

        else if (x == 3){break;} //Con esta opcion apaga el sistema (cierra el programa)

        else {
            cout<<"ERROR, VUELVA A INTANTAR"<<endl; //Si no se usa ninguna de las opciones, el programa marca error y te regresa al inicio
        }
    }
}