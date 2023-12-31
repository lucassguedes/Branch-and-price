#ifndef __BPMODEL__
#define __BPMODEL__
#include <ilcplex/ilocplex.h>
#include <vector>

class Pattern
{
public:
    IloNumVar var;
    std::vector<int> activated_x;

    Pattern(IloNumVar var, std::vector<int> activated_x);
};

class Master
{
public:
    IloModel model;
    std::vector<Pattern> patterns;
    IloRangeArray constraints;

    Master(IloEnv env);

    void addVar(IloEnv env, char *name, std::vector<int> activated_x);
    void addConstraint(IloRange cst);

    int getNumberOfConstraints();
    int getNumberOfVariables();

    IloNumVar getVar(const int i);
};

class Pricing{
public:
    IloBoolVarArray x;
    IloModel model;
    IloExpr objective;
    IloRange cons;

    Pricing(IloEnv env, const int n);

};

#endif