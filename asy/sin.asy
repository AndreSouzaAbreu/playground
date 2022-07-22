settings.outformat="png";
unitsize(3cm);

import graph;

real f(real x) {
	return sin(x) * cos(60*x);
}
path g = graph(f,0,pi*2,n=200,Hermite);
draw(g);
