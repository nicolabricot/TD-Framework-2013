//
//  BinaryExpression.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 13/03/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_BinaryExpression_h
#define TD_Framework_2013_BinaryExpression_h

namespace core {
    
    template<class T>
    class BinaryExpression {
        
    public:        
        virtual T evaluate(Expression<T>*, Expression<T>*) const = 0;
    };
    
}


#endif
