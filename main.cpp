#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "EquipoPokemon.h"


Equipo<int> EquipoPKMN;


int main(){

  std::ifstream inputFile ("default.pkmn");

  std::string Fnombre;
  std::string Ftipo1;
  std::string Ftipo2;
  int Fvida;
  int Fataque;
  int Fdefensa;
  int Fvelocidad;

  if(inputFile){
    while(inputFile >>Fnombre>>Ftipo1>>Ftipo2>>Fvida>>Fataque>>Fdefensa>>Fvelocidad){
      EquipoPKMN.add(Fnombre, Ftipo1, Ftipo2, Fvida, Fataque, Fdefensa, Fvelocidad);
    };
  }


  std::system("CLS"); //Función para limpiar la consola.

  int seleccion;
  bool continuar = true;

  while(continuar==true){
    std::cout<<"\nSelecciona una accion:\n\n1. Mostrar tu equipo. \n2. Consultar un Pokemon \n3. Annadir un pokemon. \n4. Ordenar tu equipo. \n5. Eliminar un pokemon \n6. Eliminar tu equipo \n7. Cargar datos previos \n8. Borrar datos previos \n9. Salir.\n";
    std::cin>>seleccion;

    if(seleccion==1){
      std::cout<<EquipoPKMN.toString();
    }

    else if(seleccion==2){
      std::string elegido;
      std::cout<<"Que pokemon quieres consultar? (escribe su nombre)\n";
      std::cin>>elegido;
      int numPkmn = EquipoPKMN.indexOf(elegido);
      std::cout<<EquipoPKMN.IndexToString(numPkmn);
    }

    else if(seleccion==3){
      std::cout<<"\nComo se llama?";
      std::cin>>Fnombre;
      std::cout<<"\nCual es su primer tipo?";
      std::cin>>Ftipo1;
      std::cout<<"\nCual es su segundo tipo?";
      std::cin>>Ftipo2;
      std::cout<<"\nCuanta vida tiene?";
      std::cin>>Fvida;
      std::cout<<"\nCuanto ataque tiene?";
      std::cin>>Fataque;
      std::cout<<"\nCuanta defensa tiene?";
      std::cin>>Fdefensa;
      std::cout<<"\nCuanta velocidad tiene?";
      std::cin>>Fvelocidad;
      EquipoPKMN.add(Fnombre,Ftipo1,Ftipo2,Fvida,Fataque,Fdefensa,Fvelocidad);
      std::ofstream saveFile ("save.pkmn", std::ios::app);
      if(saveFile){
        saveFile<<Fnombre<<" "<<Ftipo1<<" "<<Ftipo2<<" "<<Fvida<<" "<<Fataque<<" "<<Fdefensa<<" "<<Fvelocidad<<"\n";
      }
      saveFile.close();
    }

    else if(seleccion==4){
      int sort;
      std::cout<<"\nSelecciona un parametro para ordenar:\n\n1. Por nombre.\n2. Por tipo principal.\n3. Por tipo secundario.\n4. Por puntos de vida.\n5. Por ataque.\n6. Por defensa.\n7. Por velocidad.\n";
      std::cin>>sort;
      if(sort == 1){
        EquipoPKMN.sort_nombre();
      }
      else if(sort == 2){
        EquipoPKMN.sort_tipo1();
      }
      else if(sort == 3){
        EquipoPKMN.sort_tipo2();
      }
      else if(sort == 4){
        EquipoPKMN.sort_vida();
      }
      else if(sort == 5){
        EquipoPKMN.sort_ataque();
      }
      else if(sort == 6){
        EquipoPKMN.sort_defensa();
      }
      else if(sort == 7){
        EquipoPKMN.sort_velocidad();
      }
      else{
        std::cout<<"Opción no válida";
      }
    }

    else if(seleccion==5){
      std::string elegido;
      std::cout<<"Que pokemon quieres eliminar? (escribe su nombre)\n";
      std::cin>>elegido;
      int numPkmn = EquipoPKMN.indexOf(elegido);
      EquipoPKMN.remove(numPkmn);
    }

    else if(seleccion==6){
      int confirmar;
      std::cout<<"Estas seguro que quieres eliminar a todo tu equipo? \n1. Si \n2. No \n";
      std::cin>>confirmar;
      if(confirmar == 1){
        EquipoPKMN.clear();
      }
    }

    else if(seleccion==7){
      std::ifstream saveFile ("save.pkmn");
      if(saveFile){
        while(saveFile >>Fnombre>>Ftipo1>>Ftipo2>>Fvida>>Fataque>>Fdefensa>>Fvelocidad){
          EquipoPKMN.add(Fnombre, Ftipo1, Ftipo2, Fvida, Fataque, Fdefensa, Fvelocidad);
        }
      }
      saveFile.close();
    }

    else if(seleccion==8){
      std::ofstream saveFile ("save.pkmn", std::ofstream::trunc);
      saveFile.close();
    }

    else if(seleccion==9){
      continuar = false;
    }

    else{
      std::cout<<"Seleccion invalida.\n";
    }
  }
}
