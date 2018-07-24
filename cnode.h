#ifndef CNODE_H
#define CNODE_H

#include <QString>
#include <QXmlAttributes>

class QXmlAttributtes;
class QXmlStreamWriter;
class QIODevice;

class CNode
{
private:
    bool writeToDevice(QIODevice* device);
    bool readFromDevice(QIODevice* device);
protected:
    QString nodeNamespace;
    QString nodePrefix;

    void writeAttribute(QXmlStreamWriter& writer,const QString& name, const QString& value);
    void writeTextElement(QXmlStreamWriter& writer,const QString& nsUri,const QString& name,const QString& text);

    friend class WidgetParser;
    virtual void setRequisites(const QString &name,const QXmlAttributes &attributes);
    virtual CNode* getNode(const QString &name);
    virtual bool isTextElement(const QString &name);

    virtual bool writeNode(QXmlStreamWriter& writer,const QString& nsUri);
public:
    CNode();


    QString nodeName;

    bool readDocument(const QString &fileName);
    bool readDocument(QByteArray* array);

    bool writeDocument(const QString &fileName);
    bool writeDocument(QByteArray* array);

    static QString encoding;
    static bool autoFormatting;
};

#endif // CNODE_H
