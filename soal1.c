/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : Structures and Dynamic Array
 *   Hari dan Tanggal    : 6 Mei 2026
 *   Nama (NIM)          : Muhammad Adli Syauqi (13224082)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program menerima antrian rumah sakit dan mengolahnya menggunakan queue
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Pasien {
    char id[20];
    int waktu;
} Pasien;

typedef struct Node {
    Pasien data;
    struct Node* next;
} Node;

// myQueue structure
typedef struct myQueue {
    int currSize;
    Node* front;
    Node* rear;
} myQueue;

// Create a new node
Node* newNode(Pasien data) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->data.id, data.id);
    node->data.waktu = data.waktu;
    node->next = NULL;
    return node;
}

// Create an empty queue
myQueue* createQueue() {
    myQueue* q = (myQueue*)malloc(sizeof(myQueue));
    q->front = q->rear = NULL;
    q->currSize = 0;
    return q;
}

// Check if the queue is empty
int isEmpty(myQueue* q) {
    return q->front == NULL;
}

// Enqueue operation
void enqueue(myQueue* q, Pasien data) {
    Node* node = newNode(data);
    if (isEmpty(q)) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
    
    q->currSize++;
}

// Dequeue operation
Pasien dequeue(myQueue* q) {
    // if (isEmpty(q)) {
    //     printf("Queue Underflow\n");
    //     return -1;
    // }
    
    Node* temp = q->front;
    Pasien removedData;
    strcpy(removedData.id, temp->data.id);
    removedData.waktu = temp->data.waktu;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    
    q->currSize--;
    return removedData;
}

// // Get front element
// int getFront(myQueue* q) {
//     if (isEmpty(q)) {
//         printf("Queue is empty\n");
//         return -1;
//     }
//     return q->front->data;
// }

// // Get queue size
// int size(myQueue* q) {
//     return q->currSize;
// }

int main() {
    myQueue* q = createQueue();

    //testing

    // Pasien data1;

    // strcpy(data1.id, "tes");
    // data1.waktu = 5;

    // enqueue(q, data1);

    // Pasien removed = dequeue(q);

    // printf("Dequeue: %d %s\n", removed.waktu, removed.id);

    // main program:
    int input;
    scanf("%d", &input);

    Pasien temp;

    for(int i = 0; i < input; i++){
        scanf("%s %d", &temp.id, &temp.waktu);
        enqueue(q, temp);
        // printf("%s", q->rear->data.id);
    }

    int sum = 0;
    int waktu_tunggu = 0;
    temp.waktu = 0;

    // a01 tunggu = 0 jam (index 0)
    // a02 tunggu = 3 jam (index 1)
    // a03 tunggu = 3 + 5 jam
    // a04 tunggu = 3+5+2 jam

    // sum = 3 + 8 + 10 = 21 jam

    printf("ORDER");
    for(int i = 0; i < input; i++){
        waktu_tunggu += temp.waktu;
        sum += waktu_tunggu;
        temp = dequeue(q);
        printf(" %s", temp.id);
        
    }

    printf("\n");
    printf("WAIT %d", sum);


        


    return 0;
}
