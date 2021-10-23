import numpy as np
import logging
import coloredlogs
#Habilitando logs
coloredlogs.install()
logging.basicConfig(level=logging.INFO) 

# definindo a funcao
def function(x:float)->float:
    y = ((x*x)/5) - x + 1
    return y
# definindo a derivada primeira da funcao
def dev_function(x:float)->float:
    y = (2/5)*x -1
    return y
# definindo o calculo da proxima estimativa xk
def next_xi(xn1)->float:
    xn2 = xn1 - (function(xn1) / dev_function(xn1))
    return xn2

x=1
logging.warning(f'Metodo de Newton para a f(x) = x^2/5 -x + 1, com x0={x}')
# realizando as 2 primeiras iteracoes
for i in range(2):
    logging.info(f'Iniciando {i+1} iteracao do metodo de Newton...')
    y=next_xi(x)
    logging.info(f'O valor para x{i+1} e: {round(y,6)}')
    x=y