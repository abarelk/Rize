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
    OP_NETADDRESS
};

struct Elem {
    unsigned index;
    char     shortKey;
    CString  longKey;
    CString  desc;
    Param    param;
};

class IOption {
public:
    //virtual const bool CheckOption (const unsigned index);
    //virtual const bool CheckOption (const char shortKey);
    //virtual const bool CheckOption (const std::wstring longKey);

    virtual bool Parse (CString commandArgs);

	virtual const bool      GetBoolParam (unsigned index, bool default=false) = 0;
    virtual const CString * GetStrParam (unsigned index, CString * default=nullptr) = 0;
    virtual const int       GetIntParam (unsigned index, int default=0) = 0;
};

IOption * CreateOption (std::initializer_list<Elem> options);


} // namespace Option

