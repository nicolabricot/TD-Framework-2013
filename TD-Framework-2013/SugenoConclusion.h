//
//  SugenoConclusion.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 02/06/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_SugenoConclusion_h
#define TD_Framework_2013_SugenoConclusion_h

#include "NaryExpression.h"

namespace fuzzy {
    
	template<class T>
	class SugenoConclusion : public core::NaryExpression<T>{
	
    public:
		SugenoConclusion(const std::vector<T>*);
        virtual ~SugenoConclusion();
        
		virtual T evaluate(std::vector<const core::Expression<T>*>*) const;
	
    private:
		const std::vector<T> *_coeff;
	};
    
	template<class T>
	SugenoConclusion <T>::SugenoConclusion(const std::vector<T> *coeff):
	_coeff(coeff)
	{}
    
    template<class T>
	SugenoConclusion <T>::~SugenoConclusion()
	{}
    
	template<class T>
	T SugenoConclusion <T>::evaluate(std::vector<const core::Expression<T>*> *operands) const {
		typename std::vector<T>::const_iterator itcoef = _coeff->begin();
		typename std::vector<const core::Expression<T>*>::const_iterator itexpr = operands->begin();
		T result = 0;
        
		for (; itexpr != operands->end() && itcoef != _coeff->end(); itexpr++, itcoef++) {
			T evaluation = (*itexpr)->evaluate();
			result = result + (*itcoef * evaluation);
		}
        
		if (itexpr != operands->end())
			return NULL;
        
		return result;
	}
}

#endif
