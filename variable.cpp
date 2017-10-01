#include "variable.h"
#include "atom.h"

Variable :: Variable(string s) : _symbol(s) {}
string Variable :: get_value() { return _value; }
string Variable :: get_symbol() { return _symbol; }
void Variable :: set_value(string key) { _value = key; }
bool Variable :: get_assignable() { return _assignable; }
void Variable :: set_assignable(bool key) { _assignable = key; }