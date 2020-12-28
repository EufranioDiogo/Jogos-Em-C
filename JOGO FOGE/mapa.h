struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

void alocaMapa(mapa m);
void liberarMapa(mapa m);
void lerMapa(FILE* ficheiro, mapa m);