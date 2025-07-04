/*
Alunos: Guilherme de Oliveira Aredes - 2025.1.08.026
        Pedro Ferreira Prado - 2025.1.08.028
 Objetivo: adquirir conhecimentos de manipulação de  matrizes (imagens) com ponteiros 
        implementando funcionalidades que geram novas matrizes (imagens) a partir de valores carregados 
        de arquivos-texto em formato PGM de representação de imagens.
 Data: 2025-02-20
*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// ========== IMPLEMENTAÇÃO DAS FUNÇÕES DE PROCESSAMENTO ==========

/*
 * Função: lerImagem
 * Objetivo: carrega uma imagem PGM de um arquivo
 */
void lerImagem(const std::string& nomeArquivo, int*& dados, int& linhas, int& colunas, int& maxValor) {
    ifstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        cout << "Erro: não foi possível abrir o arquivo " << nomeArquivo << endl;
        return;
    }
    
    string formato;
    arquivo >> formato;
    
    // Verifica se é formato PGM (P2 para ASCII)
    if (formato != "P2") {
        cout << "Erro: formato de arquivo não suportado. Esperado P2 (PGM ASCII)" << endl;
        arquivo.close();
        return;
    }
    
    // Lê dimensões e valor máximo
    arquivo >> colunas >> linhas >> maxValor;
    
    // Libera memória anterior se existir
    if (dados != nullptr) {
        delete[] dados;
    }
    
    // Aloca memória para a nova imagem
    dados = new int[linhas * colunas];
    
    // Lê os pixels da imagem
    int* ptr = dados;
    for (int i = 0; i < linhas * colunas; i++) {
        arquivo >> *ptr;
        ptr++;
    }
    
    arquivo.close();
    cout << "Imagem carregada com sucesso: " << colunas << "x" << linhas << " pixels" << endl;
}

/*
 * Função: escreverImagem
 * Objetivo: salva uma imagem em formato PGM
 */
void escreverImagem(const std::string& nomeArquivo, int* dados, int linhas, int colunas, int maxValor) {
    if (dados == nullptr) {
        cout << "Erro: nenhuma imagem carregada para salvar" << endl;
        return;
    }
    
    ofstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        cout << "Erro: não foi possível criar o arquivo " << nomeArquivo << endl;
        return;
    }
    
    // Escreve cabeçalho PGM
    arquivo << "P2" << endl;
    arquivo << colunas << " " << linhas << endl;
    arquivo << maxValor << endl;
    
    // Escreve os pixels
    int* ptr = dados;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            arquivo << *ptr;
            if (j < colunas - 1) arquivo << " ";
            ptr++;
        }
        arquivo << endl;
    }
    
    arquivo.close();
    cout << "Imagem salva com sucesso: " << nomeArquivo << endl;
}

/*
 * Função: escurecerImagem
 * Objetivo: escurece a imagem diminuindo os valores dos pixels
 */
void escurecerImagem(int* dados, int linhas, int colunas, int maxValor, int fator) {
    if (dados == nullptr) {
        cout << "Erro: nenhuma imagem carregada" << endl;
        return;
    }
    
    int* ptr = dados;
    for (int i = 0; i < linhas * colunas; i++) {
        // Subtrai o fator, garantindo que não fique negativo
        *ptr = max(0, *ptr - fator);
        ptr++;
    }
    
    cout << "Imagem escurecida com fator " << fator << endl;
}

/*
 * Função: clarearImagem
 * Objetivo: clareia a imagem aumentando os valores dos pixels
 */
void clarearImagem(int* dados, int linhas, int colunas, int maxValor, int fator) {
    if (dados == nullptr) {
        cout << "Erro: nenhuma imagem carregada" << endl;
        return;
    }
    
    int* ptr = dados;
    for (int i = 0; i < linhas * colunas; i++) {
        // Soma o fator, garantindo que não ultrapasse o valor máximo
        *ptr = min(maxValor, *ptr + fator);
        ptr++;
    }
    
    cout << "Imagem clareada com fator " << fator << endl;
}

/*
 * Função: rotacionarDireita
 * Objetivo: rotaciona a imagem 90 graus no sentido horário
 */
void rotacionarDireita(int* dados, int linhas, int colunas, int*& novaImagem) {
    if (dados == nullptr) {
        cout << "Erro: nenhuma imagem carregada" << endl;
        return;
    }
    
    // Aloca memória para a nova imagem (dimensões invertidas)
    novaImagem = new int[linhas * colunas];
    
    // Rotação 90° horário: (i,j) -> (j, linhas-1-i)
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int* ptrOriginal = dados + (i * colunas + j);
            int* ptrNova = novaImagem + (j * linhas + (linhas - 1 - i));
            *ptrNova = *ptrOriginal;
        }
    }
    
    cout << "Imagem rotacionada 90° para direita" << endl;
}

