from models import OptimizeRoute
from platypus import NSGAII
from platypus import *
import json
import pandas as pd

# read json with problem coefs
with open('problemCoefs.json') as f:
    problemCoefs = json.load(f)




algorithm = NSGAII(OptimizeRoute(
    num_decision_variables= len(problemCoefs['variables']),
    num_objectives= len(problemCoefs['objectives']),
    num_constraints= len(problemCoefs['constraints']),
    constraint_sign_list= problemCoefs['constraint_types'],
    objective_list= problemCoefs['objectives'],
    constraint_list= problemCoefs['constraints']
),variator=CompoundOperator(SBX(), HUX(), PM(), BitFlip()))

algorithm.run(10000)
result_feasible_solutions = [s for s in algorithm.result if s.feasible]
print(len(result_feasible_solutions))
for first_solution in result_feasible_solutions[:3]:
    df_result = pd.DataFrame({
     "variables":problemCoefs['variables'],
        "solution":first_solution.variables
    })
    df_obj_result = pd.DataFrame({
        "objectives": ["ponto_inicial","tempo_viagem"],
        "solution":[first_solution.objectives[0],first_solution.objectives[1]]
    })

    print(df_result)
    print(df_obj_result)
