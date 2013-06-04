//
//  Agg.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 26/05/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_Agg_h
#define TD_Framework_2013_Agg_h

#include "BinaryExpression.h"

namespace fuzzy {
    
    template<class T>
    class Agg : public core::BinaryExpression<T> {
        
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const = 0;
        
    };

    
}



#endif