/*
 * Função: rotacionarEsquerda
 * Objetivo: rotaciona a imagem 90 graus no sentido anti-horário
 */
void rotacionarEsquerda(int* dados, int linhas, int colunas, int*& novaImagem) {
    if (dados == nullptr) {
        cout << "Erro: nenhuma imagem carregada" << endl;
        return;
    }
    
    // Aloca memória para a nova imagem (dimensões invertidas)
    novaImagem = new int[linhas * colunas];
    
    // Rotação 90° anti-horário: (i,j) -> (colunas-1-j, i)
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int* ptrOriginal = dados + (i * colunas + j);
            int* ptrNova = novaImagem + ((colunas - 1 - j) * linhas + i);
            *ptrNova = *ptrOriginal;
        }
    }
    
    cout << "Imagem rotacionada 90° para esquerda" << endl;
}

/*
 * Função: negativaImagem
 * Objetivo: cria o negativo da imagem (inverte os tons)
 */
void negativaImagem(int* dados, int linhas, int colunas, int maxValor) {
    if (dados == nullptr) {
        cout << "Erro: nenhuma imagem carregada" << endl;
        return;
    }
    
    int* ptr = dados;
    for (int i = 0; i < linhas * colunas; i++) {
        // Inverte o valor: pixel_novo = maxValor - pixel_original
        *ptr = maxValor - *ptr;
        ptr++;
    }
    
    cout << "Negativa da imagem aplicada" << endl;
}

/*
 * Função: binarizarImagem
 * Objetivo: converte a imagem para binária (preto e branco)
 */
void binarizarImagem(int* dados, int linhas, int colunas, int maxValor, int limiar) {
    if (dados == nullptr) {
        cout << "Erro: nenhuma imagem carregada" << endl;
        return;
    }
    
    int* ptr = dados;
    for (int i = 0; i < linhas * colunas; i++) {
        // Se pixel >= limiar, vira branco (maxValor), senão vira preto (0)
        *ptr = (*ptr >= limiar) ? maxValor : 0;
        ptr++;
    }
    
    cout << "Imagem binarizada com limiar " << limiar << endl;
}

/*
 * Função: iconizarImagem
 * Objetivo: reduz a imagem para 64x64 pixels (iconização)
 */
void iconizarImagem(int* dados, int linhas, int colunas, int*& novaImagem) {
    if (dados == nullptr) {
        cout << "Erro: nenhuma imagem carregada" << endl;
        return;
    }
    
    const int TAMANHO_ICONE = 64;
    
    // Aloca memória para a imagem iconizada
    novaImagem = new int[TAMANHO_ICONE * TAMANHO_ICONE];
    
    // Calcula fatores de escala
    double escalaX = (double)colunas / TAMANHO_ICONE;
    double escalaY = (double)linhas / TAMANHO_ICONE;
    
    // Redimensiona usando amostragem simples (nearest neighbor)
    for (int i = 0; i < TAMANHO_ICONE; i++) {
        for (int j = 0; j < TAMANHO_ICONE; j++) {
            // Mapeia coordenadas do ícone para a imagem original
            int origemX = (int)(j * escalaX);
            int origemY = (int)(i * escalaY);
            
            // Garante que não ultrapasse os limites
            origemX = min(origemX, colunas - 1);
            origemY = min(origemY, linhas - 1);
            
            int* ptrOriginal = dados + (origemY * colunas + origemX);
            int* ptrIcone = novaImagem + (i * TAMANHO_ICONE + j);
            
            *ptrIcone = *ptrOriginal;
        }
    }
    
    cout << "Imagem iconizada para 64x64 pixels" << endl;
}

