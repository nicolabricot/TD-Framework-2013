//
//  BinaryExpressionModel.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 13/03/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_BinaryExpressionModel_h
#define TD_Framework_2013_BinaryExpressionModel_h

#include "Expression.h"
#include "BinaryExpression.h"

namespace core {
    
    template<class T>
    class BinaryExpressionModel : public Expression<T>, public BinaryExpression<T> {
        
    public:
        BinaryExpressionModel();
        BinaryExpressionModel(Expression<T>*, Expression<T>*, BinaryExpression<T>*);
        virtual ~BinaryExpressionModel();
        
        virtual T evaluate() const;
        virtual T evaluate(Expression<T>*, Expression<T>*) const;
        
        virtual Expression<T>* getLeft();
        virtual Expression<T>* getRight();
        virtual BinaryExpression<T>* getOperator();
        virtual void setLeft(Expression<T>*);
        virtual void setRight(Expression<T>*);
        virtual void setOperator(BinaryExpression<T>*);
        
    private:
        Expression<T>* _left;
        Expression<T>* _right;
        BinaryExpression<T>* _operator;
        
    };
    
    
    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel():
    _left(NULL), _right(NULL), _operator(NULL)
    {}
    
    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(Expression<T>* left, Expression<T>* right, BinaryExpression<T>* op):
    _left(left), _right(right), _operator(op)
    {}
    
    template<class T>
    BinaryExpressionModel<T>::~BinaryExpressionModel()
    {}
    
    template<class T>
    T BinaryExpressionModel<T>::evaluate() const {
        if (_left != NULL && _right != NULL)
            return evaluate(_left, _right);
        return NULL;
    }
    
    template<class T>
    T BinaryExpressionModel<T>::evaluate(Expression<T> *left, Expression<T> *right) const {
        if (_operator != NULL)
            return _operator->evaluate(left, right);
        return NULL;
    }
    
    template<class T>
    Expression<T>* BinaryExpressionModel<T>::getLeft() {
        return _left;
    }
    
    template<class T>
    Expression<T>* BinaryExpressionModel<T>::getRight() {
        return _right;
    }
    
    template<class T>
    BinaryExpression<T>* BinaryExpressionModel<T>::getOperator() {
        return _operator;
    }
    
    template<class T>
    void BinaryExpressionModel<T>::setLeft(Expression<T> *left) {
        _left = left;
    }
    
    template<class T>
    void BinaryExpressionModel<T>::setRight(Expression<T> *right) {
        _right = right;
    }
    
    template<class T>
    void BinaryExpressionModel<T>::setOperator(BinaryExpression<T> *op) {
        _operator = op;
    }
    
}


#endif
