//
//  main.cpp
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 12/03/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#include <iostream>
//shape
#include "Interval.h"
#include "Shape.h"
// core
#include "core.h"
// fuzzy
#include "fuzzy.h"

using namespace core;

void expressions() {
    
    std::cout << "/* expressions */" << std::endl << std::endl;
    
	/* values */
	ValueModel<float>* x = new ValueModel<float>(2);
	ValueModel<float>* y = new ValueModel<float>(10);
    
    std::cout << "x: " << x->evaluate() << std::endl;
    std::cout << "y: " << y->evaluate() << std::endl;
    
	/* operators */
    fuzzy::AggMax<float>* aggMax = new fuzzy::AggMax<float>();
	fuzzy::AggPlus<float>* aggPlus = new fuzzy::AggPlus<float>();
	fuzzy::AndMin<float>* andMin = new fuzzy::AndMin<float>();
	fuzzy::AndMult<float>* andMult = new fuzzy::AndMult<float>();
	fuzzy::NotMinus1<float>* notMinus1 = new fuzzy::NotMinus1<float>();
	fuzzy::OrMax<float>* orMax = new fuzzy::OrMax<float>();
	fuzzy::OrPlus<float>* orPlus = new fuzzy::OrPlus<float>();
	fuzzy::ThenMin<float>* thenMin = new fuzzy::ThenMin<float>();
	fuzzy::ThenMult<float>* thenMult = new fuzzy::ThenMult<float>();
    
    /* expressions */
    std::cout << std::endl << "Agg" << std::endl;
	BinaryExpressionModel<float> a(x, y, aggMax);
    std::cout << "max: " << a.evaluate() << std::endl;
	BinaryExpressionModel<float> b(x, y, aggPlus);
	std::cout << "add: " << b.evaluate() << std::endl;

    std::cout << "And" << std::endl;
	BinaryExpressionModel<float> c(x, y, andMin);
	std::cout << "min: " << c.evaluate() << std::endl;
	BinaryExpressionModel<float> d(x, y, andMult);
	std::cout << "mult: " << d.evaluate() << std::endl;

    std::cout << "Not" << std::endl;
	UnaryExpressionModel<float> e(x, notMinus1);
	std::cout << "not: " << e.evaluate() << " (x)" << std::endl;
    UnaryExpressionModel<float> f(x, notMinus1);
	std::cout << "not: " << f.evaluate() << " (y)" << std::endl;

    std::cout << "Or" << std::endl;
	BinaryExpressionModel<float> g(x, y, orMax);
	std::cout << "max: " << g.evaluate() << std::endl;
	BinaryExpressionModel<float> h(x, y, orPlus);
	std::cout << "add: " << h.evaluate() << std::endl;

    std::cout << "Then" << std::endl;
	BinaryExpressionModel<float> i(x, y, thenMin);
	std::cout << "min: " << i.evaluate() << std::endl;
	BinaryExpressionModel<float> j(x, y, thenMult);
	std::cout << "mult: " << j.evaluate() << std::endl;
    
	delete x;
	delete y;
}

void triangle() {
    
    std::cout << std::endl << std::endl << "/* triangle */" << std::endl << std::endl;

	fuzzy::isTriangle<float> t = fuzzy::isTriangle<float>(0, 5, 15);
    std::cout << "triangle min: " << t.min() << ", mid: " << t.mid() << ", max: " << t.max() << std::endl;
	ValueModel<float> value = ValueModel<float>(0);
	UnaryExpressionModel<float> expr = UnaryExpressionModel<float>(&value, &t);
    
	float input = 0;
	while (true) {
		std::cout << "value : ";
        std::cin >> input;
		value.setValue(input);
		std::cout << "result -> " << expr.evaluate() << std::endl;
	}
}

