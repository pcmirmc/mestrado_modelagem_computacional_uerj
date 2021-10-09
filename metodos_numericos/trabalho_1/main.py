import numpy as np
import random
from root_find import rootFind
import logging
import coloredlogs
#Habilitando logs
coloredlogs.install()
logging.basicConfig(level=logging.INFO) 

if __name__ == "__main__":
    # Escolhendo metodo 1 para newton e 2 para bisseccao
    method_choiced = input('Escolha 1 para o metodo de newton ou 2 para o metodo da bissecção:')
    h_choiced = input('Digite o valor para h2:')
    #calculo das assintotas verticais para k = {0,1,2,3,4,5}
    x_lim = [(np.pi/2) + (k*np.pi) for k in [0,1,2,3,4,5]]
    # criacao dos pares usando as assintotas verticais e armazenando em um dicionario
    dict ={}
    for a in range(0,6):
        if a==0:
            dict[f'par_{a+1}'] = (0,x_lim[a]) 
        else: 
            dict[f'par_{a+1}'] = (x_lim[a-1],x_lim[a])
    # iniciando a busca das raizes para cada par (total 6 pares)
    i=1
    for k,value in dict.items():
        logging.info(f"INICIANDO A BUSCA DA RAIZ {i}...")
        # valor inicial para x0 usando a media de cada par
        if float(h_choiced) < 10:
            selected_x_ini = (value[0] + value[1]) / 2
        else:
            # para valores altos de h2 usar um valor proximo a assintota vertical mais a direita para valor inicial x0
            selected_x_ini = value[1] - 0.0001
        #instanciando o metodo para achar as raizes no arquiavo root_find.py, tolerancia de 10^-6, valor de h2 para esse exemplo valor 1
        problem = rootFind(selected_x_ini,0.000001,float(h_choiced))
        #rodando o metodo escolhido pelo usuario
        if method_choiced == '1':
            problem.newton_raphson_method()
        else:
            if k == 'par_1':
                problem.bisection_method(value[0],value[1])
            else:
                problem.bisection_method(value[0]+0.000001,value[1]-0.000001)
        # termino do loop raiz encontrada, proxima iteracao sera escolhida o proximo par para obtencao da proxima raiz
        logging.info(f"BUSCA DA RAIZ {i} FINALIZADA!!!")
        i+=1