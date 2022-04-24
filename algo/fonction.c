#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alea2(int inf, int sup, int rando)
{
   srand(rando);

   int irandom;
   irandom = inf + (rand() % (sup - inf + 1));

   return (irandom);
}

/* fonction pour la création du graphe */

Graphel nouveau_graph(int nbsommet)
{

   int i;

   Grapheelem *element;

   element = malloc(sizeof(*element));

   if (element == NULL)
   {
      fprintf(stderr, "mauvaise allocation du graph");
      exit(EXIT_FAILURE);
   }

   element->nb_sommet = nbsommet;

   element->tab_voisin = malloc(nbsommet * sizeof(Adjalistelem));

   if (element->tab_voisin == NULL)
   {
      fprintf(stderr, "mauvaise allocation du tab_voisin");
      exit(EXIT_FAILURE);
   }

   for (i = 1; i < element->nb_sommet + 1; i++)
   {
      element->tab_voisin[i - 1].debut = NULL;
   }
   return (element);
}

int vide(Graphel g)
{
   if (g == NULL)
   {
      return (1); // le graphe est vide
   }
   return (0); //le graphe n'est pas vide
}

LNoeud ajoutnoeud(int y, int poids)
{
   LNoeud n;
   n = malloc(sizeof(ListeNoeud));

   if (n == NULL)
   {
      fprintf(stderr, "mauvaise crea de noeud");
      exit(EXIT_FAILURE);
   }
   n->value = y;
   n->poids = poids;
   n->suivant = NULL;
   return (n);
}

void liberedelivre(Graphel g)
{
   if (vide(g))
   {
      printf("aucun graphe a effacer\n");
      return;
   }

   if (g->tab_voisin)
   {
      int i;
      for (i = 1; i < g->nb_sommet + 1; i++)
      {
         LNoeud n = g->tab_voisin[i - 1].debut;
         while (n != NULL)
         {
            LNoeud tmp;
            tmp = n;

            n = n->suivant;
            free(tmp);
         }
      }
      free(g->tab_voisin);
   }
   free(g);
}

void ajouarr(Graphel g, int source, int desti, int poids)
{
   /*on effectue ce if pour éviter que la source soit relié a elle même */
   if (source == desti)
   {
      return;
   }

   if (g->tab_voisin[source - 1].debut != NULL)
   {
      LNoeud tmp = g->tab_voisin[source - 1].debut;
      while (tmp != NULL)
      {
         if (tmp->value == desti)
         {
            return;
         }
         tmp = tmp->suivant;
      }
   }

   LNoeud n = ajoutnoeud(desti, poids);

   n->suivant = g->tab_voisin[source - 1].debut;
   g->tab_voisin[source - 1].debut = n;

   n = ajoutnoeud(source, poids);
   n->suivant = g->tab_voisin[desti - 1].debut;
   g->tab_voisin[desti - 1].debut = n;
}

void affgraph(Graphel g)
{
   int i;

   if (g == NULL)
   {
      printf("graph vide");
      return;
   }

   for (i = 1; i < g->nb_sommet + 1; i++)
   {
      LNoeud n = g->tab_voisin[i - 1].debut;
      printf("(%d)", i);

      while (n != NULL)
      {
         printf(" %d(%d),", n->value, n->poids);
         n = n->suivant;
      }
      printf("\n");
   }
}

void initT1(LNoeud n, Graphel g)
{
   int i;
   n = malloc(sizeof(LNoeud));
   for (i = 1; i < 11; i++)
   {
      n->value = i;

      int rand1 = alea2(1, 10, i);
      int rand2 = alea2(0, 3, i);

      if (rand2 != 3)
      {
         n->poids = alea2(5, 10, i);
         ajouarr(g, i, rand1, n->poids);
      }

      n->suivant = malloc(sizeof(LNoeud));
      n = n->suivant;
   }
}

void initT2(LNoeud n, Graphel g)
{
   int i;
   n = malloc(sizeof(LNoeud));

   for (i = 11; i < 31; i++)
   {
      n->value = i;

      int rand1 = alea2(1, 2, i);
      int rand2 = alea2(2, 3, i);

      int rand3 = alea2(1, 10, i);
      int rand4 = alea2(1, 10, i * i);

      int rand5 = alea2(11, 30, i);
      int rand6 = alea2(11, 30, i * i);
      int rand7 = alea2(11, 30, i * i * i);

      if (rand1 == 1)
      {
         n->poids = alea2(10, 20, i);

         ajouarr(g, i, rand3, n->poids);
      }
      else if (rand1 == 2)
      {

         n->poids = alea2(10, 20, i);
         ajouarr(g, i, rand3, n->poids);

         n->poids = alea2(10, 20, i * i);
         ajouarr(g, i, rand4, n->poids);
      }

      if (rand2 == 2)
      {

         n->poids = alea2(10, 20, i);
         ajouarr(g, i, rand5, n->poids);

         n->poids = alea2(10, 20, i * i);
         ajouarr(g, i, rand6, n->poids);
      }
      else if (rand2 == 3)
      {

         n->poids = alea2(10, 20, i);
         ajouarr(g, i, rand5, n->poids);

         n->poids = alea2(10, 20, i * i);
         ajouarr(g, i, rand6, n->poids);

         n->poids = alea2(10, 20, i * i * i);
         ajouarr(g, i, rand7, n->poids);
      }

      n->suivant = malloc(sizeof(LNoeud));
      n = n->suivant;
   }
}

