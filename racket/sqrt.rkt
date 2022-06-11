(define (sqrth a e g)
  (if (and 
        (>
          (+ a e)
          (* g g)
        )
        (<
          (- a e)
          (* g g)
        )
      )
      g
      (sqrth a e (/ (+ g (/ a g)) 2))
  )
)

(define (sqrtt a e)
  (sqrth a e (/ a 2))
)

(sqrtt 23 0.1)
(sqrth 49 0.1 2)
