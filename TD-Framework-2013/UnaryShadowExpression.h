//
//  UnaryShadowExpression.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 02/06/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_UnaryShadowExpression_h
#define TD_Framework_2013_UnaryShadowExpression_h

namespace core {
    
	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T> {
	public:
		UnaryShadowExpression(UnaryExpression<T>*);
		virtual ~UnaryShadowExpression();
        
		T evaluate(Expression<T>*) const;
		void setTarget(UnaryExpression<T>*);
        
	private:
		UnaryExpression<T>* _target;
	};
    
	template<class T>
	UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* target):
    _target(target)
	{}
    
    template<class T>
	UnaryShadowExpression<T>::~UnaryShadowExpression()
	{}
    
	template<class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T>* operand) const {
		return _target->evaluate(operand);
	}
    
	template<class T>
	void UnaryShadowExpression<T>::setTarget(UnaryExpression<T> *target) {
		_target = target;
	}
}

#endif
