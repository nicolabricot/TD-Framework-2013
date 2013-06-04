//
//  Expression.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 12/03/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_Expression_h
#define TD_Framework_2013_Expression_h

namespace core {
    
    template<class T>
    class Expression {

    public:
        virtual T evaluate() const = 0;

    };

}


#endif
