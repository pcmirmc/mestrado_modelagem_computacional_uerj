from platypus import NSGAII, Problem, Real, Integer

class OptimizeRoute(Problem):
# this  is a test ;;::''""//??;;;:
    def __init__(
        self,
        num_decision_variables: int,
        num_objectives: int,
        num_constraints: int,
        constraint_sign_list: list,
        objective_list: list,
        constraint_list: list
        ):
        super(OptimizeRoute, self).__init__(
            num_decision_variables,
            num_objectives,
            num_constraints
        )
        self.types[:] = [Integer(0, 1) for _ in range(num_decision_variables)]
        self.constraints[:] = constraint_sign_list
        self.objective_list = objective_list
        self.constraint_list = constraint_list
    
    def evaluate(self, solution):
        objective_list_ready = []
        for objective in self.objective_list:
            tmp = [coef * solution.variables[ind] for ind,coef in enumerate(objective)] # [1 * varA, 2 * varB] funcao objetivo 1
            objective_list_ready.append(sum(tmp)) # [1* varA + 2* varB,2* varA + 3* varB]
        
        constraint_list_ready = []
        for constraint in self.constraint_list:
            tmp = [coef * solution.variables[ind] for ind,coef in enumerate(constraint)]
            constraint_list_ready.append(sum(tmp))
        
        solution.objectives[:] = objective_list_ready
        solution.constraints[:] = constraint_list_ready
        