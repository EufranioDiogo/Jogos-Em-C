struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

void alocaMapa();
void processarMapa(FILE* ficheiro);
void liberarMapa();
void lerMapa(FILE* ficheiro);
void imprimeMapa();