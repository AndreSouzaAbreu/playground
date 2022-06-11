(define (lastel l)
  (if (null? l) null
    (if (null? (cdr l))
      (car l)
      (ultimo (cdr l))
    )
  )
)

(lastel '(a b da e ea ea kea ta ea eaea))
