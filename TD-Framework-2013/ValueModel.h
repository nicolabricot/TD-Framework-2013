//
//  ValueModel.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 12/03/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_ValueModel_h
#define TD_Framework_2013_ValueModel_h

#include "Expression.h"

namespace core {
    
    template<class T>
    class ValueModel : public Expression<T> {
       
    public:
        ValueModel(const T& = T(0));
        virtual ~ValueModel();
        
        virtual T evaluate() const;
        void setValue(const T&);
        
    private:
        T _value;
        
    };
    
    template<class T>
    ValueModel<T>::ValueModel(const T& value):
    _value(value)
    {}
    
    template<class T>
    ValueModel<T>::~ValueModel() {}
    
    template<class T>
    void ValueModel<T>::setValue(const T& value) {
        _value = value;
    }
    
    template<class T>
     T ValueModel<T>::evaluate() const {
        return _value;
    }
    
}

#endif
