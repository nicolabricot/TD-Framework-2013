//
//  ThenSugeno.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 02/06/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_ThenSugeno_h
#define TD_Framework_2013_ThenSugeno_h

#include "Then.h"

namespace fuzzy {
    
	template<class T>
	class ThenSugeno : public Then<T> {
	public:
		ThenSugeno();
        virtual ~ThenSugeno();
        
		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
		virtual T premiseValue();

	private:
		mutable T _premiseValue;
	};
    
	template<class T>
	ThenSugeno <T>::ThenSugeno():
    _premiseValue(0)
	{}
    
    template<class T>
	ThenSugeno <T>::~ThenSugeno()
	{}
    
	template<class T>
	T ThenSugeno <T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const {
        _premiseValue = left->evaluate();
		return (_premiseValue * right->evaluate());
	}
    
	template<class T>
	T ThenSugeno <T>::premiseValue() {
		return _premiseValue;
	}
}


#endif
