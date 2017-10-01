#include "variable.h"
#include "atom.h"
#include "number.h"
#include <string>
using std :: string;
Variable :: Variable(string s) : _symbol(s) {}
string Variable :: get_value() { return _value; }
string Variable :: get_symbol() { return _symbol; }
void Variable :: set_value(string key) { _value = key; }
bool Variable :: get_assignable() { return _assignable; }
void Variable :: set_assignable(bool key) { _assignable = key; }
string Variable :: match(Atom operand) {
	bool ret = _assignable;
	if(_assignable || _value == operand.get_symbol()) {
		_value = operand.get_symbol();
		_assignable = false;
		return _symbol + " = " + _value + ".";
	}
	return "false.";
}
string Variable :: match(Number operand) {
	bool ret = _assignable;
	if(_assignable) {
		_value = operand.value();
		_assignable = false;
		return _symbol + " = " + _value + ".";
	}
	return "false.";
}