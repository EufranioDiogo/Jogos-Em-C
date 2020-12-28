#define LINHAS 5
#define COLUNAS 10

void lerMapa(FILE* ficheiro);
void processarMapa(FILE* ficheiro);
int acabou();
void move(char comando);
void alocaMapa();
void liberarMapa();
void imprimeMapa();