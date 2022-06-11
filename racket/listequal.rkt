(define (equal a b)
  (if (and (null? a) (null? b))
    #t
    (if (or (null? a) (null? b))
      #f
      (if (= (car a) (car b))
        (listequal (cdr a) (cdr b))
        #f
      )
    )
  )
)


(listequal '(2 1 23 4) '(2 1 3 4))
