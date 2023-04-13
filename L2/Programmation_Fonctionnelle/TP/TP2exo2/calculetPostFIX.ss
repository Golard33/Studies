(load "libpile.ss")

(define (calcpost)
  (begin
    (display "entrer une expression")
    (let ((saisie (read)))
      (cond
        ((number? saisie)
         (begin (empiler saisie)
                (newline)
                (calcpost)))
        ((or (equal? saisie '+)
             (equal? saisie '-)
             (equal? saisie '*)
             (equal? saisie '/))
         (begin (let ((op1 (sommet)))
                  (depiler)
                  (let ((op2 (sommet)))
                    (depiler)
                    (empiler ((eval saisie (interaction-environment )) op1 op2))
                    (newline)
                    (calcpost)))))
        ((or (equal? saisie 'sqrt)
             (equal? saisie 'abs)
             (equal? saisie 'cos)
             (equal? saisie 'sin))
         (begin ((let ((op (sommet)))
                   (depiler)
                   (empiler ( (eval saisie (interaction-environment )) op))
                   (newline)
                   (calcpost)))
                ((equal? saisie 'fin)
                 (begin
                   (display "fin")
                   (if (not (vide?))
                       (vider))))))
                (else (display "erreur")
                      (newline)
                      (calcpost))))))

    (calcpost)
                   
  
      
      
      