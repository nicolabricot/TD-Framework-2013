//
//  SugenoDefuzz.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 02/06/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_SugenoDefuzz_h
#define TD_Framework_2013_SugenoDefuzz_h

#include "NaryExpression.h"
#include "BinaryExpressionModel.h"
#include "ThenSugeno.h"
#include <vector>

namespace fuzzy {
    
	template<class T>
	class SugenoDefuzz : public core::NaryExpression<T> {
	public:
		virtual T evaluate(std::vector<const core::Expression<T>*>*) const;
	};
    
	template<class T>
	T SugenoDefuzz <T>::evaluate(std::vector<const core::Expression<T>*> *operands) const {
		typename std::vector<const core::Expression<T>*>::const_iterator it = operands->begin();
		T numerator = 0;
		T denumerator = 0;
        
		for(it = operands->begin(); it != operands->end(); it++) {
			numerator = numerator + (*it)->evaluate();
		}
        
		for(it = operands->begin(); it != operands->end(); it++) {
			core::BinaryExpressionModel<T> *bem = (core::BinaryExpressionModel<T>*) (*it);
			core::BinaryShadowExpression<T> *bse = (core::BinaryShadowExpression<T>*) bem->getOperator();
			Then<T> *th = (Then<T>*) bse->getTarget();
			ThenSugeno<T> *sth = (ThenSugeno<T>*) th;
            
			denumerator = denumerator + sth->premiseValue();
		}
        
		if(denumerator != 0)
			return (numerator / denumerator);
        
        return 0;
	}
    
}

#endif