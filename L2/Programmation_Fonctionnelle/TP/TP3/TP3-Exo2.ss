(#%require eopl)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Exercice 2 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  


;;;;;;;;;;;;;;;;;;;;;;;;;; Exo 2.1 ;;;;;;;;;;;;;;;;;;;;;;  

(define l1 '(jus pomme abricot fraise));; jules
(define l2 '(pomme banane citron)) ;; julie 



(define (produit-Julie? p liste)
  (cond 
       ((null? liste) #f)
       ((equal? (car liste) p) #t)
       (else (produit-Julie? p (cdr liste)))
  )
)

(trace produit-Julie?)

(produit-Julie? 'pomme l2)










