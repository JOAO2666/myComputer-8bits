//FILA SEQUENCIAl

typedef struct{
    int N;
    int INICIO;
    int FIM;
    int val[MAX];

}FILA_SEQ;
void cria_fila(FILA_SEQ *);
int eh_vazia(FILA_SEQ *);      
int tam(FILA_SEQ *);
void inserir(FILA_SEQ *,int);
int cons(FILA_SEQ *);
void ret(FILA_SEQ *);
int cons_ret(FILA_SEQ *);

void cria_fila(FILA_SEQ *f){
    f->N = f->INICIO = 0;
    f->FIM = -1;
}
int eh_vazia(FILA_SEQ *f){
    return (f->N == 0);
}

int tam(FILA_SEQ *f){
    return(f->N);
}

void ins(FILA_SEQ *f, int v){
    if(f->N==MAX){
        printf("\nErro!Estouro na fila.\n");
        exit(1);
    }
    f->FIM = ((f->FIM)+ 1) % MAX;
    f->val[f->FIM] = v;
    f->N++;
}
int cons(FILA_SEQ *f){
  if(eh_vazia(f)){
    printf("\nErro!Consulta na fila vazia.\n");
    exit(2);
  }
  return(f->val[f->INICIO]);
}

void ret(FILA_SEQ *f){
    if(eh_vazia(f)){
        printf("\nErro!Remocao na fila vazia.\n");
        exit(3);
    }else{
    f->INICIO = (f->INICIO+1) % MAX;
    f->N--;
  }
}

int cons_ret(FILA_SEQ *f){
   if(eh_vazia(f)){
    printf("\nErro!Consulta e retirada na fila vazia.\n");
    exit(4);
   }else{
    int v = f->val[f->INICIO];
    f->INICIO = ((f->INICIO+1) % MAX);
    f->N--;
    return(v);
   }
}

void gera_fila (FILA_SEQ *f, int m, int n)
{
    if (m>n)
    {
        printf ("\nERRO! Intervalo invalido.\n");
        exit (5);
    } else 
    if (m==n){
        cria_fila (f);
        ins (f, m);
    } else {
        gera_fila (f, m, n-1);
        ins (f, n);
    }
}


//FILAS ENCADEADAS

typedef struct nodo{
    int inf;
    struct nodo *next;
}NODO;
typedef struct{
    NODO *INICIO;
    NODO *FIM;
}DESCRITOR;

typedef DESCRITOR *FILA_ENC;
void cria_fila(FILA_ENC);
int eh_vazia(FILA_ENC);
void ins(FILA_ENC, int);
int cons(FILA_ENC);
void ret(FILA_ENC);
int cons_ret(FILA_ENC);
void destruir(FILA_ENC);

void cria_fila_enc (FILA_ENC *pf)
{
   *pf=(DESCRITOR *)malloc(sizeof(DESCRITOR));
   if (!*pf)
   {
      printf ("\nERRO! Memoria insuficiente!\n");
      exit (1);
   }
   (*pf)->INICIO=(*pf)->FIM=NULL;
}

int eh_vazia_enc (FILA_ENC f)
{
   return (f->INICIO == NULL);
}

void ins_enc (FILA_ENC f, int v)
{
   NODO *novo;
   novo = (NODO *) malloc (sizeof(NODO));
   if (!novo) {
      printf ("\nERRO! Memoria insuficiente!\n");
      exit (1);
   }
   novo->inf = v;
   novo->next = NULL;
   if (eh_vazia_enc(f))
      f->INICIO=novo;
   else
      f->FIM->next=novo;
   f->FIM=novo;
}

int cons_enc (FILA_ENC f)
{
   if (eh_vazia_enc(f))
   {
      printf ("\nERRO! Consulta em fila vazia!\n");
      exit (2);
   }
   else
      return (f->INICIO->inf);
}

void ret_enc (FILA_ENC f)
{
   if (eh_vazia_enc(f))
   {
      printf ("\nERRO! Retirada em fila vazia!\n");
      exit (3);
   }
   else
   {
      NODO *aux=f->INICIO;
      f->INICIO=f->INICIO->next;
      if (!f->INICIO)
         f->FIM=NULL;
      free (aux);
   }
}

