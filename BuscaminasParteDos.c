#include <stdio.h>
#include <stdlib.h>


struct casilla{//tipo castillo
    char etiqueta;
    char tipo;
    int Minas;
};
typedef struct casilla tipocasilla;

tipocasilla **CrearMatriz(int filas,int columnas){
    tipocasilla **matriz=(tipocasilla **)malloc((filas) * sizeof(tipocasilla *));
    int i;
    for(i=0;i<filas;i++){
        matriz[i]=((tipocasilla *)malloc(columnas * sizeof(tipocasilla)));
    }
    return matriz;
}


void llenar_tablero(int filas,int columnas,tipocasilla **matriz){
  int i;
  for(i=0;i<filas;i++){
    int j;
    for(j=0;j<columnas;j++){
      matriz[i][j].etiqueta='.';
      matriz[i][j].tipo='c';
      matriz[i][j].Minas=0;
    }
  }
}

void imprimir_tablero(int filas,int columnas,tipocasilla **matriz){
    int i;
    int j;
    int t;
    for(t=0;t<columnas;t++){
        printf("  %d ",t);
    }
    for(i=0;i<filas;i++){
      printf("\n");
      for(j=0;j<columnas;j++){
        printf("|");
        printf(" %c ",matriz[i][j].etiqueta);
        //printf(" %d ",matriz[i][j].Minas);
        //printf(" %c ",matriz[i][j].tipo);
      }
      printf("|");
      printf(" %d",i);
      printf("\n");
    }
}

void colocarminas(int filas,int columnas,tipocasilla **matriz,int minas){
    int posfila;
    int poscolumna;
    while(minas>0){
        posfila=rand()%filas;
        poscolumna=rand()%columnas;
        if(matriz[posfila][poscolumna].tipo=='c'){
            matriz[posfila][poscolumna].tipo='M';
            minas--;
        }
    }
}


