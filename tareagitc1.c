#include <stdio.h>
#include <stdlib.h>
#include <string.h>



	
void encriptCiclico(int clave, char palabra[])  {
	char enc[1024] = {0};
	char abcMinus[28] = "abcdefghijklmnopqrstuvwxyz ";
	char abcMayus[28] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	int lenPalabra, lenAbc, i, j, bandera;
	lenPalabra = strlen(palabra);
	lenAbc = strlen(abcMinus);
	bandera = 0;
	for(i = 0; i < lenPalabra; i++) {
		for(j = 0; j < lenAbc; j++) {
			if(abcMinus[j] == palabra[i]) {
				bandera = 1;
				if((j+clave) < 27){
					enc[i] = abcMinus[j+clave];
				} else {
					enc[i] = abcMinus[(j+clave) - 27];
				}
			}
		}
	}
	if(bandera == 0) {
		for(i = 0; i < lenPalabra; i++) {
			for(j = 0; j < lenAbc; j++) {
				if(abcMayus[j] == palabra[i]) {
					bandera = 1;
					if((j+clave) < 26){
						enc[i] = abcMayus[j+clave];
					} else {
						enc[i] = abcMayus[(j+clave) - 26];
					}
				}
			}
		}
	}
	printf("Palabra encriptada: %s", enc);
}

	
//void encriptMorse(int car, char *palabra) {
//	
//}



int main(int argc, char *argv[]) {
	char palabra[1024];
	int clave;
	
	
	if(argc == 3){
		clave = atoi(argv[1]);
		encriptCiclico(clave,argv[2]);
	} else {
		printf("Ingrese la palabra:\n");
		fgets(palabra, 256, stdin);
		printf("Ingrese la clave numerica\n");
		scanf("%d", &clave);
		encriptCiclico(clave, palabra);
	}
	return 0;
}