int cons_ret_enc (FILA_ENC f)
{
   if (eh_vazia_enc(f))
   {
      printf ("\nERRO! Consulta e retirada em fila vazia!\n");
      exit (4);
   }
   else
   {
      int v=f->INICIO->inf;
      NODO *aux=f->INICIO;
      f->INICIO=f->INICIO->next;
      if (!f->INICIO)
         f->FIM=NULL;
      free (aux);
      return (v);
   }
}

void destruir_enc (FILA_ENC f)
{
   NODO *aux;
   while (f->INICIO)
   {
      aux=f->INICIO;
      f->INICIO=f->INICIO->next;
      free(aux);
   }
   free(f);
}


typedef struct nodo2 {
    int inf;
    struct nodo2 * next;
 }NODO2;
 typedef struct {
    int ne;
    NODO2 *INICIO;
    NODO2 *FIM;
 }DESCRITOR2;
 typedef DESCRITOR2 *FILA_ENC2;
 void cria_fila2 (FILA_ENC2 *);
 int eh_vazia2 (FILA_ENC2);
 void ins2 (FILA_ENC2, int);
 int cons2 (FILA_ENC2);
 void ret2 (FILA_ENC2);
 int cons_ret2 (FILA_ENC2);
 void destruir2 (FILA_ENC2);
 int tam2 (FILA_ENC2);


 void cria_fila2 (FILA_ENC2 *pf)
{
   *pf=(DESCRITOR2 *)malloc(sizeof(DESCRITOR2));
   if (!*pf)
   {
      printf ("\nERRO! Memoria insuficiente!\n");
      exit (1);
   }
   (*pf)->INICIO=(*pf)->FIM=NULL;
   (*pf)->ne = 0;
}

void ins2 (FILA_ENC2 f, int v)
{
   NODO2 *novo;
   novo = (NODO2 *) malloc (sizeof(NODO2));
   if (!novo) {
      printf ("\nERRO! Memoria insuficiente!\n");
      exit (1);
   }
   novo->inf = v;
   novo->next = NULL;
   if (eh_vazia2(f))
      f->INICIO=novo;
   else
      f->FIM->next=novo;
   f->FIM=novo;
   f->ne++;
}

void ret2 (FILA_ENC2 f)
{
   if (!f->INICIO)
   {
      printf ("\nERRO! Retirada em fila vazia!\n");
      exit (3);
   }
   else
   {
      NODO2 *aux=f->INICIO;
      f->INICIO=f->INICIO->next;
      if (!f->INICIO)
         f->FIM=NULL;
      free (aux);
      f->ne--;
   }
}

int cons_ret2 (FILA_ENC2 f)
{
   if (!f->INICIO)
   {
      printf ("\nERRO! Consulta e retirada em fila vazia!\n");
      exit (4);
   }
   else
   {
      int v=f->INICIO->inf;
      NODO2 *aux=f->INICIO;
      f->INICIO=f->INICIO->next;
      if (!f->INICIO)
         f->FIM=NULL;
      free (aux);
      f->ne--;
      return (v);
   }
}

int tam2 (FILA_ENC2 f)
{
   return (f->ne);
}

// Pilhas Alocacao Sequencial

typedef struct
{
   int TOPO;
   int VAL[MAX];
}PILHA_SEQ;
void cria_pilha (PILHA_SEQ *);
int eh_vazia_pilha (PILHA_SEQ *);
void push (PILHA_SEQ *, int);
int top (PILHA_SEQ *);
void pop (PILHA_SEQ *);
int top_pop (PILHA_SEQ *);

void cria_pilha (PILHA_SEQ *p)
{
   p->TOPO = -1;
}

int eh_vazia_pilha (PILHA_SEQ *p)
{
   return (p->TOPO == -1);
}

void push (PILHA_SEQ *p, int v)
{
   if (p->TOPO == MAX-1)
   {
      printf ("\nERRO! Estouro na pilha.\n");
      exit (1);
   }
   p->VAL[++(p->TOPO)]=v;
}

int top (PILHA_SEQ *p)
{
   if (eh_vazia_pilha(p))
   {
      printf ("\nERRO! Consulta na pilha vazia.\n");
      exit (2);
   }
   else
      return (p->VAL[p->TOPO]);
}

