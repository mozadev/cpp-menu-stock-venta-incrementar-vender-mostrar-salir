#include<iostream>

using namespace std;

int cantPedCajasColIncompleto = 0;
int totalCajasColores = 0, totalCajasColoresVendidas = 0;
int totalCajasColoresFalt = 0, cantPedpapelBondCompleto = 0;
int cantPedPapelBonIncompleto = 0, totalPapelBondMIllar = 0, totalPapeBoVent = 0, totalPapelBonFaltante = 0;
int nuevoIngresoCajaColor, opcion, cantVentCajaColor, nuevoIngresoPapelBondMillar, cantVentPapelbonMillar;
int numVeceActualiCajaCol = 0, numVeceActualiPapelBonMILL = 0;
int cantClientAtenCompl = 0, cantClientAtenParcial = 0;
int valorDecision, nuevaCantidadParcialCajacol, nuevaCantidadParcialPapel, acumuladorPedidoCompletaronParcialCAJA = 0,
acumuladorPedidoCompletaronParcialPapel = 0;
int cantipedidoDEJAatende = 0;

int main() {
	do {
		do {
			cout << "Menu Principal" << endl;
			cout << "1 Actualizar" << endl;
			cout << "2 Vender" << endl;
			cout << "3 Reportar" << endl;
			cout << "4 Salir" << endl;
			cout << "Ingrese opción" << endl;
			cin >> opcion;
			if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)
				cout << "No valido" << endl;
		} while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);
		switch (opcion)
		{
		case 1: {
			cout << "Nuevo ingreso de productos caja de colores" << endl;
			cin >> nuevoIngresoCajaColor;
			totalCajasColores = totalCajasColores + nuevoIngresoCajaColor;
			numVeceActualiCajaCol++;

			cout << "Nuevo ingreso de productos papel bon millar" << endl;
			cin >> nuevoIngresoPapelBondMillar;
			totalPapelBondMIllar = totalPapelBondMIllar + nuevoIngresoPapelBondMillar;
			numVeceActualiPapelBonMILL++;
			break;
		}
		case 2: {
			do {

				cout << "Ingrese cantidad a vender caja de colores" << endl;
				cin >> cantVentCajaColor;
				cout << "Ingrese cantidad a vender papel bon millar" << endl;
				cin >> cantVentPapelbonMillar;
				if (cantVentPapelbonMillar <= 0 || cantVentCajaColor<=0)
					cout << "Cantidad invalida, cantidad debe ser mayor de 0 " << endl;
			} while (cantVentCajaColor <= 0 || cantVentPapelbonMillar <= 0);

			// si hay cantidad sufienciente 
			if (cantVentCajaColor <= totalCajasColores && cantVentPapelbonMillar <= totalPapelBondMIllar)
			{
				if (cantVentCajaColor >= 0 && cantVentPapelbonMillar >= 0) {

					totalCajasColores = totalCajasColores - cantVentCajaColor; // saldo stock 
					cantPedCajasColIncompleto++; // acumulador de cantidad de pedidos completos
					totalCajasColoresVendidas = totalCajasColoresVendidas + cantVentCajaColor; // acumulador total ventas caja color


					totalPapelBondMIllar = totalPapelBondMIllar - cantVentPapelbonMillar;
					cantPedpapelBondCompleto++;
					totalPapeBoVent = totalPapeBoVent + cantVentPapelbonMillar;

					cantClientAtenCompl++;
				}

			}
			// si no hay cantidad suficiente
			if (cantVentCajaColor > totalCajasColores || cantVentPapelbonMillar > totalPapelBondMIllar)
			{
				if (cantVentCajaColor >= 0 && cantVentPapelbonMillar >= 0) {

					cout << "Cantidad insuficiente, desea pedir menos? V=1 , de lo contrario ingrese 0" << endl;
					cin >> valorDecision;
					if (valorDecision == 1) {
						cout << "ingrese la cantidad parcial caja de colores , stock actual: " << totalCajasColores << endl;
						cin >> nuevaCantidadParcialCajacol;
						cout << "ingrese la cantidad parcial papel bond millar , stock actual: " << totalPapelBondMIllar << endl;
						cin >> nuevaCantidadParcialPapel;

						totalCajasColores = totalCajasColores - nuevaCantidadParcialCajacol; // saldo stock 
						acumuladorPedidoCompletaronParcialCAJA++; // acumulador de cantidad de pedidos completos
						totalCajasColoresVendidas = totalCajasColoresVendidas + nuevaCantidadParcialCajacol; // acumulador total ventas caja color


						totalPapelBondMIllar = totalPapelBondMIllar - nuevaCantidadParcialPapel;
						acumuladorPedidoCompletaronParcialPapel++;
						totalPapeBoVent = totalPapeBoVent + nuevaCantidadParcialPapel;

						cantClientAtenParcial++;
					}
					else {
						if (cantVentCajaColor >= 0 && cantVentPapelbonMillar >= 0) {
							cout << "Cantidad insuficiente" << endl;
							cantPedCajasColIncompleto++;
							totalCajasColoresFalt = cantVentCajaColor - totalCajasColores;


							cantPedPapelBonIncompleto++;
							totalPapelBonFaltante = cantVentPapelbonMillar - totalPapelBondMIllar;
							cantipedidoDEJAatende++;
						}
					}
				}

			}
			

			break;
		}
		case 3: {

			cout << "cantidad de veces que se actualizo CAJA DE COLORES  " << numVeceActualiCajaCol << endl;
			cout << "cantidad de veces que se actualizo PAPEL BOND MILLAR " << numVeceActualiPapelBonMILL << endl;
			cout << "cantidad de clientes atendidos si se completo el pedido " << cantClientAtenCompl << endl;

			cout << "cantidad de pedidos que se atendieron una parte "
				<< cantClientAtenParcial << endl;

			cout << "cantidad de pedidos incompletos ( dejaron de atenderse)  " << cantipedidoDEJAatende << endl;
			cout << "stock de caja de colores   " << totalCajasColores << endl;
			cout << "stock de papel bond " << totalPapelBondMIllar << endl;
			cout << "unidades vendidas de caja de colores   " << totalCajasColoresVendidas << endl;
			cout << "unidades vendidas de papel bond " << totalPapeBoVent << endl;


			break;
		}
		case 4: {
			cout << "Gracias por su compra" << endl;
			break;
		}
		}
	} while (opcion != 4);


}