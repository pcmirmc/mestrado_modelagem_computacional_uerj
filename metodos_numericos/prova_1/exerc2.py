import numpy as np
import logging
import coloredlogs
#Habilitando logs
coloredlogs.install()
logging.basicConfig(level=logging.INFO) 
# defindo classe lagrange para calcula dos coeficientes de um polinomio de grau 2 baseado em 3 pontos
class LagrangeP2:
    def __init__(self,dict_points:dict)->None:
        # inicializa as variaveis (pontos da funcao) oriundas do dicionario
        self.x0 = dict_points['p1'][0]
        self.y0 = dict_points['p1'][1]
        self.x1 = dict_points['p2'][0]
        self.y1 = dict_points['p2'][1]
        self.x2 = dict_points['p3'][0]
        self.y2 = dict_points['p3'][1]
    def coefs_multiplier(self):
        #calcula os coeficientes dos polinomios de lagrange multiplicado pela variavel y
        cl0 = 1/((self.x0-self.x1)*(self.x0-self.x2))
        cl1 = 1/((self.x1-self.x0)*(self.x1-self.x2))
        cl2 = 1/((self.x2-self.x0)*(self.x2-self.x1))
        return self.y0*cl0, self.y1*cl1, self.y2*cl2
    def get_polinomial_coefs(self):
        # com os coeficientes dos polinomios de lagrange calcula os coeficientes finais para cada grau do polinomio
        c0,c1,c2 = self.coefs_multiplier()
        # coeficiente de x^2
        coef_x2 = c0 + c1 + c2
        x1_t0 = -self.x1 + -self.x2
        x1_t1 = -self.x0 + -self.x2
        x1_t2 = -self.x0 + -self.x1
        # coeficiente de x
        coef_x1 = (c0*x1_t0) + (c1*x1_t1) + (c2*x1_t2)
        x0_t0 = -self.x1 * -self.x2
        x0_t1 = -self.x0 * -self.x2
        x0_t2 = -self.x0 * -self.x1
        # coeficiente de x^0
        coef_x0 = (c0*x0_t0) + (c1*x0_t1) + (c2*x0_t2)
        return coef_x2,coef_x1,coef_x0
# definindo a funcao do problema
def function(x:float)->float:
    y = 1/(x*x)
    return y


if __name__ == "__main__":
    # dicionario com os pontos da funcao
    dict_points = {
    'p1': (1,function(1)),
    'p2': (2,function(2)),
    'p3': (4,function(4)),
    }
    # instanciando a classe criada de lagrange
    lagrange_method = LagrangeP2(dict_points)
    # retornando os coeficientes do polinomio de grau 2
    coef_x2,coef_x1,coef_x0 = lagrange_method.get_polinomial_coefs()
    #printando o resultado
    logging.info(f"O polinomio de Lagrange encontrado e P2(x) = {round(coef_x2,6)}x^2 + {round(coef_x1,6)}x + {round(coef_x0,6)}")
