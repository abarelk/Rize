/********************************************************************
*
*	Rize.cpp
*
*	Written by J1 (14 Aug 2017)
*
***/

#include "Pch.h"

int main(int argc, char ** argv) {

    Option::Elem el = { 0, 'h', "host", "host address", Option::OP_NETADDRESS };

    Option::IOption * option = Option::CreateOption(
    {
        //  key, short key, long key, desc, additional param 
        { 0, 'h', "host", "host address", Option::OP_NETADDRESS },
        { 0, 'p', "port", "port"        , Option::OP_INT },
    });

	return 0;
}