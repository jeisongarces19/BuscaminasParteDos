#include <stdio.h>
#include <stdlib.h>
//el invariante e suna propiedad que debe cumplir algo o noo cambia nunca.

struct empleado{//tipo empleado
    char* nombre;
    int* cedula;
    char* cargo;
    char* foto;
};

typedef struct empleado tipoempleado;


int main(){
    typedef struct empleado tipoempleado;
    //empleado tipoempleado={"manuela",24324,"jefe","htttp.ggww/foto"};//o tambien

    empleado tipoempleado;
    tipoempleado.nombre="manuela";


}
