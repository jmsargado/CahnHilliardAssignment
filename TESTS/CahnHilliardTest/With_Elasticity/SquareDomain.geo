Mesh.Algorithm = 5;

L = 200.0;
cl = 1.0;

Point( 1 ) = { 0, 0, 0, cl };
Point( 2 ) = { L, 0, 0, cl };
Point( 3 ) = { L, L, 0, cl };
Point( 4 ) = { 0, L, 0, cl };

Line( 1 ) = { 1, 2 };
Line( 2 ) = { 2, 3 };
Line( 3 ) = { 3, 4 };
Line( 4 ) = { 4, 1 };

Curve Loop( 1 ) = { 1, 2, 3, 4 };
Plane Surface( 1 ) = { 1 };

Physical Surface( "Domain", 5 ) = { 1 };
Physical Curve( "Bottom", 6 ) = { 1 };
Physical Curve( "Right", 7 ) = { 2 };
Physical Curve( "Top", 8 ) = { 3 };
Physical Curve( "Left", 9 ) = { 4 };
