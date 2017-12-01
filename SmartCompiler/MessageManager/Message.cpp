
#include "Message.h"

namespace MessageManager {

Message::Message(const E_MESSAGE_TYPE type, const std::string& msg)
: m_msgType(type)
, m_msgText(msg)
{
}

Message::~Message()
{
}

} /* namespace MessageManager */
