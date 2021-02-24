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

#include "config.h"
#include "qwebnode.h"

#include "APICast.h"
#include "Node.h"
#include "qt_runtime.h"

#include <QPainter>

using namespace WebCore;

class QWebNodePrivate {
public:
};

QWebNode::QWebNode()
    : d(0)
    , m_node(0)
{
}

QWebNode::QWebNode(WebCore::Node* node)
    : d(0)
    , m_node(node)
{
    if (node) {
        m_node->ref();
    }
}

QWebNode::QWebNode(const QWebNode &other)
    : d(0)
    , m_node(other.m_node)
{
    if (m_node)
        m_node->ref();
}

QWebNode &QWebNode::operator=(const QWebNode &other)
{
    // ### handle "d" assignment
    if (this != &other) {
        Node *otherNode = other.m_node;
        if (otherNode)
            otherNode->ref();
        if (m_node)
            m_node->deref();
        m_node = otherNode;
    }
    return *this;
}

QWebNode::~QWebNode()
{
    delete d;
    if (m_node)
        m_node->deref();
}

bool QWebNode::operator==(const QWebNode& o) const
{
    return m_node == o.m_node;
}

bool QWebNode::operator!=(const QWebNode& o) const
{
    return m_node != o.m_node;
}

bool QWebNode::isNull() const
{
    return !m_node;
}

bool QWebNode::isElementNode() const
{
    if (!m_node)
        return false;
    return m_node->isElementNode();
}

bool QWebNode::isContainerNode() const
{
    if (!m_node)
        return false;
    return m_node->isContainerNode();
}

bool QWebNode::isTextNode() const
{
    if (!m_node)
        return false;
    return m_node->isTextNode();
}

bool QWebNode::isHTMLElement() const
{
    if (!m_node)
        return false;
    return m_node->isHTMLElement();
}

bool QWebNode::isSVGElement() const
{
    if (!m_node)
        return false;
    return m_node->isSVGElement();
}

QString QWebNode::nodeValue() const
{
    if (!m_node)
        return QString();
    return m_node->nodeValue();
}

QWebNode QWebNode::parent() const
{
    if (m_node)
        return QWebNode(m_node->parentNode());
    return QWebNode();
}

QWebNode QWebNode::firstChild() const
{
    if (!m_node)
        return QWebNode();
    return QWebNode(m_node->firstChild());
}

QWebNode QWebNode::lastChild() const
{
    if (!m_node)
        return QWebNode();
    return QWebNode(m_node->lastChild());
}

QWebNode QWebNode::nextSibling() const
{
    if (!m_node)
        return QWebNode();
    return QWebNode(m_node->nextSibling());
}

QWebNode QWebNode::previousSibling() const
{
    if (!m_node)
        return QWebNode();
    return QWebNode(m_node->previousSibling());
}
