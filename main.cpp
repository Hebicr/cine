#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
typedef int sala [4][6][3];

	string tandas[3][3] ={
					  {"1","Superman","1900"},
					  {"2","Iron Man","1700"},
					  {"3","Godzilla","2300"}
	};

	void menu()	{
			cout<<"***********************************"<<endl;
			cout<<"***********************************"<<endl;
			cout<<"***********************************"<<endl;
			cout<<"   \n\t** Cinemas  El Camino **\n\n"<<endl;
			cout<<"    1. Administrar Tandas          "<<endl;
			cout<<"    2. Reservar Espacios           "<<endl;
			cout<<"    3. Campos Reservados y Libres  "<<endl;
			cout<<"    4. Cerrar Tanda                "<<endl;
			cout<<"    5. Salir                       "<<endl;
			cout<<endl;
			cout<<"***********************************"<<endl;
			cout<<"***********************************"<<endl;
			cout<<"***********************************"<<endl;
			cout<<"    \n INGRESE OPCION:             "<<endl;
	}
	
	void menutandas(){
		cout<<"***********************************"<<endl;
		cout<<"***********************************"<<endl;
		cout<<endl;
		cout<<"		\n\t Administrar Tandas \n\n  "<<endl;
		cout<<" 	1. Ver Tandas                 "<<endl;
		cout<<" 	2. Editar Pelicula            "<<endl;
		cout<<" 	3. Salir                      "<<endl;
		cout<<endl;
		cout<<"***********************************"<<endl;
		cout<<"***********************************"<<endl;
		cout<<"\n INGRESE OPCION: ";
	}
	
	void imprimirTandas(){
		cout<<" Tanda "<< "    Pelicula "<<"      $   "<<endl;
		for(int x=0;x<=2;x++){
			for(int y=0;y<=2;y++){
				cout<< "    " <<tandas[x][y]<<" | ";
				}
				cout<<" "<<endl;
			}	
	}
	
	int precioTanda(int numT){
		string s = tandas[numT][2];
		stringstream geek(s); 
		int precio = 0;
		geek >> precio; 
		return precio;		
	}
	
	void imprimirTanda(int numT){
			for(int y=0;y<=2;y++){
				cout<< "    " <<tandas[numT][y]<<" | ";
				}
				cout<<" "<<endl;	
	}
	
	void iniciarsalas(sala a){
		int butaca = 0;
		for (int i=0;i<=2;i++) {
			for (int j=0;j<=3;j++) {
				for (int k=0;k<=5;k++) {
					butaca = butaca +1;
					a[j][k][i] = butaca;
				}
			}
			butaca = 0;
		}	
	}
		
	void imprimirsalas(sala a,int numT){
		int libre = 0,ocupado = 0;
		system("cls");
		cout<<""<<endl;
		cout<<"  Tanda "<< numT <<endl;
		for(int i=0;i<=2;i++){
			cout<<" "<<endl;
			cout<<"	    Nivel "<< i+1 <<endl;
			cout<<""<<endl;
			cout<<"		[            Pantalla           ]"<<endl;
			for (int j=0;j<=3;j++){
			cout<<"		[ ";
				for(int k=0;k<=5;k++){
					if(a[j][k][i] < 0){
						cout<<" X"<<" | ";
						ocupado = ocupado + 1;
					}else{
						if(a[j][k][i] > 0 && a[j][k][i] < 10 ){
							cout<<"0"<<a[j][k][i]<<" | ";
						}else{
							cout<<a[j][k][i]<<" | ";
						}
					if(a[j][k][i] > 0){
						libre = libre + 1;
					}
				}
							
			}
			cout<<"]";
			cout<<" "<<endl;
			}	
			cout<<" "<<endl;
			cout<<"              Espacios Libres:   "<<libre<<endl;
			cout<<"              Espacios Ocupados: "<<ocupado<<endl;
		    cout<<" "<<endl;
		    libre = 0;
		    ocupado = 0;
		}
	};
	
	void cerrarTanda(sala a, int numT){
		int libre = 0,ocupado = 0;
		cout<<""<<endl;
		cout<<"  Tanda "<< numT <<endl;
		imprimirTanda(numT-1);
		cout<<""<<endl;
		for(int i=0;i<=2;i++){
			for (int j=0;j<=3;j++){
				for(int k=0;k<=5;k++){
					if(a[j][k][i] < 0){
						ocupado = ocupado + 1;
					}else{
						libre = libre + 1;
					}
				}			
			}
		}	
		cout<<" "<<endl;
		int precio = precioTanda(numT-1);
		int totalT = precio * ocupado;
		cout<<"              Espacios Libres:   "<<libre<<endl;
		cout<<" "<<endl;
		cout<<"              Espacios Ocupados: "<<ocupado<<endl;
		cout<<" "<<endl;
		cout<<"Precio por Butaca "<< precio <<endl;
		cout<<" "<<endl;
		cout<<"Total de Tanda "<<numT <<" $ "<< totalT<<endl;
		cout<<" "<<endl;
		libre = 0;
		ocupado = 0;
		iniciarsalas(a);	
	}
	
	void imprimirNivel(sala a,int lvl){
		int libre = 0,ocupado = 0;
		cout<<""<<endl;
		cout<<"	    Nivel "<< lvl <<endl;
		cout<<""<<endl;
		cout<<"		[            Pantalla           ]"<<endl;
		for (int j=0;j<=3;j++){
			cout<<"		[ ";
			for(int k=0;k<=5;k++){
				if(a[j][k][lvl-1] < 0){
						cout<<" X"<<" | ";
						ocupado = ocupado + 1;
					}else{
						if(a[j][k][lvl-1] > 0 && a[j][k][lvl-1] < 10 ){
							cout<<"0"<<a[j][k][lvl-1]<<" | ";
						}else{
							cout<<a[j][k][lvl-1]<<" | ";
						}
					if(a[j][k][lvl-1] > 0){
						libre = libre + 1;
					}
				}	
			}
			cout<<"]";
			cout<<" "<<endl;
		}	
		cout<<" "<<endl;
		cout<<"              Espacios Libres:   "<<libre<<endl;
		cout<<"              Espacios Ocupados: "<<ocupado<<endl;
	    cout<<" "<<endl;
		libre = 0;
		ocupado = 0;
	};
	
	int butacasDisponibles(sala a,int lvl){
		int libre = 0;
		for (int j=0;j<=3;j++){	
			for(int k=0;k<=5;k++){
				if(a[j][k][lvl-1] > 0){
					libre = libre + 1;
				}		
			}		
		}		
		return libre;
	};
	
	void picktanda(sala a,int numT){
		int cantButacasCli,butacasDispo,numButaca,valorNivel;
			system("cls");
			cout<<"Tanda "<<  numT <<endl;
			imprimirsalas(a,numT);
			cout<<"\nEliga su Nivel?"<<endl;	
			cin >>valorNivel;
			if(valorNivel>0 && valorNivel <=3){
				system("cls");
				imprimirNivel(a,valorNivel);
				cout<<"Cuantas Butacas desea?"<<endl;
				cin>>cantButacasCli; 
				int	ButacasCliente[cantButacasCli];
				butacasDispo = butacasDisponibles(a,valorNivel);
				if(cantButacasCli <= butacasDispo){
					int cont1 = 1;
					while(cont1 <= cantButacasCli){
						cout<<"Ingrese # de Butaca "<< cont1 <<endl;
						cin>>numButaca;
						if(numButaca <=24){
							for (int j=0;j<=3;j++){ 	
								for(int k=0;k<=5;k++){
									if(a[j][k][valorNivel-1] == numButaca ){
										a[j][k][valorNivel-1] = -numButaca;
										cont1++;
										cout<<"Butaca seleccionada correctamente"<<endl;
										ButacasCliente[cont1-1] = numButaca; 
									}else{
										if(a[j][k][valorNivel-1] == -numButaca){
											cout<<"Butaca NO Disponible"<<endl;
										}
									}	
								}		
							}	
						}else{
							cout<<"Butaca NO Existe"<<endl;
						}	
					}
					system("cls");
					cout<<""<<endl;
					cout<<"*******************************************************"<<endl;
					cout<<"*******************************************************"<<endl;
					cout<<""<<endl;
					cout<<"                           Tiket                       "<<endl;
					cout<<""<<endl;
					cout<<"*******************************************************"<<endl;
					cout<<"Tanda " << numT<<endl;
					cout<<""<<endl;
					imprimirTanda(numT-1);
					cout<<"*******************************************************"<<endl;
					cout<<""<<endl;
					cout<<"# Butaca : "<<endl;
					for(int q=1;q<=cantButacasCli;q++){
						cout<<" | "<< ButacasCliente[q];
						if(q == 6 || q == 12 || q == 18){
							cout<<""<<endl;
						}
					}
					cout<<""<<endl;
					cout<<""<<endl;
					cout<<"Cantidad de Butacas : "<< cantButacasCli<<endl;
					cout<<"*******************************************************"<<endl;
					int precio = precioTanda(numT-1);
					int precioticket = precio * cantButacasCli; 
					cout<<"Precio por Butaca "<< precio <<endl;
					cout<<"*******************************************************"<<endl;
					cout<<"Total :                                 $ "<<precioticket<<endl;
					cout<<"*******************************************************"<<endl;
				}else{
					cout<<"Espacios NO disponibles"<<endl;
				}
		}else{
			cout<<"\nOpción no valida"<<endl;
		}
	}
	
