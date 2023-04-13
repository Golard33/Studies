;a.	Définir la fonction mange1 qui s’applique à une population et supprime le premier individu qui peut être supprimé en appliquant les règles 3 et 4 ci-dessus. Le résultat retourné est la population modifiée.
;Si aucune suppression n’est possible, la fonction retourne une liste vide.


(define (mange1 pop)
      (cond 
        ((null? (cddr pop)) '())
        ((and (not (equal? (car pop) (cadr pop)))
               (equal? (car pop) (caddr pop))) 
               (cons (car pop) (cddr pop)))
        (else (if (null? (mange1 (cdr pop)))
                  '()
                  (cons (car pop) (mange1(cdr pop)))))))
