(#%require eopl)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Exercice 1 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;; Exo 1.1 ;;;;;;;;;;;;;;;;;;;;;;


(define (somme liste)
  (if (null? liste) 0
      (+ (car liste) (somme (cdr liste)))
  )
)




(define (moyenne liste) 
  
  (if (not (null? liste))
      (/ (somme liste) (length liste))
      0
  )
  
)

;;(trace moyenne)

;;(moyenne '(15 13 16 20))


;;;;;;;;;;;;;;;;;;;;;;;;;; Exo 1.2 ;;;;;;;;;;;;;;;;;;;;;;

(define l '(5 10 15 20 20))


(define (notes-aux liste moy)
  ( if (null? liste) 
       0 
       (if (>= (car liste) moy) 
           (+ 1 (notes-aux (cdr liste) moy))
           (notes-aux (cdr liste) moy)
       )
   )
)

(define (notes liste)
  (notes-aux l (moyenne l))
)
  
(moyenne l)

(define (taux-reussite liste)
  (if (null? liste ) 0
  (/ (* (notes liste) 100) (length liste))) 
)

(trace taux-reussite)

(taux-reussite l)
  
  

