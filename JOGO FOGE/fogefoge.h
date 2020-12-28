#define LINHAS 5
#define COLUNAS 10

void lerMapa(FILE* ficheiro, mapa m);
void processarMapa(FILE* ficheiro, mapa m);
int acabou();
void move(char comando);