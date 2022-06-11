(define (appendorder l a)
  (if (null? l)
    (cons a null)
    (if (> a (car l))
      (cons (car l) (appendorder (cdr l) a))
      (cons a l)
      )
  )
)

(define (insertionsort l)
  (if (null? l)
    l
    (appendorder (insertionsort (cdr l)) (car l))
  ) 
)

(insertionsort '(4 1 43 38 7000 5423 5 48 2133 3421 34))
