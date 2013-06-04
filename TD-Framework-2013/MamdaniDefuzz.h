//
//  MamdaniDefuzz.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 08/04/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_MamdaniDefuzz_h
#define TD_Framework_2013_MamdaniDefuzz_h

#include "BinaryExpression.h"

namespace fuzzy {
    
    template<class T>
    class MamdaniDefuzz : public core::BinaryExpression<T> {
        
    public:
        MamdaniDefuzz(shape::Interval<T>*);
        virtual ~MamdaniDefuzz();
        
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
        virtual T defuzz(shape::Shape<T>) const = 0;
        
    private:
        shape::Interval<T>* _interval;
        
    };
    
    template<class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(shape::Interval<T>* interval):
    _interval(interval)
    {}
    
    template<class T>
    MamdaniDefuzz<T>::~MamdaniDefuzz()
    {}
    
    template<class T>
    T MamdaniDefuzz<T>::evaluate(core::Expression<T>* left, core::Expression<T>* right) const {
        shape::Shape<T> shape = shape::Shape<T>(left, (core::ValueModel<T>*) right, *_interval);
        return defuzz(shape);
    }
    
    
    
    
}


#endif
