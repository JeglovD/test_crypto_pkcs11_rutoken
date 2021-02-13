#include "library.h"

Library& Library::Instance()
{
   static Library library;
   return library;
}

Library::Library():
   mPHandle{ LoadLibrary( "..\\lib\\rtPKCS11ECP.dll" ) }
{
   if( !mPHandle )
      throw "!mPHandle";
}

Library::~Library()
{
   FreeLibrary( mPHandle );
}

const HMODULE& Library::PHandle()
{
   return mPHandle;
}
