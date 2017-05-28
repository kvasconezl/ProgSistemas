#include <stdio.h>
#include <stdlib.h>
#include <string.h>



	
void encriptCiclico(int clave, char palabra[])  {
	char enc[1024] = {0};
	char abcMinus[28] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '\0'};
	char abcMayus[28] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '\0'};
	int lenPalabra, lenAbc, i, j, bandera;
	lenPalabra = strlen(palabra);
	lenAbc = strlen(abcMinus);
	bandera = 0;
	for(i = 0; i < lenPalabra; i++) {
		for(j = 0; j < lenAbc; j++) {
			if((abcMinus[j] == palabra[i]) && !(palabra[i] == ' ')) {
				bandera = 1;
				if((j+clave) < 27){
					enc[i] = abcMinus[j+clave];
				} else {
					enc[i] = abcMinus[(j+clave) - 27];
				}
			}
			if(palabra[i] == ' ') {
				enc[i] = ' ';
			}
		}
	}
	if(bandera == 0) {
		for(i = 0; i < lenPalabra; i++) {
			for(j = 0; j < lenAbc; j++) {
				if(abcMayus[j] == palabra[i] && !(palabra[i] == ' ')) {
					bandera = 1;
					if((j+clave) < 27){
						enc[i] = abcMayus[j+clave];
					} else {
						enc[i] = abcMayus[(j+clave) - 26];
					}
				}
				if(palabra[i] == ' ') {
					bandera = 1;
					enc[i] = ' ';
				}
			}
		}
	}
	printf("Palabra encriptada: %s\n", enc);
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
