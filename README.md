# HyperbolicEquation
#### The project is programmed grid method for solving linear differential equations of second order of hyperbolic type.In the project realised explicit and implicit algorithms for numerical solution of equation.
####
#### The program shows the movement of the wave equation on the chart, compute the maximum error between numerical and analytical solution of the equation.
#### As the input enters the number of divisions of the grid in the spatial axis (N), the number of divisions of the grid along the time axis (M) and time limit (T).
 #### As the input enters the number of divisions of the grid in the spatial axis (N), the number of divisions of the grid along the time axis (M) and time limit (T).
 ####
 ## A posteriori evaluation
#### Consider the net-point method by the following equation.
![equation](http://www.imageup.ru/img143/2980320/snimok-1.jpg "equation") 
 #### Let us compare the explicit and implicit algorithm grid method, determine the a posteriori estimation of the optimal number of the mesh and compute the maximum error in the numerical method. 
 #### As time limit we take T=10.
 #### The results of the experiments are presented in table:
 |3000x3000|	0,01457757|	1000x5000|	1.00606|
 |5000x5000|	0,01110913|	3000x10000|	1.00365|
 
#### As can be seen from the table, the explicit method is very poorly approximated, and thus this method requires the condition of stability (8) <1, otherwise the clear solution will go to infinity. With increase in time will grow and error, and quite quickly.
#### The implicit method converges when the mesh size 1000x1000. This split is already enough in order to speak with confidence about the approximation solutions.
