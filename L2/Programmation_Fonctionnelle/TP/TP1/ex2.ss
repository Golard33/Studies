(define (fonction x y)
  ( + (/ (- x 3) (+ (* y y) 1) ) (/ 1 (+ (* x x x) 3) ) )
  )

(define ( celfar C )
  ( + 32 ( * C (/ 9 5) ) ) )

(define (carre x)
  (* x x))

(define (distance x1 x2 y1 y2)
  (sqrt ( + (carre (- x2 x1)) (carre ( - y2 y1) ) ) ) )

(define (ms m)
  ( * m 60) )

(define (hm h)
  ( * h 60) )

(define (hs h)
  (ms (hm h) ) )

(define (moypond n1 n2 c1 c2)
  (/ ( + (* n1 c1) (* n2 c2)) 2 ) )
