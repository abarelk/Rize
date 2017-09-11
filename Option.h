/********************************************************************
*
*	Option.h
*
*   Create Option instance with OptionElem initializer_list instance.
*
*	Written by J1 (14 Aug 2017)
*
***/

#pragma once

namespace  Option {

enum Param {
    OP_NONE,
    OP_INT,
    OP_BOOL,
    OP_STRING,
};

struct Elem {
    unsigned     index;
    char         shortKey;
    std::wstring longKey;
    std::wstring desc;
    Param        param;
};

class IOption {
public:
    virtual const bool CheckOption (const unsigned index);
    virtual const bool CheckOption (const char shortKey);
    virtual const bool CheckOption (const std::wstring longKey);

	virtual const bool      GetBoolParam (unsigned index, bool default=false) = 0;
    virtual const wchar_t * GetStrParam (unsigned index, wchar_t * default=nullptr) = 0;
    virtual const int       GetIntParam (unsigned index, int default=0) = 0;
};

IOption * CreateOption (std::initializer_list<Elem> options);


} // namespace Option

