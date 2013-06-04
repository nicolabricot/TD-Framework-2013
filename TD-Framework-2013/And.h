//
//  And.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 13/03/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_And_h
#define TD_Framework_2013_And_h

#include "BinaryExpression.h"

namespace fuzzy {
    
    template<class T>
    class And : public core::BinaryExpression<T> {
        
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const = 0;
        
    };
    
}


#endif
