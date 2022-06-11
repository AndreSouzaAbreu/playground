on(a, b).
on(b, c).
above(X, Y) :- on(X, Y) , ! ; ( on(X, Z), above(Z, Y) ).
