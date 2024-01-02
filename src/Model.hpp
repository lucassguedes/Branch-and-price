#ifndef __BPMODEL__
#define __BPMODEL__
#include <ilcplex/ilocplex.h>
#include <vector>
#include "Data.hpp"
#include "Node.hpp"

#define BIG_M 1e6

class Pattern
{
public:
    IloNumVar var;
    double value;
    std::vector<int> activated_x;

    Pattern(IloNumVar var, std::vector<int> activated_x);
};

class Master
{
public:
    IloModel model;
    std::vector<Pattern> patterns;
    IloRangeArray constraints;
    IloExpr objective;

    Master(IloEnv env);
    Master(){}

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
    IloRange capCons; /*Restrição de capacidade*/
    std::vector<IloRange> nodeCons; /*Restrições características da ramificação*/

    Pricing(){}
    Pricing(IloEnv env, const int n);

};


Master createMasterModel(Data *data, IloEnv env);
void solveMaster(Master & master, IloCplex & masterSolver);
Pricing createPricingModel(Data * data, NodeInfo &nodeInfo, std::vector<double> pi, const int nCons, IloEnv env);
void updatePricingCoefficients(Pricing &pricing, const int nCons, std::vector<double>&pi);
void solvePricing(Pricing &pricing, IloCplex & pricingSolver);

#endif