//
//  OrPlus.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 18/03/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_OrPlus_h
#define TD_Framework_2013_OrPlus_h

#include "Or.h"

namespace fuzzy {
    
    template<class T>
    class OrPlus : public Or<T> {
        
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
        
    };
    
    
    template<class T>
    T OrPlus<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const {
        return (left->evaluate() + right->evaluate());
    }
    
}

#endif
