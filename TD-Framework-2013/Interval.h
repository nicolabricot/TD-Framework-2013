//
//  Interval.h
//  TD-Framework-2013
//
//  Created by Nicolas Devenet on 26/05/13.
//  Copyright (c) 2013 Nicolas Devenet. All rights reserved.
//

#ifndef TD_Framework_2013_Interval_h
#define TD_Framework_2013_Interval_h

namespace shape {
    
    template<class T>
    class Interval {
    public:
        Interval(T, T, T);
        virtual ~Interval();
        
        void reset();
        bool hasNext();
        T next();
        
        
    private:
        T _min;
        T _max;
        T _step;
        T _current;
        
    };
    
    template<class T>
    Interval<T>::Interval(T min, T max, T step):
    _min(min), _max(max), _step(step), _current(min)
    {}
    
    template<class T>
    Interval<T>::~Interval()
    {}
    
    template<class T>
    void Interval<T>::reset() {
        _current = _min;
    }
    
    template<class T>
    bool Interval<T>::hasNext() {
        return (_current < _max);
    }
    
    template<class T>
    T Interval<T>::next() {
        // check we are not out of range
        if (_current < _max) {
            T result = _current;
            _current = _current + _step;
            return result;
        }
        
        return NULL;
    }
    
}

#endif
