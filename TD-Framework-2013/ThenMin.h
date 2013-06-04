//
//  ThenMin.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 18/03/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_ThenMin_h
#define TD_Framework_2013_ThenMin_h

#include "Then.h"

namespace fuzzy {
    
    template<class T>
    class ThenMin : public Then<T> {
        
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
        
    };
    
    
    template<class T>
    T ThenMin<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const {
        return (left->evaluate() < right->evaluate()) ? left->evaluate() : right->evaluate() ;
    }
    
}

#endif
