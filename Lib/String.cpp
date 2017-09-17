/********************************************************************
*
*	String.cpp
*
*   String class that works for both wide and single character
*
*	Written by J1 (17 Aug 2017)
*
***/

#pragma once
#include "Pch.h"

/********************************************************************
*
*   CString
*
***/

CString::CString (wchar_t * ch, size_t count)
    : m_str(nullptr) {
    m_wstr = NEW(std::wstring)(ch, count);
}

//===================================================================
CString::CString (wchar_t * ch)
    : m_str(nullptr) {
    m_wstr = NEW(std::wstring)(ch);
}

//===================================================================
CString::CString (char * ch, size_t count)
    : m_wstr(nullptr) {
    m_str = NEW(std::string)(ch, count);
}

//===================================================================
CString::CString (char * ch)
    : m_wstr(nullptr)
{
    m_str = NEW(std::string)(ch);
}