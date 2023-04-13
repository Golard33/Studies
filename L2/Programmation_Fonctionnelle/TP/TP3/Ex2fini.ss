(define (produitDansListe? produit liste)
  (cond ((null? liste) #f)
        ((equal? produit (car liste)) #t)
        (else (produitDansListe? produit (cdr liste)))))

;-------------------------------------

(define (produits-double liste1 liste2)
  (cond ((null? liste1) '())
        ((produitDansListe? (car liste1) liste2) (cons (car liste1)(produits-double (cdr liste1) liste2)))
        (else (produits-double (cdr liste1) liste2))))

;-------------------------------------

(define (produits liste1 liste2)
  (cond ((null? liste1) liste2)
        ((null? liste2) liste1)
        ((produitDansListe? (car liste1) liste2) (produits (cdr liste1) liste2))
        (else (cons (car liste1) (produits (cdr liste1) liste2)))))

;----------------------------------
(define produits-Julie '(poulet))
(define produits-Jules '(poire jus banane pomme poisson poulet))

(produitDansListe? 'citron produits-Julie) ;; produit julie
(produits-double produits-Julie produits-Jules)
(produits produits-Julie produits-Jules)