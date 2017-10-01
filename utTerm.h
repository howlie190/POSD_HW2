#ifndef UTTERM_H
#define UTTERM_H
#include "atom.h"
#include "number.h"
#include "variable.h"
//test Number.value()
TEST (Number,ctor) {
	Number number_25("number_25", "25");
	ASSERT_EQ("25", number_25.value());
}
//test Number.symbol()
TEST (Number, symbol) {
	Number number_25("number_25", "25");
	ASSERT_EQ("number_25", number_25.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
	Number numberX("numberX", "25"), numberY("numberY", "25");
	ASSERT_TRUE(numberX.match(numberY));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
	Number numberX("numberX", "25"), numberY("numberY", "0");
	ASSERT_FALSE(numberX.match(numberY));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
	Atom tom("tom");
	Number number("number_25", "25");
	ASSERT_FALSE(number.match(tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
	Number number_25("number_25", "25");
	Number number_50("number_50", "50");
	Variable X("X");
	ASSERT_TRUE(number_25.match(X));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
	Atom tom("tom");
	Number number("number_25", "25");
	ASSERT_FALSE(tom.match(number));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
	Atom tom("tom");
	Variable X("X");
	ASSERT_EQ("X = tom.", tom.match(X));
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
	Atom tom("tom");
	Variable X("X");
	X.match(tom);
	tom.match(X);
	ASSERT_EQ("X = tom.", )
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {

}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
 
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {

}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {

}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {

}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){

}
#endif
