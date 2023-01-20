#pragma once

class  Transition
{
public:
    virtual bool condition()const=0;
    inline  operator bool() const
    {
        return condition();
    }
};
