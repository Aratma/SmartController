/******************************************************************************
 * @file TreeSerializer.h
 *
 * @brief Serialize parse tree to file
  *
 * @version 1.0
 * @author It's me
 * @date 2018/02/23
 *
 *
 *******************************l**********************************************/

#ifndef TREESERIALIZER_H_
#define TREESERIALIZER_H_

#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

namespace Parser
{

class TreeNode;


class TreeSerializer
{
public:
	TreeSerializer();
	virtual ~TreeSerializer();

public:
	void serialize(shared_ptr<TreeNode> rootNode, const string& fileName);

protected:
	DOMImplementation* initXerces();


protected:
	ofstream m_fileStream;
};

} /* namespace Parser */

#endif /* TREESERIALIZER_H_ */
