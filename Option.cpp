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

template<typename CTy>
class COption : public IOption {
public: 
    COption ();
    virtual ~COption ();

    // Overrides IOption
    const bool   GetBoolValue (const CTy * key, bool default = false) override;
    const int    GetIntValue (const CTy * key, int default = 0) override;
    const CTy *  GetStrValue (const CTy * key, CTy * default = nullptr) override;

    bool ParseArg (const int argc, const CTy ** argv);

private:
    typedef std::basic_string<CTy> TString;
    typedef std::pair<TString, TString> TStringPair;

    std::unordered_map<TString, TString>  m_options;
    char m_error[1024];

    void LogError (const char * fmt, ...);
};


/********************************************************************
*
*	COption
*
***/
template<typename CTy>
COption<CTy>::COption () {
}

//===================================================================
template<typename CTy>
COption<CTy>::~COption () {
}

//===================================================================
template<typename CTy>
const bool COption<CTy>::GetBoolValue (const CTy * key, bool default) {
    return default;
}

//===================================================================
template<typename CTy>
const int COption<CTy>::GetIntValue (const CTy * key, int default) {
    return default;
}

//===================================================================
template<typename CTy>
const CTy * COption<CTy>::GetStrValue (const CTy * key, CTy * default) {
    return default;
}

//===================================================================
template<typename CTy>
bool COption<CTy>::ParseArg (const int argc, const CTy ** argv) {
    enum EState {
        ST_KEY,
        ST_LONGKEY,
        ST_VALUE
    };
    EState state = ST_VALUE;
    int arg = 1;
    
    while (arg < argc) {
        const CTy * ptr = argv[arg];    
        TString key, value;
        for (; ptr; ++ptr) {
            switch (ptr) {
            case '-':
                if (state == ST_KEY) {
                    state = ST_LONGKEY;
                    continue;
                }
                if (state == ST_LONGKEY) {
                    return false;
                }
                break;
            case '/':
                break;
            default:

            }
        }
    }
}


//===================================================================
template<typename CTy>
void COption<CTy>::LogError (const char * fmt, ...) {
    va_list v;
    va_start(v, fmt);
    std::vsnprintf(m_error, fmt, v);
    va_end(v);
}


/********************************************************************
*
*	Export functions
*
***/
IOption * CreateOption (const int argc, const char ** argv) {
    return nullptr;
}