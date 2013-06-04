//
//  CogDeffuz.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 08/04/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_CogDeffuz_h
#define TD_Framework_2013_CogDeffuz_h

#include "MamdaniDefuzz.h"

namespace fuzzy {
    
    template<class T>
    class CogDefuzz : public MamdaniDefuzz<T> {
        
    public:
        CogDefuzz(shape::Interval<T>*);
        virtual ~CogDefuzz();
        
        virtual T defuzz(shape::Shape<T>) const;
        
    };
    
    template<class T>
    CogDefuzz<T>::CogDefuzz(shape::Interval<T>* interval):
    MamdaniDefuzz<T>(interval)
    {}
    
    template<class T>
    CogDefuzz<T>::~CogDefuzz()
    {}
    
    template<class T>
    T CogDefuzz<T>::defuzz(shape::Shape<T> shape) const {
        T numerator = 0;
        T denominator = 0;
        std::pair<T,T> value;
        
        shape.reset();
        while (shape.hasNext()) {
            value = shape.next();
            
            numerator = numerator + (value.first * value.second);
            denominator = denominator + value.second;
        }
        
        if (denominator != 0)
            return (numerator / denominator);
        
        return 0;
        
    }
    
}


#endif
