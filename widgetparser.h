#ifndef WIDGETPARSER_H
#define WIDGETPARSER_H

#include <QXmlDefaultHandler>
#include <QFileDialog>
#include <QDir>
#include <QStack>
#include <QDebug>

class CNode;

class WidgetParser : public QXmlDefaultHandler
{

private:
    CNode* doc;               // pointer to object
    QStack<CNode*> nodeStack;
    QString textElement;
public:
    WidgetParser();
    WidgetParser(CNode* node);
    virtual ~WidgetParser();

    void setDocument(CNode* node);
    void reset();	             // clear stack/buffer

    bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts);
    bool characters(const QString &ch);
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
};

#endif // WIDGETPARSER_H
