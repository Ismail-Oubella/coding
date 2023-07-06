#include <stdio.h>
#include <stdlib.h>

typedef struct file {
    int tete;
    int queue;
    int val[100];
} file;

file *initialis() {
    file *f = (file*) malloc(sizeof(file));
    f->tete = 0;
    f->queue = 0;
    return f;
}

int defiler(file *f) {
    int x = f->val[f->tete];
    f->tete++;
    return x;
}

void emfiler(file *f, int x) {
    f->val[f->queue] = x;
    f->queue++;
}

void supprimer_superieur(file *f, int max) {
    int n = f->queue - f->tete;
    for (int i = 0; i < n; i++) {
        int x = defiler(f);
        if (x < max) {
            emfiler(f, x);
        }
    }
}

int main() {
    file *f = initialis();
    int val;
    int n;
    printf("donnez nombre d'elemeents en file ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("donnez val %d : ", i);
        scanf("%d", &val);
        emfiler(f, val);
    }

    printf("File avant la suppression: ");
    for (int i = f->tete; i < f->queue; i++) {
        printf("%d ", f->val[i]);
    }
    printf("\n");

    int max;
    printf("donner la max : ");
    scanf("%d", &max);
    supprimer_superieur(f, max);

    printf("File après la suppression: ");
    for (int i = f->tete; i < f->queue; i++) {
        printf("%d ", f->val[i]);
    }
    printf("\n");

    return 0;
}
