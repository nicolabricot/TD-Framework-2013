//
//  BinaryShadowExpression.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 02/06/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_BinaryShadowExpression_h
#define TD_Framework_2013_BinaryShadowExpression_h

namespace core {
    
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T> {
	public:
		BinaryShadowExpression(BinaryExpression<T>*);
		virtual ~BinaryShadowExpression();
        
		T evaluate(Expression<T>*, Expression<T>*) const;
		void setTarget(BinaryExpression<T>*);
		BinaryExpression<T>* getTarget();
        
	private:
		BinaryExpression<T>* _target;
	};
    
	template<class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* target):
    _target(target)
	{}
    
    template<class T>
	BinaryShadowExpression<T>::~BinaryShadowExpression()
    {}
    
	template<class T>
	T BinaryShadowExpression<T>::evaluate(Expression<T>* left, Expression<T>* right) const {
		return _target->evaluate(left, right);
	}
    
	template<class T>
	void BinaryShadowExpression<T>::setTarget(BinaryExpression<T> *target) {
		_target = target;
	}
    
	template<class T>
	BinaryExpression<T>* BinaryShadowExpression<T>::getTarget() {
		return _target;
	}
}

#endif
