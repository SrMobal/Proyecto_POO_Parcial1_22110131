#include <iostream>
#include <conio.h>
#include <windows.h>

//Listing 11.8 using virtual methods, pages: 323 - 330

using namespace std;

//Enpieza clase padre.

class shape
{
    private:

		int x;
		int y;

    public:

		shape(int,int);
		virtual void setParam();
		virtual void draw();
		void gotoxy();
		int getY();
		int getX();
		void setY(int);
		void setX(int);
};

//Constructor de la clase Shape

shape::shape(int _x, int _y){x = _x; y = _y;}

void shape::draw()
{
  cout<<endl<<"Dibujando un ";
}

void shape::setParam()
{

}

void shape::gotoxy()  // funcion que posiciona el cursos en la coordenada (x,y)
{
    //limites de la pantalla x (min:0 max:101), y (min:0 max:26)
    if(x<1)x=0;
    if(y<1)y=0;
    if(x>101)x=101;
    if(y>26)y=26;


    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

int shape::getX(){return x;};
int shape::getY(){return y;};

void shape::setX(int _x){x += _x;};
void shape::setY(int _y){y += _y;};

//Termina clase padre.

//Empieza clase hija (cuadrado).

class square : public shape
{
    private:

        int opcion;
        int rows;
        int columns;

    public:

		square(int,int,int,int,int);
		void setParam();
		void draw();
};

//Constructor de la clase Square (Cuadrado)

square::square(int _x,int _y,int _opcion,int _rows, int _columns) : shape(_x,_y)
{
    opcion = _opcion;
	rows = _rows;
	columns = _columns;
}

void square::setParam()
{
    cout<<"opcion 1                    opcion 2"<<endl;
    cout<<"***                         ***"<<endl;
    cout<<"***                         * *"<<endl;
    cout<<"***                         ***"<<endl;
    cout<<"Selecciona el tipo:"<<endl;
    cin>>opcion;

    cout<<"Medida de alto:"<<endl;
    cin>>rows;

    cout<<"Medida de largo:"<<endl;
    cin>>columns;
}

void square::draw()
{
    int row,column;

	shape::draw();

	cout<<"Cuadrado"<<endl;

	shape::gotoxy();

        for(row=1;row<=rows;row++){

            for(column=1;column<=columns;column++){

                shape::setX(1); shape::gotoxy();

                if(opcion==2                            //Selecciono Vacio en medio del cuadrado
                   && !(column==1 || column==columns)   //y ... que no (sea la primer o ultima columna)
                   && !(row==1 || row==rows)            //y ... que no (sea el primer o ultimo renglon)
                   ){
                    printf ("%c", 32);
                }else{
                     printf ("%c", 219);
                }
            }
            shape::setY(1);shape::setX(-columns);
        }
        shape::setY(-rows);
}

//Termina clase hija (cuadrado).

//Empieza clase hija (triangulo).

class triangle : public shape
{
    private:

        int opcion;
        int rows;

    public:

		triangle(int,int,int,int);
		void setParam();
		void draw();
};

triangle::triangle(int _x, int _y,int _opcion,int _rows) : shape(_x, _y)
{
    opcion = _opcion;
    rows = _rows;
}

void triangle::setParam()
{

    cout<<"opcion 1                    opcion 2"<<endl;
    cout<<"*                           ****"<<endl;
    cout<<"**                          ***"<<endl;
    cout<<"****                        **"<<endl;
    cout<<"*****                       *"<<endl;
    cout<<"Selecciona el tipo:"<<endl;
    cin>>opcion;

    cout<<"Medida de alto:"<<endl;
    cin>>rows;

}

void triangle::draw()
{
    int row,column,length=1;

	shape::draw();
	cout<<"Triangulo"<<endl;
    shape::gotoxy();

    if(opcion==1){
        for(row=1;row<=rows;row++){

            for(column=1;column<=length;column++){
                shape::setX(1); shape::gotoxy(); printf ("%c", 219);
            }
            shape::setY(1);shape::setX(-length);
            length++;
        }


    }else{
        length = rows;
        for(row=1;row<=rows;row++){
            cout<<endl;
            for(column=1;column<=length;column++){
                shape::setX(1); shape::gotoxy(); printf ("%c", 219);
            }
            shape::setY(1);shape::setX(-length);
            length--;
        }
    }

    shape::setY(-rows);
}

//Termina clase hija (triangulo).

//Empieza clase hija (diamante).

class diamond : public shape
{
	private:
	    int opcion;
		int rows;

	public:

		diamond(int,int,int,int);
		void setParam();
		void draw();
};

diamond::diamond(int _x, int _y,int _opcion,int _rows) : shape(_x, _y)
{
    opcion = _opcion;
	rows = _rows;
}

void diamond::setParam()
{
    cout<<"opcion 1                    opcion 2"<<endl;
    cout<<"   *                           *"<<endl;
    cout<<"  ***                         * *"<<endl;
    cout<<" *****                       *   *"<<endl;
    cout<<"*******                     *     *"<<endl;
    cout<<" *****                       *   *"<<endl;
    cout<<"  ***                         * *"<<endl;
    cout<<"   *                           *"<<endl;
    cout<<"Selecciona el tipo:"<<endl;
    cin>>opcion;

    cout<<endl<<"Medida del Largo:"<<endl;
    cin>>rows;
}

void diamond::draw()
{
    int row,column,length=1;
    int caracterVacio = 32;

	shape::draw();
	cout<<"Diamante"<<endl;
    shape::gotoxy();

    if(opcion==1) caracterVacio = 219;

    int pintados = 0;
    int ren = 0;

    int z=1;
    for ( int i=0; i<=rows-1; i++){
        for (int j=rows-1; j>i; j--){shape::setX(1); shape::gotoxy();printf ("%c", 32); pintados++;}

        shape::setX(1); shape::gotoxy();printf ("%c", 219);pintados++;

        if ( i>0){
            for ( int k=1; k<=z; k++){shape::setX(1);shape::gotoxy();printf ("%c", caracterVacio);pintados++;}
            z+=2;
            shape::setX(1); shape::gotoxy();printf ("%c", 219);pintados++;
        }

        //cout<<endl;
        shape::setY(1);shape::setX(-pintados);
        pintados=0;
        ren++;
    }

    z-=4;

    pintados = 0;
    for (int i=0; i<=rows-2; i++){
        for (int j=0; j<=i; j++){shape::setX(1); shape::gotoxy();printf ("%c", 32);pintados++;}

        shape::setX(1); shape::gotoxy();printf ("%c", 219);pintados++;

        for (int k=1; k<=z; k++){shape::setX(1); shape::gotoxy();printf ("%c", caracterVacio);pintados++;}

        z-=2;

        if (i!=rows-2){shape::setX(1); shape::gotoxy();printf ("%c", 219);pintados++;}
        shape::setY(1);shape::setX(-pintados);
        pintados=0;
        ren++;
    }

    shape::setY(-ren);
}

//Termina clase hija (diamante).

//Empieza clase InputManager.


class InputManager
{
    private:

        int repetir;
        int seleccion;

    public:

        InputManager(int,int);
        int SeleccionarFigura();
        int RepetirPrograma();
};

InputManager::InputManager(int _repetir, int _seleccion)
{
    repetir = _repetir;
    seleccion = _seleccion;
}

int InputManager::SeleccionarFigura()
{
    cout<<"Seleciona figura: "<<endl;
    cout<<"1.- Cuadrado "<<endl;
    cout<<"2.- Triangulo "<<endl;
    cout<<"3.- Diamante "<<endl;
    cin>>seleccion;

    return seleccion;
}

int InputManager::RepetirPrograma()
{
    cout<<"Repetir programa: "<<endl;
    cout<<"1.- Si "<<endl;
    cout<<"2.- No "<<endl;
    cin>>repetir;

    return repetir;
}

//Termina clase InputManager.


int main()
{
	int numero=1,seleccion=0, controlteclado=1;
	char tecla;

    InputManager Menu(1,1);

    do
    {

      system("cls");

        do
        {

            seleccion = Menu.SeleccionarFigura();

        }while((seleccion < 1) || (seleccion > 3));

        shape *figura;

        switch(seleccion)
        {
            case 1: figura = new square(1,3,1,4,4);break;
            case 2: figura = new triangle(1,3,1,4);break;
            case 3: figura = new diamond(1,3,1,4);break;
        }

        figura->setParam();
        system("cls");
        figura->draw();

        while(controlteclado==1){
            if(kbhit()){
                tecla = getch();
                if((int)tecla == 27) controlteclado=0;//si oprime la tecla ESCAPE que se salga del bucle
                if(tecla == 'i' || (int)tecla == 72) figura->setY(-1); else if(tecla == 'm' || (int)tecla == 80) figura->setY(1);
                if(tecla == 'j' || (int)tecla == 75) figura->setX(-1); else if(tecla == 'l' || (int)tecla == 77) figura->setX(1);
                system("cls");
                figura->gotoxy();
                figura->draw();
                //cout<<" "<<figura->getY()<<" , "<<figura->getX();
            }
        }

        controlteclado=1;//para que entre a mover la siguiente figura

        delete figura;

        do
        {
            numero = Menu.RepetirPrograma();

        }while((numero < 1) || (numero > 2));


    }while(numero == 1);

    return 0;
}
