//Очередь(первый вошел - первый вышел)
#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node {
    int a;
    struct Node* next;
} tNode;

///////////////////////////////////////////////////////////////////////////////

//----------------------/// удаление ///
tNode* delete_list(tNode* head, int x);
//----------------------/// добавление ///
tNode* Plus(tNode* str, int a);

///////////////////////////////////////////////////////////////////////////////

int main(void) {
    tNode* p = NULL;
   printf("1-add 2-delete 3-display 4-exit\n");
    int qwe;
    int k=0;
    scanf("%d", &qwe);
    while (qwe != 4) {
        if (qwe == 1) {
            k++;
            /// добавление и инициализация(если первый корень) ///
            int a;
            printf("Enter the number:");
            scanf("%d", &a);
            p = Plus(p, a);
    
        }
        else if (qwe == 2) {
            /// удаление ///
            int x = k;
            delete_list(p, x);
        }
        else if (qwe == 3) {
            /// печать ///
            while (p != NULL) {
                printf("%d \n", p->a);
                p = p->next;
            }
        }
        printf("1-add 2-delete 3-display 4-exit\n");
        scanf("%d", &qwe);
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////

//----------------------/// удаление ///


tNode* delete_list(tNode* head, int x) {
    if (x == 1)
        head = head->next;
    else {
        x--;
        head->next = delete_list(head->next, x);
    }
    return head;
}
//----------------------/// добавление ///
tNode* Plus(tNode* head, int a) {

    tNode* head1 = (tNode*)malloc(sizeof(tNode));
    head1->a = a;
    head1->next = head;
    return head1;

}
