#include "widgetparser.h"
#include "cnode.h"

WidgetParser::WidgetParser()
{
    reset();
}

WidgetParser::WidgetParser(CNode *node)
{
    setDocument(node);
}

WidgetParser::~WidgetParser()
{
    textElement.clear();
    nodeStack.clear();
}

void WidgetParser::reset(){
    doc=0;
    textElement.clear();
    nodeStack.clear();
}

void WidgetParser::setDocument(CNode* node){
    reset();
    doc=node;

    // root element
    nodeStack.push(doc);
}

bool WidgetParser::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts)
{
    if(nodeStack.isEmpty())
        return false;

    // current element
    CNode* node=nodeStack.top();

    if(node)
        node=node->getNode(localName);

    if(node)
        node->setRequisites(localName,atts);
    qDebug()<<localName;
    nodeStack.push(node);
    textElement.clear();
    return true;
}

bool WidgetParser::characters(const QString &ch)
{
    textElement+=ch;
    return true;
}
bool WidgetParser::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{
    if(nodeStack.isEmpty())
        return false;

    CNode* node=nodeStack.top();

    if(node && node->isTextElement(localName)){
        QXmlAttributes textAttr;
        textAttr.append(localName,"","",textElement);
        node->setRequisites(localName,textAttr);
    }

    nodeStack.pop();
    return true;
}