void initT3(LNoeud n, Graphel g)
{
   int i;
   n = malloc(sizeof(LNoeud));
   for (i = 31; i < 101; i++)
   {
      n->value = i;

      int rand1 = alea2(11, 30, i);
      int rand2 = alea2(11, 30, i * i);
      int rand3 = alea2(31, 100, i);

      n->poids = alea2(15, 50, i);
      ajouarr(g, i, rand1, n->poids);

      n->poids = alea2(15, 50, i * i);
      ajouarr(g, i, rand2, n->poids);

      n->poids = alea2(15, 50, i * i * i);
      ajouarr(g, i, rand3, n->poids);

      n->suivant = malloc(sizeof(LNoeud));
      n = n->suivant;
   }
}

/*----------------------------------------------------------------------------------*/
/*partie sur la connexité du graphe */

void initmarquage(int *marquage)
{
   int i;
   if (marquage == NULL)
   {
      fprintf(stderr, "mauvaise allocation du marquage");
      return;
   }

   for (i = 0; i < 100; i++)
   {
      marquage[i] = 0;
   }
}

int verifco(int *marquage, int nb_sommet)
{
   int i;

   for (i = 0; i < nb_sommet - 1; i++)
   {
      if (marquage[i] == 0)
      {
         printf("graph nonconnexe\n");
         return (1);
      }
   }
   printf("graph connexe\n");
   return (0);
}

void parcourp(Graphel g, int indice, int *marck)
{
   LNoeud tmp = g->tab_voisin[indice - 1].debut;
   while (tmp != NULL)
   {
      if (marck[tmp->value - 1] == 0)
      {
         marck[tmp->value - 1] = 1;
         parcourp(g, tmp->value, marck);
      }
      tmp = tmp->suivant;
   }
}

int connexe(Graphel g1)
{
   int *marck;
   marck = malloc(sizeof(int) * 100);

   if (marck == NULL)
   {
      printf("mauvaiseallocation de marck");
      return (1);
   }
   initmarquage(marck);
   parcourp(g1, 1, marck);

   return (verifco(marck, g1->nb_sommet));

   free(marck);
}

/*----------------------------------------------------------------------------------*/
/*partie sur djikstra*/

void initm(int *marquage, dijk routage)
{
   int i;
   if (marquage == NULL)
   {
      fprintf(stderr, "mauvaise allocation du marquage");
      return;
   }

   for (i = 0; i < 100; i++)
   {
      marquage[i] = 0;
   }

   if (routage == NULL)
   {
      fprintf(stderr, "mauvaise allocation du routage");
      return;
   }

   for (i = 0; i < 100; i++)
   {
      routage[i].conca[1] = 0;
   }
}

dijk initdijk(int debut)
{
   dijk d;
   int i;
   d = malloc(sizeof(dijkstra) * 100);

   if (d == NULL)
   {
      fprintf(stderr, "mauvaise allocation");
      return ((d));
   }

   for (i = 0; i < 100; i++)

   {
      d[i].chemin = malloc(sizeof(int) * 80);

      if (d[i].chemin == NULL)
      {
         fprintf(stderr, "mauvaise allocation");
         return (d);
      }
      d[i].conca = malloc(sizeof(int) * 3);

      if (d == NULL)
      {
         fprintf(stderr, "mauvaise allocation");
         return (d);
      }

      d[i].chemin[0] = debut;
      d[i].conca[1] = 0;
   }
   return ((d));
}

dijk getddijkstra(Graphel g, dijk routage, int debut)
{
   LNoeud n = malloc(sizeof(LNoeud));
   dijk d = initdijk(debut);
   
   for (int i = 0; i < 100;i++
   {
      parcourd(g,i,,d);
   
   }
   return (routage);
}

void parcourd(Graphel g, int indice, int *marck, dijk routage)
{
   LNoeud tmp = g->tab_voisin[indice - 1].debut;
   while (tmp != NULL)
   {
      if (marck[tmp->value - 1] == 0)
      {
         marck[tmp->value - 1] = 1;
         parcourp(g, tmp->value, marck);
      }
      tmp->poids = routage[indice-1].conca[1];
      tmp = tmp->suivant;
   }
}
