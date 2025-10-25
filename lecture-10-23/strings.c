int str_length(char str[]) {
    int i= 0;
    while(str[i] != 0) {
        ++i;
    }
    return i;
}

void str_copy(char dest[], char src[]) {
    int i= 0;
    // while(src[i] != 0) {
    //     dest[i] = src[i];
    //     ++i;
    // }
    // do {
    //     dest[i] = src[i]; 
    //     ++i;
    // }
    // while (src[i-1] != 0);

    while ((dest[i] = src[i]) != 0) {
        ++i;
    }
   
}


void str_capitalize(char str[]) {
    // TODO
}

int main() {
    char linha[] = "bom dia";

    int sz = str_length(linha);
    printf("tamanho da string linha é: %d\n", sz);

    char result[100] = "111111111111111111111111111111111111";
    str_copy(result, linha);

    printf("conteúdo de result é: '%s'\n", result);
    return 0;
}