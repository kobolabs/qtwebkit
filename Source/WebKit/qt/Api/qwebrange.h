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

#ifndef QWEBRANGE_H
#define QWEBRANGE_H

#include <QtCore/qstring.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qrect.h>
#include <QtCore/qvariant.h>
#include <QtCore/qshareddata.h>

#include "qwebkitglobal.h"
#include "qwebnode.h"

namespace WebCore {
    class Range;
}

class QWebRangePrivate;

class QWEBKIT_EXPORT QWebRange {
public:
    QWebRange();
    QWebRange(const QWebRange&);
    QWebRange &operator=(const QWebRange&);
    ~QWebRange();

    bool operator==(const QWebRange& o) const;
    bool operator!=(const QWebRange& o) const;

    bool isNull() const;

    QRect boundingBox() const;

    QString text() const;

    QWebNode startContainer() const;
    int startOffset() const;
    QWebNode endContainer() const;
    int endOffset() const;

private:
    explicit QWebRange(WebCore::Range*);

    friend class QWebPageAdapter;

    QWebRangePrivate* d;
    WebCore::Range* m_range;
};

Q_DECLARE_METATYPE(QWebRange)

#endif // QWEBRANGE_H
