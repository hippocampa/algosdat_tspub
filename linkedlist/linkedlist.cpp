#include <iostream>
#include <variant>


struct Node
{
    int value;
    Node* next_node;
};

struct LinkedList {
    Node* node = nullptr;

    void append(Node* n);
    void print();
    std::variant<Node*, int> get(int index, bool value_only);
    void insert(int at, Node* n);
};

/**
 * @brief Menambahkan node baru ke akhir linked list.
 *
 * Fungsi ini menambahkan node baru ke akhir linked list. Jika linked list
 * masih kosong (node == nullptr), node baru akan menjadi node pertama.
 * Jika tidak, fungsi ini akan mencari node terakhir dan menambahkan node
 * baru di akhir linked list.
 *
 * @param n Pointer ke node yang akan ditambahkan ke linked list.
 */
void LinkedList::append(Node* n) {
    if (node == nullptr)
    {
        node = n;
    }
    else {

        Node* nptr = node;
        while (nptr->next_node != nullptr)
        {
            nptr = nptr->next_node;
        }
        nptr->next_node = n;
    }
}

/**
 * @brief Mencetak semua nilai yang ada di dalam Linked List.
 *
 * Fungsi ini akan mencetak semua nilai yang ada di dalam Linked List
 * mulai dari node pertama hingga node terakhir. Jika Linked List kosong,
 * maka akan mencetak pesan bahwa tidak ada nilai yang ada di dalam Linked List.
 *
 * @note Fungsi ini menggunakan std::cerr untuk mencetak pesan kesalahan
 * jika Linked List kosong, dan std::cout untuk mencetak nilai-nilai dari node.
 */
void LinkedList::print() {
    if (node == nullptr) {
        std::cerr << "No values exist in the Linked List" << std::endl;
    }
    else {
        Node* pptr = node;
        while (pptr != nullptr) {
            std::cout << pptr->value << " -> ";
            pptr = pptr->next_node;
        }
        std::cout << '\n';
    }
}

/**
 * Mengambil node atau nilai dari linked list pada indeks tertentu.
 *
 * @param index Indeks dari node yang ingin diambil.
 * @param value_only Jika true, hanya mengembalikan nilai dari node; jika false, mengembalikan pointer ke node.
 * @return std::variant<Node*, int> Mengembalikan pointer ke node atau nilai dari node tergantung pada parameter value_only.
 * @throws std::runtime_error Jika linked list kosong.
 */
std::variant<Node*, int> LinkedList::get(int index, bool value_only) {
    if (node == nullptr) {
        std::cerr << "No values exist in the Linked List" << std::endl;
    }
    else {
        Node* pptr = node;
        for (size_t i = 0; i < index; i++)
        {
            pptr = pptr->next_node;
        }
        if (value_only) {
            return pptr->value;
        }
        else {
            return pptr;
        }
    }
}

/**
 * @brief Menyisipkan node baru pada indeks tertentu dalam linked list.
 *
 * Fungsi ini akan menyisipkan node baru pada posisi yang ditentukan oleh parameter `at`.
 * Node baru yang akan disisipkan diberikan melalui parameter `n`.
 *
 * @param at Indeks di mana node baru akan disisipkan. Indeks dimulai dari 0.
 * @param n Pointer ke node yang akan disisipkan.
 *
 * @example
 * Misalkan terdapat linked list sebagai berikut:
 * 1 -> 2 -> 3
 *
 * Kemudian `ll.insert(1, &Node{42, nullptr})`
 * akan menghasilkan:
 * 1 -> 42 -> 2 -> 3
 */
void LinkedList::insert(int at, Node* n) {
    /*
    TODO: insert node n at index n
    */

}


int main() {
    Node n1{ 1, nullptr };
    Node n2{ 2, nullptr };
    Node n3{ 3, nullptr };
    LinkedList ll;
    ll.append(&n1);
    ll.append(&n2);
    ll.append(&n3);
    ll.print();
    auto value = ll.get(2, true);
    if (std::holds_alternative<Node*>(value)) {
        Node* n = std::get<Node*>(value);
        std::cout << "Result: " << n << std::endl;
    }
    else {
        int result = std::get<int>(value);
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}
