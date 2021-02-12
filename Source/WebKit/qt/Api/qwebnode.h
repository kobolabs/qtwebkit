/*
    Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef QWEBNODE_H
#define QWEBNODE_H

#include <QtCore/qstring.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qrect.h>
#include <QtCore/qvariant.h>
#include <QtCore/qshareddata.h>

#include "qwebkitglobal.h"
namespace WebCore {
    class Node;
}

class QWebNodePrivate;
class QWebElement;
class QWebPageAdapter;
class QWebRange;

class QWEBKIT_EXPORT QWebNode {
public:
    QWebNode();
    QWebNode(const QWebNode&);
    QWebNode &operator=(const QWebNode&);
    ~QWebNode();

    bool operator==(const QWebNode& o) const;
    bool operator!=(const QWebNode& o) const;

    bool isNull() const;

    bool isElementNode() const;
    bool isContainerNode() const;
    bool isTextNode() const;
    bool isHTMLElement() const;
    bool isSVGElement() const;

    QString nodeValue() const;

    QWebNode parent() const;
    QWebNode firstChild() const;
    QWebNode lastChild() const;
    QWebNode nextSibling() const;
    QWebNode previousSibling() const;

private:
    explicit QWebNode(WebCore::Node*);

    friend class QWebElement;
    friend class QWebPageAdapter;
    friend class QWebRange;

    QWebNodePrivate* d;
    WebCore::Node* m_node;
};

Q_DECLARE_METATYPE(QWebNode)

#endif // QWEBNODE_H
