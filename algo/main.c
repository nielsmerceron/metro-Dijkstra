#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int main()
{
    LNoeud n;
    Graphel g1 = nouveau_graph(100);
    while (connexe(g1))
    {
        initT1(n, g1);
        initT2(n, g1);
        initT3(n, g1);
    }

    affgraph(g1);

    liberedelivre(g1);

    return (0);
}