void pop (PILHA_SEQ *p)
{
   if (eh_vazia_pilha(p))
   {
      printf ("\nERRO! Retirada na pilha vazia.\n");
      exit (3);
   }
   else
      p->TOPO--;
}

int top_pop (PILHA_SEQ *p)
{
   if (eh_vazia_pilha(p))
   {
      printf ("\nERRO! Consulta e retirada na pilha vazia.\n");
      exit (4);
   }
   else
      return (p->VAL[p->TOPO--]);
}

void inverte_fila (FILA_SEQ *f)
{
   PILHA_SEQ p;
   cria_pilha(&p);
   while (!eh_vazia(f))
      push(&p,cons_ret(f));
   while (!eh_vazia_pilha(&p))
      ins(f, top_pop(&p));
}

//Pilhas Alocacao Encadeada

typedef struct nodo_pilha_enc
{
   int inf;
   struct nodo_pilha_enc * next;
}NODE_PILHA_ENC;
typedef NODE_PILHA_ENC * PILHA_ENC_T;
void create (PILHA_ENC_T *);
int is_empty (PILHA_ENC_T);
void push_enc (PILHA_ENC_T *, int);
int top_enc (PILHA_ENC_T);
void pop_enc (PILHA_ENC_T *);
int top_pop_enc (PILHA_ENC_T *);
void destroy_pilha_enc (PILHA_ENC_T);

void create (PILHA_ENC_T *pp)
{
   *pp=NULL;
}

int is_empty (PILHA_ENC_T p)
{
   return (!p);
}

void push_enc (PILHA_ENC_T *pp, int v)
{
   NODE_PILHA_ENC *new;
   new = (NODE_PILHA_ENC *) malloc (sizeof(NODE_PILHA_ENC));
   if (!new)
   {
      printf ("\nERRO! Memoria insuficiente!\n");
      exit (1);
   }
   new->inf = v;
   new->next = *pp;
   *pp=new;
}

int top_enc (PILHA_ENC_T p)
{
   if (!p)
   {
      printf ("\nERRO! Consulta em pilha vazia!\n");
      exit (2);
   }
   return (p->inf);
}

void pop_enc (PILHA_ENC_T *pp)
{
   if (!(*pp))
   {
      printf ("\nERRO! Retirada em pilha vazia!\n");
      exit (3);
   }
   else
   {
      NODE_PILHA_ENC *aux=*pp;
      *pp=(*pp)->next;
      free (aux);
   }
}

int top_pop_enc (PILHA_ENC_T *pp)
{
   if (!(*pp))
   {
      printf ("\nERRO! Consulta e retirada em pilha vazia!\n");
      exit (4);
   }
   else
   {
      int v=(*pp)->inf;
      NODE_PILHA_ENC *aux=*pp;
      *pp=(*pp)->next;
      free (aux);
      return (v);
   }
}

void destroy_pilha_enc (PILHA_ENC_T l)
{
   PILHA_ENC_T aux;
   while (l)
   {
      aux = l;
      l = l->next;
      free(aux);
   }
}


// Árvores – Caracterização Árvores Binárias
//Árvores Binárias Armazenamento Estático

typedef struct {
    int info;
    int left;
    int right;
    int father;
 } NODE_ARV_SEQ;
 typedef struct{
    int root;
    int nodeFree;
    NODE_ARV_SEQ nodes[NUMNODES];/*#define NUMNODES 100*/
 }ARV_BIN_SEQ;
 void maketree(ARV_BIN_SEQ *, int);
 void setleft(ARV_BIN_SEQ *, int, int);
 void setright(ARV_BIN_SEQ *, int, int);
 int info_arv_seq(ARV_BIN_SEQ *, int);
 int left_arv_seq(ARV_BIN_SEQ *, int);
 int right_arv_seq(ARV_BIN_SEQ *, int);
 int father_arv_seq(ARV_BIN_SEQ *, int);
 int brother_arv_seq(ARV_BIN_SEQ *, int);
 int isleft_arv_seq(ARV_BIN_SEQ *, int);
 int isright_arv_seq(ARV_BIN_SEQ *, int);


 int getNode(ARV_BIN_SEQ *t)
{
   if (t->nodeFree != -1)
   {
      int i = t->nodeFree;
      t->nodeFree = t->nodes[t->nodeFree].left;
      return i;
   }
   else
      return -1;
}
void freeNode(ARV_BIN_SEQ *t, int node)
{
   t->nodes[node].left = t->nodeFree;
}
   
