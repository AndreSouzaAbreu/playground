settings.outformat="png";
settings.render=16;
size(4.5cm, 0);

import three;

currentlight = White;
path3 spiral = path3(
  (-2,0) .. (0,7/4) .. (6/4,0) .. (0,-5/4) ..
  (-4/4,0) .. (0,3/4) .. (2/4,0) .. (0,-1/4) .. (0,0));
triple vertex = (0,-1, -2);
draw(extrude(spiral, vertex -- cycle), material(gray,
emissivepen=gray));
draw(spiral);
