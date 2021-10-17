from types import FunctionType
import numpy as np
import logging
import pandas as pd
from tabulate import tabulate

#criacao de classe que roda os metodos de newton e bisseccao
class rootFind:
    """
    Roda os metodos numericos de newton e bisseccao para uma funcao do tipo f(x) = xtan(x) - h. Ambos os metodos foi-se utilizado a recursividade de funcoes para a geracao de cada iteracao.
    Args:
        x_ini: O valor inicial x0 para o metodo de newton.
        tol: Tolerancia a ser batida para ambos os metodos.
        h: Termo Independente h2 da funcao.
        i: Variavel auxiliar para iteracao do algoritmo.
    Returns:
        Resultados de cada iteracao seja do metodo de newton ou do metodo da bissecao.
    """
    def __init__(self,x_ini:float,tol:float,i=0):
        #instanciando variaveis para serem usadas em todas as funcoes da classe
        self.x_ini = x_ini
        self.tol = tol
        self.i = i
        self.m = 9999999999999999999999999
        self.df = pd.DataFrame({})

    def function(self,beta=None)->float:
        # lembrar de ajustar a funcao abaixo
        if beta != None:
            return (beta * beta) - 15
        else:
            return (self.x_ini * self.x_ini) - 15

    def dev_function(self,beta=None)->float:
        #lembrar de ajustar a derivada
        if beta != None:
            return 2*beta
        else:
            return self.x_ini*2

    def next_xi(self)->float:
        # calcula o proximo xi do metodo de newton
        xi = self.x_ini - (self.function() / self.dev_function())
        return xi
    def secant_next_xi(self,x0:float,x1:float)->float:
        # calcula o proximo xi do metodo da secante
        function_result = self.function(x1)
        xi = x1 - (function_result * ((x1 - x0) / (function_result - self.function(x0))))
        return xi
    def newton_raphson_method(self)->None:
        #roda o metodo de newton
        logging.info(f"Iniciando Iteracao {self.i} do metodo de Newton...")
        x0 = self.x_ini
        self.x_ini = self.next_xi()
        tmp_dict = {
            "k": self.i,
            "x_k": x0,
            "f(x_k)":self.function(beta=x0),
            "f'(x_k)":self.dev_function(beta=x0),
            "x_k+1":self.x_ini,
            "|x_k+1 - x_k|": abs(self.x_ini - x0)
        }
        self.df = self.df.append(tmp_dict,ignore_index=True)
        # verifica criterio de tolerancia
        if abs(self.x_ini - x0) <= self.tol:
            logging.info(f"Solucao encontrada na iteracao {self.i}, valor aproximado para beta e: {self.x_ini}")
            return print( tabulate(self.df, headers='keys', tablefmt='psql') )
        else:
            logging.warning(f"Solucao nao encontrada na iteracao {self.i}, valor aproximado para beta e: {self.x_ini}, indo para a proxima iteracao...")
            self.i +=1
            return self.newton_raphson_method()

    def bisection_method(self,a:float, b:float)->None: 
        #roda o metodo da bisseccao
        logging.info(f"Iniciando Iteracao {self.i} do metodo da bissecção...")
        #novo valor de m para o intervalo dado
        m0 = self.m
        self.m = (a + b)/2
        tmp_dict = {
            "k": self.i,
            "a_k": a,
            "f(a_k)":self.function(beta=a),
            "b_k":b,
            "f(b_k)":self.function(beta=b),
            "c_k":self.m,
            "f(c_k)":self.function(beta=self.m),
            "|c_k - c_k-1|":  None if self.i == 0 else np.abs(self.m - m0)
        }
        self.df = self.df.append(tmp_dict,ignore_index=True)
        # verifica o criterio de tolerancia
        if np.abs(self.m - m0) < self.tol and self.i > 0:
            logging.info(f"Solucao encontrada na iteracao {self.i}, valor aproximado para beta e: {self.m} com um erro de {np.abs(self.m - m0)}.")
            return print( tabulate(self.df, headers='keys', tablefmt='psql') )
        # verifica se a saida de m e igual a saida do extremo a do intervalo, se for m sera usado no lugar de a na proxima iteracao.
        elif np.sign(self.function(beta=a)) == np.sign(self.function(beta=self.m)):
            logging.warning(f"Solucao nao encontrada na iteracao {self.i}, valor aproximado para beta e: {self.m}, indo para a proxima iteracao...")
            self.i+=1
            return self.bisection_method(self.m, b)
        # verifica se a saida de m e igual a saida do extremo b do intervalo, se for, m sera usado no lugar de b na proxima iteracao.
        elif np.sign(self.function(beta=b)) == np.sign(self.function(beta=self.m)):
            logging.warning(f"Solucao nao encontrada na iteracao {self.i}, valor aproximado para beta e: {self.m}, indo para a proxima iteracao...")
            self.i+=1
            return self.bisection_method(a, self.m)

    def secant_method(self,x0:float, x1:float)->None: 
        #roda o metodo da bisseccao
        logging.info(f"Iniciando Iteracao {self.i} do metodo da secante...")
        #novo valor de m para o intervalo dado
        x_next = self.secant_next_xi(x0,x1)
        tmp_dict = {
            "k": self.i,
            "x_k": x1,
            "f(x_k)":self.function(beta=x1),
            "x_k-1": x0,
            "f(x_k-1)":self.function(beta=x0),
            "x_k+1":x_next,
            "|x_k+1 - x_k|": abs(x_next- x1)
        }
        self.df = self.df.append(tmp_dict,ignore_index=True)
        # verifica o criterio de tolerancia
        if abs(x_next - x1) <= self.tol:
            logging.info(f"Solucao encontrada na iteracao {self.i}, valor aproximado para beta e: {x_next}")
            return print( tabulate(self.df, headers='keys', tablefmt='psql') )
        else:
            logging.warning(f"Solucao nao encontrada na iteracao {self.i}, valor aproximado para beta e: {x_next}, indo para a proxima iteracao...")
            self.i +=1
            return self.secant_method(x1,x_next)