void setleft_arv_seq(ARV_BIN_SEQ *t, int p, int x)
{
   int ind = getNode(t);
   if (ind != -1) {
      t->nodes[p].left = ind;
      t->nodes[ind].info = x;
      t->nodes[ind].left = -1;
      t->nodes[ind].right = -1;
      t->nodes[ind].father = p;
   } else {
      printf("Impossivel inserir filho a esquerda!");
      exit(2);
   }
}

void setright_arv_seq(ARV_BIN_SEQ *t, int p, int x)
{
   int ind = getNode(t);
   if (ind != -1) {

      t->nodes[ind].info = x;
      t->nodes[ind].left = -1;
      t->nodes[ind].right = -1;
      t->nodes[ind].father = p;
   } else {
      printf("Impossivel inserir filho a direita!");
      exit(2);
   }
}

int info_arv_seq(ARV_BIN_SEQ *t, int p)
{
   return t->nodes[p].info;
}

int left_arv_seq(ARV_BIN_SEQ *t, int p)
{
   return t->nodes[p].left;
}

int right_arv_seq(ARV_BIN_SEQ *t, int p)
{
   return t->nodes[p].right;
}

int father_arv_seq(ARV_BIN_SEQ *t, int p)
{
   return t->nodes[p].father;
}

int brother_arv_seq(ARV_BIN_SEQ *t, int p) {
    if (father_arv_seq(t, p) != -1) /*Se nao for a raiz*/
       if (isleft_arv_seq(t, p))
          return right_arv_seq(t,father_arv_seq(t, p));
       else
          return t->nodes[t->nodes[p].father].left;
    return -1;
 }

 int isleft_arv_seq(ARV_BIN_SEQ *t, int p) {
    int q = father_arv_seq(t, p);
    if (q == -1) /*Se for a raiz*/
        return 0;
 
    if (left_arv_seq(t,q) == p)
       return (1);
    return (0);
 }

 int isright_arv_seq(ARV_BIN_SEQ *t, int p) {
    if (father_arv_seq(t, p) != -1)
       return (!isleft_arv_seq(t,p));
    return (0);
 }

 //Árvore Binária Alocação Encadeada Exemplos de Aplicação

 typedef struct node_arv_enc
{
   int info;
   struct node_arv_enc *left;
   struct node_arv_enc *right;
   struct node_arv_enc *father;
} NODE_ARV_ENC;
typedef NODE_ARV_ENC * ARV_BIN_ENC;
void maketree_enc(ARV_BIN_ENC *, int);
void setleft_enc(ARV_BIN_ENC, int);
void setright_enc(ARV_BIN_ENC, int);
int info_arv_enc(ARV_BIN_ENC);
ARV_BIN_ENC left_arv_enc(ARV_BIN_ENC);
ARV_BIN_ENC right_arv_enc(ARV_BIN_ENC);
ARV_BIN_ENC father_arv_enc(ARV_BIN_ENC);
ARV_BIN_ENC brother_arv_enc(ARV_BIN_ENC);
int isleft_arv_enc(ARV_BIN_ENC);
int isright_arv_enc(ARV_BIN_ENC);

void maketree_enc(ARV_BIN_ENC *t, int x)
{
   *t = (ARV_BIN_ENC) malloc (sizeof (NODE_ARV_ENC));
   if (!(*t))
   {
      printf("Erro! Nao existe memoria disponivel!");
      exit (1);
   }
   (*t)->info = x;
   (*t)->left = NULL;
   (*t)->right = NULL;
   (*t)->father = NULL;
}

void setleft_enc(ARV_BIN_ENC t, int x)
{
   t->left = (ARV_BIN_ENC) malloc (sizeof(NODE_ARV_ENC));
   if (!(t->left))
   {
      printf("Erro! Nao existe memoria disponivel!");
      exit (1);
   }
   t->left->info = x;
   t->left->left = NULL;
   t->left->right = NULL;
   t->left->father = t;
}