// ========== FUNÇÃO PRINCIPAL ==========
int main() {
    // ========== DECLARAÇÃO DE VARIÁVEIS ==========
    int* imagem = nullptr;          // Ponteiro para array que armazenará os pixels da imagem
    int linhas = 0, colunas = 0;    // Dimensões da imagem (inicializadas como 0)
    int maxValor = 0;               // Valor máximo dos pixels na imagem PGM
    int opcao;                      // Variável para armazenar a opção escolhida pelo usuário

    // ========== LOOP PRINCIPAL DO MENU ==========
    do {
        // Exibe o menu de opções para o usuário
        cout << "\n=== MENU PGM ===\n";
        cout << "1. Ler imagem PGM\n";
        cout << "2. Clarear imagem\n";
        cout << "3. Escurecer imagem\n";
        cout << "4. Rotacionar para direita\n";
        cout << "5. Rotacionar para esquerda\n";
        cout << "6. Negativa da imagem\n";
        cout << "7. Binarizar imagem\n";
        cout << "8. Iconizar imagem (64x64)\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;   // Lê a opção escolhida pelo usuário

        // Declaração de variáveis auxiliares usadas em diferentes casos
        string nomeEntrada, nomeSaida;  // Nomes dos arquivos de entrada e saída
        int fator, limiar;              // Fatores para operações e limiar para binarização
        int* novaImagem = nullptr;      // Ponteiro para nova imagem (usado em rotações)

        // ========== SWITCH PARA PROCESSAR A OPÇÃO ESCOLHIDA ==========
        switch (opcao) {
            case 1:
                // ========== CARREGAR IMAGEM PGM ==========
                cout << "Nome do arquivo PGM de entrada: ";
                cin >> nomeEntrada;
                // Chama função para ler a imagem do arquivo
                // Os parâmetros são passados por referência para serem modificados
                lerImagem(nomeEntrada, imagem, linhas, colunas, maxValor);
                break;

            case 2:
                // ========== CLAREAR IMAGEM ==========
                cout << "Fator de clareamento: ";
                cin >> fator;
                // Aplica o clareamento na imagem existente
                clarearImagem(imagem, linhas, colunas, maxValor, fator);
                cout << "Nome do arquivo de saída: ";
                cin >> nomeSaida;
                // Salva a imagem modificada
                escreverImagem(nomeSaida, imagem, linhas, colunas, maxValor);
                break;

            case 3:
                // ========== ESCURECER IMAGEM ==========
                cout << "Fator de escurecimento: ";
                cin >> fator;
                // Aplica o escurecimento na imagem existente
                escurecerImagem(imagem, linhas, colunas, maxValor, fator);
                cout << "Nome do arquivo de saída: ";
                cin >> nomeSaida;
                // Salva a imagem modificada
                escreverImagem(nomeSaida, imagem, linhas, colunas, maxValor);
                break;

            case 4:
                // ========== ROTAÇÃO PARA DIREITA (90° HORÁRIO) ==========
                // Cria uma nova imagem rotacionada
                rotacionarDireita(imagem, linhas, colunas, novaImagem);
                cout << "Nome do arquivo de saída: ";
                cin >> nomeSaida;
                // IMPORTANTE: na rotação, as dimensões se invertem (linhas <-> colunas)
                escreverImagem(nomeSaida, novaImagem, colunas, linhas, maxValor);
                // Libera a memória da nova imagem após uso
                delete[] novaImagem;
                break;

            case 5:
                // ========== ROTAÇÃO PARA ESQUERDA (90° ANTI-HORÁRIO) ==========
                // Cria uma nova imagem rotacionada
                rotacionarEsquerda(imagem, linhas, colunas, novaImagem);
                cout << "Nome do arquivo de saída: ";
                cin >> nomeSaida;
                // IMPORTANTE: na rotação, as dimensões se invertem (linhas <-> colunas)
                escreverImagem(nomeSaida, novaImagem, colunas, linhas, maxValor);
                // Libera a memória da nova imagem após uso
                delete[] novaImagem;
                break;

            case 6:
                // ========== NEGATIVA DA IMAGEM ==========
                // Inverte os tons da imagem (claro vira escuro e vice-versa)
                negativaImagem(imagem, linhas, colunas, maxValor);
                cout << "Nome do arquivo de saída: ";
                cin >> nomeSaida;
                // Salva a imagem com negativa aplicada
                escreverImagem(nomeSaida, imagem, linhas, colunas, maxValor);
                break;

            case 7:
                // ========== BINARIZAR IMAGEM ==========
                cout << "Limiar para binarização (0-" << maxValor << "): ";
                cin >> limiar;
                // Converte para preto e branco usando o limiar
                binarizarImagem(imagem, linhas, colunas, maxValor, limiar);
                cout << "Nome do arquivo de saída: ";
                cin >> nomeSaida;
                // Salva a imagem binarizada
                escreverImagem(nomeSaida, imagem, linhas, colunas, maxValor);
                break;

            case 8:
                // ========== ICONIZAR IMAGEM (64x64) ==========
                // Reduz a imagem para um ícone de 64x64 pixels
                iconizarImagem(imagem, linhas, colunas, novaImagem);
                cout << "Nome do arquivo de saída: ";
                cin >> nomeSaida;
                // Salva o ícone (sempre 64x64)
                escreverImagem(nomeSaida, novaImagem, 64, 64, maxValor);
                // Libera a memória da nova imagem após uso
                delete[] novaImagem;
                break;

            case 0:
                // ========== SAIR DO PROGRAMA ==========
                cout << "Encerrando...\n";
                break;

            default:
                // ========== OPÇÃO INVÁLIDA ==========
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);   // Continua executando até o usuário escolher sair (opção 0)

    // ========== LIMPEZA DE MEMÓRIA ==========
    // Libera a memória alocada para a imagem antes de encerrar o programa
    delete[] imagem;
    
    return 0;   // Retorna 0 indicando execução bem-sucedida
}

