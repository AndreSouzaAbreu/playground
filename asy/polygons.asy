settings.outformat="png";
settings.render=16;
size(5cm);

for (int n = 3; n <= 7; ++n) {
	draw(shift(2.5*n, 0) * polygon(n));
	draw(shift(2.5*n, 0) * unitcircle);
}