void ayudadminas(int filas,int columnas,tipocasilla **matriz,int minas){
    //esquinas = 0,0 y fila,0 y 0,columna y fila,columna.
    int fila=filas-1;
    int columna=columnas-1;
    int i=0,j=0;// 0,0 el lado izquierdo arriba
    if(matriz[i][j].tipo=='c'){
      if(matriz[i+1][j].tipo=='M'){
        matriz[i][j].Minas=matriz[i][j].Minas+1;
      }
      if(matriz[i][j+1].tipo=='M'){
        matriz[i][j].Minas=matriz[i][j].Minas+1;
      }
      if(matriz[i+1][j+1].tipo=='M'){
        matriz[i][j].Minas=matriz[i][j].Minas+1;
      }
    }
    // 0,columna : el lado derecho arriba.
    if(matriz[i][columna].tipo=='c'){
      if(matriz[i][columna-1].tipo=='M'){
        matriz[i][columna].Minas=matriz[i][columna].Minas+1;
      }
      if(matriz[i+1][columna].tipo=='M'){
        matriz[i][columna].Minas=matriz[i][columna].Minas+1;
      }
      if(matriz[i+1][columna-1].tipo=='M'){
        matriz[i][columna].Minas=matriz[i][columna].Minas+1;
      }
    }
    //fila,0 : este es el ultimo izquierda
    if(matriz[fila][j].tipo=='c'){
      if(matriz[fila-1][j].tipo=='M'){
        matriz[fila][j].Minas=matriz[fila][j].Minas+1;
      }
      if(matriz[fila][j+1].tipo=='M'){
        matriz[fila][j].Minas=matriz[fila][j].Minas+1;
      }
      if(matriz[fila-1][j+1].tipo=='M'){
        matriz[fila][j].Minas=matriz[fila][j].Minas+1;
      }
    }
    // fila,columna : el lado derecho de abajo.
    if(matriz[fila][columna].tipo=='c'){
      if(matriz[fila][columna-1].tipo=='M'){
        matriz[fila][columna].Minas=matriz[fila][columna].Minas+1;
      }
      if(matriz[fila-1][columna].tipo=='M'){
        matriz[fila][columna].Minas=matriz[fila][columna].Minas+1;
      }
      if(matriz[fila-1][columna-1].tipo=='M'){
        matriz[fila][columna].Minas=matriz[fila][columna].Minas+1;
      }
    }
    //lateral derecho y izquierdo.
    //derecho , fila:1,2,3..n-1, columna.
    int i1=1;//contador y posicion para las filas
    while(i1<fila){
      if(matriz[i1][j].tipo=='c'){
        if(matriz[i1-1][j].tipo=='M'){
          matriz[i1][j].Minas=matriz[i1][j].Minas+1;
        }
        if(matriz[i1-1][j+1].tipo=='M'){
          matriz[i1][j].Minas=matriz[i1][j].Minas+1;
        }
        if(matriz[i1][j+1].tipo=='M'){
          matriz[i1][j].Minas=matriz[i1][j].Minas+1;
        }
        if(matriz[i1+1][j+1].tipo=='M'){
          matriz[i1][j].Minas=matriz[i1][j].Minas+1;
        }
        if(matriz[i1+1][j].tipo=='M'){
          matriz[i1][j].Minas=matriz[i1][j].Minas+1;
        }
      }
      i1++;
    }
    int j1=1;
    //derecho , fila:1,2,3..n-1, columna.
    while(j1<fila){
      if(matriz[j1][columna].tipo=='c'){
        if(matriz[j1-1][columna].tipo=='M'){
          matriz[j1][columna].Minas=matriz[j1][columna].Minas+1;
        }
        if(matriz[j1-1][columna-1].tipo=='M'){
          matriz[j1][columna].Minas=matriz[j1][columna].Minas+1;
        }
        if(matriz[j1][columna-1].tipo=='M'){
          matriz[j1][columna].Minas=matriz[j1][columna].Minas+1;
        }
        if(matriz[j1+1][columna-1].tipo=='M'){
          matriz[j1][columna].Minas=matriz[j1][columna].Minas+1;
        }
        if(matriz[j1+1][columna].tipo=='M'){
          matriz[j1][columna].Minas=matriz[j1][columna].Minas+1;
        }
      }
      j1++;
    }
    //arriba y abajo
    //arriba , fila: columna: 1,2,3..n-1
    int i2=1;//contador y posicion para las filas
    while(i2<columna){//i2=1 y i=0
      if(matriz[i][i2].tipo=='c'){
        if(matriz[i][i2-1].tipo=='M'){
          matriz[i][i2].Minas=matriz[i][i2].Minas+1;
        }
        if(matriz[i+1][i2-1].tipo=='M'){
          matriz[i][i2].Minas=matriz[i][i2].Minas+1;
        }
        if(matriz[i+1][i2].tipo=='M'){
          matriz[i][i2].Minas=matriz[i][i2].Minas+1;
        }
        if(matriz[i+1][i2+1].tipo=='M'){
          matriz[i][i2].Minas=matriz[i][i2].Minas+1;
        }
        if(matriz[i][i2+1].tipo=='M'){
          matriz[i][i2].Minas=matriz[i][i2].Minas+1;
        }
      }
      i2++;
    }
    int j2=1;
    //abajo , fila, columna:1,2,3..n-1.
    while(j2<columna){
      if(matriz[fila][j2].tipo=='c'){
        if(matriz[fila][j2-1].tipo=='M'){
          matriz[fila][j2].Minas=matriz[fila][j2].Minas+1;
        }
        if(matriz[fila-1][j2-1].tipo=='M'){
          matriz[fila][j2].Minas=matriz[fila][j2].Minas+1;
        }
        if(matriz[fila-1][j2].tipo=='M'){
          matriz[fila][j2].Minas=matriz[fila][j2].Minas+1;
        }
        if(matriz[fila-1][j2+1].tipo=='M'){
          matriz[fila][j2].Minas=matriz[fila][j2].Minas+1;
        }
        if(matriz[fila][j2+1].tipo=='M'){
          matriz[fila][j2].Minas=matriz[fila][j2].Minas+1;
        }
      }
      j2++;
    }
    //numeros del medio
    int i3=1;
    while(i3<fila){
      int j3=1;
      while(j3<columna){
        if(matriz[i3][j3].tipo=='c'){
            if(matriz[i3][j3-1].tipo=='M'){
              matriz[i3][j3].Minas=matriz[i3][j3].Minas+1;
            }
            if(matriz[i3-1][j3-1].tipo=='M'){
              matriz[i3][j3].Minas=matriz[i3][j3].Minas+1;
            }
            if(matriz[i3-1][j3].tipo=='M'){
              matriz[i3][j3].Minas=matriz[i3][j3].Minas+1;
            }
            if(matriz[i3-1][j3+1].tipo=='M'){
              matriz[i3][j3].Minas=matriz[i3][j3].Minas+1;
            }
            if(matriz[i3][j3+1].tipo=='M'){
              matriz[i3][j3].Minas=matriz[i3][j3].Minas+1;
            }
            if(matriz[i3+1][j3+1].tipo=='M'){
              matriz[i3][j3].Minas=matriz[i3][j3].Minas+1;
            }
            if(matriz[i3+1][j3].tipo=='M'){
              matriz[i3][j3].Minas=matriz[i3][j3].Minas+1;
            }
            if(matriz[i3+1][j3-1].tipo=='M'){
              matriz[i3][j3].Minas=matriz[i3][j3].Minas+1;
            }
        }
        j3++;
      }
      i3++;
    }
}
void pedirfilacolumna(int filas,int columnas,tipocasilla **matriz,int minas){
    while(1){
        int i2,j2;
        char MoB;
        printf("\nN = Normal , B = Bandera");
        printf("\n\nIngrese: fila,columna,N  O  fila,columna,B:  ");
        scanf("%d,%d,%c",&i2,&j2,&MoB);
        if(MoB=='N'){
            matriz[i2][j2].etiqueta=matriz[i2][j2].Minas + '0';
            system("cls");
            imprimir_tablero(filas,columnas,matriz);
            if(matriz[i2][j2].tipo=='M'){
                matriz[i2][j2].etiqueta='*';
                system("cls");
                imprimir_tablero(filas,columnas,matriz);
                break;
            }
        }
        if(MoB=='B'){
            matriz[i2][j2].etiqueta='B';
            system("cls");
            imprimir_tablero(filas,columnas,matriz);
            if(matriz[i2][j2].etiqueta=='M'){
                break;
            }
        }
        //else{
            //printf("Debes ingresar si es con bandera o normal:");
        //}
    }
    printf("\n PERDISTE, PERO PUEDES VOLVERLO A INTENTAR\n");
}

int main(int argc,char *argv[],int argc2,char *argv2[],int argc3,char *argv3[]){
    typedef struct casilla tipocasilla;
    tipocasilla **matriz;
    int filas=atoi(argv[1]);
    int columnas=atoi(argv[2]);
    int minas=atoi(argv3[3]);

    matriz=CrearMatriz(filas,columnas);
    llenar_tablero(filas,columnas,matriz);
    imprimir_tablero(filas,columnas,matriz);
    colocarminas(filas,columnas,matriz,minas);
    ayudadminas(filas,columnas,matriz,minas);
    pedirfilacolumna(filas,columnas,matriz,minas);

}
