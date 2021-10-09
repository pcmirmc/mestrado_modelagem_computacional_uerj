from types import FunctionType
import numpy as np
import logging

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
    def __init__(self,x_ini:float,tol:float,h:float,i=1):
        #instanciando variaveis para serem usadas em todas as funcoes da classe
        self.x_ini = x_ini
        self.tol = tol
        self.h =h
        self.i = i

    def tan_function(self,beta=None)->float:
        # funcao tangente target f(x)= xtan(x) - h
        if beta != None:
            return (beta * np.tan(beta)) - self.h
        else:
            return (self.x_ini * np.tan(self.x_ini)) - self.h

    def dev_tan_function(self)->float:
        # funcao que calcula a derivada da funcao tan_function
        return (self.x_ini * (1/np.cos(self.x_ini))**2) + np.tan(self.x_ini)

    def next_xi(self)->float:
        # calcula o proximo xi do metodo de newton
        xi = self.x_ini - (self.tan_function() / self.dev_tan_function())
        return xi

    def newton_raphson_method(self)->None:
        #roda o metodo de newton
        logging.info(f"Iniciando Iteracao {self.i} do metodo de Newton...")
        y = self.tan_function()
        # verifica criterio de tolerancia
        if abs(y) <= self.tol:
            return logging.info(f"Solucao encontrada na iteracao {self.i}, valor aproximado para beta e: {self.x_ini} com um erro de {abs(y)}.")
        else:
            logging.warning(f"Solucao nao encontrada na iteracao {self.i}, valor aproximado para beta e: {self.x_ini}, indo para a proxima iteracao...")
            self.i +=1
            self.x_ini = self.next_xi()
            return self.newton_raphson_method()

    def bisection_method(self,a:float, b:float)->None: 
        #roda o metodo da bisseccao
        logging.info(f"Iniciando Iteracao {self.i} do metodo da bissecção...")
        #novo valor de m para o intervalo dado
        m = (a + b)/2
        # verifica o criterio de tolerancia
        if np.abs(self.tan_function(beta=m)) < self.tol:
            return logging.info(f"Solucao encontrada na iteracao {self.i}, valor aproximado para beta e: {m} com um erro de {abs(self.tan_function(beta=m))}.")
        # verifica se a saida de m e igual a saida do extremo a do intervalo, se for m sera usado no lugar de a na proxima iteracao.
        elif np.sign(self.tan_function(beta=a)) == np.sign(self.tan_function(beta=m)):
            logging.warning(f"Solucao nao encontrada na iteracao {self.i}, valor aproximado para beta e: {m}, indo para a proxima iteracao...")
            self.i+=1
            return self.bisection_method(m, b)
        # verifica se a saida de m e igual a saida do extremo b do intervalo, se for, m sera usado no lugar de b na proxima iteracao.
        elif np.sign(self.tan_function(beta=b)) == np.sign(self.tan_function(beta=m)):
            logging.warning(f"Solucao nao encontrada na iteracao {self.i}, valor aproximado para beta e: {m}, indo para a proxima iteracao...")
            self.i+=1
            return self.bisection_method(a, m)