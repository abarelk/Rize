/********************************************************************
*
*	Option.cpp
*
*	Written by J1 (14 Aug 2017)
*
*   COption is an implementation of IOption which allows most common
*   usage of command line argument option. 
*   Options allowed starts with
*       '/', '-': one character option
*       '--': long string option
*   An option can have at most one value.
*
*   This class is not thread-safe.
*
***/

#include "Pch.h"

namespace Option {


class COption : public IOption {
public: 
    COption (std::initializer_list<Elem> options);
    virtual ~COption ();

    // Overrides IOption
    bool Parse (CString commandArgs) override;

    const bool      GetBoolParam (unsigned index, bool default) override;
    const CString * GetStrParam (unsigned index, CString * default) override;
    const int       GetIntParam (unsigned index, int default) override;

private:

    std::unordered_map<CString, CString>  m_options;
    char m_error[1024];

    void LogError (const char * fmt, ...);
};


/********************************************************************
*
*	COption
*
***/
COption::COption(std::initializer_list<Elem> options) {
}

//===================================================================
COption::~COption () {
}

//===================================================================
const bool COption::GetBoolParam (unsigned index, bool default) {
    return default;
}

//===================================================================
const int COption::GetIntParam (unsigned index, int default) {
    return default;
}

//===================================================================
const CString * COption::GetStrParam (unsigned index, CString * default) {
    return default;
}

//===================================================================
bool COption::Parse (CString args) {
    enum EState {
        ST_KEY,
        ST_LONGKEY,
        ST_VALUE
    };
    EState state = ST_VALUE;
    int arg = 1;
    
    //while (arg < argc) {
    //    const CTy * ptr = argv[arg];    
    //    TString key, value;
    //    for (; ptr; ++ptr) {
    //        switch (ptr) {
    //        case '-':
    //            if (state == ST_KEY) {
    //                state = ST_LONGKEY;
    //                continue;
    //            }
    //            if (state == ST_LONGKEY) {
    //                return false;
    //            }
    //            break;
    //        case '/':
    //            break;
    //        default:

    //        }
    //    }
    //}
}


//===================================================================
void COption::LogError (const char * fmt, ...) {
    va_list v;
    va_start(v, fmt);
    std::vsnprintf(m_error, ARRSIZE(m_error), fmt, v);
    va_end(v);
}


/********************************************************************
*
*	Export functions
*
***/
IOption * CreateOption (std::initializer_list<Elem> options) {
    return NEW(COption)(options);
}


} // namespace Option