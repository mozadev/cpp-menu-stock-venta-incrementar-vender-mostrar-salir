#include<iostream>
using namespace std;
int main()
{
	int opcion,vecesActualizoStock=0;
	float stock=0,ucompra,uventa,totalUndVend=0;
	do
	{
		do
		{
			cout<<"---Menú----"<<endl;
			cout<<"1 Actualizar stock"<<endl;
			cout<<"2 Vender"<<endl;
			cout<<"3 Mostrar"<<endl;
			cout<<"4 Salir"<<endl;
			cout<<"Ingrese una opción (1-4)"<<endl;
			cin>>opcion;
			if(opcion<1 or opcion>4)
				cout<<"Error... solo de 1 a 4"<<endl;
		}while(opcion<1 or opcion>4);
		
		switch(opcion)
		{
			case 1:
				{
					do
					{
						cout<<"Ingrese nuevas unidades"<<endl;
						cin>>ucompra;	
						if(ucompra<0)
							cout<<"Debe ser positivo "<<endl;
					}while(ucompra<0);
					stock=stock+ucompra;
					vecesActualizoStock++;		
				}break;	
			case 2:
				{
					do
					{
						cout<<"Ingrese unidades a vender"<<endl;
						cin>>uventa;
						if(uventa<0)
							cout<<"Debe ser positivo"<<endl;
					}while(uventa<0);
					if(stock>=uventa)
					{
						stock=stock-uventa;
						totalUndVend=totalUndVend+uventa;
					}
					else
					{
						cout<<"Las unidades a atender son "<<stock/2<<endl;
						stock=stock-stock/2;
						totalUndVend=totalUndVend+stock;
					}
				}break;
			case 3:
				{
					cout<<"El stock actual es "<<stock<<endl;
					cout<<"El total de las unidades vendidas es "<<totalUndVend<<endl;
					cout<<"La cant de veces q se incrementó stock es "<<vecesActualizoStock<<endl;	
				}break;
			case 4:
				{
					cout<<"Adios   "<<endl;
				}			
		}
		
	system("pause");
	system("cls");	
	}while(opcion!=4);
		
	return 0;
}
