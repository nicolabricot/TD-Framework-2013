//
//  AggMax.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 26/05/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_AggMax_h
#define TD_Framework_2013_AggMax_h

#include "Agg.h"

namespace fuzzy {
    
    template<class T>
    class AggMax : public Agg<T> {
        
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
        
    };
    
    
    template<class T>
    T AggMax<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const {
        return (left->evaluate() > right->evaluate()) ? left->evaluate() : right->evaluate();
    }
    
}



#endif
