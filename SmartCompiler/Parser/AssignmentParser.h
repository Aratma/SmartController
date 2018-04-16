/******************************************************************************
* @file AssignmentParser.cpp
*
* @brief Parse assignment statements
*
* @version 1.0
* @author It's me
* @date 2018/03/28
*
*
*****************************************************************************/

#ifndef ASSIGNMENTPARSER_H_
#define ASSIGNMENTPARSER_H_

#include <memory>
#include "StatementParser.h"

namespace Parser
{

class AssignmentParser : public StatementParser
{
public:
	AssignmentParser(shared_ptr<ParserContext> ctx);
	virtual ~AssignmentParser();

public:
	virtual shared_ptr<TreeNode> parse();

};

} /* namespace Parser */

#endif /* ASSIGNMENTPARSER_H_ */
