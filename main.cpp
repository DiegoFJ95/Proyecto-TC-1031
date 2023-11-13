#include <iostream>
#include "EquipoPokemon.h"
#include <stdlib.h>


Equipo<int> EquipoPKMN;


int main(){
  EquipoPKMN.addFirst("Charizard","Fuego","Volador",297,254,206,236);
  EquipoPKMN.add("Garchomp","Dragon","Tierra",357,296,226,240);
  EquipoPKMN.add("Volcarona","Fuego","Bicho",311,306,246,236);
  EquipoPKMN.add("Lucario","Lucha","Acero",281,266,176,286);

  std::cout<<EquipoPKMN.toString();

  std::system("CLS"); //Función para limpiar la consola.

  int seleccion;
  bool continuar = true;
  std::string nom;
  std::string tip1;
  std::string tip2;
  int vida;
  int ataque;
  int defensa;
  int velocidad;

  while(continuar==true){
    std::cout<<"\nSelecciona una accion:\n\n1. Mostrar tu equipo. \n2. Añadir pokémon. \n3. Ordenar tu equipo. \n4. Salir.\n";
    std::cin>>seleccion;
    if(seleccion==1){
      std::cout<<EquipoPKMN.toString();
    }
    else if(seleccion==2){
      std::cout<<"\nComo se llama?";
      std::cin>>nom;
      std::cout<<"\nCual es su primer tipo?";
      std::cin>>tip1;
      std::cout<<"\nCual es su segundo tipo?";
      std::cin>>tip2;
      std::cout<<"\nCuanta vida tiene?";
      std::cin>>vida;
      std::cout<<"\nCuanta ataque tiene?";
      std::cin>>ataque;
      std::cout<<"\nCuanta defensa tiene?";
      std::cin>>defensa;
      std::cout<<"\nCuanta velocidad tiene?";
      std::cin>>velocidad;
      EquipoPKMN.add(nom,tip1,tip2,vida,ataque,defensa,velocidad);

    }
    else if(seleccion==3){
      int sort;
      std::cout<<"\nSelecciona un parametro para ordenar:\n\n1. Por nombre.\n2. Por tipo principal.\n3. Por tipo secundario.\n4. Por puntos de vida.\n5. Por ataque.\n6. Por defensa.\n7.Por velocidad.\n";
      std::cin>>sort;
      std::cout<<"Feature no implementada aun.\n";
//      equipo.SortHp();
    }
    else if(seleccion==4){
      continuar = false;
    }
    else{
      std::cout<<"Seleccion invalida.\n";
    }
  }

}
