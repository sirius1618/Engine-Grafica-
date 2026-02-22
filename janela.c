#include<X11/Xlib.h>
#include<X11/X.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define COR_BRANCA_FUNDO 0Xffffff
#define COR_VERDE_FUNDO 0X79d221

Display* conetcar_servidor_grafico() {
    Display *d = XOpenDisplay(NULL); 

    if (d == NULL) {
        printf("Conexão com o servidor X falhou");
        exit(EXIT_FAILURE);
    }
    return d;
}

void fechar_conexao(Display *d) {
    if (d != NULL)  {
        XCloseDisplay(d);
        printf("Conexão com o servidor X encerrada"); 
    }
}

void criar_janela(Display *d) {
    Window janela_pai = XDefaultRootWindow(d);

    int x = 0;
    int y = 0;

    unsigned int largura = 800;
    unsigned int altura = 600;

    int largura_borda = 5; 
    int profundidade_cor = CopyFromParent;
    unsigned int classe_janela = InputOutput;

    Visual* visual_janela = CopyFromParent;
    int valor_atributo = CWBackingPixel;
    XSetWindowAttributes atributos_janela = {};
    atributos_janela.background_pixel = COR_BRANCA_FUNDO; 

    Window janela = XCreateWindow(
        d, janela_pai, 
        x, y,
        largura, altura,
        largura_borda,
        profundidade_cor,
        classe_janela,
        visual_janela,
        valor_atributo,
        &atributos_janela
    );

    XMapWindow(d, janela);

    for (;;) {
        XEvent evento = {};
        XNextEvent(d, &evento);
    }

}


int main () {
    Display *d = conetcar_servidor_grafico();
    criar_janela(d);
    fechar_conexao(d);
}