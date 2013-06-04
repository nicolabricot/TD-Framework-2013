//
//  AndMin.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 13/03/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_AndMin_h
#define TD_Framework_2013_AndMin_h

#include "And.h"

namespace fuzzy {

    template<class T>
    class AndMin : public And<T> {
        
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
        
    };
    
    
    template<class T>
    T AndMin<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const {
        return (left->evaluate() < right->evaluate()) ? left->evaluate() : right->evaluate() ;
    }
    
}


#endif
