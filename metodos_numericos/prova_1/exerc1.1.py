import numpy as np
import logging
import coloredlogs
#Habilitando logs
coloredlogs.install()
logging.basicConfig(level=logging.INFO) 
# definindo funcao ajustada para o metodo do ponto fixo
def function(x:float)->float:
    y = ((x*x)/5)  + 1
    return y
x=1
logging.warning(f'Metodo do ponto fixo para a f(x) = x^2/5 -x + 1, com x0={x}')
# realizando as 5 iteracoes
for i in range(5):
    logging.info(f'Iniciando {i+1} iteracao do metodo do ponto fixo...')
    y=function(x)
    logging.info(f'O valor para x{i+1} e: {round(y,6)}')
    x=y