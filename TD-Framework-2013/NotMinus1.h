//
//  NotMinus.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 08/04/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_NotMinus_h
#define TD_Framework_2013_NotMinus_h

#include "Not.h"

namespace fuzzy {
    
    template<class T>
    class NotMinus1 : public Not<T> {
      
    public:
        virtual T evaluate(core::Expression<T>*) const;
        
    };
    
    template<class T>
    T NotMinus1<T>::evaluate(core::Expression<T>* expr) const {
        return (1- expr->evaluate());
    }
    
}



#endif
