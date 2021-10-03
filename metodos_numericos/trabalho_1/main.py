import numpy as np
import random
from root_find import rootFind
import logging
import coloredlogs

coloredlogs.install()

logging.basicConfig(level=logging.INFO) 

if __name__ == "__main__":

    method_choiced = input('Escolha 1 para o metodo de newton ou 2 para o metodo da bissecção.')
    x_lim = [(np.pi/2) + (k*np.pi) for k in [0,1,2,3,4,5]]
    dict ={}
    for a in range(0,6):
        if a==0:
            dict[f'par_{a+1}'] = (0,x_lim[a]) 
        else: 
            dict[f'par_{a+1}'] = (x_lim[a-1],x_lim[a])
    i=1
    for k,value in dict.items():
        logging.info(f"INICIANDO A BUSCA DA RAIZ {i}...")
        random_x_ini = random.uniform(value[0],value[1])
        problem = rootFind(random_x_ini,0.000001,1)
        if method_choiced == '1':
            problem.newton_raphson_method()
        else:
            problem.bisection_method(value[0]+0.00001,value[1])
        logging.info(f"BUSCA DA RAIZ {i} FINALIZADA!!!")
        i+=1