
/**
 * define uma nova semente (valor inicial) para o gerador pseudo-aleatório
 * relacionada com o tempo de calendário
 */
void random_init();

/**
 * retorna um valor aleatório dentro dos limites
 * especificados por parâmetro (intervalo fechado)
 */
int random_range(int start, int end);
    
/**
 * ler um valor inteiro garantindo 
 * que está dentro do intervalo especificado
 */
int read_int(int start, int end);