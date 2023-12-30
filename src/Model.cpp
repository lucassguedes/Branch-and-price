#include "Model.hpp"


Pattern::Pattern(IloBoolVar var, std::vector<int>activated_x)
{
this->var = var;
this->activated_x = activated_x;
}

Master::Master(IloEnv env)
{
this->model = IloModel(env);
}

void Master::addVar(IloEnv env, char*name, std::vector<int> activated_x)
{
    IloBoolVar newvar = IloBoolVar(env, name);
    this->patterns.push_back(Pattern(newvar, activated_x));
    this->model.add(newvar);
}

IloBoolVar Master::getVar(const int i)
{
    return this->patterns[i].var;
}
