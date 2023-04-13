; L2-Info-Examen-Prog-Fonctionnelle-Jan-2020.ss
; Programmation fonctionnelle
; Correction examen janvier 2020
; (c) Eric Gouardères, Janvier 2020

;;;;;;;;;;;;;;;;;;;;;;;
; Question 1 (3 points)
; Définir une fonction change qui prend en paramètres une somme d’argent en Euros (nombre réel
; positif) et une monnaie (symbole) et qui retourne la somme d’argent convertie dans la monnaie
; correspondante. Si la monnaie n’est pas connue (voir tableau ci-dessous), la fonction retourne le
; symbole err_monnaie.

(define (change somme monnaie)
  (cond
    ((equal? monnaie 'USD) (* somme 1.115))
    ((equal? monnaie 'RUB) (* somme 69.093))
    ((equal? monnaie 'CNY) (* somme 7.743))
    (else 'err_monnaie))
  )

;;;;;;;;;;;;;;;;;;;;;;;
; Question 2 (2 points)
; Donner les expressions à évaluer pour construire les listes ci-dessous

; ... --> (a () b)
(cons 'a (cons '() (cons 'b '())))
(list 'a '() 'b)

; ... --> ((1 2) 3 ())
(cons (cons 1 (cons 2 '())) (cons 3 (cons '() '())))
(list (list 1 2) 3 '())

;;;;;;;;;;;;;;;;;;;;;;;
; Question 3 (4 points)
; Soit l’environnement {<x, 1>, <y, "x">, <z, x>}.
(define x 1)
(define y "x")
(define z 'x)

; Donner les résultats des évaluations des expressions Scheme suivantes :

(cons x (cons 'y (list z)))
;(1 y x)
(cons (list 'x y) (cons z '()))
;((x "x") x)
(list x (list 'y (list z)))
;(1 (y (x)))
(list x y '(+ y y) z) 
;(1 "x" (+ y y) x)
(caaddr '(x y ((z))))
;(z)
(cddar (cons (list x y) (list z)))
;()

;;;;;;;;;;;;;;;;;;;;;;;
; Question 4 (9 points)
; On représente le fichier clients d'une entreprise par une liste de clients.
; Chaque client est lui-même représenté par une liste contenant la référence (entier positif),
; le nom (symbole), le prénom (symbole), l'adresse (chaîne) et une liste de commandes.
; Chaque commande est représentée par une paire pointée associant un produit (chaîne) et une quantité commandée (entier positif).

(define fichier-client '((1651 Ada Paul "1 rue Foo, 64000 Pau"  (("souris" . 1) ("écran" . 2) ("clavier" . 1) ("boitier" . 1)))
 (1652 Java Pierre "1 av. Bar, 65000 Tarbes"  (("écran" . 2) ("boitier". 1)))
 (1653 Python Jean "5 bd.  Spam , 40000 Dax"  (("souris" . 2) ("écran" . 1)))))

; a. Définir une fonction quantite qui étant donné un produit et un client, retourne la quantité du produit commandée par le client.
; Si le client n'a pas commandé ce produit, la fonction retourne le symbole nc.
(define (commande cl)
  (car (cddddr cl))
  )

(define (quantite pdt cl)
  (quantite-aux pdt (commande cl)))

(define (quantite-aux pdt cde)
  (cond
    ((null? cde) 'nc)
    ((equal? (caar cde) pdt) (cdar  cde))
    (else (quantite-aux pdt (cdr cde)))))

; a.

(define (quantite pdt cl)
  (cond
    ((null? cl) 'nc)
    ((list? (car cl)) (quantite pdt (car cl)))
    ((pair? (car cl))
     (if (equal? (caar cl) pdt)
         (cdar cl)
         (quantite pdt (cdr cl))))
    (else (quantite pdt (cdr cl))))
  )

(quantite "écran" '(1652 Java Pierre "1 av. Bar, 65000 Tarbes"  (("écran" . 2) ("boitier". 1))))
(quantite "boitier" '(1652 Java Pierre "1 av. Bar, 65000 Tarbes"  (("écran" . 2) ("boitier". 1))))

; b. Définir une fonction quantite-totale qui étant donné un produit et le fichier client,
; retourne la quantité totale de ce produit commandée par l'ensemble des clients.

(define (quantite-totale pdt fcl)
  (if (null? fcl)
      0
      (let ((pdt-cl (quantite pdt (car fcl))))
        (if (not (equal? pdt-cl 'nc))
            (+ pdt-cl (quantite-totale pdt (cdr fcl)))
            (quantite-totale pdt (cdr fcl)))))
  )

(quantite-totale "écran" fichier-client)

; c. Définir une fonction produits qui étant donné deux clients, retourne la liste des produits achetés par ces clients.
; L'ordre des produits n'a pas d'importance, mais chaque produit n’apparaît qu’une seule fois dans la liste résultat.
(define (l-produits cde)
  (if (null? cde)
      '()
      (cons (caar cde) (l-produits (cdr cde)))))
  

(define (produits cl1 cl2)
  (produits-aux (l-produits (commande cl1)) (l-produits (commande cl2)))
  )

(define (appartient? x e)
  (cond
    ((null? e) #f)
    ((equal? x (car e)) #t)
    (else (appartient? x (cdr e))))
  )

(define (produits-aux cde1 cde2)
  (cond
    ((null? cde1) cde2)
    ((appartient? (car cde1) cde2) (produits-aux (cdr cde1) cde2))
    (else (cons (car cde1) (produits-aux (cdr cde1) cde2)))))

(produits  '(1652 Java Pierre "1 av. Bar, 65000 Tarbes"  (("écran" . 2) ("boitier". 1)))
           '(1653 Python Jean "5 bd.  Spam , 40000 Dax"  (("souris" . 2) ("écran" . 1))))

; d.Définir une fonction partition qui étant donné un produit et le fichier client, retourne une liste contenant deux sous-listes éventuellement vides.
; La première contient les clients qui ont commandé ce produit, la seconde contient ceux qui ne l'ont pas commandé.

(define (partition pdt fcl)
  (if (null? fcl)
      '(() ())
      (let ((sol-partielle (partition pdt (cdr fcl))))
        (if (equal? (quantite pdt (car fcl)) 'nc)
            (list (car sol-partielle) (cons (car fcl) (cadr sol-partielle)))
            (cons (cons (car fcl) (car sol-partielle)) (cdr sol-partielle)))))
  )
(partition "souris" fichier-client)
            

;;;;;;;;;;;;;;;;;;;;;;;
; Question 5 (3 points)
; On considère un environnement e dans lequel sont définies :
; - une variable l contenant une liste de nombres entiers,
; - une fonction f à deux paramètres p1 et p2.

; Définir la fonction gen-env qui prend en paramètre une fonction unaire foo, crée un environnement local selon
; le modèle de e et retourne l’évaluation de f.
; Initialement l est vide.
(define gen-env (lambda (foo)
                  (let ((l '()))
                    (let ((f (lambda (p1 p2)
                               (cond ((and (equal? p1 'get-l)
                                           (equal? p2 '()))
                                      l)
                                     ((and (equal? p1 'set-l!)
                                           (integer? p2))
                                      (set! l (cons p2 l)))
                                     ((and (equal? p1 'execute)
                                           (equal? p2 '()))
                                      (map foo l))
                                     (else (display "Erreur paramètres"))
                                     ))))
                      f))))