//
//  NaryExpressionModel.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 02/06/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_NaryExpressionModel_h
#define TD_Framework_2013_NaryExpressionModel_h

#include "NaryExpression.h"
#include "Expression.h"
#include <vector>

namespace core {
    
    template<class T>
    class NaryExpressionModel : public Expression<T>, public NaryExpression<T> {
        
    public:
        NaryExpressionModel(std::vector<const Expression<T>*>*, NaryExpression<T>*);
        virtual ~NaryExpressionModel();
        
        T evaluate() const;
        T evaluate(std::vector<const Expression<T>*>*) const;
        
    private:
        std::vector<const Expression<T>*> *_operands;
        NaryExpression<T> *_operator;
        
    };
    
    template<class T>
	NaryExpressionModel<T>::NaryExpressionModel(std::vector<const Expression<T>*> *operands, NaryExpression<T>* ope) :
    _operands(operands), _operator(ope)
	{}
    
    template<class T>
    NaryExpressionModel<T>::~NaryExpressionModel()
    {}
    
	template<class T>
	T NaryExpressionModel<T>::evaluate() const {
		if(this->_operands != NULL)
			return this->evaluate(this->_operands);
        
		return NULL;
	}
    
	template<class T>
	T NaryExpressionModel<T>::evaluate(std::vector<const Expression<T>*> *operands) const {
		if(this->_operator != NULL)
			return this->_operator->evaluate(operands);
        
		return NULL;
	}
    
}



#endif
