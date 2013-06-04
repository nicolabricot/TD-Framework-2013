//
//  NaryExpression.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 02/06/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_NaryExpression_h
#define TD_Framework_2013_NaryExpression_h

#include "Expression.h"
#include <vector>

namespace core {
    
    template<class T>
    class NaryExpression {
        
    public:
        virtual T evaluate(std::vector<const Expression<T>*>*) const = 0;
    };
}


#endif
