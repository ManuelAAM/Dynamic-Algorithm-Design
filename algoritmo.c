
int cortar(int* precios, int* memoria, int* solucion, int tam, int nPrecios){
	int valor = 0, valorAux = 0, corte = 0, precio =0;
	
	if(tam == 0){
		return 0;
	}
	if(memoria[tam] != -1){
		return memoria[tam];
	}
	
	for(int i = 1; i < tam+1; i++){
		if(i < nPrecios) precio = precios[i];
		else precio = 0;
		valorAux = precio + cortar(precios, memoria, solucion, tam -i, nPrecios);
		
		if(valorAux > valor){
			valor = valorAux;
			corte = i;
		}
		
	}
	
	memoria[tam] = valor;
	solucion[tam] = corte;
	return valor;
}