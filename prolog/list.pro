list_member([X|_], X).
list_member([_|T], X) :- list_member(T, X), !.

list_length([], 0).
list_length([_|T], N) :- list_length(T, NT), N is NT+1.

list_concat([], L, L).
list_concat([H|T], L, [H|X]) :- list_concat(T, L, X).

list_shift([_|T], T).

list_pop([_], []).
list_pop([H|T], [H|L]) :- list_pop(T, L), !.

list_prepend(A, X, [X|A]).
list_append(A, X, L) :- list_concat(A, [X], L).

list_del([X|T], X, T).
list_del([H|T], X, [H|LT]) :- list_del(T, X, LT), !.

list_ith(_, 0, _) :- fail.
list_ith([H|_], 1, H).
list_ith([_|T], I, X) :- list_ith(T, J, X), I is J+1.
list_ref(L, I, X) :- list_ith(L, I, X), !.

list_eq(A, A).

list_rev([], []).
list_rev([H], [H]).
list_rev([H|T], X) :- list_rev(T, Y), list_append(Y, H, X), !.

seq1(1, [1]).
seq1(N, [N|X]) :-  seq1(N1, X), N is N1+1.
seq(N, X) :- seq1(N ,X), !.
