//
//  ExpressionFactory.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 08/04/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_ExpressionFactory_h
#define TD_Framework_2013_ExpressionFactory_h

#include "core.h"
#include "fuzzy.h"
#include <set>
#include <vector>

namespace core {
    
	template <class T>
	class ExpressionFactory {
	public:
		ExpressionFactory();
		virtual ~ExpressionFactory();
        
		Expression<T>* hold(Expression<T>*);
		ValueModel<T>* newValue(fuzzy::is<T>*);
		UnaryExpressionModel<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
		BinaryExpressionModel<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
		NaryExpressionModel<T>* newNary(NaryExpression<T>*, std::vector<Expression<T>*>);
        
	private:
		std::set<Expression<T>*> *_memory;
	};
    
	template<class T>
	ExpressionFactory<T>::ExpressionFactory():
	_memory(new std::set<Expression<T>*>)
	{}
    
	template<class T>
	ExpressionFactory<T>::~ExpressionFactory() {
		delete _memory;
	}
    
	template<class T>
	Expression<T>* ExpressionFactory<T>::hold(Expression<T>* expr) {
		_memory->insert(expr);
		return expr;
	}
    
	template<class T>
	ValueModel<T>* ExpressionFactory<T>::newValue(fuzzy::is<T>* value) {
		return new ValueModel<T>(value);
	}
    
	template<class T>
	UnaryExpressionModel<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* expr) {
		return new UnaryExpressionModel<T>(ope, expr);
	}
    
	template<class T>
	BinaryExpressionModel<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* left, Expression<T>* right) {
		return new BinaryExpressionModel<T>(ope, left, right);
	}
    
	template<class T>
	NaryExpressionModel<T>* ExpressionFactory<T>::newNary(NaryExpression<T>* ope, std::vector<Expression<T>*> operands) {
		return new NaryExpressionModel<T>(ope, operands);
	}
}


#endif