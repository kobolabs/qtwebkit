#include "config.h"
#include "EpubReadingSystem.h"

#if ENABLE(EPUB3)

#include <wtf/text/WTFString.h>

namespace WebCore {

EpubReadingSystem::EpubReadingSystem()
{
}

EpubReadingSystem::~EpubReadingSystem()
{
}

void EpubReadingSystem::setFeature(const String& feature)
{
    m_features.add(feature);
}

bool EpubReadingSystem::hasFeature(const String& feature, const String&)
{
    return m_features.contains(feature);
}

} // namespace WebCore

#endif // ENABLE(EPUB3)
