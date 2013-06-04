//
//  ThenMult.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 18/03/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_ThenMult_h
#define TD_Framework_2013_ThenMult_h

namespace fuzzy {
    
    template<class T>
    class ThenMult : public Then<T> {
        
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
        
    };
    
    
    template<class T>
    T ThenMult<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const {
        return (left->evaluate() * right->evaluate());
    }
    
}

#endif
