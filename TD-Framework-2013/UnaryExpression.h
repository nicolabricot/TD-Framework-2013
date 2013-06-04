//
//  UnaryExpression.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 12/03/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_UnaryExpression_h
#define TD_Framework_2013_UnaryExpression_h

#include "Expression.h"

namespace core {
    
    template<class T>
    class UnaryExpression {
      
    public:
        virtual T evaluate(Expression<T>*) const = 0;
        
    };
    
}


#endif
