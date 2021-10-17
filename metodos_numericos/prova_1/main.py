import numpy as np
import random
from rootFind import rootFind
import logging
import coloredlogs
#Habilitando logs
coloredlogs.install()
logging.basicConfig(level=logging.INFO) 
#chute inicial
x_ini = 2.5
#valores usados para bisseccao e para secante
a=0
b=5
if __name__ == "__main__":
    # Escolhendo metodo 1 para newton e 2 para bisseccao e 3 para secante
    method_choiced = input('Escolha 1 para o metodo de newton, 2 para o metodo da bissecção ou 3 para o metodod a secante:')
    tol = float(input('Digite a tolerancia:'))
    problem = rootFind(x_ini,tol)
    if method_choiced == '1':
        problem.newton_raphson_method()
    elif method_choiced == '2':
        problem.bisection_method(a,b)
    elif method_choiced == '3':
        problem.secant_method(a,b)