

(define (valeur paire-pointe)
  (cond ((null? paire-pointe) #f)
        ((equal? 'roi (car paire-pointe)) (car paire-pointe))
        ((equal? 'dame (car paire-pointe)) (car paire-pointe))
        ((equal? 'as (car paire-pointe)) (car paire-pointe))
        ((equal? 'valet (car paire-pointe)) (car paire-pointe))
        ((equal? '10 (car paire-pointe)) (car paire-pointe))
        ((equal? '9 (car paire-pointe)) (car paire-pointe))
        ((equal? '8 (car paire-pointe)) (car paire-pointe))
        ((equal? '7 (car paire-pointe)) (car paire-pointe))
        ((equal? '6 (car paire-pointe)) (car paire-pointe))
        ((equal? '5 (car paire-pointe)) (car paire-pointe))
        ((equal? '4 (car paire-pointe)) (car paire-pointe))
        ((equal? '3 (car paire-pointe)) (car paire-pointe))
        ((equal? '2 (car paire-pointe)) (car paire-pointe))

        ))

(define (couleur paire-pointe)
  (cond ((null? paire-pointe) #f)
        ((equal? 'carreau (cdr paire-pointe)) (cdr paire-pointe))
        ((equal? 'coeur (cdr paire-pointe)) (cdr paire-pointe))
        ((equal? 'pique (cdr paire-pointe)) (cdr paire-pointe))
        ((equal? 'trefle (cdr paire-pointe)) (cdr paire-pointe))

        ))

(define (carte? paire-pointe)
  (cond ((null? paire-pointe) #f)
        ((equal? (valeur paire-pointe) (car paire-pointe))#t)
        ((equal? (couleur paire-pointe) (cdr paire-pointe))#t)
        (else (#f))

        ))

        
(define liste1 '(a . carreau))


(valeur  liste1)
(couleur liste1)
(carte? liste1)
