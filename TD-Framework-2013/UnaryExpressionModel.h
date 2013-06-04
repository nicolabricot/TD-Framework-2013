//
//  UnaryExpressionModel.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 12/03/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_UnaryExpressionModel_h
#define TD_Framework_2013_UnaryExpressionModel_h

#include "Expression.h"
#include "UnaryExpression.h"

namespace core {
    
    template<class T>
    class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {
      
    public:
        UnaryExpressionModel();
        UnaryExpressionModel(Expression<T>*, UnaryExpression<T>*);
        virtual ~UnaryExpressionModel();
        
        virtual T evaluate() const;
        virtual T evaluate(Expression<T>*) const;
        
        virtual Expression<T>* getOperand();
        virtual UnaryExpression<T>* getOperator();
        virtual void setOperand(Expression<T>*);
        virtual void setOperator(UnaryExpression<T>*);
      
    private:
        UnaryExpression<T>* _operator;
        Expression<T>* _operand;
        
    };
    
    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel():
    _operand(NULL), _operator(NULL)
    {}
    
    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(Expression<T>* operand, UnaryExpression<T>* op):
    _operand(operand), _operator(op)
    {}
    
    template<class T>
    UnaryExpressionModel<T>::~UnaryExpressionModel()
    {}
    
    template<class T>
    T UnaryExpressionModel<T>::evaluate() const {
        if (_operand != NULL)
            return evaluate(_operand);
        return NULL;
    }
    
    template<class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T>* expr) const {
        if (_operator != NULL)
            return _operator->evaluate(expr);
        return NULL;
    }
    
    template<class T>
    Expression<T>* UnaryExpressionModel<T>::getOperand() {
        return _operand;
    }
    
    template<class T>
    UnaryExpression<T>* UnaryExpressionModel<T>::getOperator() {
        return _operator;
    }
    
    template<class T>
    void UnaryExpressionModel<T>::setOperand(Expression<T>* operand) {
        _operand = operand;
    }
    
    template<class T>
    void UnaryExpressionModel<T>::setOperator(UnaryExpression<T>* op) {
        _operator = op;
    }
    
}


#endif
