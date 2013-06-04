//
//  isTriangle.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 08/04/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_isTriangle_h
#define TD_Framework_2013_isTriangle_h

#include "Is.h"

namespace fuzzy {
    
    template<class T>
    class isTriangle : public is<T> {
      
    public:
        isTriangle(const T&, const T&, const T&);
        
        virtual T evaluate(core::Expression<T>*) const;
        
        T min() const;
        T mid() const;
        T max() const;
        
    private:
        T _min;
        T _mid;
        T _max;
        
    };
    
    template<class T>
    isTriangle<T>::isTriangle(const T& min, const T& mid, const T& max):
    _min(min), _mid(mid), _max(max)
    {}
    
    template<class T>
    T isTriangle<T>::evaluate(core::Expression<T>* expr) const {
        T value = expr->evaluate();
        
        // we are not in the triangle
        if (value <= _min || value >= _max)
            return 0;
        
        // we are after the middle of the triangle
        if (value > _mid)
            return ((_max - value) / (_max - _mid));
        
        // if we are before the middle of the triangle
        if (value <= _mid)
            return ((value - _min) / (_mid - _min));
        
        // by security
        return 0;
    }

    template<class T>
    T isTriangle<T>::min() const {
        return _min;
    }
    
    template<class T>
    T isTriangle<T>::mid() const {
        return _mid;
    }
    
    template<class T>
    T isTriangle<T>::max() const {
        return _max;
    }
    
    
}


#endif
