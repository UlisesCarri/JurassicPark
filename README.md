# JurassicPark
# TC1030 - Proyecto - A01027715 - Ulises Orlando Carrizalez Lerín
Como proyecto de TC1030 realice el siguiente trabajo. Este trata de una interfaz de empleado para Jurassic Park, en esta puede acceder tanos administradores como empleados, los empleados podrán revisar su estatus como empleado (Nombre, Matricula, Área de trabajo (1,2,3), Sueldo, puesto y administrador a cargo). Mientras que los administradores tendrán la misma capacidad que el empleado de planta, pero también puede recuperar la información de los empleados de su área de trabajo que están a su cargo, agregar nuevos empleados, enseñar información básica del administrador y revisar su información sensible, pero requiere dar su contraseña para ello, si falla, el programa se va a burlar cual Jurassic Park. El programa ya tendrá de información base de 3 Áreas de trabajo, con 4 empleados de planta y 1 administrador (La información de cada empleado está en el Excel "Empleado JP.xlsx" para que pueda probar cada empleado(El objetivo del excel es meramente informativo, si realiza cambios en el excel no afectara a los datos del programa)).
## Funcionalidad

- Si la matricula del empleado no existe el programa automáticamente se cierra.
- El programa no permite mover empleados ya existentes de un área de trabajo a otra área, solo puede agregar nuevos empleados al arreglo del programa, no eliminarlos.
- Los empleados agregados son temporales, una ves que se detenga el programa, también se perderan los nuevos nuevos empleados.
- El programa no acepta los espacios en el texto de entrada, porque si esto sucede el programa funciona erróneamente y salta entradas de infromacion.
## Consideraciones
- El programa puede correr en la terminal de programación y en la consolaEsta hecho con c++ standard por lo que corre en todos los sistemas operativos, este también ya fue probado en la terminal de Linux del profesor.
- El main se llama "main.cpp", es importante mencionar que hay que descargar todos los .h porque cada uno de ellos contiene una clase diferente y solo funcionan si todas están juntas, ya que todos están interconectados, solo necesitan estar en la mima carpeta para funcionar.

## Referencias
- PNG all. (s/f). LOGO DE JURASSIC PARK PNG Imagen gratis "[Imagen]". Recuperado de https://www.pngall.com/es/jurassic-park-png/download/32911
- IBM. (2023). El operador dynamic_cast (solo C++). Recuperado de https://www.ibm.com/docs/es/i/7.5?topic=expressions-dynamic-cast-operator-c-only
