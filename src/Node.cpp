#include "Node.hpp"


std::ostream& operator << (std::ostream& os, const NodeInfo& node){
    os << "Node " << node.id << "\n\t";
    os << "Must be separated: ";
    for(auto&[first, second] : node.mustBeSeparated)
    {
        os << "(" << first << ", " << second << "),";
    }
    os << "\n\tMust be together: ";
    for(auto&[first, second] : node.mustBeTogether)
    {
        os << "(" << first << ", " << second << "),";
    }
    os << "\n";

    return os;   
}
