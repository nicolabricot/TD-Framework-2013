//
//  Shape.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 26/05/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_Shape_h
#define TD_Framework_2013_Shape_h

#include "Interval.h"
#include "Expression.h"
#include "ValueModel.h"

namespace shape {
    
    template<class T>
    class Shape {
        
    public:
        Shape(const core::Expression<T>*, core::ValueModel<T>*, Interval<T>);
        virtual ~Shape();
        
        void reset();
        bool hasNext();
        std::pair<T,T> next();
        
    private:
        const core::Expression<T>* _expr;
        core::ValueModel<T>* _value;
        Interval<T> _interval;
        
    };
    
    template<class T>
    Shape<T>::Shape(const core::Expression<T>* expr, core::ValueModel<T>* value, Interval<T> interval):
    _expr(expr), _value(value), _interval(interval)
    {}
    
    template<class T>
    Shape<T>::~Shape()
    {}
    
    template<class T>
    void Shape<T>::reset() {
        _interval.reset();
    }
    
    template<class T>
    bool Shape<T>::hasNext() {
        return _interval.hasNext();
    }
    
    template<class T>
    std::pair<T,T> Shape<T>::next() {
        std::pair<T,T> result;
        T x = _interval.next();
        _value->setValue(x);
        T y = _expr->evaluate();
        return std::make_pair(x, y);
    }
    
    
}

#endif
