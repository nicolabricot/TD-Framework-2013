//
//  Not.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 26/05/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_Not_h
#define TD_Framework_2013_Not_h

#include "Expression.h"
#include "UnaryExpression.h"

namespace fuzzy {
    
    template<class T>
    class Not : public core::UnaryExpression<T> {
        
    public:
        virtual T evaluate(core::Expression<T>*) const = 0;
        
    };
    
}

#endif
