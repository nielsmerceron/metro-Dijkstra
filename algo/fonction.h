int alea2(int inf, int sup, int rando);

/* les trois structs que je définis vont servir a faire le graphe
    via des listes chaînées
    spoiler: c'est un joli bordel */

//def d'un noeud
typedef struct ListeNoeud
{
    int value;
    int poids;
    struct ListeNoeud *suivant;
} ListeNoeud, *LNoeud;

//liste d'adjencement des éléments
typedef struct Adjalistelem
{
    ListeNoeud *debut;
} Adjalistelem, *Adjale;

typedef struct Grapheelem
{
    int nb_sommet;
    Adjale tab_voisin;
} Grapheelem, *Graphel;

/*fonction pour le graphe*/

Graphel nouveau_graph(int nbsommet);
int empty_grahe(Graphel g);
LNoeud ajoutnoeud(int y, int poids);
void liberedelivre(Graphel g);

void ajouarr(Graphel g, int source, int desti, int poids);
void affgraph(Graphel g);

/*Initialisation des noeud dans le graphe */
void initT1(LNoeud n, Graphel g);
void initT2(LNoeud n, Graphel g);
void initT3(LNoeud n, Graphel g);

void initmarquage(int *marquage);
int verifco(int *marquage, int nb_sommet);
void parcourp(Graphel g, int indice, int *marck);
int connexe(Graphel g1);

typedef struct dijkstra
{
    int *chemin;
    int *conca; // conca[3]= [0]=début [1]=poid [2]=fin

} dijkstra, *dijk;

void initm(int *marquage,dijk routage);

dijk init(int debut,int fin);
dijk getdijkstra(Graphel g1,dijk routage,int debut);
void parcourd(Graphel g, int indice, int *marck,dijk routage);


   