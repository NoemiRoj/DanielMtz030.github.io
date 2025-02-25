#include <stdio.h>

int main() {
    int destino;
    float peso_kg, peso_g, peso_total, costo = 0.0;
    
    // Entrada de datos
    printf("Seleccione el destino del envio:\n");
    printf("1 -> Nacional\n");
    printf("2 -> Internacional\n");
    printf("Opcion: ");
    scanf("%d", &destino);
    
    if (destino != 1 && destino != 2) {
        printf("Destino invalido. Solo se permite 1 (Nacional) o 2 (Internacional).\n");
        return 1;
    }

    printf("Ingrese el peso del paquete en kilogramos: ");
    scanf("%f", &peso_kg);
    printf("Ingrese el peso del paquete en gramos: ");
    scanf("%f", &peso_g);

    // Conversión a kilogramos
    peso_total = peso_kg + (peso_g / 1000);

    // Cálculo del costo
    if (destino == 1) { // Nacional
        if (peso_total < 1) {
            costo = 50;
        } else if (peso_total <= 5) {
            costo = peso_total * 40;
        } else if (peso_total <= 10) {
            costo = peso_total * 35;
        } else if (peso_total <= 20) {
            costo = peso_total * 30;
        } else {
            costo = peso_total * 30 + 200; // Recargo por exceder 20 kg
        }
    } else if (destino == 2) { // Internacional
        if (peso_total < 1) {
            costo = 120;
        } else if (peso_total <= 5) {
            costo = peso_total * 100;
        } else if (peso_total <= 10) {
            costo = peso_total * 90;
        } else if (peso_total <= 20) {
            costo = peso_total * 80;
        } else {
            costo = peso_total * 80 + 500; // Recargo por exceder 20 kg
        }
    }

    // Salida de datos
    printf("El costo total del envio es: $%.2f MXN\n", costo);
    return 0;}
    
