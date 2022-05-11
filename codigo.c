#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char titulo[30];
    char link[350];
    char canal[30];
	int likes;
} Video;

int comparaStrings(char a[30], char b[30]){
	int k,c = 0,w1 = 0,w2 = 0, comp;
	w1 = strlen(a);
	w2 = strlen(b);
	if(w1 != w2)return 1;
	else{
		for(k = 0; k < w1 ; k++){
			comp = strcmp(&a[k],&b[k]);
			if(comp > 0)c++;
		}
		printf("%d",c);
		return c;
	}
}



int exibeMenu(){
	int opcao = 0;
	do{
		printf("\nBem vindo! \n1 - Cadastrar Videos \n2 - Verificar videos cadastrados \n3 - Pesquisar Videos Cadastrados\n0 - Sair");
		scanf("%d", &opcao);
		if(opcao > 3 || opcao < 0) printf("Opção invalida! Entre novamente com uma resposta valida");
	}while(opcao > 3 || opcao < 0);
	return opcao;
}

Video cadastrarVideo(){
	Video video;
	printf("Titulo do Video: ");
	scanf("%s", &video.titulo);
	
	printf("Link do Video: ");
	scanf("%s", &video.link);
	
	printf("Nome do canal: ");
	scanf("%s", &video.canal);
	
	printf("Total de curtidas do video: ");
	scanf("%d", &video.likes);
	
	printf("Video Cadastrado com Sucesso!");
	
	return video;
}

void exibeVideo(Video video){
	printf("\nInformacoes do video:\n");
	printf("\nTitulo: %s", video.titulo);
	printf("\nLink: %s", video.link);
	printf("\nCanal: %s", video.canal);
	printf("\nTotal de Likes: %d", video.likes);
}


void listarVideos(Video V[10], int i){
	int k;
	for(k = 0; k < i; k++)exibeVideo(V[k]);
}

void pesquisaTitulo(Video V[10],int i){
	int k = 0, c = 0;
	char tituloProcurado[30];
	printf("\nDigite o titulo procurado: ");
	scanf("%s",&tituloProcurado);
	printf("Resultado da Busca para: %s",tituloProcurado);
	//int len = sizeof(V)/sizeof(V[0]);
	
	for(k = 0;k < i; k++){
		c = comparaStrings(V[k].titulo,tituloProcurado);
		if(c == 0){
			exibeVideo(V[k]);
		}
	}
}

void pesquisaCurtida(Video V[10], int i){
	int k, c;
	printf("\nDigite o parametro de Curtidas: ");
	scanf("%d",&c);
	printf("Resultado da Busca para Videos com mais de %d Curtidas",c);
	for(k = 0; k < i ; k++){
		if(V[k].likes >= c)exibeVideo(V[k]);	
	}
}

void pesquisaCanal(Video V[10], int i){
	int k,c;
	char canal[30];
	printf("\nDigite o canal procurado: ");
	scanf("%s",&canal);
	printf("Resultado da Busca para Videos do canal: %s",canal);
	for(k = 0; k < i ; k++){
		c = comparaStrings(V[k].canal,canal);
		if(c == 0){
			exibeVideo(V[k]);	
		}
	}
	
}

void pesquisarVideos(Video V[10], int i){
	int opt = 0;
	printf("Qual método de Busca?\n");
	do{
		printf("\n1 - Pesquisa por Titulo \n2 - Total de Curtidas(Maior que)\n3 - Nome do Canal\n0 - Sair do menu de Busca");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				pesquisaTitulo(V, i);
				break;
			case 2:
				pesquisaCurtida(V, i);
				break;
			case 3:
				pesquisaCanal(V, i);
				break;
		}
	}while(opt != 0);
}



int main()
{
    int opt = 0, index = 0;
    Video videos[13];
   
    do{
    	opt = exibeMenu();
    	switch(opt){
    		case 1:
    			videos[index] = cadastrarVideo();
    			index = index+1;
    			break;
    		case 2:
    			listarVideos(videos, index);
    			break;
    		case 3:
    			pesquisarVideos(videos, index);
				break;    			
		}
    	
	}while(opt != 0);
	
	

}