int main() {
	int opt,opt2,idTanda,valorTanda;
	bool noDispo,repButaca,ediTanda;
	system("color 04");
	sala a1,a2,a3;
	iniciarsalas(a1);
	iniciarsalas(a2);
	iniciarsalas(a3);
		do{
			menu(); 
			cin>> opt;
			switch(opt){
				case 1:
					do{
						system("cls");
						menutandas(); 
						cin>> opt2;
						switch(opt2){
							
							case 1:
								system("cls");
								cout<<"***********************************"<<endl;
								cout<<"***********************************"<<endl;
								cout<<""<<endl;
								imprimirTandas();
								cout<<""<<endl;
								cout<<"***********************************"<<endl;
								cout<<"***********************************"<<endl;
								system("pause");
								break;
							
							case 2:
								system("cls");
								cout<<"***********************************"<<endl;
								cout<<"***********************************"<<endl;
								cout<<""<<endl;
								cout<<"  Edidar Peliculas "<<endl;
								cout<<""<<endl;
								imprimirTandas();
								cout<<""<<endl;
								cout<<"0 = Cancelar"<<endl;
								cout<<"Que tanda quiere editar 1-2-3 ?"<<endl;
								cin>>idTanda;
								ediTanda = false;
								while(ediTanda == false){
									if(idTanda == 1 || idTanda == 2 || idTanda == 3){
										cout<<"Nombre de la pelicula?" <<endl;
										cin >>tandas[idTanda-1][1];
										cout<<""<<endl;
										cout<<"Precio?" <<endl;
										cin >>tandas[idTanda-1][2];
										cout<<""<<endl;
										imprimirTandas();
										cout<<""<<endl;
										cout<<"Tanda "<<idTanda<<" Editada con exito"<<endl;
										system("pause");
										ediTanda = true;
									}else{
										cout<<"\nOpción no valida"<<endl;
										system("pause");
										
										ediTanda = true;
									}	
								}	
								break;
									
							default:
								system("cls");
								cout<<"\nOpción no valida"<<endl;
								opt2 = 3;
								break;				
						}
						system("cls");	
					}while(opt2 != 3);
				break;
				
				case 2:
					system("cls");
				    cout<<"***********************************"<<endl;
					cout<<"***********************************"<<endl;
					cout<<""<<endl;
					cout<<"\nReservar Espacios"<<endl;
					imprimirTandas();
					cout<<"\nEliga su Tanda?"<<endl;
					cin>>valorTanda;
					if(valorTanda==1){
						picktanda(a1,valorTanda);
					}else{
						if(valorTanda==2){
							picktanda(a2,valorTanda);
						}else{
							if(valorTanda ==3){
								picktanda(a3,valorTanda);
							}else{
								cout<<"\nOpción no valida"<<endl;
							}
						}
					}
					system("pause");
					break;
				
				case 3:
					system("cls");
					cout<<"";
					cout<<"************************************************************"<<endl;
					cout<<"************************************************************"<<endl;
					cout<<"\nVer Campos Reservados y Libres "<<endl;
					cout<<""<<endl;
					imprimirTandas();
					cout<<""<<endl;
					cout<<"\nEliga su Tanda?"<<endl;
					cin>>valorTanda;
					if(valorTanda == 1){
						imprimirsalas(a1,valorTanda);
					}else{
						if(valorTanda == 2){
								imprimirsalas(a2,valorTanda);
						}else{
							if(valorTanda == 3){
								imprimirsalas(a3,valorTanda);
							}else{
								cout<<"\nOpción no valida"<<endl;	
							}
						}
					}
					cout<<""<<endl;
					cout<<"************************************************************"<<endl;
					cout<<"************************************************************"<<endl;
					system("pause");
					break;
					
				case 4:
					system("cls");
					cout<<"";
					cout<<"************************************************************"<<endl;
					cout<<"************************************************************"<<endl;
					cout<<"\nCerrar Tanda"<<endl;
					cout<<"";
					imprimirTandas();
					cout<<""<<endl;
					cout<<"\nTanda a Cerrar?"<<endl;
					cin>>valorTanda;
					system("cls");	
					if(valorTanda == 1){
						cerrarTanda(a1,valorTanda);
					}else{
						if(valorTanda == 2){
								cerrarTanda(a2,valorTanda);
						}else{
							if(valorTanda == 3){
								cerrarTanda(a3,valorTanda);
							}else{
								cout<<"\nOpción no valida"<<endl;	
							}
						}
					}
					system("pause");
					break;
				
				case 5:
					cout<<"\nAdios"<<endl;
					break;
				
				default :
					cout<<"\nOpción no valida"<<endl;
					break;
			}
			system("cls");
			cout<<endl<<endl;
			
		}while(opt!=5);
	
	return 0;
}
