#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
using std :: string;
class Atom;
class Variable {
private:
	const string _symbol;
	string _value;
	bool _assignable = true;
public:
	Variable(string s);
	string get_value();
	string get_symbol();
	void set_value(string key);
	bool get_assignable();
	void set_assignable(bool key);
	/*bool match(Atom atom) {
		bool ret = _assignable;
		if(_assignable) {
			_value = atom._symbol;
			_assignable = false;
		}
		return ret;
	}*/

};
#endif