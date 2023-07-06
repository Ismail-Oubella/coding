#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct pile {
    int sommet;
    int val[MAX_SIZE];
} pile;

typedef struct file {
    int tete;
    int queue;
    int val[MAX_SIZE];
} file;

void init_pile(pile *p) {
    p->sommet = -1;
}

void empiler(pile *p, int x) {
    p->sommet++;
    p->val[p->sommet] = x;
}

int depiler(pile *p) {
    int x = p->val[p->sommet];
    p->sommet--;
    return x;
}

void enfiler(file *f, int x) {
    f->val[f->queue] = x;
    f->queue++;
}

int defiler(file *f) {
    int x = f->val[f->tete];
    f->tete++;
    return x;
}

void tri_piles(pile *p1, pile *p2) {
    file f;
    f.tete = 0;
    f.queue = 0;

    // Transférer les entiers de P1 dans F
    while (p1->sommet >= 0) {
        int x = depiler(p1);
        enfiler(&f, x);
    }

    // Déplacer les entiers pairs de F dans P2 et les impairs dans P1
    while (f.tete < f.queue) {
        int x = defiler(&f);
        if (x % 2 == 0) {
            empiler(p2, x);
        } else {
            empiler(p1, x);
        }
    }
}

int main() {
    pile p1, p2;
    init_pile(&p1);
    init_pile(&p2);

    empiler(&p1, 1);
    empiler(&p1, 2);
    empiler(&p1, 3);
    empiler(&p1, 4);
    empiler(&p1, 5);
    empiler(&p1, 6);

    printf("Pile P1 avant le tri: ");
    for (int i = p1.sommet; i >= 0; i--) {
        printf("%d ", p1.val[i]);
    }
    printf("\n");

    tri_piles(&p1, &p2);

    printf("Pile P1 après le tri: ");
    for (int i = p1.sommet; i >= 0; i--) {
        printf("%d ", p1.val[i]);
    }
    printf("\n");

    printf("Pile P2 après le tri: ");
    for (int i = p2.sommet; i >= 0; i--) {
        printf("%d ", p2.val[i]);
    }
    printf("\n");

    return 0;
}
