//============================================================================
// Name        :
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#ifndef PARSERSTATE_H_
#define PARSERSTATE_H_


class Parser;

//============================================================================
class ParserState
{
public:
	static ParserState* getInstance()
	{
		static ParserState theInstance;
		return &theInstance;
	}

public:
	virtual void handle(Parser* p){};

protected:
	ParserState() {};
	ParserState(const ParserState& s);

	virtual ~ParserState() {};
};


//============================================================================
class ParserStateInit : public ParserState
{
public:
	static ParserStateInit* getInstance()
	{
		static ParserStateInit theInstance;
		return &theInstance;
	}

public:
	virtual void handle(Parser* p);

protected:
	ParserStateInit() {};
	ParserStateInit(const ParserStateInit& s);

	virtual ~ParserStateInit() {};
};

//============================================================================
class ParserStateProgram : public ParserState
{
public:
	static ParserStateProgram* getInstance()
	{
		static ParserStateProgram theInstance;
		return &theInstance;
	}

public:
	virtual void handle(Parser* p);

protected:
	ParserStateProgram() {};
	ParserStateProgram(const ParserStateProgram& s);

	virtual ~ParserStateProgram() {};
};


#endif /* PARSERSTATE_H_ */
