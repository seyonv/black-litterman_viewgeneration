/*
 * hlblacklitterman_types.h
 *
 * Code generation for function 'hlblacklitterman'
 *
 * C source code generated on: Thu Mar 19 17:44:45 2015
 *
 */

#ifndef __HLBLACKLITTERMAN_TYPES_H__
#define __HLBLACKLITTERMAN_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_ResolvedFunctionInfo
#define typedef_ResolvedFunctionInfo
typedef struct
{
    const char * context;
    const char * name;
    const char * dominantType;
    const char * resolved;
    uint32_T fileTimeLo;
    uint32_T fileTimeHi;
    uint32_T mFileTimeLo;
    uint32_T mFileTimeHi;
} ResolvedFunctionInfo;
#endif /*typedef_ResolvedFunctionInfo*/

#endif
/* End of code generation (hlblacklitterman_types.h) */
