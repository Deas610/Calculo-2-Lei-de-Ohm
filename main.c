#include <stdio.h>

// Define a estrutura de dados
typedef struct {
    float area;         // Area da secao transversal (mm²)
    float comprimento;  // Comprimento do material (mm^2)
    int material;       // Indice do material escolhido
} Dados;

// Estrutura para armazenar propriedades dos materiais
typedef struct {
    char nome[50];
    float resistividade; // Resistividade a 20 °C (ohm·metro)
    float coeficiente;   // Coeficiente de temperatura (1/°C)
} Material;

// Funcao para calcular a resistencia
float calcular_resistencia(Material mat, float comprimento, float area, float temperatura) {
    // Ajusta a resistividade com base na temperatura
    float resistividade_ajustada = mat.resistividade * (1 + mat.coeficiente * (temperatura - 20));
    // Segunda lei de Ohm: R = (resistividade * comprimento) / (area * 10^(-6))
    return (resistividade_ajustada * comprimento * 1.0e-3) / (area * 1.0e-6);
}

int main() {
    // Lista de materiais pre-definidos
    Material materiais[] = {
        {"Aluminio", 2.92e-8, 0.0039},
        {"Bronze", 6.70e-8, 0.002},
        {"Cobre puro", 1.62e-8, 0.00382},
        {"Cobre duro", 1.78e-8, 0.00382},
        {"Cobre recozido", 1.72e-8, 0.00382},
        {"Constantan", 5.00e-7, 0.00001},
        {"Estanho", 1.15e-7, 0.0042},
        {"Grafite", 1.30e-5, 0.0005},
        {"Ferro puro", 9.60e-8, 0.0052},
        {"Latao", 6.70e-8, 0.002},
        {"Manganina", 4.80e-7, 0.0},
        {"Mercurio", 9.60e-7, 0.00089},
        {"Nicromo", 1.10e-6, 0.00013},
        {"Niquel", 8.70e-8, 0.0047},
        {"Ouro", 2.40e-8, 0.0034},
        {"Prata", 1.58e-8, 0.0038},
        {"Platina", 1.06e-7, 0.0025},
        {"Tungstenio", 5.50e-8, 0.0041},
        {"Zinco", 5.60e-8, 0.0038}
    };
    int num_materiais = sizeof(materiais) / sizeof(materiais[0]);

    Dados entrada;
    float temperatura;

    // Apresenta a lista de materiais
    printf("Escolha o material:\n");
    for (int i = 0; i < num_materiais; i++) {
        printf("%d. %s\n", i + 1, materiais[i].nome);
    }
    printf("Digite o numero do material: ");
    scanf("%d", &entrada.material);

    // Valida a escolha do material
    if (entrada.material < 1 || entrada.material > num_materiais) {
        printf("Material invalido.\n");
    } else {
        Material mat_escolhido = materiais[entrada.material - 1];

        // Solicita as demais informacoes
        printf("Digite a temperatura em graus celsius: ");
        scanf("%f", &temperatura);
        printf("Digite o comprimento do material (mm^2): ");
        scanf("%f", &entrada.comprimento);
        printf("Digite a area da secao transversal (mm^2): ");
        scanf("%f", &entrada.area);

        // Calcula a resistencia
        float resistencia = calcular_resistencia(mat_escolhido, entrada.comprimento, entrada.area, temperatura);

        // Exibe o resultado
        printf("\nMaterial escolhido: %s\n", mat_escolhido.nome);
        printf("Resistencia calculada: %.6e ohms\n", resistencia);
    }

    return 0;
}
