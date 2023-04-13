(define (comptebon nb liste)
  (cond ((null? liste) #f)
        ((equal? nb (car liste)) #t)
        
        (else (compte produit (cdr liste)))))





(define comptebon '(1 1 3 5 7 10 12 15))

(comptebon 21 produits-Julie)
