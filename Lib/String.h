/********************************************************************
*
*	String.h
*
*   String class that works for both wide and single character
*
*	Written by J1 (14 Aug 2017)
*
***/

#pragma once

class CString {
public:
    CString (wchar_t * ch, size_t count);
    CString (wchar_t * ch);
    CString (char * ch, size_t count);
    CString (char * ch);

private:
    std::wstring * m_wstr;
    std::string *  m_str;
};