void setright_enc(ARV_BIN_ENC t, int x)
{
   t->right = (ARV_BIN_ENC) malloc (sizeof(NODE_ARV_ENC));
   if (!(t->right))
   {
      printf("Erro! Nao existe memoria disponivel!");
      exit (1);
   }
   t->right->info = x;
   t->right->left = NULL;
   t->right->right = NULL;
   t->right->father = t;
}

int info_arv_enc(ARV_BIN_ENC t)
{
   return t->info;
}

ARV_BIN_ENC left_arv_enc(ARV_BIN_ENC t)
{
   return t->left;
}

ARV_BIN_ENC right_arv_enc(ARV_BIN_ENC t)
{
   return t->right;
}

ARV_BIN_ENC father_arv_enc(ARV_BIN_ENC t)
{
   return t->father;
}

ARV_BIN_ENC brother_arv_enc(ARV_BIN_ENC t)
{
   if (t->father)
      if (isleft_arv_enc(t))
         return (t->father)->right;
      else
         return (t->father)->left;
   return NULL;
}

//Árvore Binária Alocação Encadeadas

int isleft_arv_enc(ARV_BIN_ENC t)
{
   NODE_ARV_ENC *q = t->father;
   if (!q)
      return (0);
   if (q->left == t)
      return (1);
   return (0);
}

int isright_arv_enc(ARV_BIN_ENC t)
{
   if (t->father)
      return (!isleft_arv_enc(t));
   return (0);
}

//Árvore Binária de Busca Definição, Percurso Inserção e Remoção de um Nó

//Árvore Binária de Busca – Modos de Travessia percurso em largura

void percursoEmLargura(ARV_BIN_ENC arvore)
{
   FILA_ENC2 fila; /*FILA_ENC2 armazena ARV_BIN_ENCs*/
   cria_fila2(&fila);
   if (arvore)
   {
      //ins_fila (fila, arvore); // suprimido
      while (!eh_vazia2(fila))
      {
         //ARV_BIN_ENC no_atual = cons_fila(fila); // suprimido
         //printf ("%d ", info_arv_enc(no_atual)); /*Visita ao no*/
         //if (left_arv_enc(no_atual))
            //ins_fila (fila, left_arv_enc(no_atual));
         //if (right_arv_enc(no_atual))
            //ins_fila (fila, right_arv_enc(no_atual));
         //ret_fila(fila); // suprimido
      }
   }
}

void percursoPreOrdem(ARV_BIN_ENC arvore)
{
   if (arvore)
   {
      printf("%d ", info_arv_enc(arvore));   /*V*/
      percursoPreOrdem(left_arv_enc(arvore));   /*L*/
      percursoPreOrdem(right_arv_enc(arvore));   /*R*/
   }
}

void percursoInOrdem(ARV_BIN_ENC arvore)
{
   if (arvore)
   {
      percursoInOrdem(left_arv_enc(arvore));   /*L*/
      printf("%d ", info_arv_enc(arvore));   /*V*/
      percursoInOrdem(right_arv_enc(arvore));   /*R*/
   }
}

void percursoPosOrdem(ARV_BIN_ENC arvore)
{
   if (arvore)
   {
      percursoPosOrdem(left_arv_enc(arvore));   /*L*/
      percursoPosOrdem(right_arv_enc(arvore));   /*R*/
      printf("%d ", info_arv_enc(arvore));   /*V*/
   }
}

