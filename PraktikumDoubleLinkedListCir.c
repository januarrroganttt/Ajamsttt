#include <stdio.h>
#include <stdlib.h>

struct DoubleLinkedListCircular {
    struct DoubleLinkedListCircular *prev;
    int data;
    struct DoubleLinkedListCircular *next;
};

typedef struct DoubleLinkedListCircular *node;

node createNode(int data) {
    node new_node = (node)malloc(sizeof(struct DoubleLinkedListCircular));
    new_node->data = data;
    new_node->next = new_node->prev = new_node; 
    return new_node;
}

node insertLast(node head, node new_node) {
    if (head == NULL) {
        head = new_node;
    } else {
        // Inisialisasi last untuk menunjuk pada node terakhir di list.
        node last = head->prev;
        // next dari new_node menunjuk ke head.
        new_node->next = head;
        // prev dari new_node menunjuk ke node terakhir.
        new_node->prev = last;
        // prev dari head menunjuk ke new_node.
        head->prev = new_node;
        // next dari last menunjuk ke new_node.
        last->next = new_node;
    }
    return head;
}

node sortingAscending(node head, node new_node) {
    // Jika list kosong, new_node menjadi head.
    if (head == NULL) {
        head = new_node;
    } else if (head->data >= new_node->data) {
        // Jika data head lebih besar atau sama dengan data new_node, new_node menjadi head.
        node last = head->prev;
        new_node->next = head;
        new_node->prev = last;
        last->next = new_node;
        head->prev = new_node;
        head = new_node;
    } else {
        // Inisialisasi curr untuk menunjuk pada head.
        node curr = head;
        // Loop sampai kita menemukan posisi yang benar untuk new_node.
        while (curr->next != head && curr->next->data < new_node->data) {
            curr = curr->next;
        }
        // Sisipkan new_node setelah curr.
        new_node->next = curr->next;
        new_node->prev = curr;
        curr->next->prev = new_node;
        curr->next = new_node;
    }
    return head;
}

node ascendingData(node head) {
    // Inisialisasi new_head untuk menyimpan list yang sudah diurutkan.
    node new_head = NULL;
    // Inisialisasi curr untuk menunjuk pada head.
    node curr = head, next;
    // Loop sampai kita memproses semua node dalam list.
    do {
        // Simpan node berikutnya.
        next = curr->next;
        // Putuskan hubungan curr dari list.
        curr->next = curr->prev = curr;
        // Sisipkan curr ke dalam list yang baru diurutkan.
        new_head = sortingAscending(new_head, curr);
        // Pindah ke node berikutnya.
        curr = next;
    } while (curr != head);
    // Mengembalikan head dari list yang sudah diurutkan.
    return new_head;
}

void viewData(node head) {
    // Jika list kosong, kembalikan.
    if (head == NULL) {
        printf("List kosong\n");
        return;
    }
    // Inisialisasi curr untuk menunjuk pada head.
    node curr = head;
    
    do {
        // Tampilkan alamat memori dan data dalam node saat ini.
        printf("(%p, %d) ", curr, curr->data);
        // Pindah ke node berikutnya.
        curr = curr->next;
    } while (curr != head);
    // Cetak baris baru di akhir.
    printf("\n");
}

int main() {

    node head = NULL;
    int N;

    printf("Masukkan jumlah elemen: ");
    scanf("%d", &N);

    if (N < 1 || N > 10) {
        printf("Jumlah elemen tidak valid. Harus antara 1 dan 10.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        int data;
        printf("Masukkan data %d: ", i + 1);
        scanf("%d", &data);

        if (data < 1 || data > 10) {
            printf("Data tidak valid. Harus antara 1 dan 10.\n");
            return 1;
        }
        // Perbarui head dengan memanggil insertLast().
        head = insertLast(head, createNode(data));
    }

    printf("List sebelum diurutkan: ");
    viewData(head);

    head = ascendingData(head);

    printf("List setelah diurutkan: ");
    viewData(head);

    return 0;
}