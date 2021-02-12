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
#include "qwebrange.h"

#include "APICast.h"
#include "Range.h"
#include "Document.h"
#include "DocumentFragment.h"
#include "FrameView.h"
#include <QWebFrameAdapter.h>
#include "qt_runtime.h"

using namespace WebCore;

class QWebRangePrivate {
public:
};

QWebRange::QWebRange()
    : d(0)
    , m_range(0)
{
}

QWebRange::QWebRange(WebCore::Range* range)
    : d(0)
    , m_range(range)
{
    if (m_range)
        m_range->ref();
}

QWebRange::QWebRange(const QWebRange &other)
    : d(0)
    , m_range(other.m_range)
{
    if (m_range)
        m_range->ref();
}

QWebRange &QWebRange::operator=(const QWebRange &other)
{
    // ### handle "d" assignment
    if (this != &other) {
        Range *otherElement = other.m_range;
        if (otherElement)
            otherElement->ref();
        if (m_range)
            m_range->deref();
        m_range = otherElement;
    }
    return *this;
}

QWebRange::~QWebRange()
{
    delete d;
    if (m_range)
        m_range->deref();
}

bool QWebRange::operator==(const QWebRange& o) const
{
    return m_range == o.m_range;
}

bool QWebRange::operator!=(const QWebRange& o) const
{
    return m_range != o.m_range;
}

bool QWebRange::isNull() const
{
    return !m_range;
}

QRect QWebRange::boundingBox() const
{
    if (!m_range)
        return QRect();
    return m_range->boundingBox();
}

QString QWebRange::text() const
{
    if (!m_range)
        return QString();
    return m_range->text();
}

QWebNode QWebRange::startContainer() const
{
    if (!m_range)
        return QWebNode();
    return QWebNode(m_range->startContainer());
}

int QWebRange::startOffset() const
{
    if (!m_range)
        return -1;
    return m_range->startOffset();
}

QWebNode QWebRange::endContainer() const
{
    if (!m_range)
        return QWebNode();
    return QWebNode(m_range->endContainer());
}

int QWebRange::endOffset() const
{
    if (!m_range)
        return -1;
    return m_range->endOffset();
}
