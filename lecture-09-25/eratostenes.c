#include <stdio.h>
#include <math.h>

#define CIRC_ANGLE 360
#define PI 3.1415926

#define EARTH_RADIUS 6371

// só para mostrar a declaração de macros a partir de outras macros
#define EARTH_PERIMETER (2*PI* EARTH_RADIUS) / 2

int main() {
    double lat1, lat2, dist;

    printf("latitude (decimal) dos lugares (1 e 2): ");
    
    //scanf retorna o número de valores lidos com sucesso pelo scanf
    int n = scanf("%lf %lf", &lat1, &lat2);
    
    printf("foram lidos %d valores\n", n);

    if (n != 2) {
        printf("latitudes inválidas\n");
    }
    else {
		printf("distância entre os lugares: ");
		scanf("%lf", &dist);


		double angle = lat1 - lat2;

		double earth_perimeter = dist * CIRC_ANGLE / angle;
		double earth_radius = earth_perimeter / (2*PI);

		printf("perimetro da terra = %lf\n", earth_perimeter);
		printf("raio da terra = %lf\n", earth_radius);
	   
    }
   
     return 0;
}
