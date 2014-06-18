#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>

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

class Numero
{
public:
    int x;
    Numero(int x)
    {
        this->x=x;
    }
};

void mainSTL()
{
    //Vector
    cout<<"Vector"<<endl;
    vector<Numero*> mi_vector;
    mi_vector.push_back(new Numero(5));
    mi_vector.push_back(new Numero(8));
    mi_vector.push_back(new Numero(3));
    mi_vector.push_back(new Numero(1));
    mi_vector.pop_back();
    for(int i=0;i<mi_vector.size();i++)
    {
        cout<<mi_vector[i]->x<<endl;
    }

    //Lista
    cout<<"Lista"<<endl;
    list<int> mi_lista;
    list<int>::iterator mi_iterador;
    mi_lista.push_back(6);
    mi_lista.push_back(8);
    mi_lista.push_front(2);

    mi_iterador=mi_lista.begin();
    for(int i=0;i<2;i++)
        mi_iterador++;

    mi_lista.insert(mi_iterador,15);

    for(mi_iterador=mi_lista.begin();
        mi_iterador!=mi_lista.end();
        mi_iterador++)
    {
        cout<<*mi_iterador<<endl;
    }

    //map
    cout<<"Mapa"<<endl;
    map<string,int>mi_mapa;
    mi_mapa["hola"]=16;
    mi_mapa["mundo"]=32;
    cout<<mi_mapa["hola"]<<endl;
    cout<<mi_mapa["mundo"]<<endl;
    map<string,int>::iterator iterador_mapa;
    for(iterador_mapa=mi_mapa.begin();
        iterador_mapa!=mi_mapa.end();
        iterador_mapa++)
    {
        cout<<iterador_mapa->first<<" ";
        cout<<iterador_mapa->second<<endl;
    }
}

class Nodo
{
public:
    int num;
    Nodo* izq;
    Nodo* der;
    Nodo(int num)
    {
        this->num = num;
        this->izq = 0;
        this->der = 0;
    }
};

class Arbol
{
public:
    Nodo* raiz;
    Arbol()
    {
        Nodo*n1 = new Nodo(2);
        Nodo*n2 = new Nodo(2);
        Nodo*n3 = new Nodo(3);
        Nodo*n4 = new Nodo(4);
        Nodo*n5 = new Nodo(5);
        Nodo*n6 = new Nodo(6);

        raiz = n4;
        n4->izq = n2;
        n4->der = n5;
        n5->izq = n3;
        n5->der = n6;
        n3->izq = n1;
    }

    void imprimir(Nodo* raiz)
    {
        if(raiz==NULL)
        {
            cout<<"LLegue a una rama!"<<endl;
            return;
        }

        cout<<raiz->num<<endl;

        imprimir(raiz->der);
        imprimir(raiz->izq);
    }

    int suma(Nodo* raiz)
    {
        if(raiz == NULL)
        {
            return 0;
        }

        int suma_der = suma(raiz->der);
        int suma_izq = suma(raiz->izq);
        int res = suma_der + suma_izq + raiz->num;
        return res;
    }

    int getMenor(Nodo* raiz)
    {
        if(raiz==NULL)
        {
            return 999999;
        }

        int num_raiz=raiz->num;
        int menor_izq = getMenor(raiz->izq);
        int menor_der = getMenor(raiz->der);

        if(num_raiz<menor_izq && num_raiz<menor_der)
            return num_raiz;
        if(menor_izq<num_raiz && menor_izq<menor_der)
            return menor_izq;

        return menor_der;
    }


    int getMayor(Nodo* raiz)
    {
        if(raiz==NULL)
        {
            return -999999;
        }

        int num_raiz=raiz->num;
        int menor_izq = getMayor(raiz->izq);
        int menor_der = getMayor(raiz->der);

        if(num_raiz>menor_izq && num_raiz>menor_der)
            return num_raiz;
        if(menor_izq>num_raiz && menor_izq>menor_der)
            return menor_izq;

        return menor_der;
    }

    bool estaOrdenado(Nodo* raiz)
    {
        if(raiz==NULL)
        {
            return true;
        }

        bool mayor_izq = false;
        if(raiz->izq == NULL)
        {
            mayor_izq = true;
        }else if(raiz->num > raiz->izq->num)
        {
            mayor_izq = true;
        }

        if(!estaOrdenado(raiz->izq))
            return false;
        if(!estaOrdenado(raiz->der))
            return false;

        bool menor_der = false;
        if(raiz->der == NULL)
        {
            menor_der = true;
        }else if(raiz->num < raiz->der->num)
        {
            menor_der = true;
        }

        if(menor_der && mayor_izq)
            return true;

        return false;
    }
};

void mainArbol()
{
    Arbol a;
    cout<< a.estaOrdenado(a.raiz);
}

int main()
{
    mainArbol();

    return 0;
}
