#ifndef TIREUSES_H
#define TIREUSES_H

// Constantes pour les types de bière
#define BEER_BLONDE 1
#define BEER_AMBREE 2

// Tailles de bière
#define BEER_QUARTER 250
#define BEER_HALF 500

// Structure pour les robinets de bière
typedef struct {
    char beer_name[32]; // Nom de la bière
    int beer_type;      // Type de bière (0: blonde, 1: ambrée)
    int beer_quantity;  // Quantité de bière restante dans le fût (en ml)
} tap_t;

// Déclarations de fonctions
void setup_shared_memory();
void setup_semaphore();
void initialize_taps();
int serve_beer(int beer_type, int beer_size);
void lock_semaphore();
void unlock_semaphore();
const char* get_beer_name(int beer_type);

#endif // TIREUSES_H
