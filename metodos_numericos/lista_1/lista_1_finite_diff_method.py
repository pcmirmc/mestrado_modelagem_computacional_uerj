# install dependencies in linux or windows PowerShell:
    # pip install numpy
    # pip install matplotlib
    # pip install pandas
# if in linux install tk module to render plot
    # sudo apt-get install python3-tk

import numpy as np
from matplotlib import pyplot as plt
import pandas as pd
import time
import logging
logging.basicConfig(level=logging.INFO)

# variables for specific problem solution
node = 10
t_0 = 180
t_n = 65
x_0 = 0
x_n = 0.15
t_amb = 20
h_conv = 150
d = 3.5 * 10**(-3)
k = 120

class finite_diff_heat_problem:
    """
    Solve EDO problem using finite difference method for a heat transfer problem with the pattern:
    y" - m^2(y - t_amb)
    Where m and t_amb are constant variables.
    Args:
        node: number of nodes to use for problem solver.
        t_0: Initial Temperature for boundary condition.
        t_n: Final Temperature for boundary condition.
        x_0: Initial Position for boundary condition.
        x_n: Final Position for boundary condition.
        h_conv: Trade heat by convexion coef.
        d: Fin Diameter.
        k: Fin = Thermal conductivity.
        t_amb: Environment Temperature.
    Returns:
        matrix_a: The A Transformation matrix for Ax = b.
        matrix_b: The b Result matrix for Ax = b.
        y_solution: The solution for the problem Ax = b.
    """

    def __init__(self,node,t_0,t_n,x_0,x_n,h_conv,d,k,t_amb):
        self.p = np.pi * d
        self.a = (np.pi*d*d) / 4
        self.m = (h_conv*self.p) / (k*self.a)
        self.h = (x_n - x_0) / node
        # Q is the coef of Yi term.
        self.Q = 2 + (self.m*self.h*self.h)
        # W is the independent term
        self.W = t_amb*self.m*self.h*self.h
        self.t_0 = t_0
        self.t_n = t_n
        self.x_0 = x_0
        self.x_n = x_n
        self.node = node
    
    def create_matrix_for_linear_transform(self):
        logging.info("Creating the Matrix using finite difference method...")
        matrix_a = np.zeros((self.node + 1, self.node + 1))
        matrix_a[0,0] = 1
        matrix_a[self.node,self.node] = 1
        for i in range(1,self.node):
            matrix_a[i, i-1] = -1
            matrix_a[i, i] = self.Q
            matrix_a[i, i+1] = -1

        matrix_b = np.zeros(node+1)
        matrix_b[0] = self.t_0
        matrix_b[1:-1] = self.W
        matrix_b[-1] = self.t_n

        return matrix_a, matrix_b

    def solve_linear_problem(self,matrix_a,matrix_b):
        logging.info("Solving Linear Problem...")
        return np.linalg.solve(matrix_a,matrix_b)

    def plot_results(self,y_solution):
        x = np.linspace(self.x_0,self.x_n,self.node + 1)
        df_result = pd.DataFrame({'x_position':x,'y_temperature':y_solution})
        logging.info("Printing Results...")
        print(df_result)
        logging.info("Ploting Solution...")
        plt.figure(figsize=(10,8))
        plt.plot(x, y_solution)
        plt.plot(self.x_n, self.t_n, 'ro')
        plt.xlabel('Position (m)')
        plt.ylabel('Temperature (C)')
        plt.show()

logging.info("Initializing problem, loading variables...")
heat_problem = finite_diff_heat_problem(node,t_0,t_n,x_0,x_n,h_conv,d,k,t_amb)
matrix_a, matrix_b = heat_problem.create_matrix_for_linear_transform()
start_time = time.time()
y_solution = heat_problem.solve_linear_problem(matrix_a, matrix_b)
print("--- %s seconds ---" % (time.time() - start_time))
heat_problem.plot_results(y_solution)
logging.info("Done...bye!")
