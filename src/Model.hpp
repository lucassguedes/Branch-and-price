#ifndef __BPMODEL__
#define __BPMODEL__
#include <ilcplex/ilocplex.h>
#include <vector>

class Pattern{
public:
  IloBoolVar var;
  std::vector<int> activated_x;

  Pattern(IloBoolVar var, std::vector<int>activated_x);
};

class Master{
public:
  IloModel model;
  std::vector<Pattern> patterns;

  Master(IloEnv env);

  void addVar(IloEnv env, char*name, std::vector<int> activated_x);
  IloBoolVar getVar(const int i);

};

#endif 