#include<X11/Xlib.h>
#include<X11/X.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

// estrutura representa a conexão com o servidor 
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


// Dou o comando de criar janela -> envia ao servidor de gerenciar janelas -> servidor renderiza a janela (e coletas os eventos do input e manda ao cliente).
void criar_janela(Display *d) {
    Window janela_pai = XDefaultRootWindow(d);

    int x = 0;
    int y = 0;
    unsigned int largura = 800;
    unsigned int altura = 600;
    int largura_borda = 5; 
    int profundidade_cor = CopyFromParent;
    unsigned int classe_janela = InputOutput;
    // define como os pixels são interpretados (modelo de cor, marcara RGB, Organização dos bits)
    Visual* visual_janela = CopyFromParent;
    // indica quais campos da estrutura `atributes ` serão usados onde separamos usando OR
    int valor_atributo = CWBackingPixel;
    // contem os valores dos atributos escolhidos acima. 
    XSetWindowAttributes atributos_janela = {};
    atributos_janela.background_pixel = 0xffafe9af; // cor de fundo. 

    Window janela = XCreateWindow(d, 
        janela_pai, 
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