(define (mdc a b)
  (if (> b a) (mdc b a)
   (if (zero? (remainder a b))
      b
      (mdc b (remainder a b))
    )
  )
)

(mdc 432540 2480)
