(load "grafcalc.ss")
(load "libcalc.ss")

(define (add a b)
  (if (non_zero? b )
        (add (incrementer a) (decrementer b))
  a))

 (define (sou a b)
  (if (non_zero? b )
        (sou (decrementer a) (decrementer b))
  a))

 (define (mul a b)
   (if (non_zero? b)
       (add a (mul a (decrementer b)))
       b))

(define (div a b)
   (if (sup_egal? a b)
      (incrementer (div (sou a b) b))
      0))

(gcalculet)