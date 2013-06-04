//
//  FuzzyFactory.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 02/06/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_FuzzyFactory_h
#define TD_Framework_2013_FuzzyFactory_h

#include "core.h"
#include "fuzzy.h"

namespace core {
    
	template <class T>
	class FuzzyFactory : public ExpressionFactory<T> {

	public:
		FuzzyFactory(fuzzy::Not<T>*, fuzzy::And<T>*, fuzzy::Or<T>*, fuzzy::Then<T>*, fuzzy::Agg<T>*, fuzzy::MamdaniDefuzz<T>*,
                     fuzzy::SugenoDefuzz<T>*, fuzzy::SugenoConclusion<T>*);
        
		Expression<T>* newAnd(Expression<T>*, Expression<T>*);
		Expression<T>* newOr(Expression<T>*, Expression<T>*);
		Expression<T>* newThen(Expression<T>*, Expression<T>*);
		Expression<T>* newAgg(Expression<T>*, Expression<T>*);
		Expression<T>* newMamdani(Expression<T>*, Expression<T>*);
		Expression<T>* newSugeno(std::vector<const Expression<T>*>*);
		Expression<T>* newConclusion(std::vector<const Expression<T>*>*);
		Expression<T>* newNot(Expression<T>*);
		Expression<T>* newIs(Expression<T>*, fuzzy::is<T>* is);
        
		void changeAnd(fuzzy::And<T>* o);
		void changeOr(fuzzy::Or<T>* o);
		void changeThen(fuzzy::Then<T>* o);
		void changeAgg(fuzzy::Agg<T>* o);
		void changeMamdani(fuzzy::MamdaniDefuzz<T>* o);
		void changeSugeno(fuzzy::SugenoDefuzz<T>* o);
		void changeConclusion(fuzzy::SugenoConclusion<T>* o);
		void changeNot(fuzzy::Not<T>* o);
        
	private:
		UnaryShadowExpression<T> *_opNot;
		BinaryShadowExpression<T> *_opAnd, *_opOr, *_opThen, *_opAgg, *_opMamdani;
		NaryShadowExpression<T> *_opSugeno, *_opConclusion;
	};
    
	template<class T>
	FuzzyFactory<T>::FuzzyFactory(fuzzy::Not<T> *opNot, fuzzy::And<T> *opAnd, fuzzy::Or<T> *opOr, fuzzy::Then<T> *opThen,
                                  fuzzy::Agg<T> *opAgg, fuzzy::MamdaniDefuzz<T> *opMamdani, fuzzy::SugenoDefuzz<T> *opSugeno,
                                  fuzzy::SugenoConclusion<T> *opConclusion):
    _opNot(new UnaryShadowExpression<T>(opNot)),
    _opAnd(new BinaryShadowExpression<T>(opAnd)),
    _opOr(new BinaryShadowExpression<T>(opOr)),
    _opThen(new BinaryShadowExpression<T>(opThen)),
    _opAgg(new BinaryShadowExpression<T>(opAgg)),
    _opMamdani(new BinaryShadowExpression<T>(opMamdani)),
    _opSugeno(new NaryShadowExpression<T>(opSugeno)),
    _opConclusion(new NaryShadowExpression<T>(opConclusion))
	{}
    
	template<class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* left, Expression<T>* right) {
		return new BinaryExpressionModel<T>(left, right, _opAnd);
	}
    
	template<class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* left, Expression<T>* right) {
		return new BinaryExpressionModel<T>(left, right, _opOr);
	}
    
	template<class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* left, Expression<T>* right) {
		return new BinaryExpressionModel<T>(left, right, _opThen);
	}
    
	template<class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* left, Expression<T>* right) {
		return new BinaryExpressionModel<T>(left, right, _opAgg);
	}
    
	template<class T>
	Expression<T>* FuzzyFactory<T>::newMamdani(Expression<T>* left, Expression<T>* right) {
		return new BinaryExpressionModel<T>(left, right, _opMamdani);
	}
    
	template<class T>
	Expression<T>* FuzzyFactory<T>::newSugeno(std::vector<const Expression<T>*> *operands) {
		return new NaryExpressionModel<T>(operands, _opSugeno);
	}
    
	template<class T>
	Expression<T>* FuzzyFactory<T>::newConclusion(std::vector<const Expression<T>*> *operands) {
		return new NaryExpressionModel<T>(operands, _opConclusion);
	}
    
	template<class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* o) {
		return new UnaryExpressionModel<T>(o, _opNot);
	}
    
	template<class T>
	Expression<T>* FuzzyFactory<T>::newIs(Expression<T>* o, fuzzy::is<T>* is) {
		return new UnaryExpressionModel<T>(o, is);
	}
    
	template<class T>
	void FuzzyFactory<T>::changeAnd(fuzzy::And<T>* o) {
		_opAnd->setTarget(o);
	}
    
	template<class T>
	void FuzzyFactory<T>::changeOr(fuzzy::Or<T>* o) {
		_opOr->setTarget(o);
	}
    
	template<class T>
	void FuzzyFactory<T>::changeThen(fuzzy::Then<T>* o) {
		_opThen->setTarget(o);
	}
    
	template<class T>
	void FuzzyFactory<T>::changeAgg(fuzzy::Agg<T>* o) {
		_opAgg->setTarget(o);
	}
    
	template<class T>
	void FuzzyFactory<T>::changeMamdani(fuzzy::MamdaniDefuzz<T>* o) {
		_opMamdani->setTarget(o);
	}
    
	template<class T>
	void FuzzyFactory<T>::changeSugeno(fuzzy::SugenoDefuzz<T>* o) {
		_opSugeno->setTarget(o);
	}
    
	template<class T>
	void FuzzyFactory<T>::changeConclusion(fuzzy::SugenoConclusion<T>* o) {
		_opConclusion->setTarget(o);
	}
    
	template<class T>
	void FuzzyFactory<T>::changeNot(fuzzy::Not<T>* o) {
		_opNot->setTarget(o);
	}
    
}


#endif
