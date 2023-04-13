

;QUESTION 1
(display "QUESTION 4")
(newline)

(cons 'a (cons 'b (cons '() '() )))
(cons 'a (cons 'b (cons '(d e) '() )))

(list 'a 'b '())
(list 'a 'b '(d e))

;QUESTION 2
(newline)
(display "QUESTION 2")
(newline)

(define x 'a)
(define y 1)
(define z "x")

(cons x (cons 'y (list z)))
; (a y "x")

(list x y '(+ y y) z)
; (a 1 (+ y y) "x") CORRECT

(cons (list 'x y) (cons z '()))
;((x 1) "x")

(caaddr '(x y ((z))) )
;(z)

(apply append (list (cons 'x (list y)) (list 'y z x)))
;(x 1 y "x" a)

(map list (cons 'x (list y)) (list 'y z x))
;((x y) (1 "x"))

;QUESTION 3
(newline)
(display "QUESTION 3")
(newline)

(define (appliquef lf n1 n2)
  (if (null? lf)
      '()
      (cons ((eval (car lf) (interaction-environment)) n1 n2) (appliquef (cdr lf) n1 n2))))

(appliquef '(+ - * expt) 4 2)

;QUESTION 4
(newline)
(display "QUESTION 4")
(newline)

(define (puiss2 n)
  (expt 2 (- n 1)))

(define (sompuiss2 n)
  (if (equal? n 0)
      0
      (+ (puiss2 n) (sompuiss2 (- n 1)))))

(define (affpuiss2 n)
  (if (not(equal? n 0))
      (begin (affpuiss2 (- n 1))
             (display (puiss2 n))
             (newline))))
                       
(affpuiss2 3)

;QUESTION 5
(newline)
(display "QUESTION 5")
(newline)

(define (mange1 pop)
  (cond ((null? (cddr pop)) pop)
        ((equal? (car pop) (cadr pop)) (cons (car pop) (mange1 (cdr pop))))
        ((equal? (car pop) (caddr pop)) (cons (car pop) (cddr pop)))
        (else (cons (car pop) (mange1 (cdr pop))))))



(define l '(+ - - + - + + - - + + -))

(mange1 l)
             