/******************************************************************************
 * @file _version.h
 *
 * @brief Some description
 *
 * @version 1.0
 * @author It's me
 * @date 2018/03/27
 *
 *****************************************************************************/

#ifndef VERSION_H_
#define VERSION_H_

#define VERSION_MAJOR "1"
#define VERSION_MINOR "0"
#define VERSION_PATCH "0"
#define VERSION_BUILD "0"

static const char* version = VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH "." VERSION_BUILD;
static const char* timestamp =  __DATE__ " " __TIME__;


#endif /* VERSION_H_ */
