#include "Model.hpp"


Pattern::Pattern(IloNumVar var, std::vector<int>activated_x)
{
this->var = var;
this->activated_x = activated_x;
}

Master::Master(IloEnv env)
{
    this->model = IloModel(env);
    this->constraints = IloRangeArray(env);
}

void Master::addVar(IloEnv env, char*name, std::vector<int> activated_x)
{
    IloNumVar newvar = IloNumVar(env, 0, IloInfinity, name);
    this->patterns.push_back(Pattern(newvar, activated_x));
    this->model.add(newvar);
}

int Master::getNumberOfConstraints()
{
    return this->constraints.getSize();
}

int Master::getNumberOfVariables()
{
    return this->patterns.size();
}

void Master::addConstraint(IloRange cst)
{
    this->model.add(cst);
    this->constraints.add(cst);
}


IloNumVar Master::getVar(const int i)
{
    return this->patterns[i].var;
}


Pricing::Pricing(IloEnv env, const int n)
{   
    this->model = IloModel(env);
    this->x = IloBoolVarArray(env, n);
    this->objective = IloExpr(env);
}