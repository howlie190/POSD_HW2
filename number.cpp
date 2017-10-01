#include "number.h"
#include "atom.h"
Number :: Number(string s, string v) : _symbol(s), _value(v) {}
bool Number :: match(Atom operand) { return false; }
bool Number :: match(Number operand) { return this->_value == operand._value; }
bool Number :: match(Variable &variable) {
	bool ret = variable.get_assignable();
	if(variable.get_assignable()) {
		variable.set_value(this->_value);
		variable.set_assignable(false);
	}
	return ret;
}
string Number :: value() { return _value; }
string Number :: symbol() { return _symbol; }