#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1 - análise estatística: percentual de participantes (% pele negra, %pele branca... perfil que participou mais da pesquisa)
//2 - Usando arquivos --> criar um arquivo para cada participantes (função) :: SALVAR E RECUPERAR FUNÇÕES
//3 - Estruturas
// qtdN/n
//N VARIÁVEL

typedef struct{
    int idade;
    char corPele;
    char tipoPele;
    char nome[50];
    char produto[150];
}Participante;


//VARIÁVEL GLOBAL
Participante p[100];
int i=0;
int qtdCorN = 0, qtdCorP = 0, qtdCorB = 0, qtdIdade = 0, qtdCor = 0, qtdTipoPele = 0, qtdTipoPeleS = 0, qtdTipoPeleM = 0, qtdTipoPeleO = 0;


//função para criar o menu
int menu(){
    int escolha;

    printf("1 - Responder questionario\n");
    printf("2 - Mostrar estatisticas\n");
    printf("3 - Mostrar descricao dos produtos\n");
    printf("4 - Sair\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &escolha);

    return escolha;
}


int responderQuestionario()
{

        char opcao;

    printf("\nOla! Somos o Skincare e nosso objetivo e fazer com que voce possa utilizar o melhor produto para a pele do seu rosto de acordo com as necessidades que ele precisa. Que tal preencher nosso cadastro? Leva apenas alguns minutos. Vamos la?\n");



    do
    {
        fflush(stdin);
        printf ("\nQual o seu nome? ");
        scanf ("%49[^\n]", p[i].nome);

        fflush(stdin);
        printf ("\nQual a sua idade? ");
        scanf ("%d", &p[i].idade);

                fflush(stdin);
            printf ("\nQual seu tipo de pele? Digite, O para oleosa, M para mista e S para seca. ");
            scanf("%c", &p[i].tipoPele);


            if(p[i].tipoPele!='O' && p[i].tipoPele!='M' && p[i].tipoPele!='S'){
                printf("Verifique se o dado esta correto!\n");
            }
        }while(p[i].tipoPele!='O' && p[i].tipoPele!='M' && p[i].tipoPele!='S');

        //verificando o tipo de pele
        if(p[i].tipoPele =='O'){
          qtdTipoPeleO = qtdTipoPeleO +1;
        }else if(p[i].tipoPele == 'M'){
          qtdTipoPeleM = qtdTipoPeleM + 1;
        } else if(p[i].tipoPele == 'S'){
          qtdTipoPeleS = qtdTipoPeleS +1;
        }

        getchar();
        do {
        fflush(stdin);

        printf ("\nQual sua cor de pele? Digite N para negra, B para branca e P para parda. ");
        scanf("%c", &p[i].corPele);

            if (p[i].corPele!='N' && p[i].corPele!='B' && p[i].corPele!='P'){
                printf("Verifique se o dado esta correto!\n");
            }while (p[i].corPele!='N' && p [i].corPele!='B' && p[i].corPele!='P');

        //verificando cor de pele
        if (p[i].corPele == 'B'){
         qtdCorB = qtdCorB +1;
        }else if (p[i].corPele == 'N'){
         qtdCorN = qtdCorN +1;
        } else if (p[i].corPele == 'P'){
         qtdCorP = qtdCorP +1;
        }

        getchar();

        if ((p[i].idade>=18) && (p[i].idade<=25)){
            printf("\nO produto pra sua pele eh o SafeYouth.\n ");
            strcpy(p[i].produto, "O produto pra sua pele eh o SafeYouth.");
        }else if ((p[i].idade >=26) && (p[i].idade <=35)){
            printf("\nO produto indicado pra sua pele eh o Aging Stopper.\n ");
            strcpy(p[i].produto, "O produto indicado pra sua pele eh o Aging Stopper.");
        }else if ((p[i].idade >=36)&& (p[i].idade<=45)){
            printf("\nO produto indicado para sua pele eh o KeepYouth.\n  ");
            strcpy(p[i].produto, "O produto indicado pra sua pele eh o KeepYouth.");
        }else if ((p[i].idade>=46) && (p[i].idade<=55)){
            printf("\nO produto indicado para sua pele eh o Aging Cool.\n ");
            strcpy(p[i].produto, "O produto indicado pra sua pele eh o Aging Cool.");
        }else if ((p[i].idade>=56 && (p[i].idade>=65))){
            printf("\nO produto indicado para sua pele eh o Gold Rush.\n ");
            strcpy(p[i].produto, "O produto indicado pra sua pele eh o Gold Rush.");
        }
        i++;

        printf("Outro participante vai responder? ");
        scanf("%c", &opcao);
    }while(opcao == 's' || opcao == 'S');
    return 0;
}


void mostraEstatistica()
{

        printf("O percentual de pessoas com pele negra que realizaram a analise foi de: %f", ((float)qtdCorN/(float)i)*100);

        printf("\nO percentual de pessoas com pele branca que realizaram a analise foi de: %f", ((float)qtdCorB/(float)i)*100);

        printf("\nO percentual de pessoas com pele parda que realizaram a analise foi de: %f", ((float)qtdCorP/(float)i)*100);

        printf("\nA quantidade de pessoas brancas que fizeram o teste eh de %d", qtdCorB);

        printf("\nA quantidade de pessoas negras que fizeram o teste eh de %d", qtdCorN);

        printf("\nA quantidade de pessoas pardas que fizeram o teste eh de %d\n", qtdCorP);

        printf("\nA quantidade de pessoas com pele oleosa que fizeram o teste eh de %d", qtdTipoPeleO);

        printf("\nA quantidade de pessoas com pele mista que fizeram o teste eh de %d", qtdTipoPeleM);

        printf("\nA quantidade de pessoas com pele seca que fizeram o teste eh de %d", qtdTipoPeleS);

}

void mostraProduto(){
    char busca[50];

    printf("Digite o nome de qual produto deseja informacoes: ");
    fflush(stdin);
    scanf("%49[^\n]", busca);

    strlwr(busca);

    if(strcmp(busca, "safe youth") == 0){
        printf("O SafeYouth é um produto para quem esta comecendo a mostrar os primeiros sinais de envelhecimento e quer previnir que eles avancem com o tempo. Traz o que ha de mais novo em tecnologia para impedir o avanco dos sinais da idade ainda na juventude.");
    }
    else if(strcmp(busca, "aging stopper") == 0){
        printf("Indicado para quem ja possui marcas expressivas do envelhecimento, o Aging Stopper possui o diferencial de vir com total controle antimanchas e que protege voce dos raios solares gracas ao fator de protecao solar na densidade 70, fazendo com que seu rosto esteje sempre protegido dos danos causados pelo sol.");
    }else if(strcmp(busca, "keep youth") == 0){
        printf("Para aqueles que ja passaram dos 30, eh comum que o rosto tenha cada vez mais sinais causados pelo envelhecimento e estresse. O Keep Youth ajuda a promover a restauracao da pele logo nas primeiras semanas de uso gracas a nanotecnologia presente no produto que ajuda o corpo a produzir mais colageno na area em que foi aplicada e assim fazendo com o que o rosto mantenha a aparencia jovem. ");
    }else if(strcmp(busca, "aging cool") == 0){
        printf("O Aging Cool balanceia o que ha de melhor no mercado em prevencao causado pelo fotoenvelhecimento. Rico em colageno e com poder de protecao solar FPS 70, o produto faz com que os danos causados pelo sol sejam reduzidos em ate 50 por cento a partir da primeira aplicacao, alem de promover a producao de colageno no rosto e o mantendo com a firmeza que ele precisa. ");
    }else if(strcmp(busca, "gold rush") == 0){
        printf("Este produto eh enriquecido com os beneficios contidos no ouro de 24 quilates. Sabe-se que o poder de restauracao contido no ouro eh tao eficaz que ha inumeros produtos no mercado que possuem esse ativo em sua composicao. Esse produto foi desenvolvido com o que ha de mais moderno em nanotecnologia de restauracao da derme no mundo e apresenta resultados logo na primeira semana de uso. Tenha uma pele renovada em apenas uma semana! ");
    }
    else{
        printf("Produto inexistente\n");
    }
}




int main(){
    int escolhaMenu; // retangulo

    do{
        system("cls");
        escolhaMenu = menu();

        switch(escolhaMenu){
            case 1: responderQuestionario();
            break;

            case 2:
                if(i != 0){
                        mostraEstatistica();
                }
                else{
                    printf("Nenhum dado inserido\n");
                }
            break;

            case 3: mostraProduto();
                break;

            case 4: printf("Saindo do sistema\n");
            break;

            default:
                printf("Opção invalida\n");

        }
        system("pause");
    }while(escolhaMenu != 4); //losango

    return 0;
}
