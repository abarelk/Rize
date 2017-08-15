/********************************************************************
*
*	Option.cpp
*
*	Written by J1 (14 Aug 2017)
*
***/

#include "Pch.h"

template<typename CTy>
class COption : public IOption {
public: 
    COption (const int argc, const CTy ** argv);
    virtual ~COption ();

    const bool   GetBoolValue (const CTy * key, bool default = false) override;
    const CTy *  GetStrValue (const CTy * key, CTy * default = nullptr) override;
    const int    GetIntValue (const CTy * key, int default = 0) override;

private:
    typedef std::basic_string<CTy> TString;
    typedef std::pair<TString, TString> TStringPair;

    std::map<TString, TString>  m_options;
};


/********************************************************************
*
*	COption
*
***/
template<typename CTy>
COption<CTy>::COption (const int argc, const CTy ** argv) {
    enum EState {
        ST_KEY,
        ST_VALUE
    };
    EState state = ST_VALUE;
    int arg = 1;

    while (arg < argc) {
        const CTy * ptr = argv[arg];        
        while (ptr++) {
            switch (ptr) {
            case '-':
                break;
            case '/':
                break;
            }
        }
    }
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
const CTy * COption<CTy>::GetStrValue (const CTy * key, CTy * default) {
    return default;
}

//===================================================================
template<typename CTy>
const int COption<CTy>::GetIntValue (const CTy * key, int default) {
    return default;
}


/********************************************************************
*
*	Export functions
*
***/
IOption * CreateOption (const int argc, const char ** argv) {
    return nullptr;
}