void mandani() {
    
    std::cout << "/* mamdani */" << std::endl << std::endl;
    
	/* shape */
    shape::Interval<float> interval = shape::Interval<float>(5, 25, 1);
    
	/* operators */
    fuzzy::NotMinus1<float> opNot;
	fuzzy::AndMin<float> opAnd;
	fuzzy::OrMax<float> opOr;
	fuzzy::ThenMin<float> opThen;
	fuzzy::AggMax<float> opAgg;
	fuzzy::CogDefuzz<float> opMamdani = fuzzy::CogDefuzz<float>(&interval);
	fuzzy::SugenoDefuzz<float> opSugeno = fuzzy::SugenoDefuzz<float>();
    
    std::vector<float> coef;
	coef.push_back(1);
	coef.push_back(1);
	fuzzy::SugenoConclusion<float> opConclusion = fuzzy::SugenoConclusion<float>(&coef);
    
	/* fuzzy factory */
	FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opMamdani, &opSugeno, &opConclusion);
    
    /* membership functions */
	fuzzy::isTriangle<float> poor(-5,0,5);
	fuzzy::isTriangle<float> good(0,5,10);
	fuzzy::isTriangle<float> excellent(5,10,15);

	fuzzy::isTriangle<float> cheap(0,5,10);
	fuzzy::isTriangle<float> average(10,15,20);
	fuzzy::isTriangle<float> generous(20,25,30);
    
    fuzzy::isTriangle<float> rancid(-5,0,5);
	fuzzy::isTriangle<float> delicious(0,10,15);
    
	/* values */
    ValueModel<float> service(0);
    ValueModel<float> food(0);
	ValueModel<float> tips(0);
    
	Expression<float> *r =
    f.newAgg(
             f.newAgg(
                      f.newThen(
                                f.newOr(
                                        f.newIs(&service, &poor),
                                        f.newIs(&food, &rancid)
                                        ),
                                f.newIs(&tips, &cheap)
                                ),
                      f.newThen(
                                f.newIs(&service, &good),
                                f.newIs(&tips, &average)
                                )
                      ),
             f.newThen(
                       f.newOr(
                                f.newIs(&service, &excellent),
                                f.newIs(&food, &delicious)
                            ),
                            f.newIs(&tips, &generous)
                        )
             );
    
	/* defuzzification */
	Expression<float> *system = f.newMamdani(r, &tips);
    
	/* let's go */
	float input;
	while(true) {
		std::cout << "service: ";
        std::cin >> input;
		service.setValue(input);
        std::cout << "food: ";
        std::cin >> input;
		food.setValue(input);
        
		std::cout << "tips > " << system->evaluate() << std::endl << std::endl;
	}
}

void sugeno() {
    
    std::cout << "/* sugeno */" << std::endl << std::endl;
    
	/* shape */
    shape::Interval<float> interval = shape::Interval<float>(5, 25, 1);
    
	/* operators */
	fuzzy::NotMinus1<float> opNot;
	fuzzy::AndMin<float> opAnd;
	fuzzy::OrMax<float> opOr;
	fuzzy::ThenSugeno<float> opThen;
	fuzzy::AggMax<float> opAgg;
	fuzzy::CogDefuzz<float> opMamdani = fuzzy::CogDefuzz<float>(&interval);
	fuzzy::SugenoDefuzz<float> opSugeno = fuzzy::SugenoDefuzz<float>();
    
    std::vector<float> coef;
	coef.push_back(1);
	coef.push_back(1);
	fuzzy::SugenoConclusion<float> opConclusion = fuzzy::SugenoConclusion<float>(&coef);
    
	/* fuzzy factory */
	FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opMamdani, &opSugeno, &opConclusion);
    
	/* membership functions */
	fuzzy::isTriangle<float> poor(-5,0,5);
	fuzzy::isTriangle<float> good(0,5,10);
	fuzzy::isTriangle<float> excellent(5,10,15);
    
	fuzzy::isTriangle<float> rancid(-5,0,5);
	fuzzy::isTriangle<float> delicious(5,10,15);
    
	/* values */
	ValueModel<float> service(0);
	ValueModel<float> food(0);
    
	/* sugeno conclusion */
    std::vector<const Expression<float>*> SCservicefood;
	SCservicefood.push_back(&service);
	SCservicefood.push_back(&food);
    
    std::vector<const Expression<float>*> SCservice;
	SCservice.push_back(&service);
    
	/* rules */
    std::vector<const Expression<float>*> rules;
    
	rules.push_back(
                     f.newThen(
                               f.newOr(
                                       f.newIs(&service, &poor),
                                       f.newIs(&food, &rancid)
                                       ),
                               f.newConclusion(&SCservicefood)
                               )
                     );
    
	rules.push_back(
                     f.newThen(
                               f.newIs(&service, &good),
                               f.newConclusion(&SCservice)
                               )
                     );
    
	rules.push_back(
                     f.newThen(
                               f.newOr(
                                       f.newIs(&service, &excellent),
                                       f.newIs(&food, &delicious)
                                       ),
                               f.newConclusion(&SCservicefood)
                               )
                     );
    
	/* defuzzification */
	Expression<float> *system = f.newSugeno(&rules);
    
	/* let's go */
	float input;
	while(true)	{
		std::cout << "service: ";
        std::cin >> input;
		service.setValue(input);
		std::cout << "food: ";
        std::cin >> input;
		food.setValue(input);
		std::cout << "tips > " << system->evaluate() << std::endl << std::endl;
	}
}

int main(int argc, const char * argv[]) {
    
    /* expressions */
	//expressions();
    
    /* triangle */
	//triangle();
    
    /* mamdani */
	//mandani();
    
    /* sugeno */
	//sugeno();
    
	return 0;
}