//Árvore Binária de Busca
typedef ARV_BIN_ENC ARV_BIN_BUSCA;
void ins_ele (ARV_BIN_BUSCA *arv, int v) {
    if (!(*arv))
       maketree_enc(arv, v);
    else{
       ARV_BIN_BUSCA father=*arv;
       do {
          if(v<father->info){
             if(father->left)
                father= father->left;
             else{
                setleft_enc(father, v);
                break;
             }
          }
          else{
             if(father->right)
                father= father->right;
             else{
                setright_enc(father, v);
                break;
             }
          }
       }while(1);
    }
 }

 void remocaoPorFusao(ARV_BIN_BUSCA *arvore) {
    if (*arvore) {
       ARV_BIN_BUSCA tmp = *arvore;
       if (!((*arvore)->right)) {
          if ((*arvore)->left) (*arvore)->left->father = (*arvore)->father;
          *arvore = (*arvore)->left;
       } else
       if ((*arvore)->left == NULL) {
          (*arvore)->right->father = (*arvore)->father;
          *arvore = (*arvore)->right;
       } else {
          tmp = (*arvore)->left;
          while (tmp->right)
             tmp = tmp->right;
          tmp->right = (*arvore)->right;
          tmp->right->father= tmp;
          tmp = *arvore;
          *arvore = (*arvore)->left;
          (*arvore)->father = tmp->father;
       }
       free (tmp);
    }
 }

 void remocaoPorCopia(ARV_BIN_BUSCA *arvore) {
    if (*arvore) {
       ARV_BIN_BUSCA tmp = *arvore;
       if (!((*arvore)->right)){
          if ((*arvore)->left) (*arvore)->left->father = (*arvore)->father;
          *arvore = (*arvore)->left;
       } else
       if ((*arvore)->left == NULL){
          (*arvore)->right->father = (*arvore)->father;
          *arvore = (*arvore)->right;
       } else {
          tmp = (*arvore)->right;
          while (tmp->left!=NULL)
             tmp = tmp->left;
          (*arvore)->info = tmp->info;
          if (tmp->father==*arvore)
             tmp->father->right = tmp->right;
          else
             tmp->father->left = tmp->right;
          if (tmp->right) tmp->right->father = tmp->father;
       }
       free (tmp);
    }
 }

 //Árvore Balanceada Árvore AVL
 typedef struct NoAVL {
    int info;
    struct NoAVL *esq;
    struct NoAVL *dir;
    int alte;
    int altd;
} NoAVL;
typedef NoAVL * ArvoreAVL;


 void rotacao_direita(ArvoreAVL *arvore)
{
   ArvoreAVL aux1, aux2;
   aux1 = (*arvore)->esq;
   aux2 = aux1->dir;
   (*arvore)->esq = aux2;
   aux1->dir = (*arvore);
   if ((*arvore)->esq == NULL)
      (*arvore)->alte = 0;
   else
      if ((*arvore)->esq->alte > (*arvore)->esq->altd)
         (*arvore)->alte = (*arvore)->esq->alte+1;
      else
         (*arvore)->alte = (*arvore)->esq->altd+1;
   if (aux1->dir->alte > aux1->dir->altd)
      aux1->altd = aux1->dir->alte + 1;
   else
      aux1->altd = aux1->dir->altd + 1;
   *arvore = aux1;
}

 void rotacao_esquerda(ArvoreAVL *arvore)
{
   ArvoreAVL aux1, aux2;
   aux1 = (*arvore)->dir;
   aux2 = aux1->esq;
   (*arvore)->dir = aux2;
   aux1->esq = (*arvore);
   if ((*arvore)->dir == NULL)
      (*arvore)->altd = 0;
   else
      if ((*arvore)->dir->alte > (*arvore)->dir->altd)
         (*arvore)->altd = (*arvore)->dir->alte+1;
      else
         (*arvore)->altd = (*arvore)->dir->altd+1;
   if (aux1->esq->alte > aux1->esq->altd)
      aux1->alte = aux1->esq->alte + 1;
   else
      aux1->alte = aux1->esq->altd + 1;
   *arvore = aux1;
}

int balanceamento(ArvoreAVL *arvore) {
    int FBpai, FBfilho;
    FBpai = (*arvore)->altd - (*arvore)->alte;
    if (FBpai == 2) {
       FBfilho = (*arvore)->dir->altd - (*arvore)->dir->alte;
       if (FBfilho >= 0)
          rotacao_esquerda(arvore);
       else {
          rotacao_direita(&((*arvore)->dir));
          rotacao_esquerda(arvore);
       }
    } else
    if (FBpai == -2) {
       FBfilho = (*arvore)->esq->altd - (*arvore)->esq->alte;
       if (FBfilho <= 0)
          rotacao_direita(arvore);
       else {
          rotacao_esquerda(&((*arvore)->esq));
          rotacao_direita(arvore);
       }
    }
    return 0;
 }