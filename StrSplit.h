/*
 *  Copyright (c) 2010-2016, Fabric Software Inc. All rights reserved.
 */

#ifndef _FTL_StrSplit_h
#define _FTL_StrSplit_h

#include <FTL/Config.h>
#include <FTL/MatchCharSingle.h>
#include <FTL/StrRef.h>

#include <string>
#include <vector>

FTL_NAMESPACE_BEGIN

template<typename MatchChar>
void StrSplit(
  StrRef strRef,
  std::vector<std::string> &list,
  bool strict = false
  )
{
  MatchChar const mc;

  StrRef::IT itBegin = strRef.begin();
  StrRef::IT const itEnd = strRef.end();
  for (;;)
  {
    StrRef::IT it = strRef.find<MatchChar>( itBegin, itEnd );
    if ( strict || it != itBegin )
      list.push_back( std::string( itBegin, it ) );
    if ( it == itEnd )
      break;
    itBegin = it + 1;
  }
}

template<char CharToMatch>
void StrSplit(
  StrRef strRef,
  std::vector<std::string> &list,
  bool strict = false
  )
{
  StrSplit< MatchCharSingle<CharToMatch> >( strRef, list, strict );
}

template<typename MatchChar>
void StrSplit(
  StrRef strRef,
  std::vector<StrRef> &list,
  bool strict = false
  )
{
  MatchChar const mc;

  StrRef::IT itBegin = strRef.begin();
  StrRef::IT const itEnd = strRef.end();
  for (;;)
  {
    StrRef::IT it = strRef.find<MatchChar>( itBegin, itEnd );
    if ( strict || it != itBegin )
      list.push_back( StrRef( itBegin, it ) );
    if ( it == itEnd )
      break;
    itBegin = it + 1;
  }
}

template<char CharToMatch>
void StrSplit(
  StrRef strRef,
  std::vector<StrRef> &list,
  bool strict = false
  )
{
  StrSplit< MatchCharSingle<CharToMatch> >( strRef, list, strict );
}

FTL_NAMESPACE_END

#endif //_FTL_StrSplit_h
