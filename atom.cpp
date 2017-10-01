#include "atom.h"
#include "number.h"
using std :: string;
Atom :: Atom(string s) : _symbol(s) {}
bool Atom :: match(Number operand) { return false; }
string Atom :: match(Variable &variable) {
	bool ret = variable.get_assignable();
	if(variable.get_assignable()) {
		variable.set_value(this->_symbol);
		variable.set_assignable(false);
		string str = variable.get_symbol() + " = " + variable.get_value() + ".";
		return str;
	}
	return "false";
}