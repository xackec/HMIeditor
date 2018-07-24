#ifndef WIDGETPARSER_H
#define WIDGETPARSER_H

#import <QXmlDefaultHandler>

class WidgetParser : public QXmlDefaultHandler
{
public:
    WidgetParser();
    bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts) override;
    bool characters(const QString &ch) override;
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName) override;
    bool fatalError(const QXmlParseException &exception) override;
};

#endif // WIDGETPARSER_H
