#ifndef ATOM_H
#define ATOM_H
#include <string>
using std :: string;
class Number;
class Variable;
class Atom {
private:
	const string _symbol;
public:
	Atom(string);
	bool match(Number operand);
	string match(Variable &variable);
};
#endif