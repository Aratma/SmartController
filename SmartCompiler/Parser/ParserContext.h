/******************************************************************************
 * @file ParserContext.h
 *
 * @brief   Context information for parsing
 *
 * @version 1.0
 * @author It's me
 * @date 2018/04/12
 *
 *
 *****************************************************************************/

#ifndef PARSERCONTEXT_H_
#define PARSERCONTEXT_H_

#include "ScannerST.h"

namespace Parser
{

using namespace Scanner;


class SymbolTabStack;
class StandardSymTabItems;

class ParserContext
{
public:
	ParserContext();
	virtual ~ParserContext();

public:
	/** @brief Scanner for ST. */
	shared_ptr<ScannerST> _scannerST;

	/** @brief Symbol table Stack. */
	shared_ptr<SymbolTabStack> _symTabStack;

	/** @brief Standard types and functions. */
	shared_ptr<StandardSymTabItems> _stdTypes;
};

} /* namespace Parser */

#endif /* PARSERCONTEXT_H_ */
