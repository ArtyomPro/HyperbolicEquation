# HyperbolicEquation
#### The project is programmed grid method for solving linear differential equations of second order of hyperbolic type.In the project realised explicit and implicit algorithms for numerical solution of equation.
####
#### The program shows the movement of the wave equation on the chart, compute the maximum error between numerical and analytical solution of the equation.
#### As the input enters the number of divisions of the grid in the spatial axis (N), the number of divisions of the grid along the time axis (M) and time limit (T).
####
## A posteriori evaluation
#### Let us compare the explicit and implicit algorithm grid method, determine the a posteriori estimation of the optimal number of the mesh and compute the maximum error in the numerical method. 
#### As time limit we take T=10.
#### The results of the experiments are presented in table:
|Dimension (NxM)|	The maximum error of the implicit method|	Dimension (NxM)|The maximum error of the explicit method |
|----------------|:---------:|----------------:|-----------------------:|
|10x10|	1,0907025|	10x100|	1.14394|
|100x100|	0,2495167|	10x1000|	1.05341|
|1000x1000|	0,04145394|	100x3000|	1.04867|
|3000x3000|	0,01457757|	1000x5000|	1.00606|
|5000x5000|	0,01110913|	3000x10000|	1.00365|


