from types import FunctionType
import numpy as np
import logging


class rootFind:
    def __init__(self,x_ini:float,tol:float,h:float,i=1):
        self.x_ini = x_ini
        self.tol = tol
        self.h =h
        self.i = i

    def tan_function(self,beta=None)->float:
        if beta != None:
            return (beta * np.tan(beta)) - self.h
        else:
            return (self.x_ini * np.tan(self.x_ini)) - self.h

    def dev_tan_function(self)->float:
        return (self.x_ini * (1/np.cos(self.x_ini))**2) + np.tan(self.x_ini)

    def next_xi(self)->float:
        xi = self.x_ini - (self.tan_function() / self.dev_tan_function())
        return xi

    def newton_raphson_method(self)->None:
        logging.info(f"Iniciando Iteracao {self.i} do metodo de Newton...")
        y = self.tan_function()
        if abs(y) <= self.tol:
            return logging.info(f"Solucao encontrada na iteracao {self.i}, valor aproximado para beta e: {self.x_ini} com um erro de {abs(y)}.")
        else:
            logging.warning(f"Solucao nao encontrada na iteracao {self.i}, indo para a proxima iteracao...")
            self.i +=1
            self.x_ini = self.next_xi()
            return self.newton_raphson_method()

    def bisection_method(self,a:float, b:float)->None: 
        logging.info(f"Iniciando Iteracao {self.i} do metodo da bissecção...")
        m = (a + b)/2
        if np.abs(self.tan_function(beta=m)) < self.tol:
            return logging.info(f"Solucao encontrada na iteracao {self.i}, valor aproximado para beta e: {m} com um erro de {abs(self.tan_function(beta=m))}.")

        elif np.sign(self.tan_function(beta=a)) == np.sign(self.tan_function(beta=m)):
            logging.warning(f"Solucao nao encontrada na iteracao {self.i}, indo para a proxima iteracao...")
            self.i+=1
            return self.bisection_method(m, b)

        elif np.sign(self.tan_function(beta=b)) == np.sign(self.tan_function(beta=m)):
            logging.warning(f"Solucao nao encontrada na iteracao {self.i}, indo para a proxima iteracao...")
            self.i+=1
            return self.bisection_method(a, m)