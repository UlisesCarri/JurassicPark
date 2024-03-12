/*
 *
 * Proyecto Interfaz de Jurassic Park
 * Ulises Orlando Carrizalez Lerín
 * A01027715
 * 13/06/2023
 * versio : c++ standards
 * Esta clase defina objeto de tipo Planta (Empleado de Planta) que hereda informacion de Empeado
*/

#ifndef planta_h
#define planta_h

#include "empleado.h" //biblioteca con mis objetos a usar (hay puentes ente unos y otros, por lo que solo necesito llamar uno de las bibliotecas y solitas se llaman el resto)

//Se declara objeto Planta que hereda de Empleado
class Planta: public Empleado {
  
  //Variables de instancia del objeto
  private: //(Modificador de clase)
    std::string Administrador_Area; //Es la variable del nombre del Administrador

  //Metodos del objeto
  public: //(Modificador de clase)
    Planta(std::string Pue, std::string  Nom, int Mat, float Tiempo_Trabajo, int Tipo, std::string  Admi, int Ran ); //Constructor del empleado de palata
    
    void imprime_info(); //Con este metodo imprimimos la informacion basica del empelado de planta (Sobrecarga)
};

Planta :: Planta (std::string Pue, std::string  Nom, int Mat, float Tiempo_Trabajo, int Tipo, std::string  Admi, int Ran ) : Empleado (Pue, Nom, Mat, Tiempo_Trabajo, Tipo, Ran){
    Administrador_Area= Admi;
}

void Planta :: imprime_info (){
    cout << "_______________________________________ \n" ;
    Empleado :: imprime_info();
    cout << "Administrador: " << Administrador_Area << endl;
    cout << "_______________________________________ \n\n" ;
}

#endif