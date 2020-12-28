#define LINHAS 5
#define COLUNAS 10

void alocaMapa();
void processarMapa(FILE* ficheiro);
void liberarMapa();
void lerMapa(FILE* ficheiro);
void imprimeMapa();
int acabou();
void move(char comando);