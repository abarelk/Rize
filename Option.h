/********************************************************************
*
*	Option.h
*
*	Written by J1 (14 Aug 2017)
*
***/

#pragma once

class IOption {
public:
	virtual const bool   GetBoolValue (const char * key, bool default=false) = 0;
    virtual const char * GetStrValue (const char * key, char * default=nullptr) = 0;
    virtual const int    GetIntValue (const char * key, int default=0) = 0;
};

IOption * CreateOption (const int argc, const char ** argv);


