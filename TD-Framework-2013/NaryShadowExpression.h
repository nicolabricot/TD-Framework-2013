//
//  NaryShadowExpression.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 02/06/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_NaryShadowExpression_h
#define TD_Framework_2013_NaryShadowExpression_h

namespace core {
    
	template <class T>
	class NaryShadowExpression : public NaryExpression<T> {
	public:
		NaryShadowExpression(NaryExpression<T>*);
		virtual ~NaryShadowExpression();
        
		T evaluate(std::vector<const Expression<T>*>*) const;
		void setTarget(NaryExpression<T>*);
        
	private:
		NaryExpression<T>* _target;
	};
    
	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>* target):
    _target(target)
	{}
    
    template<class T>
	NaryShadowExpression<T>::~NaryShadowExpression()
	{}
    
	template<class T>
	T NaryShadowExpression<T>::evaluate(std::vector<const Expression<T>*> *operands) const {
		return _target->evaluate(operands);
	}
    
	template<class T>
	void NaryShadowExpression<T>::setTarget(NaryExpression<T> *target) {
		_target = target;
	}
}

#endif
