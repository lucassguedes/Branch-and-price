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
    this->objective = IloExpr(env);
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


Master createMasterModel(Data *data, IloEnv env)
{
  Master master = Master(env);

  const int n = data->getNumberOfItems(); /**Número total de itens*/
  char varname[100];
  /*Obtendo conjunto inicial de padrões, cada um contendo apenas um item*/
  for(int i = 0; i < n; i++)
  {
    sprintf(varname, "Lambda(%d)", i+1);
    master.addVar(env, varname, std::vector<int>({i+1}));
  }

   /*Função objetivo*/
  for(size_t i = 0; i < n; i++)master.objective += BIG_M*master.getVar(i);


  master.model.add(IloMinimize(env, master.objective));


  /*No modelo mestre, para cada item i existe uma restrição associada.
    Em cada restrição, somente um padrão poderá ser ativado (valor 1).
    Inicialmente, cada um dos padrões selecionados contém somente um item.
  */

  IloRange cst;
  IloExpr exp;
  char cstName[100];
  for(int i = 0; i < n; i++)
  {
    exp = IloExpr(env);
    exp += master.getVar(i);
    cst = (exp == 1);
    sprintf(cstName, "UNIQUE_PATTERN(%d)", i+1);
    cst.setName(cstName);
    master.addConstraint(cst);
  } 

  return master;
}


void solveMaster(Master & master, IloCplex & masterSolver)
{
  // /*Resolvendo o problema*/
  masterSolver.extract(master.model);

  masterSolver.solve();
}


Pricing createPricingModel(Data * data, std::vector<double> pi, const int nCons, IloEnv env)
{
  const int n = data->getNumberOfItems();
  char varname[100];
  Pricing pricing = Pricing(env, n);


  /*Criando variáveis*/
  for(int i = 0; i < n; i++)
  {
    sprintf(varname, "X(%d)", i+1);
    pricing.x[i].setName(varname);
    pricing.model.add(pricing.x[i]);
  } 

  /*Definindo função objetivo*/
  pricing.objective += 1;

  for(int i = 0; i < nCons; i++)
  {
    pricing.objective += -pi[i]*pricing.x[i];
  }

  pricing.model.add(IloMinimize(env, pricing.objective));

  /*Definindo restrição*/
  IloExpr pricingConsExpr(env);

  for(int i = 0; i < nCons; i++)
  {
    pricingConsExpr += data->w[i]*pricing.x[i];
  }

  pricing.cons = (pricingConsExpr <= data->W);

  pricing.model.add(pricing.cons);

  return pricing;
}


void updatePricingCoefficients(Pricing &pricing, const int nCons, std::vector<double>&pi)
{
  for(int i = 0; i < nCons; i++)
  {
    pricing.objective.setLinearCoef(pricing.x[i], -pi[i]);
  }
}

void solvePricing(Pricing &pricing, IloCplex & pricingSolver)
{
  pricingSolver.extract(pricing.model);

  pricingSolver.solve();
}