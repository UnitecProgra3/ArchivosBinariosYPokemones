#include <iostream>
#include <fstream>

using namespace std;


int mainPokemones()
{
    while(true)
    {
        cout<<"Ingrese 1 para escribir, 2 para leer, "
            <<"3 para ver un pokemon, "
            <<"4 para escribir un pokemon "
            <<"o 9 para salir: ";
        int opcion;
        cin>>opcion;
        if(opcion==1)
        {
            //Informacion de jugador
            ofstream out("pokemones");
            cout<<"Nombre: ";
            char nombre_jugador[20];
            cin>>nombre_jugador;
            cout<<"Medallas: ";
            int cant_medallas;
            cin>>cant_medallas;

            out.write(nombre_jugador,20);
            out.write((char*)&cant_medallas,4);

            //Informacion de pokemon
            for(int i=0;i<3;i++)
            {
                //Leo informacion del usuario
                cout<<"Nombre pokemon: ";
                char nombre_pokemon[20];
                cin>>nombre_pokemon;
                cout<<"Sexo: ";
                char sexo_pokemon;
                cin>>sexo_pokemon;
                cout<<"Ataque: ";
                int ataque_pokemon;
                cin>>ataque_pokemon;

                //Escribo en el disco
                out.write(nombre_pokemon,20);
                out.write(&sexo_pokemon,1);
                out.write((char*)&ataque_pokemon,4);
            }

            out.close();
        }
        if(opcion==2)
        {
            //Leo datos del jugador
            ifstream in("pokemones");

            in.seekg(0,ios::end);
            int tamano_archivo = in.tellg();

            in.seekg(0);

            char nombre_jugador[20];
            in.read(nombre_jugador,20);
            cout<<"Nombre jugador: "<<nombre_jugador<<endl;
            int cant_medallas;
            in.read((char*)&cant_medallas,4);
            cout<<"Medallas: "<<cant_medallas<<endl;

            //Leo datos de los pokemones
            for(int i=0;i<(tamano_archivo-24)/25;i++)
            {
                //Leo del disco
                char nombre_pokemon[20];
                in.read(nombre_pokemon,20);

                char sexo_pokemon;
                in.read(&sexo_pokemon,1);

                int ataque;
                in.read((char*)&ataque,4);

                //Imprimo valores
                cout<<"Nombre pokemon: "<<nombre_pokemon<<endl;
                cout<<"Sexo: "<<sexo_pokemon<<endl;
                cout<<"Ataque: "<<ataque<<endl;
            }
            in.close();
        }
        if(opcion==3)
        {
            cout<<"Ingrese un pokemon: ";
            int pokemon;
            cin>>pokemon;

            ifstream in("pokemones");
            in.seekg(pokemon*25-1);
//            in.seekg((pokemon-1)*25+24);

            //Leo del disco
            char nombre_pokemon[20];
            in.read(nombre_pokemon,20);

            char sexo_pokemon;
            in.read(&sexo_pokemon,1);

            int ataque;
            in.read((char*)&ataque,4);

            //Imprimo valores
            cout<<"Nombre pokemon: "<<nombre_pokemon<<endl;
            cout<<"Sexo: "<<sexo_pokemon<<endl;
            cout<<"Ataque: "<<ataque<<endl;
        }

        if(opcion==4)
        {
            cout<<"Ingrese un pokemon: ";
            int pokemon;
            cin>>pokemon;

            ofstream out("pokemones", std::ios::out | std::ios::in);
            out.seekp(pokemon*25-1,ios::beg);

            //Leo informacion del usuario
            cout<<"Nombre pokemon: ";
            char nombre_pokemon[20];
            cin>>nombre_pokemon;
            cout<<"Sexo: ";
            char sexo_pokemon;
            cin>>sexo_pokemon;
            cout<<"Ataque: ";
            int ataque_pokemon;
            cin>>ataque_pokemon;

            //Escribo en el disco
            out.write(nombre_pokemon,20);
            out.write(&sexo_pokemon,1);
            out.write((char*)&ataque_pokemon,4);
        }

        if(opcion==9)
        {
            break;
        }
    }
}

int mainSencillo()
{
    ofstream o("archivo");
    for(int i=0;i<10;i++)
    {
//        int* ptr = new int(i);
//        o.write((char*)ptr,4);
//        delete ptr;

        int ptr = i;
        o.write((char*)&ptr,4);
    }
    o.close();

    ifstream in("archivo");

    for(int i=0;i<10;i++)
    {
//        int* leer = new int(0);
//        in.read((char*)leer,4);
//        cout<<*leer;
//        delete leer;

        int leer;
        in.read((char*)&leer,4);
        cout<<leer;
    }

}

int main()
{
    mainPokemones();

    return 0